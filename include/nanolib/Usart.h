#ifndef NANOLIB_USART_H
#define NANOLIB_USART_H


#ifndef NANOLIB_USART_BAUDRATE_MAX_ERROR_PERCENT
#define NANOLIB_USART_BAUDRATE_MAX_ERROR_PERCENT 5
#endif


#include "System.h"
#include "detail/register_map.h"


namespace periph {


/*
 *
 * Usart Configuration
 *
 */


enum Baudrate : uint32_t {
    _2_4_kHz   = 2400,
    _4_8_kHz   = 4800,
    _9_6_kHz   = 9600,
    _14_4_kHz  = 14400,
    _19_2_kHz  = 19200,
    _28_8_kHz  = 28800,
    _38_4_kHz  = 38400,
    _57_6_kHz  = 57600,
    _76_8_kHz  = 76800,
    _115_2_kHz = 115200,
    _230_4_kHz = 230400,
    _250_kHz   = 250000,
    _500_kHz   = 500000,
    _1_MHz     = 1000000,
};



using ClockPolarity = periph_detail::usart_register_set::UCSR0C::ClockPolarity;
using StopBits      = periph_detail::usart_register_set::UCSR0C::StopBits;
using ParityMode    = periph_detail::usart_register_set::UCSR0C::ParityMode;
using UsartMode     = periph_detail::usart_register_set::UCSR0C::UsartMode;
using CharacterSize = periph_detail::usart_register_set::concat::CharacterSize;
using TransmissionSpeed =
    periph_detail::usart_register_set::UCSR0A::TransmissionSpeed;


template <ClockPolarity t_clock_polarity, StopBits t_stop_bits,
          ParityMode t_parity_mode, UsartMode t_usart_mode,
          CharacterSize     t_character_size,
          TransmissionSpeed t_transmission_speed>
struct usart_conf_t {
public:
    constexpr static ClockPolarity     clock_polarity = t_clock_polarity;
    constexpr static StopBits          stop_bits      = t_stop_bits;
    constexpr static ParityMode        parity_mode    = t_parity_mode;
    constexpr static UsartMode         usart_mode     = t_usart_mode;
    constexpr static CharacterSize     character_size = t_character_size;
    constexpr static TransmissionSpeed transmission_speed =
        t_transmission_speed;
};

using usart_conf_def =
    usart_conf_t<ClockPolarity::async, StopBits::_1, ParityMode::disabled,
                 UsartMode::async, CharacterSize::_8,
                 TransmissionSpeed::normal>;

template <CharacterSize t_character_size>
struct required_usart_data_t {
    using type = char;
};
template <>
struct required_usart_data_t<CharacterSize::_9> {
    using type = uint16_t;
};

/*
 *
 * class Usart
 *
 */


template <uint32_t t_baudrate, typename usart_conf = usart_conf_def>
class Usart {

    template <uint32_t, typename>
    friend class UsartTest;

    using reg = periph_detail::usart_register_set;

    using data_t =
        typename required_usart_data_t<usart_conf::character_size>::type;

public:
    Usart(System& system) : m_system{&system} {
        init_peripheral();
        init_data_frame();
        set_baudrate();

        set_rx_enabled(true);
        set_tx_enabled(true);

        // TODO: Interrupts
    }

    data_t read() {


        while (!char_pending())
            ;

        if constexpr (usart_conf::character_size == CharacterSize::_9) {
            // Ninth bit must be read before the other ones (ATMEGA328P
            // Datasheet 24.12.3, p.247)
            uint16_t result = (reg::UCSR0B::RXB80::read() << 8);
            result += reg::UDR0::UDR0_v::read();

            return result;
        } else {
            return reg::UDR0::UDR0_v::read();
        }
    }

    void write(data_t c) {
        while (!tx_buffer_empty())
            ;

        if constexpr (usart_conf::character_size == CharacterSize::_9) {
            constexpr static uint8_t mask =
                periph_detail::get_bitmask_ones<uint8_t, 8>::value;

            // Ninth bit must be read before the other ones (ATMEGA328P
            // Datasheet 24.12.3, p.247)
            reg::UCSR0B::TXB80::write((c >> 8) & 0b0001);
            reg::UDR0::UDR0_v::write(c & mask);
        } else {
            reg::UDR0::UDR0_v::write(c);
        }
    }

    bool char_pending() {
        return reg::UCSR0A::RXC0::read();
    }

private:
    // Implemented as pointer and not as reference to suppress wrong compiler
    // warning: "ignoring packed attribute because of unpacked non-POD field"
    System* m_system;


    constexpr static uint16_t get_brr_value() {
        static_assert(t_baudrate > 0, "The Baudrate must be greater than 0");

        constexpr uint32_t clock_factor =
            (usart_conf::transmission_speed == TransmissionSpeed::double_) ? 8
                                                                           : 16;
        constexpr uint32_t clock_speed = System::get_clockspeed_Hz();
        constexpr uint32_t max_writable =
            periph_detail::get_bitmask_ones<uint32_t, 12>::value;

        constexpr uint32_t divisor  = (clock_factor * t_baudrate);
        constexpr uint32_t dividend = clock_speed + (divisor / 2);


        // ATMEGA328P Datasheet 24.11, p.241
        constexpr uint32_t rounded_value = (dividend / divisor);


        if constexpr (rounded_value == 0) {
            return rounded_value;
        } else {
            if constexpr (rounded_value > max_writable)
                return max_writable;
            else
                return rounded_value - 1;
        }
    }

    constexpr static uint8_t get_brr_error() {
        constexpr uint32_t clock_factor =
            (usart_conf::transmission_speed == TransmissionSpeed::double_) ? 8
                                                                           : 16;
        constexpr uint32_t clock_speed = System::get_clockspeed_Hz();

        constexpr uint32_t baudrate_closest_match =
            clock_speed / ((get_brr_value() + 1) * clock_factor);

        constexpr int32_t error =
            ((baudrate_closest_match * 100) / t_baudrate) - 100;

        return periph_detail::abs(error);
    }

    void init_peripheral() {
        reg::UCSR0C::UMSEL0n::write(usart_conf::usart_mode);
    }

    void init_data_frame() {
        reg::concat::UCSZ0n::write(usart_conf::character_size);
        reg::UCSR0C::USBS0::write(usart_conf::stop_bits);
        reg::UCSR0C::UCPOL0::write(usart_conf::clock_polarity);
        reg::UCSR0C::UPM0n::write(usart_conf::parity_mode);
        reg::UCSR0A::U2X0::write(usart_conf::transmission_speed);
    }

    void set_baudrate() {
        static_assert(get_brr_error() <
                          NANOLIB_USART_BAUDRATE_MAX_ERROR_PERCENT,
                      "Error in set baudrate greater than "
                      "'NANOLIB_USART_BAUDRATE_MAX_ERROR_PERCENT'");

        constexpr uint16_t brr_value = get_brr_value();
        reg::UBRR0::UBRR_v::write<brr_value>();
    }

    void set_rx_enabled(bool b) {
        reg::UCSR0B::RXEN0::write(b);
    }

    void set_tx_enabled(bool b) {
        reg::UCSR0B::TXEN0::write(b);
    }

    bool tx_buffer_empty() {
        return reg::UCSR0A::UDRE0::read();
    }

    void flush_rx_buffer() {
        while (char_pending()) {
            char dummy = reg::UDR0::UDR0_v::read();
        }
    }
};


} // namespace periph


#endif // NANOLIB_USART_H

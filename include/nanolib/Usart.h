#ifndef NANOLIB_USART_H
#define NANOLIB_USART_H


#include "detail/register_map.h"


namespace periph {


/*
 *
 * Usart Configuration
 *
 */


enum class Baudrate : uint8_t {
    _2400_KHz,
    _4800_KHz,
    _9600_KHz,
    _14_4_KHz,
    _19_2_KHz,
    _28_8_KHz,
    _38_4_KHz,
    _57_6_KHz,
    _76_8_KHz,
    _115_2_KHz,
    _230_4_KHz,
    _250_kHz,
    _500_kHz,
    _1M_Hz,
};


using ClockPolarity = periph_detail::usart_register_set::UCSR0C::ClockPolarity;
using StopBits      = periph_detail::usart_register_set::UCSR0C::StopBits;
using ParityMode    = periph_detail::usart_register_set::UCSR0C::ParityMode;
using UsartMode     = periph_detail::usart_register_set::UCSR0C::UsartMode;
using CharacterSize = periph_detail::usart_register_set::concat::CharacterSize;


template <ClockPolarity t_clock_polarity, StopBits t_stop_bits,
          ParityMode t_parity_mode, UsartMode t_usart_mode,
          CharacterSize t_character_size>
struct usart_conf_t {
public:
    constexpr static ClockPolarity clock_polarity = t_clock_polarity;
    constexpr static StopBits      stop_bits      = t_stop_bits;
    constexpr static ParityMode    parity_mode    = t_parity_mode;
    constexpr static UsartMode     usart_mode     = t_usart_mode;
    constexpr static CharacterSize character_size = t_character_size;
};

using usart_conf_def =
    usart_conf_t<ClockPolarity::async, StopBits::_1, ParityMode::disabled,
                 UsartMode::async, CharacterSize::_8>;

/*
 *
 * class Usart
 *
 */


template <Baudrate t_baudrate, typename usart_conf = usart_conf_def>
class Usart {

    using reg = periph_detail::usart_register_set;

public:
    Usart() {
        init_peripheral();
        init_data_frame();
        set_baudrate();

        set_rx_enabled(true);
        set_tx_enabled(true);

        // TODO: Interrupts
    }

    char read() {
        // TODO: Read the ninth bit from UCSR0B, if that is required

        while (!char_pending())
            ;
        return reg::UDR0::UDR0_v::read();
    }

    void write(char c) {
        // TODO: Write the ninth bit to UCSR0B, if that is required

        while (!tx_complete())
            ;
        reg::UDR0::UDR0_v::write(c);
    }

    bool char_pending() {
        return reg::UCSR0A::RXC0::read();
    }

private:
    constexpr static uint8_t get_brr_value() {
        // TODO
        return 0;
    }


    void init_peripheral() {
        reg::UCSR0C::UMSEL0n::write(usart_conf::usart_mode);
    }

    void init_data_frame() {
        reg::concat::UCSZ0n::write(usart_conf::character_size);
        reg::UCSR0C::USBS0::write(usart_conf::stop_bits);
        reg::UCSR0C::UCPOL0::write(usart_conf::clock_polarity);
        reg::UCSR0C::UPM0n::write(usart_conf::parity_mode);
    }

    void set_baudrate() {
        constexpr uint8_t brr_value = get_brr_value();

        reg::UBRR0::UBRR_v::write<brr_value>();
    }

    void set_rx_enabled(bool b) {
        reg::UCSR0B::RXEN0::write(b);
    }

    void set_tx_enabled(bool b) {
        reg::UCSR0B::TXEN0::write(b);
    }

    bool tx_complete() {
        return reg::UCSR0A::TXC0::read();
    }
};


} // namespace periph


#endif // NANOLIB_USART_H

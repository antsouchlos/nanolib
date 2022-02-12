#ifndef NANOLIB_USART_H
#define NANOLIB_USART_H


#include "detail/register_map.h"


namespace periph {


enum class Baudrate {
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


template <Baudrate t_baudrate>
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
        reg::UCSR0C::UMSEL0n::write(reg::UCSR0C::UsartMode::asynchronous);
    }

    void init_data_frame() {
        reg::concat::UCSZ0n::write(reg::concat::CharacterSize::_8);
        reg::UCSR0C::USBS0::write(reg::UCSR0C::StopBits::_1);
        reg::UCSR0C::UCPOL0::write(reg::UCSR0C::ClockPolarity::async);
        reg::UCSR0C::UPM0n::write(reg::UCSR0C::ParityMode::disabled);
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

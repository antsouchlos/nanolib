#ifndef NANOLIB_REGISTER_MAP_H
#define NANOLIB_REGISTER_MAP_H


#include "RegisterValue.h"
#include "periph_base.h"


namespace periph { namespace periph_detail {


struct power_register_set {
    struct SMCR {
        constexpr static uint8_t address = 0x53;

        using SE = RegisterValue<SMCR, 0, 1>;
        using S0 = RegisterValue<SMCR, 1, 1>;
        using S1 = RegisterValue<SMCR, 2, 1>;
        using S2 = RegisterValue<SMCR, 3, 1>;
    };

    struct MCUCR {
        constexpr static uint8_t address = 0x55;

        using IVCE  = RegisterValue<MCUCR, 0, 1>;
        using IVSEL = RegisterValue<MCUCR, 1, 1>;
        using PUD   = RegisterValue<MCUCR, 4, 1>;
        using BODSE = RegisterValue<MCUCR, 5, 1>;
        using BODS  = RegisterValue<MCUCR, 6, 1>;
    };

    struct PRR {
        constexpr static uint8_t address = 0x64;

        using PRADC   = RegisterValue<PRR, 0, 1>;
        using PRUSART = RegisterValue<PRR, 1, 1>;
        using PRSPI   = RegisterValue<PRR, 2, 1>;
        using PRTIM1  = RegisterValue<PRR, 3, 1>;
        using PRTIM0  = RegisterValue<PRR, 5, 1>;
        using PRTIM2  = RegisterValue<PRR, 6, 1>;
        using PRTWI   = RegisterValue<PRR, 7, 1>;
    };
};


struct gpio_register_set {
    template <Port t_port>
    struct PORTx {
        constexpr static uint8_t address = 0x25 + 0x3 * get_num(t_port);

        template <Pin t_pin>
        using PORTxn = RegisterValue<PORTx<t_port>, get_num(t_pin), 1>;
    };

    template <Port t_port>
    struct DDRx {
        constexpr static uint8_t address = 0x24 + 0x3 * get_num(t_port);

        template <Pin t_pin>
        using DDxn = RegisterValue<DDRx<t_port>, get_num(t_pin), 1>;
    };

    template <Port t_port>
    struct PINx {
        constexpr static uint8_t address = 0x23 + 0x3 * get_num(t_port);

        template <Pin t_pin>
        using PINxn = RegisterValue<PINx<t_port>, get_num(t_pin), 1>;
    };
};


struct usart_register_set {
    struct UDR0 {
        constexpr static uint8_t address = 0xC6;

        using UDR0_v = RegisterValue<UDR0, 0, 8>;
    };

    struct UCSR0A {
        enum class TransmissionSpeed { normal = 0, double_ = 1 };

        constexpr static uint8_t address = 0xC0 + 0x20;

        using MPCM0 = RegisterValue<UCSR0A, 0, 1>;
        using U2X0  = RegisterValueEnum<UCSR0A, 1, 1, TransmissionSpeed>;
        using UPE0  = RegisterValue<UCSR0A, 2, 1>;
        using DOR0  = RegisterValue<UCSR0A, 3, 1>;
        using FE0   = RegisterValue<UCSR0A, 4, 1>;
        using UDRE0 = RegisterValue<UCSR0A, 5, 1>;
        using TXC0  = RegisterValue<UCSR0A, 6, 1>;
        using RXC0  = RegisterValue<UCSR0A, 7, 1>;
    };

    struct UCSR0B {
        constexpr static uint8_t address = 0xC1;

        using TXB80  = RegisterValue<UCSR0B, 0, 1>;
        using RXB80  = RegisterValue<UCSR0B, 1, 1>;
        using UCSZ02 = RegisterValue<UCSR0B, 2, 1>;
        using TXEN0  = RegisterValue<UCSR0B, 3, 1>;
        using RXEN0  = RegisterValue<UCSR0B, 4, 1>;
        using UDRIE0 = RegisterValue<UCSR0B, 5, 1>;
        using TXCIE0 = RegisterValue<UCSR0B, 6, 1>;
        using RXCIE0 = RegisterValue<UCSR0B, 7, 1>;
    };

    struct UCSR0C {
        // clang-format off
        enum class ClockPolarity : uint8_t {
            tx_rising_rx_falling = 0b0,
            tx_falling_rx_rising = 0b1,
            async = 0b0
        };
        enum class StopBits : uint8_t {
            _1 = 0b0,
            _2 = 0b1
        };
        enum class ParityMode : uint8_t {
            disabled = 0b00,
            even = 0b10,
            odd = 0b11
        };
        enum class UsartMode : uint8_t {
            async = 0b00,
            sync = 0b01,
            master_spi = 0b11
        };

        // clang-format on


        constexpr static uint8_t address = 0xC2 + 0x06;

        using UCPOL0  = RegisterValueEnum<UCSR0C, 0, 1, ClockPolarity>;
        using UCSZ00  = RegisterValue<UCSR0C, 1, 1>;
        using UCSZ01  = RegisterValue<UCSR0C, 2, 1>;
        using USBS0   = RegisterValueEnum<UCSR0C, 3, 1, StopBits>;
        using UPM0n   = RegisterValueEnum<UCSR0C, 4, 2, ParityMode>;
        using UMSEL0n = RegisterValueEnum<UCSR0C, 6, 2, UsartMode>;
    };

    struct UBRR0 {
        constexpr static uint8_t address = 0xC4;

        using UBRR_v = RegisterValue<UBRR0, 0, 12>;
    };

    struct concat {
        enum class CharacterSize : uint8_t {
            _5 = 0b000,
            _6 = 0b001,
            _7 = 0b010,
            _8 = 0b011,
            _9 = 0b111
        };

        using UCSZ0n = RegisterValueEnumConcat<CharacterSize, UCSR0C::UCSZ00,
                                               UCSR0C::UCSZ01, UCSR0B::UCSZ02>;
    };
};


struct system_register_set {
    struct CLKPR {
        enum class ClockDivisionFactor : uint8_t {
            _1   = 0b0000,
            _2   = 0b0001,
            _4   = 0b0010,
            _8   = 0b0011,
            _16  = 0b0100,
            _32  = 0b0101,
            _64  = 0b0110,
            _128 = 0b0111,
            _256 = 0b1000
        };

        constexpr static uint8_t address = 0x61;

        using CLKPSn = RegisterValueEnum<CLKPR, 0, 4, ClockDivisionFactor>;
        using CLKPCE = RegisterValue<CLKPR, 7, 1>;
    };
};


}} // namespace periph::periph_detail


#endif

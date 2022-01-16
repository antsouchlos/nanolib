#ifndef NANOLIB_REGISTER_MAP_H
#define NANOLIB_REGISTER_MAP_H


#include "RegisterValue.h"
#include "periph_base.h"


namespace periph { namespace periph_detail {


struct gpio_register_set {
    struct MCUCR {
        constexpr static uint8_t address = 0x55;

        using IVCE  = RegisterValue<MCUCR, 0, 1>;
        using IVSEL = RegisterValue<MCUCR, 1, 1>;
        using PUD   = RegisterValue<MCUCR, 4, 1>;
        using BODSE = RegisterValue<MCUCR, 5, 1>;
        using BODS  = RegisterValue<MCUCR, 6, 1>;
    };

    template <Port t_port>
    struct PORTx {
        constexpr static uint8_t address = 0x25 + 4 * get_num(t_port);

        template <Pin t_pin>
        using PORTxn = RegisterValue<PORTx<t_port>, get_num(t_pin), 1>;
    };

    template <Port t_port>
    struct DDRx {
        constexpr static uint8_t address = 0x24;

        template <Pin t_pin>
        using DDxn = RegisterValue<DDRx<t_port>, get_num(t_pin), 1>;
    };

    template <Port t_port>
    struct PINx {
        constexpr static uint8_t address = 0x24;

        template <Pin t_pin>
        using PINxn = RegisterValue<PINx<t_port>, get_num(t_pin), 1>;
    };
};


struct timer_register_set {
    struct TCCR0A {
        constexpr static uint8_t address = 0x44;

        using WGM00  = RegisterValue<TCCR0A, 0, 1>;
        using WGM01  = RegisterValue<TCCR0A, 1, 1>;
        using COM0B0 = RegisterValue<TCCR0A, 4, 1>;
        using COM0B1 = RegisterValue<TCCR0A, 5, 1>;
        using COM0A0 = RegisterValue<TCCR0A, 6, 1>;
        using COM0A1 = RegisterValue<TCCR0A, 7, 1>;
    };

    struct TCCR0B {
        constexpr static uint8_t address = 0x45;

        using CS00  = RegisterValue<TCCR0B, 0, 1>;
        using CS01  = RegisterValue<TCCR0B, 1, 1>;
        using CS02  = RegisterValue<TCCR0B, 2, 1>;
        using WGM02 = RegisterValue<TCCR0B, 3, 1>;
        using FOC0B = RegisterValue<TCCR0B, 6, 1>;
        using FOC0A = RegisterValue<TCCR0B, 7, 1>;
    };

    struct TCNT0 {
        constexpr static uint8_t address = 0x46;

        using TCNT0_v = RegisterValue<TCNT0, 0, 8>;
    };

    struct OCR0A {
        constexpr static uint8_t address = 0x47;

        using OCR0A_v = RegisterValue<OCR0A, 0, 8>;
    };

    struct OCR0B {
        constexpr static uint8_t address = 0x48;

        using OCR0B_v = RegisterValue<OCR0B, 0, 8>;
    };

    struct TIMSK0 {
        constexpr static uint8_t address = 0x6E;

        using TOIE0  = RegisterValue<TIMSK0, 0, 1>;
        using OCIE0A = RegisterValue<TIMSK0, 1, 1>;
        using OCIE0B = RegisterValue<TIMSK0, 2, 1>;
    };

    struct TIFR0 {
        constexpr static uint8_t address = 0x35;

        using TOV0  = RegisterValue<TIFR0, 0, 1>;
        using OCF0A = RegisterValue<TIFR0, 1, 1>;
        using OCF0B = RegisterValue<TIFR0, 2, 1>;
    };
};


}} // namespace periph::periph_detail


#endif

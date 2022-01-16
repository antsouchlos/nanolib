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


template <TimerModule t_module>
struct timer_register_set;

template <>
struct timer_register_set<TimerModule::_0> {
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

    struct GTCCR {
        constexpr static uint8_t address = 0x43;

        using PSRSYNC = RegisterValue<GTCCR, 0, 1>;
        using PSRASY  = RegisterValue<GTCCR, 0, 1>;
        using TSM     = RegisterValue<GTCCR, 7, 1>;
    };
};

template <>
struct timer_register_set<TimerModule::_1> {
    struct TCCR1A {
        constexpr static uint8_t address = 0x80;

        using WGM10  = RegisterValue<TCCR1A, 0, 1>;
        using WGM11  = RegisterValue<TCCR1A, 1, 1>;
        using COM1B0 = RegisterValue<TCCR1A, 4, 1>;
        using COM1B1 = RegisterValue<TCCR1A, 5, 1>;
        using COM1A0 = RegisterValue<TCCR1A, 6, 1>;
        using COM1A1 = RegisterValue<TCCR1A, 7, 1>;
    };

    struct TCCR1B {
        constexpr static uint8_t address = 0x81;

        using CS10  = RegisterValue<TCCR1B, 0, 1>;
        using CS11  = RegisterValue<TCCR1B, 1, 1>;
        using CS12  = RegisterValue<TCCR1B, 2, 1>;
        using WGM12 = RegisterValue<TCCR1B, 3, 1>;
        using WGM13 = RegisterValue<TCCR1B, 4, 1>;
        using ICES1 = RegisterValue<TCCR1B, 6, 1>;
        using ICNC1 = RegisterValue<TCCR1B, 7, 1>;
    };

    struct TCCR1C {
        constexpr static uint8_t address = 0x82;

        using FOC1B = RegisterValue<TCCR1C, 6, 1>;
        using FOC1A = RegisterValue<TCCR1C, 7, 1>;
    };

    struct TCNT1 {
        constexpr static uint8_t address = 0x84;

        using TCNT1_v = RegisterValue<TCNT1, 0, 16>;
    };

    struct OCR1A {
        constexpr static uint8_t address = 0x88;

        using OCR1A_v = RegisterValue<OCR1A, 0, 16>;
    };

    struct OCR1B {
        constexpr static uint8_t address = 0x8A;

        using OCR1B_v = RegisterValue<OCR1B, 0, 16>;
    };

    struct ICR1 {
        constexpr static uint8_t address = 0x86;

        using ICR1_v = RegisterValue<ICR1, 0, 16>;
    };

    struct TIMSK1 {
        constexpr static uint8_t address = 0x6F;

        using TOIE1  = RegisterValue<TIMSK1, 0, 1>;
        using OCIE1A = RegisterValue<TIMSK1, 1, 1>;
        using OCIE1B = RegisterValue<TIMSK1, 2, 1>;
        using ICIE1  = RegisterValue<TIMSK1, 5, 1>;
    };

    struct TIFR1 {
        constexpr static uint8_t address = 0x36;

        using TOV1  = RegisterValue<TIFR1, 0, 1>;
        using OCF1A = RegisterValue<TIFR1, 1, 1>;
        using OCF1B = RegisterValue<TIFR1, 2, 1>;
        using ICF1  = RegisterValue<TIFR1, 5, 1>;
    };

    struct GTCCR {
        constexpr static uint8_t address = 0x43;

        using PSRSYNC = RegisterValue<GTCCR, 0, 1>;
        using PSRASY  = RegisterValue<GTCCR, 0, 1>;
        using TSM     = RegisterValue<GTCCR, 7, 1>;
    };
};

template <>
struct timer_register_set<TimerModule::_2> {
    struct TCCR2A {
        constexpr static uint8_t address = 0x44;

        using WGM00  = RegisterValue<TCCR2A, 0, 1>;
        using WGM01  = RegisterValue<TCCR2A, 1, 1>;
        using COM0B0 = RegisterValue<TCCR2A, 4, 1>;
        using COM0B1 = RegisterValue<TCCR2A, 5, 1>;
        using COM0A0 = RegisterValue<TCCR2A, 6, 1>;
        using COM0A1 = RegisterValue<TCCR2A, 7, 1>;
    };

    struct TCCR2B {
        constexpr static uint8_t address = 0x45;

        using CS00  = RegisterValue<TCCR2B, 0, 1>;
        using CS01  = RegisterValue<TCCR2B, 1, 1>;
        using CS02  = RegisterValue<TCCR2B, 2, 1>;
        using WGM02 = RegisterValue<TCCR2B, 3, 1>;
        using FOC0B = RegisterValue<TCCR2B, 6, 1>;
        using FOC0A = RegisterValue<TCCR2B, 7, 1>;
    };

    struct TCNT2 {
        constexpr static uint8_t address = 0x46;

        using TCNT0_v = RegisterValue<TCNT2, 0, 8>;
    };

    struct OCR2A {
        constexpr static uint8_t address = 0x47;

        using OCR0A_v = RegisterValue<OCR2A, 0, 8>;
    };

    struct OCR2B {
        constexpr static uint8_t address = 0x48;

        using OCR0B_v = RegisterValue<OCR2B, 0, 8>;
    };

    struct TIMSK2 {
        constexpr static uint8_t address = 0x6E;

        using TOIE0  = RegisterValue<TIMSK2, 0, 1>;
        using OCIE0A = RegisterValue<TIMSK2, 1, 1>;
        using OCIE0B = RegisterValue<TIMSK2, 2, 1>;
    };

    struct TIFR2 {
        constexpr static uint8_t address = 0x35;

        using TOV0  = RegisterValue<TIFR2, 0, 1>;
        using OCF0A = RegisterValue<TIFR2, 1, 1>;
        using OCF0B = RegisterValue<TIFR2, 2, 1>;
    };

    struct ASSR {
        constexpr static uint8_t address = 0xB6;

        using TCR2BUB = RegisterValue<ASSR, 0, 1>;
        using TCR2AUB = RegisterValue<ASSR, 1, 1>;
        using OCR2BUB = RegisterValue<ASSR, 2, 1>;
        using OCR2AUB = RegisterValue<ASSR, 3, 1>;
        using TCN2UB  = RegisterValue<ASSR, 4, 1>;
        using AS2     = RegisterValue<ASSR, 5, 1>;
        using EXCLK   = RegisterValue<ASSR, 6, 1>;
    };

    struct GTCCR {
        constexpr static uint8_t address = 0x43;

        using PSRSYNC = RegisterValue<GTCCR, 0, 1>;
        using PSRASY  = RegisterValue<GTCCR, 0, 1>;
        using TSM     = RegisterValue<GTCCR, 7, 1>;
    };
};


}} // namespace periph::periph_detail


#endif

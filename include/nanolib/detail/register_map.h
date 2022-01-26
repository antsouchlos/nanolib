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

        constexpr static uint8_t get_timer_pos(TimerModule module) {
            switch (module) {
            case TimerModule::_0:
                return 5;
            case TimerModule::_1:
                return 3;
            case TimerModule::_2:
                return 6;
            }
        };

        using PRADC   = RegisterValue<PRR, 0, 1>;
        using PRUSART = RegisterValue<PRR, 1, 1>;
        using PRSPI   = RegisterValue<PRR, 2, 1>;
        using PRTWI   = RegisterValue<PRR, 7, 1>;

        template <TimerModule t_module>
        using PRTIMn = RegisterValue<PRR, get_timer_pos(t_module), 1>;
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


template <TimerModule t_module>
struct timer_register_set;

template <>
struct timer_register_set<TimerModule::_0> {

    // Register definitions

    struct TCCRnA {
        constexpr static uint8_t address = 0x44;

        using WGM00  = RegisterValue<TCCRnA, 0, 1>;
        using WGM01  = RegisterValue<TCCRnA, 1, 1>;
        using COM0B0 = RegisterValue<TCCRnA, 4, 1>;
        using COM0B1 = RegisterValue<TCCRnA, 5, 1>;
        using COM0A0 = RegisterValue<TCCRnA, 6, 1>;
        using COM0A1 = RegisterValue<TCCRnA, 7, 1>;
    };

    struct TCCRnB {
        constexpr static uint8_t address = 0x45;

        using CS00  = RegisterValue<TCCRnB, 0, 1>;
        using CS01  = RegisterValue<TCCRnB, 1, 1>;
        using CS02  = RegisterValue<TCCRnB, 2, 1>;
        using WGM02 = RegisterValue<TCCRnB, 3, 1>;
        using FOC0B = RegisterValue<TCCRnB, 6, 1>;
        using FOC0A = RegisterValue<TCCRnB, 7, 1>;
    };

    struct TCNTn {
        constexpr static uint8_t address = 0x46;

        using TCNT0_v = RegisterValue<TCNTn, 0, 8>;
    };

    struct OCRnA {
        constexpr static uint8_t address = 0x47;

        using OCR0A_v = RegisterValue<OCRnA, 0, 8>;
    };

    struct OCRnB {
        constexpr static uint8_t address = 0x48;

        using OCR0B_v = RegisterValue<OCRnB, 0, 8>;
    };

    struct TIMSKn {
        constexpr static uint8_t address = 0x6E;

        using TOIE0  = RegisterValue<TIMSKn, 0, 1>;
        using OCIE0A = RegisterValue<TIMSKn, 1, 1>;
        using OCIE0B = RegisterValue<TIMSKn, 2, 1>;
    };

    struct TIFRn {
        constexpr static uint8_t address = 0x35;

        using TOV0  = RegisterValue<TIFRn, 0, 1>;
        using OCF0A = RegisterValue<TIFRn, 1, 1>;
        using OCF0B = RegisterValue<TIFRn, 2, 1>;
    };

    struct GTCCR {
        constexpr static uint8_t address = 0x43;

        using PSRSYNC = RegisterValue<GTCCR, 0, 1>;
        using PSRASY  = RegisterValue<GTCCR, 0, 1>;
        using TSM     = RegisterValue<GTCCR, 7, 1>;
    };

    // Definitions of concatenated and enum-accessible register values

    enum class Prescaler {
        none                  = 0b000,
        _1                    = 0b001,
        _8                    = 0b010,
        _64                   = 0b011,
        _256                  = 0b100,
        _1024                 = 0b101,
        external_falling_edge = 0b110,
        external_rising_edge  = 0b111
    };

    enum class TimerMode {
        normal                     = 0b000,
        pwm_phase_correct          = 0b001,
        clear_on_compare           = 0b010,
        fast_pwm                   = 0b011,
        pwm_phase_correct_out_comp = 0b101,
        fast_pwm_out_comp          = 0b111
    };

    using WGM0n = RegisterValueEnumConcat<TimerMode, TCCRnA::WGM00,
                                          TCCRnA::WGM01, TCCRnB::WGM02>;
    using CS0n  = RegisterValueEnumConcat<Prescaler, TCCRnB::CS00, TCCRnB::CS01,
                                         TCCRnB::CS02>;
};

template <>
struct timer_register_set<TimerModule::_1> {

    // Register definitions

    struct TCCRnA {
        constexpr static uint8_t address = 0x80;

        using WGM10  = RegisterValue<TCCRnA, 0, 1>;
        using WGM11  = RegisterValue<TCCRnA, 1, 1>;
        using COM1B0 = RegisterValue<TCCRnA, 4, 1>;
        using COM1B1 = RegisterValue<TCCRnA, 5, 1>;
        using COM1A0 = RegisterValue<TCCRnA, 6, 1>;
        using COM1A1 = RegisterValue<TCCRnA, 7, 1>;
    };

    struct TCCRnB {
        constexpr static uint8_t address = 0x81;

        using CS10  = RegisterValue<TCCRnB, 0, 1>;
        using CS11  = RegisterValue<TCCRnB, 1, 1>;
        using CS12  = RegisterValue<TCCRnB, 2, 1>;
        using WGM12 = RegisterValue<TCCRnB, 3, 1>;
        using WGM13 = RegisterValue<TCCRnB, 4, 1>;
        using ICES1 = RegisterValue<TCCRnB, 6, 1>;
        using ICNC1 = RegisterValue<TCCRnB, 7, 1>;
    };

    struct TCCRnC {
        constexpr static uint8_t address = 0x82;

        using FOC1B = RegisterValue<TCCRnC, 6, 1>;
        using FOC1A = RegisterValue<TCCRnC, 7, 1>;
    };

    struct TCNTn {
        constexpr static uint8_t address = 0x84;

        using TCNT1_v = RegisterValue<TCNTn, 0, 16>;
    };

    struct OCRnA {
        constexpr static uint8_t address = 0x88;

        using OCR1A_v = RegisterValue<OCRnA, 0, 16>;
    };

    struct OCRnB {
        constexpr static uint8_t address = 0x8A;

        using OCR1B_v = RegisterValue<OCRnB, 0, 16>;
    };

    struct ICRn {
        constexpr static uint8_t address = 0x86;

        using ICR1_v = RegisterValue<ICRn, 0, 16>;
    };

    struct TIMSKn {
        constexpr static uint8_t address = 0x6F;

        using TOIE1  = RegisterValue<TIMSKn, 0, 1>;
        using OCIE1A = RegisterValue<TIMSKn, 1, 1>;
        using OCIE1B = RegisterValue<TIMSKn, 2, 1>;
        using ICIE1  = RegisterValue<TIMSKn, 5, 1>;
    };

    struct TIFRn {
        constexpr static uint8_t address = 0x36;

        using TOV1  = RegisterValue<TIFRn, 0, 1>;
        using OCF1A = RegisterValue<TIFRn, 1, 1>;
        using OCF1B = RegisterValue<TIFRn, 2, 1>;
        using ICF1  = RegisterValue<TIFRn, 5, 1>;
    };

    struct GTCCR {
        constexpr static uint8_t address = 0x43;

        using PSRSYNC = RegisterValue<GTCCR, 0, 1>;
        using PSRASY  = RegisterValue<GTCCR, 0, 1>;
        using TSM     = RegisterValue<GTCCR, 7, 1>;
    };

    // Definitions of concatenated and enum-accessible register values

    enum class Prescaler {
        none                  = 0b000,
        _1                    = 0b001,
        _8                    = 0b010,
        _64                   = 0b011,
        _256                  = 0b100,
        _1024                 = 0b101,
        external_falling_edge = 0b110,
        external_rising_edge  = 0b111
    };

    enum class TimerMode {
        normal                                   = 0b0000,
        pwm_phase_correct_8bit                   = 0b0001,
        pwm_phase_correct_9bit                   = 0b0010,
        pwm_phase_correct_10bit                  = 0b0011,
        ctc_out_comp                             = 0b0100,
        fast_pwm_8bit                            = 0b0101,
        fast_pwm_9bit                            = 0b0110,
        fast_pwm_10bit                           = 0b0111,
        pwm_phase_and_frequency_correct          = 0b1000,
        pwm_phase_and_frequency_correct_out_comp = 0b1001,
        pwm_phase_correct                        = 0b1010,
        pwm_phase_correct_out_comp               = 0b1011,
        ctc                                      = 0b1100,
        fast_pwm                                 = 0b1101,
        fast_pwm_out_comp                        = 0b1111
    };

    using WGM1n =
        RegisterValueEnumConcat<TimerMode, TCCRnA::WGM10, TCCRnA::WGM11,
                                TCCRnB::WGM12, TCCRnB::WGM13>;
    using CS1n = RegisterValueEnumConcat<Prescaler, TCCRnB::CS10, TCCRnB::CS11,
                                         TCCRnB::CS12>;
};

template <>
struct timer_register_set<TimerModule::_2> {

    // Register definitions

    struct TCCRnA {
        constexpr static uint8_t address = 0x44;

        using WGM20  = RegisterValue<TCCRnA, 0, 1>;
        using WGM21  = RegisterValue<TCCRnA, 1, 1>;
        using COM2B0 = RegisterValue<TCCRnA, 4, 1>;
        using COM2B1 = RegisterValue<TCCRnA, 5, 1>;
        using COM2A0 = RegisterValue<TCCRnA, 6, 1>;
        using COM2A1 = RegisterValue<TCCRnA, 7, 1>;
    };

    struct TCCRnB {
        constexpr static uint8_t address = 0x45;

        using CS20  = RegisterValue<TCCRnB, 0, 1>;
        using CS21  = RegisterValue<TCCRnB, 1, 1>;
        using CS22  = RegisterValue<TCCRnB, 2, 1>;
        using WGM22 = RegisterValue<TCCRnB, 3, 1>;
        using FOC2B = RegisterValue<TCCRnB, 6, 1>;
        using FOC2A = RegisterValue<TCCRnB, 7, 1>;
    };

    struct TCNTn {
        constexpr static uint8_t address = 0x46;

        using TCNT2_v = RegisterValue<TCNTn, 0, 8>;
    };

    struct OCRnA {
        constexpr static uint8_t address = 0x47;

        using OCR2A_v = RegisterValue<OCRnA, 0, 8>;
    };

    struct OCRnB {
        constexpr static uint8_t address = 0x48;

        using OCR2B_v = RegisterValue<OCRnB, 0, 8>;
    };

    struct TIMSKn {
        constexpr static uint8_t address = 0x6E;

        using TOIE2  = RegisterValue<TIMSKn, 0, 1>;
        using OCIE2A = RegisterValue<TIMSKn, 1, 1>;
        using OCIE2B = RegisterValue<TIMSKn, 2, 1>;
    };

    struct TIFRn {
        constexpr static uint8_t address = 0x35;

        using TOV2  = RegisterValue<TIFRn, 0, 1>;
        using OCF2A = RegisterValue<TIFRn, 1, 1>;
        using OCF2B = RegisterValue<TIFRn, 2, 1>;
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

    // Definitions of concatenated and enum-accessible register values

    enum class Prescaler {
        none  = 0b000,
        _1    = 0b001,
        _8    = 0b010,
        _32   = 0b011,
        _64   = 0b100,
        _128  = 0b101,
        _256  = 0b110,
        _1024 = 0b111
    };

    enum class TimerMode {
        normal                     = 0b000,
        pwm_phase_correct          = 0b001,
        clear_on_compare           = 0b010,
        fast_pwm                   = 0b011,
        pwm_phase_correct_out_comp = 0b101,
        fast_pwm_out_comp          = 0b111
    };

    using WGM2n = RegisterValueEnumConcat<TimerMode, TCCRnA::WGM20,
                                          TCCRnA::WGM21, TCCRnB::WGM22>;
    using CS2n  = RegisterValueEnumConcat<Prescaler, TCCRnB::CS20, TCCRnB::CS21,
                                         TCCRnB::CS22>;
};


}} // namespace periph::periph_detail


#endif

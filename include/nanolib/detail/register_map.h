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


}} // namespace periph::periph_detail


#endif

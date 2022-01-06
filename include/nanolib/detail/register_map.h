#ifndef ARDUINO_LIB_REGISTER_MAP
#define ARDUINO_LIB_REGISTER_MAP


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


}} // namespace periph::periph_detail


#endif

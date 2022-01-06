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

    template <Port Port_>
    struct PORTx {
        constexpr static uint8_t address = 0x25 + 4 * get_num(Port_);

        template <Pin Pin_>
        using PORTxn = RegisterValue<PORTx<Port_>, get_num(Pin_), 1>;
    };

    template <Port Port_>
    struct DDRx {
        constexpr static uint8_t address = 0x24;

        template <Pin Pin_>
        using DDxn = RegisterValue<DDRx<Port_>, get_num(Pin_), 1>;
    };

    template <Port Port_>
    struct PINx {
        constexpr static uint8_t address = 0x24;

        template <Pin Pin_>
        using PINxn = RegisterValue<PINx<Port_>, get_num(Pin_), 1>;
    };
};


}} // namespace periph::periph_detail


#endif

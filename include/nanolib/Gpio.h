#ifndef ARDUINO_LIB_GPIO_H
#define ARDUINO_LIB_GPIO_H


#include "detail/register_map.h"


namespace periph {


// TODO: Add support for pullup resistors
template <Port Port_, Pin Pin_, Direction Direction_>
class Gpio {

    using reg = periph_detail::gpio_register_set;

public:
    Gpio() {
        set_direction();
    }

    void write(bool value) {
        static_assert(Direction_ == Direction::out,
                      "Only output pins can be written to");
        reg::PORTx<Port_>::template PORTxn<Pin_>::write(value);
    }

    bool read() {
        if constexpr (Direction_ == Direction::out) {
            return reg::PORTx<Port_>::template PORTxn<Pin_>::template read_as<
                bool>();
        } else {
            // TODO: Check if this works
            return reg::PINx<Port_>::template PINxn<Pin_>::read();
        }
    }

private:
    void set_direction() {
        if constexpr (Direction_ == Direction::out) {
            reg::DDRx<Port_>::template DDxn<Pin_>::template write<1>();
        } else {
            reg::DDRx<Port_>::template DDxn<Pin_>::template write<0>();
        }
    }
};


} // namespace periph


#endif

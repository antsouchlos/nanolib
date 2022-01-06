#ifndef ARDUINO_LIB_GPIO_H
#define ARDUINO_LIB_GPIO_H


#include "detail/register_map.h"


namespace periph {


// TODO: Add support for pullup resistors
template <Port t_port, Pin t_pin, Direction t_direction>
class Gpio {

    using reg = periph_detail::gpio_register_set;

public:
    Gpio() {
        set_direction();
    }

    void write(bool value) {
        static_assert(t_direction == Direction::out,
                      "Only output pins can be written to");
        reg::PORTx<t_port>::template PORTxn<t_pin>::write(value);
    }

    bool read() {
        if constexpr (t_direction == Direction::out) {
            return reg::PORTx<t_port>::template PORTxn<t_pin>::template read_as<
                bool>();
        } else {
            // TODO: Check if this works
            return reg::PINx<t_port>::template PINxn<t_pin>::read();
        }
    }

private:
    void set_direction() {
        if constexpr (t_direction == Direction::out) {
            reg::DDRx<t_port>::template DDxn<t_pin>::template write<1>();
        } else {
            reg::DDRx<t_port>::template DDxn<t_pin>::template write<0>();
        }
    }
};


} // namespace periph


#endif

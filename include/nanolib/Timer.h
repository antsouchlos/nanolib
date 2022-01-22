#ifndef NANOLIB_TIMER_H
#define NANOLIB_TIMER_H


#include "detail/register_map.h"


namespace periph {

template <TimerModule t_module>
class Timer;

// TODO: Implement this properly. This is only a test to see if everything works
template <>
class Timer<TimerModule::_0> {

    using reg     = periph_detail::timer_register_set<TimerModule::_0>;
    using pow_reg = periph_detail::power_register_set;

public:
    Timer() {
        // Atmega328P Datasheet 14.2, p.74
        pow_reg::PRR::PRTIMn<TimerModule::_0>::write(0);

        // Set timer to normal mode
        reg::TCCRnB::WGM02::write(0);

        // Start the timer by selecting the clock source
        reg::TCCRnB::CS02::write(1);
    }

private:
};


} // namespace periph


#endif

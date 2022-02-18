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
    Timer(System& system) : m_system{&system} {
        // Atmega328P Datasheet 14.2, p.74
        pow_reg::PRR::PRTIMn<TimerModule::_0>::write(0);

        reg::WGM0n::write<reg::TimerMode::normal>();

        // Start the timer by selecting the clock source
        reg::CS0n::write<reg::Prescaler::_256>();
    }

private:
    System* m_system;
};


} // namespace periph


#endif

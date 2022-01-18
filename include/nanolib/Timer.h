#ifndef NANOLIB_TIMER_H
#define NANOLIB_TIMER_H


#include "detail/register_map.h"


namespace periph {

template <TimerModule t_module>
class Timer;

// TODO: Implement this properly. This is only a test to see if everything works
template <>
class Timer<TimerModule::_0> {

    using reg = periph_detail::timer_register_set<TimerModule::_0>;

public:
    Timer() {

    }

private:
};


} // namespace periph


#endif

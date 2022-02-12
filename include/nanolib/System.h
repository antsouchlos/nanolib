#ifndef NANOLIB_SYSTEM_H
#define NANOLIB_SYSTEM_H


#ifndef NANOLIB_CLOCKSPEED
#error "Clockspeed not set"
#endif

#ifndef NANOLIB_CLOCKDIV
#define NANOLIB_CLOCKDIV ClockDivisionFactor::_1
#endif


#include "detail/periph_base.h"
#include "detail/register_map.h"
#include "detail/type_traits.h"


namespace periph {


class System {

    friend class Interrupt_LockGuard;

    using ClockDivisionFactor =
        periph_detail::system_register_set::CLKPR::ClockDivisionFactor;

    using reg = periph_detail::system_register_set;

public:
    static System& get_instance() {
        static System system;
        return system;
    }

    System(const System&) = delete;
    void operator=(const System&) = delete;

    Clockspeed get_clockspeed() {
        return NANOLIB_CLOCKSPEED;
    }

private:
    System() {
        static_assert(
            std::is_same<decltype(NANOLIB_CLOCKSPEED), Clockspeed>::value,
            "NANOLIB_CLOCKSPEED must be of type Clockspeed");

        static_assert(std::is_same<decltype(NANOLIB_CLOCKDIV),
                                   ClockDivisionFactor>::value,
                      "NANOLIB_CLOCKDIV must be of type ClockDivisionFactor");

        reg::CLKPR::CLKPSn::write(NANOLIB_CLOCKDIV);
    }

    static void disable_interrupts() {
        // See avr-libc/interrupt.h
        __asm__ __volatile__("cli" ::: "memory");
    }

    static void enable_interrupts() {
        // See avr-libc/interrupt.h
        __asm__ __volatile__("sei" ::: "memory");
    }
};


class Interrupt_LockGuard {
public:
    explicit Interrupt_LockGuard(System& system) : m_system{system} {
        m_system.disable_interrupts();
    }

    ~Interrupt_LockGuard() {
        m_system.enable_interrupts();
    }

    Interrupt_LockGuard(const Interrupt_LockGuard&) = delete;

    Interrupt_LockGuard& operator=(const Interrupt_LockGuard&) = delete;

private:
    System& m_system;
};


} // namespace periph


#endif // NANOLIB_SYSTEM_H
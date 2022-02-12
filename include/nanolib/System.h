#ifndef NANOLIB_SYSTEM_H
#define NANOLIB_SYSTEM_H


#ifndef CLOCKSPEED
#error "Clockspeed not set"
#endif


#include "detail/periph_base.h"
#include "detail/type_traits.h"


namespace periph {


class System {

    friend class Interrupt_LockGuard;

public:

    static System& get_instance() {
        static System system;
        return system;
    }

    System(const System&)         = delete;
    void operator=(const System&) = delete;

    Clockspeed get_clockspeed() {
        return CLOCKSPEED;
    }

private:
    System() {
        static_assert(std::is_same<decltype(CLOCKSPEED), Clockspeed>::value,
                      "CLOCKSPEED must be of type Clockspeed");
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
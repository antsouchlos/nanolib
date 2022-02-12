#ifndef NANOLIB_SYSTEM_H
#define NANOLIB_SYSTEM_H


#ifndef CLOCKSPEED
#error "Clockspeed not set"
#endif


#include "detail/periph_base.h"
#include "detail/type_traits.h"


namespace periph {


class System {
public:
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
    explicit Interrupt_LockGuard() {
        System::disable_interrupts();
    }

    ~Interrupt_LockGuard() {
        System::enable_interrupts();
    }

    Interrupt_LockGuard(const Interrupt_LockGuard&) = delete;

    Interrupt_LockGuard& operator=(const Interrupt_LockGuard&) = delete;
};


} // namespace periph


#endif // NANOLIB_SYSTEM_H
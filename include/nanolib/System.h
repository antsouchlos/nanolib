#ifndef NANOLIB_SYSTEM_H
#define NANOLIB_SYSTEM_H

// Hardware dependent
#define NANOLIB_HW_OSC_FREQ (uint32_t)(16000u)

// Hardware dependent; ATMEGA328p datasheed 13.12.2, p.60
#define NANOLIB_DEFAULT_CLOCKDIV ClockDivisionFactor::_8

#ifndef NANOLIB_CLOCKDIV
#define NANOLIB_CLOCKDIV NANOLIB_DEFAULT_CLOCKDIV
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

    constexpr static uint16_t get_clock_div_num(ClockDivisionFactor div) {
        switch (div) {
            case ClockDivisionFactor::_1:
                return 1;
            case ClockDivisionFactor::_2:
                return 2;
            case ClockDivisionFactor::_4:
                return 4;
            case ClockDivisionFactor::_8:
                return 8;
            case ClockDivisionFactor::_16:
                return 16;
            case ClockDivisionFactor::_32:
                return 32;
            case ClockDivisionFactor::_64:
                return 64;
            case ClockDivisionFactor::_128:
                return 128;
            case ClockDivisionFactor::_256:
                return 256;
        }
    }

public:
    static System& get_instance() {
        static System system;
        return system;
    }

    System(const System&) = delete;
    void operator=(const System&) = delete;

    constexpr static uint16_t get_clockspeed_kHz() {
        constexpr uint16_t result = NANOLIB_HW_OSC_FREQ / get_clock_div_num(NANOLIB_CLOCKDIV);
        return result;
    }

private:
    System() {
        static_assert(std::is_same<decltype(NANOLIB_CLOCKDIV),
                                   ClockDivisionFactor>::value,
                      "NANOLIB_CLOCKDIV must be of type ClockDivisionFactor");

        if constexpr (NANOLIB_CLOCKDIV != NANOLIB_DEFAULT_CLOCKDIV) {
            reg::CLKPR::CLKPSn::write(NANOLIB_CLOCKDIV);
        }
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
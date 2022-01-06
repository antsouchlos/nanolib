#ifndef ARDUINO_LIB_REGISTERVALUE_H
#define ARDUINO_LIB_REGISTERVALUE_H


#include <stdint.h>

#include "const_util.h"
#include "type_traits.h" // avr-g++ doesn't seem to recognize type_traits,
                         // so this is used as a drop-in replacement


namespace periph { namespace periph_detail {


using uint_single_t = uint8_t;
using uint_double_t = uint16_t;


/*
 *
 * Metaprogramming utilities
 *
 */


template <uint_single_t t_length>
struct requires_double_int_t {
    static_assert(t_length <= sizeof(uint_double_t) * 8,
                  "Length too long even for double int type");

    enum { value = (t_length > sizeof(uint_single_t) * 8) };
};


// TODO: Can the last template parameter be nameless?
template <uint_single_t t_length, typename T = void>
struct required_int_t {
    using type = uint_single_t;
};

template <uint_single_t t_length>
struct required_int_t<
    t_length,
    typename std::enable_if<requires_double_int_t<t_length>::value>::type> {

    using type = uint_double_t;
};


/*
 *
 * class RegisterValue
 *
 */


template <typename t_register, uint8_t t_start_bit, uint8_t t_length>
class RegisterValue {
private:
    using uint_t = typename required_int_t<t_length>::type;

    static volatile uint_t* get_addr_ptr() {
        return reinterpret_cast<volatile uint_t*>(t_register::address);
    }

public:
    template <uint_double_t t_value>
    static void write() {
        static_assert(has_no_more_bits<t_value, t_length>::value,
                      "More bits written to register value then it is long");

        write(static_cast<uint_t>(t_value));
    }

    static void write(uint_t value) {
        constexpr static uint_t mask = static_cast<uint_t>(
            ~(get_bitmask_ones<uint_t, t_length>::value << t_start_bit));

        uint_t data = *get_addr_ptr();
        data        = data & mask;
        data        = data | (value << t_start_bit);

        *get_addr_ptr() = data;
    }

    static uint_t read() {
        constexpr uint_t mask = static_cast<uint_t>(
            get_bitmask_ones<uint_t, t_length>::value << t_start_bit);

        uint_t data = *get_addr_ptr();
        data        = (data & mask) >> t_start_bit;

        return data;
    }
};


}} // namespace periph::periph_detail


#endif

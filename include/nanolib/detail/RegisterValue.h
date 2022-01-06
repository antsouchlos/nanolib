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


template <uint_single_t Length_> struct requires_double_int_t {
    static_assert(Length_ <= sizeof(uint_double_t) * 8,
                  "Length too long even for double int type");

    enum { value = (Length_ > sizeof(uint_single_t) * 8) };
};


template <uint_single_t Length_, typename T = void> struct required_int_t {
    using type = uint_single_t;
};

template <uint_single_t Length_>
struct required_int_t<
    Length_,
    typename std::enable_if<requires_double_int_t<Length_>::value>::type> {

    using type = uint_double_t;
};


/*
 *
 * class RegisterValue
 *
 */


template <typename Register_, uint8_t StartBit_, uint8_t Length_>
class RegisterValue {
private:
    using uint_t = typename required_int_t<Length_>::type;

    static volatile uint_t* get_addr_ptr() {
        return reinterpret_cast<volatile uint_t*>(Register_::address);
    }

public:
    template <uint_double_t Value> static void write() {
        static_assert(has_no_more_bits<Value, Length_>::value,
                      "More bits written to register value then it is long");

        write(static_cast<uint_t>(Value));
    }

    static void write(uint_t value) {
        constexpr static uint_t mask = static_cast<uint_t>(
            ~(get_bitmask_ones<uint_t, Length_>::value << StartBit_));

        uint_t data = *get_addr_ptr();
        data = data & mask;
        data = data | (value << StartBit_);

        *get_addr_ptr() = data;
    }

    static uint_t read() {
        constexpr uint_t mask = static_cast<uint_t>(
            get_bitmask_ones<uint_t, Length_>::value << StartBit_);

        uint_t data = *get_addr_ptr();
        data = (data & mask) >> StartBit_;

        return data;
    }
};


}} // namespace periph::periph_detail


#endif
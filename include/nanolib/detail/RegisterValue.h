#ifndef NANOLIB_REGISTERVALUE_H
#define NANOLIB_REGISTERVALUE_H


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

    template <typename enum_t, class, typename... register_vals_t>
    friend class RegisterValueEnumConcat_impl;

protected:
    constexpr static uint8_t start_bit = t_start_bit;
    constexpr static uint8_t length    = t_length;

    using uint_t = typename required_int_t<t_length + t_start_bit>::type;

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


/*
 *
 * class RegisterValueEnum
 *
 */


template <typename t_register, uint8_t t_start_bit, uint8_t t_length,
          typename enum_t>
class RegisterValueEnum : RegisterValue<t_register, t_start_bit, t_length> {

    using base = RegisterValue<t_register, t_start_bit, t_length>;

public:
    static void write(enum_t value) {
        base::write(static_cast<typename base::uint_t>(value));
    }

    static enum_t read() {
        return static_cast<enum_t>(base::read());
    }
};


/*
 *
 * class RegisterValueEnumConcat
 *
 */


template <typename T>
struct is_reg_val : std::false_type {};

template <typename t_register, uint8_t t_start_bit, uint8_t t_length>
struct is_reg_val<RegisterValue<t_register, t_start_bit, t_length>>
    : std::true_type {};


template <typename enum_t, class, typename... register_vals_t>
class RegisterValueEnumConcat_impl {
    constexpr static uintmax_t get_val_length() {
        return (register_vals_t::length + ...);
    }

    using uint_t = typename required_int_t<get_val_length()>::type;

public:
    template <enum_t t_value>
    static void write() {
        static_assert(has_no_more_bits<static_cast<uint_t>(t_value),
                                       get_val_length()>::value,
                      "More bits written to register value then it is long");

        write(t_value);
    }

    static void write(enum_t value) {
        uint_t int_value = static_cast<uint_t>(value);

        (write_val<register_vals_t>(int_value), ...);
    }

    static enum_t read() {
        uint_t int_result  = 0;
        uint_t total_shift = 0;

        (read_val<register_vals_t>(int_result, total_shift), ...);

        return static_cast<enum_t>(int_result);
    }

private:
    template <typename register_val_t>
    static void write_val(uint_t& int_value) {
        uint_t temp = int_value;
        int_value   = int_value >> register_val_t::length;

        constexpr uint_t mask =
            periph_detail::get_bitmask_ones<uint_t,
                                            register_val_t::length>::value;

        register_val_t::write(temp & mask);
    }

    template <typename register_val_t>
    static void read_val(uint_t& int_value, uint_t& total_shift) {
        uint_t temp = register_val_t::read();
        int_value   = int_value + (temp << total_shift);

        total_shift += register_val_t::length;
    }
};


template <typename enum_t, typename... register_vals_t>
using RegisterValueEnumConcat = RegisterValueEnumConcat_impl<
    enum_t,
    typename std::enable_if<((is_reg_val<register_vals_t>::value) &&
                             ...)>::type,
    register_vals_t...>;


}} // namespace periph::periph_detail


#endif

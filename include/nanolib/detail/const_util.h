#ifndef NANOLIB_CONST_UTIL_H
#define NANOLIB_CONST_UTIL_H


#include "type_traits.h"
#include <stdint.h>


namespace periph { namespace periph_detail {


/*
 *
 * Related to bit masks
 *
 */


template <typename int_t, uint8_t t_num>
struct get_bitmask_ones {
    enum {
        value = static_cast<int_t>(-(t_num != 0)) &
                (static_cast<int_t>(-1) >> (sizeof(int_t) * 8 - t_num))
    };
};


template <uint16_t t_value, uint16_t t_bits>
struct has_no_more_bits {
    constexpr static uint16_t value =
        ((t_value & ~(get_bitmask_ones<uint16_t, t_bits>::value)) == 0);
};


/*
 *
 * Compile-time enum range checking
 *
 */


#if defined(__clang__) && (__clang_major__ >= 4)
#define CLANG_PRETTY_FUNC
#endif
#if defined(__GNUC__) && (__GNUC__ >= 9)
#define GCC_PRETTY_FUNC
#endif


template <typename enum_t, enum_t t_value>
struct is_valid_enum_val_impl {

    using int_t = typename std::underlying_type<enum_t>::type;

private:
    constexpr static int_t find_substr(const char* s, const char* target,
                                       uint8_t target_len, int_t start = 0) {
        int_t i = start;
        int_t num_matched = 0;

        while (s[i] != ']') {
            if (s[i] == target[num_matched])
                ++num_matched;
            else
                num_matched = 0;

            ++i;
            if (num_matched == target_len) return (i - target_len);
        }

        return 0;
    }

    constexpr static bool contains(const char* s, char c, int_t start = 0) {
        int_t i = start;

        while (s[i] != ']') {
            if (s[i] == c) return true;

            ++i;
        }

        return false;
    }

public:
    constexpr static bool valid() {
#if defined(GCC_PRETTY_FUNC)
        constexpr const char* s = __PRETTY_FUNCTION__;
        return !contains(s, '(',
                         find_substr(s, "t_value", 7,find_substr(s, "(")));
#elif defined(CLANG_PRETTY_FUNC)
        constexpr const char* s = __PRETTY_FUNCTION__;
        return contains(s, '(', find_substr(s, "t_value", 7, find_substr(s, "(")));
#else
#error "Cannot build with compiler that does not support __PRETTY_FUNC__"
        return false;
#endif
    }
};

template <typename enum_t, enum_t t_val>
constexpr bool is_valid_enum_val() {
    return is_valid_enum_val_impl<enum_t, t_val>::valid();
}


}} // namespace periph::periph_detail


#endif

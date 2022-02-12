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
 * Various
 *
 */


template <typename int_t>
constexpr inline int_t max_int_value() {
    int_t result = 0;

    if constexpr (static_cast<int_t>(-1) < 0) {
        result = static_cast<int_t>(
            get_bitmask_ones<uintmax_t, sizeof(int_t) * 8 - 1>::value);
    } else {
        result = static_cast<int_t>(
            get_bitmask_ones<uintmax_t, sizeof(uintmax_t) * 8>::value);
    }

    return result;
}

template <typename int_t>
constexpr inline int_t min_int_value() {
    int_t result = 0;

    if constexpr (static_cast<int_t>(-1) < 0) {
        result = -max_int_value<int_t>() - 1;
    } else {
        result = 0;
    }

    return result;
}


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
private:
    constexpr static uint16_t find_substr(const char* s, const char* target,
                                          uint8_t  target_len,
                                          uint16_t start = 0) {
        uint16_t i           = start;
        uint16_t num_matched = 0;

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

    constexpr static bool contains(const char* s, char c, uint16_t start = 0) {
        uint16_t i = start;

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
                         find_substr(s, "t_value", 7, find_substr(s, "(", 1)));
#elif defined(CLANG_PRETTY_FUNC)
        constexpr const char* s = __PRETTY_FUNCTION__;
        return contains(s, '(',
                        find_substr(s, "t_value", 7, find_substr(s, "(", 1)));
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


template <typename enum_t, typename std::underlying_type<enum_t>::type t_index,
          typename std::underlying_type<enum_t>::type t_min_index, bool t_valid>
struct max_enum_val_impl;

template <typename enum_t, typename std::underlying_type<enum_t>::type t_index,
          typename std::underlying_type<enum_t>::type t_min_index>
struct max_enum_val_impl<enum_t, t_index, t_min_index, false> {
    constexpr static bool valid =
        is_valid_enum_val<enum_t, static_cast<enum_t>(t_index)>();
    constexpr static typename std::underlying_type<enum_t>::type value =
        max_enum_val_impl<enum_t, t_index - 1, t_min_index, valid>::value;
};

template <typename enum_t,
          typename std::underlying_type<enum_t>::type t_min_index>
struct max_enum_val_impl<enum_t, t_min_index, t_min_index, false> {
    constexpr static typename std::underlying_type<enum_t>::type value =
        t_min_index;
};

template <typename enum_t, typename std::underlying_type<enum_t>::type t_index,
          typename std::underlying_type<enum_t>::type t_min_index>
struct max_enum_val_impl<enum_t, t_index, t_min_index, true> {
    constexpr static typename std::underlying_type<enum_t>::type value =
        t_index + 1;
};


template <typename enum_t>
constexpr typename std::underlying_type<enum_t>::type max_enum_val() {
    using int_t = typename std::underlying_type<enum_t>::type;

    static_assert(sizeof(int_t) <= 1, "Cannot use type larger than uint8_t");

    // Reduce compile times in case of error: Make sure this code is not
    // compiled (If sizeof(int_t) > 1 this definitely runs into the template
    // recursion limit)
    if constexpr (sizeof(int_t) <= 1) {
        constexpr int_t max_val = max_int_value<int_t>();
        constexpr int_t min_val = min_int_value<int_t>();

        return max_enum_val_impl<enum_t, max_val, min_val, false>::value;
    }
}


template <typename enum_t, typename std::underlying_type<enum_t>::type t_index,
          typename std::underlying_type<enum_t>::type t_max_index, bool t_valid>
struct min_enum_val_impl;

template <typename enum_t, typename std::underlying_type<enum_t>::type t_index,
          typename std::underlying_type<enum_t>::type t_max_index>
struct min_enum_val_impl<enum_t, t_index, t_max_index, false> {
    constexpr static bool valid =
        is_valid_enum_val<enum_t, static_cast<enum_t>(t_index)>();
    constexpr static typename std::underlying_type<enum_t>::type value =
        min_enum_val_impl<enum_t, t_index + 1, t_max_index, valid>::value;
};

template <typename enum_t,
          typename std::underlying_type<enum_t>::type t_max_index>
struct min_enum_val_impl<enum_t, t_max_index, t_max_index, false> {
    constexpr static typename std::underlying_type<enum_t>::type value =
        t_max_index;
};

template <typename enum_t, typename std::underlying_type<enum_t>::type t_index,
          typename std::underlying_type<enum_t>::type t_max_index>
struct min_enum_val_impl<enum_t, t_index, t_max_index, true> {
    constexpr static typename std::underlying_type<enum_t>::type value =
        t_index - 1;
};


template <typename enum_t>
constexpr typename std::underlying_type<enum_t>::type min_enum_val() {
    using int_t = typename std::underlying_type<enum_t>::type;

    static_assert(sizeof(int_t) <= 1, "Cannot use type larger than uint8_t");

    // Reduce compile times in case of error: Make sure this code is not
    // compiled (If sizeof(int_t) > 1 this definitely runs into the template
    // recursion limit)
    if constexpr (sizeof(int_t) <= 1) {
        constexpr int_t max_val = max_int_value<int_t>();
        constexpr int_t min_val = min_int_value<int_t>();

        return min_enum_val_impl<enum_t, min_val, max_val, false>::value;
    }
}


/*
 *
 * STATIC_WARNING
 *
 */

template <bool>
struct STATIC_WARNING_FAILURE;

template <>
struct STATIC_WARNING_FAILURE<true> {
    struct type {};
};
template <>
struct STATIC_WARNING_FAILURE<false> {
    struct type;
};

template <bool t_b>
constexpr int raise_warning() {
    constexpr
        typename periph::periph_detail::STATIC_WARNING_FAILURE<t_b>::type* ptr =
            nullptr;
    delete ptr;

    return 0;
}

#define STATIC_WARNING(B, MSG)                                                 \
    constexpr int _NANOLIB_DUMMY = periph::periph_detail::raise_warning<B>();



}} // namespace periph::periph_detail


#endif

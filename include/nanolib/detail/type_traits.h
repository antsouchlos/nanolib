#ifndef NANOLIB_TYPE_TRAITS_H
#define NANOLIB_TYPE_TRAITS_H

#ifndef REQUIRES_TYPE_TRAITS_REP
#include <type_traits>
#else


// avr-g++ doesn't seem to recognize type_traits,
// so this is used as a drop-in replacement


namespace std {


template <bool t_b>
struct enable_if;

template <>
struct enable_if<true> {
    using type = void;
};
template <>
struct enable_if<false> {};


struct true_type {
    constexpr static bool value = true;
};
struct false_type {
    constexpr static bool value = false;
};


template <typename T, typename U>
struct is_same : std::false_type {};
template <typename T>
struct is_same<T, T> : std::true_type {};


} // namespace std


#endif

#endif
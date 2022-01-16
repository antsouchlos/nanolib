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


} // namespace std


#endif

#endif
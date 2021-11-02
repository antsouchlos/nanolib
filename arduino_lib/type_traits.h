#ifndef ARDUINO_LIB_TYPE_TRAITS
#define ARDUINO_LIB_TYPE_TRAITS


namespace std {


template<bool B>
struct enable_if;

template <> struct enable_if<true> { using type = void; };
template <> struct enable_if<false> {};


}

#endif
#ifndef ARDUINO_LIB_PERIPH_BASE
#define ARDUINO_LIB_PERIPH_BASE


#include <stdint.h>


namespace periph {


// clang-format off

enum class Port      { B, C, D };
enum class Pin       { _0, _1, _2, _3, _4, _5, _6, _7 };
enum class Direction { in, out };

// clang-format on


template <typename enum_t>
constexpr inline uint16_t get_num(enum_t val) {
    return static_cast<uint16_t>(val);
}


}; // namespace periph


#endif

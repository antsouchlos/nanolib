#ifndef ARDUINO_LIB_PERIPH_BASE
#define ARDUINO_LIB_PERIPH_BASE


#include <stdint.h>


namespace periph {


enum class Port      {B, C, D};
enum class Pin       {_0, _1, _2, _3, _4, _5, _6, _7};
enum class Direction {in, out};

template<typename EnumT_>
constexpr inline uint16_t get_num(EnumT_ val) { return static_cast<uint16_t>(val); }


};


#endif


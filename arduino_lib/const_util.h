#ifndef ARDUINO_LIB_CONSTEXPR_UTIL
#define ARDUINO_LIB_CONSTEXPR_UTIL


namespace periph { namespace periph_detail {


// template<uint16_t Base_, uint16_t Exponent_>
// struct constexpr_pow {
//    constexpr static uint16_t value = Base_ * constexpr_pow<Base_, Exponent_ -
//    1>::value;
//};
//
// template<uint16_t Base_>
// struct constexpr_pow<Base_, 0> {
//    constexpr static uint16_t value = 1;
//};


template <typename T, uint8_t Num_> struct get_bitmask_ones {
    enum {
        value = static_cast<T>(-(Num_ != 0)) &
                (static_cast<T>(-1) >> (sizeof(T) * 8 - Num_))
    };
};


template <uint16_t Value_, uint16_t Bits_> struct has_no_more_bits {
    constexpr static uint16_t value =
        ((Value_ & ~(get_bitmask_ones<uint16_t, Bits_>::value)) == 0);
};


}} // namespace periph::periph_detail


#endif

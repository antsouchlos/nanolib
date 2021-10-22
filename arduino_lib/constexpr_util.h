#ifndef CONSTEXPR_UTIL
#define CONSTEXPR_UTIL


namespace periph { namespace periph_detail {


template<uint16_t Base_, uint16_t Exponent_>
struct constexpr_pow {
	constexpr static uint16_t value = Base_ * constexpr_pow<Base_, Exponent_ - 1>::value;
};

template<uint16_t Base_>
struct constexpr_pow<Base_, 0> {
	constexpr static uint16_t value = 1;
};


template<uint16_t Value_, uint16_t Bits_>
struct has_no_more_bits {
	constexpr static uint16_t value = ( (Value_ & ~(constexpr_pow<2, Bits_>::value - 1)) == 0 );
};


}} // namespace periph::periph_detail


#endif


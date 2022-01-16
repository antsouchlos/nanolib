#ifndef NANOLIB_CONST_UTIL_H
#define NANOLIB_CONST_UTIL_H


namespace periph { namespace periph_detail {


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


}} // namespace periph::periph_detail


#endif

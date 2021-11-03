#include <gtest/gtest.h>
#include <arduino_lib/RegisterValue.h>


using namespace periph::periph_detail;


namespace {


    TEST(ConstUtil, get_bitmask_ones) {
        constexpr static uint8_t mask1 = get_bitmask_ones<uint8_t, 8>::value;
        constexpr static uint16_t mask2 = get_bitmask_ones<uint16_t, 8>::value;
        constexpr static uint16_t mask3 = get_bitmask_ones<uint16_t, 0>::value;
        constexpr static uint16_t mask4 = get_bitmask_ones<uint16_t, 16>::value;
        constexpr static uint16_t mask5 = get_bitmask_ones<uint16_t, 14>::value;

        EXPECT_EQ(mask1, 0b1111'1111u);
        EXPECT_EQ(mask2, 0b1111'1111u);
        EXPECT_EQ(mask3, 0u);
        EXPECT_EQ(mask4, 0b1111'1111'1111'1111u);
        EXPECT_EQ(mask5, 0b0011'1111'1111'1111u);
    }

    TEST(ConstUtil, has_no_more_bits) {
        constexpr static uint8_t num1 = 0;
        constexpr static uint16_t num2 = 0b1111'1111'1111'1111u;
        constexpr static uint16_t num3 = 0b0011'1111'0000'0011u;
        constexpr static uint8_t num4 = 0b0001'0000;

        constexpr static bool result1 = has_no_more_bits<num1, 0>::value;
        constexpr static bool result2 = has_no_more_bits<num2, 16>::value;
        constexpr static bool result3 = has_no_more_bits<num3, 14>::value;
        constexpr static bool result4 = has_no_more_bits<num4, 5>::value;

        EXPECT_EQ(result1, true);
        EXPECT_EQ(result2, true);
        EXPECT_EQ(result3, true);
        EXPECT_EQ(result4, true);
    }

}

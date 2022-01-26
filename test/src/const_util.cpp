#include <gtest/gtest.h>
#include <limits>
#include <nanolib/detail/const_util.h>


using namespace periph::periph_detail;


namespace {


TEST(ConstUtil, get_bitmask_ones) {
    constexpr static uint8_t  mask1 = get_bitmask_ones<uint8_t, 8>::value;
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
    constexpr static uint8_t  num1 = 0;
    constexpr static uint16_t num2 = 0b1111'1111'1111'1111u;
    constexpr static uint16_t num3 = 0b0011'1111'0000'0011u;
    constexpr static uint8_t  num4 = 0b0001'0000;

    constexpr static bool result1 = has_no_more_bits<num1, 0>::value;
    constexpr static bool result2 = has_no_more_bits<num2, 16>::value;
    constexpr static bool result3 = has_no_more_bits<num3, 14>::value;
    constexpr static bool result4 = has_no_more_bits<num4, 5>::value;

    EXPECT_EQ(result1, true);
    EXPECT_EQ(result2, true);
    EXPECT_EQ(result3, true);
    EXPECT_EQ(result4, true);
}

TEST(ConstUtil, max_int_value) {
    EXPECT_EQ(std::numeric_limits<uint8_t>::max(), max_int_value<uint8_t>());
    EXPECT_EQ(std::numeric_limits<int8_t>::max(), max_int_value<int8_t>());

    EXPECT_EQ(std::numeric_limits<uint16_t>::max(), max_int_value<uint16_t>());
    EXPECT_EQ(std::numeric_limits<int16_t>::max(), max_int_value<int16_t>());

    EXPECT_EQ(std::numeric_limits<uint32_t>::max(), max_int_value<uint32_t>());
    EXPECT_EQ(std::numeric_limits<int32_t>::max(), max_int_value<int32_t>());
}

TEST(ConstUtil, min_int_value) {
    EXPECT_EQ(std::numeric_limits<uint8_t>::min(), min_int_value<uint8_t>());
    EXPECT_EQ(std::numeric_limits<int8_t>::min(), min_int_value<int8_t>());

    EXPECT_EQ(std::numeric_limits<uint16_t>::min(), min_int_value<uint16_t>());
    EXPECT_EQ(std::numeric_limits<int16_t>::min(), min_int_value<int16_t>());

    EXPECT_EQ(std::numeric_limits<uint32_t>::min(), min_int_value<uint32_t>());
    EXPECT_EQ(std::numeric_limits<int32_t>::min(), min_int_value<int32_t>());
}

TEST(ConstUtil, is_valid_enum_val) {
    enum class Enum : int8_t {
        A = -5,
        B = 3,
        C = 4,
        D = 5,
        E = 6,
        F = 9,
        G = 28
    };

    constexpr bool b1 = is_valid_enum_val<Enum, Enum::A>();
    constexpr bool b2 = is_valid_enum_val<Enum, Enum::B>();
    constexpr bool b3 = is_valid_enum_val<Enum, static_cast<Enum>(4)>();

    constexpr bool b4 = is_valid_enum_val<Enum, static_cast<Enum>(29)>();
    constexpr bool b5 = is_valid_enum_val<
        Enum,
        static_cast<Enum>(
            std::numeric_limits<std::underlying_type<Enum>::type>::max())>();
    constexpr bool b6 = is_valid_enum_val<
        Enum,
        static_cast<Enum>(
            std::numeric_limits<std::underlying_type<Enum>::type>::min())>();

    EXPECT_TRUE(b1);
    EXPECT_TRUE(b2);
    EXPECT_TRUE(b3);

    EXPECT_FALSE(b4);
    EXPECT_FALSE(b5);
    EXPECT_FALSE(b6);
}

TEST(ConstUtil, max_enum_val) {
    constexpr int8_t  int8_t_min  = std::numeric_limits<int8_t>::min();
    constexpr int8_t  int8_t_max  = std::numeric_limits<int8_t>::max();
    constexpr uint8_t uint8_t_min = std::numeric_limits<uint8_t>::min();
    constexpr uint8_t uint8_t_max = std::numeric_limits<uint8_t>::max();

    // clang-format off

    enum class Enum  : int8_t  { A = int8_t_min,  B = int8_t_max  };
    enum class Enum2 : int8_t  { A = int8_t_min,  B = 0           };
    enum class Enum3 : int8_t  { A = 100,         B = 35          };
    enum class Enum4 : uint8_t { A = uint8_t_min, B = uint8_t_max };
    enum class Enum5 : uint8_t { A = uint8_t_min, B = 1          };
    enum class Enum6 : uint8_t { A = 100,         B = 35          };

    // clang-format on

    EXPECT_EQ(max_enum_val<Enum>(), int8_t_max);
    EXPECT_EQ(max_enum_val<Enum2>(), 0);
    EXPECT_EQ(max_enum_val<Enum3>(), 100);
    EXPECT_EQ(max_enum_val<Enum4>(), uint8_t_max);
    EXPECT_EQ(max_enum_val<Enum5>(), 1);
    EXPECT_EQ(max_enum_val<Enum6>(), 100);
}

// TODO
// TEST(ConstUtil, min_enum_val) {
//}

} // namespace

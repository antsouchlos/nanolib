#include <gtest/gtest.h>
#include <nanolib/detail/RegisterValue.h>


using namespace periph::periph_detail;


namespace {


/*
 *
 * Emulate the hardware registers with simple buffers
 *
 */


uint8_t REG1_buffer[2] = {0};
uint8_t REG2_buffer[2] = {0};
uint8_t REG3_buffer[2] = {0};

struct register_set {
    struct REG1 {
        static std::size_t address;
        using VAL1 = RegisterValue<REG1, 0, 8>;
        using VAL2 = RegisterValue<REG1, 0, 4>;
    };

    struct REG2 {
        static std::size_t address;
        using VAL1 = RegisterValue<REG2, 0, 4>;
        using VAL2 = RegisterValue<REG2, 4, 3>;
    };

    struct REG3 {
        static std::size_t address;
        using VAL1 = RegisterValue<REG3, 0, 2>;
        using VAL2 = RegisterValue<REG3, 2, 9>;
        using VAL3 = RegisterValue<REG3, 11, 5>;
    };

    enum class ConcatValue {
        A = 0b1111'1111'1111'1111,
        B = 0b0000'0111'1111'1100,
        C = 0b1111'1111'1100'1111,
        D = 0b0000'0111'1111'1111,
        E = 0b0000'0000'0000'0000,
        F = 0b0000'0000'0000'0000
    };

    // clang-format off

    using CONCAT_VAL1 = RegisterValueEnumConcat<ConcatValue, REG1::VAL1,
                                                             REG2::VAL2,
                                                             REG3::VAL3>;

    using CONCAT_VAL2 = RegisterValueEnumConcat<ConcatValue, REG3::VAL1,
                                                             REG3::VAL2>;

    using CONCAT_VAL3 = RegisterValueEnumConcat<ConcatValue, REG3::VAL1,
                                                             REG1::VAL2>;
    // clang-format on
};

std::size_t register_set::REG1::address =
    reinterpret_cast<std::size_t>(&REG1_buffer);
std::size_t register_set::REG2::address =
    reinterpret_cast<std::size_t>(&REG2_buffer);
std::size_t register_set::REG3::address =
    reinterpret_cast<std::size_t>(&REG3_buffer);


/*
 *
 * Actual tests
 *
 */


TEST(RegisterValueEnumConcat, write_basic) {
    uint16_t A_v = static_cast<uint16_t>(register_set::ConcatValue::A);
    //    uint16_t B_v = static_cast<uint16_t>(register_set::ConcatValue::B);
    //    uint16_t C_v = static_cast<uint16_t>(register_set::ConcatValue::C);
    //    uint16_t D_v = static_cast<uint16_t>(register_set::ConcatValue::D);

    register_set::CONCAT_VAL1::write<register_set::ConcatValue::A>();
    EXPECT_EQ(REG1_buffer[0], (A_v & get_bitmask_ones<uint16_t, 8>::value));
    EXPECT_EQ((REG2_buffer[0] >> 4),
              ((A_v >> 8) & get_bitmask_ones<uint16_t, 3>::value));
    EXPECT_EQ((REG3_buffer[1] >> 3),
              ((A_v >> 11) & get_bitmask_ones<uint16_t, 5>::value));

    // register_set::CONCAT_VAL2::write<register_set::ConcatValue::D>();

    //    EXPECT_EQ(((A_v >> 8) & get_bitmask_ones<uint16_t, 3>::value), 0xfa);
    //    EXPECT_EQ(REG1_buffer[0], 0xfa);
    //    EXPECT_EQ(REG1_buffer[1], 0xfa);
    //    EXPECT_EQ(REG2_buffer[0], 0xfa);
    //    EXPECT_EQ(REG2_buffer[1], 0xfa);
    //    EXPECT_EQ(REG3_buffer[0], 0xfa);
    //    EXPECT_EQ(REG3_buffer[1], 0xfa);
}

TEST(RegisterValueEnumConcat, write_no_overflow) {
    for (auto& elem : REG1_buffer)
        elem = 0b11111111u;
    for (auto& elem : REG2_buffer)
        elem = 0b11111111u;
    for (auto& elem : REG3_buffer)
        elem = 0b11111111u;

    //    register_set::REG1::VAL1::write<val1>();
    //    EXPECT_EQ(REG1_buffer[1], 0b11111111u);
    //
    //    register_set::REG2::VAL1::write<val2>();
    //    register_set::REG2::VAL2::write<val3>();
    //    EXPECT_EQ(REG2_buffer[1], 0b11111111u);
    //
    //    register_set::REG3::VAL1 ::write<val3>();
    //    EXPECT_EQ(REG3_buffer[1], 0);
}

TEST(RegisterValueEnumConcat, read_basic) {
    //    *(reinterpret_cast<uint16_t*>(REG1_buffer)) = 0b001100'11110000u;
    //    EXPECT_EQ(REG1_buffer[0], register_set::REG1::VAL1::read());
    //
    //    *(reinterpret_cast<uint16_t*>(REG2_buffer)) = 0b000001'00001000u;
    //    EXPECT_EQ(REG2_buffer[0] & 0b00001111u,
    //    register_set::REG2::VAL1::read()); EXPECT_EQ(REG2_buffer[0] &
    //    0b11110000u, register_set::REG2::VAL2::read());
    //
    //    *(reinterpret_cast<uint16_t*>(REG3_buffer)) = 0b000000'10001111u;
    //    EXPECT_EQ(*(reinterpret_cast<uint16_t*>(REG3_buffer)),
    //              register_set::REG3::VAL1::read());
}


} // namespace

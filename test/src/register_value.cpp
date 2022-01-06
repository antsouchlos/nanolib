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
    };

    struct REG2 {
        static std::size_t address;
        using VAL1 = RegisterValue<REG2, 0, 4>;
        using VAL2 = RegisterValue<REG2, 4, 4>;
    };

    struct REG3 {
        static std::size_t address;
        using VAL1 = RegisterValue<REG3, 0, 16>;
    };
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


TEST(RegisterValue, write_basic) {
    constexpr uint8_t  val1 = 0b01010101u;
    constexpr uint8_t  val2 = 0b1101u;
    constexpr uint8_t  val3 = 0b0111u;
    constexpr uint16_t val4 = 0b11110000'10011111u;

    for (auto& elem : REG1_buffer)
        elem = 0b10111010u;
    for (auto& elem : REG2_buffer)
        elem = 0b10101111u;
    for (auto& elem : REG3_buffer)
        elem = 0b11100011u;

    register_set::REG1::VAL1::write<val1>();
    EXPECT_EQ(REG1_buffer[0], val1);

    register_set::REG2::VAL1::write<val2>();
    register_set::REG2::VAL2::write<val3>();
    EXPECT_EQ(REG2_buffer[0], val2 | (val3 << 4));

    register_set::REG3::VAL1::write<val4>();
    uint16_t reg_value = *(reinterpret_cast<uint16_t*>(REG3_buffer));
    EXPECT_EQ(reg_value, val4);
}

TEST(RegisterValue, write_no_overflow) {
    constexpr uint8_t val1 = 0b01010101u;
    constexpr uint8_t val2 = 0b1101u;
    constexpr uint8_t val3 = 0b0111u;

    for (auto& elem : REG1_buffer)
        elem = 0b11111111u;
    for (auto& elem : REG2_buffer)
        elem = 0b11111111u;
    for (auto& elem : REG3_buffer)
        elem = 0b11111111u;

    register_set::REG1::VAL1::write<val1>();
    EXPECT_EQ(REG1_buffer[1], 0b11111111u);

    register_set::REG2::VAL1::write<val2>();
    register_set::REG2::VAL2::write<val3>();
    EXPECT_EQ(REG2_buffer[1], 0b11111111u);

    register_set::REG3::VAL1 ::write<val3>();
    EXPECT_EQ(REG3_buffer[1], 0);
}

TEST(RegisterValue, read_basic) {
    *(reinterpret_cast<uint16_t*>(REG1_buffer)) = 0b001100'11110000u;
    EXPECT_EQ(REG1_buffer[0], register_set::REG1::VAL1::read());

    *(reinterpret_cast<uint16_t*>(REG2_buffer)) = 0b000001'00001000u;
    EXPECT_EQ(REG2_buffer[0] & 0b00001111u, register_set::REG2::VAL1::read());
    EXPECT_EQ(REG2_buffer[0] & 0b11110000u, register_set::REG2::VAL2::read());

    *(reinterpret_cast<uint16_t*>(REG3_buffer)) = 0b000000'10001111u;
    EXPECT_EQ(*(reinterpret_cast<uint16_t*>(REG3_buffer)),
              register_set::REG3::VAL1::read());
}


} // namespace

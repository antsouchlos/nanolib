#include <gtest/gtest.h>
#include <arduino_lib/RegisterValue.h>


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

    std::size_t register_set::REG1::address = reinterpret_cast<std::size_t>(&REG1_buffer);
    std::size_t register_set::REG2::address = reinterpret_cast<std::size_t>(&REG2_buffer);
    std::size_t register_set::REG3::address = reinterpret_cast<std::size_t>(&REG3_buffer);


    /*
     *
     * Actual tests
     *
     */


    TEST(WriteTests, basic_write) {
        constexpr uint8_t val1 = 0b01010101;
        constexpr uint8_t val2 = 0b1101;
        constexpr uint8_t val3 = 0b0111;
        constexpr uint16_t val4 = 0b11110000'10011111;

        for (auto& elem : REG1_buffer)
            elem = 0b10111010;
        for (auto& elem : REG2_buffer)
            elem = 0b10101111;
        for (auto& elem : REG3_buffer)
            elem = 0b11100011;

        register_set::REG1::VAL1::write<val1>();
        EXPECT_EQ(REG1_buffer[0], val1);

        register_set::REG2::VAL1::write<val2>();
        register_set::REG2::VAL2::write<val3>();
        EXPECT_EQ(REG2_buffer[0], val2 | (val3 << 4));

        register_set::REG3::VAL1::write<val4>();
        uint16_t reg_value = *(reinterpret_cast<uint16_t *>(REG3_buffer));
        EXPECT_EQ(reg_value, val4);
    }

    TEST(WriteTests, no_overflow) {
        constexpr uint8_t val1 = 0b01010101;
        constexpr uint8_t val2 = 0b1101;
        constexpr uint8_t val3 = 0b0111;

        for (auto& elem : REG1_buffer)
            elem = 0b11111111;
        for (auto& elem : REG2_buffer)
            elem = 0b11111111;
        for (auto& elem : REG3_buffer)
            elem = 0b11111111;

        register_set::REG1::VAL1::write<val1>();
        EXPECT_EQ(REG1_buffer[1], 0b11111111);

        register_set::REG2::VAL1::write<val2>();
        register_set::REG2::VAL2::write<val3>();
        EXPECT_EQ(REG2_buffer[1], 0b11111111);

        register_set::REG3::VAL1 ::write<val3>();
        EXPECT_EQ(REG3_buffer[1], 0);
    }


}

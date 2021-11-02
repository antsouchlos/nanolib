#include <gtest/gtest.h>
#include <arduino_lib/RegisterValue.h>


using namespace periph::periph_detail;


namespace {


uint_single_t REG1_buffer[sizeof(uint_single_t)*8] = {0};

struct register_set {
    struct REG1 {
        static std::size_t address;

        using VAL1 = RegisterValue<REG1, 0, 8>;
    };
};

std::size_t register_set::REG1::address = reinterpret_cast<std::size_t>(&REG1_buffer);

TEST(RegisterValue, write) {
    constexpr uint_single_t val = 0b01010101;
    register_set::REG1::VAL1::write<0b01010101>();
    EXPECT_EQ(register_set::REG1::VAL1::read_as<uint_single_t>(), val);
}


}

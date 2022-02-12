#include <gtest/gtest.h>
#include <limits>

#include <nanolib/Usart.h>

using namespace periph;


namespace periph {

template <uint32_t t_baudrate, typename usart_conf = usart_conf_def>
class UsartTest {
public:
    uint32_t get_brr_value() {
        return Usart<t_baudrate, usart_conf>::get_brr_value();
    }
};

} // namespace periph


namespace {


TEST(Usart, get_brr_value_enum) {
    UsartTest<Baudrate::_2_4_kHz>   test1;
    UsartTest<Baudrate::_115_2_kHz> test2;
    UsartTest<Baudrate::_1_MHz>     test3;
    UsartTest<Baudrate::_76_8_kHz>  test4;
    UsartTest<Baudrate::_9_6_kHz>   test5;

    EXPECT_EQ(test1.get_brr_value(), 51);
    EXPECT_EQ(test2.get_brr_value(), 0);
    EXPECT_EQ(test3.get_brr_value(), 0);
    EXPECT_EQ(test4.get_brr_value(), 1);
    EXPECT_EQ(test5.get_brr_value(), 12);
}

TEST(Usart, get_brr_value_int) {
    UsartTest<std::numeric_limits<uint32_t>::max()> test1;
    UsartTest<1>                                    test2;

    EXPECT_EQ(test1.get_brr_value(), 0);
    EXPECT_EQ(test2.get_brr_value(),
              (periph_detail::get_bitmask_ones<uint16_t, 12>::value));
}

// TEST(Usart, get_brr_value_double_speed) {
//     // TODO
// }


} // namespace

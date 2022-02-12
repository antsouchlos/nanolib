#include <gtest/gtest.h>

#define NANOLIB_CLOCKDIV ClockDivisionFactor::_8
#define NANOLIB_HW_OSC_FREQ_Hz (uint32_t)(16000000u)

#include <nanolib/System.h>


using namespace periph;


namespace {


TEST(System, get_clockspeed) {
    EXPECT_EQ(System::get_clockspeed_Hz(), 2000000);
}


} // namespace

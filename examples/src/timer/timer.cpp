#define NANOLIB_HW_OSC_FREQ_Hz (uint32_t)(16000000u)
#define NANOLIB_CLOCKDIV       ClockDivisionFactor::_1

#include <nanolib/Gpio.h>
#include <nanolib/System.h>
#include <nanolib/Timer.h>
#include <nanolib/Usart.h>


using namespace periph;


int main() {
    System& system = System::get_instance();

    Timer<TimerModule::_0>                 timer;
    Gpio<Port::B, Pin::_5, Direction::out> led;
    Usart<Baudrate::_1_MHz>                usart{system};

    while (true) {
        usart.write(usart.read());
        led.write(!led.read());
    }
}
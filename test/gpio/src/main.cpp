#include <arduino_lib/Gpio.h>


using namespace periph;


int main() {
    Gpio<Port::B, Pin::_6, Direction::out> led;

    led.write(1);

    return 0;
}

#include <nanolib/Gpio.h>


using namespace periph;


int main() {
    Gpio<Port::B, Pin::_4, Direction::in>  input;
    Gpio<Port::B, Pin::_5, Direction::out> led;

    while (true) {
        led.write(input.read());
    }

    return 0;
}

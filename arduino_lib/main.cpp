#include <util/delay.h>
#include "Gpio.h"


int main() {
	using namespace periph;

	Gpio<Port::B, Pin::_5, Direction::out> led;
	led.write(1);

	while(true) {
		led.write(!led.read());

		_delay_ms(500);
	}

	return 0;
};

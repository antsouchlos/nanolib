#include <nanolib/Usart.h>


using namespace periph;


// clang-format off
using custom_usart_conf = usart_conf_t<ClockPolarity::async,
                                      StopBits::_2,
                                      ParityMode::enabled,
                                      UsartMode::async,
                                      CharacterSize::_7>;
// clang-format on


int main() {
    Usart<Baudrate::_115_2_KHz, custom_usart_conf> usart;

    while (true) {
        while (!usart.char_pending())
            ;

        usart.write(usart.read());
    }

    return 0;
}
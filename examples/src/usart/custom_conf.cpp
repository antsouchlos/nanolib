#include <nanolib/Usart.h>


using namespace periph;


// clang-format off
using custom_usart_conf = usart_conf_t<ClockPolarity::tx_falling_rx_rising,
                                      StopBits::_2,
                                      ParityMode::even,
                                      UsartMode::sync,
                                      CharacterSize::_8,
                                      TransmissionSpeed::normal>;
// clang-format on


int main() {
    System& system = System::get_instance();
    Usart<Baudrate::_115_2_kHz, custom_usart_conf> usart{system};

    while (true) {
        while (!usart.char_pending())
            ;

        usart.write(usart.read());
    }

    return 0;
}
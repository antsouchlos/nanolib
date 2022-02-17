#define NANOLIB_HW_OSC_FREQ_Hz (uint32_t)(16000000u)
#define NANOLIB_CLOCKDIV       ClockDivisionFactor::_1


#include <nanolib/Usart.h>


using namespace periph;


// clang-format off
using custom_usart_conf = usart_conf_t<ClockPolarity::async,
                                      StopBits::_1,
                                      ParityMode::even,
                                      UsartMode::async,
                                      CharacterSize::_8,
                                      TransmissionSpeed::double_>;
// clang-format on


int main() {
    System&                           system = System::get_instance();
    Usart<2000000, custom_usart_conf> usart{system};

    while (true) {
        usart.write(usart.read());
    }

    return 0;
}
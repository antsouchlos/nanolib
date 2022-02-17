#define NANOLIB_HW_OSC_FREQ_Hz                   (uint32_t)(16000000u)
#define NANOLIB_CLOCKDIV                         ClockDivisionFactor::_1
#define NANOLIB_USART_BAUDRATE_MAX_ERROR_PERCENT 2

#include <nanolib/System.h>
#include <nanolib/Usart.h>


using namespace periph;


int main() {
    System&                 system = System::get_instance();
    Usart<Baudrate::_1_MHz> usart{system};

    while (true) {
        usart.write(usart.read());
    }

    return 0;
}

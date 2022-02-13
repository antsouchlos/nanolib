#define NANOLIB_USART_BAUDRATE_MAX_ERROR_PERCENT 20

#include <nanolib/System.h>
#include <nanolib/Usart.h>

using namespace periph;


int main() {
    System&                     system = System::get_instance();
    Usart<Baudrate::_115_2_kHz> usart{system};

    while (true) {
        while (!usart.char_pending())
            ;

        usart.write(usart.read());
    }

    return 0;
}
#include <nanolib/Usart.h>


using namespace periph;


int main() {
    Usart<Baudrate::_115_2_KHz> usart;

    while (true) {
        while (!usart.char_pending())
            ;

        usart.write(usart.read());
    }

    return 0;
}
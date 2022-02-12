#include <nanolib/Usart.h>
#include <nanolib/System.h>


using namespace periph;


int main() {
    System& system = System::get_instance();
    Usart<Baudrate::_1_MHz> usart{system};

    while (true) {
        while (!usart.char_pending())
            ;

        usart.write(usart.read());
    }

    return 0;
}
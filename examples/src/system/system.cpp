#define CLOCKSPEED Clockspeed::_2


#include <nanolib/System.h>


using namespace periph;


void do_smth() {
    System& system = System::get_instance();

    Interrupt_LockGuard abcdef(system);
}

int main() {
    System& system = System::get_instance();

    do_smth();
}

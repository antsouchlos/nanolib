#ifndef NANOLIB_SYSTEM_H
#define NANOLIB_SYSTEM_H


#ifndef CLOCKSPEED
#error "Clockspeed not set"
#endif


#include "detail/periph_base.h"
#include "detail/type_traits.h"


namespace periph {


class System {
public:
    System() {
        static_assert(std::is_same<decltype(CLOCKSPEED), Clockspeed>::value,
                      "CLOCKSPEED must be of type Clockspeed");
    }

private:
};


} // namespace periph


#endif // NANOLIB_SYSTEM_H

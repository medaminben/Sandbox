#include "Geo_impl.h"
#include <Sandbox/Geo/Geo.h>

namespace Sandbox {
    namespace Geo {
       unsigned int  get_the_answer(void) {
                return get_the_answer_impl();
        }

        int  multiply(int lhs, int rhs) {
             return multiply_impl(lhs,rhs);
        }
    }
}

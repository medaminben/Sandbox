#include "Core_impl.h"
#include <Sandbox/Core/Core.h>

namespace Sandbox {
    namespace Core {
       unsigned int  get_the_answer(void) {
                return get_the_answer_impl();
        }

        int  multiply(int lhs, int rhs) {
             return multiply_impl(lhs,rhs);
        }
    }
}

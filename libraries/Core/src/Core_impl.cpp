#include "Core_impl.h"
#include <Sandbox/Core/Core.h>

namespace Sandbox {
    namespace Core {
        unsigned int get_the_answer_impl(void) {
            return 42; 
        }

        int multiply_impl(int lhs, int rhs) {
            return lhs * rhs; 
        }
    }
}

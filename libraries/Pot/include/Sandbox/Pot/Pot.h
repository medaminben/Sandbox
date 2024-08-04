#ifndef POT_H
#define POT_H
#include "INIfile.h"

namespace Sandbox { namespace Pot {
    int  inline  get_the_answer() {return 42U;};
    int  inline  multiply(int l, int r) { return l*r;};

}}


namespace Sp = Sandbox::Pot;
#endif // POT_H




#include "constants.h"

const int root_number = 30;

int main () {
    std::cout << "------------ from main" << "\n" <<
    "const_number = "      <<  const_number << 
    ",\t&const_number = "  << &const_number << "\n" <<
    "cxpr_number  = "      <<  cxpr_number  << 
    ",\t&cxpr_number  = "  << &cxpr_number  << "\n" <<
    "root_number = "       <<  root_number  << 
    ",\t&root_number  = "  << &root_number  << "\n" <<
    "\n";

    printConsts();

   return 0;
}
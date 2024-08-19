#include <iostream>
#include <iomanip>

int run_time_get_function() { return 10;}

// constexpr: the expression should be evaluated at compile time
constexpr int compile_time_get_function() { return 10;}

void run_time_function();
void compile_time_function();

int main () {
   run_time_function();
   compile_time_function();
   return 0;
}



void compile_time_function() {
    std::cout 
    << "\n -------------- Compile time initialization" 
    << "\n";

    const int n = compile_time_get_function();
    int* ptr = (int*)(&n);

    *ptr = 0;
    std::cout <<
    "n =          " << std::setw(3) << n           
    << ",\t &n  = "  <<&n   << "\n" <<
    "*(&n) =      " << std::setw(3) << *(&n)       
    << ",\t &n  = "  <<&n   << "\n" <<
    "*((int*)&n) =" << std::setw(3) << *((int*)&n) 
    << ",\t &n  = "  <<&n   << "\n" <<
    "*ptr =       " << std::setw(3) << *ptr        
    << ",\t ptr = " << ptr << "\n" <<
    "\n";
}
void run_time_function() {
    std::cout 
    << "\n -------------- Run time initialization" 
    << "\n";

    const int n = run_time_get_function();
    int* ptr = (int*)(&n);

    *ptr = 0;
    std::cout <<
    "n =          " << std::setw(3) << n           
    << ",\t &n  = "  <<&n   << "\n" <<
    "*(&n) =      " << std::setw(3) << *(&n)       
    << ",\t &n  = "  <<&n   << "\n" <<
    "*((int*)&n) =" << std::setw(3) << *((int*)&n) 
    << ",\t &n  = "  <<&n   << "\n" <<
    "*ptr =       " << std::setw(3) << *ptr        
    << ",\t ptr = " << ptr << "\n"  <<
    "\n";
}

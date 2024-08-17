#include <iostream>
#include <type_traits>
#include <concepts>
/////////////////////////////////////////////////
#ifdef __FUNCSIG__
#define SIGNATURE __FUNCSIG__
#else  
#define SIGNATURE __PRETTY_FUNCTION__
#endif
/////////////////////////////////////////////////
template<typename T1, typename T2>
auto raw_modulo(T1 n, T2 d) { 
    return n % d;
}

void test_modulo_raw() {
    std::cout << "["  << SIGNATURE << "]" << "\n";

    int n = 9; 
    int d = 5;
    // double d = 5; -> Error: invalid operands  
    // of types 'int' and 'double' to binary 
    // 'operator%' return n % d;
    std::cout << raw_modulo(n,d) 
    << " = " << n << " % " << d << "\n";
}
/////////////////////////////////////////////////
template<typename T1, typename T2,
         typename = std::enable_if_t<std::is_integral_v<T1> && 
                                     std::is_integral_v<T2>>>
auto traits_modulo(T1 n, T2 d) { 
    return n % d;
}

void test_modulo_traits() {
    std::cout << "["  << SIGNATURE << "]" << "\n";

    int n = 9; 
    int d = 5;
    // double d = 5;// -> Error: no matching function
    // for call to 'traits_modulo(int&, double&)' 
    // std::cout << traits_modulo(n,d)
    std::cout << traits_modulo(n,d) 
    << " = " << n << " % " << d << "\n";
}
/////////////////////////////////////////////////
template<typename T1, typename T2>
auto requires_modulo(T1 n, T2 d) requires requires { n % d; } { 
    return n % d;
}

void test_modulo_requires() {
    std::cout << "["  << SIGNATURE << "]" << "\n";

    int n = 9; 
    int d = 5;
    //double d = 5;// -> Error: no matching function
    // for call to 'requires_modulo(int&, double&)' 
    // std::cout << requires_modulo(n,d)
    std::cout << requires_modulo(n,d) 
    << " = " << n << " % " << d << "\n";
}

/////////////////////////////////////////////////
//using conceot, makes life  easer 
template<typename T>
concept isIntegral = std::is_integral_v<T>;

isIntegral auto constraint_modulo(isIntegral auto n, 
                                  isIntegral auto d) { 
    return n % d;
}

void test_modulo_constraint() {
    std::cout << "["  << SIGNATURE << "]" << "\n";

    int n = 9; 
    int d = 5;
    //double d = 5;// -> Error: no matching function
    // for call to 'requires_modulo(int&, double&)' 
    // std::cout << requires_modulo(n,d)
    std::cout << constraint_modulo(n,d) 
    << " = " << n << " % " << d << "\n";
}


int main () {
    test_modulo_raw();
    test_modulo_traits();
    test_modulo_requires();
    test_modulo_constraint();
    return 0;
}
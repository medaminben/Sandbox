#include <iostream>
#include <type_traits>
#include <utility>
#include "lambda_valid.h"

inline constexpr auto 
isDefaultConstructible = 
    [](auto wrapped_instance) 
        -> decltype((void)decltype(StripWrappedType(wrapped_instance))()) 
    {};


// this will strip the type of wrapped_instance 
// and then call the default constructor 
inline constexpr auto 
hasDefaultConstructor = 
        is_valid(isDefaultConstructible);

template<typename T>
inline constexpr bool 
has_default_constructor = 
    hasDefaultConstructor(WrappedInstance<T>);


class NonConstructible { 
    private: 
    NonConstructible(); 
};
class Constructible {};

int main() {
    // boolalpha to print true and false as litteral
     std::cout << std::boolalpha              << 
    "Is [Constructible] Constuctible ? \t"    << 
    has_default_constructor<Constructible>    
    << "\n"                                   <<
    "Is [NonConstructible] Constuctible ? \t" << 
    has_default_constructor<NonConstructible>       
    << "\n"                                   <<
    "Is [size_t] Constuctible ? \t\t"         << 
    has_default_constructor<int>    
    << "\n"                                   <<
    "Is [size_t&] Constuctible ? \t\t"        << 
    has_default_constructor<int&> 
    << "\n" ;
    return 0;
}
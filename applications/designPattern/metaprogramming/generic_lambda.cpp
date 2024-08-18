#include <iostream>
#include <type_traits>
#include <utility>
#include "lambda_valid.h"

inline constexpr auto isDefaultConstructible = [](auto wrapped_instance) 
            -> decltype((void)decltype(StripWrappedType(wrapped_instance))()) {};


//this will strip the type of wrapped_instance and then call the default constructor 
inline constexpr auto hasDefaultConstructor = is_valid(isDefaultConstructible);

template<typename T>
inline constexpr bool has_default_constructor = hasDefaultConstructor(WrappedInstance<T>);


class NonConstructible { private: NonConstructible(); };
class Constructible    {};

int main() {

     std::cout << std::boolalpha << // boolalpha to print true and false as litteral
    "Is [Constructible] Constuctible ? \t"                            << 
    hasDefaultConstructor(WrappedInstance<Constructible>)    << "\n" <<
    
    "Is [NonConstructible] Constuctible ? \t"                          << 
    hasDefaultConstructor(WrappedInstance<NonConstructible>) << "\n" <<

    "Is [size_t] Constuctible ?   \t\t"                                << 
    hasDefaultConstructor(WrappedInstance<size_t>)           << "\n" <<

    "Is [size_t&] Constuctible ?  \t\t"                                << 
    hasDefaultConstructor(WrappedInstance<size_t&>)          << "\n"  <<

    "Is [Constructible] Constuctible ? \t"                             << 
    has_default_constructor<int>    << "\n" <<
    
    "Is [NonConstructible] Constuctible ? \t"                          << 
    has_default_constructor<int&> << "\n" ;
    return 0;
}
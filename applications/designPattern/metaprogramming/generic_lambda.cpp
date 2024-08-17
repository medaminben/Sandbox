#include <iostream>
#include <type_traits>
#include <utility>


/// Helpers
template<typename LambdaType, typename... ArgTypes, 
         typename = decltype(std::declval<LambdaType>()(std::declval<ArgTypes&&>()...))>  
std::true_type  is_implemented(void*);

template<typename LambdaType, typename... ArgTypes> 
std::false_type is_implemented(...); //<- ... a catch all function if SFINEAE'd out

/// Lambdas
//define a lambda that takes an instance of a lamda object 
//and checks whether calling it with the arguments is valid.

inline constexpr auto
is_valid = [](auto lambda_instance) {
     return [](auto&&... lambda_args) { 
        return decltype(is_implemented<decltype(lambda_instance), 
                                       decltype(lambda_args)&&... 
                                       >(nullptr)){};
    };
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// helper template to represent a type as a value
template<typename T> struct WrappedType { using Type = T; };

template<typename T> 
constexpr auto WrappedInstance = WrappedType<T>{};

///Forward declarations
// Type stripper
// helper to unwrap a wrapped type in unevaluated contexts
template<typename T> 
T StripWrappedType(WrappedType<T>);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
constexpr auto isDefaultConstructible = [](auto wrapped_instance) 
            -> decltype((void)decltype(StripWrappedType(wrapped_instance))()) {};


//this will strip the type of wrapped_instance and then call the default constructor 
constexpr auto hasDefaultConstructor = is_valid(isDefaultConstructible);

 template<typename T>
 constexpr bool has_default_constructor = hasDefaultConstructor(WrappedInstance<T>);


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
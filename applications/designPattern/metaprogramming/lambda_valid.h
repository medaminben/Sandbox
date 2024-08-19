#pragma once
#include <type_traits>
#include <utility>
/// validators
template<typename LambdaType, typename... ArgTypes, 
         typename = decltype(std::declval<LambdaType>()
                            (std::declval<ArgTypes&&>()...))
        >  
std::true_type  is_implemented(void*);
//... a catch all function if SFINEAE'd out
template<typename LambdaType, typename... ArgTypes> 
std::false_type is_implemented(...); 

/// Lambdas
//define a lambda that takes an instance of a lamda object 
//and checks whether calling it with the arguments is valid.
inline constexpr auto is_valid = 
    [](auto lambda_instance) {
        return [](auto&&... lambda_args) { 
            return decltype(is_implemented<decltype(lambda_instance), 
                                        decltype(lambda_args)&&... 
                                        >(nullptr)){};
        };
    };
//////////////////////////////////////////////////////////////////
// helper template to represent a type as a value
template<typename T> 
struct WrappedType { 
    using Type = T; 
};

template<typename T> 
constexpr auto WrappedInstance = WrappedType<T>{};

///Forward declarations
// Type stripper
// helper to unwrap a wrapped type in unevaluated contexts
template<typename T> 
T StripWrappedType(WrappedType<T>);
//////////////////////////////////////////////////////////////////
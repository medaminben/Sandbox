#ifndef CONCEPTION_H
#define CONCEPTION_H
#include <type_traits>
#include <concepts>
#include <cmath>
namespace Sandbox { namespace Pot { 

//concepts
 /**
 * @brief Numeric concept 
 * template type guard for numeric types
 * @param numeric_type type to assert
 */
template<class numeric_type> concept Numeric = requires(numeric_type param) 
{
    requires  std::is_integral_v<numeric_type> 
           || std::is_floating_point_v<numeric_type>;
    requires !std::is_same_v<bool, numeric_type>;
    requires  std::is_arithmetic_v<decltype(param +1)>;
    requires !std::is_pointer_v<numeric_type>;
};

// Rule Constraints
template<bool> struct rule       : std::false_type {};
template<>     struct rule<true> : std::true_type  {};

// accessibility constraint
// if the dimension is higher than the space boundary 
// doesn't create (example of use see Point.h)
template<size_t dimension, size_t point_size> 
struct is_accessible : rule<(dimension < point_size)>{};

}}

#endif //CONCEPTION_H
#ifndef CONCEPTION_H
#define CONCEPTION_H
#include <type_traits>
#include <concepts>
#include <tuple>

namespace Sandbox { namespace Pot {
//concepts
 /**
 * @brief Numeric concept 
 * template type guard for numeric types
 * @tparam T type to assert
 */
template<typename T> concept Numeric = requires(T param) 
{
    requires  std::is_integral_v<T> || std::is_floating_point_v<T>;
    requires !std::is_same_v<bool, T>;
    requires  std::is_arithmetic_v<decltype(param +1)>;
    requires !std::is_pointer_v<T>;
};

/**
 * @brief trait
 * 
 * @tparam P 
 * @tparam D 
 */
template <typename P, int D> struct access;

template <typename P> struct access<P, 0> { 
    static constexpr Numeric auto get(P const& p) noexcept { return p.x; }  
};
template <typename P> struct access<P, 1> { 
    static constexpr Numeric auto get(P const& p) noexcept { return p.y; }  
};
template <typename P> struct access<P, 2> { 
    static constexpr Numeric auto get(P const& p) noexcept { return p.z; }  
};


template <int D, typename P> 
constexpr auto get(P const& p) { return access<P, D>::get(p); } 

}}

#endif //CONCEPTION_H

#ifndef POINT_H
#define POINT_H
#include <Sandbox/Core/Core.h>
#include <array>
#include <stdint.h>
#include "Conception.h"
namespace Sandbox { namespace Pot {

// Point<T,n>
/**
* @brief  Point<T,n> basic_point template: container for any dimensional point
* container for any dimensional point
* @param T   a numeric type of the coordinates
* @param dim dimensions 
*/
template<Numeric numeric_type, size_t size> 
struct basic_point {
private:
    // attribute
    std::vector<numeric_type> vec{};
    //miscs
    constexpr void copy( basic_point<numeric_type,size> const& p) noexcept { 
        vec.clear();
        std::copy(p.vec.begin(), p.vec.end(), std::back_inserter(vec));              
    }
    constexpr void copy( Numeric auto const (&p)[size] ) noexcept { 
         for (decltype(size) i = 0; i < size;  i++) vec[i] = p[i];
    }
    constexpr void copy( Numeric auto const& val ) noexcept { 
        for (decltype(size) i = 0; i < size;  i++) vec[i] = val;                             
    }
public:
    ///ctors
    /*new ctor*/
    constexpr  basic_point( numeric_type const (&pnt)[size] ) noexcept { 
        vec.assign(size, 0); copy(pnt); 
    }
    /*copy ctor*/
    constexpr  basic_point( basic_point< numeric_type, size > const& pnt ) noexcept { 
        copy(pnt); 
    }
    /*default ctor*/
    constexpr  basic_point( numeric_type dot = 0 ) noexcept { 
        vec.assign(size, 0); copy(dot);
    }
    /*default dector */
    virtual   ~basic_point() = default ;
    //operators
    constexpr auto operator+=( basic_point< numeric_type, size > const& o ) noexcept { 
        for( size_t i = 0; i < size; i++ ) vec[i] += o.vec[i];
    }
    constexpr auto operator-=( basic_point< numeric_type, size > const& o ) noexcept { 
        for( size_t i = 0; i < size; i++ ) vec[i] -= o.vec[i];
    }
    friend constexpr auto operator+( basic_point< numeric_type, size > const& a, 
                                     basic_point< numeric_type, size > const& b ) noexcept { 
        basic_point< numeric_type, size > sum{a}; sum  += b; return sum;     
    }
    friend constexpr auto operator-( basic_point< numeric_type, size > const& a, 
                                     basic_point< numeric_type, size>  const& b ) noexcept { 
        basic_point< numeric_type, size > rest{a}; rest -= b; return rest;
    }
private:
    template < size_t dimension, Numeric point_type, size_t point_size > friend struct access;
    template < Numeric point_type, size_t point_size >                   friend struct basic_point;
};

// getters through access 

template<size_t dimension, Numeric point_type, size_t point_size>
struct access 
     : is_accessible<dimension,point_size> {
    // the accessor as a basic_point friend is allowed to grab the values
    static constexpr Numeric 
    auto get_v(basic_point<point_type, point_size > const& point) noexcept { 
        return point.vec[dimension]; 
    } 
};

template<size_t dimension, Numeric point_type, size_t point_size> 
constexpr Numeric 
auto get(basic_point< point_type, point_size> const& point) noexcept { 
    return access< dimension, point_type, point_size >::get_v(point); 
};

// Aliasing
template<Numeric T> using Point2D = basic_point<T,2>;

}}// end of namespaces


#endif // POINT_H
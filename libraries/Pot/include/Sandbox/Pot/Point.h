
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
* @tparam T   a numeric type of the coordinates
* @tparam dim dimensions 
*/
template<Numeric T, size_t dim = 2> 
struct basic_point {
    // attribute
    std::array<T,dim> array;
    //miscs
    constexpr inline void copy( basic_point const& p ) noexcept { 
        // for noexcept 
        std::copy(p.array.begin(), p.array.end(), array.begin()); 
    }
    constexpr inline void copy( auto const (&p)[dim] ) noexcept { 
       

        std::copy(p, p + dim, array.begin());
    }
    constexpr inline void copy( auto const& val ) noexcept { 
        for (auto& a : array) 
            a = val;                            
    }
public:
    ///ctors
    /*new ctor*/
    constexpr inline basic_point( T const (&pnt)[dim] ) noexcept { 
        copy(pnt); 
    }
    /*copy ctor*/
    constexpr inline basic_point( basic_point<T,dim> const& pnt ) noexcept { 
        copy(pnt);  
    }
    /*default ctor*/
    constexpr inline basic_point( T dot = 0 ) noexcept { 
        copy(dot); 
    }
    virtual ~basic_point() = default ;
    //operators
    constexpr inline auto operator+=( basic_point<T,dim> const& o ) noexcept { 
        for(size_t i = 0; i < dim;i++) 
            array[i] += o.array[i]; 
    }
    constexpr inline auto operator-=( basic_point<T,dim> const& o ) noexcept { 
        for(size_t i = 0; i < dim;i++) 
            array[i] -= o.array[i]; 
    }
    friend constexpr inline auto operator+( basic_point<T,dim> const& a, 
                                            basic_point<T,dim> const& b ) noexcept { 
        basic_point<T,dim> sum{a};  
        sum  += b; 
        return sum;     
    }
    friend constexpr inline auto operator-( basic_point<T,dim> const& a, 
                                            basic_point<T,dim> const& b ) noexcept { 
        basic_point<T,dim> rest{a}; 
        rest -= b; 
        return rest;    
    }
};

//Point2D<T>
/**
 * @brief special point case 2 dimesional
 * 
 * @tparam T a numeric type of the coordinates
 */
template<Numeric T = size_t > 
struct Point2D {
public:
    // attributes
    basic_point<T,2> data = basic_point<T,2>(0);
    T& x = data.array[0];
    T& y = data.array[1];

    //ctors
    constexpr inline Point2D ( T const p ) noexcept { 
        data.copy(p); 
    }
    constexpr inline Point2D ( T const (&p)[2]  ) noexcept { 
        data.copy(p); 
    }
    constexpr inline Point2D ( Point2D const& o ) noexcept { 
        data.copy(o.data); 
    }

    //operators
    constexpr inline auto operator+=( Point2D const& o ) noexcept { 
        data += o.data; 
    }
    constexpr inline auto operator-=( Point2D const& o ) noexcept { 
        data -= o.data; 
    }

    friend constexpr inline auto operator+( Point2D const& a, 
                                            Point2D const& b ) noexcept { 
        Point2D sum(a);  
        sum += b; 
        return  sum;
    }
    friend constexpr inline auto operator-( Point2D const& a, 
                                            Point2D const& b ) noexcept { 
        Point2D rest(a); 
        rest -= b; 
        return rest;
    }
};


}}
#endif // POINT_H
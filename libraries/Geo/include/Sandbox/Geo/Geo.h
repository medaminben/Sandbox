#ifndef GEO_H
#define GEO_H
#include "Sandbox_Geo_export.h"

#include <Sandbox/Pot/Pot.h>

#include <stdint.h>
#include <cmath>
#include <utility>
namespace Sandbox { namespace Geo {

    /**
     * @brief 
     * Calculates the factorial of a number
     * \code{.cpp}
     *  const auto value = fractional<N>::is;
     * \endcode
     * @param N the number
     */
     template<size_t N> struct factorial { 
        enum { is = N * factorial<N-1>::is };
    };
    template<>
    struct factorial<0> { 
        enum { is = 1 };
    };

    /**
     * @brief 
     * This template calculates the binomial coefficient using the multiplicative formula 
     * 
     * The function takes two parameters, "items" and "to_choose", and returns the binomial coefficient as a result.
     * The function first checks if to_choose is greater than items, then, it checks if to_choose is greater than half of items, 
     * in which case it swaps to_choose with (items - to_choose) to avoid the overflow.
     * The function then calculates the binomial coefficient using a loop that iterates from 1 to to_choose. 
     * 
     * @param T integral type 
     * @param items total number of items 
     * @param to_choose number of item to choose
     * @return Result<float>
     */
    //template <Sp::Numeric T = size_t>
    constexpr auto inline bino_coef(Sp::Numeric auto items, 
                                    Sp::Numeric auto to_choose) noexcept 
    {
        float result{1};
        // checks if to_choose more than items 
        if ( to_choose > items ) { 
            return Result<float>(Sc::Error<>(" to_choose more than the given items, try to swap the arguments"));   
        }  
        // check the middle to avoid the overflow
        if ((2 * to_choose) > items) { 
            // take the difference to the number to choose
            to_choose = items - to_choose; 
        }       
        auto i = to_choose;
        for (i = 1; i <= to_choose; i++) { 
            result *= ((float) items + 1 - i) / i; 
        }   
        return Result<float>(result);
    }
    /**
     * @brief Greatest Common Divisor
     * 
     * @param a Numeric type
     * @param b Numeric type
     * @return  gcd as size_t value  
     */
    constexpr const auto inline gcd(Sp::Numeric auto const a, 
                                    Sp::Numeric auto const b) noexcept 
    {   // convert the arguments to a positive integer
        auto _a = (size_t) std::floor(std::abs(a));
        auto _b = (size_t) std::floor(std::abs(b));
        auto _temp =_b;
        while(true) { if(_b==0) return _a;
            _temp = _b; _b = _a % _b; _a = _temp;
        };
    } 
    template<Sp::Numeric T>
    auto inline reducePoint(Sp::Point2D<T> const& p) noexcept 
    { 
        const float g = Sandbox::Geo::gcd(p.y,p.x); 
        if(g != 0) {
            auto r = Sp::Point2D<float>(0); 
            r.x = ((p.x < 0) ? -1 : 1) * (abs(p.x) / g);
            r.y = ((p.y < 0) ? -1 : 1) * (abs(p.y) / g); 
            return Result<Sp::Point2D<float>>(r);
        }
        else 
            return Result<Sp::Point2D<float>>(Sc::Error<>("gcd is 0 \n"));
    }
}}
namespace Sg = Sandbox::Geo;
#endif // GEO_H

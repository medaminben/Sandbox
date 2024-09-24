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
     template<size_t N> 
     struct factorial { 
        enum { 
            is = N * factorial<N-1>::is 
        };
    };
    template<>
    struct factorial<0> { 
        enum { 
            is = 1
        };
    };

    /**
     * @brief 
     * This template calculates the binomial coefficient 
     * using the multiplicative formula 
     * 
     * The function takes two parameters, "items" and "to_choose", 
     * and returns the binomial coefficient as a result.
     * The function first checks if to_choose is greater than items, 
     * then, it checks if to_choose is greater than half of items, 
     * in which case it swaps to_choose with (items - to_choose) 
     * to avoid the overflow. The function then calculates the binomial 
     * coefficient using a loop that iterates from 1 to to_choose. 
     * 
     * @param T integral type 
     * @param items total number of items 
     * @param to_choose number of item to choose
     * @return Result<float>
     */
    //template <Sp::Numeric T = size_t>
    inline constexpr auto  
    bino_coef(Sp::Numeric auto items, 
              Sp::Numeric auto to_choose) 
    noexcept {
        float result{1};
        // checks if to_choose more than items 
        if ( to_choose > items ) { 
            return Result<float>( Sc::Error<>(
     " to_choose more than the given items, try to swap the arguments"
                    ));   
        }  
        // check the middle to avoid the overflow
        if ((2 * to_choose) > items) { 
            // take the difference to the number to choose
            to_choose = items - to_choose; 
        }       
        decltype(to_choose) i; 
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
    inline constexpr const auto  
    gcd(Sp::Numeric auto const a, 
        Sp::Numeric auto const b) 
    noexcept {   
        // convert the arguments to a positive integer
        auto _a = (size_t) std::floor(std::abs(a));
        auto _b = (size_t) std::floor(std::abs(b));
        auto _temp =_b;
        while(true) { 
            if(_b==0) // escape clause
                return _a;

            _b    = _a % _b; 
            _a    = _temp;
            _temp = _b;
        };
    } 

    template<Sp::Numeric T>
    Result<Sp::Point2D<float>> inline 
    reducePoint(Sp::Point2D<T> const& p) 
    noexcept { 
        const auto  x = Sp::get<0>(p);
        const auto  y = Sp::get<1>(p);
        if(const float g = Sandbox::Geo::gcd(y,x)) {
            float pt[2] = {
                ((x < 0) ? -1 : 1) * (abs(x) / g),
                ((y < 0) ? -1 : 1) * (abs(y) / g)
            };
            return 
                Result<Sp::Point2D<float>>(pt);
        }
        else return Sc::Error<>("gcd is 0 \n");
    }

    
    // Function to calculate distance
    inline constexpr Sp::Numeric auto 
    distance(Sp::Numeric auto const& x1, Sp::Numeric auto const& y1, 
            Sp::Numeric auto const& x2, Sp::Numeric auto const& y2)
    noexcept {
        return 
            std::sqrt( std::pow((x2 - x1), 2) 
                     + std::pow((y2 - y1), 2) );
    }
    // Function template to calculate distance
    // between 2 points 
    template<Sp::Numeric T>
    inline constexpr Sp::Numeric auto 
    distance(Sp::Point2D<T> const& a, 
             Sp::Point2D<T> const& b)
    noexcept {
        return distance(Sp::get<0>(a), Sp::get<1>(a),
                        Sp::get<0>(b), Sp::get<1>(b));
    }
        // Function template to calculate distance
    // between 2 points 
    template<Sp::Numeric T>
    inline constexpr Sp::Numeric auto 
    std_distance(Sp::Point2D<T> const& a, 
                 Sp::Point2D<T> const& b)
    noexcept {
        return std::hypot(Sp::get<0>(b) - Sp::get<0>(a),
                          Sp::get<1>(b) - Sp::get<1>(a));
    }

    template<Sp::Numeric T>
    inline constexpr std::pair<int, int> 
    nearestNeighbor(std::vector<Sp::Point2D<T>> const& points, 
                    Sp::Point2D<T>              const& current) {
        Sp::Numeric auto minDist      = INT_MAX;
        Sp::Numeric auto nearestIndex = -1;
        decltype(std::declval<points.size()>()) i;
        for (i = 0 ; i < points.size(); i++) 
            if (i != Sp::get<0>(current)) { // <-- skip current point
                auto dist = std_distance(current, points[i] );
                if (dist < minDist) {
                    minDist      = dist;
                    nearestIndex = i;
                }
            }; 
        return {nearestIndex, minDist};
    }
}}

namespace Sg = Sandbox::Geo;
#endif // GEO_H

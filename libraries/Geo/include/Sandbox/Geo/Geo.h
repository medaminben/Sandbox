#ifndef GEO_H
#define GEO_H
#include "Sandbox_Geo_export.h"
#include <Sandbox/Core/Core.h>
#include <stdint.h>

namespace Sandbox { namespace Geo {
    /**
     * @brief 
     * Calculates the factorial of a number
     * \code{.cpp}
     *  const auto vallue = fractional<N>::is;
     * \endcode
     * @tparam N the nimber
     */
    template<size_t N>
    struct factorial { enum { is = N * factorial<N-1>::is};};
    template<>
    struct factorial<0> { enum {is = 1};};

    /**
     * @brief 
     * This template calculates the binomial coefficient using the multiplicative formula 
     * 
     * The function takes two parameters, "items" and "to_choose", and returns the binomial coefficient as a result.
     * The function first checks if to_choose is greater than items, then, it checks if to_choose is greater than half of items, 
     * in which case it swaps to_choose with (items - to_choose) to avoid the overflow.
     * The function then calculates the binomial coefficient using a loop that iterates from 1 to to_choose. 
     * 
     * @tparam T integral type 
     * @param items total number of items 
     * @param to_choose number of item to choose
     * @return Result<float>
     */
    template <typename T = size_t>
    Result<float> bino_coef(T items, T to_choose) {
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
        
        for (T i = 1; i <= to_choose; i++) { 
            result *= ((float) items + 1 - i) / i; 
        }   
        return Result<float>(result);
    }
}}
namespace Sg = Sandbox::Geo;
#endif // GEO_H

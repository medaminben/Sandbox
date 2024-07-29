#ifndef GEO_H
#define GEO_H
#include "Sandbox_Geo_export.h"
#include <Sandbox/Core/Core.h>
#include <stdint.h>
#include <concepts>
namespace Sandbox { namespace Geo {
    /**
     * @brief Get an unique point id relatd to the actual session
     * It can be lead to duplicate if the used id source is exeternal to the actual session
     * @return size_t 
     */
    size_t SANDBOX_GEO_API get_point_index();

    //concept
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
     * @brief 
     * Calculates the factorial of a number
     * \code{.cpp}
     *  const auto vallue = fractional<N>::is;
     * \endcode
     * @tparam N the number
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
    template <Numeric T = size_t>
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
    
   // Point<T,n>
   /**
    * @brief basic_point template container for any dimensional point
    * 
    * @tparam T   a numeric type of the coordinates
    * @tparam dim dimensions 
    */
    template < Numeric T, size_t dim = 2 > struct basic_point {
        // attribute
        std::array<T,dim> array;
    protected:
        //miscs
               constexpr inline auto copy( basic_point const& p)        noexcept { std::copy(p.array.begin(), p.array.end(), array.begin()); }
               constexpr inline auto copy( auto const (&p)[dim])        noexcept { std::copy(p, p + dim, array.begin());                     }
               constexpr inline auto copy( auto const& val)             noexcept { for (auto& a : array) a = val;                            }
    public:
        //ctors
               constexpr inline      basic_point( T const (&pt)[dim])          /*new ctor*/ noexcept { copy(pt); }
               constexpr inline      basic_point( basic_point<T,dim> const& p)/*copy ctor*/ noexcept { copy(p);  }
               constexpr inline      basic_point( T dt = 0 )               /*default ctor*/ noexcept { copy(dt); }
        virtual ~basic_point() = default ;
        //operators
               constexpr inline auto operator+=( basic_point<T,dim> const& o )                              noexcept { for(size_t i = 0; i < dim;i++)  array[i] += o.array[i];}
               constexpr inline auto operator-=( basic_point<T,dim> const& o )                              noexcept { for(size_t i = 0; i < dim;i++) array[i] -= o.array[i]; }
        friend constexpr inline auto operator+ ( basic_point<T,dim> const& a, basic_point<T,dim> const& b ) noexcept { basic_point<T,dim> sum{a};  sum  += b; return sum;     }
        friend constexpr inline auto operator- ( basic_point<T,dim> const& a, basic_point<T,dim> const& b ) noexcept { basic_point<T,dim> rest{a}; rest -= b; return rest;    }
    };
     //Point2D<T>
     /**
      * @brief special point case 2 dimesional
      * 
      * @tparam T a numeric type of the coordinates
      */
    template< Numeric T = size_t > struct Point2D {
        // attributes
        basic_point<T,2> data= basic_point<T,2>(0);
        T& x = data.array[0];
        T& y = data.array[1];
        //ctors
               constexpr inline      Point2D   ( T const (&p)[2]  )                   noexcept { data =  p;      }
               constexpr inline      Point2D   ( Point2D const& o )                   noexcept { data =  o.data; }
        //operators
               constexpr inline auto operator+=( Point2D const& o )                   noexcept { data += o.data; }
               constexpr inline auto operator-=( Point2D const& o )                   noexcept { data -= o.data; }
        friend constexpr inline auto operator+ ( Point2D const& a, Point2D const& b ) noexcept { Point2D  sum( a );  sum += b; return  sum;}
        friend constexpr inline auto operator- ( Point2D const& a, Point2D const& b ) noexcept { Point2D rest( a ); rest -= b; return rest;}
    };
}}
namespace Sg = Sandbox::Geo;
#endif // GEO_H

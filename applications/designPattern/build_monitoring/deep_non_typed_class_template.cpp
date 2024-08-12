#include <iostream>
///////////////////////////////////////////////////////////
bool is_prime_loop( size_t p) {
    if(p < 4)  
        return p > 1;
    for(auto d = p/2 ; d > 1; --d) 
        if(p%d == 0) return false;  
    return true;
}

void prime_loop_test(size_t stop) {
    for(size_t p = 1; p <= stop; ++p) 
        if(is_prime_loop(p))  std::cout << " ( " << p << " is prime!" << " ) ";
    std::cout << "\n" ;
}           

///////////////////////////////////////////////////////////
bool is_prime_recur_impl(size_t p, size_t d) {
    if(d <= 2) // escape clause  0 1 2 
        return (d == 2) && (p % d); // if d = 2 then p % 2 else false 
    if( p % d) 
            return is_prime_recur_impl(p, d-1); 
    return false;
    // The above lines are equal to the following comment
    // return (p % d) && is_prime_recur_impl(p, d-1) 
};

bool is_prime_recur(size_t p) { 
    if(p < 4) // escape clause  0 1 2 3
        return p > 1;
    else      
        return is_prime_recur_impl(p,p/2);
    // the lines above are equal to : (p < 4) ? (p > 1) : is_prime_recur_impl(p,p/2)
}

void prime_recursion_test(size_t stop) {
    for(size_t p = 1; p <= stop; ++p) 
        if(is_prime_recur(p)) std::cout << " ( " << p << " is prime!" << " ) ";
    std::cout << "\n" ;
}

///////////////////////////////////////////////////////////
// primary struct template
template< size_t p, size_t d>
struct st_is_prime_impl {
    static const bool value = (p % d) && st_is_prime_impl< p , d - 1 >::value;
};
// spezialisations cases from 0 to 3
template< size_t p> struct st_is_prime_impl<p,2> { static const bool value = p % 2; };
template< size_t p> struct st_is_prime_impl<p,1> { static const bool value = false; };
template< size_t p> struct st_is_prime_impl<p,0> { static const bool value = false; };
// primary struct template
template<size_t p> 
struct st_is_prime { static const bool value = st_is_prime_impl< p , p / 2 >::value;};
// spezialisations cases from 0 to 3
template<> struct st_is_prime<3> { static const bool value = true;  };
template<> struct st_is_prime<2> { static const bool value = true;  };
template<> struct st_is_prime<1> { static const bool value = false; };
template<> struct st_is_prime<0> { static const bool value = false; };

// forward declaration the function is too long. 
// the iteration should be hard coded no loops in MPL!
template<size_t limit, size_t p >
constexpr void prime_class_template_test(){

    if constexpr (p <= limit) 
        if(st_is_prime<p>::value) 
            std::cout << " ( " << p  << " is prime!" << " ) ";

    if constexpr (p+1 <= limit) 
        prime_class_template_test<limit,p+1>();
}

///////////////////////////////////////////////////////////
int main() {

    constexpr size_t limit = 600; // the maximum that is allowed by the class template 
    std::cout << "-------------------------------------------------------------------------\n";
    prime_loop_test(limit);
    std::cout << "-------------------------------------------------------------------------\n";
    prime_recursion_test(limit);
    std::cout << "-------------------------------------------------------------------------\n";
    prime_class_template_test<limit,1>();
};
#include <iostream>

template<typename T>
T accum(T const* start, 
        T const* end  ) {
    T result{}; 
    while(start != end) {
        result += *start;
        ++start;
    }
    return result;
}
// traits
template<typename T> 
           struct AccumulationTraits;
template<> struct AccumulationTraits<char>           { using AccT = int;     static constexpr AccT const zero = 0;   };
template<> struct AccumulationTraits<short>          { using AccT = int;     static constexpr AccT const zero = 0;   };
template<> struct AccumulationTraits<int>            { using AccT = long;    static constexpr AccT const zero = 0;   };
template<> struct AccumulationTraits<unsigned int>   { using AccT = unsigned long;                                   };
template<> struct AccumulationTraits<float>          { using AccT = double;  static constexpr AccT const zero = 0.0f;};

template<typename T>
auto accum_traits(T const* start, T const* end  )   {
    using AccT = typename AccumulationTraits<T>::AccT;
    AccT result{ AccumulationTraits<T>::zero }; 
    while(start != end) {
        result  += *start;
        ++start;
    }
    return result;
}

template<typename T> 
           struct AccumulationTraits_2;
template<> struct AccumulationTraits_2<char>         { using AccT = int;           static constexpr AccT zero() {return 0;}};
template<> struct AccumulationTraits_2<short>        { using AccT = int;           static constexpr AccT zero() {return 0;}};
template<> struct AccumulationTraits_2<int>          { using AccT = long;          static constexpr AccT zero() {return 0;}};
template<> struct AccumulationTraits_2<unsigned int> { using AccT = unsigned long; static constexpr AccT zero() {return 0;}};
template<> struct AccumulationTraits_2<float>        { using AccT = double;        static constexpr AccT zero() {return 0;}};

template<typename T, 
         typename AT = AccumulationTraits_2<T>>
auto accum_traits_2(T const* start, T const* end  )   {
    typename AT::AccT result = AT::zero(); 
    while(start != end) {
        result  += *start;
        ++start;
    }
    return result;
}

struct own_type{};
template<> struct AccumulationTraits<own_type>   { using AccT = own_type; inline static const AccT zero = own_type{};};
template<> struct AccumulationTraits_2<own_type> { using AccT = own_type; static AccT zero() {return own_type{};}    };

struct sum_policy  { template<typename T1, typename T2> static void accumulate(T1& result, T2 const& value) {result += value;} };
struct mult_policy { template<typename T1, typename T2> static void accumulate(T1& result, T2 const& value) {result *= value;} };

template<typename T, 
         typename Pilicy = sum_policy, 
         typename Traits  = AccumulationTraits_2<T>>
auto accum_policy(T const* start, T const* end){
    using AccT = typename Traits::AccT;
    AccT result = Traits::zero();
    while(start != end) {
        Pilicy::accumulate(result, *start); 
        ++start;
    }
    return result;
}
template<typename T, 
         typename Pilicy  = sum_policy, 
         typename Traits  = AccumulationTraits_2<T>>
auto accum_policy_with_init(T const* start, 
                            T const* end, 
                            T const& init_value){
    using AccT = typename Traits::AccT;
    AccT result = init_value;
    while(start != end) {
        Pilicy::accumulate(result, *start); 
        ++start;
    }
    return result;
}
int main() {
    
    int  num[] = {1,2,3,4,5};
    auto total = accum(num, num + 5);
    std::cout << "sum of num is " << total; // sum of num is 15
    ///splitter////////////////////////////
    std::cout <<"\n--------------------\n";
    ///////////////////////////////////////
    char name[] = "whatever_litterals";
    // exclude the zero ending with -1
    size_t length  = sizeof(name)-1;
    total = accum(name, name + length);
    std::cout << "sum of name is " << total; //sum of name is -103
    ///splitter////////////////////////////
    std::cout <<"\n--------------------\n";
    ///////////////////////////////////////
    total = accum_traits(name, name + length);
    std::cout << "sum of name is " << total; //sum of name is 1945
    ///splitter////////////////////////////
    std::cout <<"\n--------------------\n";
    ///////////////////////////////////////
    total = accum_traits_2<char>(name, name + length);
    std::cout << "sum of name is " << total; //sum of name is 1945
    ///splitter////////////////////////////
    std::cout <<"\n--------------------\n";
    ///////////////////////////////////////
    total = accum_policy<>(num, num + 5);
    std::cout << "sum of name is " << total; //sum of name is 1945
    ///splitter////////////////////////////
    std::cout <<"\n--------------------\n";
    ///////////////////////////////////////
    auto totally = accum_policy<int,mult_policy>(num, num + 5);
    std::cout << "multiplication oplicy on num is " << totally; 
    //mult of name is 9, vause the policy is not forcing the trait to initialize with 1 instead of 0
     ///splitter////////////////////////////
    std::cout <<"\n--------------------\n";
    ///////////////////////////////////////
    total = accum_policy_with_init<int,mult_policy>(num, num + 5, 1);
    std::cout << "multiplication wint init of num is " << total; 

    return 0;
}
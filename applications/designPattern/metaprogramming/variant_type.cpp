#include <iostream>
#include <variant>
#include <type_traits>
#include <string>
#include <vector>
#include <sstream>
/////////////////////////////////////////////////
#ifdef __FUNCSIG__
#define SIGNATURE __FUNCSIG__
#else  
#define SIGNATURE __PRETTY_FUNCTION__
#endif 
/////////////////////////////////////////////////
//primary template
template<typename Variant_t>
struct variant_utils;

template<typename T, typename... Rest>
struct variant_utils<std::variant<T,Rest...>> {
    using variant_t = std::variant<T,Rest...>;

    static constexpr size_t 
    type_count = std::variant_size_v<variant_t>;

    template<typename Front, typename... Remaining>
    static void print(std::ostream& os, variant_t const& v) 
    {
        constexpr size_t 
        remaining_count = sizeof...(Remaining);
        constexpr size_t 
        index = type_count - remaining_count - 1;

        if (index == v.index())  {
            if constexpr(!std::is_same_v<Front, 
                                         std::monostate>) 
                os << std::get<index>(v);  
        };
        
        if constexpr(remaining_count != 0) 
            print<Remaining...>(os,v);    
    };

    template<typename Front, typename... Remaining>
    static std::string to_string(variant_t const& v) 
    {
        constexpr size_t 
        remaining_count = sizeof...(Remaining);
        constexpr size_t 
        index = type_count - remaining_count - 1;

        if (index == v.index())  
            if constexpr(!std::is_same_v<Front, 
                                         std::monostate>) 
            {
                std::ostringstream os;
                os << std::get<index>(v);  
                return os.str();
            };
               
        if constexpr(remaining_count != 0)
            return to_string<Remaining...>(v);
        
        return "";
    };
};

template<typename T, typename... TArgs,
         typename variant_t = std::variant<T,TArgs...>>
std::string to_string(std::variant<T,TArgs...> const& v) {
    return variant_utils<variant_t>::
            template to_string<T,TArgs...>(v);
} 

template<typename T, typename... TArgs>
std::ostream& operator<<(std::ostream& os, 
                         std::variant<T,TArgs...> const& v) {
    using variant_t = std::variant<T,TArgs...>;

    variant_utils<variant_t>::
     template print<T,TArgs...>(os,v);
    return os;
} 

template<typename T>
std::ostream& operator << (std::ostream& os, 
                           std::vector<T> const& v) {
    auto s = v.size();
    os << "{ ";
    for(auto const& e : v) 
        os << e << (--s > 0 ? ", " : ""); 
    os << " }";
    return os;
} 
/////////////////////////////////////////////////
template<template<typename> typename Container, 
                typename T, typename... TArgs>
using variant_container_t = Container<std::variant<T, TArgs...>>;
/////////////////////////////////////////////////
void test_variant();
void test_variant_metadata();
void test_variant_output();
void test_variant_container(); 
/////////////////////////////////////////////////   
int main() {
    test_variant();
    test_variant_metadata();
    test_variant_output();
    test_variant_container();
    return 0;
};

/////////////////////////////////////////////////
void test_variant() {
    std::cout << "["  << SIGNATURE << "]" << "\n";
    std::variant<int,char, std::string> person;
    using age_t = int;
    using gender_t = char;
    //using name_t = std::string;
    enum {age_index, gender_index, name_index};
    try {
        person = 5;
        std::cout <<  "the variant 0 is "      
        << std::get<age_index>(person)    << "\n";
        std::cout <<  "the variant 0 is "      
        << std::get<0>(person)            << "\n";
        std::cout <<  "the variant int is "    
        << std::get<int>(person)          << "\n";
        std::cout <<  "the variant int is "    
        << std::get<age_t>(person)        << "\n";
        person = 'M';
        std::cout <<  "at gender_index is "    
        << std::get<gender_index>(person) << "\n";
        std::cout <<  "the variant 1 is "      
        << std::get<1>(person)            << "\n";
        std::cout <<  "the variant char is "   
        << std::get<char>(person)         << "\n";
        std::cout <<  "the gender_t is "       
        << std::get<gender_t>(person)     << "\n";
        person = "Batman";
        std::cout <<  "the variant 2 is "      
        << std::get<2>(person)            << "\n";
        std::cout <<  "the variant string is " 
        << std::get<std::string>(person)  << "\n";
        //std::cout <<  "the variant double is " << std::get<double>(person)       << "\n"; this will crach
    } catch(std::bad_variant_access& e) {
        std::cout <<  "[Access error]" << e.what() << "\n";
    }
};
void test_variant_metadata() {
    std::cout << "["  << SIGNATURE << "]" << "\n";
    std::variant<int,long> a_variant(10L);
    std::cout << "Count of element types: " 
    << std::variant_size_v<decltype(a_variant)> << "\n";
};
void test_variant_output() {
    std::cout << "["  << SIGNATURE << "]" << "\n";
    std::variant<std::monostate,int,std::string> a_variant(10L);
    std::cout << "the content of a is " << a_variant << "\n";
    a_variant = "just a string";
    std::cout << "the content now is "  << a_variant << "\n";
}
void test_variant_container() {
    std::cout << "["  << SIGNATURE << "]" << "\n";
    variant_container_t<std::vector, int, double, char, std::string>
    a_variant_vector = {32, 43.7,'M', "a string", "aonther one", 5, 'F', 0.0};
    std::cout << a_variant_vector << "\n";  
};
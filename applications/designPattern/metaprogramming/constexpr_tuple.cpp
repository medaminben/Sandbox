#include <iostream>
#include <tuple>
// this prints the signature of the itself
// but it defines the type T. 
template<typename T> void printType() { 
std::cout << 
#ifdef __FUNCSIG__
__FUNCSIG__
#else  
__PRETTY_FUNCTION__
#endif
<< "\n"; 
};

//primary function template 
template<size_t index, size_t limit, typename... Types>
struct st_print_tuple {
    static void print(std::ostream& os, 
                      std::tuple<Types...> const& tpl) {
        os << std::get<index>(tpl) 
           << ((index + 1 != limit) ?  ", ": "" );
        st_print_tuple<index + 1, limit, Types...>::print(os, tpl);
    }
};

// partial spezialisation 
template<size_t index, typename... Types>
struct st_print_tuple<index, index, Types...> { 
    static void print(std::ostream& os, 
                      std::tuple<Types...> const& tpl) {}
};

template<size_t index, typename... Types>
void print_tuple(std::ostream& os, 
                 std::tuple<Types...> const& tpl) {
    if constexpr (index < sizeof...(Types)) {
        os << std::get<index>(tpl);
    }
    
    if constexpr (index + 1 < sizeof...(Types)) {
        os << ", ";
        print_tuple<index + 1 ,Types...>(os, tpl);
    }
};

template<typename... Types>
std:: ostream& operator<<(std::ostream& os, 
                          std::tuple<Types...> const& tpl) {
    os << "{ "; 
        print_tuple<0>(os, tpl);
    os << " }";
    return os; 
};

template<size_t start, size_t end, 
    typename Operation, typename... Types>
constexpr void compile_time_loop(Operation operation, 
                                 Types&&... args)  {
    if constexpr (start < end) 
        operation(std::forward<Types>(args)...);
    
    if constexpr (start + 1 < end) 
        compile_time_loop<start+1,end>(operation,args...);  
}

void add(int a, double b) {
    std::cout  << "add(" << a << ","
    << b << ") is called" << " \n" ;
}
void product(int a, double b, size_t c) {
    std::cout << "product(" << a << ","<< b 
    << "," << c << ") is called" << " \n" ;
};
int main() { 

    //tuple instance
    std::tuple<size_t, const char*> t1(30, "hanibal");
    std::cout  << "-----------------"       
    << " \n"   <<
    "Name = "  << std::get<0>(t1)           
    << " \n"   << 
    "Age  = "  << std::get<1>(t1)           
    << " \n"   <<
    "Name = "  << std::get<size_t>(t1)      
    << " \n"   << 
    "Age  = "  << std::get<const char*>(t1) 
    << "\n";
    
    //structure binding
    auto t2 = std::make_tuple(20,'F', "Sophie");
    auto [sophie_age, sophie_gender, sophie_name] = t2;
    std::cout   << "-----------------"  
    <<  " \n"   <<
    "Name = "   << sophie_name          
    <<  " \n"   << 
    "Age = "    << sophie_age           
    <<  " \n"   <<
    "gender = " << sophie_gender        
    <<  "\n";
    auto& [s_age, s_gender, s_name] = t2;
    s_age = 19;

    std::cout   << "-----------------"  
    << " \n"    <<
    "Name = "   << s_name               
    << " \n"    << 
    "Age = "    << s_age                
    << " \n"    << 
    "gender = " << s_gender             
    << "\n";

    std::cout   << "-----------------"  
    << " \n"    <<
    "Name = "   << std::get<2>(t2)      
    << " \n"    << 
    "Age = "    << std::get<0>(t2)      
    << " \n"    << 
    "gender = " << std::get<1>(t2)      
    << "\n";

    // elements tie
    const char* t_name{}; size_t t_age{};
    auto t3 = std::make_tuple(40,"Reading","Developer", "Annibal");

    std::tie(t_age,std::ignore, std::ignore, t_name) = t3;

    std::cout  << "-----------------"  
    << " \n"   <<
    "Name = "  << t_name               
    << " \n"   << 
    "Age = "   << t_age                
    << " \n";

    // deceltype(variable) returns the type of the variable
    // deceltype(expression) return the value categorie of the expression

    // tuple element count, 2 ways to know that
    auto tuple_t2_count = std::tuple_size<decltype(t2)>::value;
    auto tuple_t3_count = std::tuple_size_v<decltype(t3)>;
    std::cout  << "-----------------"           
    << " \n"   <<
    "Count of t2 elements = " <<  
    tuple_t2_count << " \n"   << 
    "Count of t3 elements = " << 
    tuple_t3_count << " \n";

     // Tuple signature
    std::cout  << "-----------------"  
    << " \n";
    printType<std::tuple_element_t<0, decltype(t3)>>();

    // operator overöloading for tuple
    std::cout  << "-----------------"  
    << " \n"   <<
    "t3 is = " << t3                  
     <<"\n";

    // compile time loop 
    std::cout  << "-----------------"  
    << " \n";
    compile_time_loop<1,5>(add, 3 , 5);
    compile_time_loop<1,5>(product, -9 , 5.9, 2);

    return 0;
};

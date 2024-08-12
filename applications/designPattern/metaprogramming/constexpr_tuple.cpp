#include <iostream>
#include <tuple>




int main() { 

    std::tuple<size_t, const char*> t(30, "hanibal");
     std::cout <<
        "Name = "  << std::get<0>(t)  << " \n" <<
        "Age  = "  << std::get<0>(t)  << " \n" <<
        "\n";

    
    return 0;
}

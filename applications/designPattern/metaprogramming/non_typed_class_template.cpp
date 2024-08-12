#include <iostream>
#include <chrono>
auto to_ms(std::chrono::duration<double> const& d) {
    return 
    std::chrono::duration_cast<std::chrono::nanoseconds>(d).count();
}

size_t iterative_sum(size_t to_n) {
    size_t sum{0};
    for(size_t i = to_n ; i >= 1; --i)
        sum += i;
    return sum;
};
size_t recursive_sum(size_t to_n) {
    // escape clause
    if(to_n < 2) return 1;
    // recursice clause
    return to_n + recursive_sum(to_n - 1);
};
 template<size_t to_n>
 struct static_sum {
    static const size_t value = to_n + static_sum<to_n - 1>::value;
 };
 template<> 
 struct static_sum<1> {
    static const size_t value = 1;
 };
int main() {
    constexpr auto stop  = 900;
    auto start_iterative = std::chrono::high_resolution_clock::now();
    const auto result_it = iterative_sum(stop);
    auto end_iterative   = std::chrono::high_resolution_clock::now();
    
    auto start_recursive = std::chrono::high_resolution_clock::now();
    const auto result_re = recursive_sum(stop);
    auto end_recursive   = std::chrono::high_resolution_clock::now();

    auto start_mpl       = std::chrono::high_resolution_clock::now();
    auto result_st       = static_sum<stop>::value;
    auto end_mpl         = std::chrono::high_resolution_clock::now();

    double iterative_time = to_ms(std::chrono::duration<double>(end_iterative - start_iterative));
    double recursive_time = to_ms(std::chrono::duration<double>(end_recursive - start_recursive));
    double static_time    = to_ms(std::chrono::duration<double>(end_mpl       - start_mpl      ));

     std::cout <<
        "result_it = "  << result_it << ",\t iterative time  = "  << iterative_time  << " ns\n" <<
        "result_re = "  << result_re << ",\t recursive time  = "  << recursive_time  << " ns\n" <<
        "result_st = "  << result_st << ",\t static time     = "  << static_time     << " ns\n" <<
        "\n";
    return 0;
}
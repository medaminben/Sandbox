#include <iostream>

#include <type_traits>


class NonConstructible {
    private: 
    NonConstructible();
};
class Constructible {};

template<typename T>
struct IsDefaultConstructible {
private:
    // check() trying substitute call of a  
    // default constructor for T passed as U:
    template<typename U, 
             typename = decltype(U())>
    static std::true_type check(void*);
    // check() fallback:
    template<typename>
    static std::false_type check(...);
public:
    using Type = decltype(check<T>(nullptr));
};
//
template<typename T> 
struct IsDefaultConstructibleT 
     : IsDefaultConstructible<T>::Type{};


// primary template:
template<typename, typename = std::void_t<>>
struct HasDefaultConstructor : std::false_type {};
// partial specialization (may be SFINAE'd away):
template<typename T>
struct HasDefaultConstructor<T, 
                             std::void_t<decltype(T())>> 
     : std::true_type{};

int main() {
// boolalpha to print true and false as litteral
std::cout << std::boolalpha;
std::cout << "Is [int] Constuctible ? \t\t" 
<<  IsDefaultConstructibleT<int>::value    << "\n";

std::cout << "Is [int&] Constuctible ? \t\t" 
<<  IsDefaultConstructibleT<int&>::value    << "\n";

std::cout << "Is [int*] Constuctible ? \t\t" 
<<  IsDefaultConstructibleT<int*>::value    << "\n";

std::cout << "Is [Constructible] Constuctible ? \t" 
<<  IsDefaultConstructibleT<Constructible>::value    << "\n";

std::cout << "Is [Nonconstructible] Constuctible ? \t" 
<<  IsDefaultConstructibleT<NonConstructible>::value    << "\n";

std::cout << "Is [Constructible] Constuctible ? \t" 
<<  HasDefaultConstructor<Constructible>::value    << "\n";

std::cout << "Is [Nonconstructible] Constuctible ? \t" 
<<  HasDefaultConstructor<NonConstructible>::value    << "\n";
}
#ifndef CORE_H
#define CORE_H
#include "Sandbox_export.h"
#include <variant>
#include <exception>
class string;
namespace Sandbox {  namespace Core {
    /**
     * @brief an error wrapper
     * 
     * @tparam E any movable error type 
     */
    template <typename E>
    struct Error {
    public:
        constexpr Error(E error): _error(std::move(error)) {};  
        constexpr auto&& operator()() { return std::move(_error); };
    protected:
        E _error;
    };
   
    /**
    * @brief 
    * 
    */
    struct CoreException : public std::exception
    {
        CoreException(const char*);
        ~CoreException() throw();
        const char* what() const throw();
    private:
        string* message;
    };
} }
 
namespace Sc = Sandbox::Core;

 /**
 * @brief  a result wrapper
 * 
 * @tparam T  a value type
 * @tparam ET  an error type 
 */
template<typename T, typename ET = Sc::Error<string>>
struct Result {
public:
    constexpr Result(T value): result(std::move(value)) {};
    constexpr auto isValue() const { return std::holds_alternative<T>(result); };
    constexpr auto&& operator()()  { return std::move(std::get<T>(result)); };

    constexpr Result(ET error): result(std::move(error)) {};
    constexpr auto isError() const { return std::holds_alternative<ET>(result); };
    constexpr auto&& error()       { return std::get<ET>(result)(); };
private:
    std::variant<T, ET> result;
};
#endif // CORE_H

#ifndef CORE_H
#define CORE_H
#include "Sandbox_Core_export.h"
#include <variant>
#include <string>
#include <exception>
#include <memory>
namespace Sandbox { namespace Core {
    /**
    * @brief 
    * 
    */
    struct SANDBOX_CORE_API SandException : public std::exception
    {
        SandException(const char* str) ;
        ~SandException() throw();
        const char* what() const throw();
    private:
        std::unique_ptr<std::string> message;
    };

    /**
     * @brief an error wrapper
     * 
     * @tparam E any movable error type 
     */
    template <typename E = std::string>
    struct Error {
    public:
        constexpr Error(E error): _error(std::move(error)) {};

        constexpr auto&& operator()() { 
            return std::move(_error); 
        };

    protected:
        E _error;
    };
   

}}
namespace Sc = Sandbox::Core;


 /**
 * @brief  a result wrapper
 * 
 * @tparam T  a value type
 * @tparam ET  an error type 
 */
template<typename T = std::monostate, typename ET = Sc::Error<>>
struct Result {
public:
    constexpr Result(T value) : result(std::move(value)) {};

    constexpr auto isValue() const { 
        return std::holds_alternative<T>(result); 
    };

    constexpr auto&& operator()()  { 
        return std::move(std::get<T>(result)); 
    };

    constexpr Result(ET error) : result(std::move(error)) {};

    constexpr auto isError() const { 
        return std::holds_alternative<ET>(result); 
    };

    constexpr auto&& error(){ 
        return std::move(std::get<ET>(result)()); 
    };
private:
    std::variant<T, ET> result;
};

#endif // CORE_H

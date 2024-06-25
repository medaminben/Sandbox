#ifndef CORE_H
#define CORE_H
#include "Sandbox_export.h"
#include <variant>
/**
 * @brief  a result wrapper
 * 
 * @tparam VT  a value type
 * @tparam ET  an error type 
 */
template <typename VT, typename ET>
struct Result {
public:
    constexpr Result(VT value): result(std::move(value)) {};
    constexpr auto isValue() const { return std::holds_alternative<VT>(result); };
    constexpr auto&& operator()()  { return std::move(std::get<VT>(result)); };

    constexpr Result(ET error): result(std::move(error)) {};
    constexpr auto isError() const { return std::holds_alternative<ET>(result); };
    constexpr auto&& error()       { return std::move(std::get<ET>(result)); };
private:
    std::variant<VT, ET> result;
};
namespace Sandbox {
    namespace Core {
          /**
         * @brief an error wrapper
         * 
         * @tparam E any movable error type 
         */
        template <typename E>
        struct Error {
        public:
            constexpr Error(E error): _error(std::move(error)) {};  
            constexpr auto&&  error()     { return std::move(_error); };
            constexpr auto&& operator()() { return std::move(_error); };
        protected:
            E _error;
        };
    }
}
namespace Sc = Sandbox::Core;
#endif // CORE_H

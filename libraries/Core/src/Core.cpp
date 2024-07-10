#include "Core_impl.h"
#include <Sandbox/Core/Core.h>
 
namespace Sandbox { namespace Core {
 SandException::SandException(const char* str) {
    message = std::make_unique<std::string>(str);
}

SandException::~SandException() throw() {
    
}

const char* SandException::what() const throw() {
    return message->c_str();
}

} }

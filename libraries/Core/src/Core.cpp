#include "Core_impl.h"
#include <Sandbox/Core/Core.h>
namespace Sandbox { namespace Core {
       
    CoreException::CoreException(const char* str) {
        message =  new string(str);
    }

    CoreException::~CoreException() throw() {
        delete message;
    }

    const char* CoreException::what() const throw() {
        return message->c_str();
    }
} }

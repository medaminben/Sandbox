#ifndef TOOLS_H
#define TOOLS_H
#include "Sandbox_Tools_export.h"
#include <Sandbox/Core/Core.h>

#include <stdint.h>
#include <string>
#include <vector>
#include <filesystem>
namespace Sandbox { namespace Tools {

    Result<std::vector<std::vector<std::string>>>
    SANDBOX_TOOLS_API parse_csv_file( 
                    const std::string& file_name, 
                    const std::string& delimiter = ",", 
                    const std::string& header = "");
}}
namespace St = Sandbox::Tools;
#endif // TOOLS_H

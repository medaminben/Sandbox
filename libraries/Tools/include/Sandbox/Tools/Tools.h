#ifndef TOOLS_H
#define TOOLS_H
#include "Sandbox_Tools_export.h"
#include <Sandbox/Core/Core.h>
#include <Sandbox/Pot/Pot.h>
namespace Sandbox { namespace Tools {
    //////////////////////////////////////////////////
    /////////////// csv parser ///////////////////////
    //////////////////////////////////////////////////
    Result<std::vector<std::vector<std::string>>>
    SANDBOX_TOOLS_API parse_csv_file( 
                    const std::string& file_name, 
                    const std::string& delimiter = ",", 
                    const std::string& header = "");

    //////////////////////////////////////////////////
    /////////////// csv parser ///////////////////////
    //////////////////////////////////////////////////


    Result<Pot::iniFile> 
    SANDBOX_TOOLS_API parse_ini_file(const std::string& file_path) noexcept;


    //////////////////////////////////////////////////
    /////////////// misc stuff ///////////////////////
    //////////////////////////////////////////////////    
    Result<std::string> 
    SANDBOX_TOOLS_API remove_from_line_breack(const char* sentence);
    Result<std::string> 
    SANDBOX_TOOLS_API remove_from_whitespace(const char* sentence);
}}
namespace St = Sandbox::Tools;
#endif // TOOLS_H

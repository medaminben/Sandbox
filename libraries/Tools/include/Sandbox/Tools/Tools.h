#ifndef TOOLS_H
#define TOOLS_H
#include "Sandbox_Tools_export.h"
#include <Sandbox/Core/Core.h>

#include <stdint.h>
#include <string>
#include <vector>
namespace Sandbox { namespace Tools {

    static inline constexpr std::string const unknown = "unknown";
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

    /**
     * @brief iniFile 
     * 
     * ini files are widly used in windows system as a flat serialization of data
     * the format support sections comments and properties as variable value pair
     * as example
     * 
     * ;here a comment line 
     * [a sction]; a comment
     * #this a comment line too
     * a_variable = it can be whatever value # but here starts a comment
     * 
     */
    struct iniFile {
        // own containers
        struct Section {
            constexpr Section(std::string const& name = unknown): label(name){};      
            struct Property{
                constexpr Property(std::string const& k, 
                                std::string const& v) 
                            : key(k),value(v) {};
                std::string key{}, value{};
            };
            std::string           label{}; 
            std::vector<Property> properties{};
        };
        std::vector<Section> sections{Section()};
        size_t               line_count{0}; 
    };

    Result<iniFile> 
    SANDBOX_TOOLS_API parse_ini_file(const std::string& file_path);


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

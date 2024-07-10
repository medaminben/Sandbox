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
                
struct SANDBOX_TOOLS_API csvTable {
    struct csvRow {

        explicit constexpr csvRow(const char* l, const size_t s) : size(s)  {
            if(nullptr == l)
                throw Sc::SandException("no data");
            if(0 >= s)
                throw Sc::SandException("no size");
        }
        virtual ~csvRow() {

            delete line;
        }
    protected:
        const char**  line;
        const size_t size;
    };
 
    explicit constexpr csvTable(const std::vector<std::vector<std::string>>&);
protected:
    const csvRow* this_row{};
    const csvRow* next_row{};
    const csvRow* previous_row{};
    const size_t size;

};

}}
namespace St = Sandbox::Tools;
#endif // TOOLS_H

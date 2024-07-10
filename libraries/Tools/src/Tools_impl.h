#ifndef TOOLS_IMPL_H
#define TOOLS_IMPL_H
#include <vector>
#include <string>

#include <Sandbox/Core/Core.h>

#include "Sandbox/Tools/Tools.h"

typedef std::vector<std::string> TableRow;
typedef std::vector<TableRow>    TableData;
typedef Result<TableData>        TableResult;

namespace Sandbox { namespace Tools {
    TableResult parse_csv_file_impl( const std::string& file_name,
                                     const std::string& delimiter = ",",
                                     const std::string& header    = "");  
}}

#endif //TOOLS_IMPL_H

#include "Tools_impl.h"
#include <Sandbox/Tools/Tools.h>
#include <filesystem>


Result<std::vector<std::vector<std::string>>> 
Sandbox::Tools::parse_csv_file( 
                const std::string& file_name, 
                const std::string& delimiter, 
                const std::string& header) {

      auto res =  parse_csv_file_impl(file_name, delimiter, header);
      if(res.isError())
          throw Sc::SandException(res.error().c_str());
     return res();
}
 
// constexpr csvTable::csvTable(const std::vector<std::vector<std::string>>& table) {

//     for(const auto& row : table) 
//         for(const auto& field : row) {
//             csv_table.push_back(csvRow(field.c_str(),
//                                        field.length()));
//         }                
// }


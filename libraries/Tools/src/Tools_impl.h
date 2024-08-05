#ifndef TOOLS_IMPL_H
#define TOOLS_IMPL_H
#include <vector>
#include <string>
#include <map>
#include <list>
#include <fstream>
#include <regex>
#include <Sandbox/Core/Core.h>
#include <Sandbox/Pot/Pot.h>

typedef std::vector<std::string> TableRow;
typedef std::vector<TableRow>    TableData;
typedef Result<TableData>        TableResult;

namespace Sandbox { namespace Tools {

    static inline const std::regex 
    property = std::regex("^\\s*(\\w+)\\s*=\\s*(.[^;#\\n]*)\\s*[;#]?(.*)?");
    static inline const std::regex 
    section  = std::regex("^\\s*?\\[(.+?)]\\s*[;#]?(.[^\\n]*)?");
    static inline const std::regex
    comment = std::regex("[;#]?(.[^\\n]*)?");
    static inline const std::regex
    comment_line = std::regex("^\\s*[;#](.[^\\n]*)?");
    template<typename CharT> 
    struct Marker {
         static const auto  section_begin = (CharT)'[';
         static const auto  section_end   = (CharT)']';
         static const auto  assign        = (CharT)'=';
         static const auto  comment_1     = (CharT)';';
         static const auto  comment_2     = (CharT)'#';
         static const auto  white_space   = (CharT)' ';
    }__attribute__((packed,aligned(1)));

    template<typename CharT>
    std::basic_string<CharT>
    inline erase_from_char(const std::basic_string<CharT>& the_string, CharT the_char) {
        return the_string.substr(0, the_string.find_first_of(the_char));
    };

    template <typename CharT>
    std::basic_string<CharT>
    inline erase_to_char(const std::basic_string<CharT>& the_string , CharT the_char) {
         return the_string.substr(the_string.find_first_of(the_char), the_string.end());
    };

    std::string remove_from_line_break_impl(std::string const& the_string);
    std::string remove_from_whitespace_impl(std::string const& the_string);

    TableResult parse_csv_file_impl( const std::string& file_name,
                                     const std::string& delimiter = ",",
                                     const std::string& header    = "");  

    Result<Sp::iniFile> parse_ini_file_impl(const std::string &file_path);

    const bool isComment(std::string const& line) noexcept; 
    const bool isData_then_get(std::string const& line, Sp::iniFile& data) noexcept;
}}

#endif //TOOLS_IMPL_H

#include "Tools_impl.h"
#include <Sandbox/Tools/Tools.h>

Result<std::vector<std::vector<std::string>>> 
St::parse_csv_file( const std::string& file_name, 
                    const std::string& delimiter, 
                    const std::string& header) 
{ 
     return parse_csv_file_impl(file_name, delimiter, header); 
}
Result<St::iniFile> St::parse_ini_file(const std::string &file_path)
{
    return parse_ini_file_impl(file_path);
}
Result<std::string> St::remove_from_line_breack(const char* sentence)  { 
     auto _sentence = std::string(sentence);
     if(_sentence.empty())
          return Result<std::string>(Sc::Error<>("nothing to do"));
     return Result<std::string>(St::remove_from_line_breack_impl(_sentence));
}
Result<std::string> St::remove_from_whitespace(const char *sentence)
{
     auto _sentence = std::string(sentence);
     if(_sentence.empty())
          return Result<std::string>(Sc::Error<>("nothing to do"));
    return Result<std::string>(St::remove_from_whitespace_impl(_sentence));
}

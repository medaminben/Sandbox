#include "Tools_impl.h"
#include <Sandbox/Tools/Tools.h>

Result<std::vector<std::vector<std::string>>> 
St::parse_csv_file( const std::string& file_name, 
                    const std::string& delimiter, 
                    const std::string& header) 
{ 
     return parse_csv_file_impl(file_name, delimiter, header); 
}

Result<Sp::iniFile> St::parse_ini_file(const std::string &file_path) noexcept
{
    //return parse_ini_file_impl(file_path);
     //error cases
    // if no file name
    if(file_path.empty()) return Result<Sp::iniFile>(Sc::Error<>("no file path"));
    
    auto file = std::ifstream(file_path);
    if (!file.is_open())  return Result<Sp::iniFile>(Sc::Error<>("File not found, check the path"));
    // initialiazation 
    Sp::iniFile data{}; std::string line{};

    while (!file.eof()) {
        data.line_count++;
        std::getline(file, line);
        if(line.empty()) continue;
        // match comment line 
        if (isComment(line)) continue;
        // match section
        if (isData_then_get(line,data)) continue;
        // if you reach this line very likely that the file is corrupt 
        // a line which is not a comment a property or a section is not allowed!
        const std::string message = std::string("[error] at line ") + std::to_string(data.line_count) + " content: " + line;
        return Result<Sp::iniFile>(Sc::Error<>(message));
    }
    return Result<Sp::iniFile>(data);
}
Result<std::string> St::remove_from_line_break(const char* sentence)  { 
     auto _sentence = std::string(sentence);
     if(_sentence.empty())
          return Result<std::string>(Sc::Error<>("nothing to do"));
     return Result<std::string>(St::remove_from_line_break_impl(_sentence));
}
Result<std::string> St::remove_from_whitespace(const char *sentence)
{
     auto _sentence = std::string(sentence);
     if(_sentence.empty())
          return Result<std::string>(Sc::Error<>("nothing to do"));
    return Result<std::string>(St::remove_from_whitespace_impl(_sentence));
}

#include "Tools_impl.h"
#include <vector>
#include <string>
#include <fstream>
#include <regex>
namespace St = Sandbox::Tools;
Result<TableData> 
St::parse_csv_file_impl(const std::string& file_name,
                        const std::string& delimiter,
                        const std::string& header) {
    // initialiazation 
    std::string line{} ; TableRow row{} ; TableData data{} ; size_t pos = 0;
    //error cases
    // if no file name
    if(file_name.empty()) 
        return TableResult(Sc::Error<>("file name is empty"));
    
    std::ifstream file(file_name);
    if (!file.is_open()) 
        return TableResult(Sc::Error<>("file not found, check the path"));
    
    //get the first line to check if header
    std::getline(file, line);

    if (!header.empty()){
        if(header.compare(line)) 
            return TableResult(Sc::Error<>("wrong header, the given header doesn't match the one in the file"));
    }else {
        while ((pos = line.find(delimiter)) != std::string::npos) {
            row.emplace_back(std::move(line.substr(0, pos)));
            line.erase(0, pos + delimiter.length());
        }
        data.emplace_back(std::move(row));
    }
    
    while (!file.eof()) {
        // reset container and iterator
        row.clear();
        pos = 0;
        std::getline(file, line);
        // slice the line by the delimiter
        while ((pos = line.find(delimiter)) != std::string::npos) {
            row.emplace_back(std::move(line.substr(0, pos)));
            line.erase(0, pos + delimiter.length());
        }
        //check for last value
        if(!line.empty()) 
            row.emplace_back(std::move(line));
        // add the row to the table  
        data.emplace_back(std::move(row));
    }
    
    return Result<TableData>(data);
};

std::string St::remove_from_line_breack_impl(std::string const& the_string){
    return std::string(erase_from_char(std::string(erase_from_char(the_string,'\n')),'\r'));
}

std::string St::remove_from_whitespace_impl(std::string const &the_string){
    return std::string(erase_from_char(the_string, ' '));
}

Result<St::iniFile> Sandbox::Tools::parse_ini_file_impl(const std::string &file_path)
{
    //error cases
    // if no file name
    if(file_path.empty()) 
        return Result<St::iniFile>(Sc::Error<>("no file path"));
    
    auto file = std::ifstream(file_path);
    if (!file.is_open()) 
        return Result<St::iniFile>(Sc::Error<>("file not found, check the path"));
    // initialiazation 
    St::iniFile data{}; std::string line{}; std::smatch matches;

    while (!file.eof()) {
        data.line_count++;

        std::getline(file, line);
        if(line.empty())
            continue;
        // match comment line 
        if (std::regex_search( line, matches, St::comment_line)) 
            continue;
        // match section
        if (std::regex_search( line, matches, St::section)) {
            data.sections.emplace_back(iniFile::Section(matches.str(1)));
            continue;
        }
        // match property 
        if (std::regex_search( line, matches, St::property)) {
            data.sections.back().properties.emplace_back(
                iniFile::Section::Property(matches.str(1),matches.str(2)));
            continue;
        }
        // if you reach this line very likely that the file is corrupt 
        // a line which is not a comment a property or a section is not allowed!
        const std::string message = std::string("[error] at line ") 
        + std::to_string(data.line_count) + " content: " + line;
        return Result<iniFile>(Sc::Error<>(message));
    }
    return Result<iniFile>(data);
}

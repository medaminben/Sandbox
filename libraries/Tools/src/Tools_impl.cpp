#include "Tools_impl.h"
#include <vector>
#include <string>
#include <fstream>

Result<TableData> 
St::parse_csv_file_impl(const std::string& file_name,
                        const std::string& delimiter,
                        const std::string& header) {
    // initialiazation 
    std::string line{} ; TableRow row{} ; TableData data{} ; size_t pos = 0;
    //error cases
    // if no file name
    if(file_name.empty()) {
        std::string msg = "file name is empty";
        auto error = Sc::Error<>(msg); 
        return TableResult(error);
    };

    std::ifstream file(file_name);
    if (!file.is_open()) {
        auto error = Sc::Error<>("file not found, check the path"); 
        return TableResult(error);
    };

    //get the first line to check if header
    std::getline(file, line);

    if (!header.empty()){
        if(header.compare(line)) {

            auto error = Sc::Error<>("wrong header, the given header doesn't match the one in the file"); 
            return TableResult(error);
        } 
    }else {
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            row.push_back(line.substr(0, pos));
            line.erase(0, pos + delimiter.length());
        }
        data.push_back(row);
    }
    
    while (!file.eof()) {
        // reset container and iterator
        row.clear();
        pos = 0;
        std::getline(file, line);
        // slice the line by the delimiter
        while ((pos = line.find(delimiter)) != std::string::npos) {
            row.push_back(line.substr(0, pos));
            line.erase(0, pos + delimiter.length());
        }
        //check for last value
        if(!line.empty()) 
            row.push_back(line);
        // add the row to the table  
        data.push_back(row);
    }
    
    return Result<TableData>(data);
};

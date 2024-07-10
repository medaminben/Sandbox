// CSVParser.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>
#include <Sandbox/Tools/Tools.h>
typedef struct TeachPoint
{	

	TeachPoint(const std::vector<std::string>& dataTab)
	{
		if(dataTab.size() >= 5) {
			std::string 
			device        = dataTab.at(0),
			distance      = dataTab.at(1),
			zoomAngle     = dataTab.at(2),
			focusPosition = dataTab.at(3),
			focusStep     = dataTab.at(4);

			if(device.empty() || distance.empty() ||zoomAngle.empty() || focusPosition.empty() ||focusStep.empty() ) 
					throw(std::invalid_argument("missing data"));			
			_device = device;
			try { 
				std::string dis = distance;
				if(dis.find_first_of(".") != std::string::npos)
					dis.replace(dis.begin(), dis.end(), ',', '.');
				_distance      = std::stod(dis);
				_zoomAngle     = stol(zoomAngle);
				_focusPosition = stol(focusPosition);
				_focusStep     = (int8_t)(stoi(focusStep));
			}
			catch(...){
				throw(std::runtime_error("bad data"));
			}
		}
	}
	std::string _device {""};
	double      _distance{0.0};
	uint32_t    _zoomAngle{0};
	uint32_t    _focusPosition{0};
	int8_t      _focusStep{0};
} TeachPoint;



int main()
{ 
	std::vector<TeachPoint> teachMap;

	const std::string myHeader = "Device;Distance;ZoomAngle;FocusPosition;FocusStep;";
	const std::string delimiter = ";";	
	const auto file_name = "myCSVFile.csv";
	try {
		auto result = St::parse_csv_file(file_name, delimiter, myHeader);
		if(result.isError()) {
			std::cout << result.error() << "\n";
			return -1;
		}
		for(const auto& row : result()) {
			if (row.size() == 5) 
					teachMap.push_back(TeachPoint(row));	
		};
	}catch(const Sc::SandException& ex) {
		std::cout << ex.what() << "\n";
	}
   
	std::string message{};
	for(const auto & teachMap : teachMap) {
		message = "Device: "                       + teachMap._device + 
				 " Distance: "      + std::to_string(teachMap._distance) + 
				 " ZoomAngle: "     + std::to_string(teachMap._zoomAngle) + 
				 " FocusPosition: " + std::to_string(teachMap._focusPosition) + 
				 " FocusStep: "     + std::to_string(teachMap._focusStep);
	   std::cout << message << "\n";
	}
    return 0;
}


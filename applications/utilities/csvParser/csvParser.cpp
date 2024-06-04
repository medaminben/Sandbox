// CSVParser.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>

typedef struct TeachPoint
{	
	std::string _device {""};
	double      _distance{0.0};
	uint32_t    _zoomAngle{0};
	uint32_t    _focusPosition{0};
	int8_t      _focusStep{0};
	TeachPoint(const std::string &device,
			   const std::string &distance,
			   const std::string &zoomAngle,
			   const std::string &focusPosition,
			   const std::string &focusStep)
	{
		if(device.empty() || distance.empty() ||zoomAngle.empty() 
			||focusPosition.empty() ||focusStep.empty() ) 
					throw(std::invalid_argument("missing data"));			
		_device = device;
		try { 
			std::string dis = distance;
			if(dis.find_first_of(".") != std::string::npos)
				dis.replace(dis.begin(), dis.end(), ',', '.');
			_distance      = std::stod(dis);
			_zoomAngle     = stol(zoomAngle, NULL, 32);
			_focusPosition = stol(focusPosition, NULL, 32);
			_focusStep     = (int8_t)(stoi(focusStep));

		} catch(...){
			throw(std::runtime_error("bad data"));
		}
		
	}
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
} TeachPoint;
int main()
{ 
	const std::string myHeader = "Device;Distance;ZoomAngle;FocusPosition;FocusStep;";
	const std::string delimiter = ";";
	std::ifstream myFile("myCSVFile.csv");
	if (!myFile.is_open()) 
		std::cout << "ERROR\n" ;

	std::vector<TeachPoint> teachMap;
	if (!myFile.eof()) 
	{
		std::string aLine ="";
		getline(myFile, aLine);
		if (!myHeader.compare(aLine))
		{
			std::vector<std::vector<std::string>> myDataSet;
			while (!myFile.eof()){
				std::string myRow;
				getline(myFile, myRow);
				std::vector<std::string> myDataString;
				size_t pos = 0;
				while ((pos = myRow.find(delimiter)) != std::string::npos) {
					myDataString.push_back(myRow.substr(0, pos));
					myRow.erase(0, pos + delimiter.length());
				}
				if (myDataString.size() == 5) {
					myDataSet.push_back(myDataString);
					teachMap.push_back(TeachPoint(myDataString));
				}
			}
		}
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


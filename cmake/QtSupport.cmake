# 3rd party location
### Qt framework
set(QT6_DIR "C:/Qt/6.7.0/mingw_64/lib/cmake")

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Gui Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR}  COMPONENTS Widgets Gui Core REQUIRED)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
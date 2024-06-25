# 3rd party location
set(3RD_PARTY_DIR                    ${CMAKE_SOURCE_DIR}/3rdParty  CACHE INTERNAL "")
set(PROJECT_BUILD_OUTPUT             ${CMAKE_SOURCE_DIR}/build/out CACHE INTERNAL "")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY   ${PROJECT_BUILD_OUTPUT}/lib   CACHE INTERNAL "")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY   ${PROJECT_BUILD_OUTPUT}/bin   CACHE INTERNAL "")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY   ${PROJECT_BUILD_OUTPUT}/lib   CACHE INTERNAL "")
set(CMAKE_LOG_OUTPUT_DIRECTORY       ${PROJECT_BUILD_OUTPUT}/log   CACHE INTERNAL "")
set(CMAKE_INSTALL_PREFIX             ${3RD_PARTY_DIR}/install      CACHE INTERNAL "")
if(UNIX)  
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BUILD_OUTPUT}/lib   CACHE INTERNAL "")  
endif()


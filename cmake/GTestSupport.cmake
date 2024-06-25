include(FetchContent)
# clone gtest build and install it 
#set(FETCHCONTENT_BASE_DIR "${3RD_PARTY_DIR}/deps")

set(LIBRARY_NAME googletest)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
  SOURCE_DIR    "${3RD_PARTY_DIR}/googletest/src"
  BINARY_DIR    "${3RD_PARTY_DIR}/googletest/build"
  SUBBUILD_DIR  "${3RD_PARTY_DIR}/googletest/build"
  TMP_DIR       "${3RD_PARTY_DIR}/googletest/build"
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory("${3RD_PARTY_DIR}/googletest/src" 
                     "${3RD_PARTY_DIR}/googletest/build")  
    set_target_properties(gmock gmock_main gtest gtest_main
      PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY     ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
      LIBRARY_OUTPUT_DIRECTORY     ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
      ARCHIVE_OUTPUT_DIRECTORY     ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
      PDB_OUTPUT_DIRECTORY         ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
      COMPILE_PDB_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
    )
endif()
include(googletest)
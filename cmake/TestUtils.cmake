
include(GTestSupport)
# build_gtest_executable
# Thin layer above standard CMake standard support providing utility
# functions.
#
# Use DISCOVER if you want CMake to discover the tests in the
# executable automatically with gtest_discover_tests()
#
function(build_gtest_executable)
    cmake_parse_arguments(PARGS "DISCOVER" "" "SRC;DEPENDS" ${ARGN})

    set(TEST_EXECUTABLE_NAME ${ARGV0})

    if(NOT "${TEST_EXECUTABLE_NAME}" MATCHES "test_.*")
        message(FATAL_ERROR "> ${TEST_EXECUTABLE_NAME} : for management restriction the executable name should start with test_")
    endif()

    if("${TEST_EXECUTABLE_NAME}" MATCHES ".*[A-Z].*")
        message(FATAL_ERROR "> ${TEST_EXECUTABLE_NAME}: for management restriction the executable name should start name be lowercase")
    endif()

    if ("${PARGS_SRC}" STREQUAL "")
        message(FATAL_ERROR "> ${TEST_EXECUTABLE_NAME}: missing source files for test executable")
    endif()
 
    add_executable(${TEST_EXECUTABLE_NAME} ${PARGS_SRC})
    
    target_link_libraries(${TEST_EXECUTABLE_NAME} PUBLIC ${PARGS_DEPENDS})    
 
    if(${PARGS_DISCOVER})
        gtest_discover_tests(${TEST_EXECUTABLE_NAME})
    endif()

endfunction()
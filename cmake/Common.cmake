# common utilities for CMake,
# Include this file as early as possible 
# in the top CMakeLists.txt

# Use C++ 17 at least for nested  
# namespaces and other new features 
set(CMAKE_CXX_STANDARD 20)


if(BUILD_VERBOSE_OUTPUT)
    include(DebugUtils)
    set(CMAKE_VERBOSE_MAKEFILE ON)
    dump_cmake_vars(configLogStart.log)
endif()

# some custom functions and macros
include(BuildUtils)


# Standard settings for build and import locations:
include(BuildLocation)


if(CMAKE_COMPILER_IS_GNUCXX 
    OR CMAKE_CXX_COMPILER_ID MATCHES Clang)
    # Activate all warnings 
    # and consider warnings as errors
    set(CMAKE_C_FLAGS 
    "${CMAKE_CXX_FLAGS} -Wall -Werror"
    )
    set(CMAKE_CXX_FLAGS 
    "${CMAKE_CXX_FLAGS} -Wall -Werror"
    )
endif()

if(BUILD_TESTING)
    print(BUILD_TESTING)
    include(CTest)
    enable_testing()
    include(TestUtils)
endif()

if(BUILD_QT_UI)
    include(QtSupport)
endif()

if(BUILD_VERBOSE_OUTPUT)
    dump_cmake_vars(configLogEnd.log)
endif()


# Get architecture 
macro(get_project_arch)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(PROJECT_ARCH_TARGET "amd64")    # x64
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)     
        set(PROJECT_ARCH_TARGET "i386")     # x86
    else()
        message(WARNING "Unkwnown architecture!")
    endif()
endmacro()

# validator
function(check_project_name)
    set(options)
    set(single_value_args NAME)
    set(list_args NAME_LIST)

    cmake_parse_arguments( 
        PARSE_ARGV 0
        parameter 
        "${options}" 
        "${single_value_args}"  
        "${list_args}"
    )
    foreach(arg IN LISTS parameter_UNPARSED_ARGUMENTS)
        message(" >>>>>> unparsed argumemnt: ${arg}")
    endforeach()
    set(project_list ${parameter_NAME_LIST})
    
    foreach(proj IN LISTS project_list)
        if(proj STREQUAL ${parameter_NAME})
            message(FATAL_ERROR " >>>>>> name already exists: ${proj}")
        endif()
    endforeach()
endfunction()
#unicity guard
macro(add_project name name_list)
    check_project_name(NAME ${name} NAME_LIST ${${name_list}})
    list( APPEND  ${name_list} ${name})
endmacro()
# Generates a raw target name from the given name.
# The raw name is generated by removing double colons "::"
# and converting to lowercase.
# This is used to convert names like "MyLib::MyLib" to something
# that add_library() will accept. You should define an alias once
# the target is defined.
macro(get_raw_target_name raw_target_name var_name)
    string(REPLACE "::" "_" ${var_name} ${raw_target_name})
    string(TOLOWER ${${var_name}} ${var_name})
endmacro()


function(create_library)
# LIB_NAME              ${TARGET_NAME}  LIB_FILES           ${TARGET_FILES}    
# PRIVATE_DEPENDENCIES  ${PRIVATE_DEPS} PUBLIC_DEPENDENCIES ${PUBLIC_DEPS}
# TEST_DISCOVER         ${TST_DISCOVER} TEST_SOURCES        ${TST_SOURCES}    
# TEST_DEPENDENCIES     ${TEST_DEPS}    LIB_RSC             ${TARGET_RSC}
set(options)
set(single_value_args LIB_NAME TEST_DISCOVER)
set(list_args LIB_FILES PRIVATE_DEPENDENCIES PUBLIC_DEPENDENCIES 
              TEST_SOURCES TEST_DEPENDENCIES LIB_RSC)

cmake_parse_arguments( 
    PARSE_ARGV 0
    parameter 
    "${options}" 
    "${single_value_args}"  
    "${list_args}"
)

foreach(arg IN LISTS parameter_UNPARSED_ARGUMENTS)
    message(" >>>>>> unparsed argumemnt: ${arg}")
endforeach()

if(DEFINED CMAKE_ROOT_NAME 
   AND NOT CMAKE_ROOT_NAME STREQUAL "")
    # Clients of this library should use this name, it contains a double colon
    # which tells CMake it's a target and allows for more specific error messages.
    set(LIBRARY_NAME  ${CMAKE_ROOT_NAME}::${parameter_LIB_NAME})
    # The internal, raw name is generated from LIBRARY_NAME
    get_raw_target_name(${LIBRARY_NAME} LIBRARY_NAME_RAW )
else()
    set(LIBRARY_NAME  ${parameter_LIB_NAME})
    # The internal, raw name is generated from LIBRARY_NAME
    set(LIBRARY_NAME_RAW ${LIBRARY_NAME})
endif()


###############################################################
# now add library 
###############################################################

add_library(${LIBRARY_NAME_RAW} ${parameter_LIB_FILES})

# create a dummy library aliasing the raw name
add_library(${LIBRARY_NAME} ALIAS ${LIBRARY_NAME_RAW})

include(GenerateExportHeader)
string(TOUPPER ${CMAKE_ROOT_NAME} API_FLAG)
#add_definitions(-DMAKE_${API_FLAG} )
generate_export_header(${LIBRARY_NAME_RAW}
                       EXPORT_FILE_NAME "${CMAKE_CURRENT_SOURCE_DIR}/include//${CMAKE_ROOT_NAME}/${parameter_LIB_NAME}/${CMAKE_ROOT_NAME}_export.h"
                       EXPORT_MACRO_NAME ${API_FLAG}_API
                       BASE_NAME ${API_FLAG}
                       DEFINE_NO_DEPRECATED)
                       #NO_EXPORT_MACRO_NAME ${API_FLAG}_API)
###############################################################
# Manage compiler Flags
###############################################################

# This is used in build with MSVC an export flag must be set  
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(compiler_id 1)
else()
    set(compiler_id 0)
endif()


###############################################################
# linking
###############################################################
target_include_directories(${LIBRARY_NAME_RAW}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:include/>
)
target_link_libraries(${LIBRARY_NAME_RAW}
    PRIVATE
        # private dependencies here
        ${parameter_PRIVATE_DEPENDENCIES}
    PUBLIC
        # public dependencies here
        ${parameter_PUBLIC_DEPENDENCIES}
)

###############################################################
# Testing
###############################################################
if(BUILD_TESTING)
    # Test executable names must start with "test_" 
    # and be lowercase
    set(TEST_NAME "test_${LIBRARY_NAME_RAW}")
    set(GTEST_DEPENDENCIES gtest gmock_main gmock)
    # usage: 
    # include("TestUtils")
    # add_gtest_executable(test_library_name
    #     SRC
    #         test_file1.cpp
    #         test_file2.cpp
    #     DEPENDS
    #         Some::Libs
    #     DISCOVER
    #         [ON/OFF]
    # )
    build_gtest_executable(
       ${TEST_NAME} 
        SRC
        # C++ files containing test cases should start 
        # with test_ to identify them more easily.
            ${parameter_TEST_SOURCES}
        DEPENDS
            ${parameter_TEST_DEPENDENCIES} 
            ${GTEST_DEPENDENCIES}
            ${LIBRARY_NAME}
        DISCOVER
            ${parameter_TEST_DISCOVER}
    )
endif()

endfunction()



# create_application(
#     NAME  "PROJECT_x_NAME"
#     ENTRY ["Console" "QT_ui" "WX_ui" "Service"]
#     HEADERS "<header.h ...>""
#     SOURCES ">sozrce.cpp ...>"
#     RESOURCES "<file.txt ...>"
#     UI "form.ui"
#     BUILD_ARGS "<WIN32 ...>"     
#     DEPENDENCIES "internal::dependencies" "third_party::dependencies"
# )
function(create_application)
    set(options)
    set(single_value_args NAME ENTRY UI)
    set(list_args HEADERS SOURCES RESOURCES BUILD_ARGS DEPENDENCIES)

    cmake_parse_arguments( 
        PARSE_ARGV 0
        app 
        "${options}" 
        "${single_value_args}"  
        "${list_args}"
    )

    foreach(arg IN LISTS app_UNPARSED_ARGUMENTS)
        message(" >>>>>> unparsed argumemnt: ${arg}")
    endforeach()
    if(NOT DEFINED app_ENTRY OR app_ENTRY STREQUAL "")
        message(FATAL_ERROR " >>>>>> ${app_NAME} is missing entry point definition [ENTRY]")
    endif()

    set(PROJECT_FILES ${app_HEADERS} ${app_SOURCES} ${app_UI} ${app_RESOURCES})
    if(app_ENTRY STREQUAL "Console")
        # build the executable
        add_executable( 
            ${app_NAME}       
            ${app_BUILD_ARGS}                   
            ${PROJECT_FILES}
        )
        
    elseif(app_ENTRY STREQUAL "QT_ui")
        qt_add_executable( 
            ${app_NAME}       
            ${app_BUILD_ARGS}                   
            ${PROJECT_FILES}
        )

    endif()
    
    # link the executable
    #
    target_link_libraries(${app_NAME} PRIVATE ${app_DEPENDENCIES})
   
    
    if(app_ENTRY STREQUAL "QT_ui")
        set_target_properties(${app_NAME} 
            PROPERTIES 
            WIN32_EXECUTABLE TRUE
            MACOSX_BUNDLE    TRUE
        )
    endif()
endfunction()
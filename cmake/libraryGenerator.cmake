set(VAR_MARKER_START  [[${]]) 
set(VAR_MARKER_END })

function(generate_library)
    set(options)
    set(list_args)
    set(single_value_args NAME DESTINATION ROOT_NAME CFG_SRC)
    cmake_parse_arguments(PARSE_ARGV 0 lib 
        "${options}" 
        "${single_value_args}"  
        "${list_args}"
    )
    foreach(arg IN LISTS lib_UNPARSED_ARGUMENTS)
        message(WARNING " >>>>>> unparsed argumemnt: ${arg}")
    endforeach()

    if(NOT DEFINED lib_NAME OR 
                   lib_NAME STREQUAL "")
        return()
    endif()

    set(lib_DIR ${lib_DESTINATION}/${lib_NAME})
    if(IS_DIRECTORY "${lib_DIR}")
        message(STATUS "::> ${lib_NAME} is added dynamically")
        return()
    else()
        message(STATUS "::> generating ${lib_NAME}")
    endif()
    
    if(NOT DEFINED lib_ROOT_NAME OR 
                    lib_ROOT_NAME STREQUAL "")
        set(lib_ROOT_NAME Sandbox)
        message(WARNING " >>>>>> ${lib_NAME} is missing a root project name \"ROOT_NAME\" but it's needed, \nso it set to derfault value Sandbox")
    endif()

    set(lib_include_DIR ${lib_DIR}/include/${lib_ROOT_NAME}/${lib_NAME})
    set(lib_source_DIR ${lib_DIR}/src)
    set(lib_test_DIR ${lib_DIR}/test)
    set(gen_DIR ${lib_CFG_SRC})
    string(TOUPPER ${lib_ROOT_NAME} lib_ROOT_NAME_UPPER )
    string(TOUPPER ${lib_NAME} lib_NAME_UPPER )

  

    configure_file(${gen_DIR}/lib_CMakeLists.txt.in 
                    ${lib_DIR}/CMakeLists.txt)

    configure_file(${gen_DIR}/lib.h.in 
                    ${lib_include_DIR}/${lib_NAME}.h)
    configure_file(${gen_DIR}/lib.cpp.in
                    ${lib_source_DIR}/${lib_NAME}.cpp)

    configure_file(${gen_DIR}/lib_impl.h.in
                    ${lib_source_DIR}/${lib_NAME}_impl.h)
    configure_file(${gen_DIR}/lib_impl.cpp.in
                    ${lib_source_DIR}/${lib_NAME}_impl.cpp)

    configure_file(${gen_DIR}/test_lib.cpp.in 
                    ${lib_test_DIR}/src/test_${lib_NAME}.cpp)
endfunction()
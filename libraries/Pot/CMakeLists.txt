project(Pot VERSION 1.1.0 LANGUAGES CXX)

set(TARGET_NAME Pot)

set(TST_DISCOVER ON)
###############################################################
# Manage project files
###############################################################
set(TARGET_HEADERS
    # Public headers belong in: include/CMAKE_ROOT_NAME/...
    # Other components and applications will add "include" 
    # to their search path, and need to use  the following 
    # kind of path: #include <CMAKE_ROOT_NAME/PROJECT_NAME/...>
    include/${CMAKE_ROOT_NAME}/${TARGET_NAME}/${TARGET_NAME}.h
    include/${CMAKE_ROOT_NAME}/${TARGET_NAME}/INIfile.h
    include/${CMAKE_ROOT_NAME}/${TARGET_NAME}/Conception.h
    include/${CMAKE_ROOT_NAME}/${TARGET_NAME}/Point.h
)

set(LIBRARY_ALIAS ${CMAKE_ROOT_NAME}::${TARGET_NAME})
get_raw_target_name(${LIBRARY_ALIAS} LIBRARY_NAME_RAW)

add_library(   ${LIBRARY_NAME_RAW} INTERFACE)
target_sources(${LIBRARY_NAME_RAW} INTERFACE 
    ${TARGET_HEADERS}
)

target_compile_features(${LIBRARY_NAME_RAW} INTERFACE 
    cxx_std_20
)
target_link_libraries(  ${LIBRARY_NAME_RAW} INTERFACE 
    ${CMAKE_ROOT_NAME}::Core
)
target_include_directories( ${LIBRARY_NAME_RAW} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:include/>
)
add_library(${CMAKE_ROOT_NAME}::${TARGET_NAME} ALIAS 
    ${LIBRARY_NAME_RAW}
)
# ###############################################################
# # Manage testing files
# ###############################################################
if(BUILD_TESTING)
    set(TST_SOURCES
        test/src/test_${TARGET_NAME}.cpp
    )
    set(TEST_DEPENDENCIES
    )
    set(TEST_NAME "test_${LIBRARY_NAME_RAW}")
    set(GTEST_DEPENDENCIES gtest gmock_main gmock)
    
    build_gtest_executable(
       ${TEST_NAME} 
        SRC
            ${TST_SOURCES}
        DEPENDS
            ${TEST_DEPENDENCIES} 
            ${GTEST_DEPENDENCIES}
            ${CMAKE_ROOT_NAME}::${TARGET_NAME}
        DISCOVER
            ${TST_DISCOVER}
    )
endif()
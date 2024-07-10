add_subdirectory(Gamebox)

####################################
# generate libraries from template if not exist 
# and add it as sub directory 
####################################
include(libraryGenerator)

set(LIBRARIES_LIST Core 
                   Tools
)

set(lib_LOCATION ${CMAKE_SOURCE_DIR}/libraries)
set(gen_DIR      ${CMAKE_SOURCE_DIR}/template)


foreach(item IN LISTS LIBRARIES_LIST)
    # generate_library( NAME:  library_name
    #                   DESTINATION:  where is the library folder
    #                   ROOT_NAME: the root name of the main project 
    #                   CFG_SRC: configuration source folder 
    generate_library(NAME ${item}
                     DESTINATION ${lib_LOCATION} 
                     ROOT_NAME ${CMAKE_ROOT_NAME}
                     CFG_SRC ${gen_DIR}
    )
    add_subdirectory(${item})
endforeach()
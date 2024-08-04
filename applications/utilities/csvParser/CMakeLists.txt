project(csvParser VERSION 1.1.1 LANGUAGES CXX)
set(PROJECT_LIST)
# Don't use PROJECT_NAME as target name, 
# using a proper executable name gives 
# more freedom 
set(EXECUTABLE_NAME ${PROJECT_NAME})
add_project(${EXECUTABLE_NAME} PROJECT_LIST)

set(BUILD_${EXECUTABLE_NAME} ${BUILD_APPS})
# executable type 
set(${EXECUTABLE_NAME}_ENTRY "Console")

# header files
set(${EXECUTABLE_NAME}_HEADERS
)

# source files
set(${EXECUTABLE_NAME}_SOURCES
    csvParser.cpp
)

# forme files
set(${EXECUTABLE_NAME}_UI
)

# ressources
set(${EXECUTABLE_NAME}_RSC
    myCSVFile.csv
)
# dependencies
set(${EXECUTABLE_NAME}_DEPS
    ${CMAKE_ROOT_NAME}::Tools
)
# compile arguments
set(${EXECUTABLE_NAME}_BUILD_ARGS 
)

#################################################
# Build all the projects
#################################################

foreach(item IN LISTS PROJECT_LIST)
    foreach(rsc IN LISTS ${item}_RSC)
        file(COPY ${rsc} DESTINATION ${PROJECT_BUILD_OUTPUT}/data/${EXECUTABLE_NAME})
    endforeach()
    if(BUILD_${item})
        # create_application(
        #     NAME  "PROJECT_x_NAME"
        #     ENTRY ["Console" "QT_ui" "WX_ui" "Service"]
        #     HEADERS "<header.h ...>""
        #     SOURCES ">source.cpp ...>"
        #     RESOURCES "<file.txt ...>"
        #     UI "form.ui"     
        #     BUILD_ARGS "<WIN32 ...>"
        #     DEPENDENCIES "internal::dependencies" "third_party::dependencies"
        # )
        create_application(
            NAME         ${item}
            ENTRY        ${${item}_ENTRY}
            HEADERS      ${${item}_HEADERS} 
            SOURCES      ${${item}_SOURCES} 
            RESOURCES    ${${item}_RSC}
            UI           ${${item}_UI}     
            BUILD_ARGS   ${${item}_BUILD_ARGS}
            DEPENDENCIES ${${item}_DEPS}       
        )
    endif()

endforeach()
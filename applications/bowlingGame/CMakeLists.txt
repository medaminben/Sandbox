project(BowlingGame LANGUAGES CXX)
set(PROJECT_LIST)

# Don't use PROJECT_NAME as target name, 
# using a proper executable name gives 
# more freedom 

#################################################
# executable 
#################################################
set(EXECUTABLE_NAME BowlingConsole)
add_project(${EXECUTABLE_NAME} PROJECT_LIST)

set(BUILD_${EXECUTABLE_NAME} ${BUILD_APPS})
# executable type 
set(${EXECUTABLE_NAME}_ENTRY "Console")

# header files
set(${EXECUTABLE_NAME}_HEADERS
    bowlingScreen.h
)

# source files
set(${EXECUTABLE_NAME}_SOURCES
    console.cpp
    bowlingScreen.cpp
)

# forme files
set(${EXECUTABLE_NAME}_UI
)

# ressources
set(${EXECUTABLE_NAME}_RSC
)
# dependencies
set(${EXECUTABLE_NAME}_DEPS 
    ${CMAKE_ROOT_NAME}::Gamebox
)
# compile arguments
set(${EXECUTABLE_NAME}_BUILD_ARGS 
)


#################################################
# Build all the projects
#################################################

foreach(item IN LISTS PROJECT_LIST)

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



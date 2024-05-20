# Don't use PROJECT_NAME as target name, 
# using a proper executable name gives 
# more freedom 

#################################################
# executable 
#################################################
set(EXECUTABLE_NAME State)
set(EXEC_LIST)
set(THIS_DIR ${CMAKE_CURRENT_LIST_DIR}) 

add_project(${EXECUTABLE_NAME} EXEC_LIST) # add_guard

set(BUILD_${EXECUTABLE_NAME} 
    ${BUILD_APPS}
    PARENT_SCOPE
)
# executable type 
set(${EXECUTABLE_NAME}_ENTRY 
    Console
    PARENT_SCOPE
)

# header files
set(${EXECUTABLE_NAME}_HEADERS
    ${THIS_DIR}/State.h
    PARENT_SCOPE
)

# source files
set(${EXECUTABLE_NAME}_SOURCES
    ${THIS_DIR}/main.cpp
    ${THIS_DIR}/State.cpp
    PARENT_SCOPE
)

# forme files
set(${EXECUTABLE_NAME}_UI
    PARENT_SCOPE
)

# ressources
set(${EXECUTABLE_NAME}_RSC
    PARENT_SCOPE
)
# dependencies
set(${EXECUTABLE_NAME}_DEPS 
    PARENT_SCOPE
)
# compile arguments
set(${EXECUTABLE_NAME}_BUILD_ARGS 
    PARENT_SCOPE
)
set(PROJECT_LIST 
    ${PROJECT_LIST} 
    ${EXEC_LIST} 
    PARENT_SCOPE
)



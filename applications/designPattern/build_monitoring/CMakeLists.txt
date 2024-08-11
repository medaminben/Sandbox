# Don't use PROJECT_NAME as target name, 
# using a proper executable name gives 
# more freedom 


set(EXEC_LIST)
set(THIS_DIR ${CMAKE_CURRENT_LIST_DIR}) 
#################################################
# executable 
#################################################
set(EXECUTABLE_NAME ct_vs_rt)
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
    PARENT_SCOPE
)

# source files
set(${EXECUTABLE_NAME}_SOURCES
    ${THIS_DIR}/ct_vs_rt.cpp
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
#################################################
# executable 
#################################################
set(EXECUTABLE_NAME const_versus_constexpr)
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
    ${THIS_DIR}/constants.h
    PARENT_SCOPE
)

# source files
set(${EXECUTABLE_NAME}_SOURCES
    ${THIS_DIR}/const_versus_constexpr.cpp
    ${THIS_DIR}/constants.cpp
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


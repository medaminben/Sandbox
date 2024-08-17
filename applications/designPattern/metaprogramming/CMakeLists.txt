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
set(BUILD_${EXECUTABLE_NAME} ${BUILD_APPS}  PARENT_SCOPE)
# executable type 
set(${EXECUTABLE_NAME}_ENTRY Console PARENT_SCOPE )

# source files
set(${EXECUTABLE_NAME}_SOURCES
    ${THIS_DIR}/ct_vs_rt.cpp
    PARENT_SCOPE
)
set(PROJECT_LIST ${PROJECT_LIST}  ${EXEC_LIST} PARENT_SCOPE )
#################################################
# executable 
#################################################
set(EXECUTABLE_NAME const_versus_constexpr)
add_project(${EXECUTABLE_NAME} EXEC_LIST) # add_guard
set(BUILD_${EXECUTABLE_NAME} ${BUILD_APPS}  PARENT_SCOPE)
# executable type 
set(${EXECUTABLE_NAME}_ENTRY Console PARENT_SCOPE )
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
set(PROJECT_LIST ${PROJECT_LIST}  ${EXEC_LIST} PARENT_SCOPE )
#################################################
# executable non_typed_template
#################################################
set(EXECUTABLE_NAME non_typed_template)
add_project(${EXECUTABLE_NAME} EXEC_LIST) # add_guard
set(BUILD_${EXECUTABLE_NAME} ${BUILD_APPS}  PARENT_SCOPE)
# executable type 
set(${EXECUTABLE_NAME}_ENTRY Console PARENT_SCOPE )
# source files
set(${EXECUTABLE_NAME}_SOURCES
    ${THIS_DIR}/non_typed_class_template.cpp
    PARENT_SCOPE
)
set(PROJECT_LIST ${PROJECT_LIST}  ${EXEC_LIST} PARENT_SCOPE )
#################################################
# executable deep_non_typed_class_template
#################################################
set(EXECUTABLE_NAME deep_non_typed_class_template)
add_project(${EXECUTABLE_NAME} EXEC_LIST) # add_guard
set(BUILD_${EXECUTABLE_NAME} ${BUILD_APPS}  PARENT_SCOPE)
# executable type 
set(${EXECUTABLE_NAME}_ENTRY  Console PARENT_SCOPE)
# source files
set(${EXECUTABLE_NAME}_SOURCES
    ${THIS_DIR}/deep_non_typed_class_template.cpp
    PARENT_SCOPE
)
set(PROJECT_LIST ${PROJECT_LIST} ${EXEC_LIST} PARENT_SCOPE)
#################################################
# executable constexpr_tuple
#################################################
set(EXECUTABLE_NAME constexpr_tuple)
add_project(${EXECUTABLE_NAME} EXEC_LIST) # add_guard
set(BUILD_${EXECUTABLE_NAME} ${BUILD_APPS}  PARENT_SCOPE)
# executable type 
set(${EXECUTABLE_NAME}_ENTRY  Console PARENT_SCOPE)
# source files
set(${EXECUTABLE_NAME}_SOURCES
    ${THIS_DIR}/constexpr_tuple.cpp
    PARENT_SCOPE
)
set(PROJECT_LIST ${PROJECT_LIST} ${EXEC_LIST} PARENT_SCOPE)
#################################################
# executable mpl_traits
#################################################
set(EXECUTABLE_NAME mpl_traits)
add_project(${EXECUTABLE_NAME} EXEC_LIST) # add_guard
set(BUILD_${EXECUTABLE_NAME} ${BUILD_APPS}  PARENT_SCOPE)
# executable type 
set(${EXECUTABLE_NAME}_ENTRY  Console PARENT_SCOPE)
# source files
set(${EXECUTABLE_NAME}_SOURCES
    ${THIS_DIR}/mpl_traits.cpp
    PARENT_SCOPE
)
set(PROJECT_LIST ${PROJECT_LIST} ${EXEC_LIST} PARENT_SCOPE)
#################################################
# executable construct_validation
#################################################
set(EXECUTABLE_NAME construct_validation)
add_project(${EXECUTABLE_NAME} EXEC_LIST) # add_guard
set(BUILD_${EXECUTABLE_NAME} ${BUILD_APPS}  PARENT_SCOPE)
# executable type 
set(${EXECUTABLE_NAME}_ENTRY  Console PARENT_SCOPE)
# source files
set(${EXECUTABLE_NAME}_SOURCES
    ${THIS_DIR}/construct_validation.cpp
    PARENT_SCOPE
)
set(PROJECT_LIST ${PROJECT_LIST} ${EXEC_LIST} PARENT_SCOPE)
#################################################
# executable generic_lambda
#################################################
set(EXECUTABLE_NAME generic_lambda)
add_project(${EXECUTABLE_NAME} EXEC_LIST) # add_guard
set(BUILD_${EXECUTABLE_NAME} ${BUILD_APPS}  PARENT_SCOPE)
# executable type 
set(${EXECUTABLE_NAME}_ENTRY  Console PARENT_SCOPE)
# source files
set(${EXECUTABLE_NAME}_SOURCES
    ${THIS_DIR}/generic_lambda.cpp
    PARENT_SCOPE
)
set(PROJECT_LIST ${PROJECT_LIST} ${EXEC_LIST} PARENT_SCOPE)
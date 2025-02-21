include_directories(${CMAKE_CURRENT_LIST_DIR}/inc/)

add_library(ArrayList_Callout OBJECT ${CMAKE_CURRENT_LIST_DIR}/src/ArrayList_Callout.c)

add_library(ArrayList ${CMAKE_CURRENT_LIST_DIR}/src/ArrayList.c)
target_link_libraries(ArrayList ArrayList_Callout)
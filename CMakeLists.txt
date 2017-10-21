cmake_minimum_required(VERSION 3.1)

project(DB_struct) 
set(SOURCE_EXE mmain.c)

set(SOURCE_LIB_AVL AVLnode.c AVLnode_spesial.c AVLnode_test.c)
set(SOURCE_LIB_HASH HashMap.c hashf.c)

add_library(AVLnode STATIC ${SOURCE_LIB_AVL})
add_library(HashMap STATIC ${SOURCE_LIB_HASH})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main AVLnode HashMap)
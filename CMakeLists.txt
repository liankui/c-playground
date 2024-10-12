cmake_minimum_required(VERSION 3.29)
project(c_playground C)

set(CMAKE_C_STANDARD 11)

add_executable(c_playground
    basic/arrya.c
    basic/dataType.c
    basic/function.c
    basic/hello.c
    basic/input.c
    basic/pointe.c
    basic/string.c
    basic/structure.c
    data-structure/linked_list/double_linked_list.c
    data-structure/linked_list/single_linked_list.c
    data-structure/sequenct_list/sequence_list.c
    data-structure/stack/stack.c)

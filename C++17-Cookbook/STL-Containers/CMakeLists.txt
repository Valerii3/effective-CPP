cmake_minimum_required(VERSION 3.26)
project(STL_Containers)

set(CMAKE_CXX_STANDARD 17)

add_executable(STL_Containers
        insert-method.cpp
        custom-key-hashmap.cpp)

cmake_minimum_required(VERSION 3.27)
project(Project3)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(wxWidgets-3.2.6)

add_executable(Project3
        main.cpp
        FoodList.cpp)

target_link_libraries(Project3 wx::net wx::core wx::base)
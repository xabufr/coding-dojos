project(KataRomanNumerals)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
aux_source_directory(. SRC_LIST)
file( GLOB_RECURSE
    source_files
    ./src/*.cpp
)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(${PROJECT_NAME} ${SRC_LIST} ${source_files} )
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

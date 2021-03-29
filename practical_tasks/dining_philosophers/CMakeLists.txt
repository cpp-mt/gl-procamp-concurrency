# Copyright 2018, GlobalLogic Inc.
# All rights reserved.
#

cmake_minimum_required(VERSION 3.1)

project(dining_philosophers)

add_executable(dining_philosophers_gTest
    project/dining_philosophers.cpp
    test/dining_philosophers_gTest.cpp
)


add_executable(dining_philosophers_mt
    project/dining_philosophers.cpp
    project/dining_philosophers_mt.cpp
)

target_include_directories(dining_philosophers_gTest PUBLIC
    project
)
set_target_properties(dining_philosophers_gTest PROPERTIES
    CXX_STANDARD 14
)



# for debug purpose only
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

target_sources(dining_philosophers_gTest PRIVATE
    $ENV{GTEST_DIR}/src/gtest-all.cc
)
target_include_directories(dining_philosophers_gTest PRIVATE
    $ENV{GTEST_DIR}
    $ENV{GTEST_DIR}/include
)
target_link_libraries(dining_philosophers_gTest
    pthread
)
target_link_libraries(dining_philosophers_mt
    pthread
)

# Copyright 2018, GlobalLogic Inc.
# All rights reserved.
#

cmake_minimum_required(VERSION 3.1)

project(mt_task)

add_executable(mt_task_gTest
    project/words_count.h
    project/words_count_mt.cpp
    project/words_count_st.cpp
    project/words_count_common.h
    project/words_count_common.cpp
    project/counter.h
    project/counter_mt.cpp
    project/counter_st.cpp
    project/accumulate_list_common.cpp
    project/accumulate_list.h
    project/accumulate_list_st.cpp
    project/accumulate_list_mt.cpp
    project/time_logger.h
    project/time_logger.cpp
    test/mt_task_gTest.cpp
)


add_executable(words_count_st
    project/words_count.h
    project/words_count_st.cpp
    project/words_count_common.h
    project/words_count_common.cpp
    project/words_count_st_runner.cpp
    project/time_logger.h
    project/time_logger.cpp
)

target_include_directories(mt_task_gTest PUBLIC
    project
)
set_target_properties(mt_task_gTest PROPERTIES
    CXX_STANDARD 14
)


target_include_directories(words_count_st PUBLIC
    project
)
set_target_properties(words_count_st PROPERTIES
    CXX_STANDARD 14
)

# for debug purpose only
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

target_sources(mt_task_gTest PRIVATE
    $ENV{GTEST_DIR}/src/gtest-all.cc
)
target_include_directories(mt_task_gTest PRIVATE
    $ENV{GTEST_DIR}
    $ENV{GTEST_DIR}/include
)
target_link_libraries(mt_task_gTest
    pthread
)

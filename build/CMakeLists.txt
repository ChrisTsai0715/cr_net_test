cmake_minimum_required(VERSION 2.8)

project(cr_net_test)

include_directories(../src/common
    ../src
)

set(SRC_LIST ../src/main.cpp
    ../src/common/base_thread.cpp
    ../src/net_connect_utils.h
)

set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC -s")

link_libraries( rt
                pthread
                dl
                m)

add_executable(${PROJECT_NAME} ${SRC_LIST})

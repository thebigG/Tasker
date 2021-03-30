cmake_minimum_required(VERSION 3.5)

project(XHook LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SHELL /bin/zsh)

set(TASKER_ROOT ${CMAKE_SOURCE_DIR}/../../..)

add_custom_command(OUTPUT build_libuiohook
                   COMMAND ${SHELL} ${CMAKE_SOURCE_DIR}/build_libuiohook.sh
                   WORKING_DIRECTORY ${TASKER_ROOT})

add_executable(XHook
    build_libuiohook
  main.cpp
)

target_include_directories(XHook PRIVATE ${TASKER_ROOT}/libuiohook/include)
#Not the cleanest way of doing this, but will do for now.
target_link_libraries(XHook ${TASKER_ROOT}/libuiohook/build/libuiohook.so)



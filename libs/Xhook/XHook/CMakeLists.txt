cmake_minimum_required(VERSION 3.5)

project(XHook LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(Qt5Core)

add_executable(XHook
  main.cpp
)
target_include_directories(XHook PRIVATE ${CMAKE_SOURCE_DIR}/../../../libuiohook/include)


#target_link_libraries(XHook Qt5::Core)
target_link_libraries(XHook ${CMAKE_SOURCE_DIR}/../../../libuiohook/build/libuiohook.so)

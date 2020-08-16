cmake_minimum_required(VERSION 3.5)

project(XHook LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(XHook
  main.cpp
)
#TODO: Link iohook to Xhook
execute_process(COMMAND "cmake -S .. -DENABLE_DEMO=ON -DENABLE_SHARED=ON -DCMAKE_INSTALL_PREFIX=../dis"
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/../../../libuiohook/)

execute_process(COMMAND "cmake --build . --parallel 2 --target install"
                            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/../../../libuiohook/)

LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/../../../libuiohook/)

target_include_directories(XHook PRIVATE ${CMAKE_SOURCE_DIR}/../../../libuiohook/include)
target_link_libraries(XHook Qt5::Core)

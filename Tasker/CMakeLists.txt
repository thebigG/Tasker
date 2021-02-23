cmake_minimum_required(VERSION 3.5)

project(jack-tasker-plugin LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Turn on automatic invocation of the MOC, UIC & RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(tasker main.cpp)

# Add the Qt5 libraries for linking
target_link_libraries(tasker Qt5::Core)
target_link_libraries(tasker Qt5::Multimedia)

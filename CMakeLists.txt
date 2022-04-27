cmake_minimum_required(VERSION 3.5)

project(Tasker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(APPLE)
add_compile_options(-stdlib=libstdc++)
link_directories(/usr/local/lib)
endif()

add_subdirectory(Tasker)

cmake_minimum_required(VERSION 3.5)

project(Tasker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Turn on automatic invocation of the MOC, UIC & RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    message(STATUS ${CMAKE_BUILD_TYPE})
    add_compile_definitions(__TASKER_DEBUG__=1)
endif ()
find_package(Qt5 REQUIRED COMPONENTS Widgets  Charts)


message(STATUS ${WIN32})

set(TASKER_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)

#Not sure if this is the best way of handling includes. Don't like it too much because it is not explicit in source code.
include_directories(
                    ${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Hooks/Audio/
                    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Hooks/XHook/
                    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Hooks/XHook/Audio/Jack
                    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Hooks
                    ${CMAKE_CURRENT_SOURCE_DIR}/Engine
                    ${CMAKE_CURRENT_SOURCE_DIR}/udata
                   ${CMAKE_CURRENT_SOURCE_DIR}/Ui/
                   ${CMAKE_CURRENT_SOURCE_DIR}/../miniaudio
		    )


set(SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/AppGuard.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Hooks/Audio/AudioHook.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/udata/Commitment.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/CommitmentSnaphot.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/CommStatsQWidget.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/CreateCommitmentQWidget.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Hooks/Hook.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/livesession.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/mainui.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/NewSessionQWidget.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/udata/Session.cpp
        StatsUtility.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/udata/Task.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Timer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/udata/UdataUtils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/udata/User.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Hooks/XHook/XHook.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TaskerPerf/perftimer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/CommStatsQWidget.ui
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/CreateCommitmentQWidget.ui
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/livesession.ui
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/NewSessionQWidget.ui
        Tasker.qrc)

#List out headers for IDEs
set(HEADERS
        AppGuard.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Hooks/Audio/AudioHook.h
        ${CMAKE_CURRENT_SOURCE_DIR}/udata/Commitment.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/CommitmentSnapshot.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/CommStatsQWidget.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/CreateCommitmentQWidget.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Hooks/Hook.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/livesession.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/mainui.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Ui/NewSessionQWidget.h
        ${CMAKE_CURRENT_SOURCE_DIR}/udata/Session.h
        StatsUtility.h
        ${CMAKE_CURRENT_SOURCE_DIR}/udata/Task.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Timer.h
        ${CMAKE_CURRENT_SOURCE_DIR}/udata/UdataUtils.h
        ${CMAKE_CURRENT_SOURCE_DIR}/udata/User.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Hooks/XHook/XHook.h
        TaskerPerf/perftimer.h)

add_executable(Tasker  ${SOURCES} ${HEADERS})

# Add the Qt5 libraries for linking
target_link_libraries(Tasker Qt5::Core)
target_link_libraries(Tasker Qt5::Charts)

message(STATUS ${UIOHOOK_ENABLE_STATIC})
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../libuiohook external_libs)

target_link_libraries(Tasker  uiohook)

install(TARGETS Tasker
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    )

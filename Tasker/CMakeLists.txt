cmake_minimum_required(VERSION 3.5)

project(Tasker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Turn on automatic invocation of the MOC, UIC & RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Multimedia Charts)

#Not sure if this is the best way of handling includes. Don't like it took much because it is not explicit in source code.
include_directories(${CMAKE_SOURCE_DIR}
                    ${CMAKE_SOURCE_DIR}/Engine/Hooks/Audio/
                    ${CMAKE_SOURCE_DIR}/Engine/Hooks/XHook/
                    ${CMAKE_SOURCE_DIR}/Engine/Hooks
                    ${CMAKE_SOURCE_DIR}/Engine
                    ${CMAKE_SOURCE_DIR}/udata
		    ${CMAKE_SOURCE_DIR}/Ui/)

set(SOURCES
        main.cpp
        AppGuard.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Hooks/Audio/AudioDevice.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Hooks/Audio/AudioHook.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Hooks/Audio/AudioMachine.cpp
        ${CMAKE_SOURCE_DIR}/udata/Commitment.cpp
        ${CMAKE_SOURCE_DIR}/Ui/CommitmentSnaphot.cpp
        ${CMAKE_SOURCE_DIR}/Ui/CommStatsQWidget.cpp
        ${CMAKE_SOURCE_DIR}/Ui/CreateCommitmentQWidget.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Hooks/Hook.cpp
        ${CMAKE_SOURCE_DIR}/Ui/livesession.cpp
        main.cpp
        ${CMAKE_SOURCE_DIR}/Ui/mainui.cpp
        ${CMAKE_SOURCE_DIR}/Ui/NewSessionQWidget.cpp
        ${CMAKE_SOURCE_DIR}/udata/Session.cpp
        StatsUtility.cpp
        ${CMAKE_SOURCE_DIR}/udata/Task.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Timer.cpp
        ${CMAKE_SOURCE_DIR}/udata/UdataUtils.cpp
        ${CMAKE_SOURCE_DIR}/udata/User.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Hooks/XHook/XHook.cpp
        ${CMAKE_SOURCE_DIR}/TaskerPerf/perftimer.cpp
        ${CMAKE_SOURCE_DIR}/Ui/CommStatsQWidget.ui
        ${CMAKE_SOURCE_DIR}/Ui/CreateCommitmentQWidget.ui
	Tasker.qrc)

#List out headers for IDEs
set(HEADERS
        AppGuard.h
        ${CMAKE_SOURCE_DIR}/Engine/Hooks/Audio/AudioDevice.h
        ${CMAKE_SOURCE_DIR}/Engine/Hooks/Audio/AudioHook.h
        ${CMAKE_SOURCE_DIR}/Engine/Hooks/Audio/AudioMachine.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Hooks/Audio/AudioMachine.h
        ${CMAKE_SOURCE_DIR}/udata/Commitment.h
        ${CMAKE_SOURCE_DIR}/Ui/CommitmentSnapshot.h
        ${CMAKE_SOURCE_DIR}/Ui/CommStatsQWidget.h
        ${CMAKE_SOURCE_DIR}/Ui/CreateCommitmentQWidget.h
        ${CMAKE_SOURCE_DIR}/Engine/Hooks/Hook.h
        ${CMAKE_SOURCE_DIR}/Ui/livesession.h
        ${CMAKE_SOURCE_DIR}/Ui/mainui.h
        ${CMAKE_SOURCE_DIR}/Ui/NewSessionQWidget.h
        ${CMAKE_SOURCE_DIR}/udata/Session.h
        StatsUtility.h
        ${CMAKE_SOURCE_DIR}/udata/Task.h
        ${CMAKE_SOURCE_DIR}/Engine/Timer.h
        ${CMAKE_SOURCE_DIR}/udata/UdataUtils.h
        ${CMAKE_SOURCE_DIR}/udata/User.h
        ${CMAKE_SOURCE_DIR}/Engine/Hooks/XHook/XHook.h
        TaskerPerf/perftimer.h)

add_executable(Tasker  ${SOURCES} ${HEADERS})

# Add the Qt5 libraries for linking
target_link_libraries(Tasker Qt5::Core)
target_link_libraries(Tasker Qt5::Multimedia)
target_link_libraries(Tasker Qt5::Charts)

cmake_minimum_required(VERSION 3.5)

project(jack-tasker-plugin LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Turn on automatic invocation of the MOC, UIC & RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Multimedia Charts)

include_directories(${CMAKE_SOURCE_DIR})

set(SOURCES
        main.cpp
        AppGuard.cpp
        AudioDevice.cpp
        AudioHook.cpp
        AudioMachine.cpp
        Commitment.cpp
        CommitmentSnaphot.cpp
        CommStatsQWidget.cpp
        CreateCommitmentQWidget.cpp
        Hook.cpp
        livesession.cpp
        main.cpp
        mainui.cpp
        NewSessionQWidget.cpp
        Session.cpp
        StatsUtility.cpp
        Task.cpp
        Timer.cpp
        UdataUtils.cpp
        User.cpp
        XHook.cpp
        ${CMAKE_SOURCE_DIR}/TaskerPerf/perftimer.cpp
        Tasker.qrc)
add_executable(tasker ${SOURCES})

# Add the Qt5 libraries for linking
target_link_libraries(tasker Qt5::Core)
target_link_libraries(tasker Qt5::Multimedia)
target_link_libraries(tasker Qt5::Charts)

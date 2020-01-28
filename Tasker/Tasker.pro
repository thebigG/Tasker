QT += core gui
QT += multimedia
QT += testlib

unix:{
    # suppress the default RPATH if you wish
    QMAKE_LFLAGS_RPATH=
    # add your own with quoting gyrations to make sure $ORIGIN gets to the command line unexpanded
    QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/lib\'"
}


#QT += charts
#DO NOT delete the next includepath line! If you do, things WILL break on linux
linux-g++*{
INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5
}

QT += multimedia
#QMAKE_CXXFLAGS += "-fno-sized-deallocation"
CONFIG += static
#QMAKE_LFLAGS += -Xlinker -Bstatic
#Print the debug messages ONLY in release mode
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT
#QMAKE_CXXFLAGS += lobjc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AudioDevice.cpp \
    AudioListener.cpp \
    AudioMachine.cpp \
    AudioThread.cpp \
    CommStatsQWidget.cpp \
    Commitment.cpp \
    CreateCommitmentQWidget.cpp \
    Listener.cpp \
    KeyboardListener.cpp \
    Session.cpp \
    Task.cpp \
    StatsUtility.cpp \
    TaskerPerf/perftimer.cpp \
    TaskerUIMainWindowQWidget.cpp \
    Timer.cpp \
    TimerWindowQWidget.cpp \
    UdataUtils.cpp \
    User.cpp \
    livesession.cpp \
    mainui.cpp \
    main.cpp \
    objctest.mm \
    timerthread.cpp

HEADERS += \
    AudioDevice.h \
    AudioListener.h \
    AudioMachine.h \
    AudioThread.h \
    CommStatsQWidget.h \
    Commitment.h \
    CreateCommitmentQWidget.h \
    Listener.h \
    KeyboardListener.h \
    Session.h \
    Task.h \
    TaskerPerf/perftimer.h \
    TaskerUIMainWindowQWidget.h \
    Timer.h \
    TimerWindowQWidget.h \
    Interval.h \
    StatsUtility.h \
    TaskerUIMainWindowQWidget.h \
    TimerWindowQWidget.h \
    UdataUtils.h \
    livesession.h \
    mainui.h \
    User.h \
    objctest.h \
    timerthread.h

FORMS += \
    CommStatsQWidget.ui \
    CreateCommitmentQWidget.ui \
    TaskerUIMainWindowQWidget.ui \
    TimerWindowQWidget.ui \
    livesession.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    TaskerPerf/README.md

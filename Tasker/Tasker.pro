QT += core gui
QT += multimedia
QT += testlib
QT += charts
#QMAKE_CXXFLAGS +=  -lXt
#QMAKE_CXXFLAGS += "-fno-sized-deallocation"
#QMAKE_CXXFLAGS += -lX11
QMAKE_LFLAGS += -no-pie
CONFIG(release, debug|release) {
    #This is a release build
    DEFINES += QT_NO_DEBUG_OUTPUT
} else {
    #This is a non-release(debug) build
    DEFINES+=__TASKER_DEBUG__
}
#QMAKE_CXXFLAGS += "LDFLAGS=-lX11"
#QMAKE_CXXFLAGS += -lXcb
unix:{
    # suppress the default RPATH if you wish
#    QMAKE_LFLAGS_RPATH=
    # add your own with quoting gyrations to make sure $ORIGIN gets to the command line unexpanded
#    QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/lib\'"
}

#DO NOT delete the next includepath line! If you do, things WILL break on linux
linux-g++*{
#QMAKE_CXXFLAGS+= "-lX11"
#QMAKE_CXXFLAGS += "-lICE"
#QMAKE_CXXFLAGS += "-lSM"
#QMAKE_CXXFLAGS += "-no-pie"
#QMAKE_CXXFLAGS += "-lxcb-xkb"
#LIBS += -L../libs -lX11
INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5
#CONFIG(release, debug|release)
#{
#DEFINES -=__TASKER_DEBUG__
#DEFINES += QT_NO_DEBUG_OUTPUT
#}
#debug
#{
#DEFINES+=__TASKER_DEBUG__
#DEFINES += QT_NO_DEBUG_OUTPUT
#}
}
#macx:
#{
#debug
#{
#DEFINES+=__TASKER_DEBUG__
#DEFINES += QT_NO_DEBUG_OUTPUT
#}
#!debug
#{
#DEFINES -= QT_NO_DEBUG_OUTPUT
#DEFINES -=__TASKER_DEBUG__
#}
##    SOURCES +=   objctest.mm
##    HEADERS += objctest.h
#}

QT += multimedia
QMAKE_CXXFLAGS += "-pthread"
QMAKE_CXXFLAGS = -std=c++14
#CONFIG += static
CONFIG += -std=c++14

#CONFIG+=CONFIG(debug, debug|release)
#{
#DEFINES+=__TASKER_DEBUG__
#DEFINES += QT_NO_DEBUG_OUTPUT
#}
#!debug
#{
#DEFINES -= QT_NO_DEBUG_OUTPUT
#DEFINES -=__TASKER_DEBUG__
#}
#QMAKE_LFLAGS += -Xlinker -Bstatic
#Print the debug messages ONLY in release mode
#QMAKE_CXXFLAGS += lobjc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#debug: DEFINES += __TASKER_DEBUG__
#!debug: DEFINES -= __TASKER_DEBUG__
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
    AudioHook.cpp \
    AudioMachine.cpp \
    CommStatsQWidget.cpp \
    Commitment.cpp \
    CommitmentSnaphot.cpp \
    CreateCommitmentQWidget.cpp \
    Hook.cpp \
    NewSessionQWidget.cpp \
    Session.cpp \
    Task.cpp \
    StatsUtility.cpp \
    TaskerPerf/perftimer.cpp \
    Timer.cpp \
    UdataUtils.cpp \
    User.cpp \
    XHook.cpp \
    livesession.cpp \
    mainui.cpp \
    main.cpp

HEADERS += \
    AudioDevice.h \
    AudioHook.h \
    AudioMachine.h \
    CommStatsQWidget.h \
    Commitment.h \
    CommitmentSnapshot.h \
    CreateCommitmentQWidget.h \
    Hook.h \
    NewSessionQWidget.h \
    Session.h \
    Task.h \
    TaskerPerf/perftimer.h \
    Timer.h \
    StatsUtility.h \
    UdataUtils.h \
    XHook.h \
    livesession.h \
    mainui.h \
    User.h \


FORMS += \
    CommStatsQWidget.ui \
    CreateCommitmentQWidget.ui \
    NewSessionQWidget.ui \
    livesession.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    TaskerPerf/README.md

QMAKE_LFLAGS += -Wl,-rpath,@loader_path/../,-rpath,@executable_path/../,-rpath,@executable_path/../Frameworks
QMAKE_LFLAGS += -Wl,-rpath,@loader_path/$$REL_PATH_TO_LIBS,-rpath,@loader_path/$$REL_PATH_TO_PLUGINS


linux-g++
{
#Use these if you would like to use iohook as a raw C library, which at the moment is not recommended.
#These are all static library, so obviously your binary will get bigger if you do this.
#INCLUDEPATH += ../libs/iohook
#INCLUDEPATH += ../libs/iohook/include
#DEPENDPATH += ../libs/iohook
#LIBS += ../libs/iohook/libuiohook.a
#LIBS += ../libs/iohook/libXtst.a
#LIBS += ../libs/iohook/libX11.a
#LIBS += ../libs/iohook/libXt.a
#LIBS += ../libs/iohook/libxkbcommon.a
#LIBS += ../libs/iohook/libxkbcommon-x11.a
#LIBS += ../libs/iohook/libxkbfile.a
#LIBS += ../libs/iohook/libXinerama.a
#LIBS += ../libs/iohook/libX11-xcb.a
#LIBS += ../libs/iohook/libX11.so.6
#LIBS += ../libs/iohook/libxcb.a
#LIBS += ../libs/iohook/libXau.a
#LIBS += ../libs/iohook/libXdmcp.a
#LIBS += -lICE
#LIBS += -lSM
#LIBS += ../libs/iohook/libXext.a
#LIBS += -lxcb-xkb
}

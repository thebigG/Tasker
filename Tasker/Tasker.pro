QT += core gui
QT += multimedia
QT += testlib
#QMAKE_CXXFLAGS +=  -lXt
#QMAKE_CXXFLAGS += -lX11
QMAKE_LFLAGS += -no-pie

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
}
macx:
{
#    SOURCES +=   objctest.mm
#    HEADERS += objctest.h
}

QT += multimedia
QMAKE_CXXFLAGS += "-pthread"
QMAKE_CXXFLAGS = -std=c++14
CONFIG += static
CONFIG += -std=c++14
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
    iohooklib.cpp \
    livesession.cpp \
    mainui.cpp \
    main.cpp

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
    StatsUtility.h \
    TaskerUIMainWindowQWidget.h \
    TimerWindowQWidget.h \
    UdataUtils.h \
    iohooklib.h \
    livesession.h \
    mainui.h \
    User.h \


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


#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -luiohook
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -luiohook
#else:unix: LIBS += -L$$PWD/../libs/ -luiohook

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libuiohook.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libuiohook.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/uiohook.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/uiohook.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libuiohook.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lX11
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lX11
#else:unix: LIBS += -L$$PWD/../libs/ -lX11

#INCLUDEPATH += $$PWD/../libs/
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libX11.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libX11.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/X11.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/X11.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libX11.a


#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lX11-xcb
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lX11-xcb
#else:unix: LIBS += -L$$PWD/../libs/ -lX11-xcb

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libX11-xcb.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libX11-xcb.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/X11-xcb.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/X11-xcb.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libX11-xcb.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXau
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXau
#else:unix: LIBS += -L$$PWD/../libs/ -lXau

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXau.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXau.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xau.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xau.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXau.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxcb
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxcb
#else:unix: LIBS += -L$$PWD/../libs/ -lxcb

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxcb.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxcb.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xcb.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xcb.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxcb.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxcb-dri2
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxcb-dri2
#else:unix: LIBS += -L$$PWD/../libs/ -lxcb-dri2

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxcb-dri2.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxcb-dri2.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xcb-dri2.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xcb-dri2.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxcb-dri2.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxcb-dri3
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxcb-dri3
#else:unix: LIBS += -L$$PWD/../libs/ -lxcb-dri3

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxcb-dri3.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxcb-dri3.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xcb-dri3.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xcb-dri3.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxcb-dri3.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxcb-glx
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxcb-glx
#else:unix: LIBS += -L$$PWD/../libs/ -lxcb-glx

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxcb-glx.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxcb-glx.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xcb-glx.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xcb-glx.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxcb-glx.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxcb-present
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxcb-present
#else:unix: LIBS += -L$$PWD/../libs/ -lxcb-present

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxcb-present.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxcb-present.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xcb-present.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xcb-present.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxcb-present.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxcb-randr
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxcb-randr
#else:unix: LIBS += -L$$PWD/../libs/ -lxcb-randr

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxcb-randr.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxcb-randr.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xcb-randr.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xcb-randr.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxcb-randr.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxcb-render
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxcb-render
#else:unix: LIBS += -L$$PWD/../libs/ -lxcb-render

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxcb-render.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxcb-render.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xcb-render.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xcb-render.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxcb-render.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxcb-shape
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxcb-shape
#else:unix: LIBS += -L$$PWD/../libs/ -lxcb-shape

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxcb-shape.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxcb-shape.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xcb-shape.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xcb-shape.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxcb-shape.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxcb-shm
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxcb-shm
#else:unix: LIBS += -L$$PWD/../libs/ -lxcb-shm

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxcb-shm.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxcb-shm.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xcb-shm.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xcb-shm.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxcb-shm.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxcb-shm
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxcb-shm
#else:unix: LIBS += -L$$PWD/../libs/ -lxcb-shm

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxcb-shm.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxcb-shm.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xcb-shm.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xcb-shm.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxcb-shm.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxcb-xfixes
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxcb-xfixes
#else:unix: LIBS += -L$$PWD/../libs/ -lxcb-xfixes

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxcb-xfixes.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxcb-xfixes.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xcb-xfixes.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xcb-xfixes.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxcb-xfixes.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxcb-xkb
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxcb-xkb
#else:unix: LIBS += -L$$PWD/../libs/ -lxcb-xkb

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxcb-xkb.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxcb-xkb.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xcb-xkb.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xcb-xkb.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxcb-xkb.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXcomposite
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXcomposite
#else:unix: LIBS += -L$$PWD/../libs/ -lXcomposite

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXcomposite.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXcomposite.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xcomposite.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xcomposite.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXcomposite.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXcursor
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXcursor
#else:unix: LIBS += -L$$PWD/../libs/ -lXcursor

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXcursor.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXcursor.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xcursor.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xcursor.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXcursor.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXdamage
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXdamage
#else:unix: LIBS += -L$$PWD/../libs/ -lXdamage

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXdamage.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXdamage.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xdamage.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xdamage.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXdamage.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXdmcp
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXdmcp
#else:unix: LIBS += -L$$PWD/../libs/ -lXdmcp

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXdmcp.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXdmcp.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xdmcp.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xdmcp.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXdmcp.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXext
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXext
#else:unix: LIBS += -L$$PWD/../libs/ -lXext

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXext.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXext.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xext.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xext.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXext.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXfixes
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXfixes
#else:unix: LIBS += -L$$PWD/../libs/ -lXfixes

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXfixes.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXfixes.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xfixes.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xfixes.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXfixes.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXft
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXft
#else:unix: LIBS += -L$$PWD/../libs/ -lXft

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXft.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXft.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xft.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xft.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXft.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXi
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXi
#else:unix: LIBS += -L$$PWD/../libs/ -lXi

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXi.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXi.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xi.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xi.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXi.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXinerama
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXinerama
#else:unix: LIBS += -L$$PWD/../libs/ -lXinerama

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXinerama.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXinerama.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xinerama.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xinerama.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXinerama.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxkbcommon
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxkbcommon
#else:unix: LIBS += -L$$PWD/../libs/ -lxkbcommon

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxkbcommon.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxkbcommon.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xkbcommon.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xkbcommon.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxkbcommon.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxkbcommon-x11
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxkbcommon-x11
#else:unix: LIBS += -L$$PWD/../libs/ -lxkbcommon-x11

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxkbcommon-x11.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxkbcommon-x11.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xkbcommon-x11.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xkbcommon-x11.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxkbcommon-x11.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxkbfile
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxkbfile
#else:unix: LIBS += -L$$PWD/../libs/ -lxkbfile

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxkbfile.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxkbfile.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xkbfile.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xkbfile.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxkbfile.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXrandr
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXrandr
#else:unix: LIBS += -L$$PWD/../libs/ -lXrandr

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXrandr.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXrandr.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xrandr.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xrandr.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXrandr.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXrender
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXrender
#else:unix: LIBS += -L$$PWD/../libs/ -lXrender

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXrender.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXrender.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xrender.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xrender.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXrender.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXt
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXt
#else:unix: LIBS += -L$$PWD/../libs/ -lXt

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXt.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXt.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xt.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xt.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXt.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXtst
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXtst
#else:unix: LIBS += -L$$PWD/../libs/ -lXtst

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXtst.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXtst.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xtst.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xtst.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXtst.a



#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lXxf86vm
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lXxf86vm
#else:unix: LIBS += -L$$PWD/../libs/ -lXxf86vm

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libXxf86vm.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libXxf86vm.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/Xxf86vm.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/Xxf86vm.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libXxf86vm.a


#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/release/ -lxcb-sync
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/debug/ -lxcb-sync
#else:unix: LIBS += -L$$PWD/../libs/ -lxcb-sync

#INCLUDEPATH += $$PWD/../libs
#DEPENDPATH += $$PWD/../libs

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/libxcb-sync.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/libxcb-sync.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/release/xcb-sync.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/debug/xcb-sync.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../libs/libxcb-sync.a


















linux-g++
{
LIBS += ../libs/libuiohook.a
LIBS += ../libs/libXtst.a
LIBS += ../libs/libX11.a
LIBS += ../libs/libXt.a
LIBS += ../libs/libxkbcommon.a
LIBS += ../libs/libxkbcommon-x11.a
LIBS += ../libs/libxkbfile.a
LIBS += ../libs/libXinerama.a
LIBS += ../libs/libX11-xcb.a
LIBS += -lX11
LIBS += ../libs/libxcb.a
LIBS += ../libs/libXau.a
LIBS += ../libs/libXdmcp.a
LIBS += -lICE
LIBS += -lSM
LIBS += ../libs/libXext.a
LIBS += -lxcb-xkb
}

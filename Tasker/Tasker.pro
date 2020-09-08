QT += core gui
QT += multimedia
QT += testlib
QT += charts
RESOURCES  = Tasker.qrc
macx{
ICON = taskericon.icns
}


#Add KF5Ntoficiations library for notifications support
unix:!macx: LIBS += -lKF5Notifications

QMAKE_CXXFLAGS += -Wno-deprecated-copy

win32:{

    file_paths += "\"$$PWD/Path/To/Files/ffmpeg.exe\""

    CONFIG(release, debug|release):{
        destination_pathes += $$OUT_PWD/release/
        destination_pathes += ./release
    }
    else:CONFIG(debug, debug|release):{
        destination_pathes += $$OUT_PWD/debug/
    }

    for(file_path,file_paths){
        file_path ~= s,/,\\,g
        for(dest_path,destination_pathes){
            dest_path ~= s,/,\\,g
            QMAKE_POST_LINK += $$quote(xcopy $${file_path} $${dest_path} /I /Y $$escape_expand(\n\t))
         }
    }
}

CONFIG(release, debug|release) {
    #This is a release build
    DEFINES += QT_NO_DEBUG_OUTPUT
} else {
    #This is a non-release(debug) build
    DEFINES+=__TASKER_DEBUG__
}

unix:{
QMAKE_LFLAGS += -no-pie
    # suppress the default RPATH if you wish
#    QMAKE_LFLAGS_RPATH=
    # add your own with quoting gyrations to make sure $ORIGIN gets to the command line unexpanded
#    QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/lib\'"
}

#DO NOT delete the next includepath line! If you do, things WILL break on linux
linux-g++*{
INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5
}

QT += multimedia
QMAKE_CXXFLAGS += "-pthread"
QMAKE_CXXFLAGS += -std=c++14
#CONFIG += static
CONFIG += -std=c++14

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
    AppGuard.cpp \
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
    AppGuard.h \
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
}

RESOURCES += \
    Tasker.qrc

QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

INCLUDEPATH = ..\Tasker

TEMPLATE = app

SOURCES +=  tst_testtimer.cpp \
            Timer.cpp \
            Timer.h

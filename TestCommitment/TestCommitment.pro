QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
INCLUDEPATH += ../Tasker \
               ../TestCommitment

TEMPLATE = app
SOURCES +=  tst_testcommitment.cpp \
            ../Tasker/Task.cpp \
            ../Tasker/Session.cpp

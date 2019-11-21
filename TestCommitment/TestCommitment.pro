QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
INCLUDEPATH += /home/fast-alchemist/Tasker/Tasker \
               /home/fast-alchemist/TestCommitment

TEMPLATE = app
SOURCES +=  tst_testcommitment.cpp \
            /home/fast-alchemist/Tasker/Tasker/Task.cpp \
            /home/fast-alchemist/Tasker/Tasker/session.cpp

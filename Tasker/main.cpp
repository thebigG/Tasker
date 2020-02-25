#include "AudioListener.h"
#include "CommStatsQWidget.h"
#include "CreateCommitmentQWidget.h"
#include "KeyboardListener.h"
#include "StatsUtility.h"
#include "Task.h"
#include "TaskerUIMainWindowQWidget.h"
#include "Timer.h"
#include "UdataUtils.h"
#include "User.h"
#include "livesession.h"
#include "mainui.h"
//#include "objctest.h"
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QStandardPaths>
#include <QThreadPool>
#include <Qt>
#include <QtCore>
#include <TaskerPerf/perftimer.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "iohooklib.h"
#include <QObject>

using std::cout;
using std::endl;

using namespace Engine;
using namespace udata;
using namespace std;
class Stuff : public QObject
{
public:
    QProcess node;
    QStringList arguments;
    int counter;
    Stuff()
    {
        node.setParent(this);
        arguments <<"/home/fast-alchemist/Tasker/Tasker/iohook.js";
        node.start("node", arguments);
        connect(&node, &QProcess::readyReadStandardOutput, this, &Stuff::printSTuff);
        qDebug()<<"before wait call";
        qDebug()<<"After wait call";
        qDebug()<<"After wait call#2";
    }
public slots:
    void printSTuff()
    {
        qDebug()<<"Typed!";
        qDebug(node.readAllStandardOutput().data());
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    startHook();
    qDebug()<<"returned from starthook^^^^^^^^";
    if (UdataUtils::prepFiles() == 0) {
        qDebug("files was allocated successfully");
    } else {
        qDebug("prepFiles failed");
    }
    QObject::connect(&a, &QGuiApplication::lastWindowClosed, &MainUI::saveTaskerStateSlot);
    CommStatsQWidget *widget = nullptr;
    qDebug()<<"Tasker Debug mode";
    std::cout<<"version:"<<__cplusplus;
    widget = MainUI::getInstance();
    qDebug()<<"thread id for UI:"<<QThread::currentThreadId();
    widget->update();
    widget->show();
    new Stuff();
    return a.exec();
}

#include "AudioListener.h"
#include "CommStatsQWidget.h"
#include "CreateCommitmentQWidget.h"
#include "Interval.h"
#include "StatsUtility.h"
#include "Task.h"
#include "TaskerUIMainWindowQWidget.h"
#include "User.h"
#include <KeyboardListener.h>
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QThreadPool>
#include <Qt>
#include <QtCore>
#include <Timer.h>
#include <UdataUtils.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <mainui.h>
#include <stdio.h>
#include <stdlib.h>

using std::cout;
using std::endl;

using namespace Engine;
using namespace udata;
using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    if (UdataUtils::prepFiles() == 0) {
        qDebug() << "files was allocated successfully";
    } else {
        qDebug() << "prepFiles failed";
    }

    TaskerUIMainWindowQWidget *widget = nullptr;

    // qDebug()<<"user name:"<<User::getInstance()->getUsername();

    // Commitment c = User::getInstance()->getCommitments().at(0);
    // c.getName();
    // QVector<Session> sessions = c.getSessions();
    // Task t = sessions.at(0).getTask();
    // qDebug()<<"commitment on disk:"<<c.getName();
    // qDebug()<<"task on commitment:"<<t.getName();
    // qDebug()<<"start date:"<<c.getDateStart();
    // qDebug()<<"end date:"<<c.getDateEnd();

    widget = MainUI::getInstance();
    widget->show();

    /*
    Timer myTimer(Listener::ListenerType::audio);
    myTimer.start();
    qDebug() << "main: << " << QThread::currentThreadId();
    */

    return a.exec();
}

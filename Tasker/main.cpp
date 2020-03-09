#include "AudioListener.h"
#include "CommStatsQWidget.h"
#include "CreateCommitmentQWidget.h"
#include "StatsUtility.h"
#include "Task.h"
#include "TaskerUIMainWindowQWidget.h"
#include "Timer.h"
#include "UdataUtils.h"
#include "User.h"
#include "XListener.h"
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
#include <QMainWindow>
#include <WeeklySnaphott.h>

using std::cout;
using std::endl;

using namespace Engine;
using namespace udata;
using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    qDebug() << "returned from starthook^^^^^^^^";
//    if (UdataUtils::prepFiles() == 0) {
//        qDebug("files was allocated successfully");
//    } else {
//        qDebug("prepFiles failed");
//    }
//    QObject::connect(&a, &QGuiApplication::lastWindowClosed, &MainUI::saveTaskerStateSlot);
//    CommStatsQWidget *widget = nullptr;
//    qDebug() << "Tasker Debug mode";
//    std::cout << "version:" << __cplusplus;
//    widget = MainUI::getInstance();
//    qDebug() << "thread id for UI:" << QThread::currentThreadId();
//    widget->update();
//    widget->show();
    QMainWindow window;
    WeeklySnaphot* chart = new WeeklySnaphot();
    window.setCentralWidget(&chart->view);
    window.resize(420, 300);
    window.show();
    return a.exec();
}

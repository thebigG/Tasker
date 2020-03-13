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
#include <CommitmentSnapshot.h>
#include <QPushButton>
#include <QGridLayout>

using std::cout;
using std::endl;

using namespace Engine;
using namespace udata;
using namespace std;
using namespace QtCharts;
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
    QPushButton* clickMe = new QPushButton("clickMe!");
    window.setLayout(new QGridLayout());
    QVector<CommitmentSnaphot*>* charts = new QVector<CommitmentSnaphot*>(0);
    charts->push_back(new CommitmentSnaphot{7,"Custom"});
    charts->push_back(new CommitmentSnaphot{7,"Sunday"});
    CommitmentSnaphot* chart = new CommitmentSnaphot(7,"Custom");
    clickMe->setVisible(true);
    QObject::connect(clickMe,&QPushButton::clicked, [clickMe, charts]
    {
        qDebug()<<"Hello click!!!"<<charts->length();
//        charts->at(0)->view.setChart(&charts->at(1)->chart);
        charts->at(0)->sets.last()->replace(0,5);

    });
//    window.setCentralWidget(&charts->last()->view);
    window.layout()->addWidget(clickMe);
    window.layout()->addWidget(&charts->at(0)->view);
    window.resize(500, 300);
    window.show();
    return a.exec();
}

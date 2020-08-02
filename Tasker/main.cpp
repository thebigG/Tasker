#include "AudioHook.h"
#include "CommStatsQWidget.h"
#include "CreateCommitmentQWidget.h"
#include "StatsUtility.h"
#include "Task.h"

#include "Timer.h"
#include "UdataUtils.h"
#include "User.h"
#include "XHook.h"
#include "livesession.h"
#include "mainui.h"
#include <CommitmentSnapshot.h>
#include <QStandardPaths>
#include <TaskerPerf/perftimer.h>

#include "AppGuard.h"
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QGridLayout>
#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QStandardPaths>
#include <QThreadPool>
#include <Qt>
#include <QtCore>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

using namespace Engine;
using namespace udata;
using namespace std;
using namespace QtCharts;
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    AppGuard taskerGuard{ TASKER_KEY };

    if (!taskerGuard.tryToRun()) {
        qDebug()
            << "Another instance of Tasker is running! Can only have instance "
               "running at a time because having multiple ones could "
               "compromise the user's data";
        return -1;
    }
    if (UdataUtils::prepFiles() == 0) {
        qDebug("files were loaded successfully");
    } else {
        qDebug("prepFiles failed");
        return -1;
    }

    qDebug() << "path=" << QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    qDebug() << "path2=" << QDir::homePath();
    /**Uncomment to generate "dummy" commits to play with*/
    /*
      UdataUtils::generateCommitment(
          "Generated#1", 8, util::minutesToSeconds(10),
          util::minutesToSeconds(100), util::minutesToSeconds(0),
          util::minutesToSeconds(25), udata::CommitmentType::WEEKLY);
      qDebug() << "Commitment summary:"
               << User::getInstance()->getCommitments().at(0).summary();
     */
    QObject::connect(&a, &QGuiApplication::lastWindowClosed, &MainUI::saveTaskerStateSlot);

    MainUI *widget = nullptr;
    //  qDebug() << "Tasker Debug mode";
    std::cout << "c++ version:" << __cplusplus;
    widget = MainUI::getInstance();
    qDebug() << "thread id for UI:" << QThread::currentThreadId();
    //  qDebug() << "multiplcation=" << 4.5 * 60;
    //  qDebug() << "date plus 7=" << QDate::currentDate().addDays(7);
    widget->show();
    return a.exec();
}

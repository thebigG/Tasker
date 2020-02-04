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

using std::cout;
using std::endl;

using namespace Engine;
using namespace udata;
using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    if (UdataUtils::prepFiles() == 0) {
        qDebug("files was allocated successfully");
    } else {
        qDebug("prepFiles failed");
    }
    QObject::connect(&a, &QGuiApplication::lastWindowClosed, &MainUI::saveTaskerStateSlot);
    CommStatsQWidget *widget = nullptr;
    qDebug("Tasker Debug mode");
    widget = MainUI::getInstance();
    widget->update();
    widget->show();
    return a.exec();
}

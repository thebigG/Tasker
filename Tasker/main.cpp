#include "AudioListener.h"
#include "CommStatsQWidget.h"
#include "CreateCommitmentQWidget.h"
#include "Interval.h"
#include "StatsUtility.h"
#include "Task.h"
#include "TaskerUIMainWindowQWidget.h"
#include "User.h"
#include "UdataUtils.h"
#include "KeyboardListener.h"
#include "Timer.h"
#include "livesession.h"
#include "mainui.h"

#include "objctest.h"

#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QThreadPool>
#include <Qt>
#include <QtCore>
#include <QStandardPaths>

#include <iostream>
#include <cstdio>
#include <cstdlib>

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
    widget = MainUI::getInstance();
    widget->show();


    return a.exec();
}

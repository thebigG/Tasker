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
#include <QThreadPool>
#include <Qt>
#include <Timer.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QObject>
#include <QtCore>
#include <UdataUtils.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <mainui.h>
using std::cout;
using std::endl;
using namespace Engine;
using namespace udata;
using namespace std;
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    if( UdataUtils::prepFiles() == 0)
    {
        qDebug()<<"files was allocated successfully";
    }
    else
    {
        qDebug()<<"prepFiles failed";
    }
    MainUI::getInstance()->show();
    Timer myTimer(Listener::ListenerType::audio);
    myTimer.start();
    qDebug() << "main thread id: << " << QThread::currentThreadId();

    return a.exec();
}

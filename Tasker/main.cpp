#include "AudioHook.h"
#include "CommStatsQWidget.h"
#include "CreateCommitmentQWidget.h"
#include "StatsUtility.h"
#include "Task.h"
#include "TaskerUIMainWindowQWidget.h"
#include "Timer.h"
#include "UdataUtils.h"
#include "User.h"
#include "XHook.h"
#include "livesession.h"
#include "mainui.h"
#include <CommitmentSnapshot.h>
#include <TaskerPerf/perftimer.h>

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
  if (UdataUtils::prepFiles() == 0) {
    qDebug("files were loaded successfully");
  } else {
    qDebug("prepFiles failed");
    return -1;
  }

  //  UdataUtils::generateCommitment(
  //      "Generated#13", 8, util::StatsUtility::minutesToSeconds(10),
  //      util::StatsUtility::minutesToSeconds(100),
  //      util::StatsUtility::minutesToSeconds(0),
  //      util::StatsUtility::minutesToSeconds(25),
  //      udata::CommitmentType::WEEKLY);
  //  qDebug() << "Commitment summary:"
  //           << User::getInstance()->getCommitments().at(0).summary();
  QObject::connect(&a, &QGuiApplication::lastWindowClosed,
                   &MainUI::saveTaskerStateSlot);
  MainUI *widget = nullptr;
  qDebug() << "Tasker Debug mode";
  std::cout << "c++ version:" << __cplusplus;
  widget = MainUI::getInstance();
  qDebug() << "thread id for UI:" << QThread::currentThreadId();
  widget->show();
  return a.exec();
}

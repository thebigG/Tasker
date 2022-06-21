#include "UdataUtils.h"
#include "MainUi.h"

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
    QObject::connect(&a, &QCoreApplication::aboutToQuit, &MainUI::saveTaskerStateSlot);

    MainUI *widget = nullptr;
    widget = MainUI::getInstance();
    widget->show();
    return a.exec();
}

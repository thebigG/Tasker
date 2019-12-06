#include "UdataUtils.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QProcess>
using namespace udata;
UdataUtils::UdataUtils() {
}
void UdataUtils::saveTask() {
    Task newTask{ "Music" };

    QString filename = "newTask.tasker";
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Could not open " << filename;
        return;
    }
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_1);
    out << newTask;
    file.flush();
    file.close();
}
void UdataUtils::loadTask(Task &newTask) {

    QString filename = "newTask.tasker";
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open " << filename;
        return;
    }
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_1);
    in >> newTask;
    file.close();
}

QString UdataUtils::getUsername() {
#ifdef Q_OS_LINUX
    QProcess getUsername;
    QString output;
    getUsername.start("whoami");
    getUsername.waitForFinished();
    output = QString(getUsername.readAllStandardOutput());
    return output.remove(output.length() - 1, 2); // clean up new line character from standard output
#endif
    return "";
}
/**
 * @brief UdataUtils::prepFiles prepares files and directories necessary to
 * store commitment data on disk the very first time the user opens tasker
 * @return 0 on Success. Otherwise -1. Will start defining error codes ASAP.
 */
int UdataUtils::prepFiles() {
    QString userName = getUsername();
    QString const newDir{ QString(HOME_FOLDER_NAME) + QDir::separator() +
                          userName + QDir::separator() + USER_FOLDER_NAME };
    QDir temp = QDir::current();
    QDir taskerFolder{ newDir };
    if (taskerFolder.exists()) {
        return 0;
    }
    if (taskerFolder.mkdir(newDir)) {
    } else {
        return -1;
    }
    QFile newFile{ taskerFolder.absoluteFilePath(userName + TASKER_FILE_EXTENSION) };
    if (!newFile.open(QIODevice::WriteOnly)) {
        return -1;
    }
    return 0;
}

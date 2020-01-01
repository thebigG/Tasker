#include "UdataUtils.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QProcess>

using namespace udata;

QString udata::UdataUtils::userFilePath = "";

/**
 * @brief UdataUtils::UdataUtils
 */
UdataUtils::UdataUtils() {

}

/**
 * @brief UdataUtils::saveUserData
 * @param newUser
 */
void UdataUtils::saveUserData(User &newUser) {

    QFile file(userFilePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Could not open " << userFilePath;
        return;
    }
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_1);
    out << newUser;
    file.flush();
    file.close();
}

/**
 * @brief UdataUtils::loadUserData
 * @param newUser
 */
void UdataUtils::loadUserData(User &newUser) {

    QFile file(UdataUtils::userFilePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open " << userFilePath;
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_1);
    qDebug() << "loading data";
    in >> newUser;
    file.close();
}

/**
 * @brief UdataUtils::getUsername
 * @return
 */
QString UdataUtils::getUsername() {
    if (!userFilePath.isEmpty()) {
        return userFilePath;
    }
qDebug()<<"#2";
#ifdef Q_OS_UNIX
    qDebug()<<"#3";
    QProcess getUsername;
    qDebug()<<"#4";
    QString output;
    qDebug()<<"#5";
    getUsername.start("whoami");
    qDebug()<<"#6";
    getUsername.waitForFinished();
    qDebug()<<"#7";
    output = QString(getUsername.readAllStandardOutput());
    qDebug()<<"#8";
    QString name = output.remove(output.length() - 1, 2);
    qDebug()<<"#9";
    if(name =="root")
    {
        qDebug()<<"#10";
//        qDebug()<<;
        output = QString(getUsername.readAllStandardOutput());
        name = getNotRootUser();
    }
    qDebug()<<"#11";
    return name; // clean up new line character from standard output
#else
    return "";
#endif
}

/**
 * @brief UdataUtils::prepFiles prepares files and directories necessary to
 * store commitment data on disk the very first time the user opens tasker
 * @return 0 on Success. Otherwise -1. Will start defining error codes ASAP.
 */
int UdataUtils::prepFiles() {
    qDebug()<<"#1";
    QString userName = getUsername();
    qDebug()<<"#3";
#if defined(Q_OS_LINUX)
    QString const newDir{ QString(HOME_FOLDER_NAME) + QDir::separator() +
                          userName + QDir::separator() + USER_FOLDER_NAME };
    if(userName == ROOT_USER)
    {
        QDir newTaskerFolder{ newDir };
        if (newTaskerFolder.exists()) {
            userFilePath = newTaskerFolder.absoluteFilePath(userName + TASKER_FILE_EXTENSION);
            loadUserData(*User::getInstance());
            return 0;
        }
        QProcess mkdirProcess{};
        mkdirProcess.start(QString(MKDIR_COMMAND) + newDir);
        mkdirProcess.waitForFinished();
        QFile newFile{ newTaskerFolder.absoluteFilePath(userName + TASKER_FILE_EXTENSION) };
        if (!newFile.open(QIODevice::WriteOnly)) {
            return -1;
        }
        newFile.close();
        newFile.flush();
        User::getInstance()->setUsername(userName);
        userFilePath = newTaskerFolder.absoluteFilePath(userName + TASKER_FILE_EXTENSION);
        saveUserData(*User::getInstance());
        qDebug() << "prepared files at:" << userFilePath;

    }
    else{
#elif defined(Q_OS_OSX)
    QString const newDir(QDir::separator() + QString("Users") + QDir::separator() +
                         userName + QDir::separator() + USER_FOLDER_NAME);
    qDebug() << newDir;
#endif
    QDir temp = QDir::current();
    QDir newTaskerFolder{ newDir };
    if (newTaskerFolder.exists()) {
        userFilePath = newTaskerFolder.absoluteFilePath(userName + TASKER_FILE_EXTENSION);
        loadUserData(*User::getInstance());
        return 0;
    }
    if (newTaskerFolder.mkdir(newDir)) {
    } else {
        qDebug()<<"mkdir failed:"<<newDir;
        return -1;
    }


    QFile newFile{ newTaskerFolder.absoluteFilePath(userName + TASKER_FILE_EXTENSION) };
    if (!newFile.open(QIODevice::WriteOnly)) {
        return -1;
    }
    newFile.close();
    newFile.flush();
    User::getInstance()->setUsername(userName);
    userFilePath = newTaskerFolder.absoluteFilePath(userName + TASKER_FILE_EXTENSION);
    saveUserData(*User::getInstance());
    qDebug() << "prepared files at:" << userFilePath;

    return 0;
}

QString UdataUtils::getNotRootUser()
{
    QDir homeDir{HOME_FOLDER_NAME};
    QString user =  homeDir.entryList().at(2);
    return user;

}

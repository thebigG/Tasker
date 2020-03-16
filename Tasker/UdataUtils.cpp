#include "UdataUtils.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QProcess>
#include "StatsUtility.h"
#include <random>
#include <iostream>
using udata::UdataUtils;

QString udata::UdataUtils::userFilePath = "";

/**
 * @brief UdataUtils::UdataUtils
 */
UdataUtils::UdataUtils() {
}

#ifdef __TASKER_DEBUG__
void UdataUtils::generateCommitment(QString name, int numberOfTimeWindows, int minProductiveTime, int maxProductiveTime,
                                    int minUnproducitveTime, int maxUnproductiveTime)
{
    Commitment newCommitment{};
    newCommitment.setName(name);

    QVector<util::TimeWindow> timeWindows(numberOfTimeWindows);
    QDate today = QDate::currentDate();
    newCommitment.setDateStart(today);

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis;
//    dis = std::uniform_int_distribution<int>(util::StatsUtility(minProductiveTime),util::StatsUtility::toMinutes(maxProductiveTime));
    CommitmentFrequency temptFrequency;
    temptFrequency.timeWindowSize  =7;
    temptFrequency.time = maxProductiveTime;
    dis = std::uniform_int_distribution<int>(1,7);
    temptFrequency.frequency = dis(gen);
    util::TimeWindow newTimeWindow;
    QVector<Session> newSessions;
    QDate sessionDate;
    Session newSession;
    newCommitment.setDateEnd(today.addDays(numberOfTimeWindows*temptFrequency.timeWindowSize));
    newCommitment.setFrequency(temptFrequency.time,temptFrequency.frequency,temptFrequency.timeWindowSize);
    for(int i =0;i<numberOfTimeWindows;i++)
    {
        newTimeWindow.startDate = today;
        sessionDate = today;
        for(int j =0;j<temptFrequency.frequency;j++)
        {
            newSession = Session(Task{}, temptFrequency.time, sessionDate);
            dis = std::uniform_int_distribution<int>(minProductiveTime, maxProductiveTime);
            newSession.setProductiveTime(dis(gen));
            dis = std::uniform_int_distribution<int>(minUnproducitveTime, maxUnproductiveTime);
            newSession.setUnproductiveTime(dis(gen));
            newSessions.append(newSession);
            sessionDate =  sessionDate.addDays(1);


        }
       newTimeWindow.endDate = today.addDays(7);
       newTimeWindow.sessions = newSessions;
       timeWindows.append(newTimeWindow);
       today = newTimeWindow.endDate.addDays(1);
    }
    newCommitment.setCommitmentWindows(timeWindows);
    User::getInstance()->addCommitment(newCommitment);

}
#else
void UdataUtils::generateCommitment(QString name, int numberOfTimeWindows, int minProductiveTime, int maxProductiveTime,
                                          int minUnproducitveTime, int maxUnproductiveTime)
{

}
#endif

/**
 * @brief UdataUtils::saveUserData
 *
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
 *
 * @param newUser
 */
void UdataUtils::loadUserData(User &newUser) {
    QFile file(UdataUtils::userFilePath);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open " << userFilePath;
        return;
    }

    QDataStream in(&file);
    Commitment newCommitment;
    in.setVersion(QDataStream::Qt_5_1);
    qDebug() << "loading data#1";
    in >> newUser;
    qDebug()<<"neUser data:"<<newUser.getCommitments().length();
    if (!newUser.getCommitments().isEmpty()) {
        newCommitment = newUser.getCommitments().at(0);
        qDebug() << "Commitment summary:" << newUser.getCommitments().at(0).summary();
    }
    else
    {
        file.close();
        return;
    }
    qDebug() << "loading data#2";
    file.close();
}

/**
 * @brief UdataUtils::getUsername
 *
 * @return
 */
QString UdataUtils::getUsername() {
    QString name = "";

    if (!userFilePath.isEmpty()) {
        name = userFilePath;
    } else {
        qDebug() << "#2";

#ifdef Q_OS_UNIX
        qDebug() << "#3";
        QProcess getUsername;

        qDebug() << "#4";
        QString output = "";

        qDebug() << "#5";
        getUsername.start("whoami");

        qDebug() << "#6";
        getUsername.waitForFinished();

        qDebug() << "#7";
        output = QString(getUsername.readAllStandardOutput());

        qDebug() << "#8";
        name = output.remove(output.length() - 1, 2);

        qDebug() << "#9";

        if (name == "root") {
            qDebug() << "#10";
            output = QString(getUsername.readAllStandardOutput());
            name = getNotRootUser();
        }
#else
        // no implementation yet
        name = "";
#endif
    }

    qDebug() << "#11";
    return name;
}

/**
 * @brief UdataUtils::prepFiles prepares files and directories necessary to
 * store commitment data on disk the very first time the user opens tasker
 *
 * @return 0 on Success. Otherwise -1. Will start defining error codes ASAP.
 */
int UdataUtils::prepFiles() {
    int status = 0;

    qDebug() << "#1";
    QString userName = getUsername();
    qDebug() << "#3";

#if defined(Q_OS_LINUX)
    const QString newDir{ QString(HOME_FOLDER_NAME) + QDir::separator() +
                          userName + QDir::separator() + USER_FOLDER_NAME };
#elif defined(Q_OS_OSX)
    const QString newDir(QDir::separator() + QString("Users") + QDir::separator() +
                         userName + QDir::separator() + USER_FOLDER_NAME);
#endif
    qDebug() << newDir;

    if (userName == ROOT_USER) {
        QDir newTaskerFolder{ newDir };

        if (newTaskerFolder.exists()) {
            userFilePath = newTaskerFolder.absoluteFilePath(userName + TASKER_FILE_EXTENSION);
            loadUserData(*User::getInstance());

            status = 0;
        } else {
            QProcess mkdirProcess{};

            mkdirProcess.start(QString(MKDIR_COMMAND) + newDir);
            mkdirProcess.waitForFinished();

            QFile newFile{ newTaskerFolder.absoluteFilePath(userName + TASKER_FILE_EXTENSION) };

            if (!newFile.open(QIODevice::WriteOnly)) {
                status = -1;
            } else {
                newFile.close();
                newFile.flush();

                User::getInstance()->setUsername(userName);
                userFilePath = newTaskerFolder.absoluteFilePath(userName + TASKER_FILE_EXTENSION);

                saveUserData(*User::getInstance());

                qDebug() << "prepared files at:" << userFilePath;
            }
        }
    } else {
        QDir temp = QDir::current();
        QDir newTaskerFolder{ newDir };

        if (newTaskerFolder.exists()) {
            userFilePath = newTaskerFolder.absoluteFilePath(userName + TASKER_FILE_EXTENSION);
            qDebug()<<"exists@@@@";
            loadUserData(*User::getInstance());

            status = 0;
        } else {
            if (newTaskerFolder.mkdir(newDir)) {
                QFile newFile{ newTaskerFolder.absoluteFilePath(userName + TASKER_FILE_EXTENSION) };

                if (!newFile.open(QIODevice::WriteOnly)) {
                    status = -1;
                } else {
                    newFile.close();
                    newFile.flush();

                    User::getInstance()->setUsername(userName);
                    userFilePath = newTaskerFolder.absoluteFilePath(userName + TASKER_FILE_EXTENSION);

                    saveUserData(*User::getInstance());
                    qDebug() << "prepared files at:" << userFilePath;

                    status = 0;
                }
            } else {
                qDebug() << "mkdir failed:" << newDir;
                status = -1;
            }
        }
    }

    return status;
}

QString UdataUtils::getNotRootUser() {
    QDir homeDir{ HOME_FOLDER_NAME };
    QString user = homeDir.entryList().at(2);

    return user;
}

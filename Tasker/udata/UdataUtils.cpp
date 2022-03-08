#include "UdataUtils.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QProcess>
#include <QStandardPaths>
#include <iostream>
#include <random>

#include "StatsUtility.h"
using namespace udata;
using udata::UdataUtils;
QString udata::UdataUtils::userFilePath = "";

/**
 * @brief UdataUtils::UdataUtils
 */
UdataUtils::UdataUtils() {}

void UdataUtils::generateCommitment(QString name, int numberOfTimeWindows,
                                    int minProductiveTime,
                                    int maxProductiveTime,
                                    int minUnproducitveTime,
                                    int maxUnproductiveTime,
                                    CommitmentType type) {
#ifdef __TASKER_DEBUG__
  Commitment newCommitment{};
  newCommitment.setName(name);

  QVector<TimeWindow> timeWindows{};
  QDate today = QDate::currentDate();
  newCommitment.setDateStart(today);
  newCommitment.setType(type);
  std::random_device
      rd; // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis;

  CommitmentFrequency temptFrequency;
  temptFrequency.timeWindowSize = 7;
  temptFrequency.goal = maxProductiveTime;
  dis = std::uniform_int_distribution<int>(1, 7);
  temptFrequency.frequency = dis(gen);
  TimeWindow newTimeWindow;
  QVector<Session> newSessions;
  QDate sessionDate;
  std::vector<QDate> sessionDates{};
  Session newSession;
  newCommitment.setDateEnd(
      today.addDays(numberOfTimeWindows * temptFrequency.timeWindowSize));
  newCommitment.setFrequency(temptFrequency.goal, temptFrequency.frequency,
                             temptFrequency.timeWindowSize);
  int tempDaysCount = 0;
  for (int i = 0; i < numberOfTimeWindows; i++) {
    newTimeWindow = TimeWindow{};
    newTimeWindow.startDate = today;
    sessionDate = today;
    for (int j = 0; j < temptFrequency.frequency; j++) {
      newSession = Session(Task{}, temptFrequency.goal, sessionDate);
      sessionDates.push_back(newSession.getDate());
      dis = std::uniform_int_distribution<int>(minProductiveTime,
                                               maxProductiveTime);
      int temp = dis(gen);
      newSession.setProductiveTime(temp);
      dis = std::uniform_int_distribution<int>(minUnproducitveTime,
                                               maxUnproductiveTime);
      newSession.setUnproductiveTime(dis(gen));
      newSessions.append(newSession);
      dis = std::uniform_int_distribution<int>(1, 6);
      tempDaysCount = dis(gen);
      // Keep generating a new count if it bleeds into the next time
      // window(week)
      while (today.addDays(tempDaysCount) > today.addDays(6) ||
             std::find(std::begin(sessionDates), std::end(sessionDates),
                       today.addDays(tempDaysCount)) !=
                 std::end(sessionDates)) {
        tempDaysCount = dis(gen);
      }
      sessionDate = today.addDays(tempDaysCount);
    }
    newTimeWindow.endDate = today.addDays(6);
    newTimeWindow.sessions = newSessions;
    newSessions.clear();
    timeWindows.append(newTimeWindow);
    today = newTimeWindow.endDate.addDays(1);
  }
  newCommitment.setCommitmentWindows(timeWindows);
  User::getInstance()->addCommitment(newCommitment);
#endif
}

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
  in >> newUser;
  if (!newUser.getCommitments().isEmpty()) {
    newCommitment = newUser.getCommitments().at(0);
  } else {
    file.close();
    return;
  }
  file.close();
}

/**
 * @brief UdataUtils::getUsername
 *
 * @return
 */
QString UdataUtils::getUsername() {
  QString name = "";

#ifdef Q_OS_UNIX

  QProcess getUsername;

  QString output = "";

  QString command{"whoami"};
  QStringList args{};

  getUsername.start(command, args);

  //FIXME: Implement errorOccurred signal
  getUsername.waitForFinished();

  output = QString(getUsername.readAllStandardOutput());

  name =  output.remove(output.length() - 1, 2);

#else
  // no implementation yet
  // Implement Windows code here
  name = "";
#endif
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
  QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

  QString userName = getUsername();

  QDir taskerFolder{QDir::homePath()};
  userFilePath = taskerFolder.absolutePath() + QDir::separator() +
                 USER_FOLDER_NAME + QDir::separator() + userName +
                 TASKER_FILE_EXTENSION;
  if (taskerFolder.mkdir(USER_FOLDER_NAME)) {
    QFile newFile{taskerFolder.absolutePath() + QDir::separator() +
                  USER_FOLDER_NAME + QDir::separator() + userName +
                  TASKER_FILE_EXTENSION};

    if (!newFile.open(QIODevice::WriteOnly)) {

      status = -1;
    } else {
      newFile.close();
      newFile.flush();
      User::getInstance()->setUsername(userName);

      saveUserData(*User::getInstance());

      status = 0;
    }
  } else {
    loadUserData(*User::getInstance());

    status = 0;
  }

  return status;
}

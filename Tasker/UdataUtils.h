#ifndef UDATAUTILS_H
#define UDATAUTILS_H

#include <QtGlobal>
#include <Task.h>
#include <User.h>
#ifdef __TASKER_DEBUG__
#define USER_FOLDER_NAME ".DebugTasker"
#else
#define USER_FOLDER_NAME ".Tasker"
#endif
#define TASKER_FILE_EXTENSION ".tasker"

namespace udata {
class UdataUtils;
}

/**
 * @brief The udata::UdataUtils class
 */
class udata::UdataUtils {
private:
  UdataUtils();
  static bool firstTimer();

public:
  static void generateCommitment(QString name, int numberOfTimeWindows,
                                 int minProductiveTime, int maxProductiveTime,
                                 int minUnproducitveTime,
                                 int maxUnproductiveTime, CommitmentType type);
  static void saveUserData(User &);
  static void loadUserData(User &);
  static int prepFiles();
  static QString getUsername();
  static QString taskerFolder;
  static QString userFilePath;
};
#endif

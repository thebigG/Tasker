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

public:
  /**
   * @brief generateCommitment generates a fake commitment. This makes testing
   * things out with dummy data really easy :)
   * @param name
   * @param numberOfTimeWindows
   * @param minProductiveTime
   * @param maxProductiveTime
   * @param minUnproducitveTime
   * @param maxUnproductiveTime
   * @param type
   */
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

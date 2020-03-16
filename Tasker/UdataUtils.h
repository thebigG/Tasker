#ifndef UDATAUTILS_H
#define UDATAUTILS_H

#include <QtGlobal>
#include <Task.h>
#include <User.h>

#ifdef Q_OS_UNIX
#define USERDATA_DIR "."
#define HOME_FOLDER_NAME "/home"
#define USER_FOLDER_NAME ".TaskerData"
#define TASKER_FILE_EXTENSION ".tasker"
#define MKDIR_COMMAND "mkdir "
#define ROOT_USER "root"
#endif

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
    static void generateCommitment(QString name, int numberOfTimeWindows, int minProductiveTime, int maxProductiveTime,
                                   int minUnproducitveTime, int maxUnproductiveTime);
    static void saveUserData(User &);
    static void loadUserData(User &);
    static int prepFiles();
    static QString getUsername();
    static QString taskerFolder;
    static QString userFilePath;
    static QString getNotRootUser();
};
#endif

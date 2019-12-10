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
#endif

namespace udata {
class UdataUtils;
// static const QString USERDATA_FILEPATH = "";
} // namespace udata

class udata::UdataUtils {
private:
    UdataUtils();
    static bool firstTimer();
public:
    static void saveUserData(User&);
    static void loadUserData(User&);
    static int prepFiles();
    static QString getUsername();
    static QString userFilePath;

};
#endif

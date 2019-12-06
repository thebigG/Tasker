#ifndef UDATAUTILS_H
#define UDATAUTILS_H
#include <QtGlobal>
#include <Task.h>
#ifdef Q_OS_LINUX
#define USERDATA_DIR "."
#define HOME_FOLDER_NAME "/home"
#define USER_FOLDER_NAME ".TaskerData"
#define TASKER_FILE_EXTENSION ".tasker"
#endif
namespace udata {
class UdataUtils;
}

class udata::UdataUtils {
private:
    static bool firstTimer();
    static QString getUsername();

public:
    UdataUtils();
    static void saveTask();
    static void loadTask(Task &);
    static int prepFiles();
};

#endif // UDATAUTILS_H

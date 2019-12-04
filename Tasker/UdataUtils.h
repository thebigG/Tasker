#ifndef UDATAUTILS_H
#define UDATAUTILS_H
#include <QtGlobal>
#include <Task.h>
#ifdef Q_OS_LINUX
#define USERDATA_DIR "."
#define HOME_FOLDER_NAME "~"
#define USER_FOLDER_NAME ".Tasker"
#endif
namespace udata {
class UdataUtils;
}

class udata::UdataUtils {
private:
    static bool firstTimer();
public:
    UdataUtils();
    static void saveTask();
    static void loadTask(Task&);
    static int prepFiles();
};

#endif // UDATAUTILS_H

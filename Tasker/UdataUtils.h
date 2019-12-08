#ifndef UDATAUTILS_H
#define UDATAUTILS_H
#include <QtGlobal>
#include <Task.h>
#endif // UDATAUTILS_H
#ifdef Q_OS_LINUX
#define USERDATA_DIR "."
#define HOME_FOLDER_NAME "~"
#define USER_FOLDER_NAME ".Tasker"
#endif
namespace udata {
class UdataUtils;
// static const QString USERDATA_FILEPATH = "";
} // namespace udata

class udata::UdataUtils {
public:
    UdataUtils();
    static void saveTask();
    static void loadTask(Task &);
    static void firstTimer();
};

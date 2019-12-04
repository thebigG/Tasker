#ifndef UDATAUTILS_H
#define UDATAUTILS_H
#include <Task.h>
 #include <QtGlobal>
#endif // UDATAUTILS_H
#ifdef Q_OS_LINUX
#define USERDATA_DIR "."
#endif
namespace udata {
class UdataUtils;
//static const QString USERDATA_FILEPATH = "";
}

class udata::UdataUtils
{
public:
    UdataUtils();
    static void saveTask();
    static void loadTask(Task&);
    static void firstTimer();


};


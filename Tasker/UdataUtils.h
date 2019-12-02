#ifndef UDATAUTILS_H
#define UDATAUTILS_H
#include <Task.h>

namespace udata {
class UdataUtils;
}

class udata::UdataUtils
{
public:
    UdataUtils();
    static void saveTask();
    static void loadTask(Task&);

};

#endif // UDATAUTILS_H

#include "taskermainui.h"
#include "commstats.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CommStats c;
    c.show();
    return a.exec();
}

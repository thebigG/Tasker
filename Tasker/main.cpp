#include "taskermainui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TaskerMainUI w;
    w.show();
    return a.exec();
}

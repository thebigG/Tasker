#include "taskermainui.h"
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TaskerMainUI b;
    b.show();
    return a.exec();
}

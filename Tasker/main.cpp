#include "Widget_CommStats.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget_CommStats c;
    c.show();

    return a.exec();
}

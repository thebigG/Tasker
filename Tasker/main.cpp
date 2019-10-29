#include <QApplication>

#include "taskeruimainwindow.h"
#include "Widget_CommStats.h"
#include "createcommitment.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TaskerUIMainWindow mw;
    createcommitment cc;
    Widget_CommStats cs;

    cs.show();
    cc.show();

    mw.show();

    return a.exec();
}

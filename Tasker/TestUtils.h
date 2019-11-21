#ifndef TESTUTILS_H
#define TESTUTILS_H
#include <QString>
#include <QtTest/QtTest>
namespace testUtils
{
QString getNameFromIn();
QVector<QString> getNameListFromIn();
}
//class TestCommitment : public QObject
//{
//    Q_OBJECT
//private slots:
////    void newSession();
////    void newTask();
//};
//}

#endif // TESTUTILS_H

#include <QtTest/QtTest>
#include "Task.h"
#include "Session.h"
// add necessary includes here

class TestCommitment : public QObject
{
    Q_OBJECT

private slots:
    void testTask();
    void testSession();
};


void TestCommitment::testTask()
{
    QVector<QString> listenerlist{"keyboard", "Mic"};
    auto myTask = new Task{"write", listenerlist};
    QVERIFY(myTask->getName() == "write");
    QVERIFY(myTask->getListeners().size() == 2);
    QVERIFY(myTask->getListeners().at(0) == "keyboard");
    QVERIFY(myTask->getListeners().at(1) == "Mic");
    delete myTask;
}
void TestCommitment::testSession()
{
//    QVector<QString> listenerlist{"keyboard", "Mic"};
//    Task myTask{"write", listenerlist};
//    auto mySession = new Session{myTask, 3000};
//    QVERIFY(myTask.getName() == "write");
//    QVERIFY(myTask.getListeners().size() == 2);
//    QVERIFY(myTask.getListeners().at(0) == "keyboard");
//    QVERIFY(myTask.getListeners().at(1) == "Mic");
//    QVERIFY(mySession->getTask().getName() == "write");
////    myTask.setName("music");
//    mySession->getTask().setName("music");
//    QVERIFY(mySession->getTask().getName() == "write");
//    delete mySession;

}
QTEST_MAIN(TestCommitment)

#include "tst_testcommitment.moc"

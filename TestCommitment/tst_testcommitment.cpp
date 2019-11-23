#include <QtTest/QtTest>
#include <QDebug>
#include "Task.h"
#include "Session.h"
#include <Commitment.h>
#include <StatsUtility.h>
// add necessary includes here

class TestCommitment : public QObject
{
    Q_OBJECT

private slots:
    void testTaskCorrectness();
    void testSessionCorrectness();
    void testCommitmentCorrectness();
    void testSessionNegativeGoal();
    void testCommitmentInvalidStartDate();
    void testCommitmentInvalidEndDate();
    void testSessionPostiveGoal();
};
/**
  TID:T01
  This function checks for the correcteness of an instance of task.
  It instiates a Task and tests that all of its members' data
  match with the data that was passed.
 */
void TestCommitment::testTaskCorrectness()
{
    QVector<QString> listenerlist{"keyboard", "Mic"};
    Task myTask{"write", listenerlist};
    QVERIFY(myTask.getName() == "write");
    QVERIFY(myTask.getListeners().size() == 2);
    QVERIFY(myTask.getListeners().at(0) == "keyboard");
    QVERIFY(myTask.getListeners().at(1) == "Mic");
    myTask.setName("code");
    QVERIFY(myTask.getName() != "write");
}
/**
  TID:T02
  This function checks for the correcteness of an instance of Session.
  It instiates a Session and tests that all of its members' data
  match with the data that was passed.
 */
void TestCommitment::testSessionCorrectness()
{
    QVector<QString> listenerlist{"keyboard", "Mic"};
    Task myTask{"write", listenerlist};
    auto sessionGoal = 3000;
    Session mySession{myTask, sessionGoal};
    QVERIFY(myTask.getName() == "write");
    QVERIFY(myTask.getListeners().size() == 2);
    QVERIFY(myTask.getListeners().at(0) == "keyboard");
    QVERIFY(myTask.getListeners().at(1) == "Mic");
    QVERIFY(mySession.getTask().getName() == myTask.getName());
    QVERIFY(mySession.getLength() == sessionGoal);
    QString newStr{"music"};
    mySession.getTask().setName(newStr);
    QVERIFY(mySession.getTask().getName() != "write");
}
/**
  TID:03
 */
void TestCommitment::testSessionNegativeGoal()
{
    QVector<QString> listenerlist{"keyboard", "Mic"};
    Task myTask{"write", listenerlist};
    auto sessionGoal = -3000;
    Session mySession{myTask, sessionGoal};
    QVERIFY(mySession.getLength() == ZERO);
}
/**
    TID:04
 */
void TestCommitment::testSessionPostiveGoal()
{
    QVector<QString> listenerlist{"keyboard", "Mic"};
    Task myTask{"write", listenerlist};
    auto sessionGoal = 3000;
    Session mySession{myTask, sessionGoal};
    QVERIFY(mySession.getLength() == sessionGoal);
}
/**
  TID:T05
  This function tests the correctness of a commitment
  It instiates a Commitment and tests that all of its members' data
  match with the data that was passed.
 */
void TestCommitment::testCommitmentCorrectness()
{
    QVector<QString> listenerlist{"keyboard", "Mic"};
    Task myTask{"write", listenerlist};
    QVERIFY(myTask.getName() == "write");
    QVERIFY(myTask.getListeners().size() == 2);
    QVERIFY(myTask.getListeners().at(0) == "keyboard");
    QVERIFY(myTask.getListeners().at(1) == "Mic");
    Session mySession{myTask, 3000};
    myTask.setName("code");
    QVERIFY(myTask.getName() != "write");
    QString newStr{"music"};
    mySession.getTask().setName(newStr);
    mySession.getTask().setName(newStr);
    Task myTask2{"sing", listenerlist};
    QVERIFY(myTask2.getName() == "sing");
    QVERIFY(myTask2.getListeners().size() == 2);
    QVERIFY(myTask2.getListeners().at(0) == "keyboard");
    QVERIFY(myTask2.getListeners().at(1) == "Mic");
    Session mySession2{myTask2, 6700 };
    QVERIFY(mySession2.getTask().getName() != "write");
    QDate start{QDate::currentDate()};
    QDate end{QDate::currentDate()};
    end = end.addDays(12);
    end = end.addMonths(3);
    QVector<Session> sessions;
    QString commitmentName = "Build Pacman" ;
    Commitment myCommitment{commitmentName ,start, end, sessions};
    QVERIFY( myCommitment.getDateStart() == start);
    QVERIFY( myCommitment.getDateStart() != end);
    QVERIFY(myCommitment.getDateEnd() == end);
    QVERIFY(myCommitment.getName() == commitmentName);

}
/**
    TID:T06
 * @brief This function attempts to test Commitment with an invalid start date.
 */
void TestCommitment::testCommitmentInvalidStartDate()
{
    QVector<QString> listenerlist{"keyboard", "Mic"};
    Task myTask{"write", listenerlist};
    QVERIFY(myTask.getName() == "write");
    QVERIFY(myTask.getListeners().size() == 2);
    QVERIFY(myTask.getListeners().at(0) == "keyboard");
    QVERIFY(myTask.getListeners().at(1) == "Mic");
    Session mySession{myTask, 3000};
    myTask.setName("code");
    QVERIFY(myTask.getName() != "write");
    QString newStr{"music"};
    mySession.getTask().setName(newStr);
    mySession.getTask().setName(newStr);
    Task myTask2{"sing", listenerlist};
    QVERIFY(myTask2.getName() == "sing");
    QVERIFY(myTask2.getListeners().size() == 2);
    QVERIFY(myTask2.getListeners().at(0) == "keyboard");
    QVERIFY(myTask2.getListeners().at(1) == "Mic");
    Session mySession2{myTask2, 6700 };
    QVERIFY(mySession2.getTask().getName() != "write");
    QDate start{2019,9, 12};
    QDate end;
    QVector<Session> sessions;
    QString commitmentName = "Build Pacman";
    Commitment myCommitment{commitmentName ,start, end, sessions};
    QVERIFY(myCommitment.getDateStart() == QDate::currentDate());
}
/**
 * TID:07
 * @brief This function attempts to test Commitment with an invalid end date.
 */
void TestCommitment::testCommitmentInvalidEndDate()
{
    QVector<QString> listenerlist{"keyboard", "Mic"};
    Task myTask{"write", listenerlist};
    QVERIFY(myTask.getName() == "write");
    QVERIFY(myTask.getListeners().size() == 2);
    QVERIFY(myTask.getListeners().at(0) == "keyboard");
    QVERIFY(myTask.getListeners().at(1) == "Mic");
    Session mySession{myTask, 3000};
    myTask.setName("code");
    QVERIFY(myTask.getName() != "write");
    QString newStr{"music"};
    mySession.getTask().setName(newStr);
    mySession.getTask().setName(newStr);
    Task myTask2{"sing", listenerlist};
    QVERIFY(myTask2.getName() == "sing");
    QVERIFY(myTask2.getListeners().size() == 2);
    QVERIFY(myTask2.getListeners().at(0) == "keyboard");
    QVERIFY(myTask2.getListeners().at(1) == "Mic");
    Session mySession2{myTask2, 6700 };
    QVERIFY(mySession2.getTask().getName() != "write");
    QDate start{QDate::currentDate()};
    QDate end{0,0,0};
    end = end.addDays(12);
    end = end.addMonths(3);
    QVector<Session> sessions;
    QString commitmentName = "Build Pacman";
    Commitment myCommitment{commitmentName ,start, end, sessions};
    QVERIFY(myCommitment.getDateStart() == QDate::currentDate());
    QVERIFY(myCommitment.getDateEnd() == QDate::currentDate());
}
QTEST_MAIN(TestCommitment)

#include "tst_testcommitment.moc"

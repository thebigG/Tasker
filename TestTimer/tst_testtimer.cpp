#include <QtTest>
#include "Timer.cpp"
#include <QThread>

// add necessary includes here

class TestTimer : public QObject
{
    Q_OBJECT

public:

private slots:
    //void test_case1();
     void testRealTime();
     void testProductiveTime_NoListener();
     void testUnproductiveTime_NoListener();
     void testSetRealTimeBoundaryInvalid();
     void testSetRealTimeBoundaryValid();
     void testSetProductiveTimeBoundaryValid();
     void testSetProductiveTimeBoundaryInvalid();
     void testProductiveTimeLeft_NoListener();
     void testRealTimeLeft_NoListener();
};




//T22  - on no listener, real time to 15 min, start, wait 10, check getRealTimeLeft() is 5 min
void TestTimer::testRealTimeLeft_NoListener() {
    Engine::Timer *tar = new Engine::Timer();
    QTime *goodTime = new QTime(0,15,0,0); //15 min
    tar->setRealTime(goodTime);
    tar->start();
    QThread::sleep(600); //10 min
    QTime x = tar->getRealTimeLeft();
    QVERIFY((x.minute() == 4 && x.second() >= 59) || (x.minute() == 5 &&  x.second() <= 1)); //slight leaway
}

//T23  - on no listener, set productive and real time to 15 min, start, wait 10, check getProductiveTimeLeft() is 5 min
void TestTimer::testProductiveTimeLeft_NoListener() {
    Engine::Timer *tar = new Engine::Timer();
    QTime *goodTime = new QTime(0,15,0,0); //15 min
    tar->setRealTime(goodTime);
    tar->setProductiveTime(goodTime);
    tar->start();
    QThread::sleep(600); //10 min
    QTime x = tar->getProductiveTimeLeft();
    QVERIFY((x.minute() == 4 && x.second() >= 59) || (x.minute() == 5 &&  x.second() <= 1)); //slight leaway
}

//T24; boundry test on setProductiveTime, valid case
void TestTimer::testSetProductiveTimeBoundaryValid(){
    Engine::Timer *tar = new Engine::Timer();
    QTime *goodTime = new QTime(1,0,0,0); //1 hour
    tar->setProductiveTime(goodTime);
    QTime x = tar->getProductiveTimeLeft();
    QVERIFY(x.hour() == 1 && x.minute() == 0 && x.second() == 0 && x.msec() == 0);
}

//T25; boundry test on setProductiveTime, invalid case
void TestTimer::testSetProductiveTimeBoundaryInvalid(){
    Engine::Timer *tar = new Engine::Timer();
    QTime *badTime = new QTime(-1,0,0,0); //"-1" hours
    tar->setProductiveTime(badTime);
    QTime x = tar->getProductiveTimeLeft();
    QVERIFY(x.hour() == 0 && x.minute() == 0 && x.second() == 0 && x.msec() == 0);
}

//T26; boundry test on setRealTime, valid case
void TestTimer::testSetRealTimeBoundaryValid(){
    Engine::Timer *tar = new Engine::Timer();
    QTime *goodTime = new QTime(1,0,0,0); //1 hour
    tar->setRealTime(goodTime);
    QTime x = tar->getRealTime();
    QVERIFY(x.hour() == 1 && x.minute() == 0 && x.second() == 0 && x.msec() == 0);
}

//T27; boundry test on setRealTime, invalid case
void TestTimer::testSetRealTimeBoundaryInvalid(){
    Engine::Timer *tar = new Engine::Timer();
    QTime *badTime = new QTime(-1,0,0,0); //"-1" hours
    tar->setRealTime(badTime);
    QTime x = tar->getRealTime();
    QVERIFY(x.hour() == 0 && x.minute() == 0 && x.second() == 0 && x.msec() == 0);
}

//T28
void TestTimer::testUnproductiveTime_NoListener() {
    Engine::Timer *tar = new Engine::Timer();
    QTime *goodTime = new QTime(0,20,0,0); //20 min
    tar->setRealTime(goodTime);
    tar->start();
    QThread::sleep(600); //10 min
    QTime x = tar->getUnproductiveTime();
    QVERIFY(x.minute() == 0 && x.second() == 0);
}


//T29  - on no listener, set real time to 15 min, start, wait 10, check getProductiveTime() is 10 min
void TestTimer::testProductiveTime_NoListener() {
    Engine::Timer *tar = new Engine::Timer();
    QTime *goodTime = new QTime(0,15,0,0); //15 min
    tar->setRealTime(goodTime);
    tar->start();
    QThread::sleep(600); //10 min
    QTime x = tar->getProductiveTime();
    QVERIFY((x.minute() == 9 && x.second() >= 59) ||(x.minute() == 10 &&  x.second() <= 1)); //slight leaway
}


//T30 - on no listener, set real time to 20 min, start, wait 10, check there's 10 left
void TestTimer::testRealTime() {
    Engine::Timer *tar = new Engine::Timer();
    QTime *goodTime = new QTime(0,20,0,0); //20 min
    tar->setRealTime(goodTime);
    tar->start();
    QThread::sleep(600); //10 min
    QTime x = tar->getRealTime();
    QVERIFY((x.minute() == 9 && x.second() >= 59) ||(x.minute() == 10 &&  x.second() <= 1)); //slight leaway
}

QTEST_APPLESS_MAIN(TestTimer)

#include "tst_testtimer.moc"

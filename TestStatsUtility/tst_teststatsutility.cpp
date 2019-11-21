#include <QtTest>

#include "StatsUtility.h"

class TestStatsUtility : public QObject
{
    Q_OBJECT

public:
    TestStatsUtility();
    ~TestStatsUtility();

private slots:
    void test_case1();
    // void testToMinutes();
    // void testToHours();
    // void testToDays();
    // void testToWeeks();
    // void testToMonths();
    // void calculateProductivePercentage();

};

TestStatsUtility::TestStatsUtility()
{

}

TestStatsUtility::~TestStatsUtility()
{

}

void TestStatsUtility::test_case1()
{

}

QTEST_APPLESS_MAIN(TestStatsUtility)

#include "tst_teststatsutility.moc"

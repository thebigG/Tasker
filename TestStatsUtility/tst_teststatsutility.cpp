#include <QtTest>

#include "StatsUtility.h"

class TestStatsUtility : public QObject {
    Q_OBJECT

    private slots:
    void testToMinutesPositive();
    void testToMinutesNegative();

    void testToHoursPositive();
    void testToHoursNegative();

    void testToDaysPositive();
    void testToDaysNegative();

    void testToWeeksPositive();
    void testToWeeksNegative();

    void testToMonthsPositive();
    void testToMonthsNegative();

    void calculateProductivePercentageAllNegative();
    void calculateProductivePercentageNegativeSecondsPositiveProductive();
    void calculateProductivePercentagePositiveSecondsNegativeProductive();
    void calculateProductivePercentageAllPositive();
};


using util::StatsUtility;

/**
 * @brief TestStatsUtility::testToMinutesPositive
 * TID:T09
 */
void TestStatsUtility::testToMinutesPositive() {
    int64_t value = 240;

    QVERIFY(StatsUtility::toMinutes(value) > -1);
}

/**
 * @brief TestStatsUtility::testToMinutesNegative
 * TID:T10
 */
void TestStatsUtility::testToMinutesNegative() {
    int64_t value = -99;

    QVERIFY(StatsUtility::toMinutes(value) == -1);
}

/**
 * @brief TestStatsUtility::testToHoursPositive
 * TID:T11
 */
void TestStatsUtility::testToHoursPositive() {
    int64_t value = 240;

    QVERIFY(StatsUtility::toHours(value) > -1);
}

/**
 *TID:T12
 * @brief TestStatsUtility::testToHoursNegative
 */
void TestStatsUtility::testToHoursNegative() {
    int64_t value = -99;

    QVERIFY(StatsUtility::toHours(value) == -1);
}

/**
 * @brief TestStatsUtility::testToDaysPositive
 * TID:T13
 */
void TestStatsUtility::testToDaysPositive() {
    int64_t value = 240;

    QVERIFY(StatsUtility::toDays(value) > -1);
}

/**
 *TID:T14
 * @brief TestStatsUtility::testToDaysNegative
 */
void TestStatsUtility::testToDaysNegative() {
    int64_t value = -99;

    QVERIFY(StatsUtility::toDays(value) == -1);
}

/**
 * @brief TestStatsUtility::testToWeeksPositive
 * *TID:T15
 */
void TestStatsUtility::testToWeeksPositive() {
    int64_t value = 240;

    QVERIFY(StatsUtility::toWeeks(value) > -1);
}

/**
 * @brief TestStatsUtility::testToWeeksNegative
 *TID:T16
 */
void TestStatsUtility::testToWeeksNegative() {
    int64_t value = -99;

    QVERIFY(StatsUtility::toWeeks(value) == -1);
}

/**
 * @brief TestStatsUtility::testToMonthsPositive
 *TID:T17
 */
void TestStatsUtility::testToMonthsPositive() {
    int64_t value = 240;

    QVERIFY(StatsUtility::toMonths(value) > -1);
}

/**
 * @brief TestStatsUtility::testToMonthsNegative
 * TID:T18
 */
void TestStatsUtility::testToMonthsNegative() {
    int64_t value = -99;

    QVERIFY(StatsUtility::toMonths(value) == -1);
}

/**
 * @brief TestStatsUtility::calculateProductivePercentageAllNegative
 * TID:T19
 */
void TestStatsUtility::calculateProductivePercentageAllNegative() {
    int64_t valueSeconds = -99;
    int64_t valueProductive = -66;

    QVERIFY(StatsUtility::calculateProductivePercentage(valueSeconds, valueProductive) == -1.0);
}

/**
 * @brief TestStatsUtility::calculateProductivePercentageNegativeSecondsPositiveProductive
 * TID:T20
 */
void TestStatsUtility::calculateProductivePercentageNegativeSecondsPositiveProductive() {
    int64_t valueSeconds = -99;
    int64_t valueProductive = 66;

    QVERIFY(StatsUtility::calculateProductivePercentage(valueSeconds, valueProductive) == -1.0);
}

/**
 * @brief TestStatsUtility::calculateProductivePercentagePositiveSecondsNegativeProductive
 * TID:T21
 */
void TestStatsUtility::calculateProductivePercentagePositiveSecondsNegativeProductive() {
    int64_t valueSeconds = 99;
    int64_t valueProductive = -66;

    QVERIFY(StatsUtility::calculateProductivePercentage(valueSeconds, valueProductive) == -1.0);
}

/**
 * @brief TestStatsUtility::calculateProductivePercentageAllPositive
 * TID:T22
 */
void TestStatsUtility::calculateProductivePercentageAllPositive() {
    int64_t valueSeconds = 99;
    int64_t valueProductive = 66;

    QVERIFY(StatsUtility::calculateProductivePercentage(valueSeconds, valueProductive) > -1.0);
}

QTEST_MAIN(TestStatsUtility)

#include "tst_teststatsutility.moc"

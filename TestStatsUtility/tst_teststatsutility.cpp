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

QTEST_MAIN(TestStatsUtility)

#include "tst_teststatsutility.moc"

using util::StatsUtility;

/**
 * @brief TestStatsUtility::testToMinutesPositive
 *
 */
void TestStatsUtility::testToMinutesPositive() {
    int64_t value = 240;

    QVERIFY(StatsUtility::toMinutes(value) > -1);
}

/**
 * @brief TestStatsUtility::testToMinutesNegative
 */
void TestStatsUtility::testToMinutesNegative() {
    int64_t value = -99;

    QVERIFY(StatsUtility::toMinutes(value) == -1);
}

/**
 * @brief TestStatsUtility::testToHoursPositive
 */
void TestStatsUtility::testToHoursPositive() {
    int64_t value = 240;

    QVERIFY(StatsUtility::toHours(value) > -1);
}

/**
 * @brief TestStatsUtility::testToHoursNegative
 */
void TestStatsUtility::testToHoursNegative() {
    int64_t value = -99;

    QVERIFY(StatsUtility::toHours(value) == -1);
}

/**
 * @brief TestStatsUtility::testToDaysPositive
 */
void TestStatsUtility::testToDaysPositive() {
    int64_t value = 240;

    QVERIFY(StatsUtility::toDays(value) > -1);
}

/**
 * @brief TestStatsUtility::testToDaysNegative
 */
void TestStatsUtility::testToDaysNegative() {
    int64_t value = -99;

    QVERIFY(StatsUtility::toDays(value) == -1);
}

/**
 * @brief TestStatsUtility::testToWeeksPositive
 */
void TestStatsUtility::testToWeeksPositive() {
    int64_t value = 240;

    QVERIFY(StatsUtility::toWeeks(value) > -1);
}

/**
 * @brief TestStatsUtility::testToWeeksNegative
 */
void TestStatsUtility::testToWeeksNegative() {
    int64_t value = -99;

    QVERIFY(StatsUtility::toWeeks(value) == -1);
}

/**
 * @brief TestStatsUtility::testToMonthsPositive
 */
void TestStatsUtility::testToMonthsPositive() {
    int64_t value = 240;

    QVERIFY(StatsUtility::toMonths(value) > -1);
}

/**
 * @brief TestStatsUtility::testToMonthsNegative
 */
void TestStatsUtility::testToMonthsNegative() {
    int64_t value = -99;

    QVERIFY(StatsUtility::toMonths(value) == -1);
}

/**
 * @brief TestStatsUtility::calculateProductivePercentageAllNegative
 */
void TestStatsUtility::calculateProductivePercentageAllNegative() {
    int64_t valueSeconds = -99;
    int64_t valueProductive = -66;

    QVERIFY(StatsUtility::calculateProductivePercentage(valueSeconds, valueProductive) == -1.0);
}

/**
 * @brief TestStatsUtility::calculateProductivePercentageNegativeSecondsPositiveProductive
 */
void TestStatsUtility::calculateProductivePercentageNegativeSecondsPositiveProductive() {
    int64_t valueSeconds = -99;
    int64_t valueProductive = 66;

    QVERIFY(StatsUtility::calculateProductivePercentage(valueSeconds, valueProductive) == -1.0);
}

/**
 * @brief TestStatsUtility::calculateProductivePercentagePositiveSecondsNegativeProductive
 */
void TestStatsUtility::calculateProductivePercentagePositiveSecondsNegativeProductive() {
    int64_t valueSeconds = 99;
    int64_t valueProductive = -66;

    QVERIFY(StatsUtility::calculateProductivePercentage(valueSeconds, valueProductive) == -1.0);
}

/**
 * @brief TestStatsUtility::calculateProductivePercentageAllPositive
 */
void TestStatsUtility::calculateProductivePercentageAllPositive() {
    int64_t valueSeconds = 99;
    int64_t valueProductive = 66;

    QVERIFY(StatsUtility::calculateProductivePercentage(valueSeconds, valueProductive) > -1.0);
}

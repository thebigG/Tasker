#include "StatsUtility.h"
#include <QDebug>

#define SECONDS_IN_MINUTE 60
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_DAY 86400
#define SECONDS_IN_WEEK 604800
#define SECONDS_IN_30_DAYS 2592000

/**
 * @brief util::StatsUtility::toMinutes
 * @param seconds quantity of seconds
 *
 * @return -1 if seconds is negative, otherwise quantity of minutes from seconds
 */
int64_t util::StatsUtility::toMinutes(int64_t seconds) {
    int64_t result = -1;
    return (result = seconds < 0 ? result : seconds / SECONDS_IN_MINUTE);
}

/**
 * @brief util::StatsUtility::toHours
 * @param seconds quantity of seconds
 *
 * @return -1 if seconds is negative, otherwise quantity of hours from soconds
 */
int64_t util::StatsUtility::toHours(int64_t seconds) {
    int64_t result = -1;
    return (result = seconds < 0 ? result : seconds / SECONDS_IN_HOUR);
}

/**
 * @brief util::StatsUtility::toDays
 * @param seconds quantity of seconds
 *
 * @return -1 if seconds is negative, otherwise quantity of days from seconds
 */
int64_t util::StatsUtility::toDays(int64_t seconds) {
    int64_t result = -1;
    return (result = seconds < 0 ? result : seconds / SECONDS_IN_DAY);
}

/**
 * @brief util::StatsUtility::toWeeks
 * @param seconds quantity of seconds
 *
 * @return -1 if seconds is negative, otherwise quantity of weeks from seconds
 */
int64_t util::StatsUtility::toWeeks(int64_t seconds) {
    int64_t result = -1;
    return (result = seconds < 0 ? result : seconds / SECONDS_IN_WEEK);
}

/**
 * @brief util::StatsUtility::toMonths
 *
 * @return -1 if seconds is negative, otherwise quantity of months from seconds
 */
int64_t util::StatsUtility::toMonths(int64_t seconds) {
    int64_t result = -1;
    return (result = seconds < 0 ? result : seconds / SECONDS_IN_30_DAYS);
}

/**
 * @brief util::StatsUtility::calculateProductivePercentage
 * @param seconds quantity of total seconds for session
 * @param secondsProductive quantity of productive seconds for session
 *
 * @return -1 if secondsTotal or secondsProductive is negative, otherwise percentage of productive time
 */
double util::StatsUtility::calculateProductivePercentage(int64_t secondsTotal,
                                                         int64_t secondsProductive) {
    double result = -1.0;

    if (secondsTotal >= 0 && secondsProductive >= 0 && secondsProductive <= secondsTotal) {
        result = ((secondsProductive * 100) / (secondsTotal));
    }

    return result;
}

/**
 * @brief util::StatsUtility::calculateUnproductivePercentage
 * @param seconds quantity of total seconds for session
 * @param secondsProductive quantity of unproductive seconds for session
 *
 * @return -1 if secondsTotal or secondsProductive is negative, otherwise percentage of unproductive time
 */
double util::StatsUtility::calculateUnproductivePercentage(int64_t secondsTotal,
                                                           int64_t secondsUnproductive) {
    double result = -1.0;

    if (secondsTotal >= 0 && secondsUnproductive >= 0 && secondsUnproductive <= secondsTotal) {
        result = ((secondsUnproductive * 100) / (secondsTotal));
    }

    return result;
}

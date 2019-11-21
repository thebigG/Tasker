#include "StatsUtility.h"

#define SECONDS_IN_MINUTE 60
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_DAY 86400
#define SECONDS_IN_WEEK 604800
#define SECONDS_IN_30_DAYS 2592000

int64_t util::StatsUtility::toMinutes(int64_t seconds) {
    return seconds / SECONDS_IN_MINUTE;
}

int64_t util::StatsUtility::toHours(int64_t seconds) {
    return seconds / SECONDS_IN_HOUR;
}

int64_t util::StatsUtility::toDays(int64_t seconds) {
    return seconds / SECONDS_IN_DAY;
}

int64_t util::StatsUtility::toWeeks(int64_t seconds) {
    return seconds / SECONDS_IN_WEEK;
}

int64_t util::StatsUtility::toMonths(int64_t seconds) {
    return seconds / SECONDS_IN_30_DAYS;
}

double util::StatsUtility::calculateProductivePercentage(int64_t secondsTotal, int64_t secondsProductive) {
    return ((secondsProductive * 100) / (secondsTotal));
}

double util::StatsUtility::calculateUnproductivePercentage(int64_t secondsTotal, int64_t secondsUnproductive) {
    return ((secondsUnproductive * 100) / (secondsTotal));
}

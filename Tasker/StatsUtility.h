#ifndef STATSUTILITY_H
#define STATSUTILITY_H

#include <cstdint>

#define ZERO 0
#define MINUTES_STRING "Minute(s)"
#define HOURS_STRING "Hour(s)"
#define DAY_STRING "Day"
#define WEEK_STRING "Week"
#define MONTH_STRING "Month"
#define SECONDS_IN_MINUTE 60
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_DAY 86400
#define SECONDS_IN_WEEK 604800
#define SECONDS_IN_30_DAYS 2592000

namespace util {
class StatsUtility;
}

/**
 * @brief The util::StatsUtility class
 */
class util::StatsUtility {
public:
     /**
 * @brief util::StatsUtility::toMinutes
 * @param seconds quantity of seconds
 *
 * @return -1 if seconds is negative, otherwise quantity of minutes from seconds
 */
inline static int64_t toMinutes(int64_t seconds) {
    int64_t result = -1;
    return (result = seconds < 0 ? result : seconds / SECONDS_IN_MINUTE);
}

/**
 * @brief util::StatsUtility::toHours
 * @param seconds quantity of seconds
 *
 * @return -1 if seconds is negative, otherwise quantity of hours from soconds
 */

    static inline int64_t toHours(int64_t seconds) {
        int64_t result = -1;
        return (result = seconds < 0 ? result : seconds / SECONDS_IN_HOUR);
    }
    static int64_t toDays(int64_t seconds);
    static int64_t toWeeks(int64_t seconds);
    static int64_t toMonths(int64_t seconds);
    static long long int milliToSeconds(long long int);
    static double calculateProductivePercentage(int64_t secondsTotal, int64_t secondsProductive);
    static double calculateUnproductivePercentage(int64_t secondsTotal, int64_t secondsProductive);

private:
    StatsUtility();
    ~StatsUtility();
};

template <typename T>
T min(T x, T y) {
    return x > y ? y : x;
}

template <typename T>
T max(T x, T y) {
    return x > y ? x : y;
}

#endif // STATSUTILITY_H

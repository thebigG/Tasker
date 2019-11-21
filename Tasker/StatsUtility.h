#ifndef STATSUTILITY_H
#define STATSUTILITY_H

#include <cstdint>

namespace util {
    class StatsUtility;
}

class util::StatsUtility {
public:
    static int64_t toMinutes(int64_t seconds);
    static int64_t toHours(int64_t seconds);
    static int64_t toDays(int64_t seconds);
    static int64_t toWeeks(int64_t seconds);
    static int64_t toMonths(int64_t seconds);

    static double calculateProductivePercentage(int64_t secondsTotal, int64_t secondsProductive);
    static double calculateUnproductivePercentage(int64_t secondsTotal, int64_t secondsProductive);

private:
    StatsUtility();
    ~StatsUtility();
};

#endif // STATSUTILITY_H

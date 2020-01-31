#ifndef INTERVAL_H
#define INTERVAL_H

#include <cstdint>

namespace util {
struct Interval;
}

/**
 * @brief The util::Interval struct
 */
struct util::Interval {
    long long size = 0;
    long long weeklyFrequency = 0;
};

#endif // INTERVAL_H

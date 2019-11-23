#ifndef INTERVAL_H
#define INTERVAL_H
#include <cstdint>
namespace util {
    struct Interval;
}

struct util::Interval {
    uint64_t size;
    uint64_t frequency;
};

#endif // INTERVAL_H

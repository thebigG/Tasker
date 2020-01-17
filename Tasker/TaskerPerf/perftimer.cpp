#include "perftimer.h"
#include <QDebug>
Perf::PerfTimer::PerfTimer(int newDurationRecordSize):
    durationRecord{newDurationRecordSize}
{

    start = std::chrono::high_resolution_clock::now();
}
/**
 * @brief Perf::PerfTimer::restart
 * Resets the state of the start variable with
 * the current time of the system.
 */
void Perf::PerfTimer::restart()
{
   start = std::chrono::high_resolution_clock::now();
}
Perf::PerfTimer::~PerfTimer()
{
    //
}


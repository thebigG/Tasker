#include "perftimer.h"
#include <QDebug>
/**
 * @brief Perf::PerfTimer::PerfTimer starts the PerfTimer.
 * @param newDurationRecordSize
 */
Perf::PerfTimer::PerfTimer(int newDurationRecordSize) {
    durationRecordSize = newDurationRecordSize;
    start = std::chrono::high_resolution_clock::now();
}
/**
 * @brief Perf::PerfTimer::restart
 * Resets the state of the start variable with
 * the current time of the system.
 * Make sure you ALWAYS call this before the block
 * of code you're measuring begins.
 */
void Perf::PerfTimer::restart() {
    start = std::chrono::high_resolution_clock::now();
}

#ifndef PERFTIMER_H
#define PERFTIMER_H

#include <QDebug>
#include <chrono>
#include <vector>
/**
 *Anything related to measuring performance will be found on this namespace.
 */
namespace Perf {
class PerfTimer;
}
/**
 * @brief The Perf::PerfTimer class a class to made to measure the performance
 * of entities on Tasker.
 * It keeps a record of all times recorded for averaging and crunching on a
 * QVector that will contain durationRecordSize data points.
 */
class Perf::PerfTimer {
private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start;
  std::chrono::time_point<std::chrono::high_resolution_clock> end;

public:
  PerfTimer(int newDurationRecordSize = 100);
  std::vector<long long> durationRecord;
  void restart();
  double duration;
  int durationRecordSize;
  /**
   * @brief Perf::PerfTimer::stop
   * Calculates the duration since either the object was constructed or
   * restart() was called.
   * This is inlined to reduce any miniscule latency of the function call
   * itself.
   */
  inline void stop() {
    if (durationRecord.size() < durationRecordSize) {
      end = std::chrono::high_resolution_clock::now();
      durationRecord.push_back(
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
              .count());
      long long sum = 0;
      for (long long tempDuration : durationRecord) {
        sum += tempDuration;
      }
      duration = sum / durationRecord.size();
    }
  }
};

#endif // PERFTIMER_H

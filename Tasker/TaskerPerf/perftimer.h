#ifndef PERFTIMER_H
#define PERFTIMER_H

#include <QDebug>
#include <chrono>
#include <vector>
namespace Perf {
class PerfTimer;
}

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
  ~PerfTimer();
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

      //    TASKER_LOG("vector:"+QString::nu;
      duration = sum / durationRecord.size();
      //    duration =
      //    std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    }
  }
};

#endif // PERFTIMER_H

#ifndef PERFTIMER_H
#define PERFTIMER_H

#include <chrono>
#include <vector>
#include <QDebug>
namespace Perf {
class PerfTimer;
}

class Perf::PerfTimer
{
private:
      std::chrono::time_point<std::chrono::high_resolution_clock>start;
      std::chrono::time_point<std::chrono::high_resolution_clock> end;
public:
    PerfTimer(int newDurationRecordSize = 100);
    std::vector<long long> durationRecord;
    /**
     * @brief Perf::PerfTimer::stop
     * Calculates the duration since either the object was constructed or
     * restart() was called.
     */
    inline void stop()
    {

    end = std::chrono::high_resolution_clock::now();
    durationRecord.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count());
//    start =  std::chrono::high_resolution_clock::now();
    long long sum = 0 ;
    for(long long tempDuration: durationRecord)
    {
        sum += tempDuration;
    }

    qDebug()<<"vector:"<<durationRecord;
//    duration = sum/durationRecord.size();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    }
    void restart();
    long duration;
    ~PerfTimer();
};

#endif // PERFTIMER_H

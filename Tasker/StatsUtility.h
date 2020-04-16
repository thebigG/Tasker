#ifndef STATSUTILITY_H
#define STATSUTILITY_H

#include <QDate>
#include <QDebug>
#include <Session.h>
#include <cstdint>
#define WEEK_SIZE 7
#define MONTH_SIZE 30
#define ZERO 0
#define MINUTES_STRING "Minute(s)"
#define HOURS_STRING "Hour(s)"
#define DAY_STRING "Day"
#define WEEK_STRING "Week"
#define MONTH_STRING "Month"
#define EVERYDAY_STRING "Everyday"
#define WEEKLY_STRING "Weekly"
#define MINUTES_IN_HOUR 60
#define SECONDS_IN_MINUTE 60
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_DAY 86400
#define SECONDS_IN_WEEK 604800
#define SECONDS_IN_30_DAYS 2592000
/**
 *@brief The util namespace has
 * everything that is no more than "utillity" for Tasker.
 * Things like conversion functions that convert
 * seconds to hours shall be in this namespace.
 */
namespace util {
struct TimeWindow;
// QDataStream &operator<<(QDataStream &out, const TimeWindow);
// QDataStream &operator>>(QDataStream &in, TimeWindow &);
// namespace util
struct TimeWindow {
  QDate startDate;
  QDate endDate;
  QVector<udata::Session> sessions;
};
// QDataStream& util::operator<<(QDataStream &out, const util::TimeWindow t)
//{
// return out;
//}
// QDataStream& util::operator>>(QDataStream &in, util::TimeWindow &t)
//{
// return in;
//}

/**
 * @brief util::StatsUtility::toMinutes
 * @param seconds quantity of seconds
 *
 * @return -1 if seconds is negative, otherwise quantity of minutes from
 * seconds
 */
inline double toMinutes(int64_t seconds) {
  double result = -1.0;
  return (result = seconds < 0 ? result : seconds / (double)SECONDS_IN_MINUTE);
}
inline int64_t minutesToSeconds(int64_t Minutes) {
  int64_t result = -1;
  return (result = Minutes < 0 ? result : Minutes * SECONDS_IN_MINUTE);
}
/**
 * @brief util::StatsUtility::toHours
 * @param seconds quantity of seconds
 *
 * @return -1 if seconds is negative, otherwise quantity of hours from soconds
 */

inline int64_t toHours(int64_t seconds) {
  int64_t result = -1;
  return (result = seconds < 0 ? result : seconds / SECONDS_IN_HOUR);
}
int64_t toDays(int64_t seconds);
int64_t toWeeks(int64_t seconds);
int64_t toMonths(int64_t seconds);
long long int milliToSeconds(long long int);
double calculateProductivePercentage(int64_t secondsTotal,
                                     int64_t secondsProductive);
double calculateUnproductivePercentage(int64_t secondsTotal,
                                       int64_t secondsProductive);
int formatTime(QString &formatString, float Time, QString &context,
               int start = 0);
} // namespace util
#endif // STATSUTILITY_H

#include "StatsUtility.h"
#include <QDebug>
#include <TaskerPerf/PerfTimer.h>
/**
 * @brief util::StatsUtility::toDays
 * @param seconds quantity of seconds
 *
 * @return -1 if seconds is negative, otherwise quantity of days from seconds
 */
int64_t util::toDays(int64_t seconds) {
    int64_t result = -1;
    return (result = seconds < 0 ? result : seconds / SECONDS_IN_DAY);
}

/**
 * @brief util::StatsUtility::toWeeks
 * @param seconds quantity of seconds
 *
 * @return -1 if seconds is negative, otherwise quantity of weeks from seconds
 */
int64_t util::toWeeks(int64_t seconds) {
    int64_t result = -1;
    return (result = seconds < 0 ? result : seconds / SECONDS_IN_WEEK);
}

/**
 * @brief util::StatsUtility::toMonths
 *
 * @return -1 if seconds is negative, otherwise quantity of months from seconds
 */
int64_t util::toMonths(int64_t seconds) {
    int64_t result = -1;
    return (result = seconds < 0 ? result : seconds / SECONDS_IN_30_DAYS);
}

/**
 * @brief util::StatsUtility::calculateProductivePercentage
 * @param seconds quantity of total seconds for session
 * @param secondsProductive quantity of productive seconds for session
 *
 * @return -1 if secondsTotal or secondsProductive is negative, otherwise
 * percentage of productive time
 */
double util::calculateProductivePercentage(int64_t secondsTotal, int64_t secondsProductive) {
    double result = -1.0;

    if (secondsTotal >= 0 && secondsProductive >= 0 && secondsProductive <= secondsTotal) {
        result = ((secondsProductive * 100) / (secondsTotal));
    }

    return result;
}

/**
 * @brief util::StatsUtility::calculateUnproductivePercentage
 * @param seconds quantity of total seconds for session
 * @param secondsProductive quantity of unproductive seconds for session
 *
 * @return -1 if secondsTotal or secondsProductive is negative, otherwise
 * percentage of unproductive time
 */
double util::calculateUnproductivePercentage(int64_t secondsTotal, int64_t secondsUnproductive) {
    double result = -1.0;

    if (secondsTotal >= 0 && secondsUnproductive >= 0 && secondsUnproductive <= secondsTotal) {
        result = ((secondsUnproductive * 100) / (secondsTotal));
    }

    return result;
}

long long int util::milliToSeconds(long long int milliSeconds) {
    return milliSeconds / 1000;
} /**
   * @brief util::formatTime formats the time(in seconds) to a human redable
   * format of "XhYM". This function is specially useful for optimization as it
   * tries its best to not allocate more memory for formatString, every
   * character insertion is done in-place.
   * @param formatString The string to modify and write the final
   * time(formatted) and context to.
   * @param time Time to be formatted in seconds.
   * @param context This string will get appended at the end of formatString
   * @return The index after the last character in formatString, which may be
   * smaller than its size.
   */
int util::formatTime(QString &formatString, float time, QString &context, int start, TimeFormat format) {
    static int temp = 0;
    double timeInminutes = toMinutes(time);
    static Perf::PerfTimer newPerfTimer{};
    newPerfTimer.restart();
    if (start == 0) {
        formatString.fill(' ');
    } else {
        formatString.replace(start, formatString.length() - (start + 1), ' ');
    }
    int numberOfHours = (int)timeInminutes / MINUTES_IN_HOUR;
    QString numberOfMinutesString{ QString::number(
        ((int)timeInminutes) - (numberOfHours * MINUTES_IN_HOUR)) };
    temp = QString::number(numberOfHours).length();
    formatString.replace(start, temp, QString::number(numberOfHours));
    temp += start;
    formatString.replace(temp, 1, "h");
    temp = temp + 1;
    formatString.replace(temp, numberOfMinutesString.length(), numberOfMinutesString);
    temp += numberOfMinutesString.length();
    formatString.replace(temp, 1, "m");
    temp = temp + 1;
    if (format == TimeFormat::HMS) {
        float tempDecimal = timeInminutes - (int)timeInminutes;
        QString numberOfSecondsString{ QString::number(tempDecimal * MINUTES_IN_HOUR) };
        formatString.replace(temp, numberOfSecondsString.length(), numberOfSecondsString);
        temp += numberOfSecondsString.length();
        formatString.replace(temp, 1, "s");
        temp += 1;
    }
    formatString.replace(temp, context.length(), context);
    newPerfTimer.stop();

    qDebug() << "perf time for formatTime" << newPerfTimer.duration;
    return temp + context.length();
}

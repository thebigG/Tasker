#ifndef COMMITMENTSNASPHOT_H
#define COMMITMENTSNASPHOT_H
#include <Commitment.h>
#include <TaskerPerf/PerfTimer.h>

#include <QVector>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts>
#include <memory>
#define MAX_TITLE_CHARS 81
QT_CHARTS_USE_NAMESPACE
/**
 * @brief The CommitmentSnaphot class is a UI widget that displays a weekly
 * chaty of commitments.
 */
class CommitmentSnapshot : public QWidget {
private:
    QBarSet productiveBarSet{ "Productive" };
    QBarSet unproductiveBarSet{ "Unproductive" };
    QBarSeries series;
    QChart chart;
    QStringList categories;
    QBarCategoryAxis weekAxis;
    QValueAxis minuteAxis;
    QChartView view;
    QFont chartFont;
    QWidget detailsWidget;
    QString productiveTimeAvgLabelContext{ " in Productive Avg" };
    QString unproductiveTimeAvgLabelContext{ " in Unproductive Avg" };
    QLabel productiveTimeAvgLabel;
    QLabel unproductiveTimeAvgLabel;
    QPushButton previousSnaphotLabel;
    QPushButton nextSnapshotLabel;
    QString productibeTimeAvgText{};
    QString unproductibeTimeAvgText{};
    double productiveTimeAverage = 0;
    double unproductiveTimeAverage = 0;
    double productiveRatio;
    double unproductiveRatio;
    int getWeekDayIndex(QDate &dateWindowStart, QDate &sessionDay);

    Perf::PerfTimer newPerfTimer{};

public:
    QChartView &getView();
    QBarSet &getProductiveQBarSet();
    QBarSet &getUnproducitveQbarSet();
    double getProductiveTimeAverage();
    double getUnproductiveTimeAverage();

    CommitmentSnapshot();
    void update(udata::TimeWindow &currentWindow, udata::CommitmentType type, int commitmentGoal);
    QPushButton &getNextSnapshotLabel();
    QPushButton &getPreviousSnaphotLabel();
};

#endif // COMMITMENTSNASPHOT_H

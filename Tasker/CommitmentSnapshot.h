#ifndef WEEKLYSNAPHOT_H
#define WEEKLYSNAPHOT_H
#include <Commitment.h>
#include <TaskerPerf/perftimer.h>

#include <QVector>
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
namespace udata {
// Not sure if this is the right namespace for CommitmentSnapshot, it probably
// isn't

class CommitmentSnaphot : public QWidget {
private:
  QBarSet productiveBarSet{"Productive"};
  QBarSet unproductiveBarSet{"Unproductive"};
  QBarSeries series;
  QChart chart;
  QStringList categories;
  QBarCategoryAxis x;
  QValueAxis y;
  QChartView view;
  QFont chartFont;
  QWidget detailsWidget;
  QString productiveTimeAvgLabelContext{" in Productive Avg"};
  QString unproductiveTimeAvgLabelContext{" in Unproductive Avg"};
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

  CommitmentSnaphot(int numberOfBars = 7, QString customeCatgeory = "Sunday");
  void update(TimeWindow &currentWindow, udata::CommitmentType type,
              int commitmentGoal);
  QPushButton &getNextSnapshotLabel();
  QPushButton &getPreviousSnaphotLabel();
};

} // namespace udata
#endif // WEEKLYSNAPHOT_H

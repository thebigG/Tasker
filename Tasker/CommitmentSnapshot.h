#ifndef WEEKLYSNAPHOT_H
#define WEEKLYSNAPHOT_H
#include <Commitment.h>

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
  QLabel productiveTimeAvgLabel;
  QLabel unproductiveTimeAvgLabel;
  double productiveTimeAverage = 0;
  double unproductiveTimeAverage = 0;
  double productiveRatio;
  double unproductiveRatio;

 public:
  QChartView &getView();
  QBarSet &getProductiveQBarSet();
  QBarSet &getUnproducitveQbarSet();
  double getProductiveTimeAverage();
  double getUnproductiveTimeAverage();

  void update(Commitment &updateData, int currentTimeWindow);
  CommitmentSnaphot(int numberOfBars = 7, QString customeCatgeory = "Sunday");
};
}  // namespace udata
#endif  // WEEKLYSNAPHOT_H

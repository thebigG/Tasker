#ifndef WEEKLYSNAPHOT_H
#define WEEKLYSNAPHOT_H
#include <QVector>
#include <QtCharts>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
#include <Commitment.h>
#include <memory>
#define MAX_TITLE_CHARS 81
QT_CHARTS_USE_NAMESPACE
namespace udata {


class CommitmentSnaphot
{
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
public:
    QChartView& getView();
    void update(Commitment& updateData, int currentTimeWindow);
    CommitmentSnaphot(int numberOfBars = 7, QString customeCatgeory ="Sunday");




};
}
#endif // WEEKLYSNAPHOT_H

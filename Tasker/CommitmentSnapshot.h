#ifndef WEEKLYSNAPHOT_H
#define WEEKLYSNAPHOT_H
#include <QVector>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
QT_CHARTS_USE_NAMESPACE
class WeeklySnaphot
{
public:
    QVector<QBarSet*> sets{new QBarSet{"Test#1"}};
    QBarSeries series;
    QChart chart;
    QStringList categories;
    QBarCategoryAxis x;
    QValueAxis y;
    QChartView view;

public:
    WeeklySnaphot(int numberOfBars = 7, QString customeCatgeory ="Sunday");


};

#endif // WEEKLYSNAPHOT_H

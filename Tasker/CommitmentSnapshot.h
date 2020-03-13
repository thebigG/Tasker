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
#include <memory>
QT_CHARTS_USE_NAMESPACE
class CommitmentSnaphot
{
public:
    std::unique_ptr<QBarSet> productiveBarSet = std::make_unique<QBarSet>("Productive");
    std::unique_ptr<QBarSet> unproductiveBarSet = std::make_unique<QBarSet>("Unproductive");
    QVector<QBarSet*> sets{new QBarSet{"Test#1"}};
    QBarSeries series;
    QChart chart;
    QStringList categories;
    QBarCategoryAxis x;
    QValueAxis y;
    QChartView view;

public:
    CommitmentSnaphot(int numberOfBars = 7, QString customeCatgeory ="Sunday");


};

#endif // WEEKLYSNAPHOT_H

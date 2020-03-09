#include "CommitmentSnapshot.h"

WeeklySnaphot::WeeklySnaphot(int numberOfBars, QString customCategories)
{
//    sets.push_back(QBarSet("Test#1"));
    *sets.last() <<12<<10<<3<<23<<7<<15<<12<<20;
    series.append(sets.last());
    chart.addSeries(&series);
    chart.setTitle("Simple barchart example");
    chart.setAnimationOptions(QChart::SeriesAnimations);
    categories << "Mon"<<"Tuesday"<<"Wednesday"<<"Thursday"<<"Friday"
               <<"Saturday"<<customCategories;
    x.append(categories);
    chart.addAxis(&x, Qt::AlignBottom);
    series.attachAxis(&x);

    y.setRange(1,15);
    chart.addAxis(&y, Qt::AlignLeft);
    series.attachAxis(&y);

    chart.legend()->setVisible(true);
    chart.legend()->setAlignment(Qt::AlignBottom);

    view.setChart(&chart);
    view.setRenderHint(QPainter::Antialiasing);
}

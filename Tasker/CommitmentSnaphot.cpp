#include "CommitmentSnapshot.h"

CommitmentSnaphot::CommitmentSnaphot(int numberOfBars, QString customCategories)
{
//    sets.push_back(QBarSet("Test#1"));
    *productiveBarSet.get()<<12<<10<<3<<23<<7<<15<<12<<20;
    *unproductiveBarSet.get()<<2<<3<<0<<4<<2<<1<<1<<2;
    series.append(productiveBarSet.get());
    series.append(unproductiveBarSet.get());
    chart.addSeries(&series);
    chart.setTitle("Simple barchart example");
    chart.setAnimationOptions(QChart::SeriesAnimations);
    categories << "Mon"<<"Tuesday"<<"Wednesday"<<"Thursday"<<"Friday"
               <<"Saturday"<<customCategories;
    x.append(categories);
    chart.addAxis(&x, Qt::AlignBottom);
    series.attachAxis(&x);

    y.setRange(1,50);
    y.setMax(50);
    y.setLabelFormat("%d Minutes");
    chart.addAxis(&y, Qt::AlignLeft);
    series.attachAxis(&y);

    chart.legend()->setVisible(true);
    chart.legend()->setAlignment(Qt::AlignBottom);

    view.setChart(&chart);
    view.setRenderHint(QPainter::Antialiasing);
}

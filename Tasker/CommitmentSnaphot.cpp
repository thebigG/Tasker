#include "CommitmentSnapshot.h"
#include <StatsUtility.h>

udata::CommitmentSnaphot::CommitmentSnaphot(int numberOfBars, QString customCategories)
{
//    sets.push_back(QBarSet("Test#1"));
    productiveBarSet<<12<<10<<3<<23<<7<<15<<12<<20;

    unproductiveBarSet<<2<<3<<0<<4<<2<<1<<1<<2;
    qDebug()<<"size of barset="<<sizeof(QBarSet);
    qDebug()<<"size of bar_series="<<sizeof(QBarSeries);
    qDebug()<<"size of QBarCategoryAxis="<<sizeof(QBarCategoryAxis);
    qDebug()<<"size of QValueAxis="<<sizeof(QValueAxis);
    series.append(&productiveBarSet);
    series.append(&unproductiveBarSet);
    chart.addSeries(&series);
    chart.setTitle("Simple barchart example");
    chart.setAnimationOptions(QChart::SeriesAnimations);
    categories << "Mon"<<"Tuesday"<<"Wednesday"<<"Thursday"<<"Friday"
               <<"Saturday"<<customCategories;
    x.append(categories);
    chart.addAxis(&x, Qt::AlignBottom);
    series.attachAxis(&x);
    y.setRange(1,50);
    y.setTickCount(3);
    y.setLabelFormat("%d Mins");
    chart.addAxis(&y, Qt::AlignLeft);
    series.attachAxis(&y);
    qDebug()<<"default bar width="<<series.barWidth();
    series.setBarWidth(1);
    chart.legend()->setVisible(true);
    chart.legend()->setAlignment(Qt::AlignBottom);
    chartFont = chart.font();
    chartFont.setPointSize(15);
    chart.setTitleFont(chartFont);
    view.setChart(&chart);
    qDebug()<<"size of view"<<view.size();

    view.setRenderHint(QPainter::Antialiasing);
}

QChartView& udata::CommitmentSnaphot::getView()
{
    return view;
}
void udata::CommitmentSnaphot::update(Commitment& updateData, int currentTimeWindow)
{
    qDebug()<<"breaks here???#1";
    series.take(&productiveBarSet);
    series.take(&unproductiveBarSet);
    unproductiveBarSet.setParent(nullptr);
    productiveBarSet.setParent(nullptr);
    for(int i =0;i<updateData.getCommitmentWindows().at(currentTimeWindow).sessions.length();i++)
    {
        qDebug()<<"breaks here???2";
        productiveBarSet.replace(i,
                                 util::StatsUtility::toMinutes(updateData.getCurrentTimeWindow().sessions[i].getProductiveTime()));
        unproductiveBarSet.replace(i,
                                 util::StatsUtility::toMinutes(updateData.getCurrentTimeWindow().sessions[i].getUnproductiveTime()));
        qDebug()<<"breaks here???3";
    }
 qDebug()<<"breaks here???4";

 series.append(&productiveBarSet);
 series.append(&unproductiveBarSet);
 series.detachAxis(&y);
 y.setRange(0,util::StatsUtility::toMinutes(updateData.getFrequency().goal));
 series.attachAxis(&y);
 qDebug()<<"breaks here???5";
    chart.removeSeries(&series);
    chart.addSeries(&series);
    QString dateRange{updateData.getCommitmentWindows().at(currentTimeWindow).startDate.toString()+"--" +
                updateData.getCommitmentWindows().at(currentTimeWindow).endDate.toString()};
    int remainingChars =  MAX_TITLE_CHARS - dateRange.length()  -9 ;
    for(int i =0;i<(remainingChars)/2;i+=6)
    {
        dateRange.append("&nbsp;");
    }
    for(int i =0;i<(remainingChars)/(2);i+=6)
    {
        dateRange.insert(0, "&nbsp;");
    }
    dateRange.insert(0,"&lt;");
//    QString d = dateRange.leftJustified(remainingChars/2,'&nbsp');
//    QString b = dateRange.rightJustified(remainingChars/2,'&nbsp');
    qDebug()<<"length of title="<<chart.title().length();
    dateRange.append("&gt;");

    chart.setTitle(dateRange);

    chart.legend()->setAlignment(Qt::AlignBottom);
    view.setRenderHint(QPainter::Antialiasing);

}


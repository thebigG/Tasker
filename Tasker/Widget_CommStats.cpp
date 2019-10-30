#include "Widget_CommStats.h"
#include "ui_Widget_CommStats.h"

#include "MainWidget.h"

#include <QtCharts/QBarSeries>

Widget_CommStats::Widget_CommStats(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_CommStats) {
    ui->setupUi(this);

    MainWidget *mw = new MainWidget;

    QFrame *fstats = ui->Frame_Stats;

    auto layout = new QVBoxLayout();
    layout->addWidget(mw);
    fstats->setLayout(layout);





}

Widget_CommStats::~Widget_CommStats()
{
    delete ui;
}

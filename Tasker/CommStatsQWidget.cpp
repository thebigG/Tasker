#include "CommStatsQWidget.h"
#include "ui_CommStatsQWidget.h"

#include "TempChartQWidget.h"

#include <QtCharts/QBarSeries>

CommStatsQWidget::CommStatsQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::CommStatsQWidget) {
    ui->setupUi(this);

    TempChartQWidget *mw = new TempChartQWidget;

    QFrame *fstats = ui->statsQFrame;

    auto layout = new QVBoxLayout();
    layout->addWidget(mw);
    fstats->setLayout(layout);

    // layout is dynamically allocated..delete it with conditions later
    // layout will cause a leak
}

CommStatsQWidget::~CommStatsQWidget() {
    delete ui;
}

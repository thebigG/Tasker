#include "CommStatsQWidget.h"
#include "ui_CommStatsQWidget.h"
#include <CreateCommitmentQWidget.h>
#include <mainui.h>
#include <User.h>
#include "TempChartQWidget.h"

#include <QtCharts/QBarSeries>

CommStatsQWidget::CommStatsQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::CommStatsQWidget) {
    ui->setupUi(this);

    TempChartQWidget *mw = new TempChartQWidget;
    connect(this->ui->addCommitmentQCommandLinkButton,
            &QCommandLinkButton::clicked
            ,this, &CommStatsQWidget::addCommitmentButtonSlot);
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
void CommStatsQWidget::addCommitmentButtonSlot()
{
    this->hide();
    CreateCommitmentQWidget *cc = MainUI::getInstance()->getCreateCommitment();
    cc->show();
}
void CommStatsQWidget::on_statsQFrame_destroyed()
{
    delete udata::User::getInstance();
}

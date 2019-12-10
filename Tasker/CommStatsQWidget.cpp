#include "CommStatsQWidget.h"
#include "ui_CommStatsQWidget.h"
#include <CreateCommitmentQWidget.h>
#include <mainui.h>

#include "TempChartQWidget.h"

#include <QDebug>

#include <QtCharts/QBarSeries>

using udata::Commitment;
using udata::User;

/**
 * @brief CommStatsQWidget::CommStatsQWidget
 * @param parent
 */
CommStatsQWidget::CommStatsQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::CommStatsQWidget) {
    ui->setupUi(this);

    TempChartQWidget *mw = new TempChartQWidget;
    connect(this->ui->addCommitmentQCommandLinkButton, &QCommandLinkButton::clicked,
            this, &CommStatsQWidget::addCommitmentButtonSlot);
    QFrame *fstats = ui->statsQFrame;

    auto layout = new QVBoxLayout();
    layout->addWidget(mw);
    fstats->setLayout(layout);

    /*
    {
        QVector<Commitment> v = User::getInstance()->getCommitments();

        QVector<Commitment>::iterator it = v.begin();
        while (it != v.end()) {
            qDebug() << (*it).getName() << ": " << (*it).getDateStart().toString();
            ++it;
        }

        qDebug() << "vector size: " << v.size();
    }
    */

    // layout is dynamically allocated..delete it with conditions later
    // layout will cause a leak
}

/**
 * @brief CommStatsQWidget::~CommStatsQWidget
 */
CommStatsQWidget::~CommStatsQWidget() {
    delete ui;
}

/**
 * @brief CommStatsQWidget::addCommitmentButtonSlot
 */
void CommStatsQWidget::addCommitmentButtonSlot() {
    this->hide();
    CreateCommitmentQWidget *cc = MainUI::getInstance()->getCreateCommitment();
    cc->show();
}

/**
 * @brief CommStatsQWidget::on_statsQFrame_destroyed
 */
void CommStatsQWidget::on_statsQFrame_destroyed() {
    delete udata::User::getInstance();
}

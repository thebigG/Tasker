#include "CommStatsQWidget.h"
#include "ui_CommStatsQWidget.h"
#include <CreateCommitmentQWidget.h>
#include <mainui.h>

#include "TempChartQWidget.h"

#include <QDebug>
#include "Timer.h"

#include <QtCharts/QBarSeries>

using udata::Commitment;
using udata::User;
using udata::Session;
using Engine::Listener;
using Engine::Listener;


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

void CommStatsQWidget::update() {


        QVector<Commitment> c_vec = User::getInstance()->getCommitments();




        auto it = c_vec.begin();
        while (it != c_vec.end()) {
            Commitment c = (*it);

            auto s_vec = c.getSessions();
            auto s_it = s_vec.begin();

            QTreeWidget *w = ui->commitmentsQTreeWidget;

            QTreeWidgetItem *item = new QTreeWidgetItem(QStringList() << c.getName() << ": " << c.getDateStart().toString());

            while (s_it != s_vec.end()) {
                Session s = (*s_it);



                ++s_it;
            }

            ++it;

            w->addTopLevelItem(item);
        }

}

void CommStatsQWidget::on_commitmentsQTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QString commitmentName = item->text(column);

    auto c_vec = User::getInstance()->getCommitments();
    auto c_it = c_vec.begin();

    while (c_it != c_vec.end()) {
        Commitment c = (*c_it);

        if (c.getName() == commitmentName) {
            qDebug() << c.getName();

            auto t = MainUI::getInstance()->getTimerWindow();
            t->show();
        }

        ++c_it;
    }
}

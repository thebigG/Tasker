#include "CommStatsQWidget.h"
#include "ui_CommStatsQWidget.h"
#include <CreateCommitmentQWidget.h>
#include <mainui.h>

#include "Timer.h"
#include <QDebug>

//#include <QtCharts/QBarSeries>

using Engine::Listener;
using udata::Commitment;
using udata::Session;
using udata::User;

/**
 * @brief CommStatsQWidget::CommStatsQWidget
 * @param parent
 */
CommStatsQWidget::CommStatsQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::CommStatsQWidget) {
    ui->setupUi(this);
    connect(ui->addCommitmentQPushButton, &QPushButton::clicked, this,
            &CommStatsQWidget::addCommitmentButtonSlot);
    connect(ui->removeCommitmentQPushButton, &QPushButton::clicked, this,
            &CommStatsQWidget::removeCommitmentButtonSlot);
    connect(ui->commitmentsQTreeWidget, &QTreeWidget::currentItemChanged, this,
            &CommStatsQWidget::currentCommitmentChangedSlot);
    connect(ui->liveSessionQPushButton, &QPushButton::clicked, this,
            &CommStatsQWidget::newLiveSessionSlot);
    //    TempChartQWidget *mw = new TempChartQWidget;
    //    connect(this->ui->addCommitmentQCommandLinkButton, &QCommandLinkButton::clicked,
    //            this, &CommStatsQWidget::addCommitmentButtonSlot);
    //    QFrame *fstats = ui->statsQFrame;

    //    auto layout = new QVBoxLayout();

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
    qDebug("CommStatsQWidget destructor#1");
    delete ui;
    qDebug("CommStatsQWidget destructor#2");
}

/**
 * @brief CommStatsQWidget::addCommitmentButtonSlot
 */
void CommStatsQWidget::addCommitmentButtonSlot() {
    this->hide();
    //    CreateCommitmentQWidget &cc =
    //    MainUI::getInstance()->getCreateCommitment(); cc.show();
    this->createCommimentWindow.show();
}
void CommStatsQWidget::removeCommitmentButtonSlot() {
    //    TASKER_LOG("deleting#1:" << selectedCommitmentIndex);
    int tempIndex = selectedCommitmentIndex;
    if (selectedCommitmentIndex == (User::getInstance()->getCommitments().size() - 1)) {
        selectedCommitmentIndex--;
    }
    User::getInstance()->getCommitments().removeAt(tempIndex);
    isDelete = true; // This is for the currentItemChanged signal, which gets emitted by delete keyword
    delete ui->commitmentsQTreeWidget->topLevelItem(tempIndex);
    qDebug() << "deleting#2:" << tempIndex;
    qDebug() << "deleting#3:" << tempIndex;
}

/**
 * @brief CommStatsQWidget::on_statsQFrame_destroyed
 */
void CommStatsQWidget::on_statsQFrame_destroyed() {
    qDebug()
        << "delete udata::User::getInstance() on on_statsQFrame_destroyed#1";
    //    delete udata::User::getInstance();
    qDebug()
        << "delete udata::User::getInstance() on on_statsQFrame_destroyed2";
}

void CommStatsQWidget::update() {
    QVector<Commitment> &c_vec = User::getInstance()->getCommitments();
    auto it = c_vec.begin();
    while (it != c_vec.end()) {
        Commitment c = (*it);

        auto s_vec = c.getAllSessions();
        auto s_it = s_vec.begin();

        QTreeWidget *w = ui->commitmentsQTreeWidget;
        //Removing this new() call will require more thinking
        // and considering a redesign of commStatsQwidget as a whole
        QTreeWidgetItem *item = new QTreeWidgetItem(
            QStringList() << c.getName() << ": " << c.getDateStart().toString());

        while (s_it != s_vec.end()) {
            Session s = (*s_it);

            ++s_it;
        }

        ++it;

        w->addTopLevelItem(item);
    }
}

void CommStatsQWidget::on_commitmentsQTreeWidget_itemDoubleClicked(QTreeWidgetItem *item,
                                                                   int column) {
    QString commitmentName = item->text(column);

    auto c_vec = User::getInstance()->getCommitments();
    auto c_it = c_vec.begin();

    while (c_it != c_vec.end()) {
        Commitment c = (*c_it);

        if (c.getName() == commitmentName) {
            qDebug() << c.getName();

            TimerWindowQWidget &t = MainUI::getInstance()->getTimerWindow();
            t.show();
        }

        ++c_it;
    }
}
void CommStatsQWidget::currentCommitmentChangedSlot(QTreeWidgetItem *current,
                                                    QTreeWidgetItem *previous) {
    if (isDelete) {
        isDelete = false;
        return;
    }
    if (current == previous) {
        qDebug() << "SAME OBJECT";
    }
    int currentIndex = 0;
    currentIndex = ui->commitmentsQTreeWidget->indexOfTopLevelItem(current);
    if (currentIndex == -1) {
        qDebug() << "NEGATIVE";
        currentIndex =
            ui->commitmentsQTreeWidget->indexOfTopLevelItem(current->parent());
    }

    selectedCommitmentIndex = currentIndex;
    qDebug() << "changed commitment index:" << currentIndex;
    qDebug() << "changed commitment name:"
             << User::getInstance()->getCommitments().at(currentIndex).getName();
}
void CommStatsQWidget::newLiveSessionSlot() {
    this->hide();
    this->getTimerWindow().show();
}
TimerWindowQWidget &CommStatsQWidget::getTimerWindow() {
    return timerWindow;
}
CreateCommitmentQWidget &CommStatsQWidget::getCreateCommitment() {
    return createCommimentWindow;
}

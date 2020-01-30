#include "CreateCommitmentQWidget.h"
#include "ui_CreateCommitmentQWidget.h"
#include <CommStatsQWidget.h>
#include <Commitment.h>
#include <Listener.h>
#include <QDebug>
#include <QObject>
#include <StatsUtility.h>
#include <User.h>
#include <mainui.h>

using namespace util;
using namespace udata;

/**
 * @brief CreateCommitmentQWidget::CreateCommitmentQWidget
 * @param parent
 */
CreateCommitmentQWidget::CreateCommitmentQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::CreateCommitmentQWidget) {
    ui->setupUi(this);
    //    validator = new QIntValidator(0, 999, this);
    ui->qtyQLineEdit->setValidator(&validator);
    connect(this->getUI()->commitmentBottomOptionsContainer->findChild<QPushButton*>("createCommitmentQPushButton_2"), &QPushButton::clicked,
            this, &CreateCommitmentQWidget::createCommitmentButtonSlot);
    connect(this->getUI()->commitmentBottomOptionsContainer->findChild<QPushButton*>("backQPushButton_2"), &QPushButton::clicked, this,
            &CreateCommitmentQWidget::backButtonSlot);
    QFontMetrics thisFont{ this->ui->commitmentNameQLabel->font()};
    qDebug()<<"font height="<<thisFont.height();
    qDebug()<<"average width font="<<thisFont.averageCharWidth();
}

/**
 * @brief CreateCommitmentQWidget::~CreateCommitmentQWidget
 */
CreateCommitmentQWidget::~CreateCommitmentQWidget() {
    qDebug() << "CreateCommitmentQWidget#1";
    delete ui;
    qDebug() << "CreateCommitmentQWidget#2";
}

/**
 * @brief CreateCommitmentQWidget::getUI
 * @return
 */
Ui::CreateCommitmentQWidget *CreateCommitmentQWidget::getUI() {
    return ui;
}

/**
 * @brief CreateCommitmentQWidget::backButtonSlot
 */
void CreateCommitmentQWidget::backButtonSlot() {
    qDebug()<<"Listener for back button";
    this->hide();
    MainUI::getInstance()->show();
}

/**
 * @brief CreateCommitmentQWidget::createCommitmentButtonSlot
 */
void CreateCommitmentQWidget::createCommitmentButtonSlot() {
    this->hide();
    QVector<Session> sessions{};
//    QVector<Engine::Listener::ListenerType> listeners;
//    if (this->ui->checkKeyboardQCheckBox->checkState() == Qt::Checked) {
//        listeners.push_back(Engine::Listener::ListenerType::keyboard);
//    }
//    if (this->ui->checkMicQCheckBox->checkState() == Qt::Checked) {
//        listeners.push_back(Engine::Listener::ListenerType::audio);
//    }
    Task newTask{""};
    sessions.push_back(Session{ newTask });
    Commitment temp{ this->getCommitmentName(), this->getStartDate(),
                     this->getEndDate(), this->getInterval(), sessions };
    udata::User::getInstance()->addCommitment(temp);
    MainUI::getInstance()->update();
    MainUI::getInstance()->show();
}
/**
 * @brief CreateCommitmentQWidget::getCommitmentName
 * @return
 */
QString CreateCommitmentQWidget::getCommitmentName() {
    return ui->commitmentNameQLineEdit->text();
}

/**
 * @brief CreateCommitmentQWidget::getStartDate
 * @return
 */
QDate CreateCommitmentQWidget::getStartDate() {
    return ui->dateStartQDateEdit->date();
}

/**
 * @brief CreateCommitmentQWidget::getEndDate
 * @return
 */
QDate CreateCommitmentQWidget::getEndDate() {
    return ui->dateEndQDateEdit->date();
}

/**
 * @brief CreateCommitmentQWidget::getInterval
 * @return
 */
util::Interval CreateCommitmentQWidget::getInterval() {
    util::Interval interval{};
    long long int size, frequency;
    QString currentSizeLabel = ui->dropDownUnitsLeftQComboBox->currentText();
    QString currentFrequencyLabel = ui->dropDownUnitsRightQComboBox->currentText();
    if (currentSizeLabel == MINUTES_STRING) {
        size = SECONDS_IN_MINUTE * ui->qtyQLineEdit->text().toInt();
    } else if (currentSizeLabel == HOURS_STRING) {
        size = SECONDS_IN_HOUR * ui->qtyQLineEdit->text().toInt();
    }
    if (currentFrequencyLabel == DAY_STRING) {
        frequency = SECONDS_IN_DAY;
    } else if (currentFrequencyLabel == WEEK_STRING) {
        frequency = SECONDS_IN_WEEK;
    } else if (currentFrequencyLabel == MONTH_STRING) {
        frequency = SECONDS_IN_30_DAYS;
    }
    interval.size = size;
    interval.frequency = frequency;
    return interval;
}

/**
 * @brief CreateCommitmentQWidget::getAudioCheckBox
 * @return
 */




/**
 * @brief CreateCommitmentQWidget::on_createCommitmentQFrame_destroyed
 */
void CreateCommitmentQWidget::on_createCommitmentQFrame_destroyed() {
    qDebug() << "on_createCommitmentQFrame_destroyed#1";
    //    delete udata::User::getInstance();
}

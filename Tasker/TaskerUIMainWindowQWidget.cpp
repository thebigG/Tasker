
#include "TaskerUIMainWindowQWidget.h"
#include "ui_TaskerUIMainWindowQWidget.h"

#include <User.h>
#include <mainui.h>
#include <stdio.h>
#include <stdlib.h>

#define TASKTER_TITLE "Tasker"

/**
 * @brief TaskerUIMainWindowQWidget::TaskerUIMainWindowQWidget
 * @param parent
 */
TaskerUIMainWindowQWidget::TaskerUIMainWindowQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::TaskerUIMainWindowQWidget) {
    ui->setupUi(this);
    x = new CreateCommitmentQWidget();
    this->setWindowTitle(TASKTER_TITLE);
    wc = new CommStatsQWidget();
    tw = new TimerWindowQWidget();
    connect(this->ui->makeCommitmentQPushButton, &QPushButton::clicked, this,
            &TaskerUIMainWindowQWidget::makeCommitmentButtonSlot);
    connect(this->ui->quickSessionQPushButton, &QPushButton::clicked, this,
            &TaskerUIMainWindowQWidget::quickSessionButtonSlot);
}

/**
 * @brief TaskerUIMainWindowQWidget::getButton
 * @return
 */
QPushButton *TaskerUIMainWindowQWidget::getButton() {
    return ui->makeCommitmentQPushButton;
}

/**
 * @brief TaskerUIMainWindowQWidget::getCreateCommitment
 * @return
 */
CreateCommitmentQWidget *TaskerUIMainWindowQWidget::getCreateCommitment() {
    return x;
}

/**
 * @brief TaskerUIMainWindowQWidget::quickSessionButtonSlot
 */
void TaskerUIMainWindowQWidget::quickSessionButtonSlot() {
    this->hide();
    TimerWindowQWidget *tw = MainUI::getInstance()->getTimerWindow();
    tw->show();
}

/**
 * @brief TaskerUIMainWindowQWidget::makeCommitmentButtonSlot
 */
void TaskerUIMainWindowQWidget::makeCommitmentButtonSlot() {
    MainUI::getInstance()->hide();
    MainUI::getInstance()->getCreateCommitment()->show();
}

/**
 * @brief TaskerUIMainWindowQWidget::getWelcomeFrame
 * @return
 */
QFrame *TaskerUIMainWindowQWidget::getWelcomeFrame() {
    return ui->welcomeQFrame;
}

/**
 * @brief TaskerUIMainWindowQWidget::getCommStats
 * @return
 */
CommStatsQWidget *TaskerUIMainWindowQWidget::getCommStats() {
    return wc;
}

/**
 * @brief TaskerUIMainWindowQWidget::getTimerWindow
 * @return
 */
TimerWindowQWidget *TaskerUIMainWindowQWidget::getTimerWindow() {
    return tw;
}

/**
 * @brief TaskerUIMainWindowQWidget::~TaskerUIMainWindowQWidget
 */
TaskerUIMainWindowQWidget::~TaskerUIMainWindowQWidget() {
    delete tw;
    delete wc;
    delete x;

    delete ui;
}

/**
 * @brief TaskerUIMainWindowQWidget::on_welcomeQFrame_destroyed
 */
void TaskerUIMainWindowQWidget::on_welcomeQFrame_destroyed() {
    delete udata::User::getInstance();
}

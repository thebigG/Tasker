
#include "TaskerUIMainWindowQWidget.h"
#include "ui_TaskerUIMainWindowQWidget.h"

#include <User.h>
#include <mainui.h>
#include <stdio.h>
#include <stdlib.h>
#define TASKTER_TITLE "Tasker"
TaskerUIMainWindowQWidget::TaskerUIMainWindowQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::TaskerUIMainWindowQWidget) {
    ui->setupUi(this);
    x = new CreateCommitmentQWidget();
    this->setWindowTitle(TASKTER_TITLE);
    wc = new CommStatsQWidget();
    tw = new TimerWindowQWidget();
    connect(this->ui->makeCommitmentQPushButton,
            &QPushButton::clicked, this,
            &TaskerUIMainWindowQWidget::makeCommitmentButtonSlot);
    connect(this->ui->quickSessionQPushButton,
            &QPushButton::clicked, this,
            &TaskerUIMainWindowQWidget::quickSessionButtonSlot);
}

QPushButton *TaskerUIMainWindowQWidget::getButton() {
    return ui->makeCommitmentQPushButton;
}

CreateCommitmentQWidget *TaskerUIMainWindowQWidget::getCreateCommitment() {
    return x;
}
void  TaskerUIMainWindowQWidget::quickSessionButtonSlot()
{
        this->hide();
        TimerWindowQWidget *tw = MainUI::getInstance()->getTimerWindow();
        tw->show();
}
void TaskerUIMainWindowQWidget::makeCommitmentButtonSlot() {
    MainUI::getInstance()->hide();
    MainUI::getInstance()->getCreateCommitment()->show();
}
QFrame *TaskerUIMainWindowQWidget::getWelcomeFrame() {
    return ui->welcomeQFrame;
}

CommStatsQWidget *TaskerUIMainWindowQWidget::getCommStats() {
    return wc;
}

TimerWindowQWidget *TaskerUIMainWindowQWidget::getTimerWindow() {
    return tw;
}

TaskerUIMainWindowQWidget::~TaskerUIMainWindowQWidget() {
    delete tw;
    delete wc;
    delete x;

    delete ui;
}

void TaskerUIMainWindowQWidget::on_welcomeQFrame_destroyed() {
    delete udata::User::getInstance();
}

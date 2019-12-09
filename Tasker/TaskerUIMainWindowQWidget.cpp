
#include "TaskerUIMainWindowQWidget.h"
#include "ui_TaskerUIMainWindowQWidget.h"

#include <User.h>
#include <stdio.h>
#include <stdlib.h>

TaskerUIMainWindowQWidget::TaskerUIMainWindowQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::TaskerUIMainWindowQWidget) {
    ui->setupUi(this);

    x = new CreateCommitmentQWidget();
    this->setWindowTitle("Tasker");

    wc = new CommStatsQWidget();

    tw = new TimerWindowQWidget();
}

QPushButton *TaskerUIMainWindowQWidget::getButton() {
    return ui->makeCommitmentQPushButton;
}

CreateCommitmentQWidget *TaskerUIMainWindowQWidget::getCreateCommitment() {
    return x;
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

void TaskerUIMainWindowQWidget::on_welcomeQFrame_destroyed()
{
    delete udata::User::getInstance();
}

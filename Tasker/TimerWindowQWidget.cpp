#include "TimerWindowQWidget.h"
#include "ui_TimerWindowQWidget.h"
#include <User.h>
#include <mainui.h>
TimerWindowQWidget::TimerWindowQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::TimerWindowQWidget) {
    ui->setupUi(this);
    connect(this->ui->backQPushButton,
            &QPushButton::clicked,
            this, &TimerWindowQWidget::backButtonSlot);
}

void TimerWindowQWidget::backButtonSlot()
{
    this->hide();
    MainUI::getInstance()->show();
}

TimerWindowQWidget::~TimerWindowQWidget() {
    delete ui;
}

void TimerWindowQWidget::on_timerWindowQFrame_destroyed()
{
    delete udata::User::getInstance();
}

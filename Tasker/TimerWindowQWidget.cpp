#include "TimerWindowQWidget.h"
#include "ui_TimerWindowQWidget.h"
#include <User.h>
TimerWindowQWidget::TimerWindowQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::TimerWindowQWidget) {
    ui->setupUi(this);
}

TimerWindowQWidget::~TimerWindowQWidget() {
    delete ui;
}

void TimerWindowQWidget::on_timerWindowQFrame_destroyed()
{
    delete udata::User::getInstance();
}

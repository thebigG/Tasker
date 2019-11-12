#include "TimerWindowQWidget.h"
#include "ui_TimerWindowQWidget.h"

TimerWindowQWidget::TimerWindowQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::TimerWindowQWidget) {
    ui->setupUi(this);
}

TimerWindowQWidget::~TimerWindowQWidget() {
    delete ui;
}

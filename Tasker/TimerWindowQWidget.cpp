#include "TimerWindowQWidget.h"
#include "ui_TimerWindowQWidget.h"

#include <User.h>
#include <mainui.h>

/**
 * @brief TimerWindowQWidget::TimerWindowQWidget
 * @param parent
 */
TimerWindowQWidget::TimerWindowQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::TimerWindowQWidget) {
    ui->setupUi(this);
    connect(this->ui->backQPushButton, &QPushButton::clicked, this,
            &TimerWindowQWidget::backButtonSlot);
}

/**
 * @brief TimerWindowQWidget::backButtonSlot
 */
void TimerWindowQWidget::backButtonSlot() {
    this->hide();
    MainUI::getInstance()->show();
}

/**
 * @brief TimerWindowQWidget::~TimerWindowQWidget
 */
TimerWindowQWidget::~TimerWindowQWidget() {
    delete ui;
}

/**
 * @brief TimerWindowQWidget::on_timerWindowQFrame_destroyed
 */
void TimerWindowQWidget::on_timerWindowQFrame_destroyed() {
    delete udata::User::getInstance();
}

#include "TimerWindowQWidget.h"
#include "ui_TimerWindowQWidget.h"
#include <Session.h>
#include <StatsUtility.h>
#include <User.h>
#include <Task.h>
#include <mainui.h>
#include <Timer.h>
#include <QString>
#include <Listener.h>
#include <Timer.h>
#include <livesession.h>
using namespace udata;
using namespace Engine;
/**
 * @brief TimerWindowQWidget::TimerWindowQWidget
 * @param parent
 */
TimerWindowQWidget::TimerWindowQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::TimerWindowQWidget) {
    ui->setupUi(this);
    connect(this->ui->backQPushButton, &QPushButton::clicked, this,
            &TimerWindowQWidget::backButtonSlot);
    connect(this->ui->startTimerQPushButton, &QPushButton::clicked,
            this, &TimerWindowQWidget::startTimerButtonSlot);
    connect(this->ui->taskQComboBox, SIGNAL(activated(const QString &)),
            this, SLOT(dropDownTaskSlot(const QString &)));
    this->ui->keyboardQCheckBox->setCheckState(Qt::CheckState{ Qt::Checked });
}

/**
 * @brief TimerWindowQWidget::backButtonSlot
 */
void TimerWindowQWidget::backButtonSlot() {
    this->hide();
    MainUI::getInstance()->show();
}
void TimerWindowQWidget::startTimerButtonSlot()
{
    QVector<Engine::Listener::ListenerType> newListsners;
    if(this->ui->keyboardQCheckBox->checkState() == Qt::CheckState{ Qt::Checked })
    {
        newListsners.push_back(Engine::Listener::ListenerType::keyboard);
    }
    if(this->ui->audioQCheckBox->checkState() == Qt::CheckState{Qt::Checked})
    {
        newListsners.push_back(Engine::Listener::ListenerType::audio);
    }
    int goal = this->ui->productionTimeHoursQSpinBox->value() * SECONDS_IN_HOUR;
    goal += this->ui->productionTimeMinutesQSpinBox->value() * SECONDS_IN_MINUTE;
    goal += this->ui->productionTimeSecondsQSpinBox->value();
    qDebug()<<"new goal"<<goal;
    Task newTask{getTaskName(), newListsners};
    Session newSession{newTask, goal};
    Engine::Timer::getInstance()->initTimer(newListsners.at(0), newSession);
    LiveSession* s = new LiveSession{};
    s->show();

//    Engine::Timer::getInstance()->start();
}
QString TimerWindowQWidget::getTaskName()
{
    return this->ui->taskQComboBox->currentText();
}
/**
 * @brief TimerWindowQWidget::~TimerWindowQWidget
 */
TimerWindowQWidget::~TimerWindowQWidget() {
    qDebug()<<"TimerWindowQWidget destructor#1";
    delete ui;
    qDebug()<<"TimerWindowQWidget destructor#2";
}

/**
 * @brief TimerWindowQWidget::on_timerWindowQFrame_destroyed
 */
void TimerWindowQWidget::on_timerWindowQFrame_destroyed() {
    qDebug()<<" udata::User::getInstance() on on_timerWindowQFrame_destroyed()#1";
    delete udata::User::getInstance();
    qDebug()<<" udata::User::getInstance() on on_timerWindowQFrame_destroyed()#2";
}




void TimerWindowQWidget::dropDownTaskSlot(const QString &arg1) {
    if (arg1 == QString(WRITING_STRING)) {
        this->ui->keyboardQCheckBox->setCheckState(Qt::CheckState{ Qt::Checked });
        this->ui->audioQCheckBox->setCheckState(Qt::CheckState{ Qt::Unchecked });
    } else if (arg1 == QString(MUSIC_STRING)) {
        this->ui->audioQCheckBox->setCheckState(Qt::CheckState{ Qt::Checked });
           this->ui->keyboardQCheckBox->setCheckState(Qt::CheckState{ Qt::Unchecked });
    } else if (arg1 == QString(CUSTOM_STRING)) {
        this->ui->audioQCheckBox->setCheckState(Qt::CheckState{ Qt::Unchecked });
           this->ui->keyboardQCheckBox->setCheckState(Qt::CheckState{ Qt::Unchecked });
    }
}


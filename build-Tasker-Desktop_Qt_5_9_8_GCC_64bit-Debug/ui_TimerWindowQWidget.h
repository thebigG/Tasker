/********************************************************************************
** Form generated from reading UI file 'TimerWindowQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMERWINDOWQWIDGET_H
#define UI_TIMERWINDOWQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimerWindowQWidget
{
public:
    QFrame *timerWindowQFrame;
    QLabel *timerQLabel;
    QPushButton *startTimerQPushButton;
    QPushButton *backQPushButton;
    QFrame *taskListenersQFrame;
    QComboBox *taskQComboBox;
    QLabel *taskQLabel;
    QComboBox *audioQComboBox;
    QCheckBox *audioQCheckBox;
    QCheckBox *keyboardQCheckBox;
    QLabel *listenersQLabel;
    QFrame *realTimeQFrame;
    QLabel *realTimeLabel;
    QLineEdit *realTimeDurationQLineEdit;
    QFrame *realTimeAlertQFrame;
    QLabel *realTimeAlertQLabel;
    QRadioButton *realTimeAlertWhenFinishedQRadioButton;
    QRadioButton *realTimeOffQRadioButton;
    QRadioButton *realTimeWaitForPauseQRadioButton;
    QFrame *productionTimeAlertQFrame;
    QLabel *productionTimeAlertQLabel;
    QRadioButton *productionTimeAlertWhenFinishedQRadioButton;
    QRadioButton *productionTimeOffQRadioButton;
    QRadioButton *productionTimeWaitForPauseQRadioButton;
    QFrame *productionTimerQFrame;
    QSpinBox *productionTimeMillisecondsQSpinBox;
    QLabel *productionTimeQLabel;
    QSpinBox *productionTimeSecondsQSpinBox;
    QSpinBox *productionTimeHoursQSpinBox;
    QSpinBox *productionTimeMinutesQSpinBox;
    QLabel *productionTimeDescriptionsQLabel;

    void setupUi(QWidget *TimerWindowQWidget)
    {
        if (TimerWindowQWidget->objectName().isEmpty())
            TimerWindowQWidget->setObjectName(QStringLiteral("TimerWindowQWidget"));
        TimerWindowQWidget->resize(450, 450);
        timerWindowQFrame = new QFrame(TimerWindowQWidget);
        timerWindowQFrame->setObjectName(QStringLiteral("timerWindowQFrame"));
        timerWindowQFrame->setGeometry(QRect(0, 0, 451, 451));
        timerWindowQFrame->setFrameShape(QFrame::NoFrame);
        timerWindowQFrame->setFrameShadow(QFrame::Raised);
        timerQLabel = new QLabel(timerWindowQFrame);
        timerQLabel->setObjectName(QStringLiteral("timerQLabel"));
        timerQLabel->setGeometry(QRect(60, 50, 181, 16));
        QFont font;
        font.setPointSize(14);
        timerQLabel->setFont(font);
        startTimerQPushButton = new QPushButton(timerWindowQFrame);
        startTimerQPushButton->setObjectName(QStringLiteral("startTimerQPushButton"));
        startTimerQPushButton->setGeometry(QRect(40, 410, 141, 24));
        backQPushButton = new QPushButton(timerWindowQFrame);
        backQPushButton->setObjectName(QStringLiteral("backQPushButton"));
        backQPushButton->setGeometry(QRect(330, 410, 80, 24));
        taskListenersQFrame = new QFrame(timerWindowQFrame);
        taskListenersQFrame->setObjectName(QStringLiteral("taskListenersQFrame"));
        taskListenersQFrame->setGeometry(QRect(40, 290, 301, 101));
        taskListenersQFrame->setFrameShape(QFrame::NoFrame);
        taskListenersQFrame->setFrameShadow(QFrame::Raised);
        taskQComboBox = new QComboBox(taskListenersQFrame);
        taskQComboBox->setObjectName(QStringLiteral("taskQComboBox"));
        taskQComboBox->setGeometry(QRect(150, 0, 141, 25));
        taskQLabel = new QLabel(taskListenersQFrame);
        taskQLabel->setObjectName(QStringLiteral("taskQLabel"));
        taskQLabel->setGeometry(QRect(100, 0, 31, 25));
        audioQComboBox = new QComboBox(taskListenersQFrame);
        audioQComboBox->setObjectName(QStringLiteral("audioQComboBox"));
        audioQComboBox->setGeometry(QRect(50, 70, 121, 25));
        audioQCheckBox = new QCheckBox(taskListenersQFrame);
        audioQCheckBox->setObjectName(QStringLiteral("audioQCheckBox"));
        audioQCheckBox->setGeometry(QRect(0, 70, 83, 25));
        keyboardQCheckBox = new QCheckBox(taskListenersQFrame);
        keyboardQCheckBox->setObjectName(QStringLiteral("keyboardQCheckBox"));
        keyboardQCheckBox->setGeometry(QRect(0, 50, 83, 22));
        listenersQLabel = new QLabel(taskListenersQFrame);
        listenersQLabel->setObjectName(QStringLiteral("listenersQLabel"));
        listenersQLabel->setGeometry(QRect(0, 30, 58, 16));
        realTimeQFrame = new QFrame(timerWindowQFrame);
        realTimeQFrame->setObjectName(QStringLiteral("realTimeQFrame"));
        realTimeQFrame->setGeometry(QRect(40, 170, 151, 21));
        realTimeQFrame->setFrameShape(QFrame::NoFrame);
        realTimeQFrame->setFrameShadow(QFrame::Raised);
        realTimeLabel = new QLabel(realTimeQFrame);
        realTimeLabel->setObjectName(QStringLiteral("realTimeLabel"));
        realTimeLabel->setGeometry(QRect(0, 0, 81, 25));
        realTimeDurationQLineEdit = new QLineEdit(realTimeQFrame);
        realTimeDurationQLineEdit->setObjectName(QStringLiteral("realTimeDurationQLineEdit"));
        realTimeDurationQLineEdit->setGeometry(QRect(70, 0, 81, 25));
        realTimeDurationQLineEdit->setInputMethodHints(Qt::ImhTime);
        realTimeDurationQLineEdit->setMaxLength(11);
        realTimeAlertQFrame = new QFrame(timerWindowQFrame);
        realTimeAlertQFrame->setObjectName(QStringLiteral("realTimeAlertQFrame"));
        realTimeAlertQFrame->setGeometry(QRect(200, 210, 141, 71));
        realTimeAlertQFrame->setFrameShape(QFrame::NoFrame);
        realTimeAlertQFrame->setFrameShadow(QFrame::Raised);
        realTimeAlertQLabel = new QLabel(realTimeAlertQFrame);
        realTimeAlertQLabel->setObjectName(QStringLiteral("realTimeAlertQLabel"));
        realTimeAlertQLabel->setGeometry(QRect(0, 0, 161, 16));
        realTimeAlertWhenFinishedQRadioButton = new QRadioButton(realTimeAlertQFrame);
        realTimeAlertWhenFinishedQRadioButton->setObjectName(QStringLiteral("realTimeAlertWhenFinishedQRadioButton"));
        realTimeAlertWhenFinishedQRadioButton->setGeometry(QRect(0, 20, 151, 19));
        realTimeOffQRadioButton = new QRadioButton(realTimeAlertQFrame);
        realTimeOffQRadioButton->setObjectName(QStringLiteral("realTimeOffQRadioButton"));
        realTimeOffQRadioButton->setGeometry(QRect(0, 52, 111, 19));
        realTimeWaitForPauseQRadioButton = new QRadioButton(realTimeAlertQFrame);
        realTimeWaitForPauseQRadioButton->setObjectName(QStringLiteral("realTimeWaitForPauseQRadioButton"));
        realTimeWaitForPauseQRadioButton->setGeometry(QRect(0, 36, 111, 19));
        productionTimeAlertQFrame = new QFrame(timerWindowQFrame);
        productionTimeAlertQFrame->setObjectName(QStringLiteral("productionTimeAlertQFrame"));
        productionTimeAlertQFrame->setGeometry(QRect(40, 210, 161, 71));
        productionTimeAlertQFrame->setFrameShape(QFrame::NoFrame);
        productionTimeAlertQFrame->setFrameShadow(QFrame::Raised);
        productionTimeAlertQLabel = new QLabel(productionTimeAlertQFrame);
        productionTimeAlertQLabel->setObjectName(QStringLiteral("productionTimeAlertQLabel"));
        productionTimeAlertQLabel->setGeometry(QRect(0, 0, 161, 16));
        productionTimeAlertWhenFinishedQRadioButton = new QRadioButton(productionTimeAlertQFrame);
        productionTimeAlertWhenFinishedQRadioButton->setObjectName(QStringLiteral("productionTimeAlertWhenFinishedQRadioButton"));
        productionTimeAlertWhenFinishedQRadioButton->setGeometry(QRect(0, 20, 141, 19));
        productionTimeOffQRadioButton = new QRadioButton(productionTimeAlertQFrame);
        productionTimeOffQRadioButton->setObjectName(QStringLiteral("productionTimeOffQRadioButton"));
        productionTimeOffQRadioButton->setGeometry(QRect(0, 52, 111, 19));
        productionTimeWaitForPauseQRadioButton = new QRadioButton(productionTimeAlertQFrame);
        productionTimeWaitForPauseQRadioButton->setObjectName(QStringLiteral("productionTimeWaitForPauseQRadioButton"));
        productionTimeWaitForPauseQRadioButton->setGeometry(QRect(0, 36, 111, 19));
        productionTimerQFrame = new QFrame(timerWindowQFrame);
        productionTimerQFrame->setObjectName(QStringLiteral("productionTimerQFrame"));
        productionTimerQFrame->setGeometry(QRect(60, 70, 251, 101));
        productionTimerQFrame->setFrameShape(QFrame::NoFrame);
        productionTimerQFrame->setFrameShadow(QFrame::Raised);
        productionTimeMillisecondsQSpinBox = new QSpinBox(productionTimerQFrame);
        productionTimeMillisecondsQSpinBox->setObjectName(QStringLiteral("productionTimeMillisecondsQSpinBox"));
        productionTimeMillisecondsQSpinBox->setGeometry(QRect(180, 20, 61, 51));
        QFont font1;
        font1.setPointSize(24);
        productionTimeMillisecondsQSpinBox->setFont(font1);
        productionTimeMillisecondsQSpinBox->setFrame(false);
        productionTimeMillisecondsQSpinBox->setMaximum(59);
        productionTimeMillisecondsQSpinBox->setValue(0);
        productionTimeQLabel = new QLabel(productionTimerQFrame);
        productionTimeQLabel->setObjectName(QStringLiteral("productionTimeQLabel"));
        productionTimeQLabel->setGeometry(QRect(0, 0, 151, 16));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        productionTimeQLabel->setFont(font2);
        productionTimeSecondsQSpinBox = new QSpinBox(productionTimerQFrame);
        productionTimeSecondsQSpinBox->setObjectName(QStringLiteral("productionTimeSecondsQSpinBox"));
        productionTimeSecondsQSpinBox->setGeometry(QRect(120, 20, 61, 51));
        productionTimeSecondsQSpinBox->setFont(font1);
        productionTimeSecondsQSpinBox->setFrame(false);
        productionTimeSecondsQSpinBox->setMaximum(59);
        productionTimeSecondsQSpinBox->setValue(0);
        productionTimeHoursQSpinBox = new QSpinBox(productionTimerQFrame);
        productionTimeHoursQSpinBox->setObjectName(QStringLiteral("productionTimeHoursQSpinBox"));
        productionTimeHoursQSpinBox->setGeometry(QRect(0, 20, 61, 51));
        productionTimeHoursQSpinBox->setFont(font1);
        productionTimeHoursQSpinBox->setFrame(false);
        productionTimeHoursQSpinBox->setValue(0);
        productionTimeMinutesQSpinBox = new QSpinBox(productionTimerQFrame);
        productionTimeMinutesQSpinBox->setObjectName(QStringLiteral("productionTimeMinutesQSpinBox"));
        productionTimeMinutesQSpinBox->setGeometry(QRect(60, 20, 61, 51));
        productionTimeMinutesQSpinBox->setFont(font1);
        productionTimeMinutesQSpinBox->setFrame(false);
        productionTimeMinutesQSpinBox->setMaximum(59);
        productionTimeMinutesQSpinBox->setValue(0);
        productionTimeDescriptionsQLabel = new QLabel(productionTimerQFrame);
        productionTimeDescriptionsQLabel->setObjectName(QStringLiteral("productionTimeDescriptionsQLabel"));
        productionTimeDescriptionsQLabel->setGeometry(QRect(0, 70, 231, 16));

        retranslateUi(TimerWindowQWidget);

        QMetaObject::connectSlotsByName(TimerWindowQWidget);
    } // setupUi

    void retranslateUi(QWidget *TimerWindowQWidget)
    {
        TimerWindowQWidget->setWindowTitle(QApplication::translate("TimerWindowQWidget", "Tasker - Session", Q_NULLPTR));
        timerQLabel->setText(QApplication::translate("TimerWindowQWidget", "Timer", Q_NULLPTR));
        startTimerQPushButton->setText(QApplication::translate("TimerWindowQWidget", "Start", Q_NULLPTR));
        backQPushButton->setText(QApplication::translate("TimerWindowQWidget", "Back", Q_NULLPTR));
        taskQComboBox->clear();
        taskQComboBox->insertItems(0, QStringList()
         << QApplication::translate("TimerWindowQWidget", "Writing", Q_NULLPTR)
         << QApplication::translate("TimerWindowQWidget", "Compose Music", Q_NULLPTR)
         << QApplication::translate("TimerWindowQWidget", "Custom", Q_NULLPTR)
        );
        taskQLabel->setText(QApplication::translate("TimerWindowQWidget", "Task:", Q_NULLPTR));
        audioQComboBox->clear();
        audioQComboBox->insertItems(0, QStringList()
         << QApplication::translate("TimerWindowQWidget", "Built-In Mic", Q_NULLPTR)
        );
        audioQCheckBox->setText(QApplication::translate("TimerWindowQWidget", "Mic", Q_NULLPTR));
        keyboardQCheckBox->setText(QApplication::translate("TimerWindowQWidget", "Keyboard", Q_NULLPTR));
        listenersQLabel->setText(QApplication::translate("TimerWindowQWidget", "Listeners:", Q_NULLPTR));
        realTimeLabel->setText(QApplication::translate("TimerWindowQWidget", "Real Time: ", Q_NULLPTR));
        realTimeDurationQLineEdit->setText(QApplication::translate("TimerWindowQWidget", "00:00:00:00", Q_NULLPTR));
        realTimeAlertQLabel->setText(QApplication::translate("TimerWindowQWidget", "Real-time Timer Alert", Q_NULLPTR));
        realTimeAlertWhenFinishedQRadioButton->setText(QApplication::translate("TimerWindowQWidget", "Alert when finished", Q_NULLPTR));
        realTimeOffQRadioButton->setText(QApplication::translate("TimerWindowQWidget", "Off", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        realTimeWaitForPauseQRadioButton->setToolTip(QApplication::translate("TimerWindowQWidget", "Waits for you to pause your work before alerting you that your time is up", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        realTimeWaitForPauseQRadioButton->setText(QApplication::translate("TimerWindowQWidget", "Wait for pause", Q_NULLPTR));
        productionTimeAlertQLabel->setText(QApplication::translate("TimerWindowQWidget", "Production Timer Alert", Q_NULLPTR));
        productionTimeAlertWhenFinishedQRadioButton->setText(QApplication::translate("TimerWindowQWidget", "Alert when finished", Q_NULLPTR));
        productionTimeOffQRadioButton->setText(QApplication::translate("TimerWindowQWidget", "Off", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        productionTimeWaitForPauseQRadioButton->setToolTip(QApplication::translate("TimerWindowQWidget", "Waits for you to pause your work before alerting you that your time is up", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        productionTimeWaitForPauseQRadioButton->setText(QApplication::translate("TimerWindowQWidget", "Wait for pause", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        productionTimeMillisecondsQSpinBox->setToolTip(QApplication::translate("TimerWindowQWidget", "Milliseconds", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        productionTimeMillisecondsQSpinBox->setPrefix(QApplication::translate("TimerWindowQWidget", ":", Q_NULLPTR));
        productionTimeQLabel->setText(QApplication::translate("TimerWindowQWidget", "Production Time", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        productionTimeSecondsQSpinBox->setToolTip(QApplication::translate("TimerWindowQWidget", "Seconds", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        productionTimeSecondsQSpinBox->setPrefix(QApplication::translate("TimerWindowQWidget", ":", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        productionTimeHoursQSpinBox->setToolTip(QApplication::translate("TimerWindowQWidget", "Hours", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        productionTimeMinutesQSpinBox->setToolTip(QApplication::translate("TimerWindowQWidget", "Minutes", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        productionTimeMinutesQSpinBox->setPrefix(QApplication::translate("TimerWindowQWidget", ":", Q_NULLPTR));
        productionTimeDescriptionsQLabel->setText(QApplication::translate("TimerWindowQWidget", "Hrs           Min           Sec          mSec", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TimerWindowQWidget: public Ui_TimerWindowQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERWINDOWQWIDGET_H

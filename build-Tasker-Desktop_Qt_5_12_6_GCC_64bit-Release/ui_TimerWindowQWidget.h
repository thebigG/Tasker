/********************************************************************************
** Form generated from reading UI file 'TimerWindowQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMERWINDOWQWIDGET_H
#define UI_TIMERWINDOWQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimerWindowQWidget
{
public:
    QPushButton *backQPushButton;
    QWidget *productionTimeAlertQWidget;
    QLabel *productionTimeAlertQLabel;
    QComboBox *comboBox;
    QWidget *productionTimerQWidget;
    QLabel *productionTimeQLabel;
    QSpinBox *productionTimeHoursQSpinBox;
    QSpinBox *productionTimeMinutesQSpinBox;
    QLabel *productionTimeDescriptionsQLabel;
    QPushButton *startTimerQPushButton;
    QWidget *taskListenersQWidget;
    QComboBox *taskQComboBox;
    QLabel *taskQLabel;
    QComboBox *audioQComboBox;
    QCheckBox *audioQCheckBox;
    QCheckBox *keyboardQCheckBox;
    QLabel *listenersQLabel;
    QLabel *timerQLabel;

    void setupUi(QWidget *TimerWindowQWidget)
    {
        if (TimerWindowQWidget->objectName().isEmpty())
            TimerWindowQWidget->setObjectName(QString::fromUtf8("TimerWindowQWidget"));
        TimerWindowQWidget->resize(450, 450);
        TimerWindowQWidget->setMinimumSize(QSize(450, 450));
        TimerWindowQWidget->setMaximumSize(QSize(450, 450));
        backQPushButton = new QPushButton(TimerWindowQWidget);
        backQPushButton->setObjectName(QString::fromUtf8("backQPushButton"));
        backQPushButton->setGeometry(QRect(240, 420, 204, 24));
        productionTimeAlertQWidget = new QWidget(TimerWindowQWidget);
        productionTimeAlertQWidget->setObjectName(QString::fromUtf8("productionTimeAlertQWidget"));
        productionTimeAlertQWidget->setGeometry(QRect(10, 200, 204, 92));
        productionTimeAlertQLabel = new QLabel(productionTimeAlertQWidget);
        productionTimeAlertQLabel->setObjectName(QString::fromUtf8("productionTimeAlertQLabel"));
        productionTimeAlertQLabel->setGeometry(QRect(0, 0, 161, 16));
        comboBox = new QComboBox(productionTimeAlertQWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 30, 79, 24));
        productionTimerQWidget = new QWidget(TimerWindowQWidget);
        productionTimerQWidget->setObjectName(QString::fromUtf8("productionTimerQWidget"));
        productionTimerQWidget->setGeometry(QRect(20, 100, 121, 91));
        productionTimeQLabel = new QLabel(productionTimerQWidget);
        productionTimeQLabel->setObjectName(QString::fromUtf8("productionTimeQLabel"));
        productionTimeQLabel->setGeometry(QRect(0, 0, 151, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        productionTimeQLabel->setFont(font);
        productionTimeHoursQSpinBox = new QSpinBox(productionTimerQWidget);
        productionTimeHoursQSpinBox->setObjectName(QString::fromUtf8("productionTimeHoursQSpinBox"));
        productionTimeHoursQSpinBox->setGeometry(QRect(0, 20, 61, 51));
        QFont font1;
        font1.setPointSize(24);
        productionTimeHoursQSpinBox->setFont(font1);
        productionTimeHoursQSpinBox->setFrame(false);
        productionTimeHoursQSpinBox->setValue(0);
        productionTimeMinutesQSpinBox = new QSpinBox(productionTimerQWidget);
        productionTimeMinutesQSpinBox->setObjectName(QString::fromUtf8("productionTimeMinutesQSpinBox"));
        productionTimeMinutesQSpinBox->setGeometry(QRect(60, 20, 61, 51));
        productionTimeMinutesQSpinBox->setFont(font1);
        productionTimeMinutesQSpinBox->setFrame(false);
        productionTimeMinutesQSpinBox->setMaximum(59);
        productionTimeMinutesQSpinBox->setValue(0);
        productionTimeDescriptionsQLabel = new QLabel(productionTimerQWidget);
        productionTimeDescriptionsQLabel->setObjectName(QString::fromUtf8("productionTimeDescriptionsQLabel"));
        productionTimeDescriptionsQLabel->setGeometry(QRect(0, 70, 101, 16));
        startTimerQPushButton = new QPushButton(TimerWindowQWidget);
        startTimerQPushButton->setObjectName(QString::fromUtf8("startTimerQPushButton"));
        startTimerQPushButton->setGeometry(QRect(0, 420, 204, 24));
        taskListenersQWidget = new QWidget(TimerWindowQWidget);
        taskListenersQWidget->setObjectName(QString::fromUtf8("taskListenersQWidget"));
        taskListenersQWidget->setGeometry(QRect(10, 290, 414, 111));
        taskQComboBox = new QComboBox(taskListenersQWidget);
        taskQComboBox->addItem(QString());
        taskQComboBox->addItem(QString());
        taskQComboBox->addItem(QString());
        taskQComboBox->setObjectName(QString::fromUtf8("taskQComboBox"));
        taskQComboBox->setGeometry(QRect(150, 0, 141, 25));
        taskQLabel = new QLabel(taskListenersQWidget);
        taskQLabel->setObjectName(QString::fromUtf8("taskQLabel"));
        taskQLabel->setGeometry(QRect(100, 0, 31, 25));
        audioQComboBox = new QComboBox(taskListenersQWidget);
        audioQComboBox->addItem(QString());
        audioQComboBox->setObjectName(QString::fromUtf8("audioQComboBox"));
        audioQComboBox->setGeometry(QRect(50, 70, 121, 25));
        audioQCheckBox = new QCheckBox(taskListenersQWidget);
        audioQCheckBox->setObjectName(QString::fromUtf8("audioQCheckBox"));
        audioQCheckBox->setGeometry(QRect(0, 70, 83, 25));
        keyboardQCheckBox = new QCheckBox(taskListenersQWidget);
        keyboardQCheckBox->setObjectName(QString::fromUtf8("keyboardQCheckBox"));
        keyboardQCheckBox->setGeometry(QRect(0, 50, 83, 22));
        listenersQLabel = new QLabel(taskListenersQWidget);
        listenersQLabel->setObjectName(QString::fromUtf8("listenersQLabel"));
        listenersQLabel->setGeometry(QRect(0, 30, 58, 16));
        timerQLabel = new QLabel(TimerWindowQWidget);
        timerQLabel->setObjectName(QString::fromUtf8("timerQLabel"));
        timerQLabel->setGeometry(QRect(10, 20, 121, 71));
        QFont font2;
        font2.setPointSize(14);
        timerQLabel->setFont(font2);

        retranslateUi(TimerWindowQWidget);

        QMetaObject::connectSlotsByName(TimerWindowQWidget);
    } // setupUi

    void retranslateUi(QWidget *TimerWindowQWidget)
    {
        TimerWindowQWidget->setWindowTitle(QApplication::translate("TimerWindowQWidget", "Tasker - Session", nullptr));
        backQPushButton->setText(QApplication::translate("TimerWindowQWidget", "Cancel", nullptr));
        productionTimeAlertQLabel->setText(QApplication::translate("TimerWindowQWidget", "Notify me when done", nullptr));
        comboBox->setItemText(0, QApplication::translate("TimerWindowQWidget", "Yes", nullptr));
        comboBox->setItemText(1, QApplication::translate("TimerWindowQWidget", "No", nullptr));

        productionTimeQLabel->setText(QApplication::translate("TimerWindowQWidget", "Goal", nullptr));
#ifndef QT_NO_TOOLTIP
        productionTimeHoursQSpinBox->setToolTip(QApplication::translate("TimerWindowQWidget", "Hours", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        productionTimeMinutesQSpinBox->setToolTip(QApplication::translate("TimerWindowQWidget", "Minutes", nullptr));
#endif // QT_NO_TOOLTIP
        productionTimeMinutesQSpinBox->setPrefix(QApplication::translate("TimerWindowQWidget", ":", nullptr));
        productionTimeDescriptionsQLabel->setText(QApplication::translate("TimerWindowQWidget", "Hrs         Mins", nullptr));
        startTimerQPushButton->setText(QApplication::translate("TimerWindowQWidget", "Start", nullptr));
        taskQComboBox->setItemText(0, QApplication::translate("TimerWindowQWidget", "Writing", nullptr));
        taskQComboBox->setItemText(1, QApplication::translate("TimerWindowQWidget", "Compose Music", nullptr));
        taskQComboBox->setItemText(2, QApplication::translate("TimerWindowQWidget", "Custom", nullptr));

        taskQLabel->setText(QApplication::translate("TimerWindowQWidget", "Task:", nullptr));
        audioQComboBox->setItemText(0, QApplication::translate("TimerWindowQWidget", "Built-In Mic", nullptr));

        audioQCheckBox->setText(QApplication::translate("TimerWindowQWidget", "Mic", nullptr));
        keyboardQCheckBox->setText(QApplication::translate("TimerWindowQWidget", "Keyboard", nullptr));
        listenersQLabel->setText(QApplication::translate("TimerWindowQWidget", "Listeners:", nullptr));
        timerQLabel->setText(QApplication::translate("TimerWindowQWidget", "New Session", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimerWindowQWidget: public Ui_TimerWindowQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERWINDOWQWIDGET_H

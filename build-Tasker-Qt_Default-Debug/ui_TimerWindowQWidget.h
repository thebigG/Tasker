/********************************************************************************
** Form generated from reading UI file 'TimerWindowQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
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
#include <QtWidgets/QHeaderView>
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
            TimerWindowQWidget->setObjectName(QStringLiteral("TimerWindowQWidget"));
        TimerWindowQWidget->resize(450, 450);
        TimerWindowQWidget->setMinimumSize(QSize(450, 450));
        TimerWindowQWidget->setMaximumSize(QSize(450, 450));
        backQPushButton = new QPushButton(TimerWindowQWidget);
        backQPushButton->setObjectName(QStringLiteral("backQPushButton"));
        backQPushButton->setGeometry(QRect(240, 420, 204, 24));
        productionTimeAlertQWidget = new QWidget(TimerWindowQWidget);
        productionTimeAlertQWidget->setObjectName(QStringLiteral("productionTimeAlertQWidget"));
        productionTimeAlertQWidget->setGeometry(QRect(10, 200, 204, 92));
        productionTimeAlertQLabel = new QLabel(productionTimeAlertQWidget);
        productionTimeAlertQLabel->setObjectName(QStringLiteral("productionTimeAlertQLabel"));
        productionTimeAlertQLabel->setGeometry(QRect(0, 0, 161, 16));
        comboBox = new QComboBox(productionTimeAlertQWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 30, 79, 24));
        productionTimerQWidget = new QWidget(TimerWindowQWidget);
        productionTimerQWidget->setObjectName(QStringLiteral("productionTimerQWidget"));
        productionTimerQWidget->setGeometry(QRect(20, 100, 121, 91));
        productionTimeQLabel = new QLabel(productionTimerQWidget);
        productionTimeQLabel->setObjectName(QStringLiteral("productionTimeQLabel"));
        productionTimeQLabel->setGeometry(QRect(0, 0, 151, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        productionTimeQLabel->setFont(font);
        productionTimeHoursQSpinBox = new QSpinBox(productionTimerQWidget);
        productionTimeHoursQSpinBox->setObjectName(QStringLiteral("productionTimeHoursQSpinBox"));
        productionTimeHoursQSpinBox->setGeometry(QRect(0, 20, 61, 51));
        QFont font1;
        font1.setPointSize(24);
        productionTimeHoursQSpinBox->setFont(font1);
        productionTimeHoursQSpinBox->setFrame(false);
        productionTimeHoursQSpinBox->setValue(0);
        productionTimeMinutesQSpinBox = new QSpinBox(productionTimerQWidget);
        productionTimeMinutesQSpinBox->setObjectName(QStringLiteral("productionTimeMinutesQSpinBox"));
        productionTimeMinutesQSpinBox->setGeometry(QRect(60, 20, 61, 51));
        productionTimeMinutesQSpinBox->setFont(font1);
        productionTimeMinutesQSpinBox->setFrame(false);
        productionTimeMinutesQSpinBox->setMaximum(59);
        productionTimeMinutesQSpinBox->setValue(0);
        productionTimeDescriptionsQLabel = new QLabel(productionTimerQWidget);
        productionTimeDescriptionsQLabel->setObjectName(QStringLiteral("productionTimeDescriptionsQLabel"));
        productionTimeDescriptionsQLabel->setGeometry(QRect(0, 70, 101, 16));
        startTimerQPushButton = new QPushButton(TimerWindowQWidget);
        startTimerQPushButton->setObjectName(QStringLiteral("startTimerQPushButton"));
        startTimerQPushButton->setGeometry(QRect(0, 420, 204, 24));
        taskListenersQWidget = new QWidget(TimerWindowQWidget);
        taskListenersQWidget->setObjectName(QStringLiteral("taskListenersQWidget"));
        taskListenersQWidget->setGeometry(QRect(10, 290, 414, 111));
        taskQComboBox = new QComboBox(taskListenersQWidget);
        taskQComboBox->setObjectName(QStringLiteral("taskQComboBox"));
        taskQComboBox->setGeometry(QRect(150, 0, 141, 25));
        taskQLabel = new QLabel(taskListenersQWidget);
        taskQLabel->setObjectName(QStringLiteral("taskQLabel"));
        taskQLabel->setGeometry(QRect(100, 0, 31, 25));
        audioQComboBox = new QComboBox(taskListenersQWidget);
        audioQComboBox->setObjectName(QStringLiteral("audioQComboBox"));
        audioQComboBox->setGeometry(QRect(50, 70, 121, 25));
        audioQCheckBox = new QCheckBox(taskListenersQWidget);
        audioQCheckBox->setObjectName(QStringLiteral("audioQCheckBox"));
        audioQCheckBox->setGeometry(QRect(0, 70, 83, 25));
        keyboardQCheckBox = new QCheckBox(taskListenersQWidget);
        keyboardQCheckBox->setObjectName(QStringLiteral("keyboardQCheckBox"));
        keyboardQCheckBox->setGeometry(QRect(0, 50, 83, 22));
        listenersQLabel = new QLabel(taskListenersQWidget);
        listenersQLabel->setObjectName(QStringLiteral("listenersQLabel"));
        listenersQLabel->setGeometry(QRect(0, 30, 58, 16));
        timerQLabel = new QLabel(TimerWindowQWidget);
        timerQLabel->setObjectName(QStringLiteral("timerQLabel"));
        timerQLabel->setGeometry(QRect(10, 20, 121, 71));
        QFont font2;
        font2.setPointSize(14);
        timerQLabel->setFont(font2);

        retranslateUi(TimerWindowQWidget);

        QMetaObject::connectSlotsByName(TimerWindowQWidget);
    } // setupUi

    void retranslateUi(QWidget *TimerWindowQWidget)
    {
        TimerWindowQWidget->setWindowTitle(QApplication::translate("TimerWindowQWidget", "Tasker - Session", Q_NULLPTR));
        backQPushButton->setText(QApplication::translate("TimerWindowQWidget", "Cancel", Q_NULLPTR));
        productionTimeAlertQLabel->setText(QApplication::translate("TimerWindowQWidget", "Notify me when done", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("TimerWindowQWidget", "Yes", Q_NULLPTR)
         << QApplication::translate("TimerWindowQWidget", "No", Q_NULLPTR)
        );
        productionTimeQLabel->setText(QApplication::translate("TimerWindowQWidget", "Goal", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        productionTimeHoursQSpinBox->setToolTip(QApplication::translate("TimerWindowQWidget", "Hours", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        productionTimeMinutesQSpinBox->setToolTip(QApplication::translate("TimerWindowQWidget", "Minutes", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        productionTimeMinutesQSpinBox->setPrefix(QApplication::translate("TimerWindowQWidget", ":", Q_NULLPTR));
        productionTimeDescriptionsQLabel->setText(QApplication::translate("TimerWindowQWidget", "Hrs         Mins", Q_NULLPTR));
        startTimerQPushButton->setText(QApplication::translate("TimerWindowQWidget", "Start", Q_NULLPTR));
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
        timerQLabel->setText(QApplication::translate("TimerWindowQWidget", "New Session", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TimerWindowQWidget: public Ui_TimerWindowQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERWINDOWQWIDGET_H

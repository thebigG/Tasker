/********************************************************************************
** Form generated from reading UI file 'NewSessionQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSESSIONQWIDGET_H
#define UI_NEWSESSIONQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewSessionQWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *backQPushButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGroupBox *productionTimeAlertQGroupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QGroupBox *taskListenersQGroupBox;
    QGridLayout *gridLayout_4;
    QComboBox *audioQComboBox;
    QRadioButton *keyboardQRadioButton;
    QRadioButton *audioQRadioButton;
    QRadioButton *mouseQRadioButton;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QLabel *goalQLabel;
    QWidget *TaskContainerQWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *taskQLabel;
    QLineEdit *taskLineEdit;
    QPushButton *startTimerQPushButton;

    void setupUi(QWidget *NewSessionQWidget)
    {
        if (NewSessionQWidget->objectName().isEmpty())
            NewSessionQWidget->setObjectName(QString::fromUtf8("NewSessionQWidget"));
        NewSessionQWidget->setWindowModality(Qt::ApplicationModal);
        NewSessionQWidget->resize(450, 450);
        NewSessionQWidget->setMinimumSize(QSize(450, 450));
        NewSessionQWidget->setMaximumSize(QSize(450, 450));
        NewSessionQWidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(NewSessionQWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        backQPushButton = new QPushButton(NewSessionQWidget);
        backQPushButton->setObjectName(QString::fromUtf8("backQPushButton"));
        backQPushButton->setMaximumSize(QSize(110, 30));

        gridLayout->addWidget(backQPushButton, 6, 2, 1, 1);

        groupBox = new QGroupBox(NewSessionQWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(450, 0));
        groupBox->setMaximumSize(QSize(450, 200));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        productionTimeAlertQGroupBox = new QGroupBox(groupBox);
        productionTimeAlertQGroupBox->setObjectName(QString::fromUtf8("productionTimeAlertQGroupBox"));
        productionTimeAlertQGroupBox->setMaximumSize(QSize(400, 100));
        productionTimeAlertQGroupBox->setLayoutDirection(Qt::LeftToRight);
        productionTimeAlertQGroupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(productionTimeAlertQGroupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox = new QCheckBox(productionTimeAlertQGroupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);


        gridLayout_2->addWidget(productionTimeAlertQGroupBox, 0, 1, 1, 1);

        taskListenersQGroupBox = new QGroupBox(groupBox);
        taskListenersQGroupBox->setObjectName(QString::fromUtf8("taskListenersQGroupBox"));
        taskListenersQGroupBox->setMaximumSize(QSize(200, 100));
        taskListenersQGroupBox->setStyleSheet(QString::fromUtf8(""));
        taskListenersQGroupBox->setCheckable(false);
        gridLayout_4 = new QGridLayout(taskListenersQGroupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        audioQComboBox = new QComboBox(taskListenersQGroupBox);
        audioQComboBox->addItem(QString());
        audioQComboBox->setObjectName(QString::fromUtf8("audioQComboBox"));
        audioQComboBox->setMinimumSize(QSize(0, 25));
        audioQComboBox->setMaximumSize(QSize(100, 200));

        gridLayout_4->addWidget(audioQComboBox, 2, 1, 1, 1);

        keyboardQRadioButton = new QRadioButton(taskListenersQGroupBox);
        keyboardQRadioButton->setObjectName(QString::fromUtf8("keyboardQRadioButton"));

        gridLayout_4->addWidget(keyboardQRadioButton, 0, 0, 1, 2);

        audioQRadioButton = new QRadioButton(taskListenersQGroupBox);
        audioQRadioButton->setObjectName(QString::fromUtf8("audioQRadioButton"));

        gridLayout_4->addWidget(audioQRadioButton, 2, 0, 1, 1);

        mouseQRadioButton = new QRadioButton(taskListenersQGroupBox);
        mouseQRadioButton->setObjectName(QString::fromUtf8("mouseQRadioButton"));

        gridLayout_4->addWidget(mouseQRadioButton, 1, 0, 1, 1);


        gridLayout_2->addWidget(taskListenersQGroupBox, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

        widget = new QWidget(NewSessionQWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(450, 200));
        widget->setMaximumSize(QSize(450, 200));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        goalQLabel = new QLabel(widget);
        goalQLabel->setObjectName(QString::fromUtf8("goalQLabel"));
        goalQLabel->setMaximumSize(QSize(200, 100));
        QFont font;
        font.setPointSize(14);
        goalQLabel->setFont(font);
        goalQLabel->setWordWrap(true);

        gridLayout_3->addWidget(goalQLabel, 1, 0, 1, 1);

        TaskContainerQWidget = new QWidget(widget);
        TaskContainerQWidget->setObjectName(QString::fromUtf8("TaskContainerQWidget"));
        TaskContainerQWidget->setMaximumSize(QSize(200, 50));
        horizontalLayout = new QHBoxLayout(TaskContainerQWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        taskQLabel = new QLabel(TaskContainerQWidget);
        taskQLabel->setObjectName(QString::fromUtf8("taskQLabel"));
        taskQLabel->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(taskQLabel);

        taskLineEdit = new QLineEdit(TaskContainerQWidget);
        taskLineEdit->setObjectName(QString::fromUtf8("taskLineEdit"));

        horizontalLayout->addWidget(taskLineEdit);


        gridLayout_3->addWidget(TaskContainerQWidget, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        startTimerQPushButton = new QPushButton(NewSessionQWidget);
        startTimerQPushButton->setObjectName(QString::fromUtf8("startTimerQPushButton"));
        startTimerQPushButton->setMaximumSize(QSize(110, 30));

        gridLayout->addWidget(startTimerQPushButton, 6, 0, 1, 1);


        retranslateUi(NewSessionQWidget);

        QMetaObject::connectSlotsByName(NewSessionQWidget);
    } // setupUi

    void retranslateUi(QWidget *NewSessionQWidget)
    {
        NewSessionQWidget->setWindowTitle(QCoreApplication::translate("NewSessionQWidget", "Tasker - Session", nullptr));
        backQPushButton->setText(QCoreApplication::translate("NewSessionQWidget", "Cancel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("NewSessionQWidget", "Perferences", nullptr));
        productionTimeAlertQGroupBox->setTitle(QCoreApplication::translate("NewSessionQWidget", "Others", nullptr));
        checkBox->setText(QCoreApplication::translate("NewSessionQWidget", "Notify me when done", nullptr));
        taskListenersQGroupBox->setTitle(QCoreApplication::translate("NewSessionQWidget", "Hooks", nullptr));
        audioQComboBox->setItemText(0, QCoreApplication::translate("NewSessionQWidget", "Built-In Mic", nullptr));

        keyboardQRadioButton->setText(QCoreApplication::translate("NewSessionQWidget", "Keyboard", nullptr));
        audioQRadioButton->setText(QCoreApplication::translate("NewSessionQWidget", "Mic", nullptr));
        mouseQRadioButton->setText(QCoreApplication::translate("NewSessionQWidget", "Mouse", nullptr));
        goalQLabel->setText(QCoreApplication::translate("NewSessionQWidget", "Goal: Play guitar for 1h3", nullptr));
        taskQLabel->setText(QCoreApplication::translate("NewSessionQWidget", "Task:", nullptr));
        taskLineEdit->setText(QString());
        taskLineEdit->setPlaceholderText(QCoreApplication::translate("NewSessionQWidget", "Write, Draw, Music, etc", nullptr));
        startTimerQPushButton->setText(QCoreApplication::translate("NewSessionQWidget", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewSessionQWidget: public Ui_NewSessionQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSESSIONQWIDGET_H

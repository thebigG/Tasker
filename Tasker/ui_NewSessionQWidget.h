/********************************************************************************
** Form generated from reading UI file 'NewSessionQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSESSIONQWIDGET_H
#define UI_NEWSESSIONQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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
    QCheckBox *audioQCheckBox;
    QCheckBox *keyboardQCheckBox;
    QCheckBox *mouseQCheckBox;
    QComboBox *audioQComboBox;
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
            NewSessionQWidget->setObjectName(QStringLiteral("NewSessionQWidget"));
        NewSessionQWidget->setWindowModality(Qt::ApplicationModal);
        NewSessionQWidget->resize(450, 450);
        NewSessionQWidget->setMinimumSize(QSize(450, 450));
        NewSessionQWidget->setMaximumSize(QSize(450, 450));
        NewSessionQWidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(NewSessionQWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        backQPushButton = new QPushButton(NewSessionQWidget);
        backQPushButton->setObjectName(QStringLiteral("backQPushButton"));
        backQPushButton->setMaximumSize(QSize(110, 30));

        gridLayout->addWidget(backQPushButton, 6, 2, 1, 1);

        groupBox = new QGroupBox(NewSessionQWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(450, 0));
        groupBox->setMaximumSize(QSize(450, 200));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        productionTimeAlertQGroupBox = new QGroupBox(groupBox);
        productionTimeAlertQGroupBox->setObjectName(QStringLiteral("productionTimeAlertQGroupBox"));
        productionTimeAlertQGroupBox->setMaximumSize(QSize(400, 100));
        productionTimeAlertQGroupBox->setLayoutDirection(Qt::LeftToRight);
        productionTimeAlertQGroupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(productionTimeAlertQGroupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox = new QCheckBox(productionTimeAlertQGroupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);


        gridLayout_2->addWidget(productionTimeAlertQGroupBox, 0, 1, 1, 1);

        taskListenersQGroupBox = new QGroupBox(groupBox);
        taskListenersQGroupBox->setObjectName(QStringLiteral("taskListenersQGroupBox"));
        taskListenersQGroupBox->setMaximumSize(QSize(200, 100));
        taskListenersQGroupBox->setStyleSheet(QStringLiteral(""));
        taskListenersQGroupBox->setCheckable(false);
        gridLayout_4 = new QGridLayout(taskListenersQGroupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        audioQCheckBox = new QCheckBox(taskListenersQGroupBox);
        audioQCheckBox->setObjectName(QStringLiteral("audioQCheckBox"));

        gridLayout_4->addWidget(audioQCheckBox, 2, 0, 1, 1);

        keyboardQCheckBox = new QCheckBox(taskListenersQGroupBox);
        keyboardQCheckBox->setObjectName(QStringLiteral("keyboardQCheckBox"));
        keyboardQCheckBox->setTristate(false);

        gridLayout_4->addWidget(keyboardQCheckBox, 0, 0, 1, 2);

        mouseQCheckBox = new QCheckBox(taskListenersQGroupBox);
        mouseQCheckBox->setObjectName(QStringLiteral("mouseQCheckBox"));

        gridLayout_4->addWidget(mouseQCheckBox, 1, 0, 1, 1);

        audioQComboBox = new QComboBox(taskListenersQGroupBox);
        audioQComboBox->setObjectName(QStringLiteral("audioQComboBox"));
        audioQComboBox->setMinimumSize(QSize(0, 25));
        audioQComboBox->setMaximumSize(QSize(100, 200));

        gridLayout_4->addWidget(audioQComboBox, 2, 1, 1, 1);


        gridLayout_2->addWidget(taskListenersQGroupBox, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

        widget = new QWidget(NewSessionQWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(450, 200));
        widget->setMaximumSize(QSize(450, 200));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        goalQLabel = new QLabel(widget);
        goalQLabel->setObjectName(QStringLiteral("goalQLabel"));
        goalQLabel->setMaximumSize(QSize(200, 100));
        QFont font;
        font.setPointSize(14);
        goalQLabel->setFont(font);
        goalQLabel->setWordWrap(true);

        gridLayout_3->addWidget(goalQLabel, 1, 0, 1, 1);

        TaskContainerQWidget = new QWidget(widget);
        TaskContainerQWidget->setObjectName(QStringLiteral("TaskContainerQWidget"));
        TaskContainerQWidget->setMaximumSize(QSize(200, 50));
        horizontalLayout = new QHBoxLayout(TaskContainerQWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        taskQLabel = new QLabel(TaskContainerQWidget);
        taskQLabel->setObjectName(QStringLiteral("taskQLabel"));
        taskQLabel->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(taskQLabel);

        taskLineEdit = new QLineEdit(TaskContainerQWidget);
        taskLineEdit->setObjectName(QStringLiteral("taskLineEdit"));

        horizontalLayout->addWidget(taskLineEdit);


        gridLayout_3->addWidget(TaskContainerQWidget, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        startTimerQPushButton = new QPushButton(NewSessionQWidget);
        startTimerQPushButton->setObjectName(QStringLiteral("startTimerQPushButton"));
        startTimerQPushButton->setMaximumSize(QSize(110, 30));

        gridLayout->addWidget(startTimerQPushButton, 6, 0, 1, 1);


        retranslateUi(NewSessionQWidget);

        QMetaObject::connectSlotsByName(NewSessionQWidget);
    } // setupUi

    void retranslateUi(QWidget *NewSessionQWidget)
    {
        NewSessionQWidget->setWindowTitle(QApplication::translate("NewSessionQWidget", "Tasker - Session", Q_NULLPTR));
        backQPushButton->setText(QApplication::translate("NewSessionQWidget", "Cancel", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("NewSessionQWidget", "Perferences", Q_NULLPTR));
        productionTimeAlertQGroupBox->setTitle(QApplication::translate("NewSessionQWidget", "Others", Q_NULLPTR));
        checkBox->setText(QApplication::translate("NewSessionQWidget", "Notify me when done", Q_NULLPTR));
        taskListenersQGroupBox->setTitle(QApplication::translate("NewSessionQWidget", "Hooks", Q_NULLPTR));
        audioQCheckBox->setText(QApplication::translate("NewSessionQWidget", "Mic", Q_NULLPTR));
        keyboardQCheckBox->setText(QApplication::translate("NewSessionQWidget", "Keyboard", Q_NULLPTR));
        mouseQCheckBox->setText(QApplication::translate("NewSessionQWidget", "Mouse", Q_NULLPTR));
        audioQComboBox->clear();
        audioQComboBox->insertItems(0, QStringList()
         << QApplication::translate("NewSessionQWidget", "Built-In Mic", Q_NULLPTR)
        );
        goalQLabel->setText(QApplication::translate("NewSessionQWidget", "Goal: Play guitar for 1h3", Q_NULLPTR));
        taskQLabel->setText(QApplication::translate("NewSessionQWidget", "Task:", Q_NULLPTR));
        taskLineEdit->setText(QString());
        taskLineEdit->setPlaceholderText(QApplication::translate("NewSessionQWidget", "Write, Draw, Music, etc", Q_NULLPTR));
        startTimerQPushButton->setText(QApplication::translate("NewSessionQWidget", "Start", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewSessionQWidget: public Ui_NewSessionQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSESSIONQWIDGET_H

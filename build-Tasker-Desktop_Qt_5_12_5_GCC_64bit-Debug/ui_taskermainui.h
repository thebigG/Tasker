/********************************************************************************
** Form generated from reading UI file 'taskermainui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKERMAINUI_H
#define UI_TASKERMAINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskerMainUI
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TaskerMainUI)
    {
        if (TaskerMainUI->objectName().isEmpty())
            TaskerMainUI->setObjectName(QString::fromUtf8("TaskerMainUI"));
        TaskerMainUI->resize(800, 600);
        centralwidget = new QWidget(TaskerMainUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TaskerMainUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TaskerMainUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        TaskerMainUI->setMenuBar(menubar);
        statusbar = new QStatusBar(TaskerMainUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TaskerMainUI->setStatusBar(statusbar);

        retranslateUi(TaskerMainUI);

        QMetaObject::connectSlotsByName(TaskerMainUI);
    } // setupUi

    void retranslateUi(QMainWindow *TaskerMainUI)
    {
        TaskerMainUI->setWindowTitle(QApplication::translate("TaskerMainUI", "TaskerMainUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskerMainUI: public Ui_TaskerMainUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKERMAINUI_H

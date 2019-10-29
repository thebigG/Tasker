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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskerMainUI
{
public:
    QWidget *centralwidget;
    QTimeEdit *timeEdit;
    QMenuBar *newmenu;
    QMenu *menuHello;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TaskerMainUI)
    {
        if (TaskerMainUI->objectName().isEmpty())
            TaskerMainUI->setObjectName(QString::fromUtf8("TaskerMainUI"));
        TaskerMainUI->resize(800, 600);
        centralwidget = new QWidget(TaskerMainUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        timeEdit = new QTimeEdit(centralwidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(170, 90, 118, 25));
        TaskerMainUI->setCentralWidget(centralwidget);
        newmenu = new QMenuBar(TaskerMainUI);
        newmenu->setObjectName(QString::fromUtf8("newmenu"));
        newmenu->setGeometry(QRect(0, 0, 800, 21));
        menuHello = new QMenu(newmenu);
        menuHello->setObjectName(QString::fromUtf8("menuHello"));
        TaskerMainUI->setMenuBar(newmenu);
        statusbar = new QStatusBar(TaskerMainUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TaskerMainUI->setStatusBar(statusbar);

        newmenu->addAction(menuHello->menuAction());

        retranslateUi(TaskerMainUI);

        QMetaObject::connectSlotsByName(TaskerMainUI);
    } // setupUi

    void retranslateUi(QMainWindow *TaskerMainUI)
    {
        TaskerMainUI->setWindowTitle(QApplication::translate("TaskerMainUI", "TaskerMainUI", nullptr));
        menuHello->setTitle(QApplication::translate("TaskerMainUI", "Hello", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskerMainUI: public Ui_TaskerMainUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKERMAINUI_H

/********************************************************************************
** Form generated from reading UI file 'TaskerUIMainWindowQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKERUIMAINWINDOWQWIDGET_H
#define UI_TASKERUIMAINWINDOWQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskerUIMainWindowQWidget
{
public:
    QFrame *welcomeQFrame;
    QPushButton *makeCommitmentQPushButton;
    QPushButton *quickSessionQPushButton;
    QLabel *welcomeDescriptionQLabel;

    void setupUi(QWidget *TaskerUIMainWindowQWidget)
    {
        if (TaskerUIMainWindowQWidget->objectName().isEmpty())
            TaskerUIMainWindowQWidget->setObjectName(QString::fromUtf8("TaskerUIMainWindowQWidget"));
        TaskerUIMainWindowQWidget->resize(640, 90);
        welcomeQFrame = new QFrame(TaskerUIMainWindowQWidget);
        welcomeQFrame->setObjectName(QString::fromUtf8("welcomeQFrame"));
        welcomeQFrame->setGeometry(QRect(0, 0, 640, 90));
        welcomeQFrame->setFrameShape(QFrame::StyledPanel);
        welcomeQFrame->setFrameShadow(QFrame::Raised);
        makeCommitmentQPushButton = new QPushButton(welcomeQFrame);
        makeCommitmentQPushButton->setObjectName(QString::fromUtf8("makeCommitmentQPushButton"));
        makeCommitmentQPushButton->setGeometry(QRect(128, 50, 130, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        makeCommitmentQPushButton->setFont(font);
        quickSessionQPushButton = new QPushButton(welcomeQFrame);
        quickSessionQPushButton->setObjectName(QString::fromUtf8("quickSessionQPushButton"));
        quickSessionQPushButton->setGeometry(QRect(384, 50, 130, 30));
        QFont font1;
        font1.setPointSize(12);
        quickSessionQPushButton->setFont(font1);
        welcomeDescriptionQLabel = new QLabel(welcomeQFrame);
        welcomeDescriptionQLabel->setObjectName(QString::fromUtf8("welcomeDescriptionQLabel"));
        welcomeDescriptionQLabel->setGeometry(QRect(180, 10, 271, 20));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        welcomeDescriptionQLabel->setFont(font2);
        welcomeDescriptionQLabel->setScaledContents(true);

        retranslateUi(TaskerUIMainWindowQWidget);

        QMetaObject::connectSlotsByName(TaskerUIMainWindowQWidget);
    } // setupUi

    void retranslateUi(QWidget *TaskerUIMainWindowQWidget)
    {
        TaskerUIMainWindowQWidget->setWindowTitle(QApplication::translate("TaskerUIMainWindowQWidget", "Tasker", nullptr));
        makeCommitmentQPushButton->setText(QApplication::translate("TaskerUIMainWindowQWidget", "Make Commitment", nullptr));
        quickSessionQPushButton->setText(QApplication::translate("TaskerUIMainWindowQWidget", "Quick Session", nullptr));
        welcomeDescriptionQLabel->setText(QApplication::translate("TaskerUIMainWindowQWidget", "You have no commitments at this time.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskerUIMainWindowQWidget: public Ui_TaskerUIMainWindowQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKERUIMAINWINDOWQWIDGET_H

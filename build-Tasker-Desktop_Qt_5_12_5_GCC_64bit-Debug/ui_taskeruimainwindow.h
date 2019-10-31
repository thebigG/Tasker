/********************************************************************************
** Form generated from reading UI file 'taskeruimainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKERUIMAINWINDOW_H
#define UI_TASKERUIMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskerUIMainWindow
{
public:
    QFrame *QFrame_Welcome;
    QPushButton *QPushButton_MakeCommitment;
    QPushButton *QPushButton_QuickSession;
    QLabel *QLabel_Welcome;

    void setupUi(QWidget *TaskerUIMainWindow)
    {
        if (TaskerUIMainWindow->objectName().isEmpty())
            TaskerUIMainWindow->setObjectName(QString::fromUtf8("TaskerUIMainWindow"));
        TaskerUIMainWindow->resize(640, 90);
        QFrame_Welcome = new QFrame(TaskerUIMainWindow);
        QFrame_Welcome->setObjectName(QString::fromUtf8("QFrame_Welcome"));
        QFrame_Welcome->setGeometry(QRect(0, 0, 640, 90));
        QFrame_Welcome->setFrameShape(QFrame::StyledPanel);
        QFrame_Welcome->setFrameShadow(QFrame::Raised);
        QPushButton_MakeCommitment = new QPushButton(QFrame_Welcome);
        QPushButton_MakeCommitment->setObjectName(QString::fromUtf8("QPushButton_MakeCommitment"));
        QPushButton_MakeCommitment->setGeometry(QRect(128, 50, 130, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        QPushButton_MakeCommitment->setFont(font);
        QPushButton_QuickSession = new QPushButton(QFrame_Welcome);
        QPushButton_QuickSession->setObjectName(QString::fromUtf8("QPushButton_QuickSession"));
        QPushButton_QuickSession->setGeometry(QRect(384, 50, 130, 30));
        QFont font1;
        font1.setPointSize(12);
        QPushButton_QuickSession->setFont(font1);
        QLabel_Welcome = new QLabel(QFrame_Welcome);
        QLabel_Welcome->setObjectName(QString::fromUtf8("QLabel_Welcome"));
        QLabel_Welcome->setGeometry(QRect(180, 10, 271, 20));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        QLabel_Welcome->setFont(font2);
        QLabel_Welcome->setScaledContents(true);

        retranslateUi(TaskerUIMainWindow);

        QMetaObject::connectSlotsByName(TaskerUIMainWindow);
    } // setupUi

    void retranslateUi(QWidget *TaskerUIMainWindow)
    {
        TaskerUIMainWindow->setWindowTitle(QApplication::translate("TaskerUIMainWindow", "Tasker", nullptr));
        QPushButton_MakeCommitment->setText(QApplication::translate("TaskerUIMainWindow", "Make Commitment", nullptr));
        QPushButton_QuickSession->setText(QApplication::translate("TaskerUIMainWindow", "Quick Session", nullptr));
        QLabel_Welcome->setText(QApplication::translate("TaskerUIMainWindow", "You have no commitments at this time.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskerUIMainWindow: public Ui_TaskerUIMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKERUIMAINWINDOW_H

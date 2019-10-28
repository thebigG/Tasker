/********************************************************************************
** Form generated from reading UI file 'cratecommitment.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRATECOMMITMENT_H
#define UI_CRATECOMMITMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CrateCommitment
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CrateCommitment)
    {
        if (CrateCommitment->objectName().isEmpty())
            CrateCommitment->setObjectName(QString::fromUtf8("CrateCommitment"));
        CrateCommitment->resize(800, 600);
        centralwidget = new QWidget(CrateCommitment);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 861, 721));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        CrateCommitment->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CrateCommitment);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        CrateCommitment->setMenuBar(menubar);
        statusbar = new QStatusBar(CrateCommitment);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CrateCommitment->setStatusBar(statusbar);

        retranslateUi(CrateCommitment);

        QMetaObject::connectSlotsByName(CrateCommitment);
    } // setupUi

    void retranslateUi(QMainWindow *CrateCommitment)
    {
        CrateCommitment->setWindowTitle(QApplication::translate("CrateCommitment", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CrateCommitment: public Ui_CrateCommitment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRATECOMMITMENT_H

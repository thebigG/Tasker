/********************************************************************************
** Form generated from reading UI file 'livesession.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVESESSION_H
#define UI_LIVESESSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LiveSession
{
public:
    QLabel *productiveTimeQLabel;
    QLabel *unproductiveTimeQLabel;
    QLabel *sessionLengthQLabel;
    QLabel *productiveTime;
    QLabel *unproductiveTimeValue;
    QLabel *label;
    QLabel *congratsMessageLabel;

    void setupUi(QWidget *LiveSession)
    {
        if (LiveSession->objectName().isEmpty())
            LiveSession->setObjectName(QString::fromUtf8("LiveSession"));
        LiveSession->resize(400, 300);
        productiveTimeQLabel = new QLabel(LiveSession);
        productiveTimeQLabel->setObjectName(QString::fromUtf8("productiveTimeQLabel"));
        productiveTimeQLabel->setGeometry(QRect(37, 30, 161, 21));
        QFont font;
        font.setPointSize(14);
        productiveTimeQLabel->setFont(font);
        unproductiveTimeQLabel = new QLabel(LiveSession);
        unproductiveTimeQLabel->setObjectName(QString::fromUtf8("unproductiveTimeQLabel"));
        unproductiveTimeQLabel->setGeometry(QRect(30, 70, 171, 16));
        unproductiveTimeQLabel->setFont(font);
        sessionLengthQLabel = new QLabel(LiveSession);
        sessionLengthQLabel->setObjectName(QString::fromUtf8("sessionLengthQLabel"));
        sessionLengthQLabel->setGeometry(QRect(40, 100, 101, 16));
        sessionLengthQLabel->setFont(font);
        productiveTime = new QLabel(LiveSession);
        productiveTime->setObjectName(QString::fromUtf8("productiveTime"));
        productiveTime->setGeometry(QRect(200, 30, 58, 16));
        productiveTime->setFont(font);
        unproductiveTimeValue = new QLabel(LiveSession);
        unproductiveTimeValue->setObjectName(QString::fromUtf8("unproductiveTimeValue"));
        unproductiveTimeValue->setGeometry(QRect(210, 70, 58, 16));
        unproductiveTimeValue->setFont(font);
        label = new QLabel(LiveSession);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 100, 58, 16));
        label->setFont(font);
        congratsMessageLabel = new QLabel(LiveSession);
        congratsMessageLabel->setObjectName(QString::fromUtf8("congratsMessageLabel"));
        congratsMessageLabel->setGeometry(QRect(10, 230, 371, 41));
        congratsMessageLabel->setFont(font);

        retranslateUi(LiveSession);

        QMetaObject::connectSlotsByName(LiveSession);
    } // setupUi

    void retranslateUi(QWidget *LiveSession)
    {
        LiveSession->setWindowTitle(QApplication::translate("LiveSession", "0", nullptr));
        productiveTimeQLabel->setText(QApplication::translate("LiveSession", "Productive Time:", nullptr));
        unproductiveTimeQLabel->setText(QApplication::translate("LiveSession", "Unproductive Time:", nullptr));
        sessionLengthQLabel->setText(QApplication::translate("LiveSession", "Total Time:", nullptr));
        productiveTime->setText(QApplication::translate("LiveSession", "00:00", nullptr));
        unproductiveTimeValue->setText(QApplication::translate("LiveSession", "00:00", nullptr));
        label->setText(QApplication::translate("LiveSession", "00:00", nullptr));
        congratsMessageLabel->setText(QApplication::translate("LiveSession", "Congrats! You've completed your session!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LiveSession: public Ui_LiveSession {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVESESSION_H

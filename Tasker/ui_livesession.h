/********************************************************************************
** Form generated from reading UI file 'livesession.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVESESSION_H
#define UI_LIVESESSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LiveSession
{
public:
    QGridLayout *gridLayout;
    QWidget *clockStateWidget;
    QGridLayout *gridLayout_2;
    QLabel *productiveTimeQLabel;
    QLabel *productiveTimeValue;
    QLabel *unproductiveTimeQLabel;
    QLabel *unproductiveTimeValue;
    QLabel *sessionLengthQLabel;
    QLabel *totalTimeValue;
    QWidget *clockDetailsWidget;
    QGridLayout *gridLayout_3;
    QLabel *taskStateMessageLabel;
    QLabel *hookStateQLabel;
    QPushButton *playButton;

    void setupUi(QWidget *LiveSession)
    {
        if (LiveSession->objectName().isEmpty())
            LiveSession->setObjectName(QString::fromUtf8("LiveSession"));
        LiveSession->resize(400, 300);
        gridLayout = new QGridLayout(LiveSession);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        clockStateWidget = new QWidget(LiveSession);
        clockStateWidget->setObjectName(QString::fromUtf8("clockStateWidget"));
        gridLayout_2 = new QGridLayout(clockStateWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        productiveTimeQLabel = new QLabel(clockStateWidget);
        productiveTimeQLabel->setObjectName(QString::fromUtf8("productiveTimeQLabel"));
        QFont font;
        font.setPointSize(14);
        productiveTimeQLabel->setFont(font);

        gridLayout_2->addWidget(productiveTimeQLabel, 0, 0, 1, 1);

        productiveTimeValue = new QLabel(clockStateWidget);
        productiveTimeValue->setObjectName(QString::fromUtf8("productiveTimeValue"));
        productiveTimeValue->setFont(font);

        gridLayout_2->addWidget(productiveTimeValue, 0, 1, 1, 1);

        unproductiveTimeQLabel = new QLabel(clockStateWidget);
        unproductiveTimeQLabel->setObjectName(QString::fromUtf8("unproductiveTimeQLabel"));
        unproductiveTimeQLabel->setFont(font);

        gridLayout_2->addWidget(unproductiveTimeQLabel, 1, 0, 1, 1);

        unproductiveTimeValue = new QLabel(clockStateWidget);
        unproductiveTimeValue->setObjectName(QString::fromUtf8("unproductiveTimeValue"));
        unproductiveTimeValue->setFont(font);

        gridLayout_2->addWidget(unproductiveTimeValue, 1, 1, 1, 1);

        sessionLengthQLabel = new QLabel(clockStateWidget);
        sessionLengthQLabel->setObjectName(QString::fromUtf8("sessionLengthQLabel"));
        sessionLengthQLabel->setFont(font);

        gridLayout_2->addWidget(sessionLengthQLabel, 2, 0, 1, 1);

        totalTimeValue = new QLabel(clockStateWidget);
        totalTimeValue->setObjectName(QString::fromUtf8("totalTimeValue"));
        totalTimeValue->setFont(font);

        gridLayout_2->addWidget(totalTimeValue, 2, 1, 1, 1);


        gridLayout->addWidget(clockStateWidget, 0, 0, 1, 1);

        clockDetailsWidget = new QWidget(LiveSession);
        clockDetailsWidget->setObjectName(QString::fromUtf8("clockDetailsWidget"));
        gridLayout_3 = new QGridLayout(clockDetailsWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        taskStateMessageLabel = new QLabel(clockDetailsWidget);
        taskStateMessageLabel->setObjectName(QString::fromUtf8("taskStateMessageLabel"));
        taskStateMessageLabel->setFont(font);

        gridLayout_3->addWidget(taskStateMessageLabel, 0, 0, 1, 1);

        hookStateQLabel = new QLabel(clockDetailsWidget);
        hookStateQLabel->setObjectName(QString::fromUtf8("hookStateQLabel"));
        hookStateQLabel->setFont(font);

        gridLayout_3->addWidget(hookStateQLabel, 1, 0, 1, 1);

        playButton = new QPushButton(clockDetailsWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(16);
        playButton->setFont(font1);
        playButton->setToolTipDuration(2000);
        playButton->setFlat(true);

        gridLayout_3->addWidget(playButton, 2, 0, 1, 1);


        gridLayout->addWidget(clockDetailsWidget, 1, 0, 1, 1);


        retranslateUi(LiveSession);

        QMetaObject::connectSlotsByName(LiveSession);
    } // setupUi

    void retranslateUi(QWidget *LiveSession)
    {
        LiveSession->setWindowTitle(QCoreApplication::translate("LiveSession", "0", nullptr));
        productiveTimeQLabel->setText(QCoreApplication::translate("LiveSession", "Productive Time:", nullptr));
        productiveTimeValue->setText(QCoreApplication::translate("LiveSession", "0h0m0s", nullptr));
        unproductiveTimeQLabel->setText(QCoreApplication::translate("LiveSession", "Unproductive Time:", nullptr));
        unproductiveTimeValue->setText(QCoreApplication::translate("LiveSession", "0h0m0s", nullptr));
        sessionLengthQLabel->setText(QCoreApplication::translate("LiveSession", "Total Time:", nullptr));
        totalTimeValue->setText(QCoreApplication::translate("LiveSession", "0h0m0s", nullptr));
        taskStateMessageLabel->setText(QCoreApplication::translate("LiveSession", "Congrats! You've completed your session!", nullptr));
        hookStateQLabel->setText(QCoreApplication::translate("LiveSession", "Hook State..", nullptr));
#if QT_CONFIG(tooltip)
        playButton->setToolTip(QCoreApplication::translate("LiveSession", "Hi There!", nullptr));
#endif // QT_CONFIG(tooltip)
        playButton->setText(QCoreApplication::translate("LiveSession", "u25B6", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LiveSession: public Ui_LiveSession {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVESESSION_H

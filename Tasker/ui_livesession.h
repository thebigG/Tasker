/********************************************************************************
** Form generated from reading UI file 'livesession.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVESESSION_H
#define UI_LIVESESSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
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
            LiveSession->setObjectName(QStringLiteral("LiveSession"));
        LiveSession->resize(400, 300);
        gridLayout = new QGridLayout(LiveSession);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        clockStateWidget = new QWidget(LiveSession);
        clockStateWidget->setObjectName(QStringLiteral("clockStateWidget"));
        gridLayout_2 = new QGridLayout(clockStateWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        productiveTimeQLabel = new QLabel(clockStateWidget);
        productiveTimeQLabel->setObjectName(QStringLiteral("productiveTimeQLabel"));
        QFont font;
        font.setPointSize(14);
        productiveTimeQLabel->setFont(font);

        gridLayout_2->addWidget(productiveTimeQLabel, 0, 0, 1, 1);

        productiveTimeValue = new QLabel(clockStateWidget);
        productiveTimeValue->setObjectName(QStringLiteral("productiveTimeValue"));
        productiveTimeValue->setFont(font);

        gridLayout_2->addWidget(productiveTimeValue, 0, 1, 1, 1);

        unproductiveTimeQLabel = new QLabel(clockStateWidget);
        unproductiveTimeQLabel->setObjectName(QStringLiteral("unproductiveTimeQLabel"));
        unproductiveTimeQLabel->setFont(font);

        gridLayout_2->addWidget(unproductiveTimeQLabel, 1, 0, 1, 1);

        unproductiveTimeValue = new QLabel(clockStateWidget);
        unproductiveTimeValue->setObjectName(QStringLiteral("unproductiveTimeValue"));
        unproductiveTimeValue->setFont(font);

        gridLayout_2->addWidget(unproductiveTimeValue, 1, 1, 1, 1);

        sessionLengthQLabel = new QLabel(clockStateWidget);
        sessionLengthQLabel->setObjectName(QStringLiteral("sessionLengthQLabel"));
        sessionLengthQLabel->setFont(font);

        gridLayout_2->addWidget(sessionLengthQLabel, 2, 0, 1, 1);

        totalTimeValue = new QLabel(clockStateWidget);
        totalTimeValue->setObjectName(QStringLiteral("totalTimeValue"));
        totalTimeValue->setFont(font);

        gridLayout_2->addWidget(totalTimeValue, 2, 1, 1, 1);


        gridLayout->addWidget(clockStateWidget, 0, 0, 1, 1);

        clockDetailsWidget = new QWidget(LiveSession);
        clockDetailsWidget->setObjectName(QStringLiteral("clockDetailsWidget"));
        gridLayout_3 = new QGridLayout(clockDetailsWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        taskStateMessageLabel = new QLabel(clockDetailsWidget);
        taskStateMessageLabel->setObjectName(QStringLiteral("taskStateMessageLabel"));
        taskStateMessageLabel->setFont(font);

        gridLayout_3->addWidget(taskStateMessageLabel, 0, 0, 1, 1);

        hookStateQLabel = new QLabel(clockDetailsWidget);
        hookStateQLabel->setObjectName(QStringLiteral("hookStateQLabel"));
        hookStateQLabel->setFont(font);

        gridLayout_3->addWidget(hookStateQLabel, 1, 0, 1, 1);

        playButton = new QPushButton(clockDetailsWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
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
        LiveSession->setWindowTitle(QApplication::translate("LiveSession", "0", Q_NULLPTR));
        productiveTimeQLabel->setText(QApplication::translate("LiveSession", "Productive Time:", Q_NULLPTR));
        productiveTimeValue->setText(QApplication::translate("LiveSession", "0h0m0s", Q_NULLPTR));
        unproductiveTimeQLabel->setText(QApplication::translate("LiveSession", "Unproductive Time:", Q_NULLPTR));
        unproductiveTimeValue->setText(QApplication::translate("LiveSession", "0h0m0s", Q_NULLPTR));
        sessionLengthQLabel->setText(QApplication::translate("LiveSession", "Total Time:", Q_NULLPTR));
        totalTimeValue->setText(QApplication::translate("LiveSession", "0h0m0s", Q_NULLPTR));
        taskStateMessageLabel->setText(QApplication::translate("LiveSession", "Congrats! You've completed your session!", Q_NULLPTR));
        hookStateQLabel->setText(QApplication::translate("LiveSession", "Hook State..", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        playButton->setToolTip(QApplication::translate("LiveSession", "Hi There!", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        playButton->setText(QApplication::translate("LiveSession", "u25B6", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LiveSession: public Ui_LiveSession {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVESESSION_H

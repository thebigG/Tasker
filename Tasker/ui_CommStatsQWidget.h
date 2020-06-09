/********************************************************************************
** Form generated from reading UI file 'CommStatsQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMSTATSQWIDGET_H
#define UI_COMMSTATSQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommStatsQWidget
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *commitmentsQTreeWidget;
    QWidget *commStatsHubQWidget;
    QGridLayout *gridLayout_2;
    QWidget *CommitmentInfoStatsQWidget;
    QGridLayout *gridLayout_3;
    QLabel *goalQLabel;
    QLabel *beginDateQLabel;
    QLabel *endDateQLabel;
    QPushButton *prevSnaphot;
    QPushButton *nextSnapshot;

    void setupUi(QWidget *CommStatsQWidget)
    {
        if (CommStatsQWidget->objectName().isEmpty())
            CommStatsQWidget->setObjectName(QString::fromUtf8("CommStatsQWidget"));
        CommStatsQWidget->resize(1000, 800);
        CommStatsQWidget->setMinimumSize(QSize(0, 0));
        CommStatsQWidget->setMaximumSize(QSize(1500, 800));
        gridLayout = new QGridLayout(CommStatsQWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        commitmentsQTreeWidget = new QTreeWidget(CommStatsQWidget);
        commitmentsQTreeWidget->setObjectName(QString::fromUtf8("commitmentsQTreeWidget"));
        commitmentsQTreeWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(commitmentsQTreeWidget->sizePolicy().hasHeightForWidth());
        commitmentsQTreeWidget->setSizePolicy(sizePolicy);
        commitmentsQTreeWidget->setMinimumSize(QSize(400, 600));
        commitmentsQTreeWidget->setMaximumSize(QSize(800, 1000));
        commitmentsQTreeWidget->setFrameShape(QFrame::NoFrame);
        commitmentsQTreeWidget->setFrameShadow(QFrame::Plain);
        commitmentsQTreeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        commitmentsQTreeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        commitmentsQTreeWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        commitmentsQTreeWidget->setAutoScroll(true);
        commitmentsQTreeWidget->setAlternatingRowColors(true);
        commitmentsQTreeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        commitmentsQTreeWidget->setAllColumnsShowFocus(true);
        commitmentsQTreeWidget->header()->setVisible(true);

        gridLayout->addWidget(commitmentsQTreeWidget, 0, 0, 1, 1);

        commStatsHubQWidget = new QWidget(CommStatsQWidget);
        commStatsHubQWidget->setObjectName(QString::fromUtf8("commStatsHubQWidget"));
        commStatsHubQWidget->setMaximumSize(QSize(600, 800));
        gridLayout_2 = new QGridLayout(commStatsHubQWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 0, -1, -1);
        CommitmentInfoStatsQWidget = new QWidget(commStatsHubQWidget);
        CommitmentInfoStatsQWidget->setObjectName(QString::fromUtf8("CommitmentInfoStatsQWidget"));
        CommitmentInfoStatsQWidget->setMaximumSize(QSize(800, 200));
        gridLayout_3 = new QGridLayout(CommitmentInfoStatsQWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        goalQLabel = new QLabel(CommitmentInfoStatsQWidget);
        goalQLabel->setObjectName(QString::fromUtf8("goalQLabel"));
        QFont font;
        font.setPointSize(12);
        goalQLabel->setFont(font);

        gridLayout_3->addWidget(goalQLabel, 0, 0, 1, 1);

        beginDateQLabel = new QLabel(CommitmentInfoStatsQWidget);
        beginDateQLabel->setObjectName(QString::fromUtf8("beginDateQLabel"));
        beginDateQLabel->setFont(font);

        gridLayout_3->addWidget(beginDateQLabel, 1, 0, 1, 1);

        endDateQLabel = new QLabel(CommitmentInfoStatsQWidget);
        endDateQLabel->setObjectName(QString::fromUtf8("endDateQLabel"));
        endDateQLabel->setFont(font);

        gridLayout_3->addWidget(endDateQLabel, 1, 1, 1, 1);


        gridLayout_2->addWidget(CommitmentInfoStatsQWidget, 0, 1, 1, 1);

        prevSnaphot = new QPushButton(commStatsHubQWidget);
        prevSnaphot->setObjectName(QString::fromUtf8("prevSnaphot"));
        prevSnaphot->setMaximumSize(QSize(30, 30));

        gridLayout_2->addWidget(prevSnaphot, 0, 0, 1, 1);

        nextSnapshot = new QPushButton(commStatsHubQWidget);
        nextSnapshot->setObjectName(QString::fromUtf8("nextSnapshot"));
        nextSnapshot->setMaximumSize(QSize(30, 30));

        gridLayout_2->addWidget(nextSnapshot, 0, 2, 1, 1);


        gridLayout->addWidget(commStatsHubQWidget, 0, 1, 1, 1);


        retranslateUi(CommStatsQWidget);

        QMetaObject::connectSlotsByName(CommStatsQWidget);
    } // setupUi

    void retranslateUi(QWidget *CommStatsQWidget)
    {
        CommStatsQWidget->setWindowTitle(QCoreApplication::translate("CommStatsQWidget", "Tasker - My Commitments", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = commitmentsQTreeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("CommStatsQWidget", "Name", nullptr));
        goalQLabel->setText(QCoreApplication::translate("CommStatsQWidget", "0h25m, 4 times a week.", nullptr));
        beginDateQLabel->setText(QCoreApplication::translate("CommStatsQWidget", "Commitment Began on Feb, 05, 2020", nullptr));
        endDateQLabel->setText(QCoreApplication::translate("CommStatsQWidget", "Has no end date", nullptr));
        prevSnaphot->setText(QCoreApplication::translate("CommStatsQWidget", "<", nullptr));
        nextSnapshot->setText(QCoreApplication::translate("CommStatsQWidget", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommStatsQWidget: public Ui_CommStatsQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMSTATSQWIDGET_H

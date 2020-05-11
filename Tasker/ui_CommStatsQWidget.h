/********************************************************************************
** Form generated from reading UI file 'CommStatsQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMSTATSQWIDGET_H
#define UI_COMMSTATSQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            CommStatsQWidget->setObjectName(QStringLiteral("CommStatsQWidget"));
        CommStatsQWidget->resize(1000, 800);
        CommStatsQWidget->setMinimumSize(QSize(0, 0));
        CommStatsQWidget->setMaximumSize(QSize(1500, 800));
        gridLayout = new QGridLayout(CommStatsQWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        commitmentsQTreeWidget = new QTreeWidget(CommStatsQWidget);
        commitmentsQTreeWidget->setObjectName(QStringLiteral("commitmentsQTreeWidget"));
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
        commStatsHubQWidget->setObjectName(QStringLiteral("commStatsHubQWidget"));
        commStatsHubQWidget->setMaximumSize(QSize(600, 800));
        gridLayout_2 = new QGridLayout(commStatsHubQWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 0, -1, -1);
        CommitmentInfoStatsQWidget = new QWidget(commStatsHubQWidget);
        CommitmentInfoStatsQWidget->setObjectName(QStringLiteral("CommitmentInfoStatsQWidget"));
        CommitmentInfoStatsQWidget->setMaximumSize(QSize(800, 200));
        gridLayout_3 = new QGridLayout(CommitmentInfoStatsQWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        goalQLabel = new QLabel(CommitmentInfoStatsQWidget);
        goalQLabel->setObjectName(QStringLiteral("goalQLabel"));
        QFont font;
        font.setPointSize(12);
        goalQLabel->setFont(font);

        gridLayout_3->addWidget(goalQLabel, 0, 0, 1, 1);

        beginDateQLabel = new QLabel(CommitmentInfoStatsQWidget);
        beginDateQLabel->setObjectName(QStringLiteral("beginDateQLabel"));
        beginDateQLabel->setFont(font);

        gridLayout_3->addWidget(beginDateQLabel, 1, 0, 1, 1);

        endDateQLabel = new QLabel(CommitmentInfoStatsQWidget);
        endDateQLabel->setObjectName(QStringLiteral("endDateQLabel"));
        endDateQLabel->setFont(font);

        gridLayout_3->addWidget(endDateQLabel, 1, 1, 1, 1);


        gridLayout_2->addWidget(CommitmentInfoStatsQWidget, 0, 1, 1, 1);

        prevSnaphot = new QPushButton(commStatsHubQWidget);
        prevSnaphot->setObjectName(QStringLiteral("prevSnaphot"));
        prevSnaphot->setMaximumSize(QSize(30, 30));

        gridLayout_2->addWidget(prevSnaphot, 0, 0, 1, 1);

        nextSnapshot = new QPushButton(commStatsHubQWidget);
        nextSnapshot->setObjectName(QStringLiteral("nextSnapshot"));
        nextSnapshot->setMaximumSize(QSize(30, 30));

        gridLayout_2->addWidget(nextSnapshot, 0, 2, 1, 1);


        gridLayout->addWidget(commStatsHubQWidget, 0, 1, 1, 1);


        retranslateUi(CommStatsQWidget);

        QMetaObject::connectSlotsByName(CommStatsQWidget);
    } // setupUi

    void retranslateUi(QWidget *CommStatsQWidget)
    {
        CommStatsQWidget->setWindowTitle(QApplication::translate("CommStatsQWidget", "Tasker - My Commitments", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = commitmentsQTreeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("CommStatsQWidget", "Commitment", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("CommStatsQWidget", "Name", Q_NULLPTR));
        goalQLabel->setText(QApplication::translate("CommStatsQWidget", "0h25m, 4 times a week.", Q_NULLPTR));
        beginDateQLabel->setText(QApplication::translate("CommStatsQWidget", "Commitment Began on Feb, 05, 2020", Q_NULLPTR));
        endDateQLabel->setText(QApplication::translate("CommStatsQWidget", "Has no end date", Q_NULLPTR));
        prevSnaphot->setText(QApplication::translate("CommStatsQWidget", "<", Q_NULLPTR));
        nextSnapshot->setText(QApplication::translate("CommStatsQWidget", ">", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CommStatsQWidget: public Ui_CommStatsQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMSTATSQWIDGET_H

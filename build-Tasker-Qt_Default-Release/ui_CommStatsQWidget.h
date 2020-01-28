/********************************************************************************
** Form generated from reading UI file 'CommStatsQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMSTATSQWIDGET_H
#define UI_COMMSTATSQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommStatsQWidget
{
public:
    QFrame *commitmentsQFrame;
    QTreeWidget *commitmentsQTreeWidget;
    QFrame *overviewStatsNotesMediaQFrame;
    QFrame *overviewQFrame;
    QGroupBox *overviewQGroupBox;
    QProgressBar *percentageProductiveQProgressBar;
    QProgressBar *percentageUnproductiveQProgressBar;
    QLabel *totalTimeProductiveQLabel;
    QLabel *totalTimeUnproductiveQLabel;
    QLabel *durationProductiveQLabel;
    QLabel *durationUnproductiveQLabel;
    QLabel *totalTimeSumQLabel;
    QLabel *durationTotalSumQLabel;
    QFrame *notesMediaQFrame;
    QGroupBox *notesMediaQGroupBox;
    QTextEdit *notesQTextEdit;
    QListWidget *filesQListWidget;
    QPushButton *addFileQPushButton;
    QPushButton *removeFileQPushButton;
    QFrame *bottomBarQFrame;
    QLabel *bottomBarStatsQLabel;
    QFrame *topBarQFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *addCommitmentQPushButton;
    QPushButton *removeCommitmentQPushButton;
    QPushButton *liveSessionQPushButton;

    void setupUi(QWidget *CommStatsQWidget)
    {
        if (CommStatsQWidget->objectName().isEmpty())
            CommStatsQWidget->setObjectName(QStringLiteral("CommStatsQWidget"));
        CommStatsQWidget->resize(1280, 720);
        commitmentsQFrame = new QFrame(CommStatsQWidget);
        commitmentsQFrame->setObjectName(QStringLiteral("commitmentsQFrame"));
        commitmentsQFrame->setGeometry(QRect(0, 30, 271, 661));
        commitmentsQFrame->setFrameShape(QFrame::NoFrame);
        commitmentsQFrame->setFrameShadow(QFrame::Raised);
        commitmentsQTreeWidget = new QTreeWidget(commitmentsQFrame);
        commitmentsQTreeWidget->setObjectName(QStringLiteral("commitmentsQTreeWidget"));
        commitmentsQTreeWidget->setEnabled(true);
        commitmentsQTreeWidget->setGeometry(QRect(0, 0, 270, 661));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(commitmentsQTreeWidget->sizePolicy().hasHeightForWidth());
        commitmentsQTreeWidget->setSizePolicy(sizePolicy);
        commitmentsQTreeWidget->setFrameShape(QFrame::StyledPanel);
        commitmentsQTreeWidget->setFrameShadow(QFrame::Plain);
        commitmentsQTreeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        commitmentsQTreeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        commitmentsQTreeWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        commitmentsQTreeWidget->setAutoScroll(true);
        commitmentsQTreeWidget->setAlternatingRowColors(true);
        commitmentsQTreeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        commitmentsQTreeWidget->header()->setVisible(false);
        overviewStatsNotesMediaQFrame = new QFrame(CommStatsQWidget);
        overviewStatsNotesMediaQFrame->setObjectName(QStringLiteral("overviewStatsNotesMediaQFrame"));
        overviewStatsNotesMediaQFrame->setGeometry(QRect(271, 30, 1011, 661));
        overviewStatsNotesMediaQFrame->setFrameShape(QFrame::NoFrame);
        overviewStatsNotesMediaQFrame->setFrameShadow(QFrame::Raised);
        overviewQFrame = new QFrame(overviewStatsNotesMediaQFrame);
        overviewQFrame->setObjectName(QStringLiteral("overviewQFrame"));
        overviewQFrame->setGeometry(QRect(0, 0, 1011, 121));
        overviewQFrame->setFrameShape(QFrame::NoFrame);
        overviewQFrame->setFrameShadow(QFrame::Raised);
        overviewQGroupBox = new QGroupBox(overviewQFrame);
        overviewQGroupBox->setObjectName(QStringLiteral("overviewQGroupBox"));
        overviewQGroupBox->setGeometry(QRect(20, 20, 971, 88));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        overviewQGroupBox->setFont(font);
        percentageProductiveQProgressBar = new QProgressBar(overviewQGroupBox);
        percentageProductiveQProgressBar->setObjectName(QStringLiteral("percentageProductiveQProgressBar"));
        percentageProductiveQProgressBar->setGeometry(QRect(50, 30, 441, 16));
        percentageProductiveQProgressBar->setMinimum(0);
        percentageProductiveQProgressBar->setValue(75);
        percentageUnproductiveQProgressBar = new QProgressBar(overviewQGroupBox);
        percentageUnproductiveQProgressBar->setObjectName(QStringLiteral("percentageUnproductiveQProgressBar"));
        percentageUnproductiveQProgressBar->setGeometry(QRect(50, 50, 441, 16));
        percentageUnproductiveQProgressBar->setValue(25);
        percentageUnproductiveQProgressBar->setInvertedAppearance(true);
        totalTimeProductiveQLabel = new QLabel(overviewQGroupBox);
        totalTimeProductiveQLabel->setObjectName(QStringLiteral("totalTimeProductiveQLabel"));
        totalTimeProductiveQLabel->setGeometry(QRect(500, 25, 141, 16));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        totalTimeProductiveQLabel->setFont(font1);
        totalTimeUnproductiveQLabel = new QLabel(overviewQGroupBox);
        totalTimeUnproductiveQLabel->setObjectName(QStringLiteral("totalTimeUnproductiveQLabel"));
        totalTimeUnproductiveQLabel->setGeometry(QRect(500, 45, 141, 16));
        totalTimeUnproductiveQLabel->setFont(font1);
        durationProductiveQLabel = new QLabel(overviewQGroupBox);
        durationProductiveQLabel->setObjectName(QStringLiteral("durationProductiveQLabel"));
        durationProductiveQLabel->setGeometry(QRect(660, 25, 71, 16));
        durationUnproductiveQLabel = new QLabel(overviewQGroupBox);
        durationUnproductiveQLabel->setObjectName(QStringLiteral("durationUnproductiveQLabel"));
        durationUnproductiveQLabel->setGeometry(QRect(660, 45, 71, 16));
        totalTimeSumQLabel = new QLabel(overviewQGroupBox);
        totalTimeSumQLabel->setObjectName(QStringLiteral("totalTimeSumQLabel"));
        totalTimeSumQLabel->setGeometry(QRect(500, 65, 141, 16));
        totalTimeSumQLabel->setFont(font1);
        durationTotalSumQLabel = new QLabel(overviewQGroupBox);
        durationTotalSumQLabel->setObjectName(QStringLiteral("durationTotalSumQLabel"));
        durationTotalSumQLabel->setGeometry(QRect(660, 65, 71, 16));
        notesMediaQFrame = new QFrame(overviewStatsNotesMediaQFrame);
        notesMediaQFrame->setObjectName(QStringLiteral("notesMediaQFrame"));
        notesMediaQFrame->setGeometry(QRect(0, 510, 1011, 151));
        notesMediaQFrame->setFrameShape(QFrame::NoFrame);
        notesMediaQFrame->setFrameShadow(QFrame::Raised);
        notesMediaQGroupBox = new QGroupBox(notesMediaQFrame);
        notesMediaQGroupBox->setObjectName(QStringLiteral("notesMediaQGroupBox"));
        notesMediaQGroupBox->setGeometry(QRect(20, 10, 971, 131));
        notesMediaQGroupBox->setFlat(false);
        notesQTextEdit = new QTextEdit(notesMediaQGroupBox);
        notesQTextEdit->setObjectName(QStringLiteral("notesQTextEdit"));
        notesQTextEdit->setGeometry(QRect(10, 30, 471, 91));
        filesQListWidget = new QListWidget(notesMediaQGroupBox);
        new QListWidgetItem(filesQListWidget);
        new QListWidgetItem(filesQListWidget);
        new QListWidgetItem(filesQListWidget);
        filesQListWidget->setObjectName(QStringLiteral("filesQListWidget"));
        filesQListWidget->setGeometry(QRect(490, 30, 351, 91));
        filesQListWidget->setAlternatingRowColors(true);
        filesQListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        addFileQPushButton = new QPushButton(notesMediaQGroupBox);
        addFileQPushButton->setObjectName(QStringLiteral("addFileQPushButton"));
        addFileQPushButton->setGeometry(QRect(850, 40, 81, 31));
        removeFileQPushButton = new QPushButton(notesMediaQGroupBox);
        removeFileQPushButton->setObjectName(QStringLiteral("removeFileQPushButton"));
        removeFileQPushButton->setGeometry(QRect(850, 70, 91, 31));
        bottomBarQFrame = new QFrame(CommStatsQWidget);
        bottomBarQFrame->setObjectName(QStringLiteral("bottomBarQFrame"));
        bottomBarQFrame->setGeometry(QRect(0, 690, 1280, 31));
        bottomBarQFrame->setFrameShape(QFrame::NoFrame);
        bottomBarQFrame->setFrameShadow(QFrame::Raised);
        bottomBarStatsQLabel = new QLabel(bottomBarQFrame);
        bottomBarStatsQLabel->setObjectName(QStringLiteral("bottomBarStatsQLabel"));
        bottomBarStatsQLabel->setGeometry(QRect(470, 0, 401, 21));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        bottomBarStatsQLabel->setFont(font2);
        topBarQFrame = new QFrame(CommStatsQWidget);
        topBarQFrame->setObjectName(QStringLiteral("topBarQFrame"));
        topBarQFrame->setGeometry(QRect(0, -10, 381, 42));
        topBarQFrame->setFrameShape(QFrame::NoFrame);
        topBarQFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(topBarQFrame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addCommitmentQPushButton = new QPushButton(topBarQFrame);
        addCommitmentQPushButton->setObjectName(QStringLiteral("addCommitmentQPushButton"));

        horizontalLayout->addWidget(addCommitmentQPushButton);

        removeCommitmentQPushButton = new QPushButton(topBarQFrame);
        removeCommitmentQPushButton->setObjectName(QStringLiteral("removeCommitmentQPushButton"));
        removeCommitmentQPushButton->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(removeCommitmentQPushButton);

        liveSessionQPushButton = new QPushButton(topBarQFrame);
        liveSessionQPushButton->setObjectName(QStringLiteral("liveSessionQPushButton"));

        horizontalLayout->addWidget(liveSessionQPushButton);


        retranslateUi(CommStatsQWidget);

        QMetaObject::connectSlotsByName(CommStatsQWidget);
    } // setupUi

    void retranslateUi(QWidget *CommStatsQWidget)
    {
        CommStatsQWidget->setWindowTitle(QApplication::translate("CommStatsQWidget", "Tasker - My Commitments", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = commitmentsQTreeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("CommStatsQWidget", "COMMITMENTS", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        overviewQGroupBox->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        overviewQGroupBox->setTitle(QApplication::translate("CommStatsQWidget", "Untitled Commitment - Session 0", Q_NULLPTR));
        totalTimeProductiveQLabel->setText(QApplication::translate("CommStatsQWidget", "PRODUCTIVE TIME", Q_NULLPTR));
        totalTimeUnproductiveQLabel->setText(QApplication::translate("CommStatsQWidget", "UNPRODUCTIVE TIME", Q_NULLPTR));
        durationProductiveQLabel->setText(QApplication::translate("CommStatsQWidget", "(00:00:00)", Q_NULLPTR));
        durationUnproductiveQLabel->setText(QApplication::translate("CommStatsQWidget", "(00:00:00)", Q_NULLPTR));
        totalTimeSumQLabel->setText(QApplication::translate("CommStatsQWidget", "TOTAL TIME", Q_NULLPTR));
        durationTotalSumQLabel->setText(QApplication::translate("CommStatsQWidget", "(00:00:00)", Q_NULLPTR));
        notesMediaQGroupBox->setTitle(QApplication::translate("CommStatsQWidget", "NOTES/MEDIA", Q_NULLPTR));
        notesQTextEdit->setHtml(QApplication::translate("CommStatsQWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:13pt;\">(write some notes here...)</span></p></body></html>", Q_NULLPTR));

        const bool __sortingEnabled = filesQListWidget->isSortingEnabled();
        filesQListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = filesQListWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("CommStatsQWidget", "file_0.mp3", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = filesQListWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("CommStatsQWidget", "file_1.jpg", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = filesQListWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("CommStatsQWidget", "file_2.cpp", Q_NULLPTR));
        filesQListWidget->setSortingEnabled(__sortingEnabled);

        addFileQPushButton->setText(QApplication::translate("CommStatsQWidget", "Add file", Q_NULLPTR));
        removeFileQPushButton->setText(QApplication::translate("CommStatsQWidget", "Remove file", Q_NULLPTR));
        bottomBarStatsQLabel->setText(QApplication::translate("CommStatsQWidget", "2 total commitments, 00:00:00 productive time, 00:00:00 unproductive time", Q_NULLPTR));
        addCommitmentQPushButton->setText(QApplication::translate("CommStatsQWidget", "Add new commitment", Q_NULLPTR));
        removeCommitmentQPushButton->setText(QApplication::translate("CommStatsQWidget", "Remove commitment", Q_NULLPTR));
        liveSessionQPushButton->setText(QApplication::translate("CommStatsQWidget", "Live Session", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CommStatsQWidget: public Ui_CommStatsQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMSTATSQWIDGET_H

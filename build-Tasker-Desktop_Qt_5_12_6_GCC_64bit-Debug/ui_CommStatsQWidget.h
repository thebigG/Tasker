/********************************************************************************
** Form generated from reading UI file 'CommStatsQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMSTATSQWIDGET_H
#define UI_COMMSTATSQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
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
    QFrame *statsQFrame;
    QFrame *notesMediaQFrame;
    QGroupBox *notesMediaQGroupBox;
    QTextEdit *notesQTextEdit;
    QListWidget *filesQListWidget;
    QCommandLinkButton *addFileQCommandLinkButton;
    QCommandLinkButton *removeFileQCommandLinkButton;
    QFrame *bottomBarQFrame;
    QLabel *bottomBarStatsQLabel;
    QFrame *topBarQFrame;
    QCommandLinkButton *addCommitmentQCommandLinkButton;
    QCommandLinkButton *removeCommitmentQCommandLinkButton;

    void setupUi(QWidget *CommStatsQWidget)
    {
        if (CommStatsQWidget->objectName().isEmpty())
            CommStatsQWidget->setObjectName(QString::fromUtf8("CommStatsQWidget"));
        CommStatsQWidget->resize(1280, 720);
        commitmentsQFrame = new QFrame(CommStatsQWidget);
        commitmentsQFrame->setObjectName(QString::fromUtf8("commitmentsQFrame"));
        commitmentsQFrame->setGeometry(QRect(0, 30, 271, 661));
        commitmentsQFrame->setFrameShape(QFrame::NoFrame);
        commitmentsQFrame->setFrameShadow(QFrame::Raised);
        commitmentsQTreeWidget = new QTreeWidget(commitmentsQFrame);
        QBrush brush(QColor(108, 108, 108, 255));
        brush.setStyle(Qt::NoBrush);
        QFont font;
        font.setItalic(true);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(commitmentsQTreeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(commitmentsQTreeWidget);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem2->setFont(0, font);
        __qtreewidgetitem2->setBackground(0, brush);
        commitmentsQTreeWidget->setObjectName(QString::fromUtf8("commitmentsQTreeWidget"));
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
        overviewStatsNotesMediaQFrame->setObjectName(QString::fromUtf8("overviewStatsNotesMediaQFrame"));
        overviewStatsNotesMediaQFrame->setGeometry(QRect(271, 30, 1011, 661));
        overviewStatsNotesMediaQFrame->setFrameShape(QFrame::NoFrame);
        overviewStatsNotesMediaQFrame->setFrameShadow(QFrame::Raised);
        overviewQFrame = new QFrame(overviewStatsNotesMediaQFrame);
        overviewQFrame->setObjectName(QString::fromUtf8("overviewQFrame"));
        overviewQFrame->setGeometry(QRect(0, 0, 1011, 121));
        overviewQFrame->setFrameShape(QFrame::NoFrame);
        overviewQFrame->setFrameShadow(QFrame::Raised);
        overviewQGroupBox = new QGroupBox(overviewQFrame);
        overviewQGroupBox->setObjectName(QString::fromUtf8("overviewQGroupBox"));
        overviewQGroupBox->setGeometry(QRect(20, 20, 971, 88));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        overviewQGroupBox->setFont(font1);
        percentageProductiveQProgressBar = new QProgressBar(overviewQGroupBox);
        percentageProductiveQProgressBar->setObjectName(QString::fromUtf8("percentageProductiveQProgressBar"));
        percentageProductiveQProgressBar->setGeometry(QRect(50, 30, 441, 16));
        percentageProductiveQProgressBar->setMinimum(0);
        percentageProductiveQProgressBar->setValue(75);
        percentageUnproductiveQProgressBar = new QProgressBar(overviewQGroupBox);
        percentageUnproductiveQProgressBar->setObjectName(QString::fromUtf8("percentageUnproductiveQProgressBar"));
        percentageUnproductiveQProgressBar->setGeometry(QRect(50, 50, 441, 16));
        percentageUnproductiveQProgressBar->setValue(25);
        percentageUnproductiveQProgressBar->setInvertedAppearance(true);
        totalTimeProductiveQLabel = new QLabel(overviewQGroupBox);
        totalTimeProductiveQLabel->setObjectName(QString::fromUtf8("totalTimeProductiveQLabel"));
        totalTimeProductiveQLabel->setGeometry(QRect(500, 25, 141, 16));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        totalTimeProductiveQLabel->setFont(font2);
        totalTimeUnproductiveQLabel = new QLabel(overviewQGroupBox);
        totalTimeUnproductiveQLabel->setObjectName(QString::fromUtf8("totalTimeUnproductiveQLabel"));
        totalTimeUnproductiveQLabel->setGeometry(QRect(500, 45, 141, 16));
        totalTimeUnproductiveQLabel->setFont(font2);
        durationProductiveQLabel = new QLabel(overviewQGroupBox);
        durationProductiveQLabel->setObjectName(QString::fromUtf8("durationProductiveQLabel"));
        durationProductiveQLabel->setGeometry(QRect(660, 25, 71, 16));
        durationUnproductiveQLabel = new QLabel(overviewQGroupBox);
        durationUnproductiveQLabel->setObjectName(QString::fromUtf8("durationUnproductiveQLabel"));
        durationUnproductiveQLabel->setGeometry(QRect(660, 45, 71, 16));
        totalTimeSumQLabel = new QLabel(overviewQGroupBox);
        totalTimeSumQLabel->setObjectName(QString::fromUtf8("totalTimeSumQLabel"));
        totalTimeSumQLabel->setGeometry(QRect(500, 65, 141, 16));
        totalTimeSumQLabel->setFont(font2);
        durationTotalSumQLabel = new QLabel(overviewQGroupBox);
        durationTotalSumQLabel->setObjectName(QString::fromUtf8("durationTotalSumQLabel"));
        durationTotalSumQLabel->setGeometry(QRect(660, 65, 71, 16));
        statsQFrame = new QFrame(overviewStatsNotesMediaQFrame);
        statsQFrame->setObjectName(QString::fromUtf8("statsQFrame"));
        statsQFrame->setGeometry(QRect(-10, 120, 1021, 391));
        statsQFrame->setFrameShape(QFrame::NoFrame);
        statsQFrame->setFrameShadow(QFrame::Raised);
        notesMediaQFrame = new QFrame(overviewStatsNotesMediaQFrame);
        notesMediaQFrame->setObjectName(QString::fromUtf8("notesMediaQFrame"));
        notesMediaQFrame->setGeometry(QRect(0, 510, 1011, 151));
        notesMediaQFrame->setFrameShape(QFrame::NoFrame);
        notesMediaQFrame->setFrameShadow(QFrame::Raised);
        notesMediaQGroupBox = new QGroupBox(notesMediaQFrame);
        notesMediaQGroupBox->setObjectName(QString::fromUtf8("notesMediaQGroupBox"));
        notesMediaQGroupBox->setGeometry(QRect(20, 10, 971, 131));
        notesMediaQGroupBox->setFlat(false);
        notesQTextEdit = new QTextEdit(notesMediaQGroupBox);
        notesQTextEdit->setObjectName(QString::fromUtf8("notesQTextEdit"));
        notesQTextEdit->setGeometry(QRect(10, 30, 471, 91));
        filesQListWidget = new QListWidget(notesMediaQGroupBox);
        new QListWidgetItem(filesQListWidget);
        new QListWidgetItem(filesQListWidget);
        new QListWidgetItem(filesQListWidget);
        filesQListWidget->setObjectName(QString::fromUtf8("filesQListWidget"));
        filesQListWidget->setGeometry(QRect(490, 30, 351, 91));
        filesQListWidget->setAlternatingRowColors(true);
        filesQListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        addFileQCommandLinkButton = new QCommandLinkButton(notesMediaQGroupBox);
        addFileQCommandLinkButton->setObjectName(QString::fromUtf8("addFileQCommandLinkButton"));
        addFileQCommandLinkButton->setGeometry(QRect(850, 40, 81, 31));
        removeFileQCommandLinkButton = new QCommandLinkButton(notesMediaQGroupBox);
        removeFileQCommandLinkButton->setObjectName(QString::fromUtf8("removeFileQCommandLinkButton"));
        removeFileQCommandLinkButton->setGeometry(QRect(850, 70, 91, 31));
        bottomBarQFrame = new QFrame(CommStatsQWidget);
        bottomBarQFrame->setObjectName(QString::fromUtf8("bottomBarQFrame"));
        bottomBarQFrame->setGeometry(QRect(0, 690, 1280, 31));
        bottomBarQFrame->setFrameShape(QFrame::NoFrame);
        bottomBarQFrame->setFrameShadow(QFrame::Raised);
        bottomBarStatsQLabel = new QLabel(bottomBarQFrame);
        bottomBarStatsQLabel->setObjectName(QString::fromUtf8("bottomBarStatsQLabel"));
        bottomBarStatsQLabel->setGeometry(QRect(470, 0, 401, 21));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        bottomBarStatsQLabel->setFont(font3);
        topBarQFrame = new QFrame(CommStatsQWidget);
        topBarQFrame->setObjectName(QString::fromUtf8("topBarQFrame"));
        topBarQFrame->setGeometry(QRect(0, 0, 1281, 41));
        topBarQFrame->setFrameShape(QFrame::NoFrame);
        topBarQFrame->setFrameShadow(QFrame::Raised);
        addCommitmentQCommandLinkButton = new QCommandLinkButton(topBarQFrame);
        addCommitmentQCommandLinkButton->setObjectName(QString::fromUtf8("addCommitmentQCommandLinkButton"));
        addCommitmentQCommandLinkButton->setGeometry(QRect(0, 0, 141, 31));
        removeCommitmentQCommandLinkButton = new QCommandLinkButton(topBarQFrame);
        removeCommitmentQCommandLinkButton->setObjectName(QString::fromUtf8("removeCommitmentQCommandLinkButton"));
        removeCommitmentQCommandLinkButton->setGeometry(QRect(140, 0, 131, 31));
        removeCommitmentQCommandLinkButton->setIconSize(QSize(20, 20));

        retranslateUi(CommStatsQWidget);

        QMetaObject::connectSlotsByName(CommStatsQWidget);
    } // setupUi

    void retranslateUi(QWidget *CommStatsQWidget)
    {
        CommStatsQWidget->setWindowTitle(QApplication::translate("CommStatsQWidget", "Tasker - My Commitments", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = commitmentsQTreeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("CommStatsQWidget", "COMMITMENTS", nullptr));

        const bool __sortingEnabled = commitmentsQTreeWidget->isSortingEnabled();
        commitmentsQTreeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = commitmentsQTreeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("CommStatsQWidget", "Untitled Commitment 0", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("CommStatsQWidget", "Session 0 (00/00/00)", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("CommStatsQWidget", "Session 1 (00/00/00)", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("CommStatsQWidget", "Session 2 (00/00/00)", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = commitmentsQTreeWidget->topLevelItem(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("CommStatsQWidget", "Untitled Commitment 1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("CommStatsQWidget", "(no commitments yet)", nullptr));
        commitmentsQTreeWidget->setSortingEnabled(__sortingEnabled);

#ifndef QT_NO_ACCESSIBILITY
        overviewQGroupBox->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        overviewQGroupBox->setTitle(QApplication::translate("CommStatsQWidget", "Untitled Commitment - Session 0", nullptr));
        totalTimeProductiveQLabel->setText(QApplication::translate("CommStatsQWidget", "PRODUCTIVE TIME", nullptr));
        totalTimeUnproductiveQLabel->setText(QApplication::translate("CommStatsQWidget", "UNPRODUCTIVE TIME", nullptr));
        durationProductiveQLabel->setText(QApplication::translate("CommStatsQWidget", "(00:00:00)", nullptr));
        durationUnproductiveQLabel->setText(QApplication::translate("CommStatsQWidget", "(00:00:00)", nullptr));
        totalTimeSumQLabel->setText(QApplication::translate("CommStatsQWidget", "TOTAL TIME", nullptr));
        durationTotalSumQLabel->setText(QApplication::translate("CommStatsQWidget", "(00:00:00)", nullptr));
        notesMediaQGroupBox->setTitle(QApplication::translate("CommStatsQWidget", "NOTES/MEDIA", nullptr));
        notesQTextEdit->setHtml(QApplication::translate("CommStatsQWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text';\">(write some notes here...)</span></p></body></html>", nullptr));

        const bool __sortingEnabled1 = filesQListWidget->isSortingEnabled();
        filesQListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = filesQListWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("CommStatsQWidget", "file_0.mp3", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = filesQListWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("CommStatsQWidget", "file_1.jpg", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = filesQListWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("CommStatsQWidget", "file_2.cpp", nullptr));
        filesQListWidget->setSortingEnabled(__sortingEnabled1);

        addFileQCommandLinkButton->setText(QApplication::translate("CommStatsQWidget", "Add file", nullptr));
        removeFileQCommandLinkButton->setText(QApplication::translate("CommStatsQWidget", "Remove file", nullptr));
        bottomBarStatsQLabel->setText(QApplication::translate("CommStatsQWidget", "2 total commitments, 00:00:00 productive time, 00:00:00 unproductive time", nullptr));
        addCommitmentQCommandLinkButton->setText(QApplication::translate("CommStatsQWidget", "Add new commitment", nullptr));
        removeCommitmentQCommandLinkButton->setText(QApplication::translate("CommStatsQWidget", "Remove commitment", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommStatsQWidget: public Ui_CommStatsQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMSTATSQWIDGET_H

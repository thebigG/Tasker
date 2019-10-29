/********************************************************************************
** Form generated from reading UI file 'Widget_CommStats.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_COMMSTATS_H
#define UI_WIDGET_COMMSTATS_H

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

class Ui_Widget_CommStats
{
public:
    QFrame *Frame_Commitments;
    QTreeWidget *TreeWidget_Commitments;
    QFrame *Frame_OverviewStatsNotesMedia;
    QFrame *Frame_Overview;
    QGroupBox *GroupBox_Overview;
    QProgressBar *ProgressBar_Productive;
    QProgressBar *ProgressBar_Unproductive;
    QLabel *Label_ProductiveTime;
    QLabel *Label_UnproductiveTime;
    QLabel *Label_DurationProductive;
    QLabel *Label_DurationUnproductive;
    QLabel *Label_TotalTime;
    QLabel *Label_DurationTotal;
    QFrame *Frame_Stats;
    QFrame *Frame_NotesMedia;
    QGroupBox *GroupBox_NotesMedia;
    QTextEdit *TextEdit_Notes;
    QListWidget *ListWidget_Files;
    QCommandLinkButton *CommandLinkButton_AddFile;
    QCommandLinkButton *CommandLinkButton_RemoveFile;
    QFrame *Frame_BottomBar;
    QLabel *label;
    QFrame *Frame_TopBar;
    QCommandLinkButton *CommandLinkButton_AddNewCommitment;
    QCommandLinkButton *CommandLinkButton_RemoveCommitment;

    void setupUi(QWidget *Widget_CommStats)
    {
        if (Widget_CommStats->objectName().isEmpty())
            Widget_CommStats->setObjectName(QString::fromUtf8("Widget_CommStats"));
        Widget_CommStats->resize(1280, 720);
        Frame_Commitments = new QFrame(Widget_CommStats);
        Frame_Commitments->setObjectName(QString::fromUtf8("Frame_Commitments"));
        Frame_Commitments->setGeometry(QRect(0, 30, 271, 661));
        Frame_Commitments->setFrameShape(QFrame::NoFrame);
        Frame_Commitments->setFrameShadow(QFrame::Raised);
        TreeWidget_Commitments = new QTreeWidget(Frame_Commitments);
        QBrush brush(QColor(108, 108, 108, 255));
        brush.setStyle(Qt::NoBrush);
        QFont font;
        font.setItalic(true);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(TreeWidget_Commitments);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(TreeWidget_Commitments);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem2->setFont(0, font);
        __qtreewidgetitem2->setBackground(0, brush);
        TreeWidget_Commitments->setObjectName(QString::fromUtf8("TreeWidget_Commitments"));
        TreeWidget_Commitments->setEnabled(true);
        TreeWidget_Commitments->setGeometry(QRect(0, 0, 270, 661));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TreeWidget_Commitments->sizePolicy().hasHeightForWidth());
        TreeWidget_Commitments->setSizePolicy(sizePolicy);
        TreeWidget_Commitments->setFrameShape(QFrame::StyledPanel);
        TreeWidget_Commitments->setFrameShadow(QFrame::Plain);
        TreeWidget_Commitments->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        TreeWidget_Commitments->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        TreeWidget_Commitments->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        TreeWidget_Commitments->setAutoScroll(true);
        TreeWidget_Commitments->setAlternatingRowColors(true);
        TreeWidget_Commitments->setSelectionMode(QAbstractItemView::SingleSelection);
        TreeWidget_Commitments->header()->setVisible(false);
        Frame_OverviewStatsNotesMedia = new QFrame(Widget_CommStats);
        Frame_OverviewStatsNotesMedia->setObjectName(QString::fromUtf8("Frame_OverviewStatsNotesMedia"));
        Frame_OverviewStatsNotesMedia->setGeometry(QRect(271, 30, 1011, 661));
        Frame_OverviewStatsNotesMedia->setFrameShape(QFrame::NoFrame);
        Frame_OverviewStatsNotesMedia->setFrameShadow(QFrame::Raised);
        Frame_Overview = new QFrame(Frame_OverviewStatsNotesMedia);
        Frame_Overview->setObjectName(QString::fromUtf8("Frame_Overview"));
        Frame_Overview->setGeometry(QRect(0, 0, 1011, 121));
        Frame_Overview->setFrameShape(QFrame::NoFrame);
        Frame_Overview->setFrameShadow(QFrame::Raised);
        GroupBox_Overview = new QGroupBox(Frame_Overview);
        GroupBox_Overview->setObjectName(QString::fromUtf8("GroupBox_Overview"));
        GroupBox_Overview->setGeometry(QRect(20, 20, 971, 88));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        GroupBox_Overview->setFont(font1);
        ProgressBar_Productive = new QProgressBar(GroupBox_Overview);
        ProgressBar_Productive->setObjectName(QString::fromUtf8("ProgressBar_Productive"));
        ProgressBar_Productive->setGeometry(QRect(50, 30, 441, 16));
        ProgressBar_Productive->setMinimum(0);
        ProgressBar_Productive->setValue(75);
        ProgressBar_Unproductive = new QProgressBar(GroupBox_Overview);
        ProgressBar_Unproductive->setObjectName(QString::fromUtf8("ProgressBar_Unproductive"));
        ProgressBar_Unproductive->setGeometry(QRect(50, 50, 441, 16));
        ProgressBar_Unproductive->setValue(25);
        ProgressBar_Unproductive->setInvertedAppearance(true);
        Label_ProductiveTime = new QLabel(GroupBox_Overview);
        Label_ProductiveTime->setObjectName(QString::fromUtf8("Label_ProductiveTime"));
        Label_ProductiveTime->setGeometry(QRect(500, 25, 141, 16));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        Label_ProductiveTime->setFont(font2);
        Label_UnproductiveTime = new QLabel(GroupBox_Overview);
        Label_UnproductiveTime->setObjectName(QString::fromUtf8("Label_UnproductiveTime"));
        Label_UnproductiveTime->setGeometry(QRect(500, 45, 141, 16));
        Label_UnproductiveTime->setFont(font2);
        Label_DurationProductive = new QLabel(GroupBox_Overview);
        Label_DurationProductive->setObjectName(QString::fromUtf8("Label_DurationProductive"));
        Label_DurationProductive->setGeometry(QRect(660, 25, 71, 16));
        Label_DurationUnproductive = new QLabel(GroupBox_Overview);
        Label_DurationUnproductive->setObjectName(QString::fromUtf8("Label_DurationUnproductive"));
        Label_DurationUnproductive->setGeometry(QRect(660, 45, 71, 16));
        Label_TotalTime = new QLabel(GroupBox_Overview);
        Label_TotalTime->setObjectName(QString::fromUtf8("Label_TotalTime"));
        Label_TotalTime->setGeometry(QRect(500, 65, 141, 16));
        Label_TotalTime->setFont(font2);
        Label_DurationTotal = new QLabel(GroupBox_Overview);
        Label_DurationTotal->setObjectName(QString::fromUtf8("Label_DurationTotal"));
        Label_DurationTotal->setGeometry(QRect(660, 65, 71, 16));
        Frame_Stats = new QFrame(Frame_OverviewStatsNotesMedia);
        Frame_Stats->setObjectName(QString::fromUtf8("Frame_Stats"));
        Frame_Stats->setGeometry(QRect(-10, 120, 1021, 391));
        Frame_Stats->setFrameShape(QFrame::NoFrame);
        Frame_Stats->setFrameShadow(QFrame::Raised);
        Frame_NotesMedia = new QFrame(Frame_OverviewStatsNotesMedia);
        Frame_NotesMedia->setObjectName(QString::fromUtf8("Frame_NotesMedia"));
        Frame_NotesMedia->setGeometry(QRect(0, 510, 1011, 151));
        Frame_NotesMedia->setFrameShape(QFrame::NoFrame);
        Frame_NotesMedia->setFrameShadow(QFrame::Raised);
        GroupBox_NotesMedia = new QGroupBox(Frame_NotesMedia);
        GroupBox_NotesMedia->setObjectName(QString::fromUtf8("GroupBox_NotesMedia"));
        GroupBox_NotesMedia->setGeometry(QRect(20, 10, 971, 131));
        GroupBox_NotesMedia->setFlat(false);
        TextEdit_Notes = new QTextEdit(GroupBox_NotesMedia);
        TextEdit_Notes->setObjectName(QString::fromUtf8("TextEdit_Notes"));
        TextEdit_Notes->setGeometry(QRect(10, 30, 471, 91));
        ListWidget_Files = new QListWidget(GroupBox_NotesMedia);
        new QListWidgetItem(ListWidget_Files);
        new QListWidgetItem(ListWidget_Files);
        new QListWidgetItem(ListWidget_Files);
        ListWidget_Files->setObjectName(QString::fromUtf8("ListWidget_Files"));
        ListWidget_Files->setGeometry(QRect(490, 30, 351, 91));
        ListWidget_Files->setAlternatingRowColors(true);
        ListWidget_Files->setSelectionMode(QAbstractItemView::ExtendedSelection);
        CommandLinkButton_AddFile = new QCommandLinkButton(GroupBox_NotesMedia);
        CommandLinkButton_AddFile->setObjectName(QString::fromUtf8("CommandLinkButton_AddFile"));
        CommandLinkButton_AddFile->setGeometry(QRect(850, 40, 81, 31));
        CommandLinkButton_RemoveFile = new QCommandLinkButton(GroupBox_NotesMedia);
        CommandLinkButton_RemoveFile->setObjectName(QString::fromUtf8("CommandLinkButton_RemoveFile"));
        CommandLinkButton_RemoveFile->setGeometry(QRect(850, 70, 91, 31));
        Frame_BottomBar = new QFrame(Widget_CommStats);
        Frame_BottomBar->setObjectName(QString::fromUtf8("Frame_BottomBar"));
        Frame_BottomBar->setGeometry(QRect(0, 690, 1280, 31));
        Frame_BottomBar->setFrameShape(QFrame::NoFrame);
        Frame_BottomBar->setFrameShadow(QFrame::Raised);
        label = new QLabel(Frame_BottomBar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(470, 0, 401, 21));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        Frame_TopBar = new QFrame(Widget_CommStats);
        Frame_TopBar->setObjectName(QString::fromUtf8("Frame_TopBar"));
        Frame_TopBar->setGeometry(QRect(0, 0, 1281, 41));
        Frame_TopBar->setFrameShape(QFrame::NoFrame);
        Frame_TopBar->setFrameShadow(QFrame::Raised);
        CommandLinkButton_AddNewCommitment = new QCommandLinkButton(Frame_TopBar);
        CommandLinkButton_AddNewCommitment->setObjectName(QString::fromUtf8("CommandLinkButton_AddNewCommitment"));
        CommandLinkButton_AddNewCommitment->setGeometry(QRect(0, 0, 141, 31));
        CommandLinkButton_RemoveCommitment = new QCommandLinkButton(Frame_TopBar);
        CommandLinkButton_RemoveCommitment->setObjectName(QString::fromUtf8("CommandLinkButton_RemoveCommitment"));
        CommandLinkButton_RemoveCommitment->setGeometry(QRect(140, 0, 131, 31));
        CommandLinkButton_RemoveCommitment->setIconSize(QSize(20, 20));

        retranslateUi(Widget_CommStats);

        QMetaObject::connectSlotsByName(Widget_CommStats);
    } // setupUi

    void retranslateUi(QWidget *Widget_CommStats)
    {
        Widget_CommStats->setWindowTitle(QApplication::translate("Widget_CommStats", "Tasker - My Commitments", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = TreeWidget_Commitments->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Widget_CommStats", "COMMITMENTS", nullptr));

        const bool __sortingEnabled = TreeWidget_Commitments->isSortingEnabled();
        TreeWidget_Commitments->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = TreeWidget_Commitments->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("Widget_CommStats", "Untitled Commitment 0", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("Widget_CommStats", "Session 0 (00/00/00)", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("Widget_CommStats", "Session 1 (00/00/00)", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("Widget_CommStats", "Session 2 (00/00/00)", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = TreeWidget_Commitments->topLevelItem(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("Widget_CommStats", "Untitled Commitment 1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("Widget_CommStats", "(no commitments yet)", nullptr));
        TreeWidget_Commitments->setSortingEnabled(__sortingEnabled);

#ifndef QT_NO_ACCESSIBILITY
        GroupBox_Overview->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        GroupBox_Overview->setTitle(QApplication::translate("Widget_CommStats", "Untitled Commitment - Session 0", nullptr));
        Label_ProductiveTime->setText(QApplication::translate("Widget_CommStats", "PRODUCTIVE TIME", nullptr));
        Label_UnproductiveTime->setText(QApplication::translate("Widget_CommStats", "UNPRODUCTIVE TIME", nullptr));
        Label_DurationProductive->setText(QApplication::translate("Widget_CommStats", "(00:00:00)", nullptr));
        Label_DurationUnproductive->setText(QApplication::translate("Widget_CommStats", "(00:00:00)", nullptr));
        Label_TotalTime->setText(QApplication::translate("Widget_CommStats", "TOTAL TIME", nullptr));
        Label_DurationTotal->setText(QApplication::translate("Widget_CommStats", "(00:00:00)", nullptr));
        GroupBox_NotesMedia->setTitle(QApplication::translate("Widget_CommStats", "NOTES/MEDIA", nullptr));
        TextEdit_Notes->setHtml(QApplication::translate("Widget_CommStats", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text';\">(write some notes here...)</span></p></body></html>", nullptr));

        const bool __sortingEnabled1 = ListWidget_Files->isSortingEnabled();
        ListWidget_Files->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = ListWidget_Files->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Widget_CommStats", "file_0.mp3", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = ListWidget_Files->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Widget_CommStats", "file_1.jpg", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = ListWidget_Files->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Widget_CommStats", "file_2.cpp", nullptr));
        ListWidget_Files->setSortingEnabled(__sortingEnabled1);

        CommandLinkButton_AddFile->setText(QApplication::translate("Widget_CommStats", "Add file", nullptr));
        CommandLinkButton_RemoveFile->setText(QApplication::translate("Widget_CommStats", "Remove file", nullptr));
        label->setText(QApplication::translate("Widget_CommStats", "2 total commitments, 00:00:00 productive time, 00:00:00 unproductive time", nullptr));
        CommandLinkButton_AddNewCommitment->setText(QApplication::translate("Widget_CommStats", "Add new commitment", nullptr));
        CommandLinkButton_RemoveCommitment->setText(QApplication::translate("Widget_CommStats", "Remove commitment", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_CommStats: public Ui_Widget_CommStats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_COMMSTATS_H

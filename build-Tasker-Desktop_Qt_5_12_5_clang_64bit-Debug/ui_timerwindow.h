/********************************************************************************
** Form generated from reading UI file 'timerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMERWINDOW_H
#define UI_TIMERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_timerwindow
{
public:
    QFrame *QFrame_TimerWindow;
    QLabel *label;
    QPushButton *startTimerButton;
    QPushButton *pushButton_2;
    QFrame *frame;
    QComboBox *comboBox_2;
    QLabel *label_8;
    QComboBox *comboBox_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QLabel *label_9;
    QFrame *frame_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QFrame *frame_3;
    QLabel *label_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QFrame *frame_4;
    QLabel *label_5;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QFrame *PTTimer_Frame;
    QSpinBox *PTmSec;
    QLabel *label_2;
    QSpinBox *PTSec;
    QSpinBox *PTHrs;
    QSpinBox *PTMin;
    QLabel *label_6;

    void setupUi(QWidget *timerwindow)
    {
        if (timerwindow->objectName().isEmpty())
            timerwindow->setObjectName(QString::fromUtf8("timerwindow"));
        timerwindow->resize(450, 450);
        QFrame_TimerWindow = new QFrame(timerwindow);
        QFrame_TimerWindow->setObjectName(QString::fromUtf8("QFrame_TimerWindow"));
        QFrame_TimerWindow->setGeometry(QRect(0, 0, 451, 451));
        QFrame_TimerWindow->setFrameShape(QFrame::NoFrame);
        QFrame_TimerWindow->setFrameShadow(QFrame::Raised);
        label = new QLabel(QFrame_TimerWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 50, 181, 16));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        startTimerButton = new QPushButton(QFrame_TimerWindow);
        startTimerButton->setObjectName(QString::fromUtf8("startTimerButton"));
        startTimerButton->setGeometry(QRect(40, 410, 141, 24));
        pushButton_2 = new QPushButton(QFrame_TimerWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 410, 80, 24));
        frame = new QFrame(QFrame_TimerWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(40, 290, 301, 101));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        comboBox_2 = new QComboBox(frame);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(150, 0, 141, 25));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(100, 0, 31, 25));
        comboBox_3 = new QComboBox(frame);
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(50, 70, 121, 25));
        checkBox_2 = new QCheckBox(frame);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(0, 70, 83, 25));
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(0, 50, 83, 22));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 30, 58, 16));
        frame_2 = new QFrame(QFrame_TimerWindow);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(40, 170, 151, 21));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 81, 25));
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(-60, 80, 113, 21));
        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 0, 81, 25));
        lineEdit_2->setInputMethodHints(Qt::ImhTime);
        lineEdit_2->setMaxLength(11);
        frame_3 = new QFrame(QFrame_TimerWindow);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(200, 210, 141, 71));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 161, 16));
        radioButton = new QRadioButton(frame_3);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(0, 20, 151, 19));
        radioButton_2 = new QRadioButton(frame_3);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(0, 52, 111, 19));
        radioButton_3 = new QRadioButton(frame_3);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(0, 36, 111, 19));
        frame_4 = new QFrame(QFrame_TimerWindow);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(40, 210, 161, 71));
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 161, 16));
        radioButton_4 = new QRadioButton(frame_4);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(0, 20, 141, 19));
        radioButton_5 = new QRadioButton(frame_4);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(0, 52, 111, 19));
        radioButton_6 = new QRadioButton(frame_4);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(0, 36, 111, 19));
        PTTimer_Frame = new QFrame(QFrame_TimerWindow);
        PTTimer_Frame->setObjectName(QString::fromUtf8("PTTimer_Frame"));
        PTTimer_Frame->setGeometry(QRect(60, 70, 251, 101));
        PTTimer_Frame->setFrameShape(QFrame::NoFrame);
        PTTimer_Frame->setFrameShadow(QFrame::Raised);
        PTmSec = new QSpinBox(PTTimer_Frame);
        PTmSec->setObjectName(QString::fromUtf8("PTmSec"));
        PTmSec->setGeometry(QRect(180, 20, 61, 51));
        QFont font1;
        font1.setPointSize(24);
        PTmSec->setFont(font1);
        PTmSec->setFrame(false);
        PTmSec->setMaximum(59);
        PTmSec->setValue(0);
        label_2 = new QLabel(PTTimer_Frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 151, 16));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        PTSec = new QSpinBox(PTTimer_Frame);
        PTSec->setObjectName(QString::fromUtf8("PTSec"));
        PTSec->setGeometry(QRect(120, 20, 61, 51));
        PTSec->setFont(font1);
        PTSec->setFrame(false);
        PTSec->setMaximum(59);
        PTSec->setValue(0);
        PTHrs = new QSpinBox(PTTimer_Frame);
        PTHrs->setObjectName(QString::fromUtf8("PTHrs"));
        PTHrs->setGeometry(QRect(0, 20, 61, 51));
        PTHrs->setFont(font1);
        PTHrs->setFrame(false);
        PTHrs->setValue(0);
        PTMin = new QSpinBox(PTTimer_Frame);
        PTMin->setObjectName(QString::fromUtf8("PTMin"));
        PTMin->setGeometry(QRect(60, 20, 61, 51));
        PTMin->setFont(font1);
        PTMin->setFrame(false);
        PTMin->setMaximum(59);
        PTMin->setValue(0);
        label_6 = new QLabel(PTTimer_Frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 70, 231, 16));

        retranslateUi(timerwindow);

        QMetaObject::connectSlotsByName(timerwindow);
    } // setupUi

    void retranslateUi(QWidget *timerwindow)
    {
        timerwindow->setWindowTitle(QApplication::translate("timerwindow", "Tasker - Session", nullptr));
        label->setText(QApplication::translate("timerwindow", "Timer", nullptr));
        startTimerButton->setText(QApplication::translate("timerwindow", "Start", nullptr));
        pushButton_2->setText(QApplication::translate("timerwindow", "Back", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("timerwindow", "Writing", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("timerwindow", "Compose Music", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("timerwindow", "Custom", nullptr));

        label_8->setText(QApplication::translate("timerwindow", "Task:", nullptr));
        comboBox_3->setItemText(0, QApplication::translate("timerwindow", "Built-In Mic", nullptr));

        checkBox_2->setText(QApplication::translate("timerwindow", "Mic", nullptr));
        checkBox->setText(QApplication::translate("timerwindow", "Keyboard", nullptr));
        label_9->setText(QApplication::translate("timerwindow", "Listeners:", nullptr));
        label_3->setText(QApplication::translate("timerwindow", "Real Time: ", nullptr));
        lineEdit_2->setText(QApplication::translate("timerwindow", "00:00:00:00", nullptr));
        label_4->setText(QApplication::translate("timerwindow", "Real-time Timer Alert", nullptr));
        radioButton->setText(QApplication::translate("timerwindow", "Alert when finished", nullptr));
        radioButton_2->setText(QApplication::translate("timerwindow", "Off", nullptr));
#ifndef QT_NO_TOOLTIP
        radioButton_3->setToolTip(QApplication::translate("timerwindow", "Waits for you to pause your work before alerting you that your time is up", nullptr));
#endif // QT_NO_TOOLTIP
        radioButton_3->setText(QApplication::translate("timerwindow", "Wait for pause", nullptr));
        label_5->setText(QApplication::translate("timerwindow", "Production Timer Alert", nullptr));
        radioButton_4->setText(QApplication::translate("timerwindow", "Alert when finished", nullptr));
        radioButton_5->setText(QApplication::translate("timerwindow", "Off", nullptr));
#ifndef QT_NO_TOOLTIP
        radioButton_6->setToolTip(QApplication::translate("timerwindow", "Waits for you to pause your work before alerting you that your time is up", nullptr));
#endif // QT_NO_TOOLTIP
        radioButton_6->setText(QApplication::translate("timerwindow", "Wait for pause", nullptr));
#ifndef QT_NO_TOOLTIP
        PTmSec->setToolTip(QApplication::translate("timerwindow", "Milliseconds", nullptr));
#endif // QT_NO_TOOLTIP
        PTmSec->setPrefix(QApplication::translate("timerwindow", ":", nullptr));
        label_2->setText(QApplication::translate("timerwindow", "Production Time", nullptr));
#ifndef QT_NO_TOOLTIP
        PTSec->setToolTip(QApplication::translate("timerwindow", "Seconds", nullptr));
#endif // QT_NO_TOOLTIP
        PTSec->setPrefix(QApplication::translate("timerwindow", ":", nullptr));
#ifndef QT_NO_TOOLTIP
        PTHrs->setToolTip(QApplication::translate("timerwindow", "Hours", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        PTMin->setToolTip(QApplication::translate("timerwindow", "Minutes", nullptr));
#endif // QT_NO_TOOLTIP
        PTMin->setPrefix(QApplication::translate("timerwindow", ":", nullptr));
        label_6->setText(QApplication::translate("timerwindow", "Hrs           Min           Sec          mSec", nullptr));
    } // retranslateUi

};

namespace Ui {
    class timerwindow: public Ui_timerwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERWINDOW_H

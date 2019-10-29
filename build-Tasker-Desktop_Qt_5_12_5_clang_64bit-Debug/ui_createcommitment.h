/********************************************************************************
** Form generated from reading UI file 'createcommitment.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECOMMITMENT_H
#define UI_CREATECOMMITMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createcommitment
{
public:
    QFrame *QFrame_CreateCommitment;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *comboBox;
    QLabel *label_8;
    QComboBox *comboBox_2;
    QLabel *label_9;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QComboBox *comboBox_3;
    QCheckBox *checkBox_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *createcommitment)
    {
        if (createcommitment->objectName().isEmpty())
            createcommitment->setObjectName(QString::fromUtf8("createcommitment"));
        createcommitment->resize(450, 450);
        QFrame_CreateCommitment = new QFrame(createcommitment);
        QFrame_CreateCommitment->setObjectName(QString::fromUtf8("QFrame_CreateCommitment"));
        QFrame_CreateCommitment->setGeometry(QRect(0, 0, 451, 451));
        QFrame_CreateCommitment->setFrameShape(QFrame::StyledPanel);
        QFrame_CreateCommitment->setFrameShadow(QFrame::Raised);
        label = new QLabel(QFrame_CreateCommitment);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 50, 181, 16));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        lineEdit = new QLineEdit(QFrame_CreateCommitment);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(240, 50, 141, 24));
        label_2 = new QLabel(QFrame_CreateCommitment);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 110, 61, 16));
        label_3 = new QLabel(QFrame_CreateCommitment);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 110, 58, 16));
        dateEdit = new QDateEdit(QFrame_CreateCommitment);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(70, 130, 110, 25));
        dateEdit_2 = new QDateEdit(QFrame_CreateCommitment);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(240, 130, 110, 25));
        label_4 = new QLabel(QFrame_CreateCommitment);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 170, 21, 16));
        lineEdit_2 = new QLineEdit(QFrame_CreateCommitment);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 190, 41, 24));
        label_5 = new QLabel(QFrame_CreateCommitment);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 170, 58, 16));
        lineEdit_3 = new QLineEdit(QFrame_CreateCommitment);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 190, 41, 24));
        label_6 = new QLabel(QFrame_CreateCommitment);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(190, 190, 21, 16));
        label_7 = new QLabel(QFrame_CreateCommitment);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(250, 170, 58, 16));
        comboBox = new QComboBox(QFrame_CreateCommitment);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(240, 190, 79, 24));
        label_8 = new QLabel(QFrame_CreateCommitment);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 240, 31, 16));
        comboBox_2 = new QComboBox(QFrame_CreateCommitment);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(80, 240, 79, 24));
        label_9 = new QLabel(QFrame_CreateCommitment);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(70, 290, 58, 16));
        checkBox = new QCheckBox(QFrame_CreateCommitment);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(70, 310, 83, 22));
        checkBox_2 = new QCheckBox(QFrame_CreateCommitment);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(70, 330, 83, 22));
        comboBox_3 = new QComboBox(QFrame_CreateCommitment);
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(120, 330, 111, 24));
        checkBox_3 = new QCheckBox(QFrame_CreateCommitment);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(50, 380, 231, 22));
        pushButton = new QPushButton(QFrame_CreateCommitment);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 410, 141, 24));
        pushButton_2 = new QPushButton(QFrame_CreateCommitment);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 410, 80, 24));

        retranslateUi(createcommitment);

        QMetaObject::connectSlotsByName(createcommitment);
    } // setupUi

    void retranslateUi(QWidget *createcommitment)
    {
        createcommitment->setWindowTitle(QApplication::translate("createcommitment", "Create a Commitment", nullptr));
        label->setText(QApplication::translate("createcommitment", "Commitment Name:", nullptr));
        label_2->setText(QApplication::translate("createcommitment", "Start Date", nullptr));
        label_3->setText(QApplication::translate("createcommitment", "End Date", nullptr));
        label_4->setText(QApplication::translate("createcommitment", "Qty", nullptr));
        lineEdit_2->setText(QApplication::translate("createcommitment", "1", nullptr));
        label_5->setText(QApplication::translate("createcommitment", "Units", nullptr));
        lineEdit_3->setText(QApplication::translate("createcommitment", "hr", nullptr));
        label_6->setText(QApplication::translate("createcommitment", "per", nullptr));
        label_7->setText(QApplication::translate("createcommitment", "Units", nullptr));
        comboBox->setItemText(0, QApplication::translate("createcommitment", "Day", nullptr));
        comboBox->setItemText(1, QApplication::translate("createcommitment", "Week", nullptr));
        comboBox->setItemText(2, QApplication::translate("createcommitment", "Month", nullptr));

        label_8->setText(QApplication::translate("createcommitment", "Task:", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("createcommitment", "Writing", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("createcommitment", "Compose Music", nullptr));

        label_9->setText(QApplication::translate("createcommitment", "Listeners:", nullptr));
        checkBox->setText(QApplication::translate("createcommitment", "Keyboard", nullptr));
        checkBox_2->setText(QApplication::translate("createcommitment", "Mic", nullptr));
        comboBox_3->setItemText(0, QApplication::translate("createcommitment", "Built-In Mic", nullptr));

        checkBox_3->setText(QApplication::translate("createcommitment", "Make this my default commitment", nullptr));
        pushButton->setText(QApplication::translate("createcommitment", "Create Commitment", nullptr));
        pushButton_2->setText(QApplication::translate("createcommitment", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createcommitment: public Ui_createcommitment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECOMMITMENT_H

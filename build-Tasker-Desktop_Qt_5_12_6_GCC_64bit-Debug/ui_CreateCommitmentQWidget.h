/********************************************************************************
** Form generated from reading UI file 'CreateCommitmentQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECOMMITMENTQWIDGET_H
#define UI_CREATECOMMITMENTQWIDGET_H

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

class Ui_CreateCommitmentQWidget
{
public:
    QFrame *createCommitmentQFrame;
    QLabel *commitmentNameQLabel;
    QLineEdit *commitmentNameQLineEdit;
    QLabel *dateStartQLabel;
    QLabel *dateEndQLabel;
    QDateEdit *dateStartQDateEdit;
    QDateEdit *dateEndQDateEdit;
    QLabel *qtyQLabel;
    QLineEdit *qtyQLineEdit;
    QLabel *unitsLeftQLabel;
    QLabel *perQLabel;
    QLabel *unitsRightQLabel;
    QComboBox *dropDownUnitsRightQComboBox;
    QLabel *taskQLabel;
    QComboBox *dropDownTaskQComboBox;
    QLabel *listenersQLabel;
    QCheckBox *checkKeyboardQCheckBox;
    QCheckBox *checkMicQCheckBox;
    QComboBox *dropDownAudioListenerQComboBox;
    QCheckBox *makeDefaultQCheckBox;
    QPushButton *createCommitmentQPushButton;
    QPushButton *backQPushButton;
    QComboBox *dropDownUnitsLeftQComboBox;

    void setupUi(QWidget *CreateCommitmentQWidget)
    {
        if (CreateCommitmentQWidget->objectName().isEmpty())
            CreateCommitmentQWidget->setObjectName(QString::fromUtf8("CreateCommitmentQWidget"));
        CreateCommitmentQWidget->resize(450, 450);
        createCommitmentQFrame = new QFrame(CreateCommitmentQWidget);
        createCommitmentQFrame->setObjectName(QString::fromUtf8("createCommitmentQFrame"));
        createCommitmentQFrame->setGeometry(QRect(0, 0, 451, 451));
        createCommitmentQFrame->setFrameShape(QFrame::StyledPanel);
        createCommitmentQFrame->setFrameShadow(QFrame::Raised);
        commitmentNameQLabel = new QLabel(createCommitmentQFrame);
        commitmentNameQLabel->setObjectName(QString::fromUtf8("commitmentNameQLabel"));
        commitmentNameQLabel->setGeometry(QRect(30, 40, 180, 20));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        commitmentNameQLabel->setFont(font);
        commitmentNameQLineEdit = new QLineEdit(createCommitmentQFrame);
        commitmentNameQLineEdit->setObjectName(QString::fromUtf8("commitmentNameQLineEdit"));
        commitmentNameQLineEdit->setGeometry(QRect(180, 40, 221, 20));
        dateStartQLabel = new QLabel(createCommitmentQFrame);
        dateStartQLabel->setObjectName(QString::fromUtf8("dateStartQLabel"));
        dateStartQLabel->setGeometry(QRect(70, 110, 70, 20));
        QFont font1;
        font1.setPointSize(10);
        dateStartQLabel->setFont(font1);
        dateEndQLabel = new QLabel(createCommitmentQFrame);
        dateEndQLabel->setObjectName(QString::fromUtf8("dateEndQLabel"));
        dateEndQLabel->setGeometry(QRect(240, 110, 70, 20));
        dateEndQLabel->setFont(font1);
        dateStartQDateEdit = new QDateEdit(createCommitmentQFrame);
        dateStartQDateEdit->setObjectName(QString::fromUtf8("dateStartQDateEdit"));
        dateStartQDateEdit->setGeometry(QRect(70, 130, 110, 25));
        dateEndQDateEdit = new QDateEdit(createCommitmentQFrame);
        dateEndQDateEdit->setObjectName(QString::fromUtf8("dateEndQDateEdit"));
        dateEndQDateEdit->setGeometry(QRect(240, 130, 110, 25));
        qtyQLabel = new QLabel(createCommitmentQFrame);
        qtyQLabel->setObjectName(QString::fromUtf8("qtyQLabel"));
        qtyQLabel->setGeometry(QRect(70, 170, 21, 16));
        qtyQLabel->setFont(font1);
        qtyQLineEdit = new QLineEdit(createCommitmentQFrame);
        qtyQLineEdit->setObjectName(QString::fromUtf8("qtyQLineEdit"));
        qtyQLineEdit->setGeometry(QRect(70, 190, 41, 25));
        unitsLeftQLabel = new QLabel(createCommitmentQFrame);
        unitsLeftQLabel->setObjectName(QString::fromUtf8("unitsLeftQLabel"));
        unitsLeftQLabel->setGeometry(QRect(120, 170, 58, 16));
        unitsLeftQLabel->setFont(font1);
        perQLabel = new QLabel(createCommitmentQFrame);
        perQLabel->setObjectName(QString::fromUtf8("perQLabel"));
        perQLabel->setGeometry(QRect(220, 190, 21, 25));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        perQLabel->setFont(font2);
        unitsRightQLabel = new QLabel(createCommitmentQFrame);
        unitsRightQLabel->setObjectName(QString::fromUtf8("unitsRightQLabel"));
        unitsRightQLabel->setGeometry(QRect(270, 170, 58, 16));
        unitsRightQLabel->setFont(font1);
        dropDownUnitsRightQComboBox = new QComboBox(createCommitmentQFrame);
        dropDownUnitsRightQComboBox->addItem(QString());
        dropDownUnitsRightQComboBox->addItem(QString());
        dropDownUnitsRightQComboBox->addItem(QString());
        dropDownUnitsRightQComboBox->setObjectName(QString::fromUtf8("dropDownUnitsRightQComboBox"));
        dropDownUnitsRightQComboBox->setGeometry(QRect(270, 190, 79, 25));
        QFont font3;
        font3.setPointSize(12);
        dropDownUnitsRightQComboBox->setFont(font3);
        taskQLabel = new QLabel(createCommitmentQFrame);
        taskQLabel->setObjectName(QString::fromUtf8("taskQLabel"));
        taskQLabel->setGeometry(QRect(140, 240, 31, 25));
        dropDownTaskQComboBox = new QComboBox(createCommitmentQFrame);
        dropDownTaskQComboBox->addItem(QString());
        dropDownTaskQComboBox->addItem(QString());
        dropDownTaskQComboBox->setObjectName(QString::fromUtf8("dropDownTaskQComboBox"));
        dropDownTaskQComboBox->setGeometry(QRect(180, 240, 91, 25));
        dropDownTaskQComboBox->setFont(font3);
        listenersQLabel = new QLabel(createCommitmentQFrame);
        listenersQLabel->setObjectName(QString::fromUtf8("listenersQLabel"));
        listenersQLabel->setGeometry(QRect(140, 280, 58, 25));
        checkKeyboardQCheckBox = new QCheckBox(createCommitmentQFrame);
        checkKeyboardQCheckBox->setObjectName(QString::fromUtf8("checkKeyboardQCheckBox"));
        checkKeyboardQCheckBox->setGeometry(QRect(140, 300, 83, 25));
        checkMicQCheckBox = new QCheckBox(createCommitmentQFrame);
        checkMicQCheckBox->setObjectName(QString::fromUtf8("checkMicQCheckBox"));
        checkMicQCheckBox->setGeometry(QRect(140, 320, 83, 25));
        dropDownAudioListenerQComboBox = new QComboBox(createCommitmentQFrame);
        dropDownAudioListenerQComboBox->addItem(QString());
        dropDownAudioListenerQComboBox->setObjectName(QString::fromUtf8("dropDownAudioListenerQComboBox"));
        dropDownAudioListenerQComboBox->setGeometry(QRect(230, 320, 121, 25));
        dropDownAudioListenerQComboBox->setFont(font3);
        makeDefaultQCheckBox = new QCheckBox(createCommitmentQFrame);
        makeDefaultQCheckBox->setObjectName(QString::fromUtf8("makeDefaultQCheckBox"));
        makeDefaultQCheckBox->setGeometry(QRect(40, 360, 231, 25));
        createCommitmentQPushButton = new QPushButton(createCommitmentQFrame);
        createCommitmentQPushButton->setObjectName(QString::fromUtf8("createCommitmentQPushButton"));
        createCommitmentQPushButton->setGeometry(QRect(40, 390, 150, 25));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setWeight(50);
        createCommitmentQPushButton->setFont(font4);
        backQPushButton = new QPushButton(createCommitmentQFrame);
        backQPushButton->setObjectName(QString::fromUtf8("backQPushButton"));
        backQPushButton->setGeometry(QRect(230, 390, 150, 25));
        backQPushButton->setFont(font3);
        dropDownUnitsLeftQComboBox = new QComboBox(createCommitmentQFrame);
        dropDownUnitsLeftQComboBox->addItem(QString());
        dropDownUnitsLeftQComboBox->addItem(QString());
        dropDownUnitsLeftQComboBox->setObjectName(QString::fromUtf8("dropDownUnitsLeftQComboBox"));
        dropDownUnitsLeftQComboBox->setGeometry(QRect(120, 190, 81, 25));
        dropDownUnitsLeftQComboBox->setFont(font3);

        retranslateUi(CreateCommitmentQWidget);

        QMetaObject::connectSlotsByName(CreateCommitmentQWidget);
    } // setupUi

    void retranslateUi(QWidget *CreateCommitmentQWidget)
    {
        CreateCommitmentQWidget->setWindowTitle(QApplication::translate("CreateCommitmentQWidget", "Create a Commitment", nullptr));
        commitmentNameQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Commitment Name:", nullptr));
        dateStartQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Start Date", nullptr));
        dateEndQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "End Date", nullptr));
        qtyQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Qty", nullptr));
        qtyQLineEdit->setText(QApplication::translate("CreateCommitmentQWidget", "1", nullptr));
        unitsLeftQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Units", nullptr));
        perQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "per", nullptr));
        unitsRightQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Units", nullptr));
        dropDownUnitsRightQComboBox->setItemText(0, QApplication::translate("CreateCommitmentQWidget", "Day", nullptr));
        dropDownUnitsRightQComboBox->setItemText(1, QApplication::translate("CreateCommitmentQWidget", "Week", nullptr));
        dropDownUnitsRightQComboBox->setItemText(2, QApplication::translate("CreateCommitmentQWidget", "Month", nullptr));

        taskQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Task:", nullptr));
        dropDownTaskQComboBox->setItemText(0, QApplication::translate("CreateCommitmentQWidget", "Writing", nullptr));
        dropDownTaskQComboBox->setItemText(1, QApplication::translate("CreateCommitmentQWidget", "Compose Music", nullptr));

        listenersQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Listeners:", nullptr));
        checkKeyboardQCheckBox->setText(QApplication::translate("CreateCommitmentQWidget", "Keyboard", nullptr));
        checkMicQCheckBox->setText(QApplication::translate("CreateCommitmentQWidget", "Mic", nullptr));
        dropDownAudioListenerQComboBox->setItemText(0, QApplication::translate("CreateCommitmentQWidget", "Built-In Mic", nullptr));

        makeDefaultQCheckBox->setText(QApplication::translate("CreateCommitmentQWidget", "Make this my default commitment", nullptr));
        createCommitmentQPushButton->setText(QApplication::translate("CreateCommitmentQWidget", "Create Commitment", nullptr));
        backQPushButton->setText(QApplication::translate("CreateCommitmentQWidget", "Back", nullptr));
        dropDownUnitsLeftQComboBox->setItemText(0, QApplication::translate("CreateCommitmentQWidget", "Minute(s)", nullptr));
        dropDownUnitsLeftQComboBox->setItemText(1, QApplication::translate("CreateCommitmentQWidget", "Hour(s)", nullptr));

    } // retranslateUi

};

namespace Ui {
    class CreateCommitmentQWidget: public Ui_CreateCommitmentQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECOMMITMENTQWIDGET_H

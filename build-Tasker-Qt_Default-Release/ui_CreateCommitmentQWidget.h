/********************************************************************************
** Form generated from reading UI file 'CreateCommitmentQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECOMMITMENTQWIDGET_H
#define UI_CREATECOMMITMENTQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
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
            CreateCommitmentQWidget->setObjectName(QStringLiteral("CreateCommitmentQWidget"));
        CreateCommitmentQWidget->resize(450, 450);
        createCommitmentQFrame = new QFrame(CreateCommitmentQWidget);
        createCommitmentQFrame->setObjectName(QStringLiteral("createCommitmentQFrame"));
        createCommitmentQFrame->setGeometry(QRect(0, 0, 451, 451));
        createCommitmentQFrame->setFrameShape(QFrame::StyledPanel);
        createCommitmentQFrame->setFrameShadow(QFrame::Raised);
        commitmentNameQLabel = new QLabel(createCommitmentQFrame);
        commitmentNameQLabel->setObjectName(QStringLiteral("commitmentNameQLabel"));
        commitmentNameQLabel->setGeometry(QRect(30, 40, 180, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        commitmentNameQLabel->setFont(font);
        commitmentNameQLineEdit = new QLineEdit(createCommitmentQFrame);
        commitmentNameQLineEdit->setObjectName(QStringLiteral("commitmentNameQLineEdit"));
        commitmentNameQLineEdit->setGeometry(QRect(190, 40, 221, 20));
        dateStartQLabel = new QLabel(createCommitmentQFrame);
        dateStartQLabel->setObjectName(QStringLiteral("dateStartQLabel"));
        dateStartQLabel->setGeometry(QRect(70, 110, 70, 20));
        QFont font1;
        font1.setPointSize(10);
        dateStartQLabel->setFont(font1);
        dateEndQLabel = new QLabel(createCommitmentQFrame);
        dateEndQLabel->setObjectName(QStringLiteral("dateEndQLabel"));
        dateEndQLabel->setGeometry(QRect(240, 110, 70, 20));
        dateEndQLabel->setFont(font1);
        dateStartQDateEdit = new QDateEdit(createCommitmentQFrame);
        dateStartQDateEdit->setObjectName(QStringLiteral("dateStartQDateEdit"));
        dateStartQDateEdit->setGeometry(QRect(70, 130, 110, 25));
        dateEndQDateEdit = new QDateEdit(createCommitmentQFrame);
        dateEndQDateEdit->setObjectName(QStringLiteral("dateEndQDateEdit"));
        dateEndQDateEdit->setGeometry(QRect(240, 130, 110, 25));
        qtyQLabel = new QLabel(createCommitmentQFrame);
        qtyQLabel->setObjectName(QStringLiteral("qtyQLabel"));
        qtyQLabel->setGeometry(QRect(70, 170, 21, 16));
        qtyQLabel->setFont(font1);
        qtyQLineEdit = new QLineEdit(createCommitmentQFrame);
        qtyQLineEdit->setObjectName(QStringLiteral("qtyQLineEdit"));
        qtyQLineEdit->setGeometry(QRect(70, 190, 41, 25));
        unitsLeftQLabel = new QLabel(createCommitmentQFrame);
        unitsLeftQLabel->setObjectName(QStringLiteral("unitsLeftQLabel"));
        unitsLeftQLabel->setGeometry(QRect(120, 170, 58, 16));
        unitsLeftQLabel->setFont(font1);
        perQLabel = new QLabel(createCommitmentQFrame);
        perQLabel->setObjectName(QStringLiteral("perQLabel"));
        perQLabel->setGeometry(QRect(210, 190, 41, 25));
        perQLabel->setFont(font);
        unitsRightQLabel = new QLabel(createCommitmentQFrame);
        unitsRightQLabel->setObjectName(QStringLiteral("unitsRightQLabel"));
        unitsRightQLabel->setGeometry(QRect(270, 170, 58, 16));
        unitsRightQLabel->setFont(font1);
        dropDownUnitsRightQComboBox = new QComboBox(createCommitmentQFrame);
        dropDownUnitsRightQComboBox->setObjectName(QStringLiteral("dropDownUnitsRightQComboBox"));
        dropDownUnitsRightQComboBox->setGeometry(QRect(270, 190, 79, 25));
        QFont font2;
        font2.setPointSize(12);
        dropDownUnitsRightQComboBox->setFont(font2);
        taskQLabel = new QLabel(createCommitmentQFrame);
        taskQLabel->setObjectName(QStringLiteral("taskQLabel"));
        taskQLabel->setGeometry(QRect(140, 240, 31, 25));
        dropDownTaskQComboBox = new QComboBox(createCommitmentQFrame);
        dropDownTaskQComboBox->setObjectName(QStringLiteral("dropDownTaskQComboBox"));
        dropDownTaskQComboBox->setGeometry(QRect(180, 240, 91, 25));
        dropDownTaskQComboBox->setFont(font2);
        listenersQLabel = new QLabel(createCommitmentQFrame);
        listenersQLabel->setObjectName(QStringLiteral("listenersQLabel"));
        listenersQLabel->setGeometry(QRect(140, 280, 58, 25));
        checkKeyboardQCheckBox = new QCheckBox(createCommitmentQFrame);
        checkKeyboardQCheckBox->setObjectName(QStringLiteral("checkKeyboardQCheckBox"));
        checkKeyboardQCheckBox->setGeometry(QRect(140, 300, 83, 25));
        checkMicQCheckBox = new QCheckBox(createCommitmentQFrame);
        checkMicQCheckBox->setObjectName(QStringLiteral("checkMicQCheckBox"));
        checkMicQCheckBox->setGeometry(QRect(140, 320, 83, 25));
        dropDownAudioListenerQComboBox = new QComboBox(createCommitmentQFrame);
        dropDownAudioListenerQComboBox->setObjectName(QStringLiteral("dropDownAudioListenerQComboBox"));
        dropDownAudioListenerQComboBox->setGeometry(QRect(230, 320, 121, 25));
        dropDownAudioListenerQComboBox->setFont(font2);
        makeDefaultQCheckBox = new QCheckBox(createCommitmentQFrame);
        makeDefaultQCheckBox->setObjectName(QStringLiteral("makeDefaultQCheckBox"));
        makeDefaultQCheckBox->setGeometry(QRect(40, 360, 231, 25));
        createCommitmentQPushButton = new QPushButton(createCommitmentQFrame);
        createCommitmentQPushButton->setObjectName(QStringLiteral("createCommitmentQPushButton"));
        createCommitmentQPushButton->setGeometry(QRect(40, 390, 150, 25));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        createCommitmentQPushButton->setFont(font3);
        backQPushButton = new QPushButton(createCommitmentQFrame);
        backQPushButton->setObjectName(QStringLiteral("backQPushButton"));
        backQPushButton->setGeometry(QRect(230, 390, 150, 25));
        backQPushButton->setFont(font2);
        dropDownUnitsLeftQComboBox = new QComboBox(createCommitmentQFrame);
        dropDownUnitsLeftQComboBox->setObjectName(QStringLiteral("dropDownUnitsLeftQComboBox"));
        dropDownUnitsLeftQComboBox->setGeometry(QRect(120, 190, 81, 25));
        dropDownUnitsLeftQComboBox->setFont(font2);

        retranslateUi(CreateCommitmentQWidget);

        QMetaObject::connectSlotsByName(CreateCommitmentQWidget);
    } // setupUi

    void retranslateUi(QWidget *CreateCommitmentQWidget)
    {
        CreateCommitmentQWidget->setWindowTitle(QApplication::translate("CreateCommitmentQWidget", "Create a Commitment", Q_NULLPTR));
        commitmentNameQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Commitment Name:", Q_NULLPTR));
        dateStartQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Start Date", Q_NULLPTR));
        dateEndQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "End Date", Q_NULLPTR));
        qtyQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Qty", Q_NULLPTR));
        qtyQLineEdit->setText(QApplication::translate("CreateCommitmentQWidget", "1", Q_NULLPTR));
        unitsLeftQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Units", Q_NULLPTR));
        perQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "per", Q_NULLPTR));
        unitsRightQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Units", Q_NULLPTR));
        dropDownUnitsRightQComboBox->clear();
        dropDownUnitsRightQComboBox->insertItems(0, QStringList()
         << QApplication::translate("CreateCommitmentQWidget", "Day", Q_NULLPTR)
         << QApplication::translate("CreateCommitmentQWidget", "Week", Q_NULLPTR)
         << QApplication::translate("CreateCommitmentQWidget", "Month", Q_NULLPTR)
        );
        taskQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Task:", Q_NULLPTR));
        dropDownTaskQComboBox->clear();
        dropDownTaskQComboBox->insertItems(0, QStringList()
         << QApplication::translate("CreateCommitmentQWidget", "Writing", Q_NULLPTR)
         << QApplication::translate("CreateCommitmentQWidget", "Compose Music", Q_NULLPTR)
        );
        listenersQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Listeners:", Q_NULLPTR));
        checkKeyboardQCheckBox->setText(QApplication::translate("CreateCommitmentQWidget", "Keyboard", Q_NULLPTR));
        checkMicQCheckBox->setText(QApplication::translate("CreateCommitmentQWidget", "Mic", Q_NULLPTR));
        dropDownAudioListenerQComboBox->clear();
        dropDownAudioListenerQComboBox->insertItems(0, QStringList()
         << QApplication::translate("CreateCommitmentQWidget", "Built-In Mic", Q_NULLPTR)
        );
        makeDefaultQCheckBox->setText(QApplication::translate("CreateCommitmentQWidget", "Make this my default commitment", Q_NULLPTR));
        createCommitmentQPushButton->setText(QApplication::translate("CreateCommitmentQWidget", "Create Commitment", Q_NULLPTR));
        backQPushButton->setText(QApplication::translate("CreateCommitmentQWidget", "Back", Q_NULLPTR));
        dropDownUnitsLeftQComboBox->clear();
        dropDownUnitsLeftQComboBox->insertItems(0, QStringList()
         << QApplication::translate("CreateCommitmentQWidget", "Minute(s)", Q_NULLPTR)
         << QApplication::translate("CreateCommitmentQWidget", "Hour(s)", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class CreateCommitmentQWidget: public Ui_CreateCommitmentQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECOMMITMENTQWIDGET_H

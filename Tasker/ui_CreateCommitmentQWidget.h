/********************************************************************************
** Form generated from reading UI file 'CreateCommitmentQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateCommitmentQWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *commitmentNameContainer;
    QHBoxLayout *horizontalLayout;
    QLabel *commitmentNameQLabel;
    QLineEdit *commitmentNameQLineEdit;
    QWidget *commitmentDateContainer;
    QGridLayout *gridLayout;
    QLabel *dateEndQLabel;
    QDateEdit *dateStartQDateEdit;
    QLabel *dateStartQLabel;
    QCheckBox *noEndDateQCheckBox;
    QDateEdit *dateEndQDateEdit;
    QGroupBox *commitmentFrequencyContainer;
    QGridLayout *gridLayout_2;
    QComboBox *frequencyTimeFormatQComboBox;
    QLineEdit *frequencyTimeQLineEdit;
    QComboBox *frequencyQComboBox;
    QComboBox *commitmentModeQCombox;
    QWidget *commitmentBottomOptionsContainer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *createCommitmentQPushButton_2;
    QPushButton *backQPushButton_2;

    void setupUi(QWidget *CreateCommitmentQWidget)
    {
        if (CreateCommitmentQWidget->objectName().isEmpty())
            CreateCommitmentQWidget->setObjectName(QString::fromUtf8("CreateCommitmentQWidget"));
        CreateCommitmentQWidget->setWindowModality(Qt::ApplicationModal);
        CreateCommitmentQWidget->resize(475, 475);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateCommitmentQWidget->sizePolicy().hasHeightForWidth());
        CreateCommitmentQWidget->setSizePolicy(sizePolicy);
        CreateCommitmentQWidget->setMinimumSize(QSize(475, 475));
        CreateCommitmentQWidget->setMaximumSize(QSize(475, 475));
        CreateCommitmentQWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(CreateCommitmentQWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        commitmentNameContainer = new QWidget(CreateCommitmentQWidget);
        commitmentNameContainer->setObjectName(QString::fromUtf8("commitmentNameContainer"));
        horizontalLayout = new QHBoxLayout(commitmentNameContainer);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        commitmentNameQLabel = new QLabel(commitmentNameContainer);
        commitmentNameQLabel->setObjectName(QString::fromUtf8("commitmentNameQLabel"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        commitmentNameQLabel->setFont(font);

        horizontalLayout->addWidget(commitmentNameQLabel);

        commitmentNameQLineEdit = new QLineEdit(commitmentNameContainer);
        commitmentNameQLineEdit->setObjectName(QString::fromUtf8("commitmentNameQLineEdit"));

        horizontalLayout->addWidget(commitmentNameQLineEdit);


        verticalLayout->addWidget(commitmentNameContainer);

        commitmentDateContainer = new QWidget(CreateCommitmentQWidget);
        commitmentDateContainer->setObjectName(QString::fromUtf8("commitmentDateContainer"));
        sizePolicy.setHeightForWidth(commitmentDateContainer->sizePolicy().hasHeightForWidth());
        commitmentDateContainer->setSizePolicy(sizePolicy);
        commitmentDateContainer->setMaximumSize(QSize(400, 75));
        gridLayout = new QGridLayout(commitmentDateContainer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        dateEndQLabel = new QLabel(commitmentDateContainer);
        dateEndQLabel->setObjectName(QString::fromUtf8("dateEndQLabel"));
        dateEndQLabel->setMaximumSize(QSize(75, 25));
        QFont font1;
        font1.setPointSize(10);
        dateEndQLabel->setFont(font1);

        gridLayout->addWidget(dateEndQLabel, 1, 1, 1, 1);

        dateStartQDateEdit = new QDateEdit(commitmentDateContainer);
        dateStartQDateEdit->setObjectName(QString::fromUtf8("dateStartQDateEdit"));
        dateStartQDateEdit->setMaximumSize(QSize(100, 25));

        gridLayout->addWidget(dateStartQDateEdit, 4, 0, 1, 1);

        dateStartQLabel = new QLabel(commitmentDateContainer);
        dateStartQLabel->setObjectName(QString::fromUtf8("dateStartQLabel"));
        dateStartQLabel->setMaximumSize(QSize(75, 25));
        dateStartQLabel->setFont(font1);
        dateStartQLabel->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(dateStartQLabel, 1, 0, 1, 1);

        noEndDateQCheckBox = new QCheckBox(commitmentDateContainer);
        noEndDateQCheckBox->setObjectName(QString::fromUtf8("noEndDateQCheckBox"));
        noEndDateQCheckBox->setMaximumSize(QSize(100, 25));

        gridLayout->addWidget(noEndDateQCheckBox, 4, 2, 1, 1);

        dateEndQDateEdit = new QDateEdit(commitmentDateContainer);
        dateEndQDateEdit->setObjectName(QString::fromUtf8("dateEndQDateEdit"));
        dateEndQDateEdit->setMaximumSize(QSize(100, 25));

        gridLayout->addWidget(dateEndQDateEdit, 4, 1, 1, 1);


        verticalLayout->addWidget(commitmentDateContainer);

        commitmentFrequencyContainer = new QGroupBox(CreateCommitmentQWidget);
        commitmentFrequencyContainer->setObjectName(QString::fromUtf8("commitmentFrequencyContainer"));
        commitmentFrequencyContainer->setFlat(true);
        commitmentFrequencyContainer->setCheckable(false);
        commitmentFrequencyContainer->setChecked(false);
        gridLayout_2 = new QGridLayout(commitmentFrequencyContainer);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frequencyTimeFormatQComboBox = new QComboBox(commitmentFrequencyContainer);
        frequencyTimeFormatQComboBox->addItem(QString());
        frequencyTimeFormatQComboBox->addItem(QString());
        frequencyTimeFormatQComboBox->setObjectName(QString::fromUtf8("frequencyTimeFormatQComboBox"));
        QFont font2;
        font2.setPointSize(12);
        frequencyTimeFormatQComboBox->setFont(font2);

        gridLayout_2->addWidget(frequencyTimeFormatQComboBox, 3, 1, 1, 1);

        frequencyTimeQLineEdit = new QLineEdit(commitmentFrequencyContainer);
        frequencyTimeQLineEdit->setObjectName(QString::fromUtf8("frequencyTimeQLineEdit"));
        frequencyTimeQLineEdit->setMaximumSize(QSize(70, 50));

        gridLayout_2->addWidget(frequencyTimeQLineEdit, 3, 0, 1, 1);

        frequencyQComboBox = new QComboBox(commitmentFrequencyContainer);
        frequencyQComboBox->addItem(QString());
        frequencyQComboBox->addItem(QString());
        frequencyQComboBox->addItem(QString());
        frequencyQComboBox->addItem(QString());
        frequencyQComboBox->addItem(QString());
        frequencyQComboBox->addItem(QString());
        frequencyQComboBox->addItem(QString());
        frequencyQComboBox->setObjectName(QString::fromUtf8("frequencyQComboBox"));
        frequencyQComboBox->setFont(font2);

        gridLayout_2->addWidget(frequencyQComboBox, 3, 2, 1, 1);

        commitmentModeQCombox = new QComboBox(commitmentFrequencyContainer);
        commitmentModeQCombox->addItem(QString());
        commitmentModeQCombox->addItem(QString());
        commitmentModeQCombox->setObjectName(QString::fromUtf8("commitmentModeQCombox"));

        gridLayout_2->addWidget(commitmentModeQCombox, 1, 0, 1, 2);


        verticalLayout->addWidget(commitmentFrequencyContainer);

        commitmentBottomOptionsContainer = new QWidget(CreateCommitmentQWidget);
        commitmentBottomOptionsContainer->setObjectName(QString::fromUtf8("commitmentBottomOptionsContainer"));
        horizontalLayout_3 = new QHBoxLayout(commitmentBottomOptionsContainer);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        createCommitmentQPushButton_2 = new QPushButton(commitmentBottomOptionsContainer);
        createCommitmentQPushButton_2->setObjectName(QString::fromUtf8("createCommitmentQPushButton_2"));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        createCommitmentQPushButton_2->setFont(font3);

        horizontalLayout_3->addWidget(createCommitmentQPushButton_2);

        backQPushButton_2 = new QPushButton(commitmentBottomOptionsContainer);
        backQPushButton_2->setObjectName(QString::fromUtf8("backQPushButton_2"));
        backQPushButton_2->setFont(font2);

        horizontalLayout_3->addWidget(backQPushButton_2);


        verticalLayout->addWidget(commitmentBottomOptionsContainer);


        retranslateUi(CreateCommitmentQWidget);

        QMetaObject::connectSlotsByName(CreateCommitmentQWidget);
    } // setupUi

    void retranslateUi(QWidget *CreateCommitmentQWidget)
    {
        CreateCommitmentQWidget->setWindowTitle(QCoreApplication::translate("CreateCommitmentQWidget", "Create a Commitment", nullptr));
        commitmentNameQLabel->setText(QCoreApplication::translate("CreateCommitmentQWidget", "Commitment Name:", nullptr));
        commitmentNameQLineEdit->setPlaceholderText(QCoreApplication::translate("CreateCommitmentQWidget", "Alice in Wonderland", nullptr));
        dateEndQLabel->setText(QCoreApplication::translate("CreateCommitmentQWidget", "End Date", nullptr));
        dateStartQDateEdit->setDisplayFormat(QCoreApplication::translate("CreateCommitmentQWidget", "M/d/yyyy", nullptr));
        dateStartQLabel->setText(QCoreApplication::translate("CreateCommitmentQWidget", "Start Date", nullptr));
        noEndDateQCheckBox->setText(QCoreApplication::translate("CreateCommitmentQWidget", "No End Date", nullptr));
        dateEndQDateEdit->setDisplayFormat(QCoreApplication::translate("CreateCommitmentQWidget", "M/d/yyyy", nullptr));
        commitmentFrequencyContainer->setTitle(QCoreApplication::translate("CreateCommitmentQWidget", "Frequency", nullptr));
        frequencyTimeFormatQComboBox->setItemText(0, QCoreApplication::translate("CreateCommitmentQWidget", "Minute(s)", nullptr));
        frequencyTimeFormatQComboBox->setItemText(1, QCoreApplication::translate("CreateCommitmentQWidget", "Hour(s)", nullptr));

        frequencyTimeQLineEdit->setText(QCoreApplication::translate("CreateCommitmentQWidget", "1", nullptr));
        frequencyQComboBox->setItemText(0, QCoreApplication::translate("CreateCommitmentQWidget", "Once a week", nullptr));
        frequencyQComboBox->setItemText(1, QCoreApplication::translate("CreateCommitmentQWidget", "Twice a week", nullptr));
        frequencyQComboBox->setItemText(2, QCoreApplication::translate("CreateCommitmentQWidget", "Three times a week", nullptr));
        frequencyQComboBox->setItemText(3, QCoreApplication::translate("CreateCommitmentQWidget", "Four times a week", nullptr));
        frequencyQComboBox->setItemText(4, QCoreApplication::translate("CreateCommitmentQWidget", "Five times a week", nullptr));
        frequencyQComboBox->setItemText(5, QCoreApplication::translate("CreateCommitmentQWidget", "Six times a week", nullptr));
        frequencyQComboBox->setItemText(6, QCoreApplication::translate("CreateCommitmentQWidget", "Everyday", nullptr));

        commitmentModeQCombox->setItemText(0, QCoreApplication::translate("CreateCommitmentQWidget", "Weekly", nullptr));
        commitmentModeQCombox->setItemText(1, QCoreApplication::translate("CreateCommitmentQWidget", "Everyday", nullptr));

        createCommitmentQPushButton_2->setText(QCoreApplication::translate("CreateCommitmentQWidget", "Save", nullptr));
        backQPushButton_2->setText(QCoreApplication::translate("CreateCommitmentQWidget", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateCommitmentQWidget: public Ui_CreateCommitmentQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECOMMITMENTQWIDGET_H

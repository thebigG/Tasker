/********************************************************************************
** Form generated from reading UI file 'CreateCommitmentQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            CreateCommitmentQWidget->setObjectName(QStringLiteral("CreateCommitmentQWidget"));
        CreateCommitmentQWidget->setWindowModality(Qt::ApplicationModal);
        CreateCommitmentQWidget->resize(475, 475);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateCommitmentQWidget->sizePolicy().hasHeightForWidth());
        CreateCommitmentQWidget->setSizePolicy(sizePolicy);
        CreateCommitmentQWidget->setMinimumSize(QSize(475, 475));
        CreateCommitmentQWidget->setMaximumSize(QSize(475, 475));
        CreateCommitmentQWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(CreateCommitmentQWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        commitmentNameContainer = new QWidget(CreateCommitmentQWidget);
        commitmentNameContainer->setObjectName(QStringLiteral("commitmentNameContainer"));
        horizontalLayout = new QHBoxLayout(commitmentNameContainer);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        commitmentNameQLabel = new QLabel(commitmentNameContainer);
        commitmentNameQLabel->setObjectName(QStringLiteral("commitmentNameQLabel"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        commitmentNameQLabel->setFont(font);

        horizontalLayout->addWidget(commitmentNameQLabel);

        commitmentNameQLineEdit = new QLineEdit(commitmentNameContainer);
        commitmentNameQLineEdit->setObjectName(QStringLiteral("commitmentNameQLineEdit"));

        horizontalLayout->addWidget(commitmentNameQLineEdit);


        verticalLayout->addWidget(commitmentNameContainer);

        commitmentDateContainer = new QWidget(CreateCommitmentQWidget);
        commitmentDateContainer->setObjectName(QStringLiteral("commitmentDateContainer"));
        sizePolicy.setHeightForWidth(commitmentDateContainer->sizePolicy().hasHeightForWidth());
        commitmentDateContainer->setSizePolicy(sizePolicy);
        commitmentDateContainer->setMaximumSize(QSize(400, 75));
        gridLayout = new QGridLayout(commitmentDateContainer);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        dateEndQLabel = new QLabel(commitmentDateContainer);
        dateEndQLabel->setObjectName(QStringLiteral("dateEndQLabel"));
        dateEndQLabel->setMaximumSize(QSize(75, 25));
        QFont font1;
        font1.setPointSize(10);
        dateEndQLabel->setFont(font1);

        gridLayout->addWidget(dateEndQLabel, 1, 1, 1, 1);

        dateStartQDateEdit = new QDateEdit(commitmentDateContainer);
        dateStartQDateEdit->setObjectName(QStringLiteral("dateStartQDateEdit"));
        dateStartQDateEdit->setMaximumSize(QSize(100, 25));

        gridLayout->addWidget(dateStartQDateEdit, 4, 0, 1, 1);

        dateStartQLabel = new QLabel(commitmentDateContainer);
        dateStartQLabel->setObjectName(QStringLiteral("dateStartQLabel"));
        dateStartQLabel->setMaximumSize(QSize(75, 25));
        dateStartQLabel->setFont(font1);
        dateStartQLabel->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(dateStartQLabel, 1, 0, 1, 1);

        noEndDateQCheckBox = new QCheckBox(commitmentDateContainer);
        noEndDateQCheckBox->setObjectName(QStringLiteral("noEndDateQCheckBox"));
        noEndDateQCheckBox->setMaximumSize(QSize(100, 25));

        gridLayout->addWidget(noEndDateQCheckBox, 4, 2, 1, 1);

        dateEndQDateEdit = new QDateEdit(commitmentDateContainer);
        dateEndQDateEdit->setObjectName(QStringLiteral("dateEndQDateEdit"));
        dateEndQDateEdit->setMaximumSize(QSize(100, 25));

        gridLayout->addWidget(dateEndQDateEdit, 4, 1, 1, 1);


        verticalLayout->addWidget(commitmentDateContainer);

        commitmentFrequencyContainer = new QGroupBox(CreateCommitmentQWidget);
        commitmentFrequencyContainer->setObjectName(QStringLiteral("commitmentFrequencyContainer"));
        commitmentFrequencyContainer->setFlat(true);
        commitmentFrequencyContainer->setCheckable(false);
        commitmentFrequencyContainer->setChecked(false);
        gridLayout_2 = new QGridLayout(commitmentFrequencyContainer);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frequencyTimeFormatQComboBox = new QComboBox(commitmentFrequencyContainer);
        frequencyTimeFormatQComboBox->setObjectName(QStringLiteral("frequencyTimeFormatQComboBox"));
        QFont font2;
        font2.setPointSize(12);
        frequencyTimeFormatQComboBox->setFont(font2);

        gridLayout_2->addWidget(frequencyTimeFormatQComboBox, 3, 1, 1, 1);

        frequencyTimeQLineEdit = new QLineEdit(commitmentFrequencyContainer);
        frequencyTimeQLineEdit->setObjectName(QStringLiteral("frequencyTimeQLineEdit"));
        frequencyTimeQLineEdit->setMaximumSize(QSize(70, 50));

        gridLayout_2->addWidget(frequencyTimeQLineEdit, 3, 0, 1, 1);

        frequencyQComboBox = new QComboBox(commitmentFrequencyContainer);
        frequencyQComboBox->setObjectName(QStringLiteral("frequencyQComboBox"));
        frequencyQComboBox->setFont(font2);

        gridLayout_2->addWidget(frequencyQComboBox, 3, 2, 1, 1);

        commitmentModeQCombox = new QComboBox(commitmentFrequencyContainer);
        commitmentModeQCombox->setObjectName(QStringLiteral("commitmentModeQCombox"));

        gridLayout_2->addWidget(commitmentModeQCombox, 1, 0, 1, 2);


        verticalLayout->addWidget(commitmentFrequencyContainer);

        commitmentBottomOptionsContainer = new QWidget(CreateCommitmentQWidget);
        commitmentBottomOptionsContainer->setObjectName(QStringLiteral("commitmentBottomOptionsContainer"));
        horizontalLayout_3 = new QHBoxLayout(commitmentBottomOptionsContainer);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        createCommitmentQPushButton_2 = new QPushButton(commitmentBottomOptionsContainer);
        createCommitmentQPushButton_2->setObjectName(QStringLiteral("createCommitmentQPushButton_2"));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        createCommitmentQPushButton_2->setFont(font3);

        horizontalLayout_3->addWidget(createCommitmentQPushButton_2);

        backQPushButton_2 = new QPushButton(commitmentBottomOptionsContainer);
        backQPushButton_2->setObjectName(QStringLiteral("backQPushButton_2"));
        backQPushButton_2->setFont(font2);

        horizontalLayout_3->addWidget(backQPushButton_2);


        verticalLayout->addWidget(commitmentBottomOptionsContainer);


        retranslateUi(CreateCommitmentQWidget);

        QMetaObject::connectSlotsByName(CreateCommitmentQWidget);
    } // setupUi

    void retranslateUi(QWidget *CreateCommitmentQWidget)
    {
        CreateCommitmentQWidget->setWindowTitle(QApplication::translate("CreateCommitmentQWidget", "Create a Commitment", Q_NULLPTR));
        commitmentNameQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Commitment Name:", Q_NULLPTR));
        commitmentNameQLineEdit->setPlaceholderText(QApplication::translate("CreateCommitmentQWidget", "Alice in Wonderland", Q_NULLPTR));
        dateEndQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "End Date", Q_NULLPTR));
        dateStartQDateEdit->setDisplayFormat(QApplication::translate("CreateCommitmentQWidget", "M/d/yyyy", Q_NULLPTR));
        dateStartQLabel->setText(QApplication::translate("CreateCommitmentQWidget", "Start Date", Q_NULLPTR));
        noEndDateQCheckBox->setText(QApplication::translate("CreateCommitmentQWidget", "No End Date", Q_NULLPTR));
        dateEndQDateEdit->setDisplayFormat(QApplication::translate("CreateCommitmentQWidget", "M/d/yyyy", Q_NULLPTR));
        commitmentFrequencyContainer->setTitle(QApplication::translate("CreateCommitmentQWidget", "Frequency", Q_NULLPTR));
        frequencyTimeFormatQComboBox->clear();
        frequencyTimeFormatQComboBox->insertItems(0, QStringList()
         << QApplication::translate("CreateCommitmentQWidget", "Minute(s)", Q_NULLPTR)
         << QApplication::translate("CreateCommitmentQWidget", "Hour(s)", Q_NULLPTR)
        );
        frequencyTimeQLineEdit->setText(QApplication::translate("CreateCommitmentQWidget", "1", Q_NULLPTR));
        frequencyQComboBox->clear();
        frequencyQComboBox->insertItems(0, QStringList()
         << QApplication::translate("CreateCommitmentQWidget", "Once a week", Q_NULLPTR)
         << QApplication::translate("CreateCommitmentQWidget", "Twice a week", Q_NULLPTR)
         << QApplication::translate("CreateCommitmentQWidget", "Three times a week", Q_NULLPTR)
         << QApplication::translate("CreateCommitmentQWidget", "Four times a week", Q_NULLPTR)
         << QApplication::translate("CreateCommitmentQWidget", "Five times a week", Q_NULLPTR)
         << QApplication::translate("CreateCommitmentQWidget", "Six times a week", Q_NULLPTR)
         << QApplication::translate("CreateCommitmentQWidget", "Everyday", Q_NULLPTR)
        );
        commitmentModeQCombox->clear();
        commitmentModeQCombox->insertItems(0, QStringList()
         << QApplication::translate("CreateCommitmentQWidget", "Weekly", Q_NULLPTR)
         << QApplication::translate("CreateCommitmentQWidget", "Everyday", Q_NULLPTR)
        );
        createCommitmentQPushButton_2->setText(QApplication::translate("CreateCommitmentQWidget", "Save", Q_NULLPTR));
        backQPushButton_2->setText(QApplication::translate("CreateCommitmentQWidget", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CreateCommitmentQWidget: public Ui_CreateCommitmentQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECOMMITMENTQWIDGET_H

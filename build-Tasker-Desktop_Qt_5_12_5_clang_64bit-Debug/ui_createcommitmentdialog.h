/********************************************************************************
** Form generated from reading UI file 'createcommitmentdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECOMMITMENTDIALOG_H
#define UI_CREATECOMMITMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_createcommitmentdialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *createcommitmentdialog)
    {
        if (createcommitmentdialog->objectName().isEmpty())
            createcommitmentdialog->setObjectName(QString::fromUtf8("createcommitmentdialog"));
        createcommitmentdialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(createcommitmentdialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(createcommitmentdialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), createcommitmentdialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), createcommitmentdialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(createcommitmentdialog);
    } // setupUi

    void retranslateUi(QDialog *createcommitmentdialog)
    {
        createcommitmentdialog->setWindowTitle(QApplication::translate("createcommitmentdialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createcommitmentdialog: public Ui_createcommitmentdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECOMMITMENTDIALOG_H

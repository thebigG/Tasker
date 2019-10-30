#include "createcommitment.h"
#include "ui_createcommitment.h"

#include <QDebug>

createcommitment::createcommitment(QWidget *parent)
: QWidget(parent), ui(new Ui::createcommitment) {
    ui->setupUi(this);
    validator = new QIntValidator(0, 999, this);
    ui->QLineEdit_Qty->setValidator(validator);
}

createcommitment::~createcommitment() {
    delete ui;
}

QCheckBox *createcommitment::getKeyboardCheckBox() {
    return ui->checkBox;
}

QCheckBox *createcommitment::getAudioCheckBox() {
    return ui->checkBox_2;
}

void createcommitment::on_comboBox_2_currentIndexChanged(const QString &arg1) {
    if (arg1 == QString("Writing")) {
        this->getKeyboardCheckBox()->setCheckState(Qt::CheckState{ Qt::Checked });
        this->getAudioCheckBox()->setCheckState(Qt::CheckState{ Qt::Unchecked });
    } else if (arg1 == QString("Compose Music")) {
        this->getAudioCheckBox()->setCheckState(Qt::CheckState{ Qt::Checked });
        this->getKeyboardCheckBox()->setCheckState(Qt::CheckState{ Qt::Unchecked });
    } else if (arg1 == QString("Custom")) {
        this->getAudioCheckBox()->setCheckState(Qt::CheckState{ Qt::Unchecked });
        this->getKeyboardCheckBox()->setCheckState(Qt::CheckState{ Qt::Unchecked });
    }
}

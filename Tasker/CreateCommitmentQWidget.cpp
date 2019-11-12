#include "CreateCommitmentQWidget.h"
#include "ui_CreateCommitmentQWidget.h"

#include <QDebug>

CreateCommitmentQWidget::CreateCommitmentQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::CreateCommitmentQWidget) {
    ui->setupUi(this);
    validator = new QIntValidator(0, 999, this);
    ui->qtyQLineEdit->setValidator(validator);
}

CreateCommitmentQWidget::~CreateCommitmentQWidget() {
    delete ui;
}

QCheckBox *CreateCommitmentQWidget::getKeyboardCheckBox() {
    return ui->checkKeyboardQCheckBox;
}

QCheckBox *CreateCommitmentQWidget::getAudioCheckBox() {
    return ui->checkMicQCheckBox;
}

void CreateCommitmentQWidget::on_dropDownTaskQComboBox_activated(const QString &arg1) {
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

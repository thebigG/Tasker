#include "createcommitmentqwidget.h"
#include "ui_createcommitment.h"

#include <QDebug>

createCommitmentQWidget::createCommitmentQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::createcommitment) {
    ui->setupUi(this);
    validator = new QIntValidator(0, 999, this);
    ui->QLineEdit_Qty->setValidator(validator);
}

createCommitmentQWidget::~createCommitmentQWidget() {
    delete ui;
}

QCheckBox *createCommitmentQWidget::getKeyboardCheckBox() {
    return ui->checkBox;
}

QCheckBox *createCommitmentQWidget::getAudioCheckBox() {
    return ui->checkBox_2;
}

void createCommitmentQWidget::on_comboBox_2_currentIndexChanged(const QString &arg1) {
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

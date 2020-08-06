#include "CreateCommitmentQWidget.h"
#include "ui_CreateCommitmentQWidget.h"
#include <CommStatsQWidget.h>
#include <Commitment.h>
#include <Hook.h>
#include <QDebug>
#include <QObject>
#include <StatsUtility.h>
#include <User.h>
#include <mainui.h>

using namespace util;
using namespace udata;

/**
 * @brief CreateCommitmentQWidget::CreateCommitmentQWidget
 * @param parent
 */
CreateCommitmentQWidget::CreateCommitmentQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::CreateCommitmentQWidget) {
    ui->setupUi(this);
    ui->frequencyTimeQLineEdit->setValidator(&validator);
    ui->dateStartQDateEdit->setMinimumDate(QDate::currentDate());
    ui->dateStartQDateEdit->setMaximumDate(QDate::currentDate());
    if (getType() == udata::CommitmentType::WEEKLY ||
        getType() == udata::CommitmentType::EVERDAY) {
        ui->dateEndQDateEdit->setMinimumDate(QDate::currentDate().addDays(WEEK_SIZE));
    }
    connect(this->ui->createCommitmentQPushButton_2, &QPushButton::clicked,
            this, &CreateCommitmentQWidget::createCommitmentButtonSlot);
    connect(this->ui->backQPushButton_2, &QPushButton::clicked, this,
            &CreateCommitmentQWidget::backButtonSlot);
    //    QFontMetrics thisFont{ this->ui->commitmentNameQLabel->font()};
    connect(this->ui->noEndDateQCheckBox, &QCheckBox::stateChanged, this,
            &CreateCommitmentQWidget::noEndDateCheckSlot);
    connect(this->ui->commitmentModeQCombox, &QComboBox::currentTextChanged, this,
            &CreateCommitmentQWidget::currentIndexCommitmentModeComboBoxSlot);
    connect(this->ui->frequencyQComboBox, &QComboBox::currentTextChanged, this,
            &CreateCommitmentQWidget::currentIndexFrequencyComboBoxSlot);
    this->addAction(new QAction());
    this->actions().at(0)->setShortcut(QKeySequence::Cancel);
    connect(this->actions().at(0), &QAction::triggered, this, &QWidget::hide);
}

/**
 * @brief CreateCommitmentQWidget::~CreateCommitmentQWidget
 */
CreateCommitmentQWidget::~CreateCommitmentQWidget() {
    delete ui;
}

/**
 * @brief CreateCommitmentQWidget::getUI
 * @return
 */

/**
 * @brief CreateCommitmentQWidget::backButtonSlot
 */
void CreateCommitmentQWidget::backButtonSlot() {
    this->hide();
    this->ui->commitmentNameQLineEdit->clear();
    MainUI::getInstance()->show();
}
void CreateCommitmentQWidget::noEndDateCheckSlot() {
    if (this->ui->noEndDateQCheckBox->isChecked()) {
        this->ui->dateEndQDateEdit->setDisabled(true);
    } else {
        this->ui->dateEndQDateEdit->setDisabled(false);
    }
}
void CreateCommitmentQWidget::currentIndexCommitmentModeComboBoxSlot(const QString &text) {
    if (EVERYDAY_STRING == text) {
        ui->frequencyQComboBox->setCurrentIndex(6);
    } else if (WEEKLY_STRING == text) {
        ui->frequencyQComboBox->setCurrentIndex(0);
    }
}
void CreateCommitmentQWidget::currentIndexFrequencyComboBoxSlot(const QString &text) {
    if (EVERYDAY_STRING != text) {
        ui->commitmentModeQCombox->setCurrentIndex(0);
    } else {
        ui->commitmentModeQCombox->setCurrentIndex(1);
    }
}
/**
 * @brief CreateCommitmentQWidget::createCommitmentButtonSlot gets triggered
 * every time the user hits the "Save" button of this window. If the commitment
 * is a new commitment, it is a stored to disk. If the commitment already exists
 * and the user is editing it, the changes are applied to the existent
 * commitment and not new one is created.
 */
void CreateCommitmentQWidget::createCommitmentButtonSlot() {
    if (editing) {
        editing = false;
        Commitment &currentCommitment = User::getInstance()->getCurrentCommitment();
        currentCommitment.setName(this->getCommitmentName());
        currentCommitment.setDateStart(this->getStartDate());
        currentCommitment.setDateEnd(this->getEndDate());
        currentCommitment.setFrequency(getCommitmentFrequency());
        currentCommitment.setType(this->getType());
        currentCommitment.setNoEndDate(this->ui->noEndDateQCheckBox->isChecked());
        MainUI::getInstance()->getCommitmentHub().updateCurrentCommitment();
        this->hide();
        this->ui->commitmentNameQLineEdit->clear();
        return;
    }
    this->hide();
    Commitment temp{
        this->getCommitmentName(), this->getStartDate(),
        this->getEndDate(),        this->getCommitmentFrequency(),
        this->getType(),           this->ui->noEndDateQCheckBox->isChecked()
    };
    this->ui->commitmentNameQLineEdit->clear();
    MainUI::getInstance()->getCommitmentHub().addCommitmentItem(temp);
}

/**
 * @brief CreateCommitmentQWidget::getCommitmentName
 * @return
 */
QString CreateCommitmentQWidget::getCommitmentName() {
    return ui->commitmentNameQLineEdit->text();
}

/**
 * @brief CreateCommitmentQWidget::getStartDate
 * @return
 */
QDate CreateCommitmentQWidget::getStartDate() {
    return ui->dateStartQDateEdit->date();
}

/**
 * @brief CreateCommitmentQWidget::getEndDate
 * @return
 */
QDate CreateCommitmentQWidget::getEndDate() {
    return ui->dateEndQDateEdit->date();
}

/**
 * @brief CreateCommitmentQWidget::getCommitmentFrequency
 * @return the commitment frequency the user has currently configured.
 */
udata::CommitmentFrequency CreateCommitmentQWidget::getCommitmentFrequency() {
    udata::CommitmentFrequency frequency{};
    long long int size;
    QString currentSizeLabel = ui->frequencyTimeFormatQComboBox->currentText();
    if (currentSizeLabel == MINUTES_STRING) {
        size = SECONDS_IN_MINUTE * ui->frequencyTimeQLineEdit->text().toInt();
    } else {
        size = SECONDS_IN_HOUR * ui->frequencyTimeQLineEdit->text().toInt();
    }

    frequency.goal = size;
    frequency.frequency = ui->frequencyQComboBox->currentIndex() + 1;
    switch (getType()) {
    case udata::CommitmentType::WEEKLY:
        frequency.timeWindowSize = WEEK_SIZE;
        break;
    case udata::CommitmentType::MONTHLY:
        frequency.timeWindowSize = MONTH_SIZE; // Not supported currently
        break;
    default:
        frequency.timeWindowSize = WEEK_SIZE;
    }
    return frequency;
}
/**
 * @brief CreateCommitmentQWidget::getType
 * @return The type of commitment that is currently selected.
 */
udata::CommitmentType CreateCommitmentQWidget::getType() {
    switch (this->ui->commitmentModeQCombox->currentIndex()) {
    case 0:
        return udata::CommitmentType::WEEKLY;
        break;
    case 1:
        return udata::CommitmentType::EVERDAY;
        break;
    default:
        return udata::CommitmentType::Custom;
    }
}
/**
 * @brief CreateCommitmentQWidget::editCommitment Updates this window's state
 * with the data from the commitment that the user is editing.
 * @param commitmentIndex
 */
void CreateCommitmentQWidget::editCommitment() {
    Commitment &currentCommitment = User::getInstance()->getCurrentCommitment();
    this->setWindowTitle("Edit \"" + currentCommitment.getName() + "\"");
    this->ui->commitmentNameQLineEdit->setText(currentCommitment.getName());
    this->ui->dateStartQDateEdit->setDate(currentCommitment.getDateStart());
    if (currentCommitment.hasEndDate()) {
        this->ui->noEndDateQCheckBox->setCheckState(Qt::CheckState::Unchecked);
        this->ui->dateEndQDateEdit->setDate(currentCommitment.getDateEnd());
    } else {
        this->ui->noEndDateQCheckBox->setCheckState(Qt::CheckState::Checked);
    }
    if (currentCommitment.getFrequency().frequency == 7) {
        this->ui->commitmentModeQCombox->setCurrentIndex(1);
    } else {
        this->ui->commitmentModeQCombox->setCurrentIndex(0);
    }
    if (util::toHours(currentCommitment.getFrequency().goal) > 0) {
        this->ui->frequencyTimeFormatQComboBox->setCurrentIndex(1);
        this->ui->frequencyTimeQLineEdit->setText(
            QString::number(util::toHours(currentCommitment.getFrequency().goal)));
    } else {
        this->ui->frequencyTimeFormatQComboBox->setCurrentIndex(0);
        this->ui->frequencyTimeQLineEdit->setText(
            QString::number(util::toMinutes(currentCommitment.getFrequency().goal)));
    }
    this->ui->frequencyQComboBox->setCurrentIndex(
        currentCommitment.getFrequency().frequency - 1);
    editing = true;
    this->show();

    // perhaps emit a signal to CommStats that a commitment has been modified(?)
}

void CreateCommitmentQWidget::show() {
    QWidget::show();
    if (!editing) {
        this->setWindowTitle("Create a Commitment");
    };
}

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
  if (getType() == udata::CommitmentType::WEEKLY) {
    ui->dateEndQDateEdit->setMinimumDate(
        QDate::currentDate().addDays(WEEK_SIZE));
  }
  connect(this->getUI()->createCommitmentQPushButton_2, &QPushButton::clicked,
          this, &CreateCommitmentQWidget::createCommitmentButtonSlot);
  connect(this->getUI()->backQPushButton_2, &QPushButton::clicked, this,
          &CreateCommitmentQWidget::backButtonSlot);
  //    QFontMetrics thisFont{ this->ui->commitmentNameQLabel->font()};
  connect(this->getUI()->noEndDateQCheckBox, &QCheckBox::stateChanged, this,
          &CreateCommitmentQWidget::noEndDateCheckSlot);
  connect(this->getUI()->commitmentModeQCombox, &QComboBox::currentTextChanged,
          this,
          &CreateCommitmentQWidget::currentIndexCommitmentModeComboBoxSlot);
  connect(this->getUI()->frequencyQComboBox, &QComboBox::currentTextChanged,
          this, &CreateCommitmentQWidget::currentIndexFrequencyComboBoxSlot);
  this->addAction(new QAction());
  this->actions().at(0)->setShortcut(QKeySequence::Cancel);
  connect(this->actions().at(0), &QAction::triggered, this, &QWidget::hide);
  //    qDebug()<<"font height="<<thisFont.height();
  //    qDebug()<<"average width font="<<thisFont.averageCharWidth();
}

/**
 * @brief CreateCommitmentQWidget::~CreateCommitmentQWidget
 */
CreateCommitmentQWidget::~CreateCommitmentQWidget() {
  qDebug() << "CreateCommitmentQWidget#1";
  delete ui;
  qDebug() << "CreateCommitmentQWidget#2";
}

/**
 * @brief CreateCommitmentQWidget::getUI
 * @return
 */
Ui::CreateCommitmentQWidget *CreateCommitmentQWidget::getUI() { return ui; }

/**
 * @brief CreateCommitmentQWidget::backButtonSlot
 */
void CreateCommitmentQWidget::backButtonSlot() {
  qDebug() << "Listener for back button";
  this->hide();
  this->ui->commitmentNameQLineEdit->clear();
  MainUI::getInstance()->show();
}
void CreateCommitmentQWidget::noEndDateCheckSlot(int State) {
  qDebug("Checkbox signal#1");
  if (this->getUI()->noEndDateQCheckBox->isChecked()) {
    this->getUI()->dateEndQDateEdit->setDisabled(true);
    qDebug("Checkbox signal#2");
  } else {
    this->getUI()->dateEndQDateEdit->setDisabled(false);
  }
}
void CreateCommitmentQWidget::currentIndexCommitmentModeComboBoxSlot(
    const QString &text) {
  qDebug() << "Slot for commitment mode combo box" + text;
  if (EVERYDAY_STRING == text) {
    ui->frequencyQComboBox->setCurrentIndex(6);
  } else if (WEEKLY_STRING == text) {
    ui->frequencyQComboBox->setCurrentIndex(0);
  }
}
void CreateCommitmentQWidget::currentIndexFrequencyComboBoxSlot(
    const QString &text) {
  if (EVERYDAY_STRING != text) {
    ui->commitmentModeQCombox->setCurrentIndex(0);
  } else {
    ui->commitmentModeQCombox->setCurrentIndex(1);
  }
}
/**
 * @brief CreateCommitmentQWidget::createCommitmentButtonSlot
 */
void CreateCommitmentQWidget::createCommitmentButtonSlot() {
  if (editing) {
    editing = false;
    Commitment &currentCommitment = User::getInstance()->getCurrentCommitment();
    currentCommitment.setName(this->getCommitmentName());
    currentCommitment.setDateStart(this->getStartDate());
    currentCommitment.setDateEnd(this->getEndDate());
    currentCommitment.setFrequency(getInterval());
    currentCommitment.setType(this->getType());
    currentCommitment.setNoEndDate(
        this->getUI()->noEndDateQCheckBox->isChecked());
    MainUI::getInstance()->getCommitmentHub().updateCurrentCommitment();
    this->hide();
    this->ui->commitmentNameQLineEdit->clear();
    //    emit commitmentEdit();
    return;
  }
  this->hide();
  Commitment temp{this->getCommitmentName(),
                  this->getStartDate(),
                  this->getEndDate(),
                  this->getInterval(),
                  this->getType(),
                  this->getUI()->noEndDateQCheckBox->isChecked()};
  if (this->getUI()->noEndDateQCheckBox->isChecked()) {
    qDebug() << "noEndDate is checked";
    if (!temp.hasEndDate()) {
      qDebug() << "commitment has no end date";
    }
  }
  this->ui->commitmentNameQLineEdit->clear();
  qDebug() << "Does this run on createCommitmentButtonSlot?";
  MainUI::getInstance()->getCommitmentHub().addCommitmentItem(temp);
  qDebug() << "Does this run on createCommitmentButtonSlot#2?";
  //  MainUI::getInstance()->show();
  qDebug() << "Does this run on createCommitmentButtonSlot#3?";
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
 * @brief CreateCommitmentQWidget::getInterval
 * @return
 */
udata::CommitmentFrequency CreateCommitmentQWidget::getInterval() {
  udata::CommitmentFrequency interval{};
  long long int size;
  QString currentSizeLabel = ui->frequencyTimeFormatQComboBox->currentText();
  if (currentSizeLabel == MINUTES_STRING) {
    size = SECONDS_IN_MINUTE * ui->frequencyTimeQLineEdit->text().toInt();
  } else {
    size = SECONDS_IN_HOUR * ui->frequencyTimeQLineEdit->text().toInt();
  }

  interval.goal = size;
  interval.frequency = ui->frequencyQComboBox->currentIndex() + 1;
  switch (getType()) {
  case udata::CommitmentType::WEEKLY:
    interval.timeWindowSize = WEEK_SIZE;
    break;
  case udata::CommitmentType::MONTHLY:
    interval.timeWindowSize = MONTH_SIZE; // Not supported currently
  default:
    interval.timeWindowSize = WEEK_SIZE;
  }
  return interval;
}
udata::CommitmentType CreateCommitmentQWidget::getType() {
  switch (this->getUI()->commitmentModeQCombox->currentIndex()) {
  case 0:
    return udata::CommitmentType::WEEKLY;
    break;
  case 1:
    return udata::CommitmentType::MONTHLY;
    break;
  default:
    return udata::CommitmentType::Custom;
  }
}

/**
 * @brief CreateCommitmentQWidget::getAudioCheckBox
 * @return
 */

/**
 * @brief CreateCommitmentQWidget::on_createCommitmentQFrame_destroyed
 */
void CreateCommitmentQWidget::on_createCommitmentQFrame_destroyed() {
  qDebug() << "on_createCommitmentQFrame_destroyed#1";
  //    delete udata::User::getInstance();
}
void CreateCommitmentQWidget::editCommitment(int commitmentIndex) {
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
    this->ui->frequencyTimeQLineEdit->setText(QString::number(
        util::toMinutes(currentCommitment.getFrequency().goal)));
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

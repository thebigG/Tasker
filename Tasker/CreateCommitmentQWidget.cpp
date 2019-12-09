#include "CreateCommitmentQWidget.h"
#include "ui_CreateCommitmentQWidget.h"
#include <CommStatsQWidget.h>
#include <Commitment.h>
#include <QDebug>
#include <QObject>
#include <StatsUtility.h>
#include <User.h>
#include <mainui.h>
#include <Listener.h>
using namespace util;
using namespace udata;
CreateCommitmentQWidget::CreateCommitmentQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::CreateCommitmentQWidget) {
    ui->setupUi(this);
    validator = new QIntValidator(0, 999, this);
    ui->qtyQLineEdit->setValidator(validator);
    connect(this->getUI()->createCommitmentQPushButton, &QPushButton::clicked,
            this, &CreateCommitmentQWidget::createCommitmentButtonSlot);
    connect(this->getUI()->backQPushButton, &QPushButton::clicked, this,
            &CreateCommitmentQWidget::backButtonSlot);
    connect(this->getUI()->dropDownTaskQComboBox, SIGNAL(activated(const QString &)),
            this, SLOT(dropDownTaskSlot(const QString &)));
}

CreateCommitmentQWidget::~CreateCommitmentQWidget() {
    delete ui;
}
Ui::CreateCommitmentQWidget *CreateCommitmentQWidget::getUI() {
    return ui;
}
void CreateCommitmentQWidget::backButtonSlot() {
    this->hide();
    MainUI::getInstance()->show();
}
void CreateCommitmentQWidget::createCommitmentButtonSlot() {
    this->hide();
    QVector<Session> sessions{};
    QVector<Engine::Listener::ListenerType> listeners;
    if(this->ui->checkKeyboardQCheckBox->checkState() == Qt::Checked )
    {
        listeners.push_back(Engine::Listener::ListenerType::keyboard);
    }
    if(this->ui->checkMicQCheckBox->checkState() == Qt::Checked )
    {
        listeners.push_back(Engine::Listener::ListenerType::audio);
    }
    Task newTask{ui->dropDownTaskQComboBox->currentText(), listeners};
    sessions.push_back(Session{newTask});
    Commitment temp{ this->getCommitmentName(), this->getStartDate(),
                     this->getEndDate(), this->getInterval(), sessions};
    udata::User::getInstance()->addCommitment(temp);
    CommStatsQWidget *wc = MainUI::getInstance()->getCommStats();
    wc->show();
}

QCheckBox *CreateCommitmentQWidget::getKeyboardCheckBox() {
    return ui->checkKeyboardQCheckBox;
}
QString CreateCommitmentQWidget::getCommitmentName() {
    return ui->commitmentNameQLineEdit->text();
}
QDate CreateCommitmentQWidget::getStartDate() {
    return ui->dateStartQDateEdit->date();
}
QDate CreateCommitmentQWidget::getEndDate() {
    return ui->dateEndQDateEdit->date();
}
util::Interval CreateCommitmentQWidget::getInterval() {
    util::Interval interval{};
    long long int size, frequency;
    QString currentSizeLabel = ui->dropDownUnitsLeftQComboBox->currentText();
    QString currentFrequencyLabel = ui->dropDownUnitsRightQComboBox->currentText();
    if (currentSizeLabel == MINUTES_STRING) {
        size = SECONDS_IN_MINUTE * ui->qtyQLineEdit->text().toInt();
    } else if (currentSizeLabel == HOURS_STRING) {
        size = SECONDS_IN_HOUR * ui->qtyQLineEdit->text().toInt();
    }
    if (currentFrequencyLabel == DAY_STRING) {
        frequency = SECONDS_IN_DAY;
    } else if (currentFrequencyLabel == WEEK_STRING) {
        frequency = SECONDS_IN_WEEK;
    } else if (currentFrequencyLabel == MONTH_STRING) {
        frequency = SECONDS_IN_30_DAYS;
    }
    interval.size = size;
    interval.frequency = frequency;
    return interval;
}
QCheckBox *CreateCommitmentQWidget::getAudioCheckBox() {
    ui->qtyQLabel;
    return ui->checkMicQCheckBox;
}
void CreateCommitmentQWidget::dropDownTaskSlot(const QString &arg1) {
    if (arg1 == QString(WRITING_STRING)) {
        this->getKeyboardCheckBox()->setCheckState(Qt::CheckState{ Qt::Checked });
        this->getAudioCheckBox()->setCheckState(Qt::CheckState{ Qt::Unchecked });
    } else if (arg1 == QString(MUSIC_STRING)) {
        this->getAudioCheckBox()->setCheckState(Qt::CheckState{ Qt::Checked });
        this->getKeyboardCheckBox()->setCheckState(Qt::CheckState{ Qt::Unchecked });
    } else if (arg1 == QString(CUSTOM_STRING)) {
        this->getAudioCheckBox()->setCheckState(Qt::CheckState{ Qt::Unchecked });
        this->getKeyboardCheckBox()->setCheckState(Qt::CheckState{ Qt::Unchecked });
    }
}

void CreateCommitmentQWidget::on_createCommitmentQFrame_destroyed() {
    delete udata::User::getInstance();
}

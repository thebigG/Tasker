#include "NewSessionQWidget.h"
#include "AudioHook.h"
#include "ui_NewSessionQWidget.h"
#include <Hook.h>
#include <LiveSession.h>
#include <MainUi.h>
#include <NewSessionQWidget.h>
#include <QString>
#include <Session.h>
#include <StatsUtility.h>
#include <Task.h>
#include <Timer.h>
#include <User.h>
#include <iostream>
using namespace udata;
using namespace Engine;
/**
 * @brief NewSessionQWidget::NewSessionQWidget
 * @param parent
 */
NewSessionQWidget::NewSessionQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::NewSessionQWidget) {
    ui->setupUi(this);
    connect(this->ui->backQPushButton, &QPushButton::clicked, this,
            &NewSessionQWidget::backButtonSlot);
    connect(this->ui->startTimerQPushButton, &QPushButton::clicked, this,
            &NewSessionQWidget::startTimerButtonSlot);
    connect(this->ui->audioQComboBox, QOverload<int>::of(&QComboBox::highlighted),
            this, &NewSessionQWidget::isJackActiveSlot);
    this->addAction(new QAction());
    this->actions().at(0)->setShortcut(QKeySequence::Cancel);
    connect(this->actions().at(0), &QAction::triggered, this, &QWidget::hide);
    goalText.reserve(100);
    goalText.resize(100);

    this->ui->audioQComboBox->setEnabled(false);

    connect(this->ui->audioQCheckBox, &QCheckBox::stateChanged, [this](int state) {
        if (state == Qt::CheckState::Checked) {
            this->ui->audioQComboBox->setEnabled(true);
        } else {
            this->ui->audioQComboBox->setEnabled(false);
        }
    });

    this->ui->audioQComboBox->installEventFilter(this);
}

/**
 * @brief TimerWindowQWidget::backButtonSlot
 */
void NewSessionQWidget::backButtonSlot() {
    this->hide();
    MainUI::getInstance()->show();
}
/**
 * @brief NewSessionQWidget::startTimerButtonSlot initializes all necessary
 * state to start a new session such as starting the Timer engine.
 */
void NewSessionQWidget::startTimerButtonSlot() {
    if (!validateSessionConfig()) {
        return;
    }
    std::vector<Engine::Hook::HookType> newHooks;
    if (this->ui->keyboardQCheckBox->isChecked() && this->ui->mouseQCheckBox->isChecked()) {
        newHooks.push_back(Engine::Hook::HookType::X_MOUSE_KEYBOARD);
    } else if (this->ui->keyboardQCheckBox->isChecked()) {
        newHooks.push_back(Engine::Hook::HookType::X_KEYBOARD);
    } else if (this->ui->mouseQCheckBox->isChecked()) {
        newHooks.push_back(Engine::Hook::HookType::X_MOUSE);
    }

    if (this->ui->audioQCheckBox->isChecked()) {
        newHooks.push_back(Engine::Hook::HookType::AUDIO);
    }
    EngineConfig newConfig{};
    newConfig.activeHooks = newHooks;
    Task newTask{ getTaskName(), newHooks };
    Session newSession{
        newTask, User::getInstance()->getCurrentCommitment().getFrequency().goal,
        QDate::currentDate()
    };
    newConfig.audioDevice = ui->audioQComboBox->currentText().toStdString();
    Hook::HookError error = Engine::Timer::getInstance()->initTimer(newConfig, newSession);
    if (error.getStatus() == Hook::HookError::HookErrorStatus::FAIL) {
        QMessageBox m{ QMessageBox::Critical, "Error",
                       "Error:" + QString::fromStdString(error.what()) };
        m.exec();
    }
    this->hide();
}
QString NewSessionQWidget::getTaskName() {
    return this->ui->taskLineEdit->text();
}
/**
 * @brief NewSessionQWidget::~NewSessionQWidget
 */
NewSessionQWidget::~NewSessionQWidget() {
    delete ui;
}

/**
 * @brief TimerWindowQWidget::updateGoalText
 */
void NewSessionQWidget::updateGoalText() {
    goalText.fill(' ');
    const QString &commitmentName =
        " \"" + QString{ User::getInstance()->getCurrentCommitment().getName() + "\"" } + " for ";
    goalText.replace(0, 5, "Goal:");
    goalText.replace(5, commitmentName.length(), commitmentName);
    util::formatTime(goalText,
                     User::getInstance()->getCurrentCommitment().getFrequency().goal,
                     goalContext, 5 + commitmentName.length());
    this->ui->goalQLabel->setText(goalText);
}

/**
  @todo Trying to figure out the best way to detect
  a mouse click on the combox box. Sadly the only way, I think,
  is to make my own custom  QComboBox class and override the
  behavior of the popup method. Which is not too bad I guess...
 * @brief NewSessionQWidget::isJackActiveSlot
 * @param index
 */
void NewSessionQWidget::isJackActiveSlot(int index) {
    qDebug() << "jack active:" << index;
}

void NewSessionQWidget::updateAudioDevices() {
    QStringList devices{};
    devices.clear();
    auto deviceNames = AudioHook::queryDeviceNames();
    for (auto &d : deviceNames) {
        devices.append(d.c_str());
    }
    this->setAudioQComboBoxItems(devices);
}

void NewSessionQWidget::updateAudioBackends() {
    QStringList devices{};
    devices.clear();
    auto deviceNames = AudioHook{ "" }.queryBackendNames();
    for (auto &d : deviceNames) {
        devices.append(d.c_str());
    }
    this->setAudioQComboBoxItems(devices);
}

void NewSessionQWidget::show() {
    updateGoalText();

    this->setWindowTitle("New session for \"" +
                         User::getInstance()->getCurrentCommitment().getName() + "\"");
    this->ui->taskLineEdit->setText(User::getInstance()->getCurrentCommitment().getName());

    //    updateAudioDevices();
    updateAudioBackends();

    QWidget::show();
}

void NewSessionQWidget::setAudioQComboBoxItems(QStringList items) {
    this->ui->audioQComboBox->clear();
    this->ui->audioQComboBox->insertItems(0, items);
}

bool NewSessionQWidget::eventFilter(QObject *obj, QEvent *event) {
    if (obj == this->ui->audioQComboBox) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *keyEvent = static_cast<QMouseEvent *>(event);
            //            updateAudioDevices();
            updateAudioBackends();
            return false;
        } else {
            return false;
        }
    } else {
        // pass the event on to the parent class
        return NewSessionQWidget::eventFilter(obj, event);
    }
}

/**
 * @brief NewSessionQWidget::validateSessionConfig
 * Validates the configuration of the new session.
 * The validation uses several criteria to consider a certain configuration
 * valid or not such as whether at least a hook is selected.
 * This method also updates the UI to inform to the user
 * about any validation they need to act upon(such as marking a textbox as red).
 * @return true is the current config is valid. Otherwisde return false.
 */
bool NewSessionQWidget::validateSessionConfig() {
    // TODO: Handle return status codes from
    // Hook API.
    bool valid = true;
    if (this->ui->taskLineEdit->text().isEmpty()) {
        valid = false;
        this->ui->taskLineEdit->setStyleSheet(Ui::invalidStateStylesheet);
    }
    if (this->ui->audioQCheckBox->checkState() == Qt::CheckState::Unchecked &&
        this->ui->keyboardQCheckBox->checkState() == Qt::CheckState::Unchecked &&
        this->ui->mouseQCheckBox->checkState() == Qt::CheckState::Unchecked) {
        valid = false;
        this->ui->audioQCheckBox->setStyleSheet(Ui::invalidStateStylesheet);
        this->ui->keyboardQCheckBox->setStyleSheet(Ui::invalidStateStylesheet);
        this->ui->mouseQCheckBox->setStyleSheet(Ui::invalidStateStylesheet);
    }
    return valid;
}

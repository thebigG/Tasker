#include "MainUi.h"

#include <UdataUtils.h>
#include <User.h>

#include <QDebug>

std::unique_ptr<MainUI> MainUI::mainHub;

using namespace udata;

MainUI::MainUI() {
    connect(commitmentMenu.addAction(NEW_COMMITMENT_STRING), &QAction::triggered,
            &commitmentHub, &CommStatsQWidget::newCommitmentSlot);
    connect(commitmentMenu.addAction(EDIT_COMMITMENT_STRING), &QAction::triggered,
            &commitmentHub, &CommStatsQWidget::editCommitmentSlot);
    connect(commitmentMenu.addAction(DELETE_COMMITMENT_STRING), &QAction::triggered,
            &commitmentHub, &CommStatsQWidget::deleteCommitmentSlot);
    connect(sessionMenu.addAction(NEW_SESSION_STRING), &QAction::triggered,
            &commitmentHub, &CommStatsQWidget::newSessionSlot);
    connect(&trayIcon, &QSystemTrayIcon::activated, this, &MainUI::trayIconShoWindowSlot);
    connect(trayIconMenu.addAction("Show/Hide"), &QAction::triggered, this,
            &MainUI::toggleShowWindow);

    connect(trayIconMenu.addAction("Quit"), &QAction::triggered, this, &MainUI::quitSlot);
    commitmentMenu.actions().at(0)->setShortcut(QKeySequence::New);

    liveSessionStatusAction = trayIconMenu.addAction(liveSessionStatusText);

    trayIcon.setIcon(QIcon{ ICONPATH });
    trayIcon.setContextMenu(&trayIconMenu);
    trayIcon.show();
    trayIcon.setToolTip("Tasker");
#ifdef __TASKER_DEBUG__
    sessionMenu.addAction(EDIT_SESSION_STRING);
    sessionMenu.addAction(DELETE_SESSION_STRING);
    this->setWindowTitle("Tasker(Debug)");
#endif
    mainMenuBar.addMenu(&commitmentMenu);
    mainMenuBar.addMenu(&sessionMenu);
    this->setMenuBar(&mainMenuBar);
    this->layout()->setContentsMargins(0, 0, 0, 0);
    this->layout()->setSpacing(0);
    commitmentHub.layout()->setSpacing(0);
    commitmentHub.setContentsMargins(0, 0, 0, 0);
    this->setCentralWidget(&commitmentHub);
    this->statusBar()->hide();
}
void MainUI::closeEvent(QCloseEvent *event) {
    event->ignore();
    this->hide();
    qDebug() << "closing event";
}

void MainUI::trayIconShoWindowSlot(QSystemTrayIcon::ActivationReason reason) {

    switch (reason) {
    case QSystemTrayIcon::ActivationReason::MiddleClick: {
        /** We ignore middle click because that would feel weird. */
        break;
    }
    default: {
        updateLiveSessionStatusAction();
        trayIconMenu.show();
        break;
    }
    }
}

/**
 * @brief MainUI::updateNewSessionActionState updates the state of the QAction
 * that allows users to create a new session. This method uses a handful of
 * heuristics to determine if the user is allowed to create a new session such
 * as, are they in the middle of a session at the moment, has this commitment
 * ended, etc.
 */
void MainUI::updateNewSessionActionState() {
    if (commitmentHub.getcurrentLiveSessionWidget().getCurrentState() == LiveSessionState::Started ||
        commitmentHub.getcurrentLiveSessionWidget().getCurrentState() ==
            LiveSessionState::Paused) {

        getNewSessionAction()->setEnabled(false);
        return;
    }

    if (User::getInstance()->getCurrentCommitment().isDone()) {
        getNewSessionAction()->setEnabled(false);
        return;
    }

    if (User::getInstance()
            ->getCurrentCommitment()
            .getCommitmentWindows()
            .last()
            .isDone()) {

        getNewSessionAction()->setEnabled(false);
        return;
    }

    if (!User::getInstance()
             ->getCurrentCommitment()
             .getCommitmentWindows()
             .last()
             .sessions.isEmpty()) {

        if (QDate::currentDate() == User::getInstance()
                                        ->getCurrentCommitment()
                                        .getCommitmentWindows()
                                        .last()
                                        .sessions.last()
                                        .getDate()) {
            getNewSessionAction()->setEnabled(false);
            return;
        }
    }

    getNewSessionAction()->setEnabled(true);
}
CommStatsQWidget &MainUI::getCommitmentHub() {
    return commitmentHub;
}

/**
 * @brief MainUI::getInstance
 * @return
 */
MainUI *MainUI::getInstance() {
    if (mainHub.get() == nullptr) {
        mainHub = std::make_unique<MainUI>();
    }
    return mainHub.get();
}
/**
 * @brief MainUI::saveTaskerState
 * Stores the state of Tasker on disk.
 * This includes all commitments,sessions or anything
 * that the user has changed since the last time that state was loaded.
 * This is called every time the application is about to be closed.
 */
void MainUI::saveTaskerStateSlot() {
    UdataUtils::saveUserData(*User::getInstance());
}
/**
 * @brief MainUI::newSessionActionState
 * @return true if Tasker is able to create a session at the moment; false
 * otherwise.
 */
bool MainUI::newSessionActionState() {
    return getNewSessionAction()->isEnabled();
}
bool MainUI::editCommitmentActionState() {
    return getEditCommitmentAction()->isEnabled();
}
bool MainUI::deleteCommitmentActionState() {
    return getDeleteCommitmentAction()->isEnabled();
}
/**
 * @brief MainUI::updateEditCommitmentActionState updates the state of the
 * QAction(whether it is enabled or disbaled) that is tasked with editing a
 * commitment.
 */
void MainUI::updateEditCommitmentActionState() {
    if (commitmentHub.getcurrentLiveSessionWidget().getCurrentState() !=
        LiveSessionState::Stopped) {
        if (commitmentHub.currentLiveSessionCommitment != commitmentHub.selectedCommitmentIndex) {
            this->getEditCommitmentAction()->setEnabled(true);
        } else {
            this->getEditCommitmentAction()->setEnabled(false);
        }
    } else {
        this->getEditCommitmentAction()->setEnabled(true);
    }
}
/**
 * @brief MainUI::updateDeleteCommitmentActionState updates the state of the
 * QAction tasked with deleting a commitment.
 * For example; if the user is in the middle of a session, then they
 * are not allowed to delete the commitment to which that new session belongs
 * to.
 */
void MainUI::updateDeleteCommitmentActionState() {
    if (commitmentHub.getcurrentLiveSessionWidget().getCurrentState() !=
        LiveSessionState::Stopped) {
        this->getDeleteCommitmentAction()->setEnabled(false);
    } else {
        this->getDeleteCommitmentAction()->setEnabled(true);
    }
}

/**
 * @brief MainUI::updateActionStates updates all of the QActions' states.
 * @todo Add logic for "Edit Commitment" QAction
 */
void MainUI::updateActionStates() {
    updateNewSessionActionState();
    updateEditCommitmentActionState();
    updateDeleteCommitmentActionState();
}
QAction *MainUI::getNewSessionAction() {
    return sessionMenu.actions().at(0);
}
QAction *MainUI::getEditCommitmentAction() {
    return commitmentMenu.actions().at(1);
}
QAction *MainUI::getDeleteCommitmentAction() {
    return commitmentMenu.actions().at(2);
}

/**
 * @brief toggleShowWindow Show/hide Tasker's window.
 *If Tasker is currently being shown, this method wil hide it.
 * If it is hiddedn, it will show Tasker.
 * This is very useful for Tasker's hide-on-close logic.
 */
void MainUI::toggleShowWindow() {
    if (this->isHidden()) {
        this->show();
    } else {
        this->hide();
    }
}

void MainUI::quitSlot() {
    if (commitmentHub.getcurrentLiveSessionWidget().getCurrentState() !=
        LiveSessionState::Stopped) {
        this->show();
    }

    if (mainHub->getCommitmentHub().getcurrentLiveSessionWidget().getCurrentState() ==
            LiveSessionState::Started ||
        mainHub->getCommitmentHub().getcurrentLiveSessionWidget().getCurrentState() ==
            LiveSessionState::Paused) {
        QMessageBox msgBox{};

        msgBox.setText("Session in progress.");
        msgBox.setInformativeText(
            "Do you want to save your progress for the session in progress?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard |
                                  QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Save:
            Engine::Timer::getInstance()->stopTimerSlot();
            // I don't love the way I'm hanlding this by going around and reaching the instance...
            Engine::Timer::getInstance()->quit();
            mainHub->getCommitmentHub().saveCurrentSession();
            QApplication::quit();
            break;
        case QMessageBox::Discard:
            // Don't Save was clicked
            Engine::Timer::getInstance()->stopTimerSlot();
            // I don't love the way I'm hanlding this by going around and reaching the instance...
            Engine::Timer::getInstance()->quit();
            QApplication::quit();
            break;
        case QMessageBox::Cancel:
            return;
        default:
            // should never be reached
            break;
        }
    }

    QApplication::quit();
}

void MainUI::updateLiveSessionStatusText() {
    QString prefix{ "LiveSession:" };
    liveSessionStatusText = prefix;
    if (commitmentHub.getcurrentLiveSessionWidget().getCurrentState() ==
        LiveSessionState::Started) {
        liveSessionStatusText += LIVESSION_IN_PROGRESS;
        switch (Engine::Timer::getInstance()->timerHookState) {
        case Engine::Hook::HookState::productive: {
            qDebug() << "productive case";
            liveSessionStatusText += "(productive)";
            break;
        }
        case Engine::Hook::HookState::unproductive: {
            liveSessionStatusText += "(unproductive)";
            qDebug() << "unproductive case";
            break;
        }
        default:
            break;
        }
    } else if (commitmentHub.getcurrentLiveSessionWidget().getCurrentState() ==
               LiveSessionState::Paused) {
        liveSessionStatusText += LIVESESSION_PAUSED;
    } else if (!User::getInstance()
                    ->getCurrentCommitment()
                    .getCommitmentWindows()
                    .last()
                    .sessions.isEmpty() &&
               QDate::currentDate() == User::getInstance()
                                           ->getCurrentCommitment()
                                           .getCommitmentWindows()
                                           .last()
                                           .sessions.last()
                                           .getDate()) {
        /**
        The session for the current commitment has been completed, so we
        update the status string accordingly.
        */
        liveSessionStatusText += LIVESSION_COMPLETE;

    } else {
        liveSessionStatusText += LIVESESSION_PENDING;
    }
}

void MainUI::updateLiveSessionStatusAction() {
    updateLiveSessionStatusText();
    liveSessionStatusAction->setText(liveSessionStatusText);
}

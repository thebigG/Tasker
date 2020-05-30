#include "mainui.h"

#include <UdataUtils.h>
#include <User.h>

#include <QDebug>

std::unique_ptr<MainUI> MainUI::mainHub;

using namespace udata;

MainUI::MainUI() {
  commitmentHub.update();

  connect(commitmentMenu.addAction(NEW_COMMITMENT_STRING), &QAction::triggered,
          &commitmentHub, &CommStatsQWidget::newCommitmentSlot);

  connect(commitmentMenu.addAction(EDIT_COMMITMENT_STRING), &QAction::triggered,
          &commitmentHub, &CommStatsQWidget::editCommitmentSlot);
  connect(commitmentMenu.addAction(DELETE_COMMITMENT_STRING),
          &QAction::triggered, &commitmentHub,
          &CommStatsQWidget::deleteCommitmentSlot);
  connect(sessionMenu.addAction(NEW_SESSION_STRING), &QAction::triggered,
          &commitmentHub, &CommStatsQWidget::newSessionSlot);
  commitmentMenu.actions().at(0)->setShortcut(QKeySequence::New);
#ifdef __TASKER_DEBUG__
  sessionMenu.addAction(EDIT_SESSION_STRING);
  sessionMenu.addAction(DELETE_SESSION_STRING);
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

void MainUI::update() {
  QMainWindow::update();
  commitmentHub.update();
}
void MainUI::updateNewSessionActionState() {
  if (User::getInstance()->getCurrentCommitment().isDone()) {
    getNewSessionAction()->setEnabled(false);
    qDebug() << "updateNewSessionActionState#1";
    return;
  }
  qDebug() << "frequency for timeWindow="
           << User::getInstance()
                  ->getCurrentCommitment()
                  .getCommitmentWindows()
                  .last()
                  .frequency;
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
CommStatsQWidget &MainUI::getCommitmentHub() { return commitmentHub; }

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
  qDebug() << "Saving state...";
  UdataUtils::saveUserData(*User::getInstance());
} /**
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

void MainUI::updateEditCommitmentActionState() {
  qDebug() << "commitmentHub.currentLiveSessionCommitment="
           << commitmentHub.currentLiveSessionCommitment
           << "commitmentHub.selectedCommitmentIndex"
           << commitmentHub.selectedCommitmentIndex;
  if (commitmentHub.getcurrentLiveSessionWidget().getCurrentState() !=
      LiveSessionState::Stopped) {
    if (commitmentHub.currentLiveSessionCommitment !=
        commitmentHub.selectedCommitmentIndex) {
      this->getEditCommitmentAction()->setEnabled(true);
    } else {
      this->getEditCommitmentAction()->setEnabled(false);
    }
  } else {
    this->getEditCommitmentAction()->setEnabled(true);
  }
}
void MainUI::updateDeleteCommitmentActionState() {
  if (commitmentHub.getcurrentLiveSessionWidget().getCurrentState() !=
      LiveSessionState::Stopped) {
    this->getDeleteCommitmentAction()->setEnabled(false);
  } else {
    this->getDeleteCommitmentAction()->setEnabled(true);
  }
}

/**
 * @brief MainUI::updateActionStates
 * @todo Add logic for "Edit Commitment" QAction
 */
void MainUI::updateActionStates() {
  updateNewSessionActionState();
  updateEditCommitmentActionState();
  updateDeleteCommitmentActionState();
}
QAction *MainUI::getNewSessionAction() { return sessionMenu.actions().at(0); }
QAction *MainUI::getEditCommitmentAction() {
  return commitmentMenu.actions().at(1);
}
QAction *MainUI::getDeleteCommitmentAction() {
  return commitmentMenu.actions().at(2);
}

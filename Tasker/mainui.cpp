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
  connect(commitmentMenu.addAction(DELETE_COMMITMENT_STRING),
          &QAction::triggered, &commitmentHub,
          &CommStatsQWidget::deleteCommitmentSlot);
  commitmentMenu.addAction(EDIT_COMMITMENT_STRING);
  connect(sessionMenu.addAction(NEW_SESSION_STRING), &QAction::triggered,
          &commitmentHub, &CommStatsQWidget::newSessionSlot);
  commitmentMenu.actions().at(0)->setShortcut(QKeySequence::New);
  sessionMenu.addAction(EDIT_SESSION_STRING);
  sessionMenu.addAction(DELETE_SESSION_STRING);
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
    sessionMenu.actions().at(0)->setEnabled(false);
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
      sessionMenu.actions().at(0)->setEnabled(false);
      return;
    }
  }
  sessionMenu.actions().at(0)->setEnabled(true);
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
  qDebug() << "Saving state";
  UdataUtils::saveUserData(*User::getInstance());
}
bool MainUI::newSessionActionState() {
  return this->sessionMenu.actions().at(0)->isEnabled();
}

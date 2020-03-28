#include "mainui.h"

#include <UdataUtils.h>
#include <User.h>

#include <QDebug>
std::unique_ptr<MainUI> MainUI::mainHub;

using namespace udata;

MainUI::MainUI() {
  commitmentHub.update();
  statusBar()->hide();
  this->menuBar()->hide();
  this->layout()->setContentsMargins(0, 0, 0, 0);
  this->layout()->setSpacing(0);
  commitmentHub.layout()->setSpacing(0);
  commitmentHub.setContentsMargins(0, 0, 0, 0);
  this->setCentralWidget(&commitmentHub);
  this->statusBar()->hide();
}

CommStatsQWidget& MainUI::getCommitmentHub() { return commitmentHub; }

/**
 * @brief MainUI::getInstance
 * @return
 */
MainUI* MainUI::getInstance() {
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

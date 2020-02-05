#include "mainui.h"
#include <QDebug>
#include <UdataUtils.h>
#include <User.h>
std::unique_ptr<CommStatsQWidget> MainUI::Instance;

using namespace udata;

/**
 * @brief MainUI::getInstance
 * @return
 */
CommStatsQWidget *MainUI::getInstance() {
    if(Instance.get() == nullptr)
    {
        Instance = std::make_unique<CommStatsQWidget>();
    }
    return Instance.get();
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

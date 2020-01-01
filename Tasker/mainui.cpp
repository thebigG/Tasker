#include "mainui.h"

TaskerUIMainWindowQWidget *MainUI::Instance = nullptr;

/**
 * @brief MainUI::MainUI
 */
MainUI::MainUI() {
}

/**
 * @brief MainUI::getInstance
 * @return
 */
TaskerUIMainWindowQWidget *MainUI::getInstance() {
    if (Instance == nullptr) {
        Instance = new TaskerUIMainWindowQWidget{};
    }
    return Instance;
}

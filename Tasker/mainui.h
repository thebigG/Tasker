#ifndef MAINUI_H
#define MAINUI_H

#include <TaskerUIMainWindowQWidget.h>

/**
 * @brief The MainUI class
 */
class MainUI {
private:
    MainUI();
    static TaskerUIMainWindowQWidget *Instance;

public:
    static TaskerUIMainWindowQWidget *getInstance();
};

#endif // MAINUI_H

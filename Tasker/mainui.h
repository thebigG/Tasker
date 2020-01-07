#ifndef MAINUI_H
#define MAINUI_H
#include <memory>
#include <TaskerUIMainWindowQWidget.h>

/**
 * @brief The MainUI class
 */
class MainUI {
private:
    MainUI();
    static TaskerUIMainWindowQWidget* Instance;

public:
    static TaskerUIMainWindowQWidget *getInstance();
//    static int getRefCount();
     ~MainUI();
};

#endif // MAINUI_H

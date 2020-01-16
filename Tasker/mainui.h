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
     ~MainUI();
public slots:
    static void saveTaskerStateSlot();
};

#endif // MAINUI_H

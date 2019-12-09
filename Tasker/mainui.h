#ifndef MAINUI_H
#define MAINUI_H
#include <TaskerUIMainWindowQWidget.h>

class MainUI
{
private:
    MainUI();
    static TaskerUIMainWindowQWidget* Instance ;
public:
     static TaskerUIMainWindowQWidget* getInstance();
};

#endif // MAINUI_H

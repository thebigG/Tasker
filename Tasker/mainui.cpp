#include "mainui.h"
TaskerUIMainWindowQWidget* MainUI::Instance = nullptr;
MainUI::MainUI()
{
}
TaskerUIMainWindowQWidget* MainUI::getInstance()
{
    if(Instance == nullptr){
        Instance = new TaskerUIMainWindowQWidget{};
    }
    return Instance;
}

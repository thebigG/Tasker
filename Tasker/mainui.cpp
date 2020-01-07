#include "mainui.h"
#include <QDebug>
TaskerUIMainWindowQWidget* MainUI::Instance = nullptr;

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
        Instance = new TaskerUIMainWindowQWidget();
        qDebug()<<"making shared pointer";
    }
//    qDebug()<<"Main window ref count"<<Instance.use_count();
    return Instance;
}
MainUI::~MainUI()
{
    qDebug()<<"MainUI destructor#1\n";
    delete Instance;
    qDebug()<<"MainUI destructor#2";
}

//int MainUI::getRefCount()
//{
//    return Instance.use_count();
//}

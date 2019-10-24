#include "taskermainui.h"
#include "ui_taskermainui.h"

TaskerMainUI::TaskerMainUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TaskerMainUI)
{
    ui->setupUi(this);

}

TaskerMainUI::~TaskerMainUI()
{
    delete ui;
}


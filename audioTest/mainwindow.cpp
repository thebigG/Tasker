#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread.h>
//extern Thread t;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect();
//    ui->centralwidget->
//    this->centralWidget()->;
//    this->ui->label_level->setText("testing 1");
}

MainWindow::~MainWindow()
{
    delete ui;
}
QLabel* MainWindow::getLabel()
{
    return ui->label_level;
}



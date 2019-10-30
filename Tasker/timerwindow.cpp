#include "timerwindow.h"
#include "ui_timerwindow.h"

timerwindow::timerwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::timerwindow)
{
    ui->setupUi(this);
}

timerwindow::~timerwindow()
{
    delete ui;
}


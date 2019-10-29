#include "Widget_CommStats.h"
#include "ui_Widget_CommStats.h"

Widget_CommStats::Widget_CommStats(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_CommStats)
{
    ui->setupUi(this);


}

Widget_CommStats::~Widget_CommStats()
{
    delete ui;
}

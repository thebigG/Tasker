#include "commstats.h"
#include "ui_commstats.h"

CommStats::CommStats(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommStats)
{
    ui->setupUi(this);


}

CommStats::~CommStats()
{
    delete ui;
}

#include "createcommitment.h"
#include "ui_createcommitment.h"

createcommitment::createcommitment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createcommitment)
{
    ui->setupUi(this);
}

createcommitment::~createcommitment()
{
    delete ui;
}

void createcommitment::on_pushButton_2_clicked()
{

}

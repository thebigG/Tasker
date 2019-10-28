#include "cratecommitment.h"
#include "ui_cratecommitment.h"

CrateCommitment::CrateCommitment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CrateCommitment)
{
    ui->setupUi(this);
}

CrateCommitment::~CrateCommitment()
{
    delete ui;
}

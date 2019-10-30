#include "tasker_test.h"
#include "ui_tasker_test.h"

Tasker_Test::Tasker_Test(QWidget *parent)
: QMainWindow(parent), ui(new Ui::Tasker_Test) {
    ui->setupUi(this);
}

Tasker_Test::~Tasker_Test() {
    delete ui;
}

#include "taskeruimainwindow.h"
#include "ui_taskeruimainwindow.h"

#include <iostream>

TaskerUIMainWindow::TaskerUIMainWindow(QWidget *parent)
: QWidget(parent), ui(new Ui::TaskerUIMainWindow) {
    ui->setupUi(this);

    x = new createcommitment;

    /*
    ui->label->setText("No Commitments at the moment");

    connect(ui->QPushButton_MakeCommitment,SIGNAL(clicked()), this,
    SLOT(hello_clicked())); ui->QPushButton_MakeCommitment->addAction();
    ui->QFrame_Welcome->hide();
    connect(this, SIGNAL(on_QPushButton_MakeCommitment_clicked));

    ui->label->setWordWrap(true);
    */
}

TaskerUIMainWindow::~TaskerUIMainWindow() {
    delete ui;
}

QPushButton *TaskerUIMainWindow::getButton() {
    return ui->QPushButton_MakeCommitment;
}

QFrame *TaskerUIMainWindow::getWelcomeFrame() {
    return ui->QFrame_Welcome;
}

createcommitment *TaskerUIMainWindow::getCreateCommitment() {
    return x;
}

/*
TaskerUIMainWindow* TaskerUIMainWindow::getUI()
{
    return this->ui;
}

Ui::TaskerUIMainWindow get_ui()
{
    return Ui::ui;
}

void TaskerUIMainWindow::hello_clicked()
{
    std::cout << "Clicked using connect!!!" << std::endl;
}
*/

void TaskerUIMainWindow::on_TaskerUIMainWindow_windowIconTextChanged(const QString &iconText) {
    iconText.isNull(); // just so the compiler errors go away for now
}

void TaskerUIMainWindow::on_QPushButton_MakeCommitment_clicked() {
}

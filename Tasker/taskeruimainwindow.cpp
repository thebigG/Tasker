#include "taskeruimainwindow.h"
#include "ui_taskeruimainwindow.h"
#include <stdlib.h>
#include <stdio.h>
TaskerUIMainWindow::TaskerUIMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskerUIMainWindow)
{
    ui->setupUi(this);
    x = new createcommitment();
//    ui->label->setText("No Commitments at the moment");
    this->setWindowTitle("Tasker");
//    connect(ui->QPushButton_MakeCommitment,SIGNAL(clicked()), this, SLOT(hello_clicked()));
//    ui->QPushButton_MakeCommitment->addAction();
//    ui->QFrame_Welcome->hide();
//    connect(this, SIGNAL(on_QPushButton_MakeCommitment_clicked));

//    ui->label->setWordWrap(true);
}
QPushButton* TaskerUIMainWindow::getButton()
{
    return ui->QPushButton_MakeCommitment;
}
createcommitment* TaskerUIMainWindow::getCreateCommitment()
{
    return x;
}
QFrame* TaskerUIMainWindow::getWelcomeFrame()
{
    return ui->QFrame_Welcome;
}
//TaskerUIMainWindow* TaskerUIMainWindow::getUI()
//{
//    return this->ui;
//}
//Ui::TaskerUIMainWindow get_ui()
//{
////    return Ui::ui;
//}
//void TaskerUIMainWindow::hello_clicked()
//{
//    printf("Clicked using connect!!!!");
//}
TaskerUIMainWindow::~TaskerUIMainWindow()
{
    delete ui;
}

void TaskerUIMainWindow::on_TaskerUIMainWindow_windowIconTextChanged(const QString &iconText)
{

}



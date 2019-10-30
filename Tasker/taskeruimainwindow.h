#ifndef TASKERUIMAINWINDOW_H
#define TASKERUIMAINWINDOW_H

#include "createcommitment.h"
#include "Widget_CommStats.h"
#include "timerwindow.h"

#include <QFrame>
#include <QPushButton>
#include <QWidget>

namespace Ui {
class TaskerUIMainWindow;
}

class TaskerUIMainWindow : public QWidget {
    Q_OBJECT

    public:
    explicit TaskerUIMainWindow(QWidget *parent = nullptr);
    ~TaskerUIMainWindow();

    QPushButton *getButton();
    createcommitment *getCreateCommitment();
    QFrame *getWelcomeFrame();
    Widget_CommStats *getCommStats();
    timerwindow *getTimerWindow();


    public slots:
    void on_QPushButton_MakeCommitment_clicked();

    public:
    Ui::TaskerUIMainWindow *ui;

private slots:
    void on_QPushButton_QuickSession_clicked();

private:
    createcommitment *x;
    Widget_CommStats *wc;
    timerwindow *tw;

    /*
    signals:
    void hello_clicked();
    */
};

#endif // TASKERUIMAINWINDOW_H

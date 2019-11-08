#ifndef TASKERUIMAINWINDOW_H
#define TASKERUIMAINWINDOW_H

#include "Widget_CommStats.h"
#include "createcommitmentqwidget.h"
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
    createCommitmentQWidget *getCreateCommitment();
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
    createCommitmentQWidget *createCommitmentWindow;
    Widget_CommStats *wc;
    timerwindow *tw;
};

#endif // TASKERUIMAINWINDOW_H

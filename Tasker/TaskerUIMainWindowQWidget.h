#ifndef TASKERUIMAINWINDOW_H
#define TASKERUIMAINWINDOW_H

#include "CommStatsQWidget.h"
#include "CreateCommitmentQWidget.h"
#include "TimerWindowQWidget.h"

#include <QFrame>
#include <QPushButton>
#include <QWidget>

namespace Ui {
class TaskerUIMainWindowQWidget;
}

class TaskerUIMainWindowQWidget : public QWidget {
    Q_OBJECT

public:
    explicit TaskerUIMainWindowQWidget(QWidget *parent = nullptr);
    ~TaskerUIMainWindowQWidget();

    QPushButton *getButton();
    CreateCommitmentQWidget *getCreateCommitment();
    QFrame *getWelcomeFrame();
    CommStatsQWidget *getCommStats();
    TimerWindowQWidget *getTimerWindow();

public:
    Ui::TaskerUIMainWindowQWidget *ui;

private slots:
    void on_makeCommitmentQPushButton_clicked();
    void on_quickSessionQPushButton_clicked();

    void on_welcomeQFrame_destroyed();

private:
    CreateCommitmentQWidget *x;
    CommStatsQWidget *wc;
    TimerWindowQWidget *tw;
};

#endif // TASKERUIMAINWINDOW_H

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

/**
 * @brief The TaskerUIMainWindowQWidget class
 */
class TaskerUIMainWindowQWidget : public QWidget {
    Q_OBJECT

public:
    explicit TaskerUIMainWindowQWidget(QWidget *parent = nullptr);
    ~TaskerUIMainWindowQWidget();

    QPushButton *getButton();
    CreateCommitmentQWidget &getCreateCommitment();
    QFrame *getWelcomeFrame();
    CommStatsQWidget &getCommStats();
    TimerWindowQWidget &getTimerWindow();

public:
    Ui::TaskerUIMainWindowQWidget *ui;

private slots:
    void makeCommitmentButtonSlot();
    void quickSessionButtonSlot();
    void on_welcomeQFrame_destroyed();

private:
    CreateCommitmentQWidget x;
    CommStatsQWidget wc;
    TimerWindowQWidget tw;
    LiveSession *s;
};

#endif // TASKERUIMAINWINDOW_H

#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

#include <QWidget>

namespace Ui {
class TimerWindowQWidget;
}

/**
 * @brief The TimerWindowQWidget class
 */
class TimerWindowQWidget : public QWidget {
    Q_OBJECT

public:
    explicit TimerWindowQWidget(QWidget *parent = nullptr);
    ~TimerWindowQWidget();
    QString getTaskName();

private slots:
    //    void on_backQPushButton_clicked();
    void backButtonSlot();
    void startTimerButtonSlot();
    void on_timerWindowQFrame_destroyed();
    void dropDownTaskSlot(const QString &arg1);

private:
    Ui::TimerWindowQWidget *ui;
};

#endif // TIMERWINDOW_H

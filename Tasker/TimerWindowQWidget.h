#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

#include <QWidget>

namespace Ui {
class TimerWindowQWidget;
}

class TimerWindowQWidget : public QWidget {
    Q_OBJECT

public:
    explicit TimerWindowQWidget(QWidget *parent = nullptr);
    ~TimerWindowQWidget();

private slots:
    void on_backQPushButton_clicked();

private:
    Ui::TimerWindowQWidget *ui;
};

#endif // TIMERWINDOW_H

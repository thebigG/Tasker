#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

#include <QWidget>
#include <livesession.h>
#include <memory>
namespace Ui {
class NewSessionQWidget;
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
  void show();
private slots:
  //    void on_backQPushButton_clicked();
  void backButtonSlot();
  void startTimerButtonSlot();
  void on_timerWindowQFrame_destroyed();
  void dropDownTaskSlot(const QString &arg1);

private:
  Ui::NewSessionQWidget *ui;
  std::unique_ptr<LiveSession> liveTimer;
  QString goalText{};
  QString goalContext{""};
  void updateGoalText();
};

#endif // TIMERWINDOW_H

#ifndef NEWSESSIONQWIDGET_H
#define NEWSESSIONQWIDGET_H

#include <QWidget>
#include <livesession.h>
#include <memory>
namespace Ui {
class NewSessionQWidget;
}

/**
 * @brief The TimerWindowQWidget class
 */
class NewSessionQWidget : public QWidget {
  Q_OBJECT

public:
  explicit NewSessionQWidget(QWidget *parent = nullptr);
  ~NewSessionQWidget();
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

#endif // NEWSESSIONQWIDGET_H

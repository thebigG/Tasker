#ifndef NEWSESSIONQWIDGET_H
#define NEWSESSIONQWIDGET_H

#include <QWidget>
#include <livesession.h>
#include <memory>
namespace Ui {
class NewSessionQWidget;
}

/**
 * @brief The NewSessionQWidget class represents the window that allows users to
 * decribe the new session they are about to start.
 */
class NewSessionQWidget : public QWidget {
  Q_OBJECT

public:
  explicit NewSessionQWidget(QWidget *parent = nullptr);
  ~NewSessionQWidget();
  QString getTaskName();
  void show();
private slots:
  void backButtonSlot();
  void startTimerButtonSlot();

private:
  Ui::NewSessionQWidget *ui;
  std::unique_ptr<LiveSession> liveTimer;
  QString goalText{};
  QString goalContext{""};
  void updateGoalText();
};

#endif // NEWSESSIONQWIDGET_H

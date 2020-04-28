#ifndef LIVESESSION_H
#define LIVESESSION_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <TaskerPerf/perftimer.h>
namespace Ui {
class LiveSession;
}

class LiveSession : public QWidget {
  Q_OBJECT

public:
  explicit LiveSession(QWidget *parent = nullptr);
  QLabel &getcongratsMessageLabel();
  QPushButton *getPlayButton();
  ~LiveSession();
private slots:
  void updateTimeUI();
  void congratsSlot();

private:
  Ui::LiveSession *ui;
  QString productiveTimeValueText;
  QString unproductiveTimeValueText;
  QString totalTimeValueText;
  QString contextText{""};
  Perf::PerfTimer liveSessionPerfTimer{};
  Perf::PerfTimer liveSessionPerfTimer1{};
  Perf::PerfTimer liveSessionPerfTimer2{};
  Perf::PerfTimer liveSessionPerfTimer3{};
};

#endif // LIVESESSION_H

#ifndef LIVESESSION_H
#define LIVESESSION_H

#include <QWidget>
#include <TaskerPerf/perftimer.h>
namespace Ui {
class LiveSession;
}

class LiveSession : public QWidget {
    Q_OBJECT

public:
    explicit LiveSession(QWidget *parent = nullptr);
    ~LiveSession();
private slots:
    void updateTimeUI();
    void congratsSlot();
    void on_productiveTimeValue_linkActivated(const QString &link);


private:
    Ui::LiveSession *ui;
    Perf::PerfTimer liveSessionPerfTimer{};
};

#endif // LIVESESSION_H

#ifndef WIDGET_COMMSTATS_H
#define WIDGET_COMMSTATS_H
#include "User.h"
#include <CreateCommitmentQWidget.h>
#include <QTreeWidget>
#include <QWidget>
#include <TimerWindowQWidget.h>
namespace Ui {
class CommStatsQWidget;
}

/**
 * @brief The CommStatsQWidget class
 */
class CommStatsQWidget : public QWidget {
    Q_OBJECT

public:
    explicit CommStatsQWidget(QWidget *parent = nullptr);
    TimerWindowQWidget &getTimerWindow();
    CreateCommitmentQWidget &getCreateCommitment();
    ~CommStatsQWidget();
    void func();
    void update();

private slots:
    void addCommitmentButtonSlot();
    void removeCommitmentButtonSlot();
    void currentCommitmentChangedSlot(QTreeWidgetItem *, QTreeWidgetItem *);
    void newLiveSessionSlot();
    void on_statsQFrame_destroyed();
    void on_commitmentsQTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::CommStatsQWidget *ui;
    bool isDelete = false;
    //    TempChartQWidget mw{};
    int selectedCommitmentIndex = 0;
    //    QVBoxLayout layout{};
    CreateCommitmentQWidget createCommimentWindow;
    TimerWindowQWidget timerWindow;
};

#endif // WIDGET_COMMSTATS_H

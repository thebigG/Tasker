#ifndef WIDGET_COMMSTATS_H
#define WIDGET_COMMSTATS_H

#include "TempChartQWidget.h"
#include "User.h"
#include <QTreeWidget>
#include <QWidget>
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
    ~CommStatsQWidget();
    void func();
    void update();

private slots:
    void addCommitmentButtonSlot();
    void removeCommitmentButtonSlot();
    void currentCommitmentChangedSlot(QTreeWidgetItem *, QTreeWidgetItem *);
    void on_statsQFrame_destroyed();
    void on_commitmentsQTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::CommStatsQWidget *ui;
    bool isDelete = false;
    //    TempChartQWidget mw{};
    int selectedCommitmentIndex = 0;
    QVBoxLayout layout{};
};

#endif // WIDGET_COMMSTATS_H

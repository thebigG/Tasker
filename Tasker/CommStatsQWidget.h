#ifndef WIDGET_COMMSTATS_H
#define WIDGET_COMMSTATS_H

#include "User.h"
#include <QWidget>
#include <QTreeWidget>

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
    void on_statsQFrame_destroyed();

    void on_commitmentsQTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::CommStatsQWidget *ui;
};

#endif // WIDGET_COMMSTATS_H

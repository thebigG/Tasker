#ifndef WIDGET_COMMSTATS_H
#define WIDGET_COMMSTATS_H

#include "User.h"
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

private slots:
    void addCommitmentButtonSlot();
    //    void on_addCommitmentQCommandLinkButton_clicked();
    void on_statsQFrame_destroyed();

private:
    Ui::CommStatsQWidget *ui;
};

#endif // WIDGET_COMMSTATS_H

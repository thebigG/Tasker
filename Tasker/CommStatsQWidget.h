#ifndef WIDGET_COMMSTATS_H
#define WIDGET_COMMSTATS_H

#include <QWidget>

namespace Ui {
class CommStatsQWidget;
}

class CommStatsQWidget : public QWidget {
    Q_OBJECT

public:
    explicit CommStatsQWidget(QWidget *parent = nullptr);
    ~CommStatsQWidget();

private slots:
    void on_addCommitmentQCommandLinkButton_clicked();

    void on_statsQFrame_destroyed();

private:
    Ui::CommStatsQWidget *ui;
};

#endif // WIDGET_COMMSTATS_H

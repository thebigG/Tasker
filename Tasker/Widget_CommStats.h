#ifndef WIDGET_COMMSTATS_H
#define WIDGET_COMMSTATS_H

#include <QWidget>

namespace Ui {
class Widget_CommStats;
}

class Widget_CommStats : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_CommStats(QWidget *parent = nullptr);
    ~Widget_CommStats();

private slots:
    void on_CommandLinkButton_AddNewCommitment_clicked();

private:
    Ui::Widget_CommStats *ui;
};

#endif // WIDGET_COMMSTATS_H

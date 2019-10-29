#ifndef COMMSTATS_H
#define COMMSTATS_H

#include <QWidget>

namespace Ui {
class CommStats;
}

class CommStats : public QWidget
{
    Q_OBJECT

public:
    explicit CommStats(QWidget *parent = nullptr);
    ~CommStats();

private:
    Ui::CommStats *ui;
};

#endif // COMMSTATS_H

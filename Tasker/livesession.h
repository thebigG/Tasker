#ifndef LIVESESSION_H
#define LIVESESSION_H

#include <QWidget>

namespace Ui {
class LiveSession;
}

class LiveSession : public QWidget
{
    Q_OBJECT

public:
    explicit LiveSession(QWidget *parent = nullptr);
    ~LiveSession();
private slots:
    void updateTimeUI();
    void on_productiveTimeValue_linkActivated(const QString &link);

private:
    Ui::LiveSession *ui;
};

#endif // LIVESESSION_H

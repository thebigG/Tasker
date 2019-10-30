#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

#include <QWidget>

namespace Ui {
class timerwindow;
}

class timerwindow : public QWidget
{
    Q_OBJECT

public:
    explicit timerwindow(QWidget *parent = nullptr);
    ~timerwindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::timerwindow *ui;
};

#endif // TIMERWINDOW_H

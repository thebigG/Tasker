#ifndef TASKERMAINUI_H
#define TASKERMAINUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TaskerMainUI; }
QT_END_NAMESPACE

class TaskerMainUI : public QMainWindow
{
    Q_OBJECT

public:
    TaskerMainUI(QWidget *parent = nullptr);
    ~TaskerMainUI();

private:
    Ui::TaskerMainUI *ui;
};
#endif // TASKERMAINUI_H

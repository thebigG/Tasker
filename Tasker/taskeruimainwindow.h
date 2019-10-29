#ifndef TASKERUIMAINWINDOW_H
#define TASKERUIMAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QFrame>

#include "createcommitment.h"

namespace Ui {
class TaskerUIMainWindow;
}

class TaskerUIMainWindow : public QWidget {
    Q_OBJECT

public:
    explicit TaskerUIMainWindow(QWidget *parent = nullptr);
    ~TaskerUIMainWindow();

    QPushButton* getButton();
    QFrame* getWelcomeFrame();
    createcommitment* getCreateCommitment();

public slots:
    void on_TaskerUIMainWindow_windowIconTextChanged(const QString &iconText);
    void on_QPushButton_MakeCommitment_clicked();

public:
    Ui::TaskerUIMainWindow *ui;

private:
    createcommitment* x;

signals:
    void hello_clicked();
};

#endif // TASKERUIMAINWINDOW_H

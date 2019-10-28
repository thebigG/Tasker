#ifndef CRATECOMMITMENT_H
#define CRATECOMMITMENT_H

#include <QMainWindow>

namespace Ui {
class CrateCommitment;
}

class CrateCommitment : public QMainWindow
{
    Q_OBJECT

public:
    explicit CrateCommitment(QWidget *parent = nullptr);
    ~CrateCommitment();

private:
    Ui::CrateCommitment *ui;
};

#endif // CRATECOMMITMENT_H

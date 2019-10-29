#ifndef CREATECOMMITMENT_H
#define CREATECOMMITMENT_H

#include <QWidget>

namespace Ui {
class createcommitment;
}

class createcommitment : public QWidget
{
    Q_OBJECT

public:
    explicit createcommitment(QWidget *parent = nullptr);
    ~createcommitment();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::createcommitment *ui;


};

#endif // CREATECOMMITMENT_H


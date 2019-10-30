#ifndef CREATECOMMITMENT_H
#define CREATECOMMITMENT_H

#include <QCheckBox>
#include <QIntValidator>
#include <QWidget>

namespace Ui {
class createcommitment;
}

class createcommitment : public QWidget {
    Q_OBJECT

    public:
    explicit createcommitment(QWidget *parent = nullptr);
    ~createcommitment();

    QCheckBox *getKeyboardCheckBox();
    QCheckBox *getAudioCheckBox();

    QValidator *validator;

    private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    private:
    Ui::createcommitment *ui;
};

#endif // CREATECOMMITMENT_H

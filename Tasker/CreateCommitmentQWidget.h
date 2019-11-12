#ifndef CREATECOMMITMENT_H
#define CREATECOMMITMENT_H

#include <QCheckBox>
#include <QIntValidator>
#include <QWidget>

namespace Ui {
class CreateCommitmentQWidget;
}

class CreateCommitmentQWidget : public QWidget {
    Q_OBJECT

public:
    explicit CreateCommitmentQWidget(QWidget *parent = nullptr);
    ~CreateCommitmentQWidget();

    QCheckBox *getKeyboardCheckBox();
    QCheckBox *getAudioCheckBox();

    QValidator *validator;

private slots:
    void on_backQPushButton_clicked();
    void on_createCommitmentQPushButton_clicked();
    void on_dropDownTaskQComboBox_activated(const QString &arg1);

private:
    Ui::CreateCommitmentQWidget *ui;
};

#endif // CREATECOMMITMENT_H

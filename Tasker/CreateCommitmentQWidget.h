#ifndef CREATECOMMITMENT_H
#define CREATECOMMITMENT_H

#include <QCheckBox>
#include <QIntValidator>
#include <QWidget>
#include <QLineEdit>
#include <QDateEdit>
#include <Interval.h>

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
    Ui::CreateCommitmentQWidget* getUI();
    QValidator *validator;
    QString getCommitmentName();
    QDate getStartDate();
    QDate getEndDate();
    util::Interval getInterval();

private slots:
//    void on_backQPushButton_clicked();
//    void on_createCommitmentQPushButton_clicked();
    void on_dropDownTaskQComboBox_activated(const QString &arg1);
    void createCommitmentButtonSlot();
    void backButtonSlot();
    void on_createCommitmentQFrame_destroyed();

private:
    Ui::CreateCommitmentQWidget *ui;
};

#endif // CREATECOMMITMENT_H

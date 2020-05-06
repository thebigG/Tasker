#ifndef CREATECOMMITMENT_H
#define CREATECOMMITMENT_H
#include <Commitment.h>
#include <CommitmentSnapshot.h>
#include <QCheckBox>
#include <QDateEdit>
#include <QIntValidator>
#include <QLineEdit>
#include <QWidget>
#define WRITING_STRING "Writing"
#define MUSIC_STRING "Compose Music"
#define CUSTOM_STRING "Custom"

namespace Ui {
class CreateCommitmentQWidget;
}

/**
 * @brief The CreateCommitmentQWidget class
 */
class CreateCommitmentQWidget : public QWidget {
  Q_OBJECT

public:
  explicit CreateCommitmentQWidget(QWidget *parent = nullptr);
  ~CreateCommitmentQWidget();
  Ui::CreateCommitmentQWidget *getUI();
  QIntValidator validator{(0, 999, this)};
  QString getCommitmentName();
  void show();
  QDate getStartDate();
  QDate getEndDate();
  void editCommitment(int commitmentIndex);
  udata::CommitmentFrequency getInterval();
  udata::CommitmentType getType();
signals:
  void commitmentEdit();

private slots:
  void createCommitmentButtonSlot();
  void backButtonSlot();
  void noEndDateCheckSlot(int);
  void on_createCommitmentQFrame_destroyed();
  void currentIndexCommitmentModeComboBoxSlot(const QString &);
  void currentIndexFrequencyComboBoxSlot(const QString &);

private:
  /**
   * @brief editing used for knowing whether this widget is being used for
   * editing a commitment or creating a new commitment.
   */
  bool editing = false;
  Ui::CreateCommitmentQWidget *ui;
};

#endif // CREATECOMMITMENT_H

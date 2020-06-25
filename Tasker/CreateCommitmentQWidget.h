#ifndef CREATECOMMITMENT_H
#define CREATECOMMITMENT_H
#include <Commitment.h>
#include <CommitmentSnapshot.h>
#include <QCheckBox>
#include <QDateEdit>
#include <QIntValidator>
#include <QLineEdit>
#include <QWidget>

namespace Ui {
class CreateCommitmentQWidget;
}

/**
 * @brief The CreateCommitmentQWidget class manages the window that alllow users
 * to edit and create commitments.
 */
class CreateCommitmentQWidget : public QWidget {
  Q_OBJECT

public:
  explicit CreateCommitmentQWidget(QWidget *parent = nullptr);
  ~CreateCommitmentQWidget();
  QIntValidator validator{(0, 999, this)};
  QString getCommitmentName();
  void show();
  QDate getStartDate();
  QDate getEndDate();
  void editCommitment();
  udata::CommitmentFrequency getCommitmentFrequency();
  udata::CommitmentType getType();

private slots:
  void createCommitmentButtonSlot();
  void backButtonSlot();
  void noEndDateCheckSlot();
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

#ifndef NEWSESSIONQWIDGET_H
#define NEWSESSIONQWIDGET_H

#include <LiveSession.h>
#include <QWidget>
#include <memory>
namespace Ui {
class NewSessionQWidget;
const QString invalidStateStylesheet{ "border: 1px solid red;" };
} // namespace Ui

/**
 * @brief The NewSessionQWidget class represents the window that allows users to
 * decribe the new session they are about to start.
 */
class NewSessionQWidget : public QWidget {
    Q_OBJECT

public:
    explicit NewSessionQWidget(QWidget *parent = nullptr);
    ~NewSessionQWidget();
    QString getTaskName();
    void setAudioDeviceQComboBoxItems(QStringList items);
    void setAudioBackendQComboBoxItems(QStringList items);
    void show();
private slots:
    void backButtonSlot();
    void startTimerButtonSlot();

    void isJackActiveSlot(int);
    void backendActivated(QString);

protected:
    bool eventFilter(QObject *obj, QEvent *ev);

private:
    Ui::NewSessionQWidget *ui;
    std::unique_ptr<LiveSession> liveTimer;
    QString goalText{};
    QString goalContext{ "" };
    void updateGoalText();
    void updateAudioDevices(std::string backend);
    void updateAudioBackends();
    bool validateSessionConfig();
};

#endif // NEWSESSIONQWIDGET_H

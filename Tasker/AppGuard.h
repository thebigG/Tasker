#ifndef AppGuard_H
#define AppGuard_H

#include <QCryptographicHash>
#include <QObject>
#include <QSharedMemory>
#include <QSystemSemaphore>

#define TASKER_KEY "tasker_key"
/**
 * @brief The AppGuard class prevents multiple instances of Tasker to be running
 * at the same time. It essentially creates a unique hash key on shared memory.
 * Given the ocassion that a second instance of Tasker attempts to exist, it
 * checks this hash and make sure that one else is using  it.
 * @note This class and mechanism is heavily based on this code
 * sample:https://stackoverflow.com/a/28172162/3038882
 * Thanks a million to stackoverflow users, saving my tail as always :)!
 */
class AppGuard {

public:
    AppGuard(const QString &key);
    ~AppGuard();

    bool isAnotherRunning();
    bool tryToRun();
    void release();

private:
    const QString key;
    const QString memLockKey;
    const QString sharedmemKey;

    QSharedMemory sharedMem;
    QSystemSemaphore memLock;

    QString generateKeyHash(const QString &key, const QString &salt);
    Q_DISABLE_COPY(AppGuard)
};

#endif // AppGuard_H

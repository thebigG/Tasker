#ifndef SESSION_H
#define SESSION_H
#include "Task.h"
#include <QDataStream>
#include <QDate>

namespace udata {
class Session;
QDataStream &operator<<(QDataStream &out, const udata::Session &newSession);
QDataStream &operator>>(QDataStream &in, udata::Session &newSession);
} // namespace udata

/**
 * @brief The udata::Session class
 */
class udata::Session {
public:
  Session();
  Session(Task newTask, long long goalLength, QDate date);
  Session(Task);
  const Task &getTask() const;
  void setTask(Task value);

  long long getProductiveTime() const;
  void setProductiveTime(long long value);

  long long getUnproductiveTime() const;
  void setUnproductiveTime(long long int value);

  QString &getNotes();
  void setNotes(QString value);

  QVector<QString> &getMedia();
  void setMedia(QVector<QString> value);

  long long getLength() const;
  void setLength(long long int value);

  void setGoal(int);
  long long int getGoal();

  QDate getDate() const;

private:
  Task task;
  long long int goal;
  long long int productiveTime;
  long long int unproductiveTime;
  QString notes;
  QVector<QString> media;
  long long int length;
  QDate date;
  friend QDataStream &operator<<(QDataStream &out,
                                 const udata::Session &newSession);
  friend QDataStream &operator>>(QDataStream &in, udata::Session &newSession);
};

#endif // SESSION_H

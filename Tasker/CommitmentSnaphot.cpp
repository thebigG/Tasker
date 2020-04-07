#include <StatsUtility.h>

#include "CommitmentSnapshot.h"

udata::CommitmentSnaphot::CommitmentSnaphot(int numberOfBars,
                                            QString customCategories)
    : QWidget() {
  //    sets.push_back(QBarSet("Test#1"));

  productiveBarSet << 95 << 0 << 0 << 0 << 0 << 0 << 0;
  unproductiveBarSet << 0 << 0 << 0 << 0 << 0 << 0 << 0;
  qDebug() << "size of barset=" << sizeof(QBarSet);
  qDebug() << "size of bar_series=" << sizeof(QBarSeries);
  qDebug() << "size of QBarCategoryAxis=" << sizeof(QBarCategoryAxis);
  qDebug() << "size of QValueAxis=" << sizeof(QValueAxis);
  series.append(&productiveBarSet);
  series.append(&unproductiveBarSet);
  chart.addSeries(&series);
  chart.setTitle("Simple barchart example");
  chart.setAnimationOptions(QChart::SeriesAnimations);
  categories << "Mon"
             << "Tue"
             << "Wed"
             << "Thu"
             << "Fri"
             << "Sat"
             << "Sun";
  x.append(categories);
  chart.addAxis(&x, Qt::AlignBottom);
  series.attachAxis(&x);
  y.setRange(1, 100);
  nextSnapshotLabel.setText(">");
  previousSnaphotLabel.setText("<");
  nextSnapshotLabel.setMaximumSize(20, 20);
  previousSnaphotLabel.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  previousSnaphotLabel.setMaximumSize(20, 20);
  qDebug() << "previous label size policy="
           << previousSnaphotLabel.sizePolicy();

  //  y.setMax(50);
  y.setTickCount(3);
  y.setLabelFormat("%d Mins");
  chart.addAxis(&y, Qt::AlignLeft);
  series.attachAxis(&y);
  qDebug() << "default bar width constructor=" << series.barWidth();
  series.setBarWidth(1);
  chart.legend()->setVisible(true);
  chart.legend()->setAlignment(Qt::AlignBottom);
  chartFont = chart.font();
  chartFont.setPointSize(15);
  chart.setTitleFont(chartFont);
  view.setChart(&chart);
  qDebug() << "size of view" << view.size();
  qDebug() << "size of chart" << chart.size();
  //  view.setMinimumSize(view.size());
  //  chart.setMinimumSize(view.size().width() + 100, view.size().height());
  //  chart.setPreferredSize(view.size());
  //  chart.layout()->setContentsMargins(0, 0, 0, 0);
  //  chart.layout()->activate();
  //  chart.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  qDebug() << "size policy for chart" << chart.sizePolicy();
  //  chart.setSizePolicy();
  //  view.setSizeIncrement(QSizePolicy::Ignored, QSizePolicy::Expanding);
  //  view.setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Expanding);
  this->setLayout(new QGridLayout());
  //  static_cast<QGridLayout *>(this->layout())->setHorizontalSpacing(0);
  detailsWidget.setLayout(new QGridLayout());
  view.setRenderHint(QPainter::Antialiasing);
  getView().setAlignment(Qt::AlignCenter);
  //  static_cast<QGridLayout *>(this->layout())
  //      ->addWidget(&previousSnaphotLabel, 0, 0);
  this->layout()->setContentsMargins(0, 0, 0, 0);
  this->layout()->setSpacing(0);
  static_cast<QGridLayout *>(this->layout())->setHorizontalSpacing(0);
  static_cast<QGridLayout *>(this->layout())->addWidget(&getView(), 0, 0);
  //  static_cast<QGridLayout *>(this->layout())
  //     ->addWidget(&nextSnapshotLabel, 0, 2);
  QPalette p = view.palette();
  p.setColor(QPalette::ColorRole::Background, Qt::white);
  this->setAutoFillBackground(true);
  //  this->setPalette(p);
  this->setPalette(p);
  QPalette labelPalette = productiveTimeAvgLabel.palette();
  labelPalette.setColor(QPalette::ColorRole::Foreground,
                        productiveBarSet.color());
  productiveTimeAvgLabel.setPalette(labelPalette);

  labelPalette = unproductiveTimeAvgLabel.palette();
  labelPalette.setColor(QPalette::ColorRole::Foreground,
                        unproductiveBarSet.color());
  unproductiveTimeAvgLabel.setPalette(labelPalette);
  static_cast<QGridLayout *>(detailsWidget.layout())
      ->addWidget(&productiveTimeAvgLabel, 0, 0);
  static_cast<QGridLayout *>(detailsWidget.layout())
      ->addWidget(&unproductiveTimeAvgLabel, 0, 1);
  static_cast<QGridLayout *>(this->layout())->addWidget(&detailsWidget, 1, 0);
  //  static_cast<QGridLayout
  //  *>(this->layout())->addWidget(productiveTimeAvgLabel);
}

QChartView &udata::CommitmentSnaphot::getView() { return view; }
/**
  This function assumes that the sessions in updateData
  are sorted from oldest to newest.
 * This is a time-sensitive function. Whatever it executes, it MUST return
 * within 250 milliseconds, which is human perception threshold.
 * Current latency(average)=15 milliseconds.
 * @brief udata::CommitmentSnaphot::update
 * @param updateData
 * @param currentTimeWindow
 */
void udata::CommitmentSnaphot::update(util::TimeWindow &currentWindow,
                                      udata::CommitmentType type,
                                      int commitmentGoal) {
  //  util::TimeWindow currentWindow =
  //      updateData.getCommitmentWindows().at(currentTimeWindow);
  QDate dayOfTheWeek = QDate{currentWindow.startDate};
  qDebug() << "_________________________________________________";
  x.clear();
  if (type == udata::CommitmentType::WEEKLY) {
    for (int i = 0; i < WEEK_SIZE; i++) {
      productiveBarSet.replace(i, 0);
      unproductiveBarSet.replace(i, 0);
      x.append(dayOfTheWeek.toString("ddd"));
      dayOfTheWeek = dayOfTheWeek.addDays(1);
    }
  }
  /* Need to reset the state of the bars in order to re-render them with new
   * values
   */
  series.take(&productiveBarSet);
  series.take(&unproductiveBarSet);
  unproductiveBarSet.setParent(nullptr);
  productiveBarSet.setParent(nullptr);
  int temp = 0;
  for (int i = 0; i < currentWindow.sessions.length(); i++) {
    qDebug() << "productive time in minutes"
             << util::StatsUtility::toMinutes(
                    currentWindow.sessions[i].getProductiveTime());
    qDebug() << "unproducive time in minutes"
             << util::StatsUtility::toMinutes(
                    currentWindow.sessions[i].getUnproductiveTime());
    qDebug() << "session date diff-->"
             << currentWindow.startDate.daysTo(
                    currentWindow.sessions[i].getDate());
    qDebug() << "day in session=" << currentWindow.sessions[i].getDate().day();
    qDebug() << "day in start"
             << "date=" << currentWindow.startDate.day();
    temp = getWeekDayIndex(currentWindow.startDate,
                           currentWindow.sessions[i].getDate());
    productiveBarSet.replace(
        temp, util::StatsUtility::toMinutes(
                  currentWindow.sessions[i].getProductiveTime()));
    unproductiveBarSet.replace(
        temp, util::StatsUtility::toMinutes(
                  currentWindow.sessions[i].getUnproductiveTime()));
  }

  series.append(&productiveBarSet);
  series.append(&unproductiveBarSet);
  y.setRange(0, util::StatsUtility::toMinutes(commitmentGoal));
  QString dateRange{currentWindow.startDate.toString() + "--" +
                    currentWindow.endDate.toString()};

  chart.setTitle(dateRange);
  productiveTimeAverage =
      productiveBarSet.sum() / currentWindow.sessions.length();
  unproductiveTimeAverage =
      unproductiveBarSet.sum() / currentWindow.sessions.length();
  productiveRatio = productiveBarSet.sum() / productiveBarSet.sum() +
                    unproductiveBarSet.sum();
  unproductiveRatio = unproductiveBarSet.sum() / productiveBarSet.sum() +
                      unproductiveBarSet.sum();
  //  Format average productive time
  productibeTimeAvgText.fill(' ');
  int numberOfHours = (int)productiveTimeAverage / MINUTES_IN_HOUR;
  temp = QString::number(numberOfHours).length();
  productibeTimeAvgText.insert(0, QString::number(numberOfHours));
  productibeTimeAvgText.insert(temp, 'h');
  temp = temp + 1;
  productibeTimeAvgText.insert(
      temp, QString::number(((int)productiveTimeAverage) -
                            (numberOfHours * MINUTES_IN_HOUR)));
  temp += QString::number(((int)productiveTimeAverage) -
                          (numberOfHours * MINUTES_IN_HOUR))
              .length();
  productibeTimeAvgText.insert(temp, 'm');
  temp = temp + 1;
  productibeTimeAvgText.insert(temp, " in Productive Average");
  productiveTimeAvgLabel.setText(productibeTimeAvgText);
  // For average unproductive time
  unproductibeTimeAvgText.fill(' ');
  numberOfHours = (int)unproductiveTimeAverage / MINUTES_IN_HOUR;
  temp = QString::number(numberOfHours).length();
  unproductibeTimeAvgText.insert(0, QString::number(numberOfHours));
  unproductibeTimeAvgText.insert(temp, 'h');
  temp = temp + 1;
  unproductibeTimeAvgText.insert(
      temp, QString::number((int)unproductiveTimeAverage -
                            numberOfHours * MINUTES_IN_HOUR));
  temp += QString::number((int)unproductiveTimeAverage -
                          numberOfHours * MINUTES_IN_HOUR)
              .length();
  unproductibeTimeAvgText.insert(temp, 'm');
  temp = temp + 1;
  unproductibeTimeAvgText.insert(temp, " in Unproductive Average");
  //  temp.append(QString::number(productiveTimeAverage));
  unproductiveTimeAvgLabel.setText(unproductibeTimeAvgText);
  chart.legend()->setAlignment(Qt::AlignBottom);
  view.setRenderHint(QPainter::Antialiasing);
  qDebug() << "average for productive time=" << productiveTimeAverage;
  qDebug() << "default bar width update=" << series.barWidth();
  qDebug() << "previous label size hint" << previousSnaphotLabel.sizeHint();
  qDebug() << "previous label size policy="
           << previousSnaphotLabel.sizePolicy();
  qDebug() << "view size" << view.size();

  qDebug() << "view size policy" << view.sizePolicy();
  qDebug() << "horizontal spacing"
           << static_cast<QGridLayout *>(this->layout())->horizontalSpacing();
  qDebug() << "size hint of view in " << view.sizeHint();
  qDebug() << "size of chart in update" << chart.size();
  view.setMinimumSize(492, 528);
  qDebug() << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
}

int udata::CommitmentSnaphot::getWeekDayIndex(QDate &dateWindowStart,
                                              QDate &sessionDay) {
  return dateWindowStart.daysTo(sessionDay);
}
QBarSet &udata::CommitmentSnaphot::getProductiveQBarSet() {
  return productiveBarSet;
}
QBarSet &udata::CommitmentSnaphot::getUnproducitveQbarSet() {
  return unproductiveBarSet;
}
double udata::CommitmentSnaphot::getProductiveTimeAverage() {
  return productiveTimeAverage;
}

double udata::CommitmentSnaphot::getUnproductiveTimeAverage() {
  return unproductiveTimeAverage;
}
QPushButton &udata::CommitmentSnaphot::getNextSnapshotLabel() {
  return nextSnapshotLabel;
}
QPushButton &udata::CommitmentSnaphot::getPreviousSnaphotLabel() {
  return previousSnaphotLabel;
}

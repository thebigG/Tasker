#include <StatsUtility.h>

#include "CommitmentSnapshot.h"
/**
 * @brief CommitmentSnaphot::CommitmentSnaphot Initializes a dummy chart.
 * @param numberOfBars
 * @param customCategories
 */
CommitmentSnaphot::CommitmentSnaphot(int numberOfBars, QString customCategories)
    : QWidget() {
  productiveBarSet << 95 << 0 << 0 << 0 << 0 << 0 << 0;
  unproductiveBarSet << 0 << 0 << 0 << 0 << 0 << 0 << 0;
  series.append(&productiveBarSet);
  series.append(&unproductiveBarSet);
  chart.addSeries(&series);
  chart.setTitle("Simple barchart example");
  chart.setAnimationOptions(QChart::NoAnimation);
  categories << "Mon"
             << "Tue"
             << "Wed"
             << "Thu"
             << "Fri"
             << "Sat"
             << "Sun";
  weekAxis.append(categories);
  chart.addAxis(&weekAxis, Qt::AlignBottom);
  series.attachAxis(&weekAxis);
  minuteAxis.setRange(1, 100);
  previousSnaphotLabel.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  previousSnaphotLabel.setMaximumSize(20, 20);
  minuteAxis.setTickCount(3);
  minuteAxis.setLabelFormat("%d Mins");
  chart.addAxis(&minuteAxis, Qt::AlignLeft);
  series.attachAxis(&minuteAxis);
  qDebug() << "default bar width constructor=" << series.barWidth();
  series.setBarWidth(1);
  chart.legend()->setVisible(true);
  chart.legend()->setAlignment(Qt::AlignBottom);
  chartFont = chart.font();
  chartFont.setPointSize(15);
  chart.setTitleFont(chartFont);
  view.setChart(&chart);
  this->setLayout(new QGridLayout());
  detailsWidget.setLayout(new QGridLayout());
  view.setRenderHint(QPainter::Antialiasing);
  getView().setAlignment(Qt::AlignCenter);
  this->layout()->setContentsMargins(0, 0, 0, 0);
  this->layout()->setSpacing(0);
  static_cast<QGridLayout *>(this->layout())->setHorizontalSpacing(0);
  static_cast<QGridLayout *>(this->layout())->addWidget(&getView(), 0, 0);
  QPalette p = view.palette();
  p.setColor(QPalette::ColorRole::Background, Qt::white);
  this->setAutoFillBackground(true);
  this->setPalette(p);
  QPalette labelPalette = productiveTimeAvgLabel.palette();
  labelPalette.setColor(QPalette::ColorRole::Foreground,
                        productiveBarSet.color());
  productiveTimeAvgLabel.setPalette(labelPalette);
  chartFont.setBold(true);
  chartFont.setPointSize(chartFont.pointSize() - 2);
  productiveTimeAvgLabel.setFont(chartFont);
  labelPalette = unproductiveTimeAvgLabel.palette();
  labelPalette.setColor(QPalette::ColorRole::Foreground,
                        unproductiveBarSet.color());
  unproductiveTimeAvgLabel.setPalette(labelPalette);
  unproductiveTimeAvgLabel.setFont(chartFont);
  static_cast<QGridLayout *>(detailsWidget.layout())
      ->addWidget(&productiveTimeAvgLabel, 0, 0);
  static_cast<QGridLayout *>(detailsWidget.layout())
      ->addWidget(&unproductiveTimeAvgLabel, 0, 1);
  static_cast<QGridLayout *>(this->layout())->addWidget(&detailsWidget, 1, 0);
  chart.setBackgroundVisible(false);
}

QChartView &CommitmentSnaphot::getView() { return view; }
/**
 * @brief udata::CommitmentSnaphot::update
 * This function assumes that the sessions in currentWindow
  are sorted from oldest to newest.
 * This is a time-sensitive function. Whatever it executes, it MUST return
 * within 250 milliseconds, which is the human perception threshold.
 * Current latency(average)=20 milliseconds.
 * @param currentWindow
 * @param type
 * @param commitmentGoal
 */
void CommitmentSnaphot::update(udata::TimeWindow &currentWindow,
                               udata::CommitmentType type, int commitmentGoal) {

  QDate dayOfTheWeek = QDate{currentWindow.startDate};
  weekAxis.clear();
  /*Maps the dates to week days(like Monday, Tuesday, etc).
   */
  if (type == udata::CommitmentType::WEEKLY ||
      type == udata::CommitmentType::EVERDAY) {
    for (int i = 0; i < WEEK_SIZE; i++) {
      productiveBarSet.replace(i, 0);
      unproductiveBarSet.replace(i, 0);
      if (dayOfTheWeek == QDate::currentDate()) {
        weekAxis.append("Today");
      } else {
        weekAxis.append(dayOfTheWeek.toString("ddd"));
      }

      dayOfTheWeek = dayOfTheWeek.addDays(1);
    }
  }
  int numberOfSessions = currentWindow.sessions.length();
  /* Need to reset the state of the bars in order to re-render them with new
   * values
   */
  series.take(&productiveBarSet);
  series.take(&unproductiveBarSet);
  unproductiveBarSet.setParent(nullptr);
  productiveBarSet.setParent(nullptr);
  int temp = 0;
  /*
   * Gather session data to update all the bar sets.
   */
  for (int i = 0; i < numberOfSessions; i++) {
    temp = getWeekDayIndex(currentWindow.startDate,
                           currentWindow.sessions[i].getDate());
    productiveBarSet.replace(
        temp,
        (int)util::toMinutes(currentWindow.sessions[i].getProductiveTime()));
    unproductiveBarSet.replace(
        temp,
        (int)util::toMinutes(currentWindow.sessions[i].getUnproductiveTime()));
  }

  series.append(&productiveBarSet);
  series.append(&unproductiveBarSet);
  minuteAxis.setRange(0, util::toMinutes(commitmentGoal));
  minuteAxis.setTickCount(3);
  QString dateRange{currentWindow.startDate.toString() + "--" +
                    currentWindow.endDate.toString()};

  chart.setTitle(dateRange);
  if (numberOfSessions == 0) {
    numberOfSessions = 1;
  }
  /*Render and prepare meata data such as the average for this TimeWindow(such
   * as week) about these sessions.
   */
  productiveTimeAverage = productiveBarSet.sum() / numberOfSessions;
  unproductiveTimeAverage = unproductiveBarSet.sum() / numberOfSessions;
  productiveRatio = productiveBarSet.sum() / productiveBarSet.sum() +
                    unproductiveBarSet.sum();
  unproductiveRatio = unproductiveBarSet.sum() / productiveBarSet.sum() +
                      unproductiveBarSet.sum();
  util::formatTime(productibeTimeAvgText,
                   util::minutesToSeconds(productiveTimeAverage),
                   productiveTimeAvgLabelContext);
  productiveTimeAvgLabel.setText(productibeTimeAvgText);
  util::formatTime(unproductibeTimeAvgText,
                   util::minutesToSeconds(unproductiveTimeAverage),
                   unproductiveTimeAvgLabelContext);
  unproductiveTimeAvgLabel.setText(unproductibeTimeAvgText);
  chart.legend()->setAlignment(Qt::AlignBottom);
  view.setRenderHint(QPainter::Antialiasing);
  series.setLabelsVisible();
  series.setLabelsFormat("@value");
  series.setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
}
/**
 * @brief CommitmentSnaphot::getWeekDayIndex Maps sessionDay to an index of
 * the week relative to dateWindowStart. For example, say that we have January
 * 17th as sessionDay and January 15th, this function will return 2.
 * @param dateWindowStart
 * @param sessionDay
 * @return
 */
int CommitmentSnaphot::getWeekDayIndex(QDate &dateWindowStart,
                                       QDate &sessionDay) {
  return dateWindowStart.daysTo(sessionDay);
}
QBarSet &CommitmentSnaphot::getProductiveQBarSet() { return productiveBarSet; }
QBarSet &CommitmentSnaphot::getUnproducitveQbarSet() {
  return unproductiveBarSet;
}
double CommitmentSnaphot::getProductiveTimeAverage() {
  return productiveTimeAverage;
}

double CommitmentSnaphot::getUnproductiveTimeAverage() {
  return unproductiveTimeAverage;
}
QPushButton &CommitmentSnaphot::getNextSnapshotLabel() {
  return nextSnapshotLabel;
}
QPushButton &CommitmentSnaphot::getPreviousSnaphotLabel() {
  return previousSnaphotLabel;
}

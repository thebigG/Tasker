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
  //  y.setMax(50);
  y.setTickCount(3);
  y.setLabelFormat("%d Mins");
  chart.addAxis(&y, Qt::AlignLeft);
  series.attachAxis(&y);
  qDebug() << "default bar width=" << series.barWidth();
  series.setBarWidth(1);
  chart.legend()->setVisible(true);
  chart.legend()->setAlignment(Qt::AlignBottom);
  chartFont = chart.font();
  chartFont.setPointSize(15);
  chart.setTitleFont(chartFont);
  view.setChart(&chart);
  qDebug() << "size of view" << view.size();
  this->setLayout(new QGridLayout());
  detailsWidget.setLayout(new QGridLayout());
  view.setRenderHint(QPainter::Antialiasing);
  this->layout()->addWidget(&getView());
  QPalette p = view.palette();
  view.palette();
  p.setColor(QPalette::ColorRole::Background, Qt::white);
  this->setAutoFillBackground(true);
  //  this->setPalette(p);
  this->setPalette(p);
  QPalette labelPalette = productiveTimeAvgLabel.palette();
  labelPalette.setColor(QPalette::ColorRole::Foreground,
                        productiveBarSet.color());
  productiveTimeAvgLabel.setPalette(labelPalette);
  static_cast<QGridLayout *>(detailsWidget.layout())
      ->addWidget(&productiveTimeAvgLabel, 0, 0);
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
 * @brief udata::CommitmentSnaphot::update
 * @param updateData
 * @param currentTimeWindow
 */
void udata::CommitmentSnaphot::update(Commitment &updateData,
                                      int currentTimeWindow) {
  util::TimeWindow currentWindow =
      updateData.getCommitmentWindows().at(currentTimeWindow);
  QDate dayOfTheWeek = QDate{currentWindow.startDate};
  x.clear();
  if (updateData.getType() == udata::CommitmentType::WEEKLY) {
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

  for (int i = 0; i < currentWindow.sessions.length(); i++) {
    qDebug() << "productive time in minutes"
             << util::StatsUtility::toMinutes(
                    currentWindow.sessions[i].getProductiveTime());
    qDebug() << "unproducive time in minutes"
             << util::StatsUtility::toMinutes(
                    currentWindow.sessions[i].getUnproductiveTime());
    qDebug() << "session date diff-->"
             << currentWindow.startDate.daysTo(
                    currentWindow.sessions.at(i).getDate());
    qDebug() << "day in session=" << currentWindow.sessions[i].getDate().day();
    qDebug() << "day in start"
             << "date=" << currentWindow.startDate.day();
    productiveBarSet.replace(
        currentWindow.startDate.daysTo(currentWindow.sessions.at(i).getDate()),
        util::StatsUtility::toMinutes(
            currentWindow.sessions[i].getProductiveTime()));
    unproductiveBarSet.replace(
        currentWindow.startDate.daysTo(currentWindow.sessions.at(i).getDate()),
        util::StatsUtility::toMinutes(
            currentWindow.sessions[i].getUnproductiveTime()));
  }

  series.append(&productiveBarSet);
  series.append(&unproductiveBarSet);
  y.setRange(0, util::StatsUtility::toMinutes(updateData.getFrequency().goal));
  QString dateRange{updateData.getCommitmentWindows()
                        .at(currentTimeWindow)
                        .startDate.toString() +
                    "--" +
                    updateData.getCommitmentWindows()
                        .at(currentTimeWindow)
                        .endDate.toString()};
  // ugly hack; will remove as soon as I can
  // Add spaces to center the tiltle of chart(it's in HTML)
  int remainingChars = MAX_TITLE_CHARS - dateRange.length() - 9;
  for (int i = 0; i < (remainingChars) / 2; i += 6) {
    dateRange.append("&nbsp;");
  }
  for (int i = 0; i < (remainingChars) / (2); i += 6) {
    dateRange.insert(0, "&nbsp;");
  }

  chart.setTitle(dateRange);
  productiveTimeAverage =
      productiveBarSet.sum() / currentWindow.sessions.length();
  qDebug() << "productiveBarSet.sum()=" << productiveBarSet.sum();
  qDebug() << "currentWindow.sessions.length()"
           << currentWindow.sessions.length();
  for (int i = 0; i < productiveBarSet.count(); i++) {
    qDebug() << "for i=" << i << "productive valuee for bar"
             << productiveBarSet.at(i);
  }
  unproductiveTimeAverage =
      unproductiveBarSet.sum() / unproductiveBarSet.count();
  productiveRatio = productiveBarSet.sum() / productiveBarSet.sum() +
                    unproductiveBarSet.sum();
  unproductiveRatio = unproductiveBarSet.sum() / productiveBarSet.sum() +
                      unproductiveBarSet.sum();
  QString temp{};
  temp.append(QString::number(productiveTimeAverage));
  productiveTimeAvgLabel.setText(temp);
  chart.legend()->setAlignment(Qt::AlignBottom);
  view.setRenderHint(QPainter::Antialiasing);
}

int udata::CommitmentSnaphot::getWeekDayIndex(QDate dateWindowStart,
                                              QDate sessionDay) {
  //    sessionDay.
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

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QPushButton>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartGlobal>
#include <QtCharts/QChartView>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsGridLayout>
#include <QtWidgets/QGraphicsWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QWidget>

QT_CHARTS_USE_NAMESPACE

class TempChartQWidget : public QWidget {
    Q_OBJECT

public:
    explicit TempChartQWidget(QWidget *parent = nullptr);
    ~TempChartQWidget();
    void createSeries();
    void showLegendSpinbox();
    void hideLegendSpinbox();

public Q_SLOTS:
    void toggleAttached();
    void addBarset();
    void removeBarset();

    void setLegendAlignment();

    void toggleBold();
    void toggleItalic();
    void fontSizeChanged();

    void updateLegendLayout();

private:
    QChart m_chart;
    QBarSeries m_series;
    //    QBarSet barSet;
    QChartView m_chartView;
    QGridLayout m_mainLayout;
    QGridLayout m_buttonLayout;
    //    QGridLayout m_fontLayout; It looks like it works without using this field.

    QDoubleSpinBox m_fontSize;

    // For detached layout
    QGroupBox m_legendSettings{ "Detached legend" };
    QDoubleSpinBox m_legendPosX;
    QDoubleSpinBox m_legendPosY;
    QDoubleSpinBox m_legendWidth;
    QDoubleSpinBox m_legendHeight;
};

#endif // MAINWIDGET_H

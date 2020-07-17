#pragma once
#include <QWidget>
#include "CommonCharts.h"
#include <QChart>
#include <QChartView>
#include <QChart>
#include <QBarSeries>
#include <QAreaSeries>
#include <QValueAxis>
QT_CHARTS_USE_NAMESPACE
namespace Ui
{
	class HandleBarChart;
}

class  COMMONCHARTS_EXPORT HandleBarChart : public QWidget
{
	Q_OBJECT

public:
	HandleBarChart(QWidget *parent = Q_NULLPTR);
	~HandleBarChart();
	void SetXAxisRange(double min_value, double max_value);
	void SetYAxisRange(double min_value, double max_value);
	void UpdateCurve(QList<QPointF>points_up, QList<QPointF>points_mid, QList<QPointF>points_low);

private:
	Ui::HandleBarChart *ui;
	void SetDefaultProperty(); //设置默认属性

	QChartView*qchart_view;
	QChart* qchart; //QChart对象
	QLegend *legend; //图标标题


	QBarSeries*bar_series;

	QValueAxis *axisX; //x坐标轴
	QValueAxis *axisY; //y坐标轴
};

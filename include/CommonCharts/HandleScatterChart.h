#pragma once
#include <QWidget>
#include "CommonCharts.h"
#include <QChart>
#include <QChartView>
#include <QChart>
#include <QScatterSeries>
#include <QValueAxis>
QT_CHARTS_USE_NAMESPACE

namespace Ui
{
	class HandleScatterChart;
}

class  COMMONCHARTS_EXPORT HandleScatterChart : public QWidget
{
	Q_OBJECT

public:
	HandleScatterChart(QWidget *parent = Q_NULLPTR);
	~HandleScatterChart();
	void SetXAxisRange(double min_value, double max_value);
	void SetYAxisRange(double min_value, double max_value);
	void UpdateCurve(QList<QPointF>points_up, QList<QPointF>points_mid, QList<QPointF>points_low);

private:
	Ui::HandleScatterChart *ui;
	void SetDefaultProperty(); //设置默认属性

	QChartView*qchart_view;
	QChart* qchart; //QChart对象
	QLegend *legend; //图标标题

	//展示用三条散点对象
	QScatterSeries  *scatter_series_up;//折现对象
	QScatterSeries  *scatter_series_middle;//折现对象	
	QScatterSeries  *scatter_series_low;//折现对象	

	QValueAxis *axisX; //x坐标轴
	QValueAxis *axisY; //y坐标轴
};

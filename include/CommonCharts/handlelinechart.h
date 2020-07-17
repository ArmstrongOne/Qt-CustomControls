#pragma once
#include <QWidget>
#include "CommonCharts.h"
#include <QChart>
#include <QChartView>
#include <QChart>
#include <QSplineSeries>
#include <QAreaSeries>
#include <QValueAxis>
QT_CHARTS_USE_NAMESPACE



namespace Ui
{
	class HandleLineChart;
}

class  COMMONCHARTS_EXPORT HandleLineChart : public QWidget
{
	Q_OBJECT

public:
	HandleLineChart(QWidget *parent = Q_NULLPTR);
	~HandleLineChart();
	void SetXAxisRange(double min_value, double max_value);
	void SetYAxisRange(double min_value, double max_value);
	void UpdateCurve(QList<QPointF>points_up,QList<QPointF>points_mid,QList<QPointF>points_low);

private:
	Ui::HandleLineChart *ui;
	void SetDefaultProperty(); //设置默认属性

	QChartView*qchart_view;
	QChart* qchart; //QChart对象
	QLegend *legend; //图标标题


	//展示用三条折线对象
	QLineSeries *line_series_up;//折现对象
	QLineSeries *line_series_middle;//折现对象	
	QLineSeries *line_series_low;//折现对象	

	QAreaSeries *area_series_up;//区域对象
	QAreaSeries *area_series_middle;//区域对象
	QAreaSeries *area_series_low;//区域对象

	QValueAxis *axisX; //x坐标轴
	QValueAxis *axisY; //y坐标轴
};

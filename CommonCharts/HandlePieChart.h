#pragma once

#include <QWidget>
#include "CommonCharts.h"
#include <QChart>
#include <QChartView>
#include <QChart>
#include <QPieSeries>
#include <QAreaSeries>
#include <QValueAxis>
QT_CHARTS_USE_NAMESPACE

namespace Ui
{
	class HandlePieChart;
}

class  COMMONCHARTS_EXPORT HandlePieChart : public QWidget
{
	Q_OBJECT

public:
	HandlePieChart(QWidget *parent = Q_NULLPTR);
	~HandlePieChart();
	void SetXAxisRange(double min_value, double max_value);
	void SetYAxisRange(double min_value, double max_value);
	void UpdateCurve(QList<int>value_list);

private:
	Ui::HandlePieChart *ui;
	void SetDefaultProperty(); //设置默认属性

	QChartView*qchart_view;
	QChart* qchart; //QChart对象
	QLegend *legend; //图标标题


   //展示用三条折线对象
	QPieSeries *pie_series;//折现对象
};

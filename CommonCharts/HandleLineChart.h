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
	void SetDefaultProperty(); //����Ĭ������

	QChartView*qchart_view;
	QChart* qchart; //QChart����
	QLegend *legend; //ͼ�����


	//չʾ���������߶���
	QLineSeries *line_series_up;//���ֶ���
	QLineSeries *line_series_middle;//���ֶ���	
	QLineSeries *line_series_low;//���ֶ���	

	QAreaSeries *area_series_up;//�������
	QAreaSeries *area_series_middle;//�������
	QAreaSeries *area_series_low;//�������

	QValueAxis *axisX; //x������
	QValueAxis *axisY; //y������
};

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
	void SetDefaultProperty(); //����Ĭ������

	QChartView*qchart_view;
	QChart* qchart; //QChart����
	QLegend *legend; //ͼ�����

	//չʾ������ɢ�����
	QScatterSeries  *scatter_series_up;//���ֶ���
	QScatterSeries  *scatter_series_middle;//���ֶ���	
	QScatterSeries  *scatter_series_low;//���ֶ���	

	QValueAxis *axisX; //x������
	QValueAxis *axisY; //y������
};

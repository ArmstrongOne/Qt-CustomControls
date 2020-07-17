#include "HandleBarChart.h"
#include<QValueAxis>
#include <QBarSet>
#pragma execution_character_set("utf-8")
#include "ui_HandleBarChart.h"
HandleBarChart::HandleBarChart(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::HandleBarChart;
	ui->setupUi(this);
	qchart_view = ui->qchart_view;
	qchart = new QChart;
	legend = qchart->legend();

	axisX = new QValueAxis(this);
	axisY = new QValueAxis(this);

	//柱子对象
	bar_series = new QBarSeries(this);
	this->SetDefaultProperty();
}

HandleBarChart::~HandleBarChart()
{
	delete ui;
}

void HandleBarChart::SetXAxisRange(double min_value, double max_value)
{
	qchart->axisX()->setRange(min_value, max_value);
}

void HandleBarChart::SetYAxisRange(double min_value, double max_value)
{
	qchart->axisY()->setRange(min_value, max_value);
}

void HandleBarChart::UpdateCurve(QList<QPointF>points_up, QList<QPointF>points_mid, QList<QPointF>points_low)
{
	//   qchart->addSeries(area_series_up);
	//   qchart->addSeries(area_series_low);
	//qchart->addSeries(area_series_middle);
}

void HandleBarChart::SetDefaultProperty()
{
	QBarSet *set0 = new QBarSet("Jane");
	QBarSet *set1 = new QBarSet("John");
	QBarSet *set2 = new QBarSet("Axel");
	QBarSet *set3 = new QBarSet("Mary");
	QBarSet *set4 = new QBarSet("Samantha");

	*set0<<1<< 2 << 3 << 4 << 5 << 6;
	*set1<<5<< 0 << 0 << 4 << 0 << 7;
	*set2<< 3 << 5 << 8 << 13 << 8 << 5;
	*set3<< 5 << 6 << 7 << 3 << 4 << 5;
	*set4<< 9 << 7 << 5 << 3 << 1 << 2;

	bar_series->append(set0);
	bar_series->append(set1);
	bar_series->append(set2);
	bar_series->append(set3);
	bar_series->append(set4);

	qchart->addSeries(bar_series);

	qchart->createDefaultAxes();

	//qchart->createDefaultAxes();//不确定是否new了新坐标轴 要看一下源码再用

	qchart_view->setChart(qchart);
	qchart_view->setRubberBand(QChartView::NoRubberBand);
	qchart_view->setRenderHint(QPainter::Antialiasing);//抗锯齿渲染
	qchart_view->chart()->setTheme(QChart::ChartThemeBlueCerulean);

	bar_series->setUseOpenGL(true);//openGl 加速
	bar_series->setVisible(true);


	//先自定义设置下参数
	axisX->setRange(0, 10);
	axisX->setLabelFormat("%d");
	axisX->setTickCount(9);//设置大刻度
	axisX->setMinorTickCount(0); //设置小刻度线的数目(两个大刻度之间的小刻度数目)

	axisY->setRange(0, 20);
	axisY->setTickCount(9);//设置大刻度
	axisY->setMinorTickCount(0);
	axisY->setLabelFormat("%.1f");

	////将坐标轴加入画布
	//qchart->setAxisX(axisX, NULL);
	//qchart->setAxisY(axisY, NULL);

	////将曲线加入坐标轴
	//bar_series->attachAxis(axisX);
	//bar_series->attachAxis(axisY);

	qchart->legend()->hide();
	qchart->setMargins(QMargins(0, 0, 0, 0));

	//曲线颜色
	//line_series_up->setPen(QPen(QColor(220, 220, 200), 1, Qt::SolidLine));//设置画笔

	//画布颜色 设置风格后不需要设置
	//qchart->setBackgroundBrush(QColor(0, 0, 0, 150));

	//画布颜色
	//坐标轴字体以及颜色
	axisX->setLabelsColor(QColor(255, 255, 255));
	axisY->setLabelsColor(QColor(255, 255, 255));

	

	QFont font_x = axisX->labelsFont();
	QFont font_y = axisY->labelsFont();
	font_x.setFamily(QString::fromUtf8("微软雅黑"));
	font_y.setFamily(QString::fromUtf8("微软雅黑"));
	font_x.setPixelSize(12);
	font_y.setPixelSize(12);
	axisX->setLabelsFont(font_x);
	axisY->setLabelsFont(font_y);

	//标题
	qchart->setMargins(QMargins(20, 20, 20, 20));
	qchart->setTitle(QString::fromUtf8("柱状图"));
}

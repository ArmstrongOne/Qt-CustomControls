#include "HandleScatterChart.h"
#include<QValueAxis>
#include "ui_HandleScatterChart.h"
#pragma execution_character_set("utf-8")
HandleScatterChart::HandleScatterChart(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::HandleScatterChart;
	ui->setupUi(this);
	qchart_view = ui->qchart_view;
	qchart = new QChart;
	legend = qchart->legend();

	axisX = new QValueAxis(this);
	axisY = new QValueAxis(this);

	//折现对象
	scatter_series_up = new QScatterSeries;
	scatter_series_middle = new QScatterSeries;
	scatter_series_low = new QScatterSeries;

	this->SetDefaultProperty();
}

HandleScatterChart::~HandleScatterChart()
{
	delete ui;
}

void HandleScatterChart::SetXAxisRange(double min_value, double max_value)
{
	qchart->axisX()->setRange(min_value, max_value);
}

void HandleScatterChart::SetYAxisRange(double min_value, double max_value)
{
	qchart->axisY()->setRange(min_value, max_value);
}

void HandleScatterChart::UpdateCurve(QList<QPointF>points_up, QList<QPointF>points_mid, QList<QPointF>points_low)
{
	scatter_series_up->clear();
	scatter_series_up->append(points_up);
	scatter_series_middle->clear();
	scatter_series_middle->append(points_mid);
	scatter_series_low->clear();
	scatter_series_low->append(points_low);
}

void HandleScatterChart::SetDefaultProperty()
{
	qchart->addSeries(scatter_series_up);
	qchart->addSeries(scatter_series_middle);
	qchart->addSeries(scatter_series_low);

	//qchart->createDefaultAxes();//不确定是否new了新坐标轴 要看一下源码再用

	qchart_view->setChart(qchart);
	qchart_view->setRubberBand(QChartView::NoRubberBand);
	qchart_view->setRenderHint(QPainter::Antialiasing);//抗锯齿渲染
	qchart_view->chart()->setTheme(QChart::ChartThemeBlueCerulean);

	scatter_series_up->setUseOpenGL(true);//openGl 加速
	scatter_series_up->setVisible(true);
	scatter_series_middle->setUseOpenGL(true);//openGl 加速
	scatter_series_middle->setVisible(true);
	scatter_series_low->setUseOpenGL(true);//openGl 加速
	scatter_series_low->setVisible(true);


	//先自定义设置下参数
	axisX->setRange(0, 10);
	axisX->setLabelFormat("%d");
	axisX->setTickCount(9);//设置大刻度
	axisX->setMinorTickCount(0); //设置小刻度线的数目(两个大刻度之间的小刻度数目)

	axisY->setRange(0, 20);
	axisY->setTickCount(9);//设置大刻度
	axisY->setMinorTickCount(0);
	axisY->setLabelFormat("%.1f");

	//将坐标轴加入画布
	qchart->setAxisX(axisX, NULL);
	qchart->setAxisY(axisY, NULL);

	//将曲线加入坐标轴
	scatter_series_up->attachAxis(axisX);
	scatter_series_up->attachAxis(axisY);
	scatter_series_middle->attachAxis(axisX);
	scatter_series_middle->attachAxis(axisY);
	scatter_series_low->attachAxis(axisX);
	scatter_series_low->attachAxis(axisY);


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

	//设置散点属性

	scatter_series_up->setMarkerShape(QScatterSeries::MarkerShapeCircle);//圆形的点
	scatter_series_up->setBorderColor(QColor(255, 255, 255));  //边框颜色
	scatter_series_up->setBrush(QBrush(QColor(92, 191, 155)));//背景颜色
	scatter_series_up->setMarkerSize(10);

	scatter_series_middle->setMarkerShape(QScatterSeries::MarkerShapeCircle);//圆形的点
	scatter_series_middle->setBorderColor(QColor(255, 255, 255));  //边框颜色
	scatter_series_middle->setBrush(QColor(28, 181, 79));//背景颜色
	scatter_series_middle->setMarkerSize(10);

	scatter_series_low->setMarkerShape(QScatterSeries::MarkerShapeCircle);//圆形的点
	scatter_series_low->setBorderColor(QColor(255, 255, 255));  //边框颜色
	scatter_series_low->setBrush(QBrush(QColor(199, 231, 91)));//背景颜色
	scatter_series_low->setMarkerSize(10);

	//标题
	qchart->setMargins(QMargins(20, 20, 20, 20));
	qchart->setTitle(QString::fromUtf8("散点图"));
}

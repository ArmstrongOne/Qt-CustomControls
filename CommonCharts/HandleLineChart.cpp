#include "HandleLineChart.h"
#include<QValueAxis>
#include "ui_HandleLineChart.h"
#pragma execution_character_set("utf-8")
HandleLineChart::HandleLineChart(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::HandleLineChart;
	ui->setupUi(this);
	qchart_view = ui->qchart_view;
	qchart = new QChart;
	legend = qchart->legend();

	axisX = new QValueAxis(this);
	axisY = new QValueAxis(this);

	//折现对象
	line_series_up = new QLineSeries;
	line_series_middle = new QLineSeries;
	line_series_low = new QLineSeries;

	//折现区域对象
	area_series_up = new QAreaSeries(line_series_up, line_series_middle);
	area_series_middle = new QAreaSeries(line_series_middle, line_series_low);
	area_series_low = new QAreaSeries(line_series_low, nullptr);

	this->SetDefaultProperty();
}

HandleLineChart::~HandleLineChart()
{
	delete ui;
}

void HandleLineChart::SetXAxisRange(double min_value, double max_value)
{
	qchart->axisX()->setRange(min_value, max_value);
}

void HandleLineChart::SetYAxisRange(double min_value, double max_value)
{
	qchart->axisY()->setRange(min_value, max_value);
}

void HandleLineChart::UpdateCurve(QList<QPointF>points_up, QList<QPointF>points_mid, QList<QPointF>points_low)
{
	line_series_up->clear();
	line_series_up->append(points_up);
	line_series_middle->clear();
	line_series_middle->append(points_mid);
	line_series_low->clear();
	line_series_low->append(points_low);


 //   qchart->addSeries(area_series_up);
 //   qchart->addSeries(area_series_low);
	//qchart->addSeries(area_series_middle);
}

void HandleLineChart::SetDefaultProperty()
{
	qchart->addSeries(line_series_up);
	qchart->addSeries(line_series_middle);
	qchart->addSeries(line_series_low);
	
	qchart->addSeries(area_series_up);
	qchart->addSeries(area_series_low);
	qchart->addSeries(area_series_middle);

	//qchart->createDefaultAxes();//不确定是否new了新坐标轴 要看一下源码再用
	
	qchart_view->setChart(qchart);
	qchart_view->setRubberBand(QChartView::NoRubberBand);
	qchart_view->setRenderHint(QPainter::Antialiasing);//抗锯齿渲染
	qchart_view->chart()->setTheme(QChart::ChartThemeBlueCerulean);

	line_series_up->setUseOpenGL(true);//openGl 加速
	line_series_up->setVisible(true);
	line_series_middle->setUseOpenGL(true);//openGl 加速
	line_series_middle->setVisible(true);
	line_series_low->setUseOpenGL(true);//openGl 加速
	line_series_low->setVisible(true);

	
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
	line_series_up->attachAxis(axisX);
	line_series_up->attachAxis(axisY);
	line_series_middle->attachAxis(axisX);
	line_series_middle->attachAxis(axisY);
	line_series_low->attachAxis(axisX);
	line_series_low->attachAxis(axisY);

	area_series_up->attachAxis(axisX);
	area_series_up->attachAxis(axisY);
	area_series_middle->attachAxis(axisX);
	area_series_middle->attachAxis(axisY);
	area_series_low->attachAxis(axisX);
	area_series_low->attachAxis(axisY);


	qchart->legend()->hide();
	qchart->setMargins(QMargins(0, 0, 0, 0));

	//曲线颜色
	//line_series_up->setPen(QPen(QColor(220, 220, 200), 1, Qt::SolidLine));//设置画笔

	//折现区域颜色
	area_series_up->setName("area");
	QBrush brush_up(QColor(92, 191, 155));
	area_series_up->setBrush(brush_up);

	area_series_middle->setName("area");
	QBrush brush_middle(QColor(28, 181, 79));
	area_series_middle->setBrush(brush_middle);

	area_series_low->setName("area");
	QBrush brush_low(QColor(199, 231, 91));
	area_series_low->setBrush(brush_low);

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
    qchart->setMargins(QMargins(20,20,20,20));
	qchart->setTitle(QString::fromUtf8("折线图"));
}

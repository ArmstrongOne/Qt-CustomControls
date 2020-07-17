#include "HandlePieChart.h"
#include<QValueAxis>
#include <QPieSlice>
#include "ui_HandlePieChart.h"
#pragma execution_character_set("utf-8")
HandlePieChart::HandlePieChart(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::HandlePieChart;
	ui->setupUi(this);
	qchart_view = ui->qchart_view;
	qchart = new QChart;
	legend = qchart->legend();

	pie_series = new QPieSeries(this);
	this->SetDefaultProperty();
}

HandlePieChart::~HandlePieChart()
{
	delete ui;
}

void HandlePieChart::SetXAxisRange(double min_value, double max_value)
{
	qchart->axisX()->setRange(min_value, max_value);
}

void HandlePieChart::SetYAxisRange(double min_value, double max_value)
{
	qchart->axisY()->setRange(min_value, max_value);
}

void HandlePieChart::UpdateCurve(QList<int>value_list)
{
	pie_series->append(QString::fromUtf8("顾逸凡 10%"), 1);
	pie_series->append(QString::fromUtf8("波尔 56.4%"), 3);
	pie_series->append(QString::fromUtf8("来须苍真 23.8%"), 6);

	//用QPieSlice改变对用块的颜色
	QPieSlice *slice_red = pie_series->slices().at(0);
	QPieSlice *slice_green = pie_series->slices().at(1);
	QPieSlice *slice_blue = pie_series->slices().at(2);
	slice_red->setColor(QColor(151, 176, 69, 255));
	slice_green->setColor(QColor(218, 240, 146, 255));
	slice_blue->setColor(QColor(55, 64, 25, 255));
}

void HandlePieChart::SetDefaultProperty()
{
	qchart->addSeries(pie_series);
	pie_series->setHoleSize(0.35);//设置空心

	qchart_view->setChart(qchart);
	qchart_view->setRubberBand(QChartView::NoRubberBand);
	qchart_view->setRenderHint(QPainter::Antialiasing);//抗锯齿渲染
	qchart_view->chart()->setTheme(QChart::ChartThemeBlueCerulean);

	pie_series->setUseOpenGL(true);//openGl 加速
	pie_series->setVisible(true);

	legend = qchart->legend();
	legend->setAlignment(Qt::AlignBottom);
	legend->setFont(QFont("Arial", 8));

	qchart->setMargins(QMargins(0, 0, 0, 0));

	//曲线颜色
	//line_series_up->setPen(QPen(QColor(220, 220, 200), 1, Qt::SolidLine));//设置画笔

	//画布颜色 设置风格后不需要设置
	//qchart->setBackgroundBrush(QColor(0, 0, 0, 150));

	//画布颜色
	//坐标轴字体以及颜色

	//标题
	qchart->setMargins(QMargins(20, 20, 20, 20));
	qchart->setTitle(QString::fromUtf8("饼图"));
}

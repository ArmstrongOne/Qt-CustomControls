#include "RectWaveProgressBar.h"
#include "ui_RectWaveProgressBar.h"
#include<QPainter>
#include <QPainterPath>
#include <math.h>
#include <QDebug>
RectWaveProgressBar::RectWaveProgressBar(QWidget *parent):QWidget(parent)
{

	ui = new Ui::RectWaveProgressBar;
	ui->setupUi(this);

	text_label = ui->text_lab;

	//初始化变量
	out_rect.setWidth(0);
	out_rect.setHeight(0);
	out_rect.setX(0);
	out_rect.setY(0);

	in_rect.setWidth(0);
	in_rect.setHeight(0);
	in_rect.setX(0);
	in_rect.setY(0);


	margin_left = 0;
	margin_right = 0;
	margin_top = 0;
	margin_bottom = 0;

	border_width = 0;
	cur_value = 0;

	m_waterDensity = 0;
	m_waterHeight = 0;
	m_init_offset = 0;
	m_offset = 0;
}

RectWaveProgressBar::~RectWaveProgressBar()
{
	delete ui;
}

void RectWaveProgressBar::SetPanColor(QColor background_color, QColor border_color)
{
	this->background_color = background_color;
	this->border_color = border_color;
}


void RectWaveProgressBar::SetMargin(int left_margin, int right_margin, int top_margin, int bottom_margin)
{
	this->margin_left = left_margin;
	this->margin_right = right_margin;
	this->margin_top = top_margin;
	this->margin_bottom = bottom_margin;

}

void RectWaveProgressBar::SetWaveColor(QColor front_wave_color, QColor behind_wave_color)
{
	this->front_wave_color = front_wave_color;
	this->behind_wave_color = behind_wave_color;
}

void RectWaveProgressBar::SetBorderWidth(int value)
{
	border_width = value;
}

void RectWaveProgressBar::SetWaveProperty(int density, double m_waterHeight, double offset)
{
	this->m_waterDensity = density;
	this->m_waterHeight = m_waterHeight;
	this->m_offset = offset;
}

void RectWaveProgressBar::Update()
{
	QPalette pa;
	pa.setColor(QPalette::WindowText, label_font_color);
	pa.setColor(QPalette::Window, label_back_color);

	text_label->setAutoFillBackground(true);
	text_label->setPalette(pa);
	text_label->setFont(label_font);

	text_label->setText("0%");
	text_label->show();
}

void RectWaveProgressBar::SetPanValue(int value)
{
	this->cur_value = value;
	text_label->setText(QString::number(value) + "%");
}

void RectWaveProgressBar::SetPanLabelColor(QColor font_color, QColor back_color)
{
	this->label_font_color = font_color;
	this->label_back_color = back_color;
}

void RectWaveProgressBar::SetPanLabelFont(QFont font)
{
	this->label_font = font;
}

void RectWaveProgressBar::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;

	int height = in_rect.height();
	int width = in_rect.width();

	//计算当前值所占百分比 percent实际上是水波上区域的百分比
	double percent = 1 - (double)(cur_value - 0)/(100-0);

	//正弦曲线公式 y = A * sin(ωx + φ) + k
	//w表示周期,可以理解为水波的密度,值越大密度越大(浪越密集 ^_^),取值 密度*M_PI/宽度
	double w = m_waterDensity * M_PI/width;
	//A表示振幅,可以理解为水波的高度,值越大高度越高(越浪 ^_^),取值高度的百分比
	double A = height*m_waterHeight;
	//k表示y轴偏移,可以理解为进度,取值高度的进度百分比
	double k = height*percent+ in_rect.y();

	//第一条波浪路径集合
	QPainterPath waterPath1;
	//第二条波浪路径集合
	QPainterPath waterPath2;

	//移动到左上角起始点
	waterPath1.moveTo(in_rect.x(), in_rect.y());
	waterPath2.moveTo(in_rect.x(), in_rect.y());

	m_init_offset += m_offset;
	if (m_init_offset > (in_rect.width()/2)) {
		m_init_offset = 0;
	}

	for (int x = in_rect.x(); x <= in_rect.x() + in_rect.width(); x++) {
		//第一条波浪Y轴
		double waterY1 = (double)(A*sin(w*x+m_init_offset))+k;

		//第二条波浪Y轴
		double waterY2 = (double)(A*sin(w*x+m_init_offset+M_PI))+k;

		//如果当前值为最小值则Y轴为高度
		if (cur_value == 0)
		{
			waterY1 = in_rect.y() + in_rect.height();
			waterY2 = in_rect.y() + in_rect.height();
		}

		//如果当前值为最大值则Y轴为0
		if (cur_value == 100)
		{
			waterY1 = in_rect.y();
			waterY2 = in_rect.y();
		}
		waterPath1.lineTo(x, waterY1);
		waterPath2.lineTo(x, waterY2);
	}

	//移动到右下角结束点,整体形成一个闭合路径
	waterPath1.lineTo(in_rect.x() + in_rect.width(), in_rect.y() + in_rect.height());
	waterPath2.lineTo(in_rect.x() + in_rect.width(), in_rect.y() + in_rect.height());

	//再移动到左下角
	waterPath1.lineTo(in_rect.x(), in_rect.y() + in_rect.height());
	waterPath2.lineTo(in_rect.x(), in_rect.y() + in_rect.height());

	//画外部矩形
	painter.setBrush(border_color);
	painter.drawRect(out_rect);
	//画内部矩形
	painter.setBrush(background_color);
	painter.drawRect(in_rect);

	//大路径
	QPainterPath big_path;
	big_path.addRect(in_rect);
	painter.save();

	QColor waterColor1 = front_wave_color;
	QColor waterColor2 = behind_wave_color;

	//新路径
	QPainterPath path;
	//第一条波浪挖去后的路径
	painter.setBrush(waterColor1);
	path = big_path.intersected(waterPath1);
	painter.drawPath(path);

	//第二条波浪挖去后的路径
	painter.setBrush(waterColor2);
	path = big_path.intersected(waterPath2);
	painter.drawPath(path);

	painter.restore();
	this->update();
}

void RectWaveProgressBar::resizeEvent(QResizeEvent* size)
{
	//确定控件长和宽
	int width = this->width();
	int height = this->height();

	//外界矩形
	out_rect.setWidth(width-margin_left-margin_right);
	out_rect.setHeight(height-margin_top-margin_bottom);
	out_rect.setX(0 + margin_left);
	out_rect.setY(0 + margin_top);

	//内接矩形(外界矩形和 border_width操控)
	in_rect.setX(out_rect.x()+border_width);
	in_rect.setY(out_rect.y() + border_width);
	in_rect.setWidth(out_rect.width()-2*border_width);
	in_rect.setHeight(out_rect.height() - 2 * border_width);

	//定label位置
	text_label->move(in_rect.width()/2-text_label->width()/2+ in_rect.x(), in_rect.height()/2-text_label->height()/2+ in_rect.y());
}


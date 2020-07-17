#include "WaveProgressBar.h"
#include "ui_WaveProgressBar.h"
#include<QPainter>
#include <math.h>
WaveProgressBar::WaveProgressBar(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::WaveProgressBar;
	ui->setupUi(this);

	text_label = ui->text_lab;


	//初始化变量
	m_width_out_cir = 0;
	m_height_out_cir = 0;
	m_radius_out_cir = 0;

	m_width_in_cir= 0;
	m_height_in_cir = 0;
	m_radius_in_cir = 0;

	border_width = 0;
	cur_value=0;

	m_waterDensity = 0;
	m_waterHeight = 0;
	m_init_offset = 0;
	m_offset = 0;
}

WaveProgressBar::~WaveProgressBar()
{
	delete ui;

}

void WaveProgressBar::SetPanColor(QColor background_color, QColor border_color)
{
	this->background_color = background_color;
	this->border_color = border_color;
}


void WaveProgressBar::SetWaveColor(QColor front_wave_color, QColor behind_wave_color)
{
	this->front_wave_color = front_wave_color;
	this->behind_wave_color = behind_wave_color;
}

void WaveProgressBar::SetBorderWidth(int value)
{
	border_width = value;
}

void WaveProgressBar::SetWaveProperty(int density, double m_waterHeight, double offset)
{
	this->m_waterDensity = density;
	this->m_waterHeight = m_waterHeight;
	this->m_offset = offset;
}

void WaveProgressBar::Update()
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

void WaveProgressBar::SetPanValue(int value)
{
	this->cur_value = value;
	text_label->setText(QString::number(value) + "%");
}

void WaveProgressBar::SetPanLabelColor(QColor font_color, QColor back_color)
{
	this->label_font_color = font_color;
	this->label_back_color = back_color;
}

void WaveProgressBar::SetPanLabelFont(QFont font)
{
	this->label_font = font;
}

void WaveProgressBar::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
	
	int height = m_height_in_cir+ in_cir_rect.y();
	int width = m_width_in_cir + in_cir_rect.x();

	//计算当前值所占百分比 percent实际上是水波上区域的百分比
	double percent=1-(double)(cur_value-0)/(100-0);

	//正弦曲线公式 y = A * sin(ωx + φ) + k
	//w表示周期,可以理解为水波的密度,值越大密度越大(浪越密集 ^_^),取值 密度*M_PI/宽度
	double w = m_waterDensity * M_PI / width;
	//A表示振幅,可以理解为水波的高度,值越大高度越高(越浪 ^_^),取值高度的百分比
	double A = height*m_waterHeight;
	//k表示y轴偏移,可以理解为进度,取值高度的进度百分比
	double k = height*percent;

	//第一条波浪路径集合
	QPainterPath waterPath1;
	//第二条波浪路径集合
	QPainterPath waterPath2;

	//移动到左上角起始点
	waterPath1.moveTo(in_cir_rect.x(), in_cir_rect.y()+ in_cir_rect.height());
	waterPath2.moveTo(in_cir_rect.x(), in_cir_rect.y() + in_cir_rect.height());

	m_init_offset+= m_offset;
	if (m_init_offset > (m_width_in_cir / 2)) {
		m_init_offset = 0;
	}

	for (int x = in_cir_rect.x(); x <= in_cir_rect.x()+m_width_in_cir; x++) {
		//第一条波浪Y轴
		double waterY1 = (double)(A * sin(w * x+m_init_offset)) + k;

		//第二条波浪Y轴
		double waterY2 = (double)(A * sin(w*x+m_init_offset + M_PI)) + k;

		//如果当前值为最小值则Y轴为高度
		if (cur_value == 0) 
		{
			waterY1 = in_cir_rect.y() + in_cir_rect.height();
			waterY2 = in_cir_rect.y() + in_cir_rect.height();
		}

		//如果当前值为最大值则Y轴为0
		if (cur_value == 100) 
		{
			waterY1= in_cir_rect.y();
			waterY2= in_cir_rect.y();
		}
		waterPath1.lineTo(x, waterY1);
		waterPath2.lineTo(x, waterY2);
	}

	//移动到右下角结束点,整体形成一个闭合路径
	waterPath1.lineTo(in_cir_rect.x()+in_cir_rect.width(), in_cir_rect.y()+ in_cir_rect.height());
	waterPath2.lineTo(in_cir_rect.x() + in_cir_rect.width(), in_cir_rect.y() + in_cir_rect.height());

	//大路径
	QPainterPath bigPath;
	//画外部圆
	painter.setBrush(border_color);
	painter.drawEllipse(0, 0, m_width_out_cir, m_height_out_cir);
	//画内部圆
	painter.setBrush(background_color);
	painter.drawEllipse(in_cir_rect);
	//将内部圆加入到大路径中
	bigPath.addEllipse(in_cir_rect);
	painter.save();

	//painter.setPen(QColor(11,21,0));
	//painter.setBrush(QColor(212, 11, 100));
	//painter.drawPath(waterPath1);
	
	//新路径,用大路径减去波浪区域的路径,形成遮罩效果
	QPainterPath path;
	QColor waterColor1 = front_wave_color;
	QColor waterColor2 = behind_wave_color;

	//第一条波浪挖去后的路径
	path = bigPath.intersected(waterPath1);
	painter.setBrush(waterColor1);
	painter.drawPath(path);

	//第二条波浪挖去后的路径
	path = bigPath.intersected(waterPath2);
	painter.setBrush(waterColor2);
	painter.drawPath(path);

	painter.restore();
	this->update();
}

void WaveProgressBar::resizeEvent(QResizeEvent* size)
{
	this->m_width_out_cir = this->width();
	this->m_height_out_cir = this->height();
	//由于圆形的特殊直径数值必须为偶数
	if (this->m_width_out_cir % 2 != 0)
	{
		m_width_out_cir--;
	}
	if (this->m_height_out_cir % 2 != 0)
	{
		m_height_out_cir--;
	}

	//长宽不一致用最小的边
	if (this->m_width_out_cir < this->m_height_out_cir)
	{
		this->m_height_out_cir = this->m_width_out_cir;
	}
	else if (this->m_width_out_cir > this->m_height_out_cir)
	{
		this->m_width_out_cir = this->m_height_out_cir;
	}

	m_radius_out_cir = (this->m_width_out_cir + this->m_height_out_cir) / 2;

	
	//长宽优化过 确定lab的位置
	text_label->move(m_width_out_cir / 2 - text_label->width() / 2, m_height_out_cir / 2 - text_label->height() / 2);

	//确定内部圆的参数
	m_width_in_cir = m_width_out_cir - 2 * border_width;
	m_height_in_cir = m_height_out_cir - 2 * border_width;
	m_radius_in_cir = m_radius_out_cir-border_width;

	in_cir_rect.setX(m_radius_out_cir- m_radius_in_cir);
	in_cir_rect.setY(m_radius_out_cir - m_radius_in_cir);
	in_cir_rect.setWidth(m_width_in_cir);
	in_cir_rect.setHeight(m_height_in_cir);
}


#include "DashBoard.h"
#include<QPainter>
#include "ui_DashBoard.h"
#include <QLabel>
DashBoard::DashBoard(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::DashBoard;
	ui->setupUi(this);

	text_label = ui->text_lab;
	cur_value = 0;
}

DashBoard::~DashBoard()
{
	delete ui;
}

void DashBoard::SetPanColor(QColor unselected_color, QColor selected_color)
{
	this->unselected_color = unselected_color;
	this->selected_color = selected_color;
}

void DashBoard::Update()
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

void DashBoard::SetPanValue(int value)
{
	this->cur_value = value;

	text_label->setText(QString::number(value) + "%");
}

void DashBoard::SetPanLabelColor(QColor font_color, QColor back_color)
{
	this->label_font_color = font_color;
	this->label_back_color = back_color;
}

void DashBoard::SetPanLabelFont(QFont font)
{
	this->label_font = font;
}

void DashBoard::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	//设置透明笔
	painter.setPen(QColor(1, 1, 1, 0));

	//画背景
	painter.setBrush(unselected_color);
	painter.drawEllipse(0, 0,m_radius,m_radius);

	//画扫过的扇形图
	painter.setBrush(selected_color);
	
	//单位是1/16度  一圈是5760(某未知单位)  //饼图三点钟方位角度为0 1440则逆时针转90度 到12点钟方位
	int startAngle =1440;
	// 扇形覆盖范围（120度的）
	int spanAngle = (double)cur_value/100*5760;  //旋转角也是朝逆时针增长的
	//矩形区域 因为长和宽被优化过了 需要重新设置
	QRect rect(0, 0, m_width, m_height);
	painter.drawPie(rect, startAngle, spanAngle);
	this->update();
}

void DashBoard::resizeEvent(QResizeEvent* size)
{
	this->m_width = this->width();
	this->m_height = this->height();
	//由于圆形的特殊直径数值必须为偶数
	if (this->m_width % 2 != 0)
	{
		m_width--;
	}
	if (this->m_height % 2 != 0)
	{
		m_height--;
	}

	//长宽不一致用最小的边
	if (this->m_width<this->m_height)
	{
		this->m_height = this->m_width;
	}
	else if (this->m_width>this->m_height)
	{
		this->m_width = this->m_height;
	}

	m_radius= (this->m_width+ this->m_height)/2;

	//长宽优化过 确定lab的位置
	text_label->move(m_width/2-text_label->width()/2, m_height/2-text_label->height()/2);
}

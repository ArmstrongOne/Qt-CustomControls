#include "DashBoard.h"
#include<QPainter>
DashBoard::DashBoard(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	text_label = ui.text_lab;
	cur_value = 0;
}

DashBoard::~DashBoard()
{


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
	
	//单位是1/16度  一圈是5760(某未知单位)
	int startAngle = 1440;
	// 扇形覆盖范围（120度的）
	int spanAngle = (double)cur_value/100*5760;
	painter.drawPie(this->rect(), startAngle, spanAngle);
	this->update();
}

void DashBoard::resizeEvent(QResizeEvent* size)
{
	this->m_width = this->width();
	this->m_height = this->height();
	m_radius= (this->width()+ this->height())/2;
}

#include "CustomSlider.h"
#include<QPainter>
#include <QDebug>
#include <QPalette>
#include<QMouseEvent>
#include<math.h>
CustomSlider::CustomSlider(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_hander = ui.slider_wid;
	m_hander->installEventFilter(this);


	this->hander_lab = ui.hander_lab;
	hander_lab->hide();
}

CustomSlider::~CustomSlider()
{

}

void CustomSlider::SetSliveWidth(int value)
{
	//如果设置的杆子宽度超过整个滑动条宽度，默认为2;
	//if (value >= this->m_width) 
	//{
	//	value = 2;
	//}
	this->slive_width = value;
}

void CustomSlider::SetBackgrondColor(QColor slive_color, QColor slider_color, QColor slive_color_bottom)
{
	this->slive_color = slive_color;
	this->slider_color = slider_color;
	this->slive_color_bottom = slive_color_bottom;
}

void CustomSlider::SetTopAndBottomBlank(int top_value, int bottom_value)
{
	//如果滑动条杆子到上下边的距离超过整个滑动条高度，默认为5;
	//if (top_value>= this->height()||bottom_value>=this->height())
	//{
	//	top_value = 5;
	//	bottom_value = 5;
	//}
	
	this->top_value = top_value;
	this->bottom_value = bottom_value;
}

void CustomSlider::SetSliderWidgetWidthAndHeight(int width, int height)
{
	this->wid_width = width;
	this->wid_height = height;
	m_hander->setGeometry(0, 0, wid_width, wid_height);
	m_hander->show();
}

void CustomSlider::SetHanderColor(QColor hander_color)
{
	QPalette palette;
	palette.setColor(QPalette::Background, hander_color);
	m_hander->setPalette(palette);
	m_hander->setAutoFillBackground(true);//必须要这句话
}

void CustomSlider::SetSliderRange(int min_value, int max_value)
{
	if (min_value>=max_value)
	{
		this->min_value = 0;
		this->max_value = 100;
	}

	this->min_value = min_value;
	this->max_value = max_value;
}

void CustomSlider::SetHanderLabelEnable(bool flag)
{
	if (flag)
	{
		hander_lab->show();
	}
	else
	{
		hander_lab->hide();
	}
}

void CustomSlider::SetHanderLabelColor(QColor font_color, QColor back_color)
{
	this->label_font_color = font_color;

	this->label_back_color = back_color;
}

void CustomSlider::SetHanderLabelFont(QFont font)
{
	this->label_font = font;
}

void CustomSlider::Update()
{
	//固定下来的x轴
	hander_x_axis = (m_width - wid_width)/2;
	//y轴移动的总距离
	hander_y_dis = m_height-top_value-bottom_value;
	//y轴的步长
	haner_y_step = (double)hander_y_dis/(max_value - min_value);

	//label设置
	QPalette pa;
	pa.setColor(QPalette::WindowText, label_font_color);
	pa.setColor(QPalette::Window, label_back_color);

	hander_lab->setAutoFillBackground(true);
	hander_lab->setPalette(pa);

	hander_lab->setFont(label_font);

	m_hander->show();
	SetSliderValue(min_value);
}

void CustomSlider::SetSliderValue(int value)
{
	if (value<min_value&&value >max_value)
	{
		cur_value=0;
		MoveSlider(cur_value);
		emit ValueChange(cur_value);
	}

	cur_value = value;
	MoveSlider(cur_value);
	emit ValueChange(cur_value);
}

void CustomSlider::resizeEvent(QResizeEvent* size)
{
	this->m_width = this->width();
	this->m_height = this->height();

	this->Update();
}

void CustomSlider::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	//设置透明笔
	painter.setPen(QColor(1,1,1,0));
	
	//画背景
	painter.setBrush(slider_color);
	painter.drawRoundedRect(0,0, m_width, m_height,8,8);

	//画杆子
	painter.setBrush(slive_color);
	//计算下杆子的坐标以及长宽
	int slive_x = (m_width - slive_width)/2;
	int slive_y = top_value;
	int slive_width_new = this->slive_width;
	int slive_height=this->height()-top_value-bottom_value;
	painter.drawRoundedRect(slive_x, slive_y, slive_width_new, slive_height,8,8);

	//覆盖一层滑动条划过的颜色的杆子
	painter.setBrush(slive_color_bottom);
	painter.drawRoundedRect(slive_x, m_hander->y(), slive_width_new, this->height()-bottom_value- m_hander->y(),8,8);

}

void CustomSlider::MoveSlider(int value)
{
	//当前value值对应的y值
	int cur_y =top_value+(value-min_value)*haner_y_step -wid_height/2;
	m_hander->move(hander_x_axis, cur_y);
	hander_lab->setText(QString::number(value));
}

bool CustomSlider::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == m_hander&&event->type() == QEvent::MouseButtonPress)
	{
		cur_state = Checked_State;
	}
	else if (obj == NULL&&event->type() == QEvent::MouseButtonPress)
	{
		cur_state = UnCheck_State;
	}
	if (obj == m_hander&&event->type() == QEvent::MouseButtonRelease)
	{
		cur_state = UnCheck_State;
	}
	else if (obj == NULL&&event->type() == QEvent::MouseButtonRelease)
	{
		cur_state = UnCheck_State;
	}
	return QWidget::eventFilter(obj, event);
}

void CustomSlider::leaveEvent(QEvent* event)
{
	QWidget::leaveEvent(event);
	cur_state = UnCheck_State;
	update();
}

void CustomSlider::mouseMoveEvent(QMouseEvent* event)
{
	if (event->buttons()&Qt::LeftButton)
	{
		switch (cur_state)
		{
		case Checked_State:
		{
			float move = (event->y()-top_value)/haner_y_step;
			if (move < min_value|| move >=max_value)
			{
				//"超过最小值或者比最大值大了";
				return;
			}
			cur_value = round(move);
			m_hander->move(hander_x_axis,event->y()-wid_height/2);

			hander_lab->setText(QString::number(cur_value));

			emit ValueChange(cur_value);
			break;
		}
		}
	}
	update();
}

#include "TipSlider.h"
#include "ui_TipSlider.h"
#include<QPainter>
#include <QDebug>
#include <QPalette>
#include<QMouseEvent>
#include<math.h>
TipSlider::TipSlider(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::TipSlider;
	ui->setupUi(this);

	this->hander_lab = ui->hander_lab;
	this->hander_lab->installEventFilter(this);

	this->tip_lab = ui->tip_lab;

	//初始化
	slive_width = 0;
	top_value = 0;
	bottom_value = 0;
	round_value_x = 0;
	round_value_y = 0;
	wid_width = 0;
	wid_height = 0;
	min_value = 0;
	max_value = 0;
	cur_value = 0;
	hander_x_axis = 0;
	hander_y_dis = 0;
	haner_y_step = 0;
	tip_wid_width = 0;
	tip_wid_height = 0;
	tip_wid_pole_width = 0;
	tip_wid_pole_height = 0;
	tip_wid_x = 0;
}

TipSlider::~TipSlider()
{
	delete ui;
}

void TipSlider::SetSliveWidth(int value)
{
	this->slive_width = value;
}

void TipSlider::SetBackgrondColor(QColor slive_color, QColor slider_color, QColor slive_color_bottom)
{
	this->slive_color = slive_color;
	this->slider_color = slider_color;
	this->slive_color_bottom = slive_color_bottom;
}

void TipSlider::SetTopAndBottomBlank(int top_value, int bottom_value)
{
	this->top_value = top_value;
	this->bottom_value = bottom_value;
}

void TipSlider::SetSliderWidgetWidthAndHeight(int width, int height)
{
	this->wid_width = width;
	this->wid_height = height;
}

void TipSlider::SetSliderRange(int min_value, int max_value)
{
	if (min_value >= max_value)
	{
		this->min_value = 0;
		this->max_value = 100;
	}

	this->min_value = min_value;
	this->max_value = max_value;
}

void TipSlider::SetSliveRoundValue(int x_value, int y_value)
{
	this->round_value_x = x_value;
	this->round_value_y = y_value;
}


void TipSlider::SetHanderLabelProperty(QFont font, QColor font_color, QColor back_color)
{
	hander_lab->SetBackgroundColor(back_color);
	hander_lab->SetLabelFontAndColor(font, font_color);
}


void TipSlider::SetHanderLabelRoundValue(int border_x_value, int border_y_value)
{
	hander_lab->SetRoundValue(border_x_value, border_y_value);
}

void TipSlider::SetTipLabelWidthAndHeight(int tip_label_width, int tip_label_height)
{
	this->tip_wid_width = tip_label_width;
	this->tip_wid_height = tip_label_height;
}

void TipSlider::SetTipLabelRoundValue(int x_value, int y_value)
{
	tip_lab->SetRoundValue(x_value, y_value);
}

void TipSlider::SetTipLabelProperty(QFont font, QColor font_color, QColor back_color)
{
	tip_lab->SetBackgroundColor(back_color);
	tip_lab->SetLabelFontAndColor(font, font_color);
}

void TipSlider::SetShowMode(TipSliderShowMode show_mode)
{
	tip_slider_show_mode = show_mode;
}


void TipSlider::SetTipLabelSpaceAndWidth(int tip_wid_pole_width, int tip_wid_pole_height)
{
	this->tip_wid_pole_width = tip_wid_pole_width;
	this->tip_wid_pole_height = tip_wid_pole_height;
}



void TipSlider::Update()
{
	//固定下来的x轴
	hander_x_axis = (m_width - wid_width) / 2;
	//y轴移动的总距离
	hander_y_dis = m_height - top_value - bottom_value;
	//y轴的步长
	haner_y_step = (double)hander_y_dis / (max_value - min_value);
	//提示滑块x轴
	if (tip_slider_show_mode == Show_Left_Label)
	{
		tip_wid_x = hander_x_axis - tip_wid_pole_width - tip_wid_width;
		tip_lab->show();
	}
	else if(tip_slider_show_mode == Show_Right_Label)
	{
		tip_wid_x = hander_x_axis+ wid_width+ tip_wid_pole_width;
		tip_lab->show();
	}
	else if (tip_slider_show_mode == Show_None_Label)
	{
		tip_wid_x = 0;
		tip_lab->hide();
	}
	
	hander_lab->show();
	SetSliderValue(min_value);
}

void TipSlider::SetSliderValue(int value)
{
	if (value<min_value&&value >max_value)
	{
		cur_value = 0;
		MoveSlider(cur_value);
		emit ValueChange(cur_value);
	}

	cur_value = value;
	MoveSlider(cur_value);
	emit ValueChange(cur_value);
}

void TipSlider::resizeEvent(QResizeEvent* size)
{
	this->m_width = this->width();
	this->m_height = this->height();

	hander_lab->resize(wid_width, wid_height);
	hander_lab->show();

	tip_lab->resize(tip_wid_width, tip_wid_height);

	this->Update();
}
void TipSlider::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	//设置透明笔
	painter.setPen(QColor(1, 1, 1, 0));

	//画背景
	painter.setBrush(slider_color);
	painter.drawRoundedRect(0, 0, m_width, m_height, 8, 8);

	//画杆子
	painter.setBrush(slive_color);
	//计算下杆子的坐标以及长宽
	int slive_x = (m_width - slive_width) / 2;
	int slive_y = top_value;
	int slive_width_new = this->slive_width;
	int slive_height = this->height() - top_value - bottom_value;
	painter.drawRoundedRect(slive_x, slive_y, slive_width_new, slive_height, round_value_x, round_value_y);

	//覆盖一层滑动条划过的颜色的杆子
	painter.setBrush(slive_color_bottom);
	painter.drawRoundedRect(slive_x, hander_lab->y(), slive_width_new, this->height() - bottom_value - hander_lab->y(), round_value_x, round_value_y);

	//画提示滑块和滑块间的线
	QPen pen(slive_color_bottom);
	pen.setWidth(tip_wid_pole_height);
	painter.setPen(pen);
	if (tip_slider_show_mode == Show_Left_Label)
	{
	painter.drawLine(tip_wid_x + tip_wid_width, tip_lab->pos().y() + tip_wid_height / 2, tip_wid_x + tip_wid_width + tip_wid_pole_width, tip_lab->pos().y() + tip_wid_height / 2);

	}
	else if (tip_slider_show_mode == Show_Right_Label)
	{
	painter.drawLine(tip_wid_x- tip_wid_pole_width,tip_lab->pos().y()+tip_wid_height/2,tip_wid_x, tip_lab->pos().y() + tip_wid_height/2);
	}
}
void TipSlider::MoveSlider(int value)
{
	//当前value值对应的y值
	int cur_y = top_value + (value - min_value)*haner_y_step - wid_height / 2;
	hander_lab->move(hander_x_axis, cur_y);
	hander_lab->SetText(QString::number(value));

	tip_lab->move(tip_wid_x, cur_y);
	tip_lab->SetText(QString::number(value));
}

bool TipSlider::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == hander_lab&&event->type() == QEvent::MouseButtonPress)
	{
		cur_state = Checked_State;
	}
	else if (obj == NULL&&event->type() == QEvent::MouseButtonPress)
	{
		cur_state = UnCheck_State;
	}
	if (obj == hander_lab&&event->type() == QEvent::MouseButtonRelease)
	{
		cur_state = UnCheck_State;
	}
	else if (obj == NULL&&event->type() == QEvent::MouseButtonRelease)
	{
		cur_state = UnCheck_State;
	}
	return QWidget::eventFilter(obj, event);
}

void TipSlider::leaveEvent(QEvent* event)
{
	QWidget::leaveEvent(event);
	cur_state = UnCheck_State;
	update();
}

void TipSlider::mouseMoveEvent(QMouseEvent* event)
{
	if (event->buttons()&Qt::LeftButton)
	{
		switch (cur_state)
		{
		case Checked_State:
		{
			if (event->y() <= top_value)
			{
				cur_value = min_value;
				hander_lab->move(hander_x_axis,top_value-wid_height/2);
				hander_lab->SetText(QString::number(cur_value));
				
				tip_lab->move(tip_wid_x,top_value-wid_height/2);
				tip_lab->SetText(QString::number(cur_value));
				
				emit ValueChange(cur_value);
				this->update();
				return;
			}
			else if (event->y() >= m_height - bottom_value)
			{
				cur_value = max_value;
				hander_lab->move(hander_x_axis, m_height-bottom_value-wid_height/2);
				hander_lab->SetText(QString::number(cur_value));

				tip_lab->move(tip_wid_x, m_height-bottom_value-wid_height/2);
				tip_lab->SetText(QString::number(cur_value));

				emit ValueChange(cur_value);
				this->update();
				return;
			}

			float move = (event->y() - top_value) / haner_y_step;
			cur_value = round(move);
			hander_lab->move(hander_x_axis, event->y() - wid_height / 2);
			hander_lab->SetText(QString::number(cur_value));

			tip_lab->move(tip_wid_x, event->y() - wid_height / 2);
			tip_lab->SetText(QString::number(cur_value));

			emit ValueChange(cur_value);
			break;
		}
		}
	}
	update();
}

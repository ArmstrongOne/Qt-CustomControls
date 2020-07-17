#include "CustomSliderStyleTwo.h"
#include "ui_CustomSliderStyleTwo.h"
#include<QPainter>
#include <QDebug>
#include <QPalette>
#include<QMouseEvent>
#include<math.h>
CustomSliderStyleTwo::CustomSliderStyleTwo(QWidget *parent):QWidget(parent)
{
	ui = new Ui::CustomSliderStyleTwo;
	ui->setupUi(this);

	this->hander_lab = ui->hander_lab;
	this->hander_lab->installEventFilter(this);

	//��ʼ��
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

	back_slive_width=0;
	back_slive_top_value=0;
	back_slive_bottom_value=0;
}

CustomSliderStyleTwo::~CustomSliderStyleTwo()
{
	delete ui;
}

void CustomSliderStyleTwo::SetSliveWidth(int value)
{
	this->slive_width = value;
}

void CustomSliderStyleTwo::SetBackgrondColor(QColor slive_color, QColor slider_color, QColor slive_color_bottom)
{
	this->slive_color = slive_color;
	this->slider_color = slider_color;
	this->slive_color_bottom = slive_color_bottom;
}

void CustomSliderStyleTwo::SetTopAndBottomBlank(int top_value, int bottom_value)
{
	this->top_value = top_value;
	this->bottom_value = bottom_value;
}

void CustomSliderStyleTwo::SetSliderWidgetWidthAndHeight(int width, int height)
{
	this->wid_width = width;
	this->wid_height = height;
}

void CustomSliderStyleTwo::SetSliderRange(int min_value, int max_value)
{
	if (min_value >= max_value)
	{
		this->min_value = 0;
		this->max_value = 100;
	}

	this->min_value = min_value;
	this->max_value = max_value;
}

void CustomSliderStyleTwo::SetSliveRoundValue(int x_value, int y_value)
{
	this->round_value_x = x_value;
	this->round_value_y = y_value;
}



void CustomSliderStyleTwo::SetHanderLabelProperty(QFont font, QColor font_color, QColor back_color)
{
	hander_lab->SetBackgroundColor(back_color);
	hander_lab->SetLabelFontAndColor(font, font_color);
}


void CustomSliderStyleTwo::SetHanderLabelRoundValue(int border_x_value, int border_y_value)
{
	hander_lab->SetRoundValue(border_x_value, border_y_value);
}



void CustomSliderStyleTwo::SetInnerCircleRadiusAndColor(int radius, QColor color)
{
	hander_lab->SetInnerCircleProperty(radius, color);
}

void CustomSliderStyleTwo::SetBackgroundSliverColor(QColor back_slive_color)
{
	this->back_slive_color = back_slive_color;
}

void CustomSliderStyleTwo::SetBackgroundSliverWidth(int back_slive_width)
{
	this->back_slive_width = back_slive_width;
}

void CustomSliderStyleTwo::SetBackgroundSliverTopBottomMargin(int back_slive_top_value, int back_slive_bottom_value)
{
	this->back_slive_top_value = back_slive_top_value;
	this->back_slive_bottom_value = back_slive_bottom_value;
}

void CustomSliderStyleTwo::SetBackgroundSliverRoundValue(int back_slive_round_value_x, int back_slive_round_value_y)
{
	this->back_slive_round_value_x = back_slive_round_value_x;
	this->back_slive_round_value_y = back_slive_round_value_y;
}

void CustomSliderStyleTwo::Update()
{
	//�̶�������x��
	hander_x_axis = (m_width - wid_width) / 2;
	//y���ƶ����ܾ���
	hander_y_dis = m_height - top_value - bottom_value;
	//y��Ĳ���
	haner_y_step = (double)hander_y_dis / (max_value - min_value);

	hander_lab->show();
	SetSliderValue(min_value);
}

void CustomSliderStyleTwo::SetSliderValue(int value)
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

void CustomSliderStyleTwo::resizeEvent(QResizeEvent* size)
{
	this->m_width = this->width();
	this->m_height = this->height();

	hander_lab->resize(wid_width, wid_height);
	hander_lab->show();

	this->Update();
}
void CustomSliderStyleTwo::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	//����͸����
	painter.setPen(QColor(1, 1, 1, 0));

	//������
	painter.setBrush(slider_color);
	painter.drawRoundedRect(0, 0, m_width, m_height, 8, 8);

	//����������
	painter.setBrush(back_slive_color);
	//�����¸��ӵ������Լ�����
	int back_slive_x = (m_width - back_slive_width) / 2;
	int back_slive_y = back_slive_top_value;
	int back_slive_width_new = this->back_slive_width;
	int back_slive_height = this->height() - back_slive_top_value - back_slive_bottom_value;
	painter.drawRoundedRect(back_slive_x, back_slive_y, back_slive_width_new, back_slive_height, back_slive_round_value_x, back_slive_round_value_y);

	//������
	painter.setBrush(slive_color);
	//�����¸��ӵ������Լ�����
	int slive_x = (m_width - slive_width) / 2;
	int slive_y = top_value;
	int slive_width_new = this->slive_width;
	int slive_height = this->height() - top_value - bottom_value;
	painter.drawRoundedRect(slive_x, slive_y, slive_width_new, slive_height, round_value_x, round_value_y);

	//����һ�㻬������������ɫ�ĸ���
	painter.setBrush(slive_color_bottom);
	painter.drawRoundedRect(slive_x, hander_lab->y(), slive_width_new, this->height() - bottom_value - hander_lab->y(), round_value_x, round_value_y);
}
void CustomSliderStyleTwo::MoveSlider(int value)
{
	//��ǰvalueֵ��Ӧ��yֵ
	int cur_y = top_value + (value - min_value)*haner_y_step - wid_height / 2;
	hander_lab->move(hander_x_axis, cur_y);
	hander_lab->SetText(QString::number(value));
}

bool CustomSliderStyleTwo::eventFilter(QObject *obj, QEvent *event)
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

void CustomSliderStyleTwo::leaveEvent(QEvent* event)
{
	QWidget::leaveEvent(event);
	cur_state = UnCheck_State;
	update();
}

void CustomSliderStyleTwo::mouseMoveEvent(QMouseEvent* event)
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
				hander_lab->move(hander_x_axis, top_value - wid_height / 2);
				hander_lab->SetText(QString::number(cur_value));
				emit ValueChange(cur_value);
				this->update();
				return;
			}
			else if (event->y() >= m_height - bottom_value)
			{
				cur_value = max_value;
				hander_lab->move(hander_x_axis, m_height - bottom_value - wid_height / 2);
				hander_lab->SetText(QString::number(cur_value));
				emit ValueChange(cur_value);
				this->update();
				return;
			}

			float move = (event->y() - top_value) / haner_y_step;
			cur_value = round(move);
			hander_lab->move(hander_x_axis, event->y() - wid_height / 2);
			hander_lab->SetText(QString::number(cur_value));
			emit ValueChange(cur_value);
			break;
		}
		}
	}
	update();
}

#include "DoubleHandleSlider.h"
#include "ui_DoubleHandleSlider.h"
#include<QPainter>
#include <QDebug>
#include <QPalette>
#include<QMouseEvent>
#include<math.h>
DoubleHandleSlider::DoubleHandleSlider(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::DoubleHandleSlider;
	ui->setupUi(this);

	this->min_handle_lab = ui->min_handle_lab;
	this->min_handle_lab->installEventFilter(this);

	this->max_handle_lab=ui->max_handle_lab;
	this->max_handle_lab->installEventFilter(this);

	m_width=0; 
	m_height=0;

	slive_width=0;
	top_value=0;
	bottom_value=0;

	round_value_x=0; 
	round_value_y=0; 
	wid_width=0;
	wid_height=0;

	min_value=0;
	max_value=0;

	cur_min_value=0;
	cur_max_value=0;

	hander_x_axis=0;
	hander_y_dis=0; 
	haner_y_step = 0;

	cur_state = UnCheck_State;
}

DoubleHandleSlider::~DoubleHandleSlider()
{
	delete ui;
}

void DoubleHandleSlider::SetSliveWidth(int value)
{
	this->slive_width = value;
}

void DoubleHandleSlider::SetBackgrondColor(QColor slive_color, QColor slider_color, QColor slive_color_bottom)
{
	this->slive_color = slive_color;
	this->slider_color = slider_color;
	this->slive_color_bottom = slive_color_bottom;
}

void DoubleHandleSlider::SetTopAndBottomBlank(int top_value, int bottom_value)
{
	this->top_value = top_value;
	this->bottom_value = bottom_value;
}

void DoubleHandleSlider::SetSliderWidgetWidthAndHeight(int width, int height)
{
	this->wid_width = width;
	this->wid_height = height;
}

void DoubleHandleSlider::SetSliderRange(int min_value, int max_value)
{
	if (min_value >= max_value)
	{
		this->min_value = 0;
		this->max_value = 100;
	}

	this->min_value = min_value;
	this->max_value = max_value;
}

void DoubleHandleSlider::SetSliveRoundValue(int x_value, int y_value)
{
	this->round_value_x = x_value;
	this->round_value_y = y_value;
}

void DoubleHandleSlider::SetMinHanderLabelProperty(QFont font, QColor font_color, QColor back_color)
{
	min_handle_lab->SetBackgroundColor(back_color);
	min_handle_lab->SetLabelFontAndColor(font, font_color);
}


void DoubleHandleSlider::SetMinHanderLabelRoundValue(int border_x_value, int border_y_value)
{
	min_handle_lab->SetRoundValue(border_x_value, border_y_value);
}

void DoubleHandleSlider::SetMaxHanderLabelProperty(QFont font, QColor font_color, QColor back_color)
{
	max_handle_lab->SetBackgroundColor(back_color);
	max_handle_lab->SetLabelFontAndColor(font, font_color);
}

void DoubleHandleSlider::SetMaxHanderLabelRoundValue(int border_x_value, int border_y_value)
{
	max_handle_lab->SetRoundValue(border_x_value, border_y_value);
}

void DoubleHandleSlider::Update()
{
	//�̶�������x��
	hander_x_axis = (m_width - wid_width) / 2;
	//y���ƶ����ܾ���
	hander_y_dis = m_height - top_value - bottom_value;
	//y��Ĳ���
	haner_y_step=(double)hander_y_dis/(max_value-min_value);

	min_handle_lab->show();
	max_handle_lab->show();

	//����Сֵ�����Ƶ���С�� �����ֵ�����ƶ�������
	SetMinSliderValue(min_value);
	SetMaxSliderValue(max_value);
}

void DoubleHandleSlider::SetMinSliderValue(int value)
{
	//���С����ֵ�ʹ󻬿���Ȼ��߸�����ô��Ϊ��Сֵ
	if (value<min_value&&value>=cur_max_value)
	{
		cur_min_value = 0;
		MoveMinSlider(cur_min_value);
		emit MinHandleValueChange(cur_min_value);
	}

	cur_min_value = value;
	MoveMinSlider(cur_min_value);
	emit MinHandleValueChange(cur_min_value);
}

void DoubleHandleSlider::SetMaxSliderValue(int value)
{
	//����󻬿�ֵ��С����һ�����߸�С ���߳������ֵ ��ô��Ϊ���ֵ
	if (value<=cur_min_value&&value >max_value)
	{
		cur_max_value = max_value;
		MoveMaxSlider(cur_max_value);
		emit MaxHandleValueChange(cur_max_value);
	}

	cur_max_value = value;
	MoveMaxSlider(cur_max_value);
	emit MaxHandleValueChange(cur_max_value);
}

void DoubleHandleSlider::resizeEvent(QResizeEvent* size)
{
	this->m_width = this->width();
	this->m_height = this->height();

	min_handle_lab->resize(wid_width, wid_height);
	min_handle_lab->show();
	max_handle_lab->resize(wid_width, wid_height);
	max_handle_lab->show();

	this->Update();
}
void DoubleHandleSlider::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	//����͸����
	painter.setPen(QColor(1, 1, 1, 0));

	//������
	painter.setBrush(slider_color);
	painter.drawRoundedRect(0, 0, m_width, m_height, 8, 8);

	//������
	painter.setBrush(slive_color);
	//�����¸��ӵ������Լ�����
	int slive_x = (m_width - slive_width) / 2;
	int slive_y = top_value;
	int slive_width_new = this->slive_width;
	int slive_height = this->height() - top_value - bottom_value;
	painter.drawRoundedRect(slive_x, slive_y, slive_width_new, slive_height, round_value_x, round_value_y);

	//����һ��С���黮������ɫ�ĸ���
	painter.setBrush(slive_color_bottom);
	painter.drawRoundedRect(slive_x, slive_y, slive_width_new, min_handle_lab->y()- slive_y+ wid_height, round_value_x, round_value_y);

	//����һ��󻬿黮������ɫ�ĸ���
	painter.setBrush(slive_color_bottom);
	painter.drawRoundedRect(slive_x, max_handle_lab->y(), slive_width_new, this->height() - bottom_value - max_handle_lab->y(), round_value_x, round_value_y);
}

void DoubleHandleSlider::MoveMinSlider(int min_handle_value)
{
	//��ǰvalueֵ��Ӧ��yֵ�����ﲻ��Ҫ�ж�����һ�㺯�����Ѿ��ж�
	int cur_y = top_value + (min_handle_value - min_value)*haner_y_step - wid_height / 2;
	min_handle_lab->move(hander_x_axis, cur_y);
	min_handle_lab->SetText(QString::number(min_handle_value));
}

void DoubleHandleSlider::MoveMaxSlider(int max_handle_value)
{
	//��ǰvalueֵ��Ӧ��yֵ
	int cur_y = top_value+(max_handle_value - min_value)*haner_y_step - wid_height / 2;
	max_handle_lab->move(hander_x_axis, cur_y);
	max_handle_lab->SetText(QString::number(max_handle_value));
}

bool DoubleHandleSlider::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == min_handle_lab&&event->type() == QEvent::MouseButtonPress)
	{
		cur_state = MinHandleChecked_State;
	}
	else if (obj == max_handle_lab&&event->type() == QEvent::MouseButtonPress)
	{
		cur_state = MaxHandleChecked_State;
	}
	else if (obj == NULL&&event->type() == QEvent::MouseButtonPress)
	{
		cur_state = UnCheck_State;
	}
	
	if (obj == min_handle_lab&&event->type() == QEvent::MouseButtonRelease)
	{
		cur_state = UnCheck_State;
	}
	else if (obj == max_handle_lab&&event->type() == QEvent::MouseButtonRelease)
	{
		cur_state = UnCheck_State;
	}
	else if (obj == NULL&&event->type() == QEvent::MouseButtonRelease)
	{
		cur_state = UnCheck_State;
	}
	return QWidget::eventFilter(obj, event);
}

void DoubleHandleSlider::leaveEvent(QEvent* event)
{
	QWidget::leaveEvent(event);
	cur_state = UnCheck_State;
	update();
}

void DoubleHandleSlider::mouseMoveEvent(QMouseEvent* event)
{
	//�ú���Ӧ������õ��ж������
	if (event->buttons()&Qt::LeftButton)
	{
		switch (cur_state)
		{
		case MinHandleChecked_State:
		{
			//���ڴ󻬿�ŵ��ʹ󻬿�һ����λ��
			if(event->y()>(max_handle_lab->y()+wid_height/2))
			{
				cur_min_value =cur_max_value;
				min_handle_lab->move(max_handle_lab->pos());
				min_handle_lab->SetText(QString::number(cur_min_value));
				emit MinHandleValueChange(cur_min_value);
				this->update();
				return;
			}
			//��������ж�
			if (event->y() <= top_value)
			{
				cur_min_value = min_value;
				min_handle_lab->move(hander_x_axis, top_value - wid_height / 2);
				min_handle_lab->SetText(QString::number(cur_min_value));
				emit MinHandleValueChange(cur_min_value);
				this->update();
				return;
			}
			else if (event->y() >= m_height - bottom_value)
			{
				cur_min_value = max_value;
				min_handle_lab->move(hander_x_axis, m_height - bottom_value - wid_height / 2);
				min_handle_lab->SetText(QString::number(cur_min_value));
				emit MinHandleValueChange(cur_min_value);
				this->update();
				return;
			}

			float move = (event->y()-top_value)/haner_y_step;
			cur_min_value = round(move);
			min_handle_lab->move(hander_x_axis, event->y()-wid_height/2);
			min_handle_lab->SetText(QString::number(cur_min_value));
			emit MinHandleValueChange(cur_min_value);
			break;
		}
		case MaxHandleChecked_State:
		{
			//�󻬿�С����С����,����С����λ��
			if (event->y()< min_handle_lab->y()+wid_height/2)
			{
				cur_max_value = cur_min_value;
				max_handle_lab->move(min_handle_lab->pos());
				max_handle_lab->SetText(QString::number(cur_max_value));
				emit MaxHandleValueChange(cur_max_value);
				this->update();
				return;
			}
			//��������ж�
			if (event->y() <= top_value)
			{
				cur_max_value = min_value;
				max_handle_lab->move(hander_x_axis, top_value - wid_height / 2);
				max_handle_lab->SetText(QString::number(cur_max_value));
				emit MinHandleValueChange(cur_max_value);
				this->update();
				return;
			}
			else if (event->y() >= m_height - bottom_value)
			{
				cur_max_value = max_value;
				max_handle_lab->move(hander_x_axis, m_height - bottom_value - wid_height / 2);
				max_handle_lab->SetText(QString::number(cur_max_value));
				emit MinHandleValueChange(cur_max_value);
				this->update();
				return;
			}

			float move = (event->y()-top_value)/haner_y_step;
	    	cur_max_value = round(move);
			max_handle_lab->move(hander_x_axis, event->y()-wid_height/2);
			max_handle_lab->SetText(QString::number(cur_max_value));
			
			emit MaxHandleValueChange(cur_max_value);
			break;
		}
		}
	}
	update();
}

#pragma once

#include "sliderbar_global.h"

class SLIDERBAR_EXPORT SliderBar
{
public:
	SliderBar();
};

#include <QLabel>
#include<QPainter>
#include <QColor>
class QRoundedLabel :public QLabel
{
	Q_OBJECT
public:
	QRoundedLabel(QWidget *parent) :QLabel(parent)
	{
		border_x_value = 0;
		border_y_value = 0;
		show_str = "";
	};

	~QRoundedLabel()
	{

	};
	void SetRoundValue(int border_x_value, int border_y_value)
	{
		this->border_x_value = border_x_value;
		this->border_y_value = border_y_value;
	};

	void SetBackgroundColor(QColor color)
	{
		back_color = color;
	};

	void SetLabelFontAndColor(QFont font, QColor font_color)
	{
		this->label_font = font;
		this->label_font_color = font_color;
	};

	void SetText(QString str)
	{
		this->show_str = str;
	};

protected:
	int border_x_value;  //����Բ��x��ֵ
	int border_y_value;  //����Բ��y��ֵ
	QColor back_color;   //���ñ�����ɫ
	QColor label_font_color;//������ɫ
	QFont label_font;//label����
	QString show_str;

	virtual void paintEvent(QPaintEvent* event)
	{
		QPainter painter(this);
		painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
		painter.setPen(QColor(1, 1, 1, 0));

		//������
		painter.setBrush(back_color);
		painter.drawRoundedRect(0, 0, this->width(), this->height(), border_x_value, border_y_value);
		//������
		painter.setFont(label_font);
		painter.setPen(QColor(label_font_color));
		painter.drawText(this->rect(), Qt::AlignCenter, show_str);
		this->update();
	};
};
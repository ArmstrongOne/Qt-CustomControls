//2019.7.30���ݷ� ����ؼ�д��ʱ��˼·�Ƚ��� �п����¸�һ��
#pragma once
#include<QPainter>
#include <QColor>
#include <QLabel>
#include "SliderBar.h"

class QRoundedLabelStyleTwo :public QRoundedLabel
{
public:
	QRoundedLabelStyleTwo(QWidget *parent) :QRoundedLabel(parent)
	{
		inner_circle_radius = 0;
	}
	~QRoundedLabelStyleTwo()
	{

	}

	void SetInnerCircleProperty(int inner_circle_radius, QColor inner_circle_color)
	{
		this->inner_circle_radius = inner_circle_radius;
		this->inner_circle_color = inner_circle_color;
	}

protected:
	int inner_circle_radius;//������Բ�뾶
	QColor inner_circle_color;//������Բ������ɫ

private:
	void paintEvent(QPaintEvent* event)//��д��paintEvent����
	{
		QPainter painter(this);
		painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
		painter.setPen(QColor(1, 1, 1, 0));

		//��������Բ��
		painter.setBrush(back_color);
		painter.drawEllipse(0, 0, this->width(), this->height());
		//������Բ��
		painter.setBrush(inner_circle_color);
		painter.drawEllipse(this->width()/2-inner_circle_radius,this->height()/2 - inner_circle_radius, inner_circle_radius*2,inner_circle_radius*2);

		//������(�ÿռ���ʱ����Ҫ��ע�͵�)
		//painter.setFont(label_font);
		//painter.setPen(QColor(label_font_color));
		//painter.drawText(this->rect(), Qt::AlignCenter, show_str);
		this->update();
	}
};

namespace Ui
{
	class CustomSliderStyleTwo;
}
class SLIDERBAR_EXPORT CustomSliderStyleTwo :public QWidget
{
	Q_OBJECT
public:
	CustomSliderStyleTwo(QWidget *parent = Q_NULLPTR);
	~CustomSliderStyleTwo();

	/*****************��Ҫ��ʼ���ӿ�*****************/
	//-----------------------��������������-----------------------
	//���ù����������ӵĿ��
	void SetSliveWidth(int value);
	//���ø�����ɫ�Լ�������ɫ
	void SetBackgrondColor(QColor slive_color, QColor slider_color, QColor slive_color_bottom);
	//���û��������ӵ����±ߵľ���
	void SetTopAndBottomBlank(int top_value, int bottom_value);

	//-------------------------��������----------------------------
	//���û���Ŀ�͸�
	void SetSliderWidgetWidthAndHeight(int width, int height);
	//���û���ķ�Χ
	void SetSliderRange(int min_value, int max_value);
	//���ø���Բ�ǳ̶�
	void SetSliveRoundValue(int x_value, int y_value);
	//���û������壬������ɫ������ɫ
	void SetHanderLabelProperty(QFont font, QColor font_color, QColor back_color);
	//���û���Բ�ǳ̶�
	void SetHanderLabelRoundValue(int border_x_value, int border_y_value);
	//���û�����Ժ�뾶��ɫ
	void SetInnerCircleRadiusAndColor(int radius,QColor colro);


	//-------------------------����������������(��������)----------------------------
	void SetBackgroundSliverColor(QColor back_slive_color);
	void SetBackgroundSliverWidth(int back_slive_width);
	void SetBackgroundSliverTopBottomMargin(int back_slive_top_value, int back_slive_bottom_value);
	void SetBackgroundSliverRoundValue(int back_slive_round_value_x, int back_slive_round_value_y);


	//�����ı�������������������º�������һ�β���Ҫ����(��Ϊ��resize�������)
	void Update();
	/***********************���ƽӿ�***********************/
	void SetSliderValue(int value);


signals:
	void ValueChange(int cur_value);

private:
	Ui::CustomSliderStyleTwo *ui;
	void resizeEvent(QResizeEvent* size); //���ڴ�С�ı��¼������ڵõ���ȷ�Ŀؼ����Ϳ�
	void paintEvent(QPaintEvent* event);//���ڻ�����
	void MoveSlider(int value);//������ֵ�ƶ�����

	bool eventFilter(QObject *obj, QEvent *event);
	void leaveEvent(QEvent* event);
	void mouseMoveEvent(QMouseEvent* event);

	/**********************����״̬********************/

	enum HanderState
	{
		UnCheck_State,
		Checked_State
	};

	/********************���ñ�������*******************/
	int m_width; //�����ؼ���
	int m_height;//�����ؼ���

	int slive_width;//�����������ӵĿ��

	QColor slive_color;  //������ɫ
	QColor slive_color_bottom; //���û��黮���ĸ�����ɫ
	QColor slider_color;  //������ɫ

	int top_value;//���û��������ӵ��ϱ߽�ľ���
	int bottom_value;//���û��������ӵ��±߽�ľ���

	int round_value_x; //����x��Բ����ֵ
	int round_value_y; //����y��Բ����ֵ

	/*******************������������******************/ //-------------��������еģ�����㲻ͬ
	int back_slive_width;        //�������ӿ��
	int back_slive_top_value;    //�������ӵ���������
	int back_slive_bottom_value; //�������ӵ��ײ��ľ���
	QColor back_slive_color;   //����������ɫ
	int back_slive_round_value_x; //��������x��Բ����ֵ
	int back_slive_round_value_y; //��������y��Բ����ֵ
	/*******************���û�������******************/
	QRoundedLabelStyleTwo *hander_lab;

	int wid_width;//������
	int wid_height;//����߶�

	int min_value;//������Сֵ
	int max_value;//�������ֵ
	int cur_value;//���鵱ǰֵ

	int hander_x_axis;//����̶�������x��
	int hander_y_dis; //�������Сֵ�����ֵ�������ܾ���(ʵ���ϵ��ڸ��ӵĳ���)

	double haner_y_step;//�����ƶ��Ĳ���(�����ƶ�1��������λ�ƶ�������ֵ)

	HanderState cur_state; //���鵱ǰ��״̬
};
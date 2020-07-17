#pragma once

#include <QLabel>
#include "SliderBar.h"

class QRoundedLabelStyleOne:public QRoundedLabel
{
public:
	QRoundedLabelStyleOne(QWidget *parent) :QRoundedLabel(parent)
	{

	}
	~QRoundedLabelStyleOne()
	{

	}
private:
	void paintEvent(QPaintEvent* event)//��д��paintEvent����
	{
		QPainter painter(this);
		painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
		painter.setPen(QColor(1, 1, 1, 0));

		//������
		QConicalGradient conicalGradient(this->width()/2, this->height()/2, 0);
		painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
		//����͸����
		painter.setPen(QColor(1, 1, 1, 0));

		//Բ��Ϊ��50��50������ʼ�Ƕ�Ϊ0
		conicalGradient.setColorAt(0, QColor(255, 255, 255));
		conicalGradient.setColorAt(0.3, QColor(100, 100, 100));
		conicalGradient.setColorAt(0.5, QColor(255, 255, 255));
		conicalGradient.setColorAt(0.8, QColor(100, 100, 100));
		conicalGradient.setColorAt(1, QColor(255, 255, 255));

		//��Բ�ĵ�0�Ƚǿ�ʼ��ʱ�����
		painter.setBrush(conicalGradient);
		painter.drawEllipse(0, 0, this->width(),this->height());
		
		//������
		//painter.setFont(label_font);
		//painter.setPen(QColor(label_font_color));
		//painter.drawText(this->rect(), Qt::AlignCenter, show_str);
		this->update();
	}
};


namespace Ui
{
	class CustomSliderStyleOne;
}
class SLIDERBAR_EXPORT CustomSliderStyleOne:public QWidget
{
	Q_OBJECT
public:
	CustomSliderStyleOne(QWidget *parent = Q_NULLPTR);
	~CustomSliderStyleOne();

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

	//�����ı�������������������º�������һ�β���Ҫ����(��Ϊ��resize�������)
	void Update();
	/***********************���ƽӿ�***********************/
	void SetSliderValue(int value);


signals:
	void ValueChange(int cur_value);

private:
	Ui::CustomSliderStyleOne *ui;
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

	/*******************���û�������******************/
	QRoundedLabelStyleOne *hander_lab;

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

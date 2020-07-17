#pragma once

#include <QWidget>
#include "ui_CustomSlider.h"
#include "customslider_global.h"
#include <QLabel>
class CUSTOMSLIDER_EXPORT CustomSlider:public QWidget
{
	Q_OBJECT

public:
	CustomSlider(QWidget *parent = Q_NULLPTR);
	~CustomSlider();

	/*****************��Ҫ��ʼ���ӿ�*****************/
	//���ù����������ӵĿ��
	void SetSliveWidth(int value); 
	//���ø�����ɫ�Լ�������ɫ
	void SetBackgrondColor(QColor slive_color,QColor slider_color,QColor slive_color_bottom);
	//���û��������ӵ����±ߵľ���
	void SetTopAndBottomBlank(int top_value,int bottom_value);
	//���û���Ŀ�͸�
	void SetSliderWidgetWidthAndHeight(int width, int height);
	//���û������ɫ
	void SetHanderColor(QColor hander_color);
	//���û���ķ�Χ
	void SetSliderRange(int min_value, int max_value);
	
	//�����ı�������������������º�������һ�β���Ҫ����
	void Update();
	
	/*****************�Ǳ�Ҫ������ʽ�ӿ�*****************/
	//LabelĬ�Ϲر�)
	void SetHanderLabelEnable(bool);//����label�Ƿ����
	void SetHanderLabelColor(QColor font_color, QColor back_color);//����Label��ɫ
	void SetHanderLabelFont(QFont font);


	/*****************���ƽӿ�*****************/
	void SetSliderValue(int value);


signals:
	void ValueChange(int cur_value);


private:
	Ui::CustomSlider ui;
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



	/*******************���û�������******************/
	QWidget *m_hander;
	int wid_width;//������
	int wid_height;//����߶�
	QColor m_hander_color;//������ɫ

	int min_value;//������Сֵ
	int max_value;//�������ֵ
	int cur_value;//���鵱ǰֵ

	int hander_x_axis;//����̶�������x��
	int hander_y_dis; //�������Сֵ�����ֵ�������ܾ���(ʵ���ϵ��ڸ��ӵĳ���)

	double haner_y_step;//�����ƶ��Ĳ���(�����ƶ�1��������λ�ƶ�������ֵ)

	HanderState cur_state; //���鵱ǰ��״̬

	/*******************�����е�Label******************/
	QLabel *hander_lab;
	QColor label_font_color;//label������ɫ
	QColor label_back_color;//label������ɫ
	QFont label_font;//label����
	
};

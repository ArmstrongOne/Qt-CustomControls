/************************˫���������*****���ݷ� 2019.7.5*********/
#pragma once
#include <QWidget>
#include "SliderBar.h"

namespace Ui
{
	class DoubleHandleSlider;
}

class SLIDERBAR_EXPORT DoubleHandleSlider: public QWidget
{
	Q_OBJECT
public:
	DoubleHandleSlider(QWidget *parent = Q_NULLPTR);
	~DoubleHandleSlider();

	/*****************��Ҫ��ʼ���ӿ�*****************/
	//���ù����������ӵĿ��
	void SetSliveWidth(int value);
	//���ø�����ɫ�Լ�������ɫ
	void SetBackgrondColor(QColor slive_color, QColor slider_color, QColor slive_color_bottom);
	//���û��������ӵ����±ߵľ���
	void SetTopAndBottomBlank(int top_value, int bottom_value);
	//���û���Ŀ�͸�
	void SetSliderWidgetWidthAndHeight(int width, int height);
	//���û���ķ�Χ
	void SetSliderRange(int min_value, int max_value);
	//���ø���Բ�ǳ̶�
	void SetSliveRoundValue(int x_value, int y_value);
	
	
	//����С�������壬������ɫ������ɫ
	void SetMinHanderLabelProperty(QFont font, QColor font_color, QColor back_color);
	//����С����Բ�ǳ̶�
	void SetMinHanderLabelRoundValue(int border_x_value, int border_y_value);

	//���ô󻬿����壬������ɫ������ɫ
	void SetMaxHanderLabelProperty(QFont font, QColor font_color, QColor back_color);
	//����С����Բ�ǳ̶�
	void SetMaxHanderLabelRoundValue(int border_x_value, int border_y_value);


	//�����ı�������������������º�������һ�β���Ҫ����(��Ϊ��resize�������)
	void Update();
	/***********************���ƽӿ�***********************/
	void SetMinSliderValue(int value);
	void SetMaxSliderValue(int value);
signals:
	void MinHandleValueChange(int cur_value);
	void MaxHandleValueChange(int cur_value);

private:
	Ui::DoubleHandleSlider *ui;
	void resizeEvent(QResizeEvent* size); //���ڴ�С�ı��¼������ڵõ���ȷ�Ŀؼ����Ϳ�
	void paintEvent(QPaintEvent* event);//���ڻ�����

	void MoveMinSlider(int min_handle_value);//�ƶ�С���鵽�̶�ֵ
	void MoveMaxSlider(int max_handle_value);//�ƶ��󻬿鵽�̶�ֵ

	bool eventFilter(QObject *obj, QEvent *event);
	void leaveEvent(QEvent* event);
	void mouseMoveEvent(QMouseEvent* event);

	/**********************����״̬********************/

	enum HanderState
	{
		UnCheck_State, //��ѡ��״̬
		MinHandleChecked_State,//С����ѡ��״̬
		MaxHandleChecked_State//�󻬿�״̬
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
	QRoundedLabel *min_handle_lab; //С����
	QRoundedLabel *max_handle_lab; //�󻬿�
	
	//����ֵ-С����ʹ󻬿鹲��
	int wid_width;//������
	int wid_height;//����߶�

	int min_value;//������Сֵ
	int max_value;//�������ֵ
	
	int cur_min_value;//С���鵱ǰֵ
	int cur_max_value;//�󻬿鵱ǰֵ

	int hander_x_axis;//����̶�������x��
	int hander_y_dis; //�������Сֵ�����ֵ�������ܾ���(ʵ���ϵ��ڸ��ӵĳ���)

	double haner_y_step;//�����ƶ��Ĳ���(�����ƶ�1��������λ�ƶ�������ֵ)

	HanderState cur_state; //���鵱ǰ��״̬
};

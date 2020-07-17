/**********��״������*******************/
#pragma once
#include <QWidget>
#include"SliderBar.h"

namespace Ui
{
	class StripSlider;
}
class SLIDERBAR_EXPORT StripSlider : public QWidget
{
	Q_OBJECT

public:
	StripSlider(QWidget *parent = Q_NULLPTR);
	~StripSlider();
	/*****************��Ҫ��ʼ���ӿ�*****************/
	//-----------------------��������������-----------------------
	//���ù����������ӵĿ��
	void SetSliveWidth(int value);
	//���ø�����ɫ�Լ�������ɫ
	void SetBackgrondColor(QColor slive_color, QColor slider_color);
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
	Ui::StripSlider *ui;
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
	QColor slider_color;  //������ɫ

	int top_value;//���û��������ӵ��ϱ߽�ľ���
	int bottom_value;//���û��������ӵ��±߽�ľ���

	int round_value_x; //����x��Բ����ֵ
	int round_value_y; //����y��Բ����ֵ

    /*******************���û�������*********************/
	QRoundedLabel *hander_lab;

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

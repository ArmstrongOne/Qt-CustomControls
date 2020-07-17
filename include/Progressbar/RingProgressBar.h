/***************************���ν�����************************/
#pragma once
#include <QWidget>
#include<QLabel>
#include "ProgressBar.h"

namespace Ui
{
	class RingProgressBar;
}

class PROGRESSBAR_EXPORT RingProgressBar : public QWidget
{
	Q_OBJECT

public:
	RingProgressBar(QWidget *parent = Q_NULLPTR);
	~RingProgressBar();
	/******************�ӿ�************************/
	void SetPanColor(QColor unselected_color, QColor selected_color);//����δѡ�����ɫ��ѡ������ɫ

	void SetInsideCircleRadius(int radius); //�����ڲ�Բ�뾶
	void SetInsideCircleColor(QColor color); //�����ڲ�Բ��ɫ
	void SetBlankLength(int value); //����Բ�������ߵļ��

	void Update();//������ ���øú���
	/*****************���ƽӿ�*****************/
	void SetPanValue(int value);
	void SetPanLabelColor(QColor font_color, QColor back_color);//����Label��ɫ
	void SetPanLabelFont(QFont font);

private:
	Ui::RingProgressBar *ui;
	void paintEvent(QPaintEvent* event);//���ڻ�����
	void resizeEvent(QResizeEvent* size); //���ڴ�С�ı��¼������ڵõ���ȷ�Ŀؼ����Ϳ�

 /***************����Բ������**********************/
	QColor unselected_color; //δѡ�����ɫ(��ʼ��ɫ)
	QColor selected_color; //ѡ�е���ɫ(ָ�뻮������ɫ)
	QColor in_cir_color;//�ڲ�Բ��ɫ

	int m_width_out_cir; //�ⲿԲ��
	int m_height_out_cir;//�ⲿԲ��
	int m_radius_out_cir;//�ⲿԲ�İ뾶

	int m_width_mid_cir; //�в�Բ��
	int m_height_mid_cir;//�в�Բ��
	int m_radius_mid_cir;//�в�Բ�İ뾶

	int m_width_in_cir; //�ڲ�Բ��
	int m_height_in_cir;//�ڲ�Բ��
	int m_radius_in_cir;//�ڲ�Բ�İ뾶

	int blank_value; //Բ�������ߵĿո����;

	int cur_value;//Բ�̵ĵ�ǰֵ ��ΧĬ����0-100

	/***************����Label����**********************/
	QLabel *text_label;
	QColor label_font_color;//label������ɫ
	QColor label_back_color;//label������ɫ
	QFont label_font;//label����
};

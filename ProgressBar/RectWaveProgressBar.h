#pragma once
#include <QWidget>
#include <QLabel>
#include "ProgressBar.h"

namespace Ui
{
	class RectWaveProgressBar;
}

class PROGRESSBAR_EXPORT RectWaveProgressBar:public QWidget
{
	Q_OBJECT

public:
	RectWaveProgressBar(QWidget *parent = Q_NULLPTR);
	~RectWaveProgressBar();
	/**********************�ӿ�************************/
	void SetPanColor(QColor background_color, QColor border_color);//����δѡ�����ɫ��ѡ������ɫ
	void SetMargin(int left_margin, int right_margin, int top_margin, int bottom_margin);

	void SetWaveColor(QColor front_wave_color, QColor behind_wave_color);//����ˮ����ɫ
	void SetBorderWidth(int value);//���ñ߿򳤶�
	void SetWaveProperty(int density, double m_waterHeight, double offset);//�ܶ� ˮ�� �ٶ�
	void Update();//������ ���øú���
	/***********************���ƽӿ�***********************/
	void SetPanValue(int value);
	void SetPanLabelColor(QColor font_color, QColor back_color);//����Label��ɫ
	void SetPanLabelFont(QFont font);

private:
	Ui::RectWaveProgressBar *ui;
	void paintEvent(QPaintEvent* event);//���ڻ�����
	void resizeEvent(QResizeEvent* size); //���ڴ�С�ı��¼������ڵõ���ȷ�Ŀؼ����Ϳ�

	/*********************���þ�������**********************/
	QColor background_color; //Բ�̱�����ɫ
	QColor border_color; //Բ�̱߿���ɫ(�ⲿԲ��ɫ)

	//����һ�����ﻹ����rect��ʾ���� bore=0 ��������غ�
	
	QRect out_rect;//������
	QRect in_rect;  //�ڽӾ���

	int margin_left;//4��marginȷ����Ӿ���
	int margin_right;
	int margin_top;
	int margin_bottom;

	int border_width;//�߿��

	int cur_value;//Բ�̵ĵ�ǰֵ ��ΧĬ����0-100

	 /********************ˮ������*********************/
	QColor front_wave_color;
	QColor behind_wave_color;

	int m_waterDensity; // ˮ�����ܶ� Ӱ����ֵĲ�����
	double m_waterHeight;//ˮ����� 0-1֮�� Ҫ�˸߶�
	double m_init_offset;//��ʼƫ��ֵ����������
	double m_offset; //ƫ��ֵ����Ļˢ��һ��ˮ��ƫ����
	 /***************����Label����**********************/
	QLabel *text_label;
	QColor label_font_color;//label������ɫ
	QColor label_back_color;//label������ɫ
	QFont label_font;//label����
};


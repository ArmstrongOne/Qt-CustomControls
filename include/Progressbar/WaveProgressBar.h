#pragma once
/***********************ˮ��������*********************************/
//gyf  2019.7.4
#include <QWidget>
#include <QLabel>
#include "ProgressBar.h"

namespace Ui
{
	class WaveProgressBar;
}

class PROGRESSBAR_EXPORT WaveProgressBar : public QWidget
{
	Q_OBJECT

public:
	WaveProgressBar(QWidget *parent = Q_NULLPTR);
	~WaveProgressBar();
	/**********************�ӿ�************************/
	void SetPanColor(QColor background_color, QColor border_color);//����δѡ�����ɫ��ѡ������ɫ
	void SetWaveColor(QColor front_wave_color, QColor behind_wave_color);//����ˮ����ɫ
	void SetBorderWidth(int value);//���ñ߿򳤶�
	void SetWaveProperty(int density, double m_waterHeight, double offset);

	void Update();//������ ���øú���
	/***********************���ƽӿ�***********************/
	void SetPanValue(int value);
	void SetPanLabelColor(QColor font_color, QColor back_color);//����Label��ɫ
	void SetPanLabelFont(QFont font);

private:
	Ui::WaveProgressBar *ui;
	void paintEvent(QPaintEvent* event);//���ڻ�����
	void resizeEvent(QResizeEvent* size); //���ڴ�С�ı��¼������ڵõ���ȷ�Ŀؼ����Ϳ�

	/***************����Բ������**********************/
	QColor background_color; //Բ�̱�����ɫ
	QColor border_color; //Բ�̱߿���ɫ(�ⲿԲ��ɫ)

	//����߿�Ϊ0 ���ڲ�Բ���ⲿԲ��С���
	int m_width_out_cir; //�ⲿԲ��
	int m_height_out_cir;//�ⲿԲ��
	int m_radius_out_cir;//�ⲿԲ�뾶

	int m_width_in_cir; //�ڲ�Բ��
	int m_height_in_cir;//�ڲ�Բ��
	int m_radius_in_cir;//�ڲ�Բ�뾶
	QRect in_cir_rect;//�ڲ�Բ������

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


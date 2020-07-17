#pragma once

#include <QWidget>
#include "ui_DashBoard.h"
#include "dashboard_global.h"
class DASHBOARD_EXPORT DashBoard : public QWidget
{
	Q_OBJECT

public:
	DashBoard(QWidget *parent = Q_NULLPTR);
	~DashBoard();
	/******************�ӿ�************************/
	void SetPanColor(QColor unselected_color,QColor selected_color);//����δѡ�����ɫ��ѡ������ɫ

	void Update();//������ ���øú���
	/*****************���ƽӿ�*****************/
	void SetPanValue(int value);
	void SetPanLabelColor(QColor font_color, QColor back_color);//����Label��ɫ
	void SetPanLabelFont(QFont font);
	

private:
	Ui::DashBoard ui;
	void paintEvent(QPaintEvent* event);//���ڻ�����
	void resizeEvent(QResizeEvent* size); //���ڴ�С�ı��¼������ڵõ���ȷ�Ŀؼ����Ϳ�

	/***************����Բ������**********************/
	QColor unselected_color; //δѡ�����ɫ(��ʼ��ɫ)
	QColor selected_color; //ѡ�е���ɫ(ָ�뻮������ɫ)

	int m_width; //�����ؼ���
	int m_height;//�����ؼ���
	int m_radius;//Բ�İ뾶

	int cur_value;//Բ�̵ĵ�ǰֵ ��ΧĬ����0-100

	/***************����Label����**********************/
	QLabel *text_label;
	QColor label_font_color;//label������ɫ
	QColor label_back_color;//label������ɫ
	QFont label_font;//label����
};

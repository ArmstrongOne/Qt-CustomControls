/**************************��ֱ����������*************************/
#pragma once
#include <QWidget>
#include "ProgressBar.h"

namespace Ui
{
	class RectProgressBar;
}
class PROGRESSBAR_EXPORT RectProgressBar : public QWidget
{
	Q_OBJECT

public:
	RectProgressBar(QWidget *parent = Q_NULLPTR);
	~RectProgressBar();
	void SetMargin(int m_margin_left,int m_margin_right,int m_margin_top,int m_margin_bottom); //���ÿؼ������ܵľ���
	void SetSpace(int value);//���ù�������lab��ľ���
	void SetProgressbarHeight(int value);//�������ܸ�
	void SetProgressBarColor(QColor background_color, QColor selected_color);
	void SetLabelProperty(QColor font_color, QColor font_background_color, QFont font);
	void SetBorderRadius(int progressbar_border_radius_x,int progressbar_border_radius_y,int label_border_radius_x,int label_border_radius_y);//����Բ�Ǿ��� Բ��ֵ(0-99);
	//�����Ͳ���Ҫupdate ��Ϊ���в�������ͨ��painterʱʱˢ�µ�

	void SetPanValue(int value);

private:
	Ui::RectProgressBar *ui;

	void paintEvent(QPaintEvent* event);//���ڻ�����
	void resizeEvent(QResizeEvent* size); //���ڴ�С�ı��¼������ڵõ���ȷ�Ŀؼ����Ϳ�

	//��֮ǰ��һ�� ����Ϣ������QRect���Ż�����
	QRect lab_rect;//lab��Ĵ�С
	QRect progressbar_rect;//�����������ӵĴ�С
	QRect selected_rect; //�Ѿ�ѡ��ľ��δ�С

	QColor background_color; //������ɫ
	QColor selected_color; //������ѡ��ɫ
	
	QColor font_color; //�ٷֱ�������ɫ
	QColor label_background_color; //���ֱ�����ɫ
	QFont font; //��������

	int progressbar_border_radius_x;//������Բ�Ǿ��� Բ��xֵ
	int progressbar_border_radius_y;//������Բ�Ǿ��� Բ��yֵ

	int label_border_radius_x;//labelԲ�Ǿ��� Բ��xֵ
	int label_border_radius_y;//labelԲ�Ǿ��� Բ��yֵ


	int m_margin_left;   //�ؼ�����߾���
	int m_margin_right;  //�ؼ����ұ߾���
	int m_margin_top;    //�ؼ�����������
	int m_margin_bottom; //�ؼ����ױ߾���

	int space; //���ֿ򵽹��������
	int progressbar_height; //��Ҫȷ��һ�����������ܳ���


	int cur_value;
};

#pragma once
//2019.7.10 GYF
#include <QWidget>
#include "Animation.h"

namespace Ui
{
	class RXTurnPan;
}

class ANIMATION_EXPORT RXTurnPan : public QWidget
{
	Q_OBJECT

public:
	RXTurnPan(QWidget *parent = Q_NULLPTR);
	~RXTurnPan();
	/*************************�ӿ�***************************/
	//�ÿؼ�������14��ͬ��Բ�滭;����������Բ���⣬ͨ��space_��Բ_СԲ�����������Բ�İ뾶��(���);���º�����Ҫ����13������
	void SetRoundRadius(int space_one_two, int space_two_three, int space_three_four, int space_four_five, int space_five_six, int space_six_seven, int space_seven_eight, int space_eight_nine, int space_nine_ten, int space_ten_eleven, int space_eleven_twelve, int space_twelve_thirteen, int space_thirteen_fourteen);
	
	//���õھŲ�͵�ʮһ��̶Ȼ��ʿ��
	void SetScaleWidth(int round_nine_scale_width, int round_eleven_scale_width);

	//���õ����㣬����㣬��ʮ���������ٶ�
	void SetSectorSpeed(int round_three_speed,int round_five_speed,int round_thirteen_speed);

	//���õھŲ�̶ȣ���ʮһ��̶�Բ������
	void SetScaleRoundSpeed(double round_nine_speed, double round_eleven_speed);

	//������ɫ 
	void SetPanColor(QColor pan_color,QColor background_color);
private:

	void init();//������ʼ��
	void paintEvent(QPaintEvent*);
	void resizeEvent(QResizeEvent* size);

	Ui::RXTurnPan *ui;

	QColor pan_color;
	QColor background_color;

	int m_height;//�ؼ�����ĸ�;����ȷ�������Բ��
	int m_width;//�ؼ�����Ŀ�����ȷ�������Բ��

	//��һ��Բ
	int round_one_radius;
	int round_one_x; //Բ��Ӿ������Ͻ�X����
	int round_one_y;//Բ��Ӿ������Ͻ�Y����
	//�ڶ���Բ��
	int round_two_radius;
	int round_two_x; //Բ��Ӿ������Ͻ�X����
	int round_two_y;//Բ��Ӿ������Ͻ�Y����
	//����������
	int round_three_radius;
	int round_three_x; //Բ��Ӿ������Ͻ�X����
	int round_three_y;//Բ��Ӿ������Ͻ�Y����
	int round_three_upset;//���γ�ʼ�Ƕ�
	int round_three_speed;//���ΰڶ�����

	//���Ĳ�Բ
	int round_four_radius;
	int round_four_x; //Բ��Ӿ������Ͻ�X����
	int round_four_y;//Բ��Ӿ������Ͻ�Y����
	//�����Բ
	int round_five_radius;
	int round_five_x;
	int round_five_y;
	int round_five_upset;//���γ�ʼ�Ƕ�
	int round_five_speed;//���ΰڶ�����
	//������Բ
	int round_six_radius;
	int round_six_x;
	int round_six_y;
	//���߲�Բ
	int round_seven_radius;
	int round_seven_x;
	int round_seven_y;
	//�ڰ˲�Բ
	int round_eight_radius;
	int round_eight_x;
	int round_eight_y;
	//�ھŲ�Բ
	int round_nine_radius;
	int round_nine_x;
	int round_nine_y;
	int round_nine_scale_width;
	double angle_nine; //��ʼ�Ƕ�
	double round_nine_speed;//���ٶ�

	//��ʮ��Բ��
	int round_ten_radius;
	int round_ten_x;
	int round_ten_y;
	//��ʮһ��Բ��
	int round_eleven_radius;
	int round_eleven_x;
	int round_eleven_y;
	int round_eleven_scale_width;
	double angle_eleven;
	double round_eleven_speed;//���ٶ�
	//��ʮ����Բ��
	int round_twelve_radius;
	int round_twelve_x;
	int round_twelve_y;
	//��ʮ����Բ��
	int round_thirteen_radius;
	int round_thirteen_x;
	int round_thirteen_y;
	int round_thirteen_upset;//���γ�ʼ�Ƕ�
	int round_thirteen_speed;//���ΰڶ�����
	//��ʮ�Ĳ�Բ��
	int round_fourteen_radius;
	int round_fourteen_x;
	int round_fourteen_y;

	/*********************Բ֮��ļ��**********************/
	int space_one_two; 
	int space_two_three; 
	int space_three_four; 
	int space_four_five; 
	int space_five_six; 
	int space_six_seven;
	int space_seven_eight; 
	int space_eight_nine; 
	int space_nine_ten;
	int space_ten_eleven; 
	int space_eleven_twelve; 
	int space_twelve_thirteen; 
	int space_thirteen_fourteen;
};

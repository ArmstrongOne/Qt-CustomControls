#include "RXTurnPan.h"
#include <QPainter>
#include <QDebug>
#include <math.h>
#include "ui_RXTurnPan.h"


RXTurnPan::RXTurnPan(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::RXTurnPan;
	ui->setupUi(this);
	init();
}

RXTurnPan::~RXTurnPan()
{
	delete ui;
}

void RXTurnPan::SetRoundRadius(int space_one_two, int space_two_three, int space_three_four, int space_four_five, int space_five_six, int space_six_seven, int space_seven_eight, int space_eight_nine, int space_nine_ten, int space_ten_eleven, int space_eleven_twelve, int space_twelve_thirteen, int space_thirteen_fourteen)
{
	this->space_one_two = space_one_two;
	this->space_two_three = space_two_three;
	this->space_three_four = space_three_four;
	this->space_four_five = space_four_five;
	this->space_five_six = space_five_six;
	this->space_six_seven = space_six_seven;
	this->space_seven_eight = space_seven_eight;
	this->space_eight_nine = space_eight_nine;
	this->space_nine_ten = space_nine_ten;
	this->space_ten_eleven = space_ten_eleven;
	this->space_eleven_twelve = space_eleven_twelve;
	this->space_twelve_thirteen = space_twelve_thirteen;
	this->space_thirteen_fourteen = space_thirteen_fourteen;
}

void RXTurnPan::SetScaleWidth(int round_nine_scale_width, int round_eleven_scale_width)
{
	this->round_nine_scale_width = round_nine_scale_width;
	this->round_eleven_scale_width = round_eleven_scale_width;
}

void RXTurnPan::SetSectorSpeed(int round_three_speed, int round_five_speed, int round_thirteen_speed)
{
	this->round_three_speed = round_three_speed;
	this->round_five_speed = round_five_speed;
	this->round_thirteen_speed = round_thirteen_speed;
}

void RXTurnPan::SetScaleRoundSpeed(double round_nine_speed, double round_eleven_speed)
{
	this->round_nine_speed = round_nine_speed;
	this->round_eleven_speed = round_eleven_speed;
}

void RXTurnPan::SetPanColor(QColor pan_color, QColor background_color)
{
	this->pan_color = pan_color;
	this->background_color = background_color;
}

void RXTurnPan::init()
{
	 m_height=0;//�ؼ�����ĸ�=0;����ȷ�������Բ��
	 m_width=0;//�ؼ�����Ŀ�����ȷ�������Բ��

				//��һ��Բ
	 round_one_radius=0;
	 round_one_x=0; //Բ��Ӿ������Ͻ�X����
	 round_one_y=0;//Բ��Ӿ������Ͻ�Y����
					//�ڶ���Բ��
	 round_two_radius=0;
	 round_two_x=0; //Բ��Ӿ������Ͻ�X����
	 round_two_y=0;//Բ��Ӿ������Ͻ�Y����
					//����������
	 round_three_radius=0;
	 round_three_x=0; //Բ��Ӿ������Ͻ�X����
	 round_three_y=0;//Բ��Ӿ������Ͻ�Y����
	 round_three_upset=0;//���γ�ʼ�Ƕ�
	 round_three_speed=0;//���ΰڶ�����

						  //���Ĳ�Բ
	 round_four_radius=0;
	 round_four_x=0; //Բ��Ӿ������Ͻ�X����
	 round_four_y=0;//Բ��Ӿ������Ͻ�Y����
					 //�����Բ
	 round_five_radius=0;
	 round_five_x=0;
	 round_five_y=0;
	 round_five_upset=0;//���γ�ʼ�Ƕ�
	 round_five_speed=0;//���ΰڶ�����
						 //������Բ
	 round_six_radius=0;
	 round_six_x=0;
	 round_six_y=0;
	//���߲�Բ
	 round_seven_radius=0;
	 round_seven_x=0;
	 round_seven_y=0;
	//�ڰ˲�Բ
	 round_eight_radius=0;
	 round_eight_x=0;
	 round_eight_y=0;
	//�ھŲ�Բ
	 round_nine_radius=0;
	 round_nine_x=0;
	 round_nine_y=0;
	 round_nine_scale_width=0;
	 angle_nine=0; //��ʼ�Ƕ�
	 round_nine_speed=0;//���ٶ�

							//��ʮ��Բ��
	 round_ten_radius=0;
	 round_ten_x=0;
	 round_ten_y=0;
	//��ʮһ��Բ��
	 round_eleven_radius=0;
	 round_eleven_x=0;
	 round_eleven_y=0;
	 round_eleven_scale_width=0;
	 angle_eleven=0;
	 round_eleven_speed=0;//���ٶ�
							  //��ʮ����Բ��
	 round_twelve_radius=0;
	 round_twelve_x=0;
	 round_twelve_y=0;
	//��ʮ����Բ��
	 round_thirteen_radius=0;
	 round_thirteen_x=0;
	 round_thirteen_y=0;
	 round_thirteen_upset=0;//���γ�ʼ�Ƕ�
	 round_thirteen_speed=0;//���ΰڶ�����
							 //��ʮ�Ĳ�Բ��
	 round_fourteen_radius=0;
	 round_fourteen_x=0;
	 round_fourteen_y=0;

	 m_height=0;//�ؼ�����ĸ�=0;����ȷ�������Բ��
	 m_width=0;//�ؼ�����Ŀ�����ȷ�������Բ��

				//��һ��Բ
	 round_one_radius=0;
	 round_one_x=0; //Բ��Ӿ������Ͻ�X����
	 round_one_y=0;//Բ��Ӿ������Ͻ�Y����
					//�ڶ���Բ��
	 round_two_radius=0;
	 round_two_x=0; //Բ��Ӿ������Ͻ�X����
	 round_two_y=0;//Բ��Ӿ������Ͻ�Y����
					//����������
	 round_three_radius=0;
	 round_three_x=0; //Բ��Ӿ������Ͻ�X����
	 round_three_y=0;//Բ��Ӿ������Ͻ�Y����
	 round_three_upset=0;//���γ�ʼ�Ƕ�
	 round_three_speed=0;//���ΰڶ�����

						  //���Ĳ�Բ
	 round_four_radius=0;
	 round_four_x=0; //Բ��Ӿ������Ͻ�X����
	 round_four_y=0;//Բ��Ӿ������Ͻ�Y����
					 //�����Բ
	 round_five_radius=0;
	 round_five_x=0;
	 round_five_y=0;
	 round_five_upset=0;//���γ�ʼ�Ƕ�
	 round_five_speed=0;//���ΰڶ�����
						 //������Բ
	 round_six_radius=0;
	 round_six_x=0;
	 round_six_y=0;
	//���߲�Բ
	 round_seven_radius=0;
	 round_seven_x=0;
	 round_seven_y=0;
	//�ڰ˲�Բ
	 round_eight_radius=0;
	 round_eight_x=0;
	 round_eight_y=0;
	//�ھŲ�Բ
	 round_nine_radius=0;
	 round_nine_x=0;
	 round_nine_y=0;
	 round_nine_scale_width=0;
	 angle_nine=0; //��ʼ�Ƕ�
	 round_nine_speed=0;//���ٶ�

							//��ʮ��Բ��
	 round_ten_radius=0;
	 round_ten_x=0;
	 round_ten_y=0;
	//��ʮһ��Բ��
	 round_eleven_radius=0;
	 round_eleven_x=0;
	 round_eleven_y=0;
	 round_eleven_scale_width=0;
	 angle_eleven=0;
	 round_eleven_speed=0;//���ٶ�
							  //��ʮ����Բ��
	 round_twelve_radius=0;
	 round_twelve_x=0;
	 round_twelve_y=0;
	//��ʮ����Բ��
	 round_thirteen_radius=0;
	 round_thirteen_x=0;
	 round_thirteen_y=0;
	 round_thirteen_upset=0;//���γ�ʼ�Ƕ�
	 round_thirteen_speed=0;//���ΰڶ�����
							 //��ʮ�Ĳ�Բ��
	 round_fourteen_radius=0;
	 round_fourteen_x=0;
	 round_fourteen_y=0;

	/*********************Բ֮��ļ��**********************/
	 space_one_two=0;
	 space_two_three=0;
	 space_three_four=0;
	 space_four_five=0;
	 space_five_six=0;
	 space_six_seven=0;
	 space_seven_eight=0;
	 space_eight_nine=0;
	 space_nine_ten=0;
	 space_ten_eleven=0;
	 space_eleven_twelve=0;
	 space_twelve_thirteen=0;
	 space_thirteen_fourteen=0;
	 space_one_two=0;
	 space_two_three=0;
	 space_three_four=0;
	 space_four_five=0;
	 space_five_six=0;
	 space_six_seven=0;
	 space_seven_eight=0;
	 space_eight_nine=0;
	 space_nine_ten=0;
	 space_ten_eleven=0;
	 space_eleven_twelve=0;
	 space_twelve_thirteen=0;
	 space_thirteen_fourteen=0;
}

void RXTurnPan::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	
	//����͸����
	painter.setPen(QColor(1, 1, 1, 0));

	//����һ��Բ��
	painter.setBrush(pan_color);
	painter.drawEllipse(round_one_x, round_one_y, round_one_radius * 2, round_one_radius*2);

	//���ڶ���Բ��
	painter.setBrush(background_color);
	painter.drawEllipse(round_two_x, round_two_y, round_two_radius * 2, round_two_radius * 2);

	//������������
	painter.setBrush(pan_color);
	round_three_upset = round_three_upset + round_three_speed;//��λ��1/16��  һȦ��5760
	int startAngle = round_three_upset;      // ���θ��Ƿ�Χ��120�ȵģ�
	int spanAngle=1500;                       //(double)60/100 * 5760;
	if (round_three_upset > 5760)
	{
		round_three_upset =0;
	}
	QRect rect_round_three(round_three_x, round_three_y, round_three_radius*2, round_three_radius * 2);
	painter.drawPie(rect_round_three, startAngle, spanAngle);


	//�����Ĳ�Բ��
	painter.setBrush(background_color);
	painter.drawEllipse(round_four_x, round_four_y, round_four_radius * 2, round_four_radius * 2);

	//�����������
	painter.setBrush(pan_color);
	//��λ��1/16��  һȦ��5760
	round_five_upset = round_five_upset-round_five_speed;
	int startAngle_round_five = round_five_upset;
	// ���θ��Ƿ�Χ��120�ȵģ�
	int spanAngle_round_five = 1500;     //(double)60/100 * 5760;
	if (round_three_upset<-5760)
	{
		round_five_upset = 0;
	}
	QRect rect_round_five(round_five_x, round_five_y, round_five_radius * 2, round_five_radius * 2);
	painter.drawPie(rect_round_five, startAngle_round_five, spanAngle);

	//��������Բ��
	painter.setBrush(background_color);
	painter.drawEllipse(round_six_x, round_six_y, round_six_radius * 2, round_six_radius * 2);

	//�����߲�Բ��
	painter.setBrush(pan_color);
	painter.drawEllipse(round_seven_x, round_seven_y, round_seven_radius * 2, round_seven_radius * 2);


	//���ڰ˲�Բ��
	painter.setBrush(background_color);
	painter.drawEllipse(round_eight_x, round_eight_y, round_eight_radius * 2, round_eight_radius * 2);
    
	//���ھŲ�̶�Բ��
	QTransform tran_round_nine;
	tran_round_nine.translate(round_one_radius, round_one_radius);//��Բ��Ϊ��ת����
	QPen pen_round_nine;
	pen_round_nine.setColor(pan_color);
	pen_round_nine.setWidth(round_nine_scale_width);
	painter.setPen(pen_round_nine);

	angle_nine = angle_nine+ round_nine_speed;
	if (angle_nine>M_PI/30)
	{
		angle_nine = 0;
	}

	for (int i = 1; i <= 60; i++)
	{
		//�ܹ�60���̶ȣ�60�Σ�ÿ��6��
		tran_round_nine.rotate(6);
		painter.setTransform(tran_round_nine);
		
		double y= sin(angle_nine)*round_nine_radius;
		double x = cos(angle_nine)*round_nine_radius;
		
		//���������̶�,
		painter.drawLine(0, 0, x,y);
	}
	QTransform tran_round_nine_init;
	painter.setTransform(tran_round_nine_init);


	//����ʮ��Բ��
	painter.setPen(QColor(1, 1, 1, 0));
	painter.setBrush(background_color);
	painter.drawEllipse(round_ten_x, round_ten_y, round_ten_radius * 2, round_ten_radius * 2);
	
	
	//����ʮһ��̶�Բ��
	QTransform tran_round_eleven;
	tran_round_eleven.translate(round_one_radius, round_one_radius);//��Բ��Ϊ��ת����
	QPen pen_round_eleven;
	pen_round_eleven.setColor(pan_color);
	pen_round_eleven.setWidth(round_eleven_scale_width);
	painter.setPen(pen_round_eleven);

	angle_eleven = angle_eleven+round_eleven_speed;
	if (angle_eleven>M_PI /60)
	{
		angle_eleven = 0;
	}
	for (int i = 1; i<=120; i++)
	{
		//�ܹ�12���̶ȣ�12�Σ�ÿ��30��
		tran_round_eleven.rotate(-3);
	
		painter.setTransform(tran_round_eleven);
		double y = sin(angle_eleven)*round_eleven_radius;
		double x = cos(angle_eleven)*round_eleven_radius;

		//���������̶�,
		painter.drawLine(0, 0,-x, y);
	}
	QTransform tran_round_eleven_init;
	painter.setTransform(tran_round_eleven_init);
	
	
	//����ʮ����Բ��
	painter.setPen(QColor(1, 1, 1, 0));
	painter.setBrush(background_color);
	painter.drawEllipse(round_twelve_x, round_twelve_y, round_twelve_radius * 2, round_twelve_radius * 2);
	

	//����ʮ��������
	painter.setBrush(pan_color);
	//��λ��1/16��  һȦ��5760
	round_thirteen_upset = round_thirteen_upset+ round_thirteen_speed;
	int startAngle_round_thirteen = round_thirteen_upset;
	// ���θ��Ƿ�Χ��120�ȵģ�
	int spanAngle_round_thirteen = 1500;     //(double)60/100 * 5760;
	if (round_three_upset>5760)
	{
		round_thirteen_upset = 0;
	}
	QRect rect_round_thirteen(round_thirteen_x, round_thirteen_y, round_thirteen_radius * 2, round_thirteen_radius * 2);
	painter.drawPie(rect_round_thirteen, startAngle_round_thirteen, spanAngle);


	//����ʮ�Ĳ�Բ��
	painter.setPen(QColor(1, 1, 1, 0));
	painter.setBrush(background_color);
	painter.drawEllipse(round_fourteen_x, round_fourteen_y,round_fourteen_radius*2,round_fourteen_radius*2);

	//ˢ��
	this->update();
}

void RXTurnPan::resizeEvent(QResizeEvent* size)
{
	//ȷ���ؼ���С
	this->m_height = this->height();
	this->m_width = this->width();
   
	//���Ϳ����ȡż��
	if (m_height % 2 != 0)
	{
		m_height = m_height - 1;
	}
	if (m_width % 2 != 0)
	{
		m_width = m_width - 1;
	}
	//���Ϳ�ȡ����һ����Сֵ
	if (m_height<m_width)
	{
		m_width = m_height;
	}
	else
	{
		m_height = m_width;
	}

	//ȷ��Բ����Ϣ(Բ1)
	round_one_radius = (m_width+ m_height)/4;
	this->round_one_x = 0;
	this->round_one_y = 0;

	//ȷ��Բ��Ϣ(Բ2)
	round_two_radius =round_one_radius- space_one_two;
	this->round_two_x = round_one_x + round_one_radius - round_two_radius;
	this->round_two_y = 0+ round_one_radius- round_two_radius;

	//ȷ��Բ(����)��Ϣ(Բ3)
	round_three_radius = round_two_radius- space_two_three;
	this->round_three_x = round_two_x +round_two_radius-round_three_radius;
	this->round_three_y = round_two_y + round_two_radius - round_three_radius;

	//ȷ��Բ(����)��Ϣ(Բ4)
	round_four_radius = round_three_radius - space_three_four;
	this->round_four_x = round_three_x + round_three_radius - round_four_radius;
	this->round_four_y = round_three_y + round_three_radius - round_four_radius;

	//ȷ��Բ(����)��Ϣ(Բ5)
	round_five_radius = round_four_radius - space_four_five;
	this->round_five_x = round_four_x + round_four_radius - round_five_radius;
	this->round_five_y = round_four_y + round_four_radius - round_five_radius;

	//ȷ��Բ(����)��Ϣ(Բ6)
	round_six_radius = round_five_radius - space_five_six;
	this->round_six_x = round_five_x + round_five_radius - round_six_radius;
	this->round_six_y = round_five_y + round_five_radius - round_six_radius;

	//ȷ��Բ(����)��Ϣ(Բ7)
	round_seven_radius = round_six_radius - space_six_seven;
	this->round_seven_x = round_six_x + round_six_radius - round_seven_radius;
	this->round_seven_y = round_six_y + round_six_radius - round_seven_radius;

	//ȷ��Բ(����)��Ϣ(Բ8)
	round_eight_radius = round_seven_radius - space_seven_eight;
	this->round_eight_x = round_seven_x + round_seven_radius - round_eight_radius;
	this->round_eight_y = round_seven_y + round_seven_radius - round_eight_radius;

	//ȷ��Բ(����)��Ϣ(Բ9)
	round_nine_radius = round_eight_radius- space_eight_nine;
	this->round_nine_x = round_eight_x + round_eight_radius - round_nine_radius;
	this->round_nine_y = round_eight_y + round_eight_radius - round_nine_radius;


	//ȷ��Բ(����)��Ϣ(Բ10)
	round_ten_radius = round_nine_radius- space_nine_ten;
	this->round_ten_x = round_nine_x + round_nine_radius - round_ten_radius;
	this->round_ten_y = round_nine_y + round_nine_radius - round_ten_radius;

	//ȷ��Բ(����)��Ϣ(Բ11)
	round_eleven_radius = round_ten_radius - space_ten_eleven;
	this->round_eleven_x = round_ten_x + round_ten_radius - round_eleven_radius;
	this->round_eleven_y = round_ten_y + round_ten_radius - round_eleven_radius;

	//ȷ��Բ(����)��Ϣ(Բ12)
	round_twelve_radius = round_eleven_radius - space_eleven_twelve;
	this->round_twelve_x = round_eleven_x + round_eleven_radius - round_twelve_radius;
	this->round_twelve_y = round_eleven_y + round_eleven_radius - round_twelve_radius;

	//ȷ��Բ(����)��Ϣ(Բ13)
	round_thirteen_radius = round_twelve_radius - space_twelve_thirteen;
	this->round_thirteen_x = round_twelve_x + round_twelve_radius - round_thirteen_radius;
	this->round_thirteen_y = round_twelve_y + round_twelve_radius - round_thirteen_radius;

	//ȷ��Բ(����)��Ϣ(Բ14)
	round_fourteen_radius = round_thirteen_radius-space_thirteen_fourteen;
	this->round_fourteen_x = round_thirteen_x + round_thirteen_radius - round_fourteen_radius;
	this->round_fourteen_y = round_thirteen_y + round_thirteen_radius - round_fourteen_radius;
}

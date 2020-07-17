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
	 m_height=0;//控件自身的高=0;用于确定最外层圆形
	 m_width=0;//控件自身的宽，用于确定最外层圆形

				//第一层圆
	 round_one_radius=0;
	 round_one_x=0; //圆外接矩形左上角X坐标
	 round_one_y=0;//圆外接矩形左上角Y坐标
					//第二层圆形
	 round_two_radius=0;
	 round_two_x=0; //圆外接矩形左上角X坐标
	 round_two_y=0;//圆外接矩形左上角Y坐标
					//第三层扇形
	 round_three_radius=0;
	 round_three_x=0; //圆外接矩形左上角X坐标
	 round_three_y=0;//圆外接矩形左上角Y坐标
	 round_three_upset=0;//扇形初始角度
	 round_three_speed=0;//扇形摆动速率

						  //第四层圆
	 round_four_radius=0;
	 round_four_x=0; //圆外接矩形左上角X坐标
	 round_four_y=0;//圆外接矩形左上角Y坐标
					 //第五层圆
	 round_five_radius=0;
	 round_five_x=0;
	 round_five_y=0;
	 round_five_upset=0;//扇形初始角度
	 round_five_speed=0;//扇形摆动速率
						 //第六层圆
	 round_six_radius=0;
	 round_six_x=0;
	 round_six_y=0;
	//第七层圆
	 round_seven_radius=0;
	 round_seven_x=0;
	 round_seven_y=0;
	//第八层圆
	 round_eight_radius=0;
	 round_eight_x=0;
	 round_eight_y=0;
	//第九层圆
	 round_nine_radius=0;
	 round_nine_x=0;
	 round_nine_y=0;
	 round_nine_scale_width=0;
	 angle_nine=0; //初始角度
	 round_nine_speed=0;//角速度

							//第十层圆形
	 round_ten_radius=0;
	 round_ten_x=0;
	 round_ten_y=0;
	//第十一层圆形
	 round_eleven_radius=0;
	 round_eleven_x=0;
	 round_eleven_y=0;
	 round_eleven_scale_width=0;
	 angle_eleven=0;
	 round_eleven_speed=0;//角速度
							  //第十二层圆形
	 round_twelve_radius=0;
	 round_twelve_x=0;
	 round_twelve_y=0;
	//第十三层圆形
	 round_thirteen_radius=0;
	 round_thirteen_x=0;
	 round_thirteen_y=0;
	 round_thirteen_upset=0;//扇形初始角度
	 round_thirteen_speed=0;//扇形摆动速率
							 //第十四层圆形
	 round_fourteen_radius=0;
	 round_fourteen_x=0;
	 round_fourteen_y=0;

	 m_height=0;//控件自身的高=0;用于确定最外层圆形
	 m_width=0;//控件自身的宽，用于确定最外层圆形

				//第一层圆
	 round_one_radius=0;
	 round_one_x=0; //圆外接矩形左上角X坐标
	 round_one_y=0;//圆外接矩形左上角Y坐标
					//第二层圆形
	 round_two_radius=0;
	 round_two_x=0; //圆外接矩形左上角X坐标
	 round_two_y=0;//圆外接矩形左上角Y坐标
					//第三层扇形
	 round_three_radius=0;
	 round_three_x=0; //圆外接矩形左上角X坐标
	 round_three_y=0;//圆外接矩形左上角Y坐标
	 round_three_upset=0;//扇形初始角度
	 round_three_speed=0;//扇形摆动速率

						  //第四层圆
	 round_four_radius=0;
	 round_four_x=0; //圆外接矩形左上角X坐标
	 round_four_y=0;//圆外接矩形左上角Y坐标
					 //第五层圆
	 round_five_radius=0;
	 round_five_x=0;
	 round_five_y=0;
	 round_five_upset=0;//扇形初始角度
	 round_five_speed=0;//扇形摆动速率
						 //第六层圆
	 round_six_radius=0;
	 round_six_x=0;
	 round_six_y=0;
	//第七层圆
	 round_seven_radius=0;
	 round_seven_x=0;
	 round_seven_y=0;
	//第八层圆
	 round_eight_radius=0;
	 round_eight_x=0;
	 round_eight_y=0;
	//第九层圆
	 round_nine_radius=0;
	 round_nine_x=0;
	 round_nine_y=0;
	 round_nine_scale_width=0;
	 angle_nine=0; //初始角度
	 round_nine_speed=0;//角速度

							//第十层圆形
	 round_ten_radius=0;
	 round_ten_x=0;
	 round_ten_y=0;
	//第十一层圆形
	 round_eleven_radius=0;
	 round_eleven_x=0;
	 round_eleven_y=0;
	 round_eleven_scale_width=0;
	 angle_eleven=0;
	 round_eleven_speed=0;//角速度
							  //第十二层圆形
	 round_twelve_radius=0;
	 round_twelve_x=0;
	 round_twelve_y=0;
	//第十三层圆形
	 round_thirteen_radius=0;
	 round_thirteen_x=0;
	 round_thirteen_y=0;
	 round_thirteen_upset=0;//扇形初始角度
	 round_thirteen_speed=0;//扇形摆动速率
							 //第十四层圆形
	 round_fourteen_radius=0;
	 round_fourteen_x=0;
	 round_fourteen_y=0;

	/*********************圆之间的间距**********************/
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
	
	//设置透明笔
	painter.setPen(QColor(1, 1, 1, 0));

	//画第一层圆形
	painter.setBrush(pan_color);
	painter.drawEllipse(round_one_x, round_one_y, round_one_radius * 2, round_one_radius*2);

	//画第二层圆形
	painter.setBrush(background_color);
	painter.drawEllipse(round_two_x, round_two_y, round_two_radius * 2, round_two_radius * 2);

	//画第三层扇形
	painter.setBrush(pan_color);
	round_three_upset = round_three_upset + round_three_speed;//单位是1/16度  一圈是5760
	int startAngle = round_three_upset;      // 扇形覆盖范围（120度的）
	int spanAngle=1500;                       //(double)60/100 * 5760;
	if (round_three_upset > 5760)
	{
		round_three_upset =0;
	}
	QRect rect_round_three(round_three_x, round_three_y, round_three_radius*2, round_three_radius * 2);
	painter.drawPie(rect_round_three, startAngle, spanAngle);


	//画第四层圆形
	painter.setBrush(background_color);
	painter.drawEllipse(round_four_x, round_four_y, round_four_radius * 2, round_four_radius * 2);

	//画第五层扇形
	painter.setBrush(pan_color);
	//单位是1/16度  一圈是5760
	round_five_upset = round_five_upset-round_five_speed;
	int startAngle_round_five = round_five_upset;
	// 扇形覆盖范围（120度的）
	int spanAngle_round_five = 1500;     //(double)60/100 * 5760;
	if (round_three_upset<-5760)
	{
		round_five_upset = 0;
	}
	QRect rect_round_five(round_five_x, round_five_y, round_five_radius * 2, round_five_radius * 2);
	painter.drawPie(rect_round_five, startAngle_round_five, spanAngle);

	//画第六层圆形
	painter.setBrush(background_color);
	painter.drawEllipse(round_six_x, round_six_y, round_six_radius * 2, round_six_radius * 2);

	//画第七层圆形
	painter.setBrush(pan_color);
	painter.drawEllipse(round_seven_x, round_seven_y, round_seven_radius * 2, round_seven_radius * 2);


	//画第八层圆形
	painter.setBrush(background_color);
	painter.drawEllipse(round_eight_x, round_eight_y, round_eight_radius * 2, round_eight_radius * 2);
    
	//画第九层刻度圆形
	QTransform tran_round_nine;
	tran_round_nine.translate(round_one_radius, round_one_radius);//以圆心为旋转中心
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
		//总共60个刻度，60段，每段6度
		tran_round_nine.rotate(6);
		painter.setTransform(tran_round_nine);
		
		double y= sin(angle_nine)*round_nine_radius;
		double x = cos(angle_nine)*round_nine_radius;
		
		//绘制线条刻度,
		painter.drawLine(0, 0, x,y);
	}
	QTransform tran_round_nine_init;
	painter.setTransform(tran_round_nine_init);


	//画第十层圆形
	painter.setPen(QColor(1, 1, 1, 0));
	painter.setBrush(background_color);
	painter.drawEllipse(round_ten_x, round_ten_y, round_ten_radius * 2, round_ten_radius * 2);
	
	
	//画第十一层刻度圆形
	QTransform tran_round_eleven;
	tran_round_eleven.translate(round_one_radius, round_one_radius);//以圆心为旋转中心
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
		//总共12个刻度，12段，每段30度
		tran_round_eleven.rotate(-3);
	
		painter.setTransform(tran_round_eleven);
		double y = sin(angle_eleven)*round_eleven_radius;
		double x = cos(angle_eleven)*round_eleven_radius;

		//绘制线条刻度,
		painter.drawLine(0, 0,-x, y);
	}
	QTransform tran_round_eleven_init;
	painter.setTransform(tran_round_eleven_init);
	
	
	//画第十二层圆形
	painter.setPen(QColor(1, 1, 1, 0));
	painter.setBrush(background_color);
	painter.drawEllipse(round_twelve_x, round_twelve_y, round_twelve_radius * 2, round_twelve_radius * 2);
	

	//画第十三层扇形
	painter.setBrush(pan_color);
	//单位是1/16度  一圈是5760
	round_thirteen_upset = round_thirteen_upset+ round_thirteen_speed;
	int startAngle_round_thirteen = round_thirteen_upset;
	// 扇形覆盖范围（120度的）
	int spanAngle_round_thirteen = 1500;     //(double)60/100 * 5760;
	if (round_three_upset>5760)
	{
		round_thirteen_upset = 0;
	}
	QRect rect_round_thirteen(round_thirteen_x, round_thirteen_y, round_thirteen_radius * 2, round_thirteen_radius * 2);
	painter.drawPie(rect_round_thirteen, startAngle_round_thirteen, spanAngle);


	//画第十四层圆形
	painter.setPen(QColor(1, 1, 1, 0));
	painter.setBrush(background_color);
	painter.drawEllipse(round_fourteen_x, round_fourteen_y,round_fourteen_radius*2,round_fourteen_radius*2);

	//刷新
	this->update();
}

void RXTurnPan::resizeEvent(QResizeEvent* size)
{
	//确定控件大小
	this->m_height = this->height();
	this->m_width = this->width();
   
	//长和宽必须取偶数
	if (m_height % 2 != 0)
	{
		m_height = m_height - 1;
	}
	if (m_width % 2 != 0)
	{
		m_width = m_width - 1;
	}
	//长和宽取其中一个最小值
	if (m_height<m_width)
	{
		m_width = m_height;
	}
	else
	{
		m_height = m_width;
	}

	//确定圆外信息(圆1)
	round_one_radius = (m_width+ m_height)/4;
	this->round_one_x = 0;
	this->round_one_y = 0;

	//确定圆信息(圆2)
	round_two_radius =round_one_radius- space_one_two;
	this->round_two_x = round_one_x + round_one_radius - round_two_radius;
	this->round_two_y = 0+ round_one_radius- round_two_radius;

	//确定圆(扇形)信息(圆3)
	round_three_radius = round_two_radius- space_two_three;
	this->round_three_x = round_two_x +round_two_radius-round_three_radius;
	this->round_three_y = round_two_y + round_two_radius - round_three_radius;

	//确定圆(扇形)信息(圆4)
	round_four_radius = round_three_radius - space_three_four;
	this->round_four_x = round_three_x + round_three_radius - round_four_radius;
	this->round_four_y = round_three_y + round_three_radius - round_four_radius;

	//确定圆(扇形)信息(圆5)
	round_five_radius = round_four_radius - space_four_five;
	this->round_five_x = round_four_x + round_four_radius - round_five_radius;
	this->round_five_y = round_four_y + round_four_radius - round_five_radius;

	//确定圆(扇形)信息(圆6)
	round_six_radius = round_five_radius - space_five_six;
	this->round_six_x = round_five_x + round_five_radius - round_six_radius;
	this->round_six_y = round_five_y + round_five_radius - round_six_radius;

	//确定圆(扇形)信息(圆7)
	round_seven_radius = round_six_radius - space_six_seven;
	this->round_seven_x = round_six_x + round_six_radius - round_seven_radius;
	this->round_seven_y = round_six_y + round_six_radius - round_seven_radius;

	//确定圆(扇形)信息(圆8)
	round_eight_radius = round_seven_radius - space_seven_eight;
	this->round_eight_x = round_seven_x + round_seven_radius - round_eight_radius;
	this->round_eight_y = round_seven_y + round_seven_radius - round_eight_radius;

	//确定圆(扇形)信息(圆9)
	round_nine_radius = round_eight_radius- space_eight_nine;
	this->round_nine_x = round_eight_x + round_eight_radius - round_nine_radius;
	this->round_nine_y = round_eight_y + round_eight_radius - round_nine_radius;


	//确定圆(扇形)信息(圆10)
	round_ten_radius = round_nine_radius- space_nine_ten;
	this->round_ten_x = round_nine_x + round_nine_radius - round_ten_radius;
	this->round_ten_y = round_nine_y + round_nine_radius - round_ten_radius;

	//确定圆(扇形)信息(圆11)
	round_eleven_radius = round_ten_radius - space_ten_eleven;
	this->round_eleven_x = round_ten_x + round_ten_radius - round_eleven_radius;
	this->round_eleven_y = round_ten_y + round_ten_radius - round_eleven_radius;

	//确定圆(扇形)信息(圆12)
	round_twelve_radius = round_eleven_radius - space_eleven_twelve;
	this->round_twelve_x = round_eleven_x + round_eleven_radius - round_twelve_radius;
	this->round_twelve_y = round_eleven_y + round_eleven_radius - round_twelve_radius;

	//确定圆(扇形)信息(圆13)
	round_thirteen_radius = round_twelve_radius - space_twelve_thirteen;
	this->round_thirteen_x = round_twelve_x + round_twelve_radius - round_thirteen_radius;
	this->round_thirteen_y = round_twelve_y + round_twelve_radius - round_thirteen_radius;

	//确定圆(扇形)信息(圆14)
	round_fourteen_radius = round_thirteen_radius-space_thirteen_fourteen;
	this->round_fourteen_x = round_thirteen_x + round_thirteen_radius - round_fourteen_radius;
	this->round_fourteen_y = round_thirteen_y + round_thirteen_radius - round_fourteen_radius;
}

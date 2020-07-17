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
	/*************************接口***************************/
	//该控件运用了14个同心圆绘画;除最外层外接圆以外，通过space_大圆_小圆来设置其各个圆的半径差(间距);以下函数需要包含13个参数
	void SetRoundRadius(int space_one_two, int space_two_three, int space_three_four, int space_four_five, int space_five_six, int space_six_seven, int space_seven_eight, int space_eight_nine, int space_nine_ten, int space_ten_eleven, int space_eleven_twelve, int space_twelve_thirteen, int space_thirteen_fourteen);
	
	//设置第九层和第十一层刻度画笔宽度
	void SetScaleWidth(int round_nine_scale_width, int round_eleven_scale_width);

	//设置第三层，第五层，第十三层扇形速度
	void SetSectorSpeed(int round_three_speed,int round_five_speed,int round_thirteen_speed);

	//设置第九层刻度，第十一层刻度圆形速率
	void SetScaleRoundSpeed(double round_nine_speed, double round_eleven_speed);

	//设置颜色 
	void SetPanColor(QColor pan_color,QColor background_color);
private:

	void init();//变量初始化
	void paintEvent(QPaintEvent*);
	void resizeEvent(QResizeEvent* size);

	Ui::RXTurnPan *ui;

	QColor pan_color;
	QColor background_color;

	int m_height;//控件自身的高;用于确定最外层圆形
	int m_width;//控件自身的宽，用于确定最外层圆形

	//第一层圆
	int round_one_radius;
	int round_one_x; //圆外接矩形左上角X坐标
	int round_one_y;//圆外接矩形左上角Y坐标
	//第二层圆形
	int round_two_radius;
	int round_two_x; //圆外接矩形左上角X坐标
	int round_two_y;//圆外接矩形左上角Y坐标
	//第三层扇形
	int round_three_radius;
	int round_three_x; //圆外接矩形左上角X坐标
	int round_three_y;//圆外接矩形左上角Y坐标
	int round_three_upset;//扇形初始角度
	int round_three_speed;//扇形摆动速率

	//第四层圆
	int round_four_radius;
	int round_four_x; //圆外接矩形左上角X坐标
	int round_four_y;//圆外接矩形左上角Y坐标
	//第五层圆
	int round_five_radius;
	int round_five_x;
	int round_five_y;
	int round_five_upset;//扇形初始角度
	int round_five_speed;//扇形摆动速率
	//第六层圆
	int round_six_radius;
	int round_six_x;
	int round_six_y;
	//第七层圆
	int round_seven_radius;
	int round_seven_x;
	int round_seven_y;
	//第八层圆
	int round_eight_radius;
	int round_eight_x;
	int round_eight_y;
	//第九层圆
	int round_nine_radius;
	int round_nine_x;
	int round_nine_y;
	int round_nine_scale_width;
	double angle_nine; //初始角度
	double round_nine_speed;//角速度

	//第十层圆形
	int round_ten_radius;
	int round_ten_x;
	int round_ten_y;
	//第十一层圆形
	int round_eleven_radius;
	int round_eleven_x;
	int round_eleven_y;
	int round_eleven_scale_width;
	double angle_eleven;
	double round_eleven_speed;//角速度
	//第十二层圆形
	int round_twelve_radius;
	int round_twelve_x;
	int round_twelve_y;
	//第十三层圆形
	int round_thirteen_radius;
	int round_thirteen_x;
	int round_thirteen_y;
	int round_thirteen_upset;//扇形初始角度
	int round_thirteen_speed;//扇形摆动速率
	//第十四层圆形
	int round_fourteen_radius;
	int round_fourteen_x;
	int round_fourteen_y;

	/*********************圆之间的间距**********************/
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

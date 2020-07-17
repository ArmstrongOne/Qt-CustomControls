//2019.7.30顾逸凡 这个控件写的时候思路比较乱 有空重新改一下
#pragma once
#include<QPainter>
#include <QColor>
#include <QLabel>
#include "SliderBar.h"

class QRoundedLabelStyleTwo :public QRoundedLabel
{
public:
	QRoundedLabelStyleTwo(QWidget *parent) :QRoundedLabel(parent)
	{
		inner_circle_radius = 0;
	}
	~QRoundedLabelStyleTwo()
	{

	}

	void SetInnerCircleProperty(int inner_circle_radius, QColor inner_circle_color)
	{
		this->inner_circle_radius = inner_circle_radius;
		this->inner_circle_color = inner_circle_color;
	}

protected:
	int inner_circle_radius;//设置内圆半径
	QColor inner_circle_color;//设置内圆背景颜色

private:
	void paintEvent(QPaintEvent* event)//重写下paintEvent函数
	{
		QPainter painter(this);
		painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
		painter.setPen(QColor(1, 1, 1, 0));

		//画背景的圆形
		painter.setBrush(back_color);
		painter.drawEllipse(0, 0, this->width(), this->height());
		//画内置圆形
		painter.setBrush(inner_circle_color);
		painter.drawEllipse(this->width()/2-inner_circle_radius,this->height()/2 - inner_circle_radius, inner_circle_radius*2,inner_circle_radius*2);

		//画文字(该空间暂时不需要，注释掉)
		//painter.setFont(label_font);
		//painter.setPen(QColor(label_font_color));
		//painter.drawText(this->rect(), Qt::AlignCenter, show_str);
		this->update();
	}
};

namespace Ui
{
	class CustomSliderStyleTwo;
}
class SLIDERBAR_EXPORT CustomSliderStyleTwo :public QWidget
{
	Q_OBJECT
public:
	CustomSliderStyleTwo(QWidget *parent = Q_NULLPTR);
	~CustomSliderStyleTwo();

	/*****************必要初始化接口*****************/
	//-----------------------滚动条主体设置-----------------------
	//设置滚动条，杆子的宽度
	void SetSliveWidth(int value);
	//设置杆子颜色以及背景颜色
	void SetBackgrondColor(QColor slive_color, QColor slider_color, QColor slive_color_bottom);
	//设置滑动条杆子到上下边的距离
	void SetTopAndBottomBlank(int top_value, int bottom_value);

	//-------------------------滑块设置----------------------------
	//设置滑块的宽和高
	void SetSliderWidgetWidthAndHeight(int width, int height);
	//设置滑块的范围
	void SetSliderRange(int min_value, int max_value);
	//设置杆子圆角程度
	void SetSliveRoundValue(int x_value, int y_value);
	//设置滑块字体，字体颜色，背景色
	void SetHanderLabelProperty(QFont font, QColor font_color, QColor back_color);
	//设置滑块圆角程度
	void SetHanderLabelRoundValue(int border_x_value, int border_y_value);
	//设置滑块内院半径颜色
	void SetInnerCircleRadiusAndColor(int radius,QColor colro);


	//-------------------------背景杆子属性设置(该类特有)----------------------------
	void SetBackgroundSliverColor(QColor back_slive_color);
	void SetBackgroundSliverWidth(int back_slive_width);
	void SetBackgroundSliverTopBottomMargin(int back_slive_top_value, int back_slive_bottom_value);
	void SetBackgroundSliverRoundValue(int back_slive_round_value_x, int back_slive_round_value_y);


	//如若改变了上述参数请调用以下函数，第一次不需要调用(因为在resize里调用了)
	void Update();
	/***********************控制接口***********************/
	void SetSliderValue(int value);


signals:
	void ValueChange(int cur_value);

private:
	Ui::CustomSliderStyleTwo *ui;
	void resizeEvent(QResizeEvent* size); //窗口大小改变事件，用于得到正确的控件长和宽
	void paintEvent(QPaintEvent* event);//用于画背景
	void MoveSlider(int value);//根据数值移动滑块

	bool eventFilter(QObject *obj, QEvent *event);
	void leaveEvent(QEvent* event);
	void mouseMoveEvent(QMouseEvent* event);

	/**********************滑块状态********************/

	enum HanderState
	{
		UnCheck_State,
		Checked_State
	};

	/********************设置背景属性*******************/
	int m_width; //整个控件宽
	int m_height;//整个控件高

	int slive_width;//滚动条，杆子的宽度

	QColor slive_color;  //杆子颜色
	QColor slive_color_bottom; //设置滑块划过的杆子颜色
	QColor slider_color;  //背景颜色

	int top_value;//设置滑动条杆子到上边界的距离
	int bottom_value;//设置滑动条杆子到下边界的距离

	int round_value_x; //杆子x轴圆角数值
	int round_value_y; //杆子y轴圆角数值

	/*******************背景杆子属性******************/ //-------------这个类特有的，就这点不同
	int back_slive_width;        //背景杆子宽度
	int back_slive_top_value;    //背景杆子到顶部距离
	int back_slive_bottom_value; //背景杆子到底部的距离
	QColor back_slive_color;   //背景杆子颜色
	int back_slive_round_value_x; //背景杆子x轴圆角数值
	int back_slive_round_value_y; //背景杆子y轴圆角数值
	/*******************设置滑块属性******************/
	QRoundedLabelStyleTwo *hander_lab;

	int wid_width;//滑块宽度
	int wid_height;//滑块高度

	int min_value;//滑块最小值
	int max_value;//滑块最大值
	int cur_value;//滑块当前值

	int hander_x_axis;//滑块固定下来的x轴
	int hander_y_dis; //滑块从最小值到最大值划过的总距离(实际上等于杆子的长度)

	double haner_y_step;//滑块移动的步长(滑块移动1个整数单位移动的像素值)

	HanderState cur_state; //滑块当前的状态
};
#pragma once

#include <QWidget>
#include "ui_CustomSlider.h"
#include "customslider_global.h"
#include <QLabel>
class CUSTOMSLIDER_EXPORT CustomSlider:public QWidget
{
	Q_OBJECT

public:
	CustomSlider(QWidget *parent = Q_NULLPTR);
	~CustomSlider();

	/*****************必要初始化接口*****************/
	//设置滚动条，杆子的宽度
	void SetSliveWidth(int value); 
	//设置杆子颜色以及背景颜色
	void SetBackgrondColor(QColor slive_color,QColor slider_color,QColor slive_color_bottom);
	//设置滑动条杆子到上下边的距离
	void SetTopAndBottomBlank(int top_value,int bottom_value);
	//设置滑块的宽和高
	void SetSliderWidgetWidthAndHeight(int width, int height);
	//设置滑块的颜色
	void SetHanderColor(QColor hander_color);
	//设置滑块的范围
	void SetSliderRange(int min_value, int max_value);
	
	//如若改变了上述参数请调用以下函数，第一次不需要调用
	void Update();
	
	/*****************非必要设置样式接口*****************/
	//Label默认关闭)
	void SetHanderLabelEnable(bool);//设置label是否可用
	void SetHanderLabelColor(QColor font_color, QColor back_color);//设置Label颜色
	void SetHanderLabelFont(QFont font);


	/*****************控制接口*****************/
	void SetSliderValue(int value);


signals:
	void ValueChange(int cur_value);


private:
	Ui::CustomSlider ui;
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



	/*******************设置滑块属性******************/
	QWidget *m_hander;
	int wid_width;//滑块宽度
	int wid_height;//滑块高度
	QColor m_hander_color;//滑块颜色

	int min_value;//滑块最小值
	int max_value;//滑块最大值
	int cur_value;//滑块当前值

	int hander_x_axis;//滑块固定下来的x轴
	int hander_y_dis; //滑块从最小值到最大值划过的总距离(实际上等于杆子的长度)

	double haner_y_step;//滑块移动的步长(滑块移动1个整数单位移动的像素值)

	HanderState cur_state; //滑块当前的状态

	/*******************滑块中的Label******************/
	QLabel *hander_lab;
	QColor label_font_color;//label字体颜色
	QColor label_back_color;//label背景颜色
	QFont label_font;//label字体
	
};

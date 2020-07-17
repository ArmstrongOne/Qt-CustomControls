//预编译
#pragma once
#include <QLabel>
#include<QPainter>
#include <QColor>
#include <QWidget>
#include"SliderBar.h"


namespace Ui
{
	class TipSlider;
}
class SLIDERBAR_EXPORT TipSlider : public QWidget
{
	Q_OBJECT

public:
	TipSlider(QWidget *parent = Q_NULLPTR);
	~TipSlider();
	enum TipSliderShowMode
	{
		Show_Left_Label,//显示左提示块
		Show_Right_Label,//显示右提示块
		Show_None_Label//不显示提示滑块
	};

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

	//-------------------------提示滑块设置----------------------------
	//设置提示滑块的宽和高
	void SetTipLabelWidthAndHeight(int tip_label_width, int tip_label_height);
	//设置提示滑块圆角程度
	void SetTipLabelRoundValue(int x_value, int y_value);
	//设置提示滑块文字背景属性
	void SetTipLabelProperty(QFont font, QColor font_color, QColor back_color);
	//设置提示滑块显示模式
	void SetShowMode(TipSliderShowMode show_mode);
	//设置提示滑块到滑块的距离以及宽度
	void SetTipLabelSpaceAndWidth(int tip_wid_pole_width,int tip_wid_pole_height);
	
	//如若改变了上述参数请调用以下函数，第一次不需要调用(因为在resize里调用了)
	void Update();
	/***********************控制接口***********************/
	void SetSliderValue(int value);

signals:
	void ValueChange(int cur_value);

private:
	Ui::TipSlider *ui;
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

	int round_value_x; //滑块x轴圆角数值
	int round_value_y; //滑块y轴圆角数值

	 /*******************设置滑块属性******************/
	QRoundedLabel *hander_lab;

	int wid_width;//滑块宽度
	int wid_height;//滑块高度

	int min_value;//滑块最小值
	int max_value;//滑块最大值
	int cur_value;//滑块当前值

	int hander_x_axis;//滑块固定下来的x轴
	int hander_y_dis; //滑块从最小值到最大值划过的总距离(实际上等于杆子的长度)

	double haner_y_step;//滑块移动的步长(滑块移动1个整数单位移动的像素值)

	HanderState cur_state; //滑块当前的状态

	/*******************提示滑块属性设置******************/
	QRoundedLabel *tip_lab;

	int tip_wid_width;//提示滑块宽
	int tip_wid_height;//提示滑块高

	//提示滑块到滑块中间的杆子
	int tip_wid_pole_width;//杆子宽度
	int tip_wid_pole_height;//杆子高度

	int tip_wid_x; //提示滑块x坐标
	TipSliderShowMode tip_slider_show_mode;
};

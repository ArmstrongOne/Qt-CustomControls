/***************************环形进度条************************/
#pragma once
#include <QWidget>
#include<QLabel>
#include "ProgressBar.h"

namespace Ui
{
	class RingProgressBar;
}

class PROGRESSBAR_EXPORT RingProgressBar : public QWidget
{
	Q_OBJECT

public:
	RingProgressBar(QWidget *parent = Q_NULLPTR);
	~RingProgressBar();
	/******************接口************************/
	void SetPanColor(QColor unselected_color, QColor selected_color);//设置未选择的颜色和选择后的颜色

	void SetInsideCircleRadius(int radius); //设置内部圆半径
	void SetInsideCircleColor(QColor color); //设置内部圆颜色
	void SetBlankLength(int value); //设置圆环到两边的间距

	void Update();//设置完 调用该函数
	/*****************控制接口*****************/
	void SetPanValue(int value);
	void SetPanLabelColor(QColor font_color, QColor back_color);//设置Label颜色
	void SetPanLabelFont(QFont font);

private:
	Ui::RingProgressBar *ui;
	void paintEvent(QPaintEvent* event);//用于画背景
	void resizeEvent(QResizeEvent* size); //窗口大小改变事件，用于得到正确的控件长和宽

 /***************设置圆盘属性**********************/
	QColor unselected_color; //未选择的颜色(初始颜色)
	QColor selected_color; //选中的颜色(指针划过的颜色)
	QColor in_cir_color;//内部圆颜色

	int m_width_out_cir; //外部圆宽
	int m_height_out_cir;//外部圆高
	int m_radius_out_cir;//外部圆的半径

	int m_width_mid_cir; //中部圆宽
	int m_height_mid_cir;//中部圆高
	int m_radius_mid_cir;//中部圆的半径

	int m_width_in_cir; //内部圆宽
	int m_height_in_cir;//内部圆高
	int m_radius_in_cir;//内部圆的半径

	int blank_value; //圆环到两边的空格距离;

	int cur_value;//圆盘的当前值 范围默认是0-100

	/***************设置Label属性**********************/
	QLabel *text_label;
	QColor label_font_color;//label字体颜色
	QColor label_back_color;//label背景颜色
	QFont label_font;//label字体
};

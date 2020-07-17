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
	/******************接口************************/
	void SetPanColor(QColor unselected_color,QColor selected_color);//设置未选择的颜色和选择后的颜色

	void Update();//设置完 调用该函数
	/*****************控制接口*****************/
	void SetPanValue(int value);
	void SetPanLabelColor(QColor font_color, QColor back_color);//设置Label颜色
	void SetPanLabelFont(QFont font);
	

private:
	Ui::DashBoard ui;
	void paintEvent(QPaintEvent* event);//用于画背景
	void resizeEvent(QResizeEvent* size); //窗口大小改变事件，用于得到正确的控件长和宽

	/***************设置圆盘属性**********************/
	QColor unselected_color; //未选择的颜色(初始颜色)
	QColor selected_color; //选中的颜色(指针划过的颜色)

	int m_width; //整个控件宽
	int m_height;//整个控件高
	int m_radius;//圆的半径

	int cur_value;//圆盘的当前值 范围默认是0-100

	/***************设置Label属性**********************/
	QLabel *text_label;
	QColor label_font_color;//label字体颜色
	QColor label_back_color;//label背景颜色
	QFont label_font;//label字体
};

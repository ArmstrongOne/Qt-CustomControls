/**************************竖直长条进度条*************************/
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
	void SetMargin(int m_margin_left,int m_margin_right,int m_margin_top,int m_margin_bottom); //设置控件到四周的距离
	void SetSpace(int value);//设置滚动条和lab框的距离
	void SetProgressbarHeight(int value);//滚动条总高
	void SetProgressBarColor(QColor background_color, QColor selected_color);
	void SetLabelProperty(QColor font_color, QColor font_background_color, QFont font);
	void SetBorderRadius(int progressbar_border_radius_x,int progressbar_border_radius_y,int label_border_radius_x,int label_border_radius_y);//设置圆角矩形 圆角值(0-99);
	//这个类就不需要update 因为所有参数都是通过painter时时刷新的

	void SetPanValue(int value);

private:
	Ui::RectProgressBar *ui;

	void paintEvent(QPaintEvent* event);//用于画背景
	void resizeEvent(QResizeEvent* size); //窗口大小改变事件，用于得到正确的控件长和宽

	//和之前不一样 将信息存入至QRect，优化代码
	QRect lab_rect;//lab框的大小
	QRect progressbar_rect;//完整滚动条子的大小
	QRect selected_rect; //已经选择的矩形大小

	QColor background_color; //背景颜色
	QColor selected_color; //滚动条选中色
	
	QColor font_color; //百分比字体颜色
	QColor label_background_color; //文字背景颜色
	QFont font; //文字字体

	int progressbar_border_radius_x;//滚动条圆角矩形 圆角x值
	int progressbar_border_radius_y;//滚动条圆角矩形 圆角y值

	int label_border_radius_x;//label圆角矩形 圆角x值
	int label_border_radius_y;//label圆角矩形 圆角y值


	int m_margin_left;   //控件到左边距离
	int m_margin_right;  //控件到右边距离
	int m_margin_top;    //控件到顶部距离
	int m_margin_bottom; //控件到底边距离

	int space; //文字框到滚动条间距
	int progressbar_height; //需要确定一个滚动条的总长度


	int cur_value;
};

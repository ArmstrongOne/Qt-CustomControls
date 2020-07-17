#pragma once
/***********************水波进度条*********************************/
//gyf  2019.7.4
#include <QWidget>
#include <QLabel>
#include "ProgressBar.h"

namespace Ui
{
	class WaveProgressBar;
}

class PROGRESSBAR_EXPORT WaveProgressBar : public QWidget
{
	Q_OBJECT

public:
	WaveProgressBar(QWidget *parent = Q_NULLPTR);
	~WaveProgressBar();
	/**********************接口************************/
	void SetPanColor(QColor background_color, QColor border_color);//设置未选择的颜色和选择后的颜色
	void SetWaveColor(QColor front_wave_color, QColor behind_wave_color);//设置水波颜色
	void SetBorderWidth(int value);//设置边框长度
	void SetWaveProperty(int density, double m_waterHeight, double offset);

	void Update();//设置完 调用该函数
	/***********************控制接口***********************/
	void SetPanValue(int value);
	void SetPanLabelColor(QColor font_color, QColor back_color);//设置Label颜色
	void SetPanLabelFont(QFont font);

private:
	Ui::WaveProgressBar *ui;
	void paintEvent(QPaintEvent* event);//用于画背景
	void resizeEvent(QResizeEvent* size); //窗口大小改变事件，用于得到正确的控件长和宽

	/***************设置圆盘属性**********************/
	QColor background_color; //圆盘背景颜色
	QColor border_color; //圆盘边框颜色(外部圆颜色)

	//如果边框为0 则内部圆和外部圆大小相等
	int m_width_out_cir; //外部圆宽
	int m_height_out_cir;//外部圆高
	int m_radius_out_cir;//外部圆半径

	int m_width_in_cir; //内部圆宽
	int m_height_in_cir;//内部圆高
	int m_radius_in_cir;//内部圆半径
	QRect in_cir_rect;//内部圆外界矩形

	int border_width;//边框宽

	int cur_value;//圆盘的当前值 范围默认是0-100

	/********************水波参数*********************/
	QColor front_wave_color;
	QColor behind_wave_color;

	int m_waterDensity; // 水波的密度 影响出现的波动数
	double m_waterHeight;//水波振幅 0-1之间 要乘高度
	double m_init_offset;//初始偏移值，无需设置
	double m_offset; //偏移值，屏幕刷新一次水波偏移量
	/***************设置Label属性**********************/
	QLabel *text_label;
	QColor label_font_color;//label字体颜色
	QColor label_back_color;//label背景颜色
	QFont label_font;//label字体
};


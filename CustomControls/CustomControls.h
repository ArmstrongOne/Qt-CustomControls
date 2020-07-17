/**************Tom开始写于2019.7.1******************/
#pragma once
#include <QtWidgets/QWidget>
#include<map>
#include <QLabel>
#include<QPropertyAnimation>
#include"TriangleLabWidget.h"
#include"all_controls_header.h"
#include <QChart>
QT_CHARTS_USE_NAMESPACE
#include "ui_CustomControls.h"
using namespace std;
class CustomControls : public QWidget
{
	Q_OBJECT

public:
	CustomControls(QWidget *parent = Q_NULLPTR);
	virtual~CustomControls();
	CustomControls(CustomControls&)=delete;
	CustomControls&operator=(CustomControls&)=delete;

private:
	Ui::CustomControlsClass ui;

	enum TabIndex
	{
		ProgressBarIndex,//进度条
		SliderBarIndex, //滑动条
		PanelIndex,//仪表盘
		QwtIndex,//qwt
		Animation,//动画
		Otherbutton,//其他按钮
		CustomWin,//软件窗口
		NoChecked = -1//无选择标签
	};

	void InitUi(); //构造函数初始化UI设置
	void resizeEvent(QResizeEvent* size); //窗口大小改变事件，用于得到正确的控件长和宽
	void showEvent(QShowEvent *event);

	//动画设置执行 index 0：左标记wid 1:右标记:2中标记  wid
	void StartAnimation(int index, QRect start_rect, QRect end_rect);

	//在指定标签上显示
	void ShowRect(TabIndex now_index);
	//从Map中获取对应的value
	QRect GetRectFromMap(map<TabIndex, QRect>left_rect_map, TabIndex);


	/*************标记widget设置*************/
	QWidget *left_mark_wid; //左右两个选择标记wid
	TriangleLabWidget *right_mark_wid;
	QLabel *middle_mark_wid;//中间滑块

	QPropertyAnimation* animation_left;//左标记动画类
	QPropertyAnimation* animation_right;//右标记动画类
	QPropertyAnimation*animation_middle;//中间滑块类

	TabIndex checked_index;//标记已经选择的标签

	int left_mark_wid_x; //左标记x坐标
	int right_mark_wid_x; //右标记x坐标
	int middle_mark_wid_x;//中间滑块x坐标

	int left_mark_width; //左标记宽
	int left_mark_height; //左标记高

	int right_mark_width; //右标记宽
	int right_mark_height; //右标记高

	int middle_mark_width; //中间标记宽
	int middle_mark_height; //中间标记高

	//左右两组标记rect的map容器 第一个参数是标签数值
 	map<TabIndex, QRect>left_rect_map;
	map<TabIndex, QRect>right_rect_map;
	map<TabIndex, QRect>middle_rect_map;

private slots:
	//按钮槽函数
	void                  on_progressbar_btn_clicked();
	void                  on_sliderbar_btn_clicked();
	void                  on_panel_btn_clicked();
	void                  on_qwt_btn_clicked();
	void                  on_animation_btn_clicked();
	void                  on_otherbutton_btn_clicked();
	void                  on_custom_win_btn_clicked();

	void                  SetProgressValue(int value);//设置进度条的数值
	void                  SetPanelValue(int value);//设置仪表盘数值
    /***************所有控件指针以及有关系的槽函数***************/
private:
	void                  SetAllControls();//设置所有的控件
	/***************进度条***************/
	DashBoard*            dash_board;
	void                  SetDashBoard();
	RingProgressBar*      ring_progressbar;
	void                  SetRingProgressBar();
	LinearProgressBar*    linear_progressbar;
	void                  SetLinearProgressBar();
	WaveProgressBar*      wave_progressbar;
	void                  SetWaveProgressBar();
	RectWaveProgressBar*  rect_wave_progressbar;
	void                  SetRectWaveProgressBar();
	RectProgressBar*      rect_progressbar;
	void                  SetRectProgressBar();
	/***************滑动条***************/
	CustomSlider*         custom_slider;
	void                  SetCustomSlider();
	DoubleHandleSlider*   double_handle_slider;
	void                  SetDoubleHandleSlider();
	TipSlider*            tip_slider;
	void                  SetTipSlider();
	StripSlider*          strip_slider;
	void                  SetStripSlider();
	CustomSliderStyleOne* custom_slider_style_one;
	void                  SetCustomSliderStyleOne();
	CustomSliderStyleTwo* custom_slider_style_two;
	void                  SetCustomSliderStyleTwo();
	StripSliderStyleOne*  strip_slider_style_one;
	void                  SetStripSliderStyleOne();
	StripSliderStyleTwo*  strip_slider_style_two;
	void                  SetStripSliderStyleTwo();
	/***************图表***************/
	HandleLineChart*      handle_line_chart;
	void                  SetHandleLineChart();
	HandlePieChart*       handle_pie_chart;
	void                  SetHandlePieChart();
	HandleScatterChart*   handle_scatter_chart;
	void                  SetHandleScatterChart();
	HandleBarChart*       handle_bar_chart;
	void                  SetHandleBarChart();
	/***************仪表盘***************/
	CustomPanel*          custom_panel;
	void                  SetCustomPanel();
	NetSpeedPanel*        netspeed_panel;
	void                  SetNetSpeedPanel();
	SemiCirclePanel*      semicircle_panel;
	void                  SetSemiCirclePanel();
	/***************动画***************/
	RXTurnPan*            turn_pan;
	void                  SetRXTurnPan();
	/***************其他按钮图***************/
	DropDownMenu*         drop_menu;
	void                  SetDropDownMenu();
	RXDateSelectPage*     date_select_page;
	void                  SetDateSelectPage();
	/***************精致窗口***************/
	LoginWin*             chat_login_win;
	void                  SetChatLoginWin();
	RXTools*              tools_win;
	void                  SetToolsWin();
};

/**************Tom��ʼд��2019.7.1******************/
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
		ProgressBarIndex,//������
		SliderBarIndex, //������
		PanelIndex,//�Ǳ���
		QwtIndex,//qwt
		Animation,//����
		Otherbutton,//������ť
		CustomWin,//�������
		NoChecked = -1//��ѡ���ǩ
	};

	void InitUi(); //���캯����ʼ��UI����
	void resizeEvent(QResizeEvent* size); //���ڴ�С�ı��¼������ڵõ���ȷ�Ŀؼ����Ϳ�
	void showEvent(QShowEvent *event);

	//��������ִ�� index 0������wid 1:�ұ��:2�б��  wid
	void StartAnimation(int index, QRect start_rect, QRect end_rect);

	//��ָ����ǩ����ʾ
	void ShowRect(TabIndex now_index);
	//��Map�л�ȡ��Ӧ��value
	QRect GetRectFromMap(map<TabIndex, QRect>left_rect_map, TabIndex);


	/*************���widget����*************/
	QWidget *left_mark_wid; //��������ѡ����wid
	TriangleLabWidget *right_mark_wid;
	QLabel *middle_mark_wid;//�м们��

	QPropertyAnimation* animation_left;//���Ƕ�����
	QPropertyAnimation* animation_right;//�ұ�Ƕ�����
	QPropertyAnimation*animation_middle;//�м们����

	TabIndex checked_index;//����Ѿ�ѡ��ı�ǩ

	int left_mark_wid_x; //����x����
	int right_mark_wid_x; //�ұ��x����
	int middle_mark_wid_x;//�м们��x����

	int left_mark_width; //���ǿ�
	int left_mark_height; //���Ǹ�

	int right_mark_width; //�ұ�ǿ�
	int right_mark_height; //�ұ�Ǹ�

	int middle_mark_width; //�м��ǿ�
	int middle_mark_height; //�м��Ǹ�

	//����������rect��map���� ��һ�������Ǳ�ǩ��ֵ
 	map<TabIndex, QRect>left_rect_map;
	map<TabIndex, QRect>right_rect_map;
	map<TabIndex, QRect>middle_rect_map;

private slots:
	//��ť�ۺ���
	void                  on_progressbar_btn_clicked();
	void                  on_sliderbar_btn_clicked();
	void                  on_panel_btn_clicked();
	void                  on_qwt_btn_clicked();
	void                  on_animation_btn_clicked();
	void                  on_otherbutton_btn_clicked();
	void                  on_custom_win_btn_clicked();

	void                  SetProgressValue(int value);//���ý���������ֵ
	void                  SetPanelValue(int value);//�����Ǳ�����ֵ
    /***************���пؼ�ָ���Լ��й�ϵ�Ĳۺ���***************/
private:
	void                  SetAllControls();//�������еĿؼ�
	/***************������***************/
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
	/***************������***************/
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
	/***************ͼ��***************/
	HandleLineChart*      handle_line_chart;
	void                  SetHandleLineChart();
	HandlePieChart*       handle_pie_chart;
	void                  SetHandlePieChart();
	HandleScatterChart*   handle_scatter_chart;
	void                  SetHandleScatterChart();
	HandleBarChart*       handle_bar_chart;
	void                  SetHandleBarChart();
	/***************�Ǳ���***************/
	CustomPanel*          custom_panel;
	void                  SetCustomPanel();
	NetSpeedPanel*        netspeed_panel;
	void                  SetNetSpeedPanel();
	SemiCirclePanel*      semicircle_panel;
	void                  SetSemiCirclePanel();
	/***************����***************/
	RXTurnPan*            turn_pan;
	void                  SetRXTurnPan();
	/***************������ťͼ***************/
	DropDownMenu*         drop_menu;
	void                  SetDropDownMenu();
	RXDateSelectPage*     date_select_page;
	void                  SetDateSelectPage();
	/***************���´���***************/
	LoginWin*             chat_login_win;
	void                  SetChatLoginWin();
	RXTools*              tools_win;
	void                  SetToolsWin();
};

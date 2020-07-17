#include "CustomControls.h"
#include <QDebug>
#include<qmath.h>
#pragma execution_character_set("utf-8")
CustomControls::CustomControls(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	InitUi();

	//初始化类变量
	left_mark_wid_x = 0;
	right_mark_wid_x = 0;
	middle_mark_wid_x = 0;

	left_mark_width = 0;
	left_mark_height = 0;

	right_mark_width = 0;
	right_mark_height = 0;

	middle_mark_width = 0;
	middle_mark_height = 0;

	left_rect_map.clear();
	right_rect_map.clear();
    middle_rect_map.clear();

	//初次选择状态设置为无选择
	checked_index = NoChecked;

	//动画类
	animation_left = new QPropertyAnimation(left_mark_wid,"pos");
	animation_right = new QPropertyAnimation(right_mark_wid, "pos");
	animation_middle = new QPropertyAnimation(middle_mark_wid, "pos");

	//切到欢迎页面
	int index = ui.main_tab_wid->count();
	ui.main_tab_wid->setCurrentIndex(index-1);

	//设置所有控件
	SetAllControls();

	ui.progress_slider->setValue(61);
}

CustomControls::~CustomControls()
{

}

void CustomControls::InitUi()
{
	//隐藏QTabWidget 页标签
	for (int i = 0; i < ui.main_tab_wid->findChildren<QTabBar*>().size(); i++)
	{
		ui.main_tab_wid->findChildren<QTabBar*>().at(i)->hide();
	}

	//设置两个标记widget
	left_mark_wid = new QWidget(ui.left_mark_wid);
	right_mark_wid=new TriangleLabWidget(ui.right_mark_wid);
	middle_mark_wid = new QLabel(this);

	QPalette pa_left;
	pa_left.setColor(QPalette::Window, QColor(0, 187, 158));
	QPalette pa_right;
	pa_right.setColor(QPalette::Window, QColor(20, 20, 20));

	QPalette pa_middle;
	pa_middle.setColor(QPalette::Window, QColor(20, 20, 20));
	pa_middle.setColor(QPalette::WindowText, QColor(255, 255, 255));
	
	QFont font_middle;
	font_middle.setFamily(QString::fromUtf8("宋体"));
	font_middle.setPixelSize(14);
	
	middle_mark_wid->setFont(font_middle);
	middle_mark_wid->setAlignment(Qt::AlignCenter);
	middle_mark_wid->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	left_mark_wid->setAutoFillBackground(true);
	right_mark_wid->setAutoFillBackground(true);
	middle_mark_wid->setAutoFillBackground(true);

	left_mark_wid->setPalette(pa_left);
	right_mark_wid->setPalette(pa_right);
	middle_mark_wid->setPalette(pa_middle);

	left_mark_wid->hide();
	right_mark_wid->hide();
	middle_mark_wid->hide();
}

void CustomControls::resizeEvent(QResizeEvent* size)
{

}

void CustomControls::showEvent(QShowEvent *event)
{
	//获取标记左中右wid长和宽
	left_mark_width = ui.left_mark_wid->width();
	left_mark_height = ui.progressbar_btn->height();

	right_mark_width = ui.right_mark_wid->width();
	right_mark_height = ui.progressbar_btn->height();

	middle_mark_width=ui.progressbar_btn->width();
	middle_mark_height= ui.progressbar_btn->height();


	//获取左标记和右标记x轴
	left_mark_wid_x = 0;
	right_mark_wid_x =0;
	middle_mark_wid_x= ui.left_mark_wid->width(); //比较特殊，因为父窗口是外层类，坐标不从0开始算

	left_mark_wid->resize(left_mark_width, left_mark_height);
	right_mark_wid->resize(right_mark_width, right_mark_height);
	middle_mark_wid->resize(middle_mark_width, middle_mark_height);

	//向左中右标签map中插入信息
	int num = ui.navigation_wid->layout()->count();
	qDebug() << num;
	QGridLayout *grid_layout = static_cast<QGridLayout*>(ui.navigation_wid->layout());
	for (int i = 0; i < num-1; i++)
	{
		//左rect
		int left_rect_x = left_mark_wid_x;
		int left_rect_y = grid_layout->cellRect(i, 0).y();
		int left_rect_width = left_mark_width;
		int left_rect_height = grid_layout->cellRect(i, 0).height();
		QRect rect_left(left_rect_x, left_rect_y, left_rect_width, left_rect_height);

		//右rect
		int right_rect_x = right_mark_wid_x;
		int right_rect_y = grid_layout->cellRect(i, 0).y();
		int right_rect_width = right_mark_width;
		int right_rect_height = grid_layout->cellRect(i, 0).height();
		QRect rect_right(right_rect_x, right_rect_y, right_rect_width, right_rect_height);

		//中rect
		int middle_rect_x = middle_mark_wid_x;
		int middle_rect_y = grid_layout->cellRect(i, 0).y();
		int middle_rect_width = middle_mark_width;
		int middle_rect_height = grid_layout->cellRect(i, 0).height();
		QRect rect_middle(middle_rect_x, middle_rect_y, middle_rect_width, middle_rect_height);

		left_rect_map.insert(pair<TabIndex,QRect>((TabIndex)i, rect_left));
		right_rect_map.insert(pair<TabIndex, QRect>((TabIndex)i, rect_right));
		middle_rect_map.insert(pair<TabIndex, QRect>((TabIndex)i, rect_middle));
	}
}

void CustomControls::StartAnimation(int index, QRect start_rect, QRect end_rect)
{
	if (index == 0)
	{
		animation_left->setDuration(300);
		animation_left->setStartValue(QPoint(start_rect.x(),start_rect.y()));
		animation_left->setEndValue(QPoint(end_rect.x(), end_rect.y()));
		animation_left->setEasingCurve(QEasingCurve::InOutQuad);
		animation_left->start(QAbstractAnimation::KeepWhenStopped);
	}
	else if(index == 1)
	{
		animation_right->setDuration(300);
		animation_right->setStartValue(QPoint(start_rect.x(), start_rect.y()));
		animation_right->setEndValue(QPoint(end_rect.x(), end_rect.y()));
		animation_right->setEasingCurve(QEasingCurve::InOutQuad);
		animation_right->start(QAbstractAnimation::KeepWhenStopped);
	}
	else if (index == 2)
	{
		animation_middle->setDuration(300);
		animation_middle->setStartValue(QPoint(start_rect.x(), start_rect.y()));
		animation_middle->setEndValue(QPoint(end_rect.x(), end_rect.y()));
		animation_middle->setEasingCurve(QEasingCurve::InOutQuad);
		animation_middle->start(QAbstractAnimation::KeepWhenStopped);
	}
}

void CustomControls::ShowRect(TabIndex now_index)
{
	//左标记rect
	QRect left_rect = GetRectFromMap(left_rect_map, now_index);
	left_mark_wid->move(0, left_rect.y());
	left_mark_wid->show();

	//右标记rect
	QRect right_rect= GetRectFromMap(right_rect_map, now_index);
	right_mark_wid->move(0, right_rect.y());
	right_mark_wid->show();

	//中标记
	QRect middle_rect = GetRectFromMap(middle_rect_map, now_index);
	middle_mark_wid->move(middle_rect.x(), middle_rect.y());
	middle_mark_wid->show();
}

QRect CustomControls::GetRectFromMap(map<TabIndex, QRect>left_rect_map, TabIndex index)
{
	QRect rect;
	map<TabIndex, QRect>::iterator iter;
	iter = left_rect_map.find(index);
	if (iter != left_rect_map.end())
	{
		rect = iter->second;
	}
	return rect;
}

void CustomControls::on_progressbar_btn_clicked()
{
	if (checked_index == -1)
	{
		ShowRect(ProgressBarIndex);
		middle_mark_wid->setText(QString::fromUtf8("进度条"));
		ui.main_tab_wid->setCurrentIndex(ProgressBarIndex);
		checked_index = ProgressBarIndex;
		return;
	}

	QRect left_rect_end = GetRectFromMap(left_rect_map, ProgressBarIndex);
	QRect right_rect_end = GetRectFromMap(right_rect_map, ProgressBarIndex);
	QRect middle_rect_end= GetRectFromMap(middle_rect_map, ProgressBarIndex);

	QRect left_rect_start= GetRectFromMap(left_rect_map, checked_index);
	QRect right_rect_start = GetRectFromMap(right_rect_map, checked_index);
	QRect middle_rect_start = GetRectFromMap(middle_rect_map, checked_index);

	//改变至对应的大小
	left_mark_wid->resize(left_rect_end.width(), left_rect_end.height());
	right_mark_wid->resize(right_rect_end.width(), right_rect_end.height());
	middle_mark_wid->resize(middle_rect_end.width(), middle_rect_end.height());

	StartAnimation(0, left_rect_start, left_rect_end);
	StartAnimation(1, right_rect_start, right_rect_end);
	StartAnimation(2, middle_rect_start, middle_rect_end);


	middle_mark_wid->setText(QString::fromUtf8("进度条"));
	
	ui.main_tab_wid->setCurrentIndex(ProgressBarIndex);
	checked_index = ProgressBarIndex;
}

void CustomControls::on_sliderbar_btn_clicked()
{
	if (checked_index == -1)
	{
		ShowRect(SliderBarIndex);
		middle_mark_wid->setText(QString::fromUtf8("滑动条"));
		ui.main_tab_wid->setCurrentIndex(SliderBarIndex);
		checked_index = SliderBarIndex;
		return;
	}
	QRect left_rect_end = GetRectFromMap(left_rect_map, SliderBarIndex);
	QRect right_rect_end = GetRectFromMap(right_rect_map, SliderBarIndex);
	QRect middle_rect_end = GetRectFromMap(middle_rect_map, SliderBarIndex);

	QRect left_rect_start = GetRectFromMap(left_rect_map, checked_index);
	QRect right_rect_start = GetRectFromMap(right_rect_map, checked_index);
	QRect middle_rect_start = GetRectFromMap(middle_rect_map, checked_index);

	//改变至对应的大小
	left_mark_wid->resize(left_rect_end.width(), left_rect_end.height());
	right_mark_wid->resize(right_rect_end.width(), right_rect_end.height());
	middle_mark_wid->resize(middle_rect_end.width(), middle_rect_end.height());

	StartAnimation(0, left_rect_start, left_rect_end);
	StartAnimation(1, right_rect_start, right_rect_end);
	StartAnimation(2, middle_rect_start, middle_rect_end);

	middle_mark_wid->setText(QString::fromUtf8("滑动条"));

	ui.main_tab_wid->setCurrentIndex(SliderBarIndex);
	checked_index = SliderBarIndex;
}

void CustomControls::on_panel_btn_clicked()
{
	if (checked_index == -1)
	{
		ShowRect(PanelIndex);
		middle_mark_wid->setText(QString::fromUtf8("仪表盘"));
		ui.main_tab_wid->setCurrentIndex(PanelIndex);
		checked_index = PanelIndex;
		return;
	}

	QRect left_rect_end = GetRectFromMap(left_rect_map, PanelIndex);
	QRect right_rect_end = GetRectFromMap(right_rect_map, PanelIndex);
	QRect middle_rect_end = GetRectFromMap(middle_rect_map, PanelIndex);

	QRect left_rect_start = GetRectFromMap(left_rect_map, checked_index);
	QRect right_rect_start = GetRectFromMap(right_rect_map, checked_index);
	QRect middle_rect_start = GetRectFromMap(middle_rect_map, checked_index);

	//改变至对应的大小
	left_mark_wid->resize(left_rect_end.width(), left_rect_end.height());
	right_mark_wid->resize(right_rect_end.width(), right_rect_end.height());
	middle_mark_wid->resize(middle_rect_end.width(), middle_rect_end.height());

	StartAnimation(0, left_rect_start, left_rect_end);
	StartAnimation(1, right_rect_start, right_rect_end);
	StartAnimation(2, middle_rect_start, middle_rect_end);

	middle_mark_wid->setText(QString::fromUtf8("仪表盘"));

	ui.main_tab_wid->setCurrentIndex(PanelIndex);
	checked_index = PanelIndex;
}

void CustomControls::on_qwt_btn_clicked()
{
	if (checked_index == -1)
	{
		ShowRect(QwtIndex);
		middle_mark_wid->setText(QString::fromUtf8("统计图"));
		ui.main_tab_wid->setCurrentIndex(QwtIndex);
		checked_index = QwtIndex;
		return;
	}

	QRect left_rect_end = GetRectFromMap(left_rect_map, QwtIndex);
	QRect right_rect_end = GetRectFromMap(right_rect_map, QwtIndex);
	QRect middle_rect_end = GetRectFromMap(middle_rect_map, QwtIndex);

	QRect left_rect_start = GetRectFromMap(left_rect_map, checked_index);
	QRect right_rect_start = GetRectFromMap(right_rect_map, checked_index);
	QRect middle_rect_start = GetRectFromMap(middle_rect_map, checked_index);

	//改变至对应的大小
	left_mark_wid->resize(left_rect_end.width(), left_rect_end.height());
	right_mark_wid->resize(right_rect_end.width(), right_rect_end.height());
	middle_mark_wid->resize(middle_rect_end.width(), middle_rect_end.height());

	StartAnimation(0, left_rect_start, left_rect_end);
	StartAnimation(1, right_rect_start, right_rect_end);
	StartAnimation(2, middle_rect_start, middle_rect_end);

	middle_mark_wid->setText(QString::fromUtf8("统计图"));
	ui.main_tab_wid->setCurrentIndex(QwtIndex);
	checked_index = QwtIndex;
}

void CustomControls::on_animation_btn_clicked()
{
	if (checked_index == -1)
	{
		ShowRect(Animation);
		middle_mark_wid->setText(QString::fromUtf8("动画"));
		ui.main_tab_wid->setCurrentIndex(Animation);
		checked_index = Animation;
		return;
	}

	QRect left_rect_end = GetRectFromMap(left_rect_map, Animation);
	QRect right_rect_end = GetRectFromMap(right_rect_map, Animation);
	QRect middle_rect_end = GetRectFromMap(middle_rect_map, Animation);

	QRect left_rect_start = GetRectFromMap(left_rect_map, checked_index);
	QRect right_rect_start = GetRectFromMap(right_rect_map, checked_index);
	QRect middle_rect_start = GetRectFromMap(middle_rect_map, checked_index);

	//改变至对应的大小
	left_mark_wid->resize(left_rect_end.width(), left_rect_end.height());
	right_mark_wid->resize(right_rect_end.width(), right_rect_end.height());
	middle_mark_wid->resize(middle_rect_end.width(), middle_rect_end.height());

	StartAnimation(0, left_rect_start, left_rect_end);
	StartAnimation(1, right_rect_start, right_rect_end);
	StartAnimation(2, middle_rect_start, middle_rect_end);

	middle_mark_wid->setText(QString::fromUtf8("动画"));
	ui.main_tab_wid->setCurrentIndex(Animation);
	checked_index = Animation;
}

void CustomControls::on_otherbutton_btn_clicked()
{
	if (checked_index == -1)
	{
		ShowRect(Otherbutton);
		middle_mark_wid->setText(QString::fromUtf8("按钮"));
		ui.main_tab_wid->setCurrentIndex(Otherbutton);
		checked_index = Otherbutton;
		return;
	}

	QRect left_rect_end = GetRectFromMap(left_rect_map, Otherbutton);
	QRect right_rect_end = GetRectFromMap(right_rect_map, Otherbutton);
	QRect middle_rect_end = GetRectFromMap(middle_rect_map, Otherbutton);

	QRect left_rect_start = GetRectFromMap(left_rect_map, checked_index);
	QRect right_rect_start = GetRectFromMap(right_rect_map, checked_index);
	QRect middle_rect_start = GetRectFromMap(middle_rect_map, checked_index);

	//改变至对应的大小
	left_mark_wid->resize(left_rect_end.width(), left_rect_end.height());
	right_mark_wid->resize(right_rect_end.width(), right_rect_end.height());
	middle_mark_wid->resize(middle_rect_end.width(), middle_rect_end.height());

	StartAnimation(0, left_rect_start, left_rect_end);
	StartAnimation(1, right_rect_start, right_rect_end);
	StartAnimation(2, middle_rect_start, middle_rect_end);

	middle_mark_wid->setText(QString::fromUtf8("按钮"));

	ui.main_tab_wid->setCurrentIndex(Otherbutton);
	checked_index = Otherbutton;
}

void CustomControls::on_custom_win_btn_clicked()
{
	if (checked_index == -1)
	{
		ShowRect(CustomWin);
		middle_mark_wid->setText(QString::fromUtf8("软件页面"));
		ui.main_tab_wid->setCurrentIndex(CustomWin);
		checked_index = CustomWin;
		return;
	}

	QRect left_rect_end = GetRectFromMap(left_rect_map, CustomWin);
	QRect right_rect_end = GetRectFromMap(right_rect_map, CustomWin);
	QRect middle_rect_end = GetRectFromMap(middle_rect_map, CustomWin);

	QRect left_rect_start = GetRectFromMap(left_rect_map, checked_index);
	QRect right_rect_start = GetRectFromMap(right_rect_map, checked_index);
	QRect middle_rect_start = GetRectFromMap(middle_rect_map, checked_index);

	//改变至对应的大小
	left_mark_wid->resize(left_rect_end.width(), left_rect_end.height());
	right_mark_wid->resize(right_rect_end.width(), right_rect_end.height());
	middle_mark_wid->resize(middle_rect_end.width(), middle_rect_end.height());

	StartAnimation(0, left_rect_start, left_rect_end);
	StartAnimation(1, right_rect_start, right_rect_end);
	StartAnimation(2, middle_rect_start, middle_rect_end);

	middle_mark_wid->setText(QString::fromUtf8("软件页面"));

	ui.main_tab_wid->setCurrentIndex(CustomWin);
	checked_index = CustomWin;
}

/*********************Setting**********************/
void CustomControls::SetAllControls()
{
	/***************进度条***************/
	connect(ui.progress_slider, SIGNAL(valueChanged(int)), this, SLOT(SetProgressValue(int)));

	SetDashBoard();
	SetRingProgressBar();
	SetLinearProgressBar();
	SetRectProgressBar();
	SetWaveProgressBar();
	SetRectWaveProgressBar();
	/***************滑动条***************/
	 SetCustomSlider();
	 SetDoubleHandleSlider();
	 SetTipSlider();
	 SetStripSlider();
	 SetCustomSliderStyleOne();
	 SetCustomSliderStyleTwo();
	 SetStripSliderStyleOne();
	 SetStripSliderStyleTwo();
	/***************仪表盘***************/
	 connect(ui.panel_slider, SIGNAL(valueChanged(int)), this, SLOT(SetPanelValue(int)));
	 SetCustomPanel();
	SetNetSpeedPanel();
	 SetSemiCirclePanel();


	/***************图表***************/
	 SetHandleLineChart();
	 SetHandlePieChart();
	 SetHandleScatterChart();
	 SetHandleBarChart();


	/***************动画***************/
	 SetRXTurnPan();



	 /***************按钮***************/
	 SetDropDownMenu();
	 SetDateSelectPage();

	 /***************其他窗口***************/
	 SetChatLoginWin();
	 SetToolsWin();

}

void CustomControls::SetCustomSlider()
{
	custom_slider = ui.custom_slider;
	custom_slider->SetSliveWidth(15);
	custom_slider->SetBackgrondColor(QColor(70, 70, 70), QColor(240, 240, 240,0), QColor(24, 189, 155));
	custom_slider->SetTopAndBottomBlank(15, 15);
	custom_slider->SetSliderWidgetWidthAndHeight(50,30);
	custom_slider->SetSliderRange(0, 100);
	custom_slider->SetSliveRoundValue(15, 10);

	QFont font;
	font.setFamily(QString::fromUtf8("楷体"));
	font.setPixelSize(20);
	custom_slider->SetHanderLabelProperty(font,QColor(255,255,255),QColor(24,189,155));
	custom_slider->SetHanderLabelRoundValue(15, 15);
}

void CustomControls::SetDoubleHandleSlider()
{
	double_handle_slider = ui.double_handle_slider;
	double_handle_slider->SetSliveWidth(15);
	double_handle_slider->SetBackgrondColor(QColor(70, 70, 70), QColor(0, 0, 0, 0), QColor(100, 184, 255));
	double_handle_slider->SetTopAndBottomBlank(15, 15);
	double_handle_slider->SetSliderWidgetWidthAndHeight(50, 30);
	double_handle_slider->SetSliderRange(0, 100);
	double_handle_slider->SetSliveRoundValue(15, 10);

	QFont font;
	font.setFamily(QString::fromUtf8("楷体"));
	font.setPixelSize(20);

	double_handle_slider->SetMinHanderLabelProperty(font, QColor(255, 255, 255), QColor(100, 184, 255));
	double_handle_slider->SetMinHanderLabelRoundValue(15, 15);

	double_handle_slider->SetMaxHanderLabelProperty(font, QColor(255, 255, 255), QColor(100, 184, 255));
	double_handle_slider->SetMaxHanderLabelRoundValue(15, 15);
}

void CustomControls::SetTipSlider()
{
	tip_slider = ui.tip_slider;
	
	tip_slider->SetSliveWidth(15);
	tip_slider->SetBackgrondColor(QColor(70, 70, 70), QColor(240, 240, 240, 0),QColor(162, 127, 191));
	tip_slider->SetTopAndBottomBlank(15, 15);
	tip_slider->SetSliderWidgetWidthAndHeight(30, 30);
	tip_slider->SetSliderRange(0, 100);
	tip_slider->SetSliveRoundValue(15, 10);

	QFont font;
	font.setFamily(QString::fromUtf8("楷体"));
	font.setPixelSize(20);
	tip_slider->SetHanderLabelProperty(font, QColor(162, 127, 191), QColor(162, 127, 191));
	tip_slider->SetHanderLabelRoundValue(15, 15);

	tip_slider->SetTipLabelWidthAndHeight(30, 30);
	tip_slider->SetTipLabelRoundValue(15,15);
	tip_slider->SetTipLabelProperty(font, QColor(255, 255, 255), QColor(162, 127, 191));
	tip_slider->SetTipLabelSpaceAndWidth(8, 1);
	tip_slider->SetShowMode(TipSlider::Show_Left_Label);
}

void CustomControls::SetStripSlider()
{
	strip_slider = ui.strip_slider;
	strip_slider->SetSliveWidth(15);
	strip_slider->SetBackgrondColor(QColor(70, 70, 70), QColor(150, 150, 100, 0));
	strip_slider->SetTopAndBottomBlank(15, 15);
	strip_slider->SetSliderWidgetWidthAndHeight(15, 60);
	strip_slider->SetSliderRange(0, 100);
	strip_slider->SetSliveRoundValue(15, 10);

	QFont font1;
	font1.setFamily(QString::fromUtf8("楷体"));
	font1.setPixelSize(20);
	strip_slider->SetHanderLabelProperty(font1, QColor(125, 125,125,0), QColor(255, 170, 127));
	strip_slider->SetHanderLabelRoundValue(15, 10);
}

void CustomControls::SetCustomSliderStyleOne()
{
	custom_slider_style_one = ui.custom_slider_style_one;
	custom_slider_style_one->SetSliveWidth(15);
	custom_slider_style_one->SetBackgrondColor(QColor(70, 70, 70), QColor(100, 160, 45, 255), QColor(24, 189, 155));
	custom_slider_style_one->SetTopAndBottomBlank(20,20);
	custom_slider_style_one->SetSliderWidgetWidthAndHeight(35, 35);
	custom_slider_style_one->SetSliderRange(0, 100);
	custom_slider_style_one->SetSliveRoundValue(15, 10);

	QFont font;
	font.setFamily(QString::fromUtf8("楷体"));
	font.setPixelSize(20);
	custom_slider_style_one->SetHanderLabelProperty(font, QColor(255, 255, 255), QColor(24, 189, 155));
	custom_slider_style_one->SetHanderLabelRoundValue(15, 15);
}

void CustomControls::SetCustomSliderStyleTwo()
{
	custom_slider_style_two = ui.custom_slider_style_two;
	custom_slider_style_two->SetSliveWidth(12);
	custom_slider_style_two->SetBackgrondColor(QColor(50, 50, 50), QColor(15, 240, 133, 0), QColor(70, 158, 228));
	custom_slider_style_two->SetTopAndBottomBlank(15, 15);
	custom_slider_style_two->SetSliderWidgetWidthAndHeight(20, 20);
	custom_slider_style_two->SetSliderRange(0, 100);
	custom_slider_style_two->SetSliveRoundValue(15, 7);

	//设置背景杆子<该例子特有>
	custom_slider_style_two->SetBackgroundSliverColor(QColor(85, 85, 85));
	custom_slider_style_two->SetBackgroundSliverWidth(26);
	custom_slider_style_two->SetBackgroundSliverTopBottomMargin(0, 0);
	custom_slider_style_two->SetBackgroundSliverRoundValue(15, 15);

	QFont font;
	font.setFamily(QString::fromUtf8("楷体"));
	font.setPixelSize(20);
	custom_slider_style_two->SetHanderLabelProperty(font, QColor(255, 255, 255), QColor(20, 20, 20));
	custom_slider_style_two->SetHanderLabelRoundValue(15, 15);
	custom_slider_style_two->SetInnerCircleRadiusAndColor(4, QColor(70, 158, 228));
}

void CustomControls::SetStripSliderStyleOne()
{
	strip_slider_style_one = ui.strip_slider_style_one;
	strip_slider_style_one->SetSliveWidth(20);
	strip_slider_style_one->SetBackgrondColor(QColor(239, 255, 178), QColor(150, 150, 100, 0));
	strip_slider_style_one->SetTopAndBottomBlank(0, 0);
	strip_slider_style_one->SetSliderWidgetWidthAndHeight(20, 60);
	strip_slider_style_one->SetSliderRange(0, 100);
	strip_slider_style_one->SetSliveRoundValue(0, 0);

	QFont font1;
	font1.setFamily(QString::fromUtf8("楷体"));
	font1.setPixelSize(20);
	strip_slider_style_one->SetHanderLabelProperty(font1, QColor(100, 125, 125, 0), QColor(142, 223, 40));
	strip_slider_style_one->SetHanderLabelRoundValue(0, 0);





}

void CustomControls::SetStripSliderStyleTwo()
{
	strip_slider_style_two = ui.strip_slider_style_two;

	strip_slider_style_two->SetSliveWidth(8);
	strip_slider_style_two->SetBackgrondColor(QColor(70, 70, 70), QColor(150, 150, 100, 0));
	strip_slider_style_two->SetTopAndBottomBlank(0, 0);
	strip_slider_style_two->SetSliderWidgetWidthAndHeight(30, 60);
	strip_slider_style_two->SetSliderRange(0, 100);
	strip_slider_style_two->SetSliveRoundValue(0, 0);
	strip_slider_style_two->SetTriangleWidth(36);
	QFont font1;
	font1.setFamily(QString::fromUtf8("楷体"));
	font1.setPixelSize(20);
	strip_slider_style_two->SetHanderLabelProperty(font1, QColor(100, 125, 125, 0), QColor(157, 173, 220));
	strip_slider_style_two->SetHanderLabelRoundValue(15, 15);
}

void CustomControls::SetHandleLineChart()
{
	handle_line_chart = ui.handle_line_chart;
	handle_line_chart->SetXAxisRange(0,6);
	handle_line_chart->SetYAxisRange(0,30);

	//上线
	QList<QPointF>points_up;
	points_up.clear();
	for (int i = 0; i < 7; i++)
	{
		QPointF point_up;
		point_up.setX(i);
		point_up.setY(qrand()%5+15);
		points_up.append(point_up);
	}
	//中线
	QList<QPointF>points_mid;
	points_mid.clear();
	for (int i = 0; i < 7; i++)
	{
		QPointF point_mid;
		point_mid.setX(i);
		point_mid.setY(qrand()%6+9);
		points_mid.append(point_mid);
	}
	//下线
	QList<QPointF>points_low;
	points_low.clear();
	for (int i = 0; i < 7; i++)
	{
		QPointF point_low;
		point_low.setX(i);
		point_low.setY(qrand()%8);
		points_low.append(point_low);
	}

	handle_line_chart->UpdateCurve(points_up,points_mid,points_low);
}

void CustomControls::SetHandlePieChart()
{
	handle_pie_chart = ui.handle_pie_chart;

	QList<int>value_list;
	value_list << 1<<2<<3;

	handle_pie_chart->UpdateCurve(value_list);
}

void CustomControls::SetHandleScatterChart()
{
	handle_scatter_chart = ui.handle_scatter_chart;
	handle_scatter_chart->SetXAxisRange(0, 9);
	handle_scatter_chart->SetYAxisRange(0, 30);

	//上线
	QList<QPointF>points_up;
	points_up.clear();
	for (int i = 0; i <10; i++)
	{
		QPointF point_up;
		point_up.setX(i);
		point_up.setY(qrand() % 5 + 15);
		points_up.append(point_up);
	}
	//中线
	QList<QPointF>points_mid;
	points_mid.clear();
	for (int i = 0; i < 10; i++)
	{
		QPointF point_mid;
		point_mid.setX(i);
		point_mid.setY(qrand() % 6 + 9);
		points_mid.append(point_mid);
	}
	//下线
	QList<QPointF>points_low;
	points_low.clear();
	for (int i = 0; i < 10; i++)
	{
		QPointF point_low;
		point_low.setX(i);
		point_low.setY(qrand() % 8);
		points_low.append(point_low);
	}

	handle_scatter_chart->UpdateCurve(points_up, points_mid, points_low);
}

void CustomControls::SetHandleBarChart()
{
	handle_bar_chart = ui.handle_bar_chart;
	//handle_bar_chart->SetXAxisRange(0, 6);
	//handle_bar_chart->SetYAxisRange(0, 10);
}

void CustomControls::SetCustomPanel()
{
	custom_panel = ui.custom_panel;
	custom_panel->SetBorderPropert(16, QColor(164, 164, 164));
	custom_panel->SetPanelColor(QColor(0, 0, 0));
	QFont font;
	font.setPixelSize(20);
	font.setFamily("微软雅黑");
	custom_panel->SetScaleFont(font);
	custom_panel->SetScaleColor(QColor(220, 220, 220));
	custom_panel->SetScaleNumColor(QColor(220, 220, 220));
	custom_panel->SetSpaceBorderToScalenum(20);
	custom_panel->SetSpaceScaleToScalenum(20);
	custom_panel->SetMajorScaleProperty(2, 20);
	custom_panel->SetMinorScaleProperty(1, 10);
	custom_panel->SetMajorCount();
	custom_panel->SetMinorCount(5);
	custom_panel->SetMinValue();
	custom_panel->SetMaxValue();
	custom_panel->SetStartAngle();
	custom_panel->SetEndAngle();
	QFont font1;
	font1.setPixelSize(30);
	font1.setFamily(QString::fromUtf8("宋体"));
	custom_panel->SetTextPosition(100);//文字y轴坐标
	custom_panel->SetTextFont(font1);
	custom_panel->SetTextColor(QColor(220, 220, 220));
	QFont font2;
	font2.setPixelSize(20);
	font2.setFamily(QString::fromUtf8("宋体"));
	custom_panel->SetTitlePosition(-40);//文字y轴坐标
	custom_panel->SetTitleFont(font2);
	custom_panel->SetTitleColor(QColor(220, 220, 220));
	custom_panel->SetTitleStr(QString::fromUtf8("速度表"));
	custom_panel->SetCenterRadius(10);
	custom_panel->SetPointerProperty(10, 100);

	//初始值
	custom_panel->SetCurValue(0);
}

void CustomControls::SetNetSpeedPanel()
{
	netspeed_panel = ui.netspeed_panel;
	netspeed_panel->SetBorderPropert(10, QColor(164, 164, 164));

	netspeed_panel->SetPanelColor(QColor(1, 39, 62));
	QFont font;
	font.setPixelSize(16);
	font.setFamily("黑体");
	netspeed_panel->SetScaleFont(font);
	netspeed_panel->SetScaleColor(QColor(220, 220, 220));
	netspeed_panel->SetScaleNumColor(QColor(220, 220, 220));

	netspeed_panel->SetSpaceBorderToScale(0);
	netspeed_panel->SetSpaceScaleToScalenum(20);

	netspeed_panel->SetMajorScaleProperty(2, 6);
	netspeed_panel->SetMinorScaleProperty(1, 10);

	netspeed_panel->SetMajorCount(6);
	netspeed_panel->SetMinorCount(1);
	netspeed_panel->SetMinValue();
	netspeed_panel->SetMaxValue(120);
	netspeed_panel->SetStartAngle();
	netspeed_panel->SetEndAngle();


	QFont font1;
	font1.setPixelSize(30);
	font1.setFamily(QString::fromUtf8("黑体"));
	netspeed_panel->SetTextPosition(100);//文字y轴坐标
	netspeed_panel->SetTextFont(font1);
	netspeed_panel->SetTextColor(QColor(170, 230, 250));


	QFont font2;
	font2.setPixelSize(20);
	font2.setFamily(QString::fromUtf8("黑体"));
	netspeed_panel->SetTitlePosition(-60);//文字y轴坐标
	netspeed_panel->SetTitleFont(font2);
	netspeed_panel->SetTitleColor(QColor(170, 230, 250));
	netspeed_panel->SetTitleStr(QString::fromUtf8("网速表"));

	netspeed_panel->SetCenterRadius(0);
	netspeed_panel->SetPointerProperty(10, 100);
	//初始值
	netspeed_panel->SetCurValue(0);
}

void CustomControls::SetSemiCirclePanel()
{
	semicircle_panel = ui.semicircle_panel;
	semicircle_panel->SetBorderPropert(4, QColor(164, 164, 164));

	semicircle_panel->SetPanelColor(QColor(0, 0, 0));
	QFont font;
	font.setPixelSize(20);
	font.setFamily("微软雅黑");
	semicircle_panel->SetScaleFont(font);
	semicircle_panel->SetScaleColor(QColor(220, 220, 220));
	semicircle_panel->SetScaleNumColor(QColor(220, 220, 220));

	semicircle_panel->SetSpaceBorderToScale(0);
	semicircle_panel->SetSpaceScaleToScalenum(15);

	semicircle_panel->SetMajorScaleProperty(2, 10);
	semicircle_panel->SetMinorScaleProperty(1, 6);

	semicircle_panel->SetMajorCount(10);
	semicircle_panel->SetMinorCount(5);
	semicircle_panel->SetMinValue(0);
	semicircle_panel->SetMaxValue(100);
	semicircle_panel->SetStartAngle(90);
	semicircle_panel->SetEndAngle(90);


	QFont font1;
	font1.setPixelSize(30);
	font1.setFamily(QString::fromUtf8(""));
	semicircle_panel->SetTextPosition(-10);//文字y轴坐标
	semicircle_panel->SetTextFont(font1);
	semicircle_panel->SetTextColor(QColor(220, 220, 220));

	QFont font2;
	font2.setPixelSize(20);
	font2.setFamily(QString::fromUtf8("宋体"));
	semicircle_panel->SetTitlePosition(-200);//文字y轴坐标
	semicircle_panel->SetTitleFont(font2);
	semicircle_panel->SetTitleColor(QColor(220, 220, 220));
	semicircle_panel->SetTitleStr(QString::fromUtf8(""));

	semicircle_panel->SetCenterRadius(60);
	semicircle_panel->SetPointerProperty(10, 250);

	//初始值
	semicircle_panel->SetCurValue(0);
}

void CustomControls::SetRXTurnPan()
{
	//设置各个圆的间距
	turn_pan = ui.turn_pan;
	turn_pan->SetRoundRadius(6,8,10,8,10, 7, 5, 6, 20,10,15, 15,5);
	turn_pan->SetScaleWidth(4, 3);
	turn_pan->SetSectorSpeed(8, 4, 4);
	turn_pan->SetScaleRoundSpeed(0.003, 0.001);
	//turn_pan->SetPanColor(QColor(98, 241, 254), QColor(19, 30, 34));
	turn_pan->SetPanColor(QColor(85,255,255), QColor(19, 30, 34));
}

void CustomControls::SetDropDownMenu()
{
	drop_menu = new DropDownMenu(ui.test_drop_menu_btn, ui.btn_controller_1_wid);
	QFont font;
	font.setPixelSize(20);
	font.setFamily(QString::fromUtf8("黑体"));
	drop_menu->SetFont(font);
	drop_menu->SetButtonFixHeight(30);
	drop_menu->SetSpacing(3);
	drop_menu->InitMenu();

	//血管列表设置
	QList<QString>option_name_list;
	option_name_list << "Item0" << "Item1";
	drop_menu->SetVesselOption(option_name_list);
	drop_menu->Update();
	drop_menu->InitSelectIndex("Item0");//设置初始值LAD
}

void CustomControls::SetDateSelectPage()
{
	date_select_page=new RXDateSelectPage(0,ui.btn_controller_2_wid);
	ui.gridLayout_14->addWidget(date_select_page);
	
	QFont font;
	font.setPixelSize(15);
	font.setFamily(QString::fromUtf8("黑体"));
	date_select_page->SetFont(font);
	date_select_page->SetSelectedDate(2020, 1, 3);
}

void CustomControls::SetChatLoginWin()
{
	chat_login_win = new LoginWin(ui.wid_customwin_0);
	chat_login_win->show();
}

void CustomControls::SetToolsWin()
{
	tools_win = new RXTools(ui.wid_customwin_2);
	tools_win->show();
}

void CustomControls::SetProgressValue(int value)
{
	dash_board->SetPanValue(value);
	ring_progressbar->SetPanValue(value);
	linear_progressbar->SetPanValue(value);
	wave_progressbar->SetPanValue(value);
	rect_progressbar->SetPanValue(value);
	rect_wave_progressbar->SetPanValue(value);
}

void CustomControls::SetPanelValue(int value)
{
	custom_panel->SetCurValue(value);
	netspeed_panel->SetCurValue(value);
	semicircle_panel->SetCurValue(value);
}

void CustomControls::SetDashBoard()
{
	dash_board = ui.dash_board;
	dash_board->SetPanColor(QColor(97, 117, 118), QColor(255, 107, 107));
	dash_board->SetPanLabelColor(QColor(255, 255, 255), QColor(0, 0, 0, 0));

	QFont font_dash;
	font_dash.setFamily(QString::fromUtf8("楷体"));
	font_dash.setPixelSize(50);
	dash_board->SetPanLabelFont(font_dash);
	dash_board->Update();
}

void CustomControls::SetRingProgressBar()
{
	ring_progressbar = ui.ring_progressbar;
	ring_progressbar->SetPanColor(QColor(255, 255, 255), QColor(100, 184, 255));
	ring_progressbar->SetPanLabelColor(QColor(255, 255, 255), QColor(0, 10, 0, 0));
	QFont font_dash;
	font_dash.setFamily(QString::fromUtf8("黑体"));
	font_dash.setPixelSize(50);
	ring_progressbar->SetPanLabelFont(font_dash);
	ring_progressbar->SetInsideCircleRadius(80);
	ring_progressbar->SetInsideCircleColor(QColor(0, 85, 127));
	ring_progressbar->SetBlankLength(5);
	ring_progressbar->Update();
}

void CustomControls::SetLinearProgressBar()
{
	linear_progressbar = ui.linear_progressbar;
	linear_progressbar->SetPanColor(QColor(0, 85, 127), QColor(255, 100, 100));
	linear_progressbar->SetPanLabelColor(QColor(255, 255, 255), QColor(0, 0, 0, 0));
	QFont font_dash_1;
	font_dash_1.setFamily(QString::fromUtf8("黑体"));
	font_dash_1.setPixelSize(50);
	linear_progressbar->SetPanLabelFont(font_dash_1);
	linear_progressbar->SetInsideCircleRadius(100);
	linear_progressbar->SetInsideCircleColor(QColor(24, 189, 155));
	linear_progressbar->Update();
}

void CustomControls::SetWaveProgressBar()
{
	wave_progressbar = ui.wave_progressbar;
	wave_progressbar->SetPanColor(QColor(100, 100, 100), QColor(0, 0, 0));
	wave_progressbar->SetPanLabelColor(QColor(255, 255, 255), QColor(0, 0, 0, 0));
	wave_progressbar->SetWaveColor(QColor(37, 200, 178, 180), QColor(37, 200, 178, 100));//设置水波颜色

	QFont font_dash_2;
	font_dash_2.setFamily(QString::fromUtf8("黑体"));
	font_dash_2.setPixelSize(70);
	wave_progressbar->SetPanLabelFont(font_dash_2);
	wave_progressbar->SetBorderWidth(8);
	wave_progressbar->SetWaveProperty(2, 0.08, 0.05);
	wave_progressbar->Update();
}

void CustomControls::SetRectWaveProgressBar()
{
	rect_wave_progressbar = ui.rect_wave_progressbar;
	rect_wave_progressbar->SetPanColor(QColor(100, 100, 100), QColor(0,85,127,255));
	rect_wave_progressbar->SetPanLabelColor(QColor(255, 255, 255), QColor(0, 0, 0, 0));
	rect_wave_progressbar->SetWaveColor(QColor(105, 177, 238, 180), QColor(105, 177, 238, 100));//设置水波颜色
	rect_wave_progressbar->SetMargin(10, 10, 10, 10);

	QFont font_dash_2;
	font_dash_2.setFamily(QString::fromUtf8("黑体"));
	font_dash_2.setPixelSize(70);
	rect_wave_progressbar->SetPanLabelFont(font_dash_2);
	rect_wave_progressbar->SetBorderWidth(8);
	rect_wave_progressbar->SetWaveProperty(3, 0.06, 0.05);
	rect_wave_progressbar->Update();
}

void CustomControls::SetRectProgressBar()
{
	rect_progressbar = ui.rect_progressbar;
	rect_progressbar->SetMargin(85, 85, 0, 0);
	rect_progressbar->SetSpace(5);
	rect_progressbar->SetProgressbarHeight(180);
	rect_progressbar->SetProgressBarColor(QColor(30,30,30), QColor(100, 184,255));
	QFont font_dash_3;
	font_dash_3.setFamily(QString::fromUtf8("黑体"));
	font_dash_3.setPixelSize(18);
	rect_progressbar->SetLabelProperty(QColor(255, 255,255), QColor(30, 30, 30), font_dash_3);
	rect_progressbar->SetBorderRadius(50, 10, 50, 50);
}

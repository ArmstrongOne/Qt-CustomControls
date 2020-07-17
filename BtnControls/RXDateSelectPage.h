#pragma once

#include <QWidget>
#include<QMouseEvent>
#include <QTimer>
#include"btncontrols_global.h"
namespace Ui
{
	class RXDateSelectPage;
}
class QLabel;
class BTNCONTROLS_EXPORT RXDateSelectPage : public QWidget
{
	Q_OBJECT

public:
	RXDateSelectPage(int mode,QWidget *parent = Q_NULLPTR);
	~RXDateSelectPage();
	QString GetSelectedDate();
	void SetSelectedDate(int year,int month,int day);

	//设置字体
	void SetFont(QFont font);
private:
	enum State
	{
		Year_Mode_Press_State,
		Month_Mode_Press_State,
		Day_Mode_Press_State,
		None_State
	};

	enum RectArea
	{
		Last_Year_Mode_Rect_Area,
		Next_Year_Mode_Rect_Area,
	
		Last_Month_Mode_Rect_Area,
		Next_Month_Mode_Rect_Area,

		Last_Day_Mode_Rect_Area,
		Next_Day_Mode_Rect_Area,
	};




	int state;
	int mode; // 0:开始日期 1:结束日期

	void InitFont();


	QTimer timer;//判断是单击还是点击长按

	Ui::RXDateSelectPage *ui;
	bool eventFilter(QObject *obj, QEvent *event);//压力，流速事件处理器
	int GetTotalDayOFMonth(int year,int month);
	void ResetDayMode();
	void leaveEvent(QEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	
	QPoint start_point;//记录鼠标移动最开始的点
	QRect GetRectArea(RectArea); //获取各个模块的矩形区域
	

	//滚动列 增减操作
	void Year_Add(); //日期增加
	void Year_Reduce(); //日期减少

	void Month_Add(); //月份增加
	void Month_Reduce(); //月份减少

	void Day_Add(); //年份增加
	void Day_Reduce(); //年份减少

	void SetDateValue(QLabel*, int value); //label赋值 因为考虑了 2位数字的情况
	bool DayNumIsEqualTotalDay(QString str,int value); //判断日期是否相等 因为要考虑01，02这种日期
	                                         //左边是label值 右边是比较的数值
signals:
	void select_start_date_signal(int,int,int);
	void select_end_date_signal(int, int, int);
private slots:
	void on_date_confirm_btn_clicked();
	void on_cancel_btn_clicked();
};

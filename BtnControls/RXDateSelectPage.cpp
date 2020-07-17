#include "RXDateSelectPage.h"
#include <QEvent>
#include<QWheelEvent>
#include <QDebug>
#include <QRect>
#include "ui_RXDateSelectPage.h"
#pragma execution_character_set("utf-8")
RXDateSelectPage::RXDateSelectPage(int mode,QWidget *parent)
	: QWidget(parent),mode(mode)
{
	ui = new Ui::RXDateSelectPage;
	ui->setupUi(this);
	ui->year_mode->installEventFilter(this);
	ui->day_mode->installEventFilter(this);
	ui->month_mode->installEventFilter(this);

	this->InitFont();
	timer.setSingleShot(true);
}

void RXDateSelectPage::InitFont()
{

}

RXDateSelectPage::~RXDateSelectPage()
{



}

QString RXDateSelectPage::GetSelectedDate()
{
	QString date_str = ui->cur_year->text().remove(" ") + QString::fromUtf8("年") + ui->cur_month->text().remove(" ") + QString::fromUtf8("月") + ui->cur_day->text().remove(" ") + QString::fromUtf8("日");
	return date_str;
}

void RXDateSelectPage::SetSelectedDate(int year, int month, int day)
{
	//设置年
	SetDateValue(ui->last_year, year - 1);
	SetDateValue(ui->cur_year, year);
	SetDateValue(ui->next_year, year+1);

	//设置月
	if (month == 1)
	{
		ui->last_month->setText("");
		ui->cur_month->setText("01");
		ui->next_month->setText("02");
	}
	else if (month == 12)
	{
		ui->last_month->setText("11");
		ui->cur_month->setText("12");
		ui->next_month->setText("");
	}
	else
	{
		SetDateValue(ui->last_month, month - 1);
		SetDateValue(ui->cur_month, month );
		SetDateValue(ui->next_month, month+1);
	}

	//设置日
	int total_day = GetTotalDayOFMonth(year, month);
	if (day == 1)
	{
		ui->last_day->setText("");
		ui->cur_day->setText("01");
		ui->next_day->setText("02");
	}
	else if (day== total_day)
	{
		SetDateValue(ui->last_day, total_day - 1);
		SetDateValue(ui->cur_day, total_day);
		ui->next_day->setText("");
	}
	else
	{
		SetDateValue(ui->last_day, day-1);
		SetDateValue(ui->cur_day, day);
		SetDateValue(ui->next_day, day+1);
	}



}

void RXDateSelectPage::SetFont(QFont font)
{
	ui->last_year->setFont(font);
	ui->cur_year->setFont(font);
	ui->next_year->setFont(font);
	ui->last_month->setFont(font);
	ui->cur_month->setFont(font);
	ui->next_month->setFont(font);
	ui->last_day->setFont(font);
	ui->cur_day->setFont(font);
	ui->next_day->setFont(font);
	ui->date_confirm_btn->setFont(font);
	ui->cancel_btn->setFont(font);
}

bool RXDateSelectPage::eventFilter(QObject *obj, QEvent *event)
{

	if (obj == ui->year_mode&&event->type() == QEvent::Wheel)
	{
		QWheelEvent *wheel_event = static_cast<QWheelEvent*>(event);

		if (wheel_event->delta() > 0)
		{
			Year_Reduce();
		}
		else
		{
			Year_Add();
		}
		ResetDayMode();
		return QWidget::eventFilter(obj, event);
	}
	
	if (obj == ui->month_mode&&event->type() == QEvent::Wheel)
	{
		QWheelEvent *wheel_event = static_cast<QWheelEvent*>(event);
		
		if(wheel_event->delta()> 0)
		{  
			Month_Reduce();
		}
	   else
	   {
		   Month_Add();
		}
		return QWidget::eventFilter(obj, event);
	}
	
	if (obj == ui->day_mode&&event->type() == QEvent::Wheel)
	{
		QWheelEvent *wheel_event = static_cast<QWheelEvent*>(event);

		if (wheel_event->delta() > 0)
		{
			Day_Reduce();
		}
		else
		{
			Day_Add();
		}
		return QWidget::eventFilter(obj, event);
	}

	else if (obj == NULL&&event->type() == QEvent::MouseButtonPress)
	{
		state = None_State;

	}

	else if (obj == NULL&&event->type() == QEvent::MouseButtonRelease)
	{
		state = None_State;
	}

	//拖动年滚动条列
	if (obj == ui->year_mode&&event->type() == QEvent::MouseButtonPress)
	{
		timer.start(200);

		QMouseEvent *mouse_event;
		mouse_event = static_cast<QMouseEvent*>(event);
		start_point = mouse_event->pos();
		state = Year_Mode_Press_State;


	}

	if (obj == ui->year_mode&&event->type() == QEvent::MouseButtonRelease)
	{

		state = None_State;

		if (!timer.isActive())
			return true;
		QMouseEvent *mouse_event;
		mouse_event = static_cast<QMouseEvent*>(event);
	

		QPoint mouse_pos = this->mapToGlobal(mouse_event->pos());
		if (GetRectArea(Last_Year_Mode_Rect_Area).contains(mouse_pos))
		{
			Year_Reduce();
		}

		if (GetRectArea(Next_Year_Mode_Rect_Area).contains(mouse_pos))
		{
			Year_Add();
		}
	}

	if (obj == ui->year_mode&&event->type() == QEvent::MouseMove)
	{
		QMouseEvent *mouse_event;
		mouse_event = static_cast<QMouseEvent*>(event);

		//移出窗口 重置状态
		QPoint mouse_position = mouse_event->globalPos();
		QPoint rect = this->mapToGlobal(QPoint(0, 0));//获取控件在窗体中的坐标
		QRect this_rect(rect.x(), rect.y(), this->width(),this->height());
		if (!this_rect.contains(mouse_position))
		{
			state = None_State;
			return true;
		}

		if (state ==Year_Mode_Press_State)
		{
			if (mouse_event->pos().y() - start_point.y() >= 30)
			{
				//年份变小
				Year_Reduce();
				start_point = mouse_event->pos();

			}
			else if (mouse_event->pos().y() - start_point.y()<=-30)
			{
				//年份变大
				Year_Add();
				start_point = mouse_event->pos();
			}
		}

	}

	//拖动月滚动条列
	if (obj == ui->month_mode&&event->type() == QEvent::MouseButtonPress)
	{
		timer.start(200);
		QMouseEvent *mouse_event;
		mouse_event = static_cast<QMouseEvent*>(event);
		start_point = mouse_event->pos();
		state = Month_Mode_Press_State;
	}

	if (obj == ui->month_mode&&event->type() == QEvent::MouseButtonRelease)
	{
		state = None_State;

		if (!timer.isActive())
			return true;
		QMouseEvent *mouse_event;
		mouse_event = static_cast<QMouseEvent*>(event);
		//qDebug() << mouse_event->pos().x() << " " << mouse_event->pos().y() << " yuanshi";
		
		QPoint mouse_pos = mouse_event->globalPos();
		if (GetRectArea(Last_Month_Mode_Rect_Area).contains(mouse_pos))
		{
			Month_Reduce();
		}

		if (GetRectArea(Next_Month_Mode_Rect_Area).contains(mouse_pos))
		{
			Month_Add();
		}
	}

	if (obj == ui->month_mode&&event->type() == QEvent::MouseMove)
	{
		QMouseEvent *mouse_event;
		mouse_event = static_cast<QMouseEvent*>(event);
		//移出窗口 重置状态
		QPoint mouse_position = mouse_event->globalPos();
		QPoint rect = this->mapToGlobal(QPoint(0, 0));//获取控件在窗体中的坐标
		QRect this_rect(rect.x(), rect.y(), this->width(), this->height());
		if (!this_rect.contains(mouse_position))
		{
			state = None_State;
			return true;
		}

		if (state == Month_Mode_Press_State)
		{
			if (mouse_event->pos().y() - start_point.y() >= 30)
			{
				//月份变小
				Month_Reduce();
				start_point = mouse_event->pos();

			}
			else if (mouse_event->pos().y() - start_point.y() <= -30)
			{
				//月份变大
				Month_Add();
				start_point = mouse_event->pos();

			}
		}
	}

	//拖动单日滚动条列
	if (obj == ui->day_mode&&event->type() == QEvent::MouseButtonPress)
	{
		timer.start(200);
		QMouseEvent *mouse_event;
		mouse_event = static_cast<QMouseEvent*>(event);
		start_point = mouse_event->pos();
		state = Day_Mode_Press_State;
	}

	if (obj == ui->day_mode&&event->type() == QEvent::MouseButtonRelease)
	{
		state = None_State;

		if (!timer.isActive())
			return true;

		QMouseEvent *mouse_event;
		mouse_event = static_cast<QMouseEvent*>(event);

		//这里坐标获取到的是控件左上角，得转换为控件坐标
		QPoint mouse_pos = mouse_event->globalPos();
		mouse_pos.setX(mouse_pos.x());

		//158 270
		//qDebug() << mouse_pos.x();
		//qDebug() << mouse_pos.y();
		if (GetRectArea(Last_Day_Mode_Rect_Area).contains(mouse_pos))
		{
			Day_Reduce();
		}

		if (GetRectArea(Next_Day_Mode_Rect_Area).contains(mouse_pos))
		{
			Day_Add();
		}
	}

	if (obj == ui->day_mode&&event->type() == QEvent::MouseMove)
	{
		QMouseEvent *mouse_event;
		mouse_event = static_cast<QMouseEvent*>(event);

		//移出窗口 重置状态
		QPoint mouse_position = mouse_event->globalPos();
		QPoint rect = this->mapToGlobal(QPoint(0, 0));//获取控件在窗体中的坐标
		QRect this_rect(rect.x(), rect.y(), this->width(), this->height());
		if (!this_rect.contains(mouse_position))
		{
			state = None_State;
			return true;
		}

		if (state == Day_Mode_Press_State)
		{
			if (mouse_event->pos().y() - start_point.y() >= 30)
			{
				//月份变小
				Day_Reduce();
				start_point = mouse_event->pos();

			}
			else if (mouse_event->pos().y() - start_point.y() <= -30)
			{
				//月份变大
				Day_Add();
				start_point = mouse_event->pos();
			}
		}
	}
}

int RXDateSelectPage::GetTotalDayOFMonth(int year, int month)
{
	int day;
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			day = 29;
		}
		else 
		{
			day = 28;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		day = 30;
	}
	else
	{
		day = 31;
	}
	return day;
}

void RXDateSelectPage::ResetDayMode()
{
	if (ui->cur_day->text().toInt() > 27)
	{
		ui->last_day->setText(QString::number(14));
		ui->cur_day->setText(QString::number(15));
		ui->next_day->setText(QString::number(16));
	}
}

void RXDateSelectPage::leaveEvent(QEvent* event)
{
	//鼠标松开后才执行

	//QWidget::leaveEvent(event);
	state = None_State;
	//qDebug() << "leaveEvent" << "None_State";
}

void RXDateSelectPage::mouseMoveEvent(QMouseEvent* event)
{

}

QRect RXDateSelectPage::GetRectArea(RectArea mode)
{
	QRect rect;
	switch (mode)
	{
	case Last_Year_Mode_Rect_Area:
	{

		QPoint last_year_left_top = ui->last_year->mapToGlobal(QPoint(0, 0));//获取控件在窗体中的坐标
		QRect last_year_rect(last_year_left_top.x(), last_year_left_top.y(), ui->last_year->width(), ui->next_year->height());
		rect = last_year_rect;
		break;
	}


	case Next_Year_Mode_Rect_Area:
	{
		QPoint next_year_left_top = ui->next_year->mapToGlobal(QPoint(0, 0));//获取控件在窗体中的坐标
		QRect next_year_rect(next_year_left_top.x(), next_year_left_top.y(), ui->next_year->width(), ui->next_year->height());

		rect = next_year_rect;

		break;
	}

	case Last_Month_Mode_Rect_Area:
	{

		QPoint last_month_left_top = ui->last_month->mapToGlobal(QPoint(0, 0));//获取控件在窗体中的坐标
		QRect last_month_rect(last_month_left_top.x(), last_month_left_top.y(), ui->last_month->width(), ui->next_month->height());

		rect = last_month_rect;

		break;
	}


	case Next_Month_Mode_Rect_Area:
	{

		QPoint next_month_left_top = ui->next_month->mapToGlobal(QPoint(0, 0));//获取控件在窗体中的坐标
		QRect next_month_rect(next_month_left_top.x(), next_month_left_top.y(), ui->next_month->width(), ui->next_month->height());
		rect = next_month_rect;

		break;
	}
	case Last_Day_Mode_Rect_Area:
	{

		QPoint last_day_left_top = ui->last_day->mapToGlobal(QPoint(0, 0));//获取控件在窗体中的坐标
		QRect last_day_rect(last_day_left_top.x(), last_day_left_top.y(), ui->last_day->width(), ui->next_day->height());
		rect = last_day_rect;
		break;
	}
	case Next_Day_Mode_Rect_Area:
	{

		QPoint next_day_left_top = ui->next_day->mapToGlobal(QPoint(0, 0));//获取控件在窗体中的坐标
		QRect next_day_rect(next_day_left_top.x(), next_day_left_top.y(), ui->next_day->width(), ui->next_day->height());
		rect = next_day_rect;
		break;
	}
	}

	return rect;
}

void RXDateSelectPage::Year_Add()
{
	SetDateValue(ui->last_year,ui->last_year->text().toInt() + 1);
	SetDateValue(ui->cur_year, ui->cur_year->text().toInt() + 1);
	SetDateValue(ui->next_year, ui->next_year->text().toInt() + 1);
}

void RXDateSelectPage::Year_Reduce()
{
	SetDateValue(ui->last_year, ui->last_year->text().toInt()-1);
	SetDateValue(ui->cur_year, ui->cur_year->text().toInt()-1);
	SetDateValue(ui->next_year, ui->next_year->text().toInt()-1);
}

void RXDateSelectPage::Month_Add()
{
	//边界情况
	if (ui->cur_month->text().remove(" ") == "12")
		return ;
	if (ui->cur_month->text().remove(" ") == "01")
	{
		SetDateValue(ui->last_month,1);
		SetDateValue(ui->cur_month, 2);
		SetDateValue(ui->next_month,3);
		ResetDayMode();
		return ;
	}

	//正常情况
	SetDateValue(ui->last_month, ui->last_month->text().toInt() + 1);
	SetDateValue(ui->cur_month, ui->cur_month->text().toInt() + 1);


	if (ui->cur_month->text().remove(" ") == "12")
	{
		ui->next_month->setText("");
		ResetDayMode();
		return ;
	}
	else
	{
		SetDateValue(ui->next_month, ui->next_month->text().toInt() + 1);
		ResetDayMode();
		return ;
	}
}

void RXDateSelectPage::Month_Reduce()
{
	//边界情况
	if (ui->cur_month->text().remove(" ") == "01")
		return ;
	if (ui->cur_month->text().remove(" ") == "12")
	{
		SetDateValue(ui->last_month, 10);
		SetDateValue(ui->cur_month, 11);
		SetDateValue(ui->next_month, 12);
		ResetDayMode();
		return ;
	}

	//正常情况
	SetDateValue(ui->cur_month, ui->cur_month->text().toInt() - 1);
	SetDateValue(ui->next_month, ui->next_month->text().toInt() - 1);

	if (ui->cur_month->text().remove(" ") == "01")
	{
		ui->last_month->setText("");
		ResetDayMode();
		return ;
	}
	else
	{
		SetDateValue(ui->last_month, ui->last_month->text().toInt() - 1);
		ResetDayMode();
		return ;
	}
}

void RXDateSelectPage::Day_Add()
{
	int total_day = GetTotalDayOFMonth(ui->cur_year->text().toInt(), ui->cur_month->text().toInt());
	
	//边界情况

	if (DayNumIsEqualTotalDay(ui->cur_day->text(), total_day))
	{
		return;
	}


	if (ui->cur_day->text().remove(" ") == "01")
	{
		SetDateValue(ui->last_day, 1);
		SetDateValue(ui->cur_day, 2);
		SetDateValue(ui->next_day, 3);
		return;
	}

	//正常情况
	SetDateValue(ui->last_day, ui->last_day->text().toInt() + 1);
	SetDateValue(ui->cur_day, ui->cur_day->text().toInt() + 1);

	if (DayNumIsEqualTotalDay(ui->cur_day->text(), total_day))
	{
		ui->next_day->setText("");
		return;
	}
	else
	{
		SetDateValue(ui->next_day, ui->next_day->text().toInt() + 1);
		return ;
	}
}

void RXDateSelectPage::Day_Reduce()
{
	int total_day = GetTotalDayOFMonth(ui->cur_year->text().toInt(), ui->cur_month->text().toInt());
	//边界情况
	if (ui->cur_day->text().remove(" ") == "01")
		return ;

	if (DayNumIsEqualTotalDay(ui->cur_day->text(), total_day))
	{
		SetDateValue(ui->last_day, total_day - 2);
		SetDateValue(ui->cur_day, total_day - 1);
		SetDateValue(ui->next_day, total_day );
		return ;
	}

	//正常情况
	SetDateValue(ui->cur_day, ui->cur_day->text().toInt() - 1);
	SetDateValue(ui->next_day, ui->next_day->text().toInt() - 1);

	if (ui->cur_day->text().remove(" ") == "01")
	{
		ui->last_day->setText("");
		return ;
	}
	else
	{
		SetDateValue(ui->last_day, ui->last_day->text().toInt() - 1);
		return ;
	}
}

void RXDateSelectPage::SetDateValue(QLabel*label, int value)
{
	if (value < 10)
	{
		label->setText("0" + QString::number(value));
	}
	else
	{
		label->setText(QString::number(value));
	}
}

bool RXDateSelectPage::DayNumIsEqualTotalDay(QString str, int value)
{
	QString data_str = str.remove(" ");
	
	//小于10情况考虑
	if (data_str.left(1) == 0)
	{
		if (data_str.remove("0").remove(" ") == QString::number(value))
		{
			return true;
		}
	}

	//大于10情况考虑
	if (data_str == QString::number(value))
	{
		return true;
	}


	return false;
}

void RXDateSelectPage::on_date_confirm_btn_clicked()
{
	int year = ui->cur_year->text().toInt();
	int month = ui->cur_month->text().toInt();
	int day = ui->cur_day->text().toInt();

	if (mode == 0)
	{
		emit select_start_date_signal(year, month, day);
	}
	else
	{
		emit select_end_date_signal(year, month, day);
	}
}

void RXDateSelectPage::on_cancel_btn_clicked()
{
	//this->setVisible(false);
}

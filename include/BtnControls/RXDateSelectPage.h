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

	//��������
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
	int mode; // 0:��ʼ���� 1:��������

	void InitFont();


	QTimer timer;//�ж��ǵ������ǵ������

	Ui::RXDateSelectPage *ui;
	bool eventFilter(QObject *obj, QEvent *event);//ѹ���������¼�������
	int GetTotalDayOFMonth(int year,int month);
	void ResetDayMode();
	void leaveEvent(QEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	
	QPoint start_point;//��¼����ƶ��ʼ�ĵ�
	QRect GetRectArea(RectArea); //��ȡ����ģ��ľ�������
	

	//������ ��������
	void Year_Add(); //��������
	void Year_Reduce(); //���ڼ���

	void Month_Add(); //�·�����
	void Month_Reduce(); //�·ݼ���

	void Day_Add(); //�������
	void Day_Reduce(); //��ݼ���

	void SetDateValue(QLabel*, int value); //label��ֵ ��Ϊ������ 2λ���ֵ����
	bool DayNumIsEqualTotalDay(QString str,int value); //�ж������Ƿ���� ��ΪҪ����01��02��������
	                                         //�����labelֵ �ұ��ǱȽϵ���ֵ
signals:
	void select_start_date_signal(int,int,int);
	void select_end_date_signal(int, int, int);
private slots:
	void on_date_confirm_btn_clicked();
	void on_cancel_btn_clicked();
};

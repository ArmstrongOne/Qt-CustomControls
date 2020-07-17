#pragma once

#include <QtWidgets/QWidget>
#include "..\CustomWin.h"
namespace Ui
{
	class RXToolsClass;
}

class CUSTOMWIN_EXPORT RXTools:public QWidget
{
	Q_OBJECT

public:
	RXTools(QWidget *parent = Q_NULLPTR);
	~RXTools();

private:
	Ui::RXToolsClass *ui;
	void InitUi();
	void paintEvent(QPaintEvent *);
	void leaveEvent(QEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	bool eventFilter(QObject *obj, QEvent *event);//�¼�����
	void showEvent(QShowEvent*);

	//�����ƶ�
	QPoint start_move_points;//��¼����ĳ�ʼ��λ��
	bool is_press_title_wid;//������λ��

private slots:
    void on_close_win_btn_clicked();
	void on_hide_win_btn_clicked();
	void on_zoom_win_btn_clicked();
};

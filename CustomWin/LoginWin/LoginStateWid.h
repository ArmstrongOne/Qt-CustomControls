//µÇÂ½×´Ì¬²Ëµ¥À¸ 2020-5-14
#pragma once
#include <QWidget>
#include ".\Panda.h"
namespace Ui { class LoginStateWid; };
using namespace Panda;
class LoginStateWid : public QWidget
{
	Q_OBJECT

public:
	LoginStateWid(QWidget *parent = Q_NULLPTR);
	~LoginStateWid();

private:
	Ui::LoginStateWid *ui;
	void paintEvent(QPaintEvent *event);

signals:
	void ChooseState(USER_STATE);
private slots:
    void on_radiobtn_state_online_clicked();
	void on_radiobtn_state_leave_clicked();
	void on_radiobtn_state_busy_clicked();
	void on_radiobtn_state_notdisturb_clicked();
	void on_radiobtn_state_invisable_clicked();
};

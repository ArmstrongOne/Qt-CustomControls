#pragma once
#include "CustomWin.h"
#include <QtWidgets/QWidget>
#include"Panda.h"
using namespace Panda;
namespace Ui { class LoginWin; };

class LoginAvatarWid;//登陆头像窗口
class LoginStateWid; //登陆状态栏

class CUSTOMWIN_EXPORT LoginWin : public QWidget
{
	Q_OBJECT

public:
	LoginWin(QWidget *parent = Q_NULLPTR);
	~LoginWin();
	LoginWin(LoginWin&) = delete;
	LoginWin&operator=(LoginWin&) = delete;

	void Init();
	void Show();

private:
	Ui::LoginWin *ui;
	bool eventFilter(QObject *obj, QEvent *e);
	void paintEvent(QPaintEvent *event);
	void mouseMoveEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void showEvent(QShowEvent*);

	void InitUi();//ui调整
	void InitFont();//字体调整

	QPoint          start_move_point;//拖动开始点
	LoginAvatarWid* avatar_wid;//头像窗口
	LoginStateWid*  state_wid; //状态窗口

private slots:
    void on_btn_close_clicked();//关闭
	void on_btn_min_clicked();//最小化
	
	void OpenStateMenuSlot();//打开状态选择栏
	void ChooseStateSlot(USER_STATE);
	
};

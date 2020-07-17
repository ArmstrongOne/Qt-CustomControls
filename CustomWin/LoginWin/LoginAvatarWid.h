//登陆界面上的头像按钮
#pragma once
#include <QtWidgets/QWidget>
#include"Panda.h"
using namespace Panda;
namespace Ui { class LoginAvatarWid; };
class QPushButton;

class LoginAvatarWid : public QWidget
{
	Q_OBJECT
public:
	//设置头像图片信息
	void SetAvatarPic(QPixmap);

	//得到用户当前状态
	USER_STATE GetUserCurState();

	//设置用户当前状态
	void SetUserCurState(USER_STATE);

public:
	LoginAvatarWid(QWidget *parent = Q_NULLPTR);
	~LoginAvatarWid();
	LoginAvatarWid(LoginAvatarWid&)=delete;
	LoginAvatarWid&operator=(LoginAvatarWid&) = delete;


private:
	void paintEvent(QPaintEvent *event);
	void showEvent(QShowEvent *e);

	void InitUi();
	void InitFont();
	QPixmap avatar_pix;
	QPushButton*btn_login_state;//右下角登陆状态按钮

	Ui::LoginAvatarWid *ui;

	USER_STATE cur_state_state;
	

signals:
	void OpenLoginStateWinSig();
private slots:
    void on_btn_login_state_clicked();//状态按钮显示按钮
};

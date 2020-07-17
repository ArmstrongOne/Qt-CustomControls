//��½�����ϵ�ͷ��ť
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
	//����ͷ��ͼƬ��Ϣ
	void SetAvatarPic(QPixmap);

	//�õ��û���ǰ״̬
	USER_STATE GetUserCurState();

	//�����û���ǰ״̬
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
	QPushButton*btn_login_state;//���½ǵ�½״̬��ť

	Ui::LoginAvatarWid *ui;

	USER_STATE cur_state_state;
	

signals:
	void OpenLoginStateWinSig();
private slots:
    void on_btn_login_state_clicked();//״̬��ť��ʾ��ť
};

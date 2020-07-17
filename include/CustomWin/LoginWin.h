#pragma once
#include "CustomWin.h"
#include <QtWidgets/QWidget>
#include"Panda.h"
using namespace Panda;
namespace Ui { class LoginWin; };

class LoginAvatarWid;//��½ͷ�񴰿�
class LoginStateWid; //��½״̬��

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

	void InitUi();//ui����
	void InitFont();//�������

	QPoint          start_move_point;//�϶���ʼ��
	LoginAvatarWid* avatar_wid;//ͷ�񴰿�
	LoginStateWid*  state_wid; //״̬����

private slots:
    void on_btn_close_clicked();//�ر�
	void on_btn_min_clicked();//��С��
	
	void OpenStateMenuSlot();//��״̬ѡ����
	void ChooseStateSlot(USER_STATE);
	
};

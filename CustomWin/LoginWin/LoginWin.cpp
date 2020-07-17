#include "LoginWin.h"
#include "ui_LoginWin.h"
#include <QDesktopWidget>
#include"LoginAvatarWid.h"
#include"LoginStateWid.h"
#include<QPainter>
#include <QMouseEvent>
#include <qmath.h>
#include<QDebug>
LoginWin::LoginWin(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::LoginWin();
	ui->setupUi(this);

	//注册类型
	qRegisterMetaType<USER_STATE>("USER_STATE");
	
	this->InitUi();
	this->InitFont();
}

void LoginWin::Init()
{



}

void LoginWin::Show()
{
	//移到桌面中间
	QDesktopWidget* desktop = QApplication::desktop(); // =qApp->desktop();也可以 
	this->move((desktop->width()-this->width())/2,(desktop->height() - this->height())/2);
	this->show();
}

LoginWin::~LoginWin()
{
	delete ui;
}

bool LoginWin::eventFilter(QObject *obj, QEvent *e)
{
	if (obj == ui->edit_account&&e->type() == QEvent::FocusIn)
	{
		ui->wid_account->setStyleSheet
		(
			"#wid_account"
			"{"
			"border:1px solid;"
			"border-color:rgb(80,90,196);"
			"}"
		);

		ui->lab_account_logo->setStyleSheet
		(
			"border-image: url(:/icon/Win_Login/check_account_ logo.png);"
		);
	}

	if (obj == ui->edit_account&&e->type() == QEvent::FocusOut)
	{
		ui->wid_account->setStyleSheet
		(
			"#wid_account"
			"{"
			"border:1px solid;"
			"border-top:0px;"
			"border-left:0px;"
			"border-right:0px;"
			"border-color:rgb(229, 229, 229);"
			"}"
		);


		ui->lab_account_logo->setStyleSheet
		(
			"border-image: url(:/icon/Win_Login/uncheck_account_ logo.png);"
		);
	}

	if (obj == ui->edit_password&&e->type() == QEvent::FocusIn)
	{
		ui->wid_password->setStyleSheet
		(
			"#wid_password"
			"{"
			"border:1px solid;"
			"border-color:rgb(80,90,196);"
			"}"
		);

		ui->lab_password_logo->setStyleSheet
		(
			"border-image:url(:/icon/Win_Login/check_code_logo.png);"
		);
	}

	if (obj == ui->edit_password&&e->type() == QEvent::FocusOut)
	{
		ui->wid_password->setStyleSheet
		(
			"#wid_password"
			"{"
			"border:1px solid;"
			"border-top:0	px;"
			"border-left:0px;"
			"border-right:0px;"
			"border-color:rgb(229, 229, 229);"
			"}"
		);

		ui->lab_password_logo->setStyleSheet
		(
			"border-image:url(:/icon/Win_Login/uncheck_code_logo.png);"
		);
	}
	return QWidget::eventFilter(obj, e);
}

void LoginWin::paintEvent(QPaintEvent *event)
{
	//窗口黑边
	//相当于依次画10个a值递减德矩形
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(10, 10, this->width() - 20, this->height() - 20);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(Qt::white));

	QColor color(0, 0, 0, 50);
	for (int i = 0; i < 10; i++)
	{
		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		path.addRect(10 - i, 10 - i, this->width() - (10 - i) * 2, this->height() - (10 - i) * 2);
		color.setAlpha(150 - qSqrt(i) * 50);
		/*if (i > 8)
		{
			color.setAlpha(0);
		}*/

		painter.setPen(color);
		painter.drawPath(path);
	}
}

void LoginWin::mouseMoveEvent(QMouseEvent *e)
{
	if (e->buttons()&Qt::LeftButton&&ui->wid_top->rect().contains(e->pos()))
	{
		if (-100 == start_move_point.x())
		{
		
			return;
		}
		move(e->pos() + pos() - start_move_point);
	}
}

void LoginWin::mousePressEvent(QMouseEvent *e)
{
	QMouseEvent *mouse_event;
	mouse_event = static_cast<QMouseEvent*>(e);
	if (mouse_event->button() == Qt::LeftButton)
	{
		QPoint temp_point = mouse_event->pos();
		if (ui->wid_top->rect().contains(temp_point))
		{
			start_move_point = temp_point;
		}
		else
		{
			//没点到拖动栏上的点统一标记为(-100,-100);用这个判断move事件
			start_move_point.setX(-100);
			start_move_point.setY(-100);
		}
		return QWidget::mousePressEvent(e);
	}
}

void LoginWin::showEvent(QShowEvent*)
{
	//展示用 移动到父窗口中央
	QWidget*parent_wid = this->parentWidget();
	if (parent_wid == NULL)
	{
		return;
	}
	this->move((parent_wid->width()-this->width())/2, (parent_wid->height()-this->height())/2);
}

void LoginWin::InitUi()
{
	//无边框
	this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->setStyleSheet("background:rgba(0,255,255,0.0);");

	//安装事件过滤器
	//ui->wid_top->installEventFilter(this);
	ui->edit_account->installEventFilter(this);
	ui->edit_password->installEventFilter(this);

	//头像窗口
	avatar_wid = new LoginAvatarWid(this);
	connect(avatar_wid, SIGNAL(OpenLoginStateWinSig()), this, SLOT(OpenStateMenuSlot()));
	avatar_wid->resize(70, 70);
	//获取登陆配置文件头像
	QPixmap pix(":/icon/Win_Login/Login_Avatar.png");
	avatar_wid->SetAvatarPic(pix);

	//移动到中间位置
	int avatar_wid_pos_x =(this->width()-avatar_wid->width())/2;
	int avatar_wid_pos_y = ui->wid_top->height() - avatar_wid->width() / 2 + 5;//5是外层margin
	avatar_wid->move(avatar_wid_pos_x, avatar_wid_pos_y);

	//状态窗口
	state_wid = new LoginStateWid(this);
	connect(state_wid, SIGNAL(ChooseState(USER_STATE)), this, SLOT(ChooseStateSlot(USER_STATE)));
	state_wid->hide();
	//移动到avatar_wid右下角
	state_wid->move(QPoint(avatar_wid->pos().x() + avatar_wid->width()-5, avatar_wid->pos().y() + avatar_wid->height()-5));
}

void LoginWin::InitFont()
{
	QFont font_chinese_2;
	font_chinese_2.setPixelSize(14);
	font_chinese_2.setFamily(QString::fromUtf8("黑体"));

	QFont font_chinese_3;
	font_chinese_3.setPixelSize(10);
	font_chinese_3.setFamily(QString::fromUtf8("黑体"));


	//账号输入
	ui->edit_account->setFont(font_chinese_2);
	//密码输入
	ui->edit_password->setFont(font_chinese_2);

	//自动登陆
	ui->checkbtn_auto_login->setFont(font_chinese_3);
	//记住密码
	ui->checkbtn_remb_password->setFont(font_chinese_3);
	//找回密码
	ui->btn_search_password->setFont(font_chinese_3);
	//注册账号
	ui->btn_register->setFont(font_chinese_3);
	//登陆
	ui->pushButton->setFont(font_chinese_2);
}

void LoginWin::on_btn_close_clicked()
{
	qApp->quit();
}

void LoginWin::on_btn_min_clicked()
{
	this->showMinimized();
}

void LoginWin::OpenStateMenuSlot()
{
	state_wid->show();
}

void LoginWin::ChooseStateSlot(USER_STATE state)
{
	avatar_wid->SetUserCurState(state);
}

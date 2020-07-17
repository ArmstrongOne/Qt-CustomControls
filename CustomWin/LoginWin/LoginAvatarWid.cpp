#include "LoginAvatarWid.h"
#include "ui_LoginAvatarWid.h"
#include <QIcon>
#include <QPainter>
#include <QApplication>
#include <QStyle>
void LoginAvatarWid::SetAvatarPic(QPixmap pixmap)
{
	this->avatar_pix = pixmap;
}

USER_STATE LoginAvatarWid::GetUserCurState()
{
	return cur_state_state;
}

void LoginAvatarWid::SetUserCurState(USER_STATE curstate)
{
	switch (curstate)
	{
	case State_Online:
		btn_login_state->setStyleSheet("border-image: url(:/icon/Win_Login/state_online.png);");
		break;
	case State_Leave:
		btn_login_state->setStyleSheet("border-image: url(:/icon/Win_Login/state_leave.png);");
		break;
	case State_Busy:
		btn_login_state->setStyleSheet("border-image: url(:/icon/Win_Login/state_busy.png);");
		break;
	case State_NotDisturb:
		btn_login_state->setStyleSheet("border-image: url(:/icon/Win_Login/state_ban.png);");
		break;
	case State_InVisable:
		btn_login_state->setStyleSheet("border-image: url(:/icon/Win_Login/state_yinshen.png);");
		break;
	default:
		break;
	}
	this->cur_state_state = curstate;
}

LoginAvatarWid::LoginAvatarWid(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::LoginAvatarWid();
	ui->setupUi(this);

	cur_state_state = State_Online;//默认选择在线状态
	this->InitUi();
	this->InitFont();
}

void LoginAvatarWid::paintEvent(QPaintEvent *event)
{
	if (avatar_pix.isNull())
	{
		//是否为空图像
		//是 用qt内置图像填充pixmap
		QStyle* style = QApplication::style();
		QIcon openPicture = style->standardIcon(QStyle::SP_TitleBarMenuButton);
		//openPicture.seticonsize(QSize(70, 70));
		avatar_pix = openPicture.pixmap(QSize(70, 70));
	}
	QPixmap res = avatar_pix.scaled(this->width(), this->height(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setRenderHint(QPainter::HighQualityAntialiasing);
	painter.setRenderHint(QPainter::SmoothPixmapTransform);

	QPainterPath path;
	int radius = 45;
	path.addRoundedRect(0, 0, this->width(), this->height(), radius, radius);
	painter.setClipPath(path);
	painter.drawPixmap(0, 0, res);
}

void LoginAvatarWid::showEvent(QShowEvent *e)
{
	//始终将状态按钮移动到 右下角
	btn_login_state->move(this->width() -btn_login_state->width(), this->height() - btn_login_state->height());
}

void LoginAvatarWid::InitUi()
{
	this->btn_login_state = ui->btn_login_state;

	//去边框
	this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏

	//固定大小
	this->resize(70, 70);
}

void LoginAvatarWid::InitFont()
{

}

void LoginAvatarWid::on_btn_login_state_clicked()
{
	emit OpenLoginStateWinSig();
}

LoginAvatarWid::~LoginAvatarWid()
{
	delete ui;
}

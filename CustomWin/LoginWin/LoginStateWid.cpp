#include "LoginStateWid.h"
#include "ui_LoginStateWid.h"
#include <QMetaType>
#include <QPainter>
#include <QtMath>
#include <QPainterPath>
LoginStateWid::LoginStateWid(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::LoginStateWid();
	ui->setupUi(this);
}

LoginStateWid::~LoginStateWid()
{
	delete ui;
}

void LoginStateWid::paintEvent(QPaintEvent *event)
{
	//窗口黑边
	//相当于依次画10个a值递减的矩形
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

void LoginStateWid::on_radiobtn_state_online_clicked()
{
	emit ChooseState(State_Online);
	this->close();
}

void LoginStateWid::on_radiobtn_state_leave_clicked()
{
	emit ChooseState(State_Leave);
	this->close();
}

void LoginStateWid::on_radiobtn_state_busy_clicked()
{
	emit ChooseState(State_Busy);
	this->close();
}

void LoginStateWid::on_radiobtn_state_notdisturb_clicked()
{
	emit ChooseState(State_NotDisturb);
	this->close();
}

void LoginStateWid::on_radiobtn_state_invisable_clicked()
{
	emit ChooseState(State_InVisable);
	this->close();
}

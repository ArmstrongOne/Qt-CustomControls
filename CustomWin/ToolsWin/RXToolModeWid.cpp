#include "RXToolModeWid.h"
#include "ui_RXToolModeWid.h"
RXToolModeWid::RXToolModeWid(QWidget *parent):QWidget(parent)
{
	ui = new Ui::RXToolModeWid();
	ui->setupUi(this);

	mode = IniFileModifyMode;
}

RXToolModeWid::~RXToolModeWid()
{
	delete ui;
}

void RXToolModeWid::SetTopLabText(QString str)
{
	ui->top_lab->setText(str);
}

void RXToolModeWid::SetBottomLabText(QString str)
{
	ui->bottom_lab->setText(str);
}

void RXToolModeWid::SetIcon(QString pic_path)
{
	QString new_str = "border-image: url(" + pic_path +");";
	ui->pic_lab->setStyleSheet(new_str);
}

void RXToolModeWid::SetButtonMdoe(ButtonMode mode)
{
	this->mode = mode;
}

void RXToolModeWid::showEvent(QShowEvent *e)
{


}

void RXToolModeWid::leaveEvent(QEvent* event)
{
	ui->main_wid->setStyleSheet("#main_wid{border:1px solid;border-color:rgb(216, 216, 216);background-color:rgb(241,241,241);}");
	ui->widget->setStyleSheet("background-color: rgb(241, 241, 241);");
	ui->widget_2->setStyleSheet("background-color: rgb(241, 241, 241);");
}

void RXToolModeWid::enterEvent(QEvent *event)
{
	ui->main_wid->setStyleSheet("#main_wid{border:1px solid;border-color:rgb(79, 182, 254);background-color:rgb(236, 247, 255);}");
	ui->widget->setStyleSheet("background-color: rgb(236, 247, 255);");
	ui->widget_2->setStyleSheet("background-color: rgb(236, 247, 255);");
}

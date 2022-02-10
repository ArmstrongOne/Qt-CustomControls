#include "RectProgressBar.h"
#include "ui_RectProgressBar.h"
#include<QResizeEvent>
#include<QPainter>
#include <QPainterPath>
RectProgressBar::RectProgressBar(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::RectProgressBar;
	ui->setupUi(this);

	progressbar_border_radius_x = 0;
	progressbar_border_radius_y = 0;
	label_border_radius_x = 0;
	label_border_radius_y = 0;

	m_margin_left = 0;
	m_margin_right=0;  //控件到右边距离
	m_margin_top=0;    //控件到顶部距离
	m_margin_bottom=0; //控件到底边距离

	space = 0;
	progressbar_height = 0;

	cur_value = 0;
}

RectProgressBar::~RectProgressBar()
{
	delete ui;
}

void RectProgressBar::SetMargin(int m_margin_left, int m_margin_right, int m_margin_top, int m_margin_bottom)
{
	this->m_margin_left = m_margin_left;
	this->m_margin_right = m_margin_right;
	this->m_margin_top = m_margin_top;
	this->m_margin_bottom = m_margin_bottom;
}

void RectProgressBar::SetSpace(int value)
{
	this->space = value;
}

void RectProgressBar::SetProgressbarHeight(int value)
{
	this->progressbar_height = value;
}

void RectProgressBar::SetProgressBarColor(QColor background_color, QColor selected_color)
{
	this->background_color = background_color;
	this->selected_color = selected_color;
}

void RectProgressBar::SetLabelProperty(QColor font_color, QColor font_background_color, QFont font)
{
	this->font_color = font_color;
	this->label_background_color = font_background_color;
	this->font = font;
}

void RectProgressBar::SetBorderRadius(int progressbar_border_radius_x, int progressbar_border_radius_y, int label_border_radius_x, int label_border_radius_y)
{
	this->progressbar_border_radius_x = progressbar_border_radius_x;
	this->progressbar_border_radius_y = progressbar_border_radius_y;
	this->label_border_radius_x = label_border_radius_x;
	this->label_border_radius_y = label_border_radius_y;
}

void RectProgressBar::SetPanValue(int value)
{
	cur_value = value;
}

void RectProgressBar::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;

    //备注：选中矩形不变 实时在变的是背景矩形

	//画选中滚动条矩形
	painter.setBrush(selected_color);
	painter.drawRoundRect(progressbar_rect, progressbar_border_radius_x, progressbar_border_radius_y);

	//画Lab
	painter.setBrush(label_background_color);
	painter.drawRoundRect(lab_rect, label_border_radius_x, label_border_radius_y);


     //画背景的矩形
	double selected_height = (1-(double)cur_value/100)*progressbar_rect.height();
	selected_rect.setX(progressbar_rect.x());
	selected_rect.setY(progressbar_rect.y());
	selected_rect.setHeight(selected_height);
	selected_rect.setWidth(progressbar_rect.width());

	painter.setBrush(background_color);
	
	//大路径减去小路径 确保能截除圆角矩形
	QPainterPath big_path;
	big_path.addRoundRect(progressbar_rect,progressbar_border_radius_x,progressbar_border_radius_y);

	QPainterPath small_path;
	small_path.addRect(selected_rect);

	QPainterPath new_path;
	new_path = big_path.intersected(small_path);

	painter.drawPath(new_path);
	

	//画文字
	painter.setFont(font);
	painter.setPen(QColor(font_color));
	painter.drawText(lab_rect, Qt::AlignCenter, QString::number(cur_value) + "%");
	this->update();
}

void RectProgressBar::resizeEvent(QResizeEvent* size)
{
	//设置完整滚动条框
	progressbar_rect.setX(m_margin_left);
	progressbar_rect.setY(this->height()-m_margin_bottom-progressbar_height);
	progressbar_rect.setWidth(this->width() - m_margin_left - m_margin_right);
	progressbar_rect.setHeight(progressbar_height);

	//设置lab矩形
	lab_rect.setX(m_margin_left);
	lab_rect.setY(m_margin_top);
	lab_rect.setWidth(this->width() - m_margin_left - m_margin_right);
	lab_rect.setHeight(this->height()-m_margin_top-m_margin_bottom-space-progressbar_height);



}

#include "NetSpeedPanel.h"
#include<QResizeEvent>
#include <QPainter>
#include <math.h>
#include <qmath.h>
#include <qDebug>
#include "ui_NetSpeedPanel.h"
#pragma execution_character_set("utf-8")
NetSpeedPanel::NetSpeedPanel(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::NetSpeedPanel;
	ui->setupUi(this);
}

NetSpeedPanel::~NetSpeedPanel()
{
	delete ui;
}

void NetSpeedPanel::SetBorderPropert(int border_width, QColor color)
{
	this->border_width = border_width;
	this->border_color = color;
}

void NetSpeedPanel::SetScaleFont(QFont scale_font)
{
	this->scale_font = scale_font;
}

void NetSpeedPanel::SetPanelColor(QColor color)
{
	this->panel_color = color;
}

void NetSpeedPanel::SetScaleNumColor(QColor scale_number_color)
{
	this->scale_number_color = scale_number_color;
}

void NetSpeedPanel::SetScaleColor(QColor scale_color)
{
	this->scale_color = scale_color;
}

void NetSpeedPanel::SetMajorScaleProperty(int width, int length)
{
	this->major_scale_width = width;
	this->major_scale_length = length;
}

void NetSpeedPanel::SetMinorScaleProperty(int width, int length)
{
	this->minor_scale_width = width;
	this->minor_scale_length = length;
}

void NetSpeedPanel::SetMajorCount(int count/*=10*/)
{
	this->major_count = count;
}

void NetSpeedPanel::SetMinorCount(int count/*=10*/)
{
	this->minor_count = count;
}

void NetSpeedPanel::SetMinValue(int min_value/*=0*/)
{
	this->min_value = min_value;
}

void NetSpeedPanel::SetMaxValue(int max_value /*= 100*/)
{
	this->max_value = max_value;
}

void NetSpeedPanel::SetStartAngle(int start_angle /*= 60*/)
{
	this->start_angle = start_angle;
}

void NetSpeedPanel::SetEndAngle(int end_angle /*= 60*/)
{
	this->end_angle = end_angle;
}

void NetSpeedPanel::SetCurValue(int cur_value)
{
	if (cur_value > max_value || cur_value < min_value)
	{
		return;
	}
	this->cur_value = cur_value;
}

void NetSpeedPanel::SetTextPosition(int y)
{
	this->text_y = y;
}

void NetSpeedPanel::SetTextFont(QFont font)
{
	this->text_font = font;
}

void NetSpeedPanel::SetTextColor(QColor color)
{
	this->text_color = color;
}

void NetSpeedPanel::SetTitlePosition(int title_y)
{
	this->title_y = title_y;
}

void NetSpeedPanel::SetTitleFont(QFont title_font)
{
	this->title_font = title_font;
}

void NetSpeedPanel::SetTitleColor(QColor title_color)
{
	this->title_color = title_color;
}

void NetSpeedPanel::SetTitleStr(QString title_str)
{
	this->title_str = title_str;
}

void NetSpeedPanel::SetSpaceBorderToScale(int space_border_scale)
{
	this->space_border_scale = space_border_scale;
}

void NetSpeedPanel::SetSpaceScaleToScalenum(int spcae_scale_scalenum)
{
	this->spcae_scale_scalenum = spcae_scale_scalenum;
}

void NetSpeedPanel::SetCenterRadius(int center_radius)
{
	this->center_radius = center_radius;
}

void NetSpeedPanel::SetPointerProperty(int pointer_width, int pointer_length)
{
	this->pointer_width = pointer_width;
	this->pointer_length = pointer_length;
}

void NetSpeedPanel::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

	//设置透明笔
	painter.setPen(QColor(1, 1, 1, 0));

	//画三个扇形
	painter.setBrush(QColor(0, 190, 137));
	int startAngle = 3360;
	int spanAngle = -1280;  
	QRect rect(0, 0, out_cir_radius*2, out_cir_radius*2);
	painter.drawPie(rect, startAngle, spanAngle);

	painter.setBrush(QColor(14, 187, 250));
	painter.drawPie(rect, 2080, spanAngle);

	painter.setBrush(QColor(253, 32, 118));
	painter.drawPie(rect, 800, spanAngle);

	painter.setBrush(QColor(220, 220, 220));
	painter.drawPie(rect, 3360, 1920);


	//设置盘的渐变色画中心点
	QRadialGradient Radial(out_cir_radius, out_cir_radius, out_cir_radius, out_cir_radius, out_cir_radius);    //设置圆的原点和焦点在中心,半径120

	Radial.setColorAt(0, QColor(0,81,128));
	Radial.setColorAt(0.6, QColor(0,30,60));        
	Radial.setColorAt(1, QColor(0, 19,46));
	painter.setBrush(Radial);
	painter.drawEllipse(out_cir_radius-in_cir_radius,out_cir_radius-in_cir_radius,2*in_cir_radius,2*in_cir_radius);
	
	painter.translate(0 + out_cir_radius, 0 + out_cir_radius);//将圆中心设为原点

	 //开始绘制
	drawScaleNum(&painter);//绘制数字
	drawScale(&painter);//绘制刻度
	drawText(&painter);//画文字
	drawTitle(&painter);//画文字
	drawIndicator(&painter);//画指针和中心点

	this->update();
}



void NetSpeedPanel::drawBackground(QPainter *painter)
{

}

void NetSpeedPanel::drawScale(QPainter *painter)
{
	if (0 == minor_count)
	{
		return;
	}

	//目前只画了大刻度 有需要自己修改下面代码 不做成借口了
	painter->save();
	//先"顺时针"旋转坐标系到开始的角度
	painter->rotate(start_angle);
	int steps = (major_count * minor_count); //相乘后的值是分的份数 
	double angleStep = (360.0 - start_angle - end_angle) / steps; //每一个份数的角度

	QPen pen;
	//pen.setColor(scale_color);

	for (int i = 0; i <= steps; i++)
	{
		if (i <= 2)
		{
			pen.setColor(QColor(0, 190, 137));
		}
		else if (i <= 4)
		{
			pen.setColor(QColor(14, 187, 250));
		}
		else if (i <= 6)
		{
			pen.setColor(QColor(253, 32, 118));
		}

		if (i%minor_count == 0)//整数刻度显示加粗 
		{
			pen.setWidth(major_scale_width); //设置线宽 
			painter->setPen(pen);
			painter->drawLine(0, in_cir_radius- space_border_scale, 0, in_cir_radius - space_border_scale - major_scale_length); //两个参数应该是两个坐标值
		}
		else
		{
			pen.setWidth(1);
			painter->setPen(pen);
			painter->drawLine(0, in_cir_radius- space_border_scale, 0, in_cir_radius- space_border_scale - minor_scale_length);
		}
		//顺时针旋转坐标系
		painter->rotate(angleStep);
	}
	painter->restore();
}

void NetSpeedPanel::drawScaleNum(QPainter *painter)
{
	int radius = in_cir_radius - space_border_scale - major_scale_length- spcae_scale_scalenum;
	painter->save();
	painter->setPen(QColor(170,230,250));

	//初始角度去单位 (以6点钟方向为0度)
	double startRad = start_angle*(M_PI / 180);
	//这个表示刻度横跨一格的度数
	double deltaRad = (360 - start_angle - end_angle)*(M_PI / 180) / major_count;
	//横跨多少格就循环多少次
	for (int i = 0; i <= major_count; i++)
	{
		double angle_value = startRad + i*deltaRad;
		double sina = 0;
		double cosa = 0;

		//为了正负号问题 索性分象限解决问题
		if (angle_value >= 0 && angle_value < M_PI / 2)  //左下象限
		{
			sina = -abs(qSin(angle_value));
			cosa = abs(qCos(angle_value));
		}
		else if (angle_value >= M_PI / 2 && angle_value < M_PI)  //左上象限
		{
			sina = -abs(qSin(M_PI - angle_value));
			cosa = -abs(qCos(M_PI - angle_value));
		}
		else if (angle_value >= M_PI&& angle_value < M_PI*0.75 * 2)  //右上象限
		{
			sina = abs(qSin(angle_value - M_PI));
			cosa = -abs(qCos(angle_value - M_PI));
		}
		else if (angle_value >= M_PI*0.75 * 2 && angle_value <= M_PI * 2)  //右下象限
		{
			sina = abs(qSin(M_PI * 2 - angle_value));
			cosa = abs(qCos(M_PI * 2 - angle_value));
		}

		//数值

		if (0 == major_count)
		{
			return;
		}
		double value = 1.0*i*((max_value - min_value)/major_count) + min_value;

		QString strValue = QString("%1").arg((double)value, 0, 'f', 0)+"M";

		//获取这个字体在特定字号下的宽高(宽可能有多个字符串所以获取要传入str 高就一个字所以不需要传)
		QFontMetrics fm(scale_font);
		double textWidth = fm.width(strValue);
		double textHeight = fm.height();

		//减去相应的文字宽高
		int x = radius * sina - textWidth / 2;
		int y = radius * cosa + textHeight / 4;

		//设置字体画文字
		painter->setFont(scale_font);
		painter->drawText(x, y, strValue);
	}

	//恢复painter属性
	painter->restore();
}

void NetSpeedPanel::drawText(QPainter *painter)
{
	painter->save();

	QPen pen;
	pen.setColor(text_color);
	painter->setPen(pen);
	painter->setFont(text_font);

	QString str = QString::number(cur_value) + QString::fromUtf8("Mbps/s");
	QFontMetrics fm(text_font);
	double textWidth = fm.width(str);
	double textHeight = fm.height();
	painter->drawText(0 - textWidth / 2, text_y, str);

	painter->restore();
}

void NetSpeedPanel::drawTitle(QPainter *painter)
{
	painter->save();

	QPen pen;
	pen.setColor(title_color);
	painter->setPen(pen);
	painter->setFont(title_font);

	QFontMetrics fm(title_font);
	double textWidth = fm.width(title_str);
	double textHeight = fm.height();
	painter->drawText(0 - textWidth / 2, title_y, title_str);

	painter->restore();
}

void NetSpeedPanel::drawIndicator(QPainter *painter)
{
	painter->save();
	QPolygon pts;

	pts.setPoints(4,-1*pointer_width/2,0,0, int(-1*2*1.7*(pointer_width/2)),pointer_width/2,0,0,pointer_length);/* (-2,0)/(2,0)/(0,60) *///第一个参数是 ，坐标的个数。后边的是坐标
	painter->rotate(start_angle);
	//根据当前值旋转的角度
	double degRotate = (360.0 - start_angle - end_angle) / (max_value - min_value)*(cur_value - min_value);
	//画指针
	painter->rotate(degRotate);  //顺时针旋转坐标系统

	painter->setPen(Qt::white); //定义线条文本颜色  设置线条的颜色
	painter->setBrush(QColor(177,214,245));//刷子定义形状如何填满 填充后的颜色
	painter->drawConvexPolygon(pts); //这是个重载函数，绘制多边形。
	painter->restore();

	//画中心点
	QColor niceBlue(150, 150, 200);
	QConicalGradient coneGradient(0, 0, -90.0);  //角度渐变
	coneGradient.setColorAt(0.0, Qt::darkGray);
	coneGradient.setColorAt(0.2, niceBlue);
	coneGradient.setColorAt(0.5, Qt::white);
	coneGradient.setColorAt(1.0, Qt::darkGray);
	painter->setPen(Qt::NoPen);  //没有线，填满没有边界
	painter->setBrush(coneGradient);
	painter->drawEllipse(-1 * center_radius, -1 * center_radius, 2 * center_radius, 2 * center_radius);
}

void NetSpeedPanel::drawNumericValue(QPainter *painter)
{

}


void NetSpeedPanel::resizeEvent(QResizeEvent* size)
{
	//获取自身控件大小
	this->width = size->size().width();
	this->height = size->size().height();

	//向下取整 确保是偶数
	if (this->width % 2 != 0)
	{
		this->width--;
	}
	if (this->height % 2 != 0)
	{
		this->height--;
	}

	//获取合理的外圆半径
	if (this->width > this->height)
	{
		out_cir_radius = this->height / 2;
	}
	else
	{
		out_cir_radius = this->width / 2;
	}

	//获取合理的内圆半径
	in_cir_radius = out_cir_radius - border_width;
}

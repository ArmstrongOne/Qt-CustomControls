#include "SemiCirclePanel.h"
#include<QResizeEvent>
#include <QPainter>
#include <math.h>
#include <qmath.h>
#include<QDebug>
#include "ui_SemiCirclePanel.h"
#pragma execution_character_set("utf-8")
SemiCirclePanel::SemiCirclePanel(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::SemiCirclePanel;
	ui->setupUi(this);
}

SemiCirclePanel::~SemiCirclePanel()
{
}

void SemiCirclePanel::SetBorderPropert(int border_width, QColor color)
{
	this->border_width = border_width;
	this->border_color = color;
}

void SemiCirclePanel::SetScaleFont(QFont scale_font)
{
	this->scale_font = scale_font;
}

void SemiCirclePanel::SetPanelColor(QColor color)
{
	this->panel_color = color;
}

void SemiCirclePanel::SetScaleNumColor(QColor scale_number_color)
{
	this->scale_number_color = scale_number_color;
}

void SemiCirclePanel::SetScaleColor(QColor scale_color)
{
	this->scale_color = scale_color;
}

void SemiCirclePanel::SetMajorScaleProperty(int width, int length)
{
	this->major_scale_width = width;
	this->major_scale_length = length;
}

void SemiCirclePanel::SetMinorScaleProperty(int width, int length)
{
	this->minor_scale_width = width;
	this->minor_scale_length = length;
}

void SemiCirclePanel::SetMajorCount(int count/*=10*/)
{
	this->major_count = count;
}

void SemiCirclePanel::SetMinorCount(int count/*=10*/)
{
	this->minor_count = count;
}

void SemiCirclePanel::SetMinValue(int min_value/*=0*/)
{
	this->min_value = min_value;
}

void SemiCirclePanel::SetMaxValue(int max_value /*= 100*/)
{
	this->max_value = max_value;
}

void SemiCirclePanel::SetStartAngle(int start_angle /*= 60*/)
{
	this->start_angle = start_angle;
}

void SemiCirclePanel::SetEndAngle(int end_angle /*= 60*/)
{
	this->end_angle = end_angle;
}

void SemiCirclePanel::SetCurValue(int cur_value)
{
	if (cur_value > max_value || cur_value < min_value)
	{
		return;
	}
	this->cur_value = cur_value;
}

void SemiCirclePanel::SetTextPosition(int y)
{
	this->text_y = y;
}

void SemiCirclePanel::SetTextFont(QFont font)
{
	this->text_font = font;
}

void SemiCirclePanel::SetTextColor(QColor color)
{
	this->text_color = color;
}

void SemiCirclePanel::SetTitlePosition(int title_y)
{
	this->title_y = title_y;
}

void SemiCirclePanel::SetTitleFont(QFont title_font)
{
	this->title_font = title_font;
}

void SemiCirclePanel::SetTitleColor(QColor title_color)
{
	this->title_color = title_color;
}

void SemiCirclePanel::SetTitleStr(QString title_str)
{
	this->title_str = title_str;
}

void SemiCirclePanel::SetSpaceBorderToScale(int space_border_scale)
{
	this->space_border_scale = space_border_scale;
}

void SemiCirclePanel::SetSpaceScaleToScalenum(int spcae_scale_scalenum)
{
	this->spcae_scale_scalenum = spcae_scale_scalenum;
}

void SemiCirclePanel::SetCenterRadius(int center_radius)
{
	this->center_radius = center_radius;
}

void SemiCirclePanel::SetPointerProperty(int pointer_width, int pointer_length)
{
	this->pointer_width = pointer_width;
	this->pointer_length = pointer_length;
}

void SemiCirclePanel::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

	//设置透明笔
	painter.setPen(QColor(1, 1, 1, 0));

	//绘制外圆
	QConicalGradient conicalGradient0(out_cir_center_x, out_cir_center_y, 0);
	conicalGradient0.setColorAt(0, QColor(220, 220, 220));
	conicalGradient0.setColorAt(0.4, QColor(0, 81, 128));
	conicalGradient0.setColorAt(0.5, QColor(220, 220, 220));
	conicalGradient0.setColorAt(0.6, QColor(0, 81, 128));
	conicalGradient0.setColorAt(1, QColor(220, 220, 220));
	painter.setBrush(conicalGradient0);
	painter.drawEllipse(out_cir_x, out_cir_y, 2 * out_cir_radius, 2 * out_cir_radius);

	//一下部分为写死的 根据需要重写放出接口
	//绘制渐变扇形
	//设置盘的渐变色画中心点
	QRadialGradient Radial(out_cir_x+out_cir_radius, out_cir_y+out_cir_radius, out_cir_radius, out_cir_y + out_cir_radius, out_cir_y + out_cir_radius);    //设置圆的原点和焦点在中心,半径120

	Radial.setColorAt(0, QColor(0, 81, 128));
	Radial.setColorAt(0.8, QColor(0, 81, 128));
	Radial.setColorAt(0.9, QColor(80, 80, 80));
	Radial.setColorAt(1, QColor(60, 60, 60));
	painter.setBrush(Radial);
	painter.drawEllipse(out_cir_x + out_cir_radius - in_cir_radius, out_cir_y + out_cir_radius - in_cir_radius, 2 * in_cir_radius, 2 * in_cir_radius);

	//画当前数值扇形
	int startAngle = 2880;
	int spanAngle = (double)cur_value / 100 * 2880;  //旋转角也是朝逆时针增长的
													 //矩形区域 因为长和宽被优化过了 需要重新设置
	QRect rect(out_cir_x + out_cir_radius - in_cir_radius, out_cir_y + out_cir_radius - in_cir_radius, 2 * in_cir_radius, 2 * in_cir_radius);
	
	double index = (double)(100-cur_value)/100*180;
	QConicalGradient conicalGradient_orange(out_cir_center_x, out_cir_center_y, index);//这第三个参数和数学里坐标系一样90度就是12点钟方位 逆时针渐变

	conicalGradient_orange.setColorAt(0, QColor(255,200,1,150));   //255 200 1
	conicalGradient_orange.setColorAt(0.1, QColor(220, 220,220,0));
	//conicalGradient_orange.setColorAt(1, QColor(255, 255, 255,0));
	painter.setBrush(conicalGradient_orange);
	painter.drawPie(rect, startAngle, -spanAngle);//符号代表顺时针滑动

	//绘制内圆1
	int border1 = 46;
	QConicalGradient conicalGradient(out_cir_center_x, out_cir_center_y, 0);
	conicalGradient.setColorAt(0, QColor(255, 255, 255));
	conicalGradient.setColorAt(0.3, QColor(100, 100, 100));
	conicalGradient.setColorAt(0.5, QColor(255, 255, 255));
	conicalGradient.setColorAt(0.8, QColor(100, 100, 100));
	conicalGradient.setColorAt(1, QColor(255, 255, 255));
	//从圆心的0度角开始逆时针填充
	painter.setBrush(conicalGradient);
	painter.drawEllipse(out_cir_x + out_cir_radius - in_cir_radius+ border1, out_cir_y + out_cir_radius - in_cir_radius+ border1, 2*(in_cir_radius- border1), 2 * (in_cir_radius- border1));
	
	//绘制内圆2
	int border2 = 2;
	painter.setBrush(QColor(0,0,0));
	painter.drawEllipse(out_cir_x + out_cir_radius - in_cir_radius + border1+border2, out_cir_y + out_cir_radius - in_cir_radius + border1 + border2, 2 * (in_cir_radius - border1-border2), 2 * (in_cir_radius - border1-border2));

	//将圆中心设为原点	
	painter.translate(out_cir_center_x, out_cir_center_y);												  
	//开始绘制
	drawScaleNum(&painter);//绘制数字
	drawScale(&painter);//绘制刻度
	drawTitle(&painter);//画文字
	drawIndicator(&painter);//画指针和中心点
	drawText(&painter);//画文字
	this->update();
}

void SemiCirclePanel::drawBackground(QPainter *painter)
{

}

void SemiCirclePanel::drawScale(QPainter *painter)
{
	//目前只画了大刻度 有需要自己修改下面代码 不做成借口了
	painter->save();
	//先"顺时针"旋转坐标系到开始的角度
	painter->rotate(start_angle);
	int steps = (major_count * minor_count);//相乘后的值是分的份数 
	double angleStep = (360.0-start_angle-end_angle)/steps; //每一个份数的角度

	QPen pen;
	pen.setColor(scale_color);

	for (int i = 0; i <= steps; i++)
	{
		if (i%minor_count == 0)//整数刻度显示加粗 
		{
			pen.setWidth(major_scale_width); //设置线宽 
			painter->setPen(pen);
			painter->drawLine(0, in_cir_radius - space_border_scale, 0, in_cir_radius - space_border_scale - major_scale_length); //两个参数应该是两个坐标值
		}
		else
		{
			pen.setWidth(1);
			painter->setPen(pen);
			painter->drawLine(0, in_cir_radius - space_border_scale, 0, in_cir_radius - space_border_scale - minor_scale_length);
		}
		//顺时针旋转坐标系
		painter->rotate(angleStep);
	}
	painter->restore();
}

void SemiCirclePanel::drawScaleNum(QPainter *painter)
{
	int radius = in_cir_radius - space_border_scale - major_scale_length - spcae_scale_scalenum;
	painter->save();
	painter->setPen(scale_number_color);

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
		double value = 1.0*i*((max_value - min_value) / major_count) + min_value;

		QString strValue = QString("%1").arg((double)value, 0, 'f', 0);

		//获取这个字体在特定字号下的宽高(宽可能有多个字符串所以获取要传入str 高就一个字所以不需要传)
		QFontMetrics fm(scale_font);
		double textWidth = fm.width(strValue);
		double textHeight = fm.height();

		//减去相应的文字宽高
		int x = radius * sina - textWidth / 2;
		int y = radius * cosa + textHeight / 4;

		//设置字体画文字
		painter->setFont(scale_font);

		if (value == min_value || value == max_value)
		{
			painter->drawText(x, y- textHeight/2, strValue);
		}
		else
		{
			painter->drawText(x, y, strValue);
		}
	}

	//恢复painter属性
	painter->restore();
}

void SemiCirclePanel::drawText(QPainter *painter)
{
	painter->save();

	QPen pen;
	pen.setColor(text_color);
	painter->setPen(pen);
	painter->setFont(text_font);

	QString str = QString::number(cur_value);
	QFontMetrics fm(text_font);
	double textWidth = fm.width(str);
	double textHeight = fm.height();
	painter->drawText(0 - textWidth / 2, text_y, str);

	painter->restore();
}

void SemiCirclePanel::drawTitle(QPainter *painter)
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

void SemiCirclePanel::drawIndicator(QPainter *painter)
{
	painter->save();
	QPolygon pts;
	pts.setPoints(4, -1 * pointer_width / 2, 0, 0, int(-1 * 2 * 1.7*(pointer_width / 2)), pointer_width / 2, 0, 0, pointer_length);/* (-2,0)/(2,0)/(0,60) *///第一个参数是 ，坐标的个数。后边的是坐标

	painter->rotate(start_angle);
	//根据当前值旋转的角度
	double degRotate = (360.0 - start_angle - end_angle) / (max_value - min_value)*(cur_value - min_value);
	
	//画指针
	painter->rotate(degRotate);  //顺时针旋转坐标系统
	QRadialGradient haloGradient(0, 0, 60, 0, 0);  //辐射渐变
	haloGradient.setColorAt(0, QColor(60, 60, 60));
	haloGradient.setColorAt(1, QColor(255, 0, 0)); //灰

	QPen pen;
	pen.setColor(QColor(0,0,0,0));
	pen.setWidth(0);
	painter->setPen(pen); //定义线条文本颜色  设置线条的颜色
	painter->setBrush(haloGradient);//刷子定义形状如何填满 填充后的颜色
	painter->drawConvexPolygon(pts); //这是个重载函数，绘制多边形。

	//画中心点
	QColor niceBlue(150, 150, 200);
	QRadialGradient conicalGradient(0, 0, center_radius,0,0,0);
	conicalGradient.setColorAt(0, QColor(255, 255, 255));
	conicalGradient.setColorAt(0.8, QColor(255, 255, 255));
	conicalGradient.setColorAt(0.9, QColor(0, 81, 128));
	conicalGradient.setColorAt(1, QColor(0, 0, 0));
	painter->setPen(Qt::NoPen);  //没有线，填满没有边界
	painter->setBrush(conicalGradient);
	painter->drawEllipse(-1 * center_radius, -1 * center_radius, 2 * center_radius, 2 * center_radius);

	//画中心覆盖点
	int radius= center_radius-10;
	painter->setBrush(QColor(0,0,0));
	painter->drawEllipse(-1* radius,-1* radius, 2 * radius, 2 * radius);





	painter->restore();
}

void SemiCirclePanel::drawNumericValue(QPainter *painter)
{

}


void SemiCirclePanel::resizeEvent(QResizeEvent* size)
{
	//获取自身控件大小
	this->width = size->size().width();
	this->height = size->size().height();

	//宽大于2倍高
	if (this->width/2>this->height)
	{
		if (width % 2 != 0)
		{
			width = width - 1;
		}
		out_cir_radius = height;
		//左上角点
		out_cir_x = 0;
		out_cir_y = 0;

		//中心点
		out_cir_center_x = out_cir_radius;
		out_cir_center_y = out_cir_radius;
	}
	else
	{
		if (width % 2 != 0)
		{
			width = width - 1;
		}
		out_cir_radius=width/2;

		//左上角点
		out_cir_x = 0;
		out_cir_y = 0+height- out_cir_radius;

		//中心点
		out_cir_center_x = out_cir_radius;
		out_cir_center_y = height;
	}

	//获取合理的内圆半径
	in_cir_radius = out_cir_radius - border_width;
}

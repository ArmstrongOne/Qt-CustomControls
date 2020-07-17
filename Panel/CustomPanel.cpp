#include "CustomPanel.h"
#include<QResizeEvent>
#include <QPainter>
#include <math.h>
#include <qmath.h>
#include "ui_CustomPanel.h"
#pragma execution_character_set("utf-8")
CustomPanel::CustomPanel(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::CustomPanel;
	ui->setupUi(this);
	//初始化
	width = 0;
	height = 0;
	out_cir_radius = 0;
	in_cir_radius = 0;
	border_width = 0;
	space_border_scalenum = 0;
	spcae_scale_scalenum = 0;
	major_scale_length = 0;
	major_scale_width = 0;
	minor_scale_length = 0;
	minor_scale_width = 0;
	major_count = 0;
	minor_count = 0;
	min_value = 0;
	max_value = 0;
	start_angle = 0;
	end_angle = 0;
	cur_value = 0;
	text_y = 0;
	title_y = 0;
	center_radius = 0;
	pointer_width = 0;
	pointer_length = 0;
}

CustomPanel::~CustomPanel()
{
}

void CustomPanel::SetBorderPropert(int border_width, QColor color)
{
	this->border_width = border_width;
	this->border_color = color;
}

void CustomPanel::SetScaleFont(QFont scale_font)
{
	this->scale_font = scale_font;
}

void CustomPanel::SetPanelColor(QColor color)
{
	this->panel_color = color;
}

void CustomPanel::SetScaleNumColor(QColor scale_number_color)
{
	this->scale_number_color = scale_number_color;
}

void CustomPanel::SetScaleColor(QColor scale_color)
{
	this->scale_color = scale_color;
}

void CustomPanel::SetMajorScaleProperty(int width, int length)
{
	this->major_scale_width = width;
	this->major_scale_length = length;
}

void CustomPanel::SetMinorScaleProperty(int width, int length)
{
	this->minor_scale_width = width;
	this->minor_scale_length = length;
}

void CustomPanel::SetMajorCount(int count/*=10*/)
{
	this->major_count = count;
}

void CustomPanel::SetMinorCount(int count/*=10*/)
{
	this->minor_count = count;
}

void CustomPanel::SetMinValue(int min_value/*=0*/)
{
	this->min_value = min_value;
}

void CustomPanel::SetMaxValue(int max_value /*= 100*/)
{
	this->max_value = max_value;
}

void CustomPanel::SetStartAngle(int start_angle /*= 60*/)
{
	this->start_angle = start_angle;
}

void CustomPanel::SetEndAngle(int end_angle /*= 60*/)
{
	this->end_angle = end_angle;
}

void CustomPanel::SetCurValue(int cur_value)
{
	if (cur_value > max_value || cur_value < min_value)
	{
		return;
	}
	this->cur_value = cur_value;
}

void CustomPanel::SetTextPosition(int y)
{
	this->text_y = y;
}

void CustomPanel::SetTextFont(QFont font)
{
	this->text_font = font;
}

void CustomPanel::SetTextColor(QColor color)
{
	this->text_color = color;
}

void CustomPanel::SetTitlePosition(int title_y)
{
	this->title_y = title_y;
}

void CustomPanel::SetTitleFont(QFont title_font)
{
	this->title_font = title_font;
}

void CustomPanel::SetTitleColor(QColor title_color)
{
	this->title_color = title_color;
}

void CustomPanel::SetTitleStr(QString title_str)
{
	this->title_str = title_str;
}

void CustomPanel::SetSpaceBorderToScalenum(int space_border_scalenum)
{
	this->space_border_scalenum = space_border_scalenum;
}

void CustomPanel::SetSpaceScaleToScalenum(int spcae_scale_scalenum)
{
	this->spcae_scale_scalenum = spcae_scale_scalenum;
}

void CustomPanel::SetCenterRadius(int center_radius)
{
	this->center_radius = center_radius;
}

void CustomPanel::SetPointerProperty(int pointer_width, int pointer_length)
{
	this->pointer_width = pointer_width;
	this->pointer_length = pointer_length;
}

void CustomPanel::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

	//设置透明笔
	painter.setPen(QColor(1, 1, 1, 0));


	//绘制内外圆
	QConicalGradient conicalGradient(out_cir_radius, out_cir_radius, 0);
	//设置透明笔
	conicalGradient.setColorAt(0, QColor(255, 255, 255));
	conicalGradient.setColorAt(0.3, QColor(100, 100, 100));
	conicalGradient.setColorAt(0.5, QColor(255, 255, 255));
	conicalGradient.setColorAt(0.8, QColor(100, 100, 100));
	conicalGradient.setColorAt(1, QColor(255, 255, 255));
	painter.setBrush(conicalGradient);
	painter.drawEllipse(0, 0, 2*out_cir_radius, 2 * out_cir_radius);

	painter.setBrush(panel_color);
	painter.drawEllipse(out_cir_radius-in_cir_radius, out_cir_radius - in_cir_radius, 2 * in_cir_radius, 2 * in_cir_radius);

	painter.translate(0+out_cir_radius,0+out_cir_radius);//将圆中心设为原点
    //painter.scale(in_cir_radius *2/200.0, in_cir_radius *2/200.0); //比例缩放,这里没必要缩放

	//开始绘制
	drawScaleNum(&painter);//绘制数字
	drawScale(&painter);//绘制刻度
	drawText(&painter);//画文字
	drawTitle(&painter);//画文字
	drawIndicator(&painter);//画指针和中心点

	this->update();
}



void CustomPanel::drawBackground(QPainter *painter)
{

}

void CustomPanel::drawScale(QPainter *painter)
{
	//目前只画了大刻度 有需要自己修改下面代码 不做成借口了

	painter->save();
	//先"顺时针"旋转坐标系到开始的角度
	painter->rotate(start_angle);
	int steps = (major_count * minor_count); //相乘后的值是分的份数 
	double angleStep = (360.0- start_angle - end_angle)/steps; //每一个份数的角度

	QPen pen;
	pen.setColor(scale_color); 
	
	for (int i=0;i<= steps;i++)
	{
		if (i%minor_count ==0)//整数刻度显示加粗 
		{
			pen.setWidth(major_scale_width); //设置线宽 
			painter->setPen(pen);
			painter->drawLine(0, in_cir_radius-space_border_scalenum- spcae_scale_scalenum, 0, in_cir_radius - space_border_scalenum - spcae_scale_scalenum- major_scale_length); //两个参数应该是两个坐标值
		}
		else
		{
			pen.setWidth(1);
			painter->setPen(pen);
			painter->drawLine(0, in_cir_radius - space_border_scalenum - spcae_scale_scalenum, 0, in_cir_radius - space_border_scalenum - spcae_scale_scalenum - minor_scale_length);
		}
		//顺时针旋转坐标系
		painter->rotate(angleStep);
	}
	painter->restore();
}

void CustomPanel::drawScaleNum(QPainter *painter)
{
	int radius = in_cir_radius- space_border_scalenum;
	painter->save();
	painter->setPen(scale_number_color);

	//初始角度去单位 (以6点钟方向为0度)
	double startRad = start_angle*(M_PI/180);
	//这个表示刻度横跨一格的度数
	double deltaRad = (360- start_angle - end_angle)*(M_PI/180)/ major_count;
	//横跨多少格就循环多少次
	for (int i = 0; i <= major_count; i++)
	{
		double angle_value = startRad + i*deltaRad;
		double sina = 0;
		double cosa = 0;

		//为了正负号问题 索性分象限解决问题
		if(angle_value >= 0 && angle_value <M_PI/2)  //左下象限
		{
			 sina = -abs(qSin(angle_value));
			 cosa = abs(qCos(angle_value));
		}
		else if(angle_value >= M_PI/2&& angle_value <M_PI)  //左上象限
		{
			sina = -abs(qSin(M_PI- angle_value));
			 cosa = -abs(qCos(M_PI- angle_value));
		}
		else if (angle_value>=M_PI&& angle_value<M_PI*0.75*2)  //右上象限
		{		
			 sina = abs(qSin(angle_value-M_PI));
			 cosa = -abs(qCos(angle_value-M_PI));
		}
		else if (angle_value>= M_PI*0.75*2&&angle_value<= M_PI*2)  //右下象限
		{
			 sina = abs(qSin(M_PI*2-angle_value));
			 cosa = abs(qCos(M_PI*2-angle_value));
		}
		
		//数值
		double value =1.0*i*((max_value - min_value)/ major_count)+ min_value;
	
		QString strValue = QString("%1").arg((double)value, 0, 'f',0);
		
		//获取这个字体在特定字号下的宽高(宽可能有多个字符串所以获取要传入str 高就一个字所以不需要传)
		QFontMetrics fm(scale_font);
		double textWidth = fm.width(strValue);
		double textHeight = fm.height();
		
		//减去相应的文字宽高
		int x =radius * sina-textWidth/2;
		int y = radius * cosa+textHeight/4;
	
		//设置字体画文字
		painter->setFont(scale_font);
		painter->drawText(x, y, strValue);
	}

	//恢复painter属性
	painter->restore();
}

void CustomPanel::drawText(QPainter *painter)
{
	painter->save();

	QPen pen;
	pen.setColor(text_color);
	painter->setPen(pen);
	painter->setFont(text_font);

	QString str = QString::number(cur_value)+QString::fromUtf8("km/h");
	QFontMetrics fm(text_font);
	double textWidth = fm.width(str);
	double textHeight = fm.height();
	painter->drawText(0-textWidth/2,text_y,str);

	painter->restore();
}

void CustomPanel::drawTitle(QPainter *painter)
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

void CustomPanel::drawIndicator(QPainter *painter)
{
	painter->save();
	QPolygon pts;
	pts.setPoints(3, -1* pointer_width/2, 0, pointer_width / 2, 0, 0, pointer_length);/* (-2,0)/(2,0)/(0,60) *///第一个参数是 ，坐标的个数。后边的是坐标

	painter->rotate(start_angle);
	//根据当前值旋转的角度
	double degRotate =(360.0-start_angle-end_angle)/(max_value-min_value)*(cur_value-min_value);

	//画指针
	painter->rotate(degRotate);  //顺时针旋转坐标系统
	QRadialGradient haloGradient(0, 0, 60, 0, 0);  //辐射渐变
	haloGradient.setColorAt(0, QColor(60, 60, 60));
	haloGradient.setColorAt(1, QColor(160, 160, 160)); //灰
	painter->setPen(Qt::white); //定义线条文本颜色  设置线条的颜色
	painter->setBrush(haloGradient);//刷子定义形状如何填满 填充后的颜色
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
	painter->drawEllipse(-1* center_radius, -1 * center_radius, 2*center_radius, 2 * center_radius);
}

void CustomPanel::drawNumericValue(QPainter *painter)
{

}


void CustomPanel::resizeEvent(QResizeEvent* size)
{
	//获取自身控件大小
	this->width= size->size().width();
	this->height = size->size().height();

	//向下取整 确保是偶数
	if (this->width%2 != 0)
	{
		this->width--;
	}
	if (this->height%2!= 0)
	{
		this->height--;
	}

	//获取合理的外圆半径
	if (this->width>this->height)
	{
		out_cir_radius = this->height/2;
	}
	else
	{
		out_cir_radius = this->width / 2;
	}

	//获取合理的内圆半径
	in_cir_radius = out_cir_radius - border_width;
}

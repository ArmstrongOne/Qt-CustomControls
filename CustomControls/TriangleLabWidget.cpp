#include "TriangleLabWidget.h"
#include <QPainter>
TriangleLabWidget::TriangleLabWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

TriangleLabWidget::~TriangleLabWidget()
{

}

void TriangleLabWidget::paintEvent(QPaintEvent* event)
{
	int this_width = this->width();
	int this_height = this->height();

	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	//设置透明笔
	painter.setPen(QColor(1, 1, 1, 0));

	//寻找三角形三个坐标点
	//左点
	int left_point_x = 0;
	int left_point_y = this_height/2;
	//右上点(三等分)
	int right_up_point_x = this_width;
	int right_up_point_y = this_height/3;
	//右下点(三等分)
	int right_down_point_x = this_width;
	int right_down_point_y = this_height*2/3;

	//画背景
	painter.setBrush(QColor(0, 187, 158));
	QPolygon polygon;
	polygon.setPoints(3, left_point_x, left_point_y, right_up_point_x, right_up_point_y, right_down_point_x, right_down_point_y);
	painter.drawPolygon(polygon);
	this->update();
}

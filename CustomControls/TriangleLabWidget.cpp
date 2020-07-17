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
	//����͸����
	painter.setPen(QColor(1, 1, 1, 0));

	//Ѱ�����������������
	//���
	int left_point_x = 0;
	int left_point_y = this_height/2;
	//���ϵ�(���ȷ�)
	int right_up_point_x = this_width;
	int right_up_point_y = this_height/3;
	//���µ�(���ȷ�)
	int right_down_point_x = this_width;
	int right_down_point_y = this_height*2/3;

	//������
	painter.setBrush(QColor(0, 187, 158));
	QPolygon polygon;
	polygon.setPoints(3, left_point_x, left_point_y, right_up_point_x, right_up_point_y, right_down_point_x, right_down_point_y);
	painter.drawPolygon(polygon);
	this->update();
}

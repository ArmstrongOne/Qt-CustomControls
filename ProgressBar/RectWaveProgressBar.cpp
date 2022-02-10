#include "RectWaveProgressBar.h"
#include "ui_RectWaveProgressBar.h"
#include<QPainter>
#include <QPainterPath>
#include <math.h>
#include <QDebug>
RectWaveProgressBar::RectWaveProgressBar(QWidget *parent):QWidget(parent)
{

	ui = new Ui::RectWaveProgressBar;
	ui->setupUi(this);

	text_label = ui->text_lab;

	//��ʼ������
	out_rect.setWidth(0);
	out_rect.setHeight(0);
	out_rect.setX(0);
	out_rect.setY(0);

	in_rect.setWidth(0);
	in_rect.setHeight(0);
	in_rect.setX(0);
	in_rect.setY(0);


	margin_left = 0;
	margin_right = 0;
	margin_top = 0;
	margin_bottom = 0;

	border_width = 0;
	cur_value = 0;

	m_waterDensity = 0;
	m_waterHeight = 0;
	m_init_offset = 0;
	m_offset = 0;
}

RectWaveProgressBar::~RectWaveProgressBar()
{
	delete ui;
}

void RectWaveProgressBar::SetPanColor(QColor background_color, QColor border_color)
{
	this->background_color = background_color;
	this->border_color = border_color;
}


void RectWaveProgressBar::SetMargin(int left_margin, int right_margin, int top_margin, int bottom_margin)
{
	this->margin_left = left_margin;
	this->margin_right = right_margin;
	this->margin_top = top_margin;
	this->margin_bottom = bottom_margin;

}

void RectWaveProgressBar::SetWaveColor(QColor front_wave_color, QColor behind_wave_color)
{
	this->front_wave_color = front_wave_color;
	this->behind_wave_color = behind_wave_color;
}

void RectWaveProgressBar::SetBorderWidth(int value)
{
	border_width = value;
}

void RectWaveProgressBar::SetWaveProperty(int density, double m_waterHeight, double offset)
{
	this->m_waterDensity = density;
	this->m_waterHeight = m_waterHeight;
	this->m_offset = offset;
}

void RectWaveProgressBar::Update()
{
	QPalette pa;
	pa.setColor(QPalette::WindowText, label_font_color);
	pa.setColor(QPalette::Window, label_back_color);

	text_label->setAutoFillBackground(true);
	text_label->setPalette(pa);
	text_label->setFont(label_font);

	text_label->setText("0%");
	text_label->show();
}

void RectWaveProgressBar::SetPanValue(int value)
{
	this->cur_value = value;
	text_label->setText(QString::number(value) + "%");
}

void RectWaveProgressBar::SetPanLabelColor(QColor font_color, QColor back_color)
{
	this->label_font_color = font_color;
	this->label_back_color = back_color;
}

void RectWaveProgressBar::SetPanLabelFont(QFont font)
{
	this->label_font = font;
}

void RectWaveProgressBar::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setRenderHint(QPainter::Antialiasing);  // �����;

	int height = in_rect.height();
	int width = in_rect.width();

	//���㵱ǰֵ��ռ�ٷֱ� percentʵ������ˮ��������İٷֱ�
	double percent = 1 - (double)(cur_value - 0)/(100-0);

	//�������߹�ʽ y = A * sin(��x + ��) + k
	//w��ʾ����,�������Ϊˮ�����ܶ�,ֵԽ���ܶ�Խ��(��Խ�ܼ� ^_^),ȡֵ �ܶ�*M_PI/���
	double w = m_waterDensity * M_PI/width;
	//A��ʾ���,�������Ϊˮ���ĸ߶�,ֵԽ��߶�Խ��(Խ�� ^_^),ȡֵ�߶ȵİٷֱ�
	double A = height*m_waterHeight;
	//k��ʾy��ƫ��,�������Ϊ����,ȡֵ�߶ȵĽ��Ȱٷֱ�
	double k = height*percent+ in_rect.y();

	//��һ������·������
	QPainterPath waterPath1;
	//�ڶ�������·������
	QPainterPath waterPath2;

	//�ƶ������Ͻ���ʼ��
	waterPath1.moveTo(in_rect.x(), in_rect.y());
	waterPath2.moveTo(in_rect.x(), in_rect.y());

	m_init_offset += m_offset;
	if (m_init_offset > (in_rect.width()/2)) {
		m_init_offset = 0;
	}

	for (int x = in_rect.x(); x <= in_rect.x() + in_rect.width(); x++) {
		//��һ������Y��
		double waterY1 = (double)(A*sin(w*x+m_init_offset))+k;

		//�ڶ�������Y��
		double waterY2 = (double)(A*sin(w*x+m_init_offset+M_PI))+k;

		//�����ǰֵΪ��Сֵ��Y��Ϊ�߶�
		if (cur_value == 0)
		{
			waterY1 = in_rect.y() + in_rect.height();
			waterY2 = in_rect.y() + in_rect.height();
		}

		//�����ǰֵΪ���ֵ��Y��Ϊ0
		if (cur_value == 100)
		{
			waterY1 = in_rect.y();
			waterY2 = in_rect.y();
		}
		waterPath1.lineTo(x, waterY1);
		waterPath2.lineTo(x, waterY2);
	}

	//�ƶ������½ǽ�����,�����γ�һ���պ�·��
	waterPath1.lineTo(in_rect.x() + in_rect.width(), in_rect.y() + in_rect.height());
	waterPath2.lineTo(in_rect.x() + in_rect.width(), in_rect.y() + in_rect.height());

	//���ƶ������½�
	waterPath1.lineTo(in_rect.x(), in_rect.y() + in_rect.height());
	waterPath2.lineTo(in_rect.x(), in_rect.y() + in_rect.height());

	//���ⲿ����
	painter.setBrush(border_color);
	painter.drawRect(out_rect);
	//���ڲ�����
	painter.setBrush(background_color);
	painter.drawRect(in_rect);

	//��·��
	QPainterPath big_path;
	big_path.addRect(in_rect);
	painter.save();

	QColor waterColor1 = front_wave_color;
	QColor waterColor2 = behind_wave_color;

	//��·��
	QPainterPath path;
	//��һ��������ȥ���·��
	painter.setBrush(waterColor1);
	path = big_path.intersected(waterPath1);
	painter.drawPath(path);

	//�ڶ���������ȥ���·��
	painter.setBrush(waterColor2);
	path = big_path.intersected(waterPath2);
	painter.drawPath(path);

	painter.restore();
	this->update();
}

void RectWaveProgressBar::resizeEvent(QResizeEvent* size)
{
	//ȷ���ؼ����Ϳ�
	int width = this->width();
	int height = this->height();

	//������
	out_rect.setWidth(width-margin_left-margin_right);
	out_rect.setHeight(height-margin_top-margin_bottom);
	out_rect.setX(0 + margin_left);
	out_rect.setY(0 + margin_top);

	//�ڽӾ���(�����κ� border_width�ٿ�)
	in_rect.setX(out_rect.x()+border_width);
	in_rect.setY(out_rect.y() + border_width);
	in_rect.setWidth(out_rect.width()-2*border_width);
	in_rect.setHeight(out_rect.height() - 2 * border_width);

	//��labelλ��
	text_label->move(in_rect.width()/2-text_label->width()/2+ in_rect.x(), in_rect.height()/2-text_label->height()/2+ in_rect.y());
}


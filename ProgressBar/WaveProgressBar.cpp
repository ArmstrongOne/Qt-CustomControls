#include "WaveProgressBar.h"
#include "ui_WaveProgressBar.h"
#include<QPainter>
#include <math.h>
WaveProgressBar::WaveProgressBar(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::WaveProgressBar;
	ui->setupUi(this);

	text_label = ui->text_lab;


	//��ʼ������
	m_width_out_cir = 0;
	m_height_out_cir = 0;
	m_radius_out_cir = 0;

	m_width_in_cir= 0;
	m_height_in_cir = 0;
	m_radius_in_cir = 0;

	border_width = 0;
	cur_value=0;

	m_waterDensity = 0;
	m_waterHeight = 0;
	m_init_offset = 0;
	m_offset = 0;
}

WaveProgressBar::~WaveProgressBar()
{
	delete ui;

}

void WaveProgressBar::SetPanColor(QColor background_color, QColor border_color)
{
	this->background_color = background_color;
	this->border_color = border_color;
}


void WaveProgressBar::SetWaveColor(QColor front_wave_color, QColor behind_wave_color)
{
	this->front_wave_color = front_wave_color;
	this->behind_wave_color = behind_wave_color;
}

void WaveProgressBar::SetBorderWidth(int value)
{
	border_width = value;
}

void WaveProgressBar::SetWaveProperty(int density, double m_waterHeight, double offset)
{
	this->m_waterDensity = density;
	this->m_waterHeight = m_waterHeight;
	this->m_offset = offset;
}

void WaveProgressBar::Update()
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

void WaveProgressBar::SetPanValue(int value)
{
	this->cur_value = value;
	text_label->setText(QString::number(value) + "%");
}

void WaveProgressBar::SetPanLabelColor(QColor font_color, QColor back_color)
{
	this->label_font_color = font_color;
	this->label_back_color = back_color;
}

void WaveProgressBar::SetPanLabelFont(QFont font)
{
	this->label_font = font;
}

void WaveProgressBar::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setRenderHint(QPainter::Antialiasing);  // �����;
	
	int height = m_height_in_cir+ in_cir_rect.y();
	int width = m_width_in_cir + in_cir_rect.x();

	//���㵱ǰֵ��ռ�ٷֱ� percentʵ������ˮ��������İٷֱ�
	double percent=1-(double)(cur_value-0)/(100-0);

	//�������߹�ʽ y = A * sin(��x + ��) + k
	//w��ʾ����,�������Ϊˮ�����ܶ�,ֵԽ���ܶ�Խ��(��Խ�ܼ� ^_^),ȡֵ �ܶ�*M_PI/���
	double w = m_waterDensity * M_PI / width;
	//A��ʾ���,�������Ϊˮ���ĸ߶�,ֵԽ��߶�Խ��(Խ�� ^_^),ȡֵ�߶ȵİٷֱ�
	double A = height*m_waterHeight;
	//k��ʾy��ƫ��,�������Ϊ����,ȡֵ�߶ȵĽ��Ȱٷֱ�
	double k = height*percent;

	//��һ������·������
	QPainterPath waterPath1;
	//�ڶ�������·������
	QPainterPath waterPath2;

	//�ƶ������Ͻ���ʼ��
	waterPath1.moveTo(in_cir_rect.x(), in_cir_rect.y()+ in_cir_rect.height());
	waterPath2.moveTo(in_cir_rect.x(), in_cir_rect.y() + in_cir_rect.height());

	m_init_offset+= m_offset;
	if (m_init_offset > (m_width_in_cir / 2)) {
		m_init_offset = 0;
	}

	for (int x = in_cir_rect.x(); x <= in_cir_rect.x()+m_width_in_cir; x++) {
		//��һ������Y��
		double waterY1 = (double)(A * sin(w * x+m_init_offset)) + k;

		//�ڶ�������Y��
		double waterY2 = (double)(A * sin(w*x+m_init_offset + M_PI)) + k;

		//�����ǰֵΪ��Сֵ��Y��Ϊ�߶�
		if (cur_value == 0) 
		{
			waterY1 = in_cir_rect.y() + in_cir_rect.height();
			waterY2 = in_cir_rect.y() + in_cir_rect.height();
		}

		//�����ǰֵΪ���ֵ��Y��Ϊ0
		if (cur_value == 100) 
		{
			waterY1= in_cir_rect.y();
			waterY2= in_cir_rect.y();
		}
		waterPath1.lineTo(x, waterY1);
		waterPath2.lineTo(x, waterY2);
	}

	//�ƶ������½ǽ�����,�����γ�һ���պ�·��
	waterPath1.lineTo(in_cir_rect.x()+in_cir_rect.width(), in_cir_rect.y()+ in_cir_rect.height());
	waterPath2.lineTo(in_cir_rect.x() + in_cir_rect.width(), in_cir_rect.y() + in_cir_rect.height());

	//��·��
	QPainterPath bigPath;
	//���ⲿԲ
	painter.setBrush(border_color);
	painter.drawEllipse(0, 0, m_width_out_cir, m_height_out_cir);
	//���ڲ�Բ
	painter.setBrush(background_color);
	painter.drawEllipse(in_cir_rect);
	//���ڲ�Բ���뵽��·����
	bigPath.addEllipse(in_cir_rect);
	painter.save();

	//painter.setPen(QColor(11,21,0));
	//painter.setBrush(QColor(212, 11, 100));
	//painter.drawPath(waterPath1);
	
	//��·��,�ô�·����ȥ���������·��,�γ�����Ч��
	QPainterPath path;
	QColor waterColor1 = front_wave_color;
	QColor waterColor2 = behind_wave_color;

	//��һ��������ȥ���·��
	path = bigPath.intersected(waterPath1);
	painter.setBrush(waterColor1);
	painter.drawPath(path);

	//�ڶ���������ȥ���·��
	path = bigPath.intersected(waterPath2);
	painter.setBrush(waterColor2);
	painter.drawPath(path);

	painter.restore();
	this->update();
}

void WaveProgressBar::resizeEvent(QResizeEvent* size)
{
	this->m_width_out_cir = this->width();
	this->m_height_out_cir = this->height();
	//����Բ�ε�����ֱ����ֵ����Ϊż��
	if (this->m_width_out_cir % 2 != 0)
	{
		m_width_out_cir--;
	}
	if (this->m_height_out_cir % 2 != 0)
	{
		m_height_out_cir--;
	}

	//����һ������С�ı�
	if (this->m_width_out_cir < this->m_height_out_cir)
	{
		this->m_height_out_cir = this->m_width_out_cir;
	}
	else if (this->m_width_out_cir > this->m_height_out_cir)
	{
		this->m_width_out_cir = this->m_height_out_cir;
	}

	m_radius_out_cir = (this->m_width_out_cir + this->m_height_out_cir) / 2;

	
	//�����Ż��� ȷ��lab��λ��
	text_label->move(m_width_out_cir / 2 - text_label->width() / 2, m_height_out_cir / 2 - text_label->height() / 2);

	//ȷ���ڲ�Բ�Ĳ���
	m_width_in_cir = m_width_out_cir - 2 * border_width;
	m_height_in_cir = m_height_out_cir - 2 * border_width;
	m_radius_in_cir = m_radius_out_cir-border_width;

	in_cir_rect.setX(m_radius_out_cir- m_radius_in_cir);
	in_cir_rect.setY(m_radius_out_cir - m_radius_in_cir);
	in_cir_rect.setWidth(m_width_in_cir);
	in_cir_rect.setHeight(m_height_in_cir);
}


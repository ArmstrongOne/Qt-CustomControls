#include "LinearProgressBar.h"
#include "ui_LinearProgressBar.h"
#include<QPainter>
LinearProgressBar::LinearProgressBar(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::LinearProgressBar;
	ui->setupUi(this);

	text_label = ui->text_lab;
	
	m_width_out_cir = 0;
	m_height_out_cir = 0;
	m_radius_out_cir = 0;
	
	m_width_in_cir = 0;
	m_height_in_cir = 0;
	m_radius_in_cir = 0;

	cur_value = 0;
}

LinearProgressBar::~LinearProgressBar()
{
	delete ui;
}

void LinearProgressBar::SetPanColor(QColor unselected_color, QColor selected_color)
{
	this->unselected_color = unselected_color;
	this->selected_color = selected_color;
}


void LinearProgressBar::SetInsideCircleRadius(int radius)
{
	if (radius % 2 != 0)
	{
		radius--;
	}
	m_radius_in_cir = radius;
	m_width_in_cir = 2 * radius;
	m_height_in_cir = 2 * radius;
}

void LinearProgressBar::SetInsideCircleColor(QColor color)
{
	in_cir_color = color;
}

void LinearProgressBar::Update()
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

void LinearProgressBar::SetPanValue(int value)
{
	this->cur_value = value;

	text_label->setText(QString::number(value) + "%");
}

void LinearProgressBar::SetPanLabelColor(QColor font_color, QColor back_color)
{
	this->label_font_color = font_color;
	this->label_back_color = back_color;
}

void LinearProgressBar::SetPanLabelFont(QFont font)
{
	this->label_font = font;
}

void LinearProgressBar::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	//����͸����
	painter.setPen(QColor(1, 1, 1, 0));

	//���ⲿԲ
	painter.setBrush(unselected_color);
	painter.drawEllipse(0, 0, m_radius_out_cir * 2, m_radius_out_cir * 2);



	//��ɨ��������ͼ
	painter.setBrush(selected_color);

	//��λ��1/16��  һȦ��5760(ĳδ֪��λ)
	int startAngle = 1440;
	// ���θ��Ƿ�Χ��120�ȵģ�
	int spanAngle = (double)cur_value / 100 * 5760;
	//�������� ��Ϊ���Ϳ��Ż����� ��Ҫ��������
	QRect rect(0, 0, m_width_out_cir, m_height_out_cir);
	painter.drawPie(rect, startAngle, spanAngle);

	//����ڲ�Բ
	painter.setBrush(in_cir_color);
	painter.drawEllipse(m_radius_out_cir - m_radius_in_cir, m_radius_out_cir - m_radius_in_cir, m_radius_in_cir * 2, m_radius_in_cir * 2);



	this->update();
}

void LinearProgressBar::resizeEvent(QResizeEvent* size)
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

	m_radius_out_cir = (this->m_width_out_cir + this->m_height_out_cir) / 4;

	//�����Ż��� ȷ��lab��λ��
	text_label->move(m_width_out_cir / 2 - text_label->width() / 2, m_height_out_cir / 2 - text_label->height() / 2);

}

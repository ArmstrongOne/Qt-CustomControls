#include "DashBoard.h"
#include<QPainter>
#include "ui_DashBoard.h"
#include <QLabel>
DashBoard::DashBoard(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::DashBoard;
	ui->setupUi(this);

	text_label = ui->text_lab;
	cur_value = 0;
}

DashBoard::~DashBoard()
{
	delete ui;
}

void DashBoard::SetPanColor(QColor unselected_color, QColor selected_color)
{
	this->unselected_color = unselected_color;
	this->selected_color = selected_color;
}

void DashBoard::Update()
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

void DashBoard::SetPanValue(int value)
{
	this->cur_value = value;

	text_label->setText(QString::number(value) + "%");
}

void DashBoard::SetPanLabelColor(QColor font_color, QColor back_color)
{
	this->label_font_color = font_color;
	this->label_back_color = back_color;
}

void DashBoard::SetPanLabelFont(QFont font)
{
	this->label_font = font;
}

void DashBoard::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	//����͸����
	painter.setPen(QColor(1, 1, 1, 0));

	//������
	painter.setBrush(unselected_color);
	painter.drawEllipse(0, 0,m_radius,m_radius);

	//��ɨ��������ͼ
	painter.setBrush(selected_color);
	
	//��λ��1/16��  һȦ��5760(ĳδ֪��λ)  //��ͼ�����ӷ�λ�Ƕ�Ϊ0 1440����ʱ��ת90�� ��12���ӷ�λ
	int startAngle =1440;
	// ���θ��Ƿ�Χ��120�ȵģ�
	int spanAngle = (double)cur_value/100*5760;  //��ת��Ҳ�ǳ���ʱ��������
	//�������� ��Ϊ���Ϳ��Ż����� ��Ҫ��������
	QRect rect(0, 0, m_width, m_height);
	painter.drawPie(rect, startAngle, spanAngle);
	this->update();
}

void DashBoard::resizeEvent(QResizeEvent* size)
{
	this->m_width = this->width();
	this->m_height = this->height();
	//����Բ�ε�����ֱ����ֵ����Ϊż��
	if (this->m_width % 2 != 0)
	{
		m_width--;
	}
	if (this->m_height % 2 != 0)
	{
		m_height--;
	}

	//����һ������С�ı�
	if (this->m_width<this->m_height)
	{
		this->m_height = this->m_width;
	}
	else if (this->m_width>this->m_height)
	{
		this->m_width = this->m_height;
	}

	m_radius= (this->m_width+ this->m_height)/2;

	//�����Ż��� ȷ��lab��λ��
	text_label->move(m_width/2-text_label->width()/2, m_height/2-text_label->height()/2);
}

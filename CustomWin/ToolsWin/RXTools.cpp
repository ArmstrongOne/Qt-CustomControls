#include "RXTools.h"
#include "ui_RXTools.h"
#include <QPainter>
#include <qmath.h>
#include <QMouseEvent>
#pragma execution_character_set("utf-8")

RXTools::RXTools(QWidget *parent):QWidget(parent)
{
	ui = new Ui::RXToolsClass;
	ui->setupUi(this);

	//ȥ�߿�;
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->setStyleSheet("background:rgba(0,255,255,0.0);");

	//����ͼ��;
	this->setWindowIcon(QIcon(":/RXTools/icon/rxtool_icon.ico"));
	this->InitUi();
}

RXTools::~RXTools()
{
	delete ui;
}

void RXTools::InitUi()
{
	//��װ�¼�������
	ui->top_wid->installEventFilter(this);
	ui->ini_file_modify_wid->installEventFilter(this);
	ui->dicom_modify_wid->installEventFilter(this);
	ui->batch_handle_wid->installEventFilter(this);
	ui->reset_setting_wid->installEventFilter(this);
	ui->pushstation_wid->installEventFilter(this);
	ui->serielport_test_wid->installEventFilter(this);

	//�������ģ�鰴ť��ͼƬ ����
	//ui->ini_file_modify_wid->SetTopLabText(QString::fromUtf8("�����ļ��޸�"));
	//ui->ini_file_modify_wid->SetBottomLabText(QString::fromUtf8("�޸������ļ�")); 
	//ui->ini_file_modify_wid->SetIcon(":/RXTools/icon/inifile_pic.png");

	//ui->dicom_modify_wid->SetTopLabText(QString::fromUtf8("ͼ���޸�"));
	//ui->dicom_modify_wid->SetBottomLabText(QString::fromUtf8("���ͼ���޸�"));
	//ui->dicom_modify_wid->SetIcon(":/RXTools/icon/dicom_modify_pic.png");

	//ui->batch_handle_wid->SetTopLabText(QString::fromUtf8("��������"));
	//ui->batch_handle_wid->SetBottomLabText(QString::fromUtf8("���ٴ���FFR"));
	//ui->batch_handle_wid->SetIcon(":/RXTools/icon/batch_handle_pic.png");

	//ui->reset_setting_wid->SetTopLabText(QString::fromUtf8("�������"));
	//ui->reset_setting_wid->SetBottomLabText(QString::fromUtf8("�ָ�����״̬"));
	//ui->reset_setting_wid->SetIcon(":/RXTools/icon/reset_setting_pic.png");

	//ui->pushstation_wid->SetTopLabText(QString::fromUtf8("����վ"));
	//ui->pushstation_wid->SetBottomLabText(QString::fromUtf8("����ѹ��ͼ��"));
	//ui->pushstation_wid->SetIcon(":/RXTools/icon/pushstation_pic.png");

	//ui->serielport_test_wid->SetTopLabText(QString::fromUtf8("���ڲ���"));
	//ui->serielport_test_wid->SetBottomLabText(QString::fromUtf8("�ȶ���ȫ����"));
	//ui->serielport_test_wid->SetIcon(":/RXTools/icon/icon5.png");

	ui->ini_file_modify_wid->SetTopLabText(QString::fromUtf8("Item1"));
	ui->ini_file_modify_wid->SetBottomLabText(QString::fromUtf8(""));
	ui->ini_file_modify_wid->SetIcon(":/new/prefix1/icon/inifile_pic.png");

	ui->dicom_modify_wid->SetTopLabText(QString::fromUtf8("Item2"));
	ui->dicom_modify_wid->SetBottomLabText(QString::fromUtf8(""));
	ui->dicom_modify_wid->SetIcon(":/new/prefix1/icon/dicom_modify_pic.png");

	ui->batch_handle_wid->SetTopLabText(QString::fromUtf8("Item3"));
	ui->batch_handle_wid->SetBottomLabText(QString::fromUtf8(""));
	ui->batch_handle_wid->SetIcon(":/new/prefix1/icon/batch_handle_pic.png");

	ui->reset_setting_wid->SetTopLabText(QString::fromUtf8("Item4"));
	ui->reset_setting_wid->SetBottomLabText(QString::fromUtf8(""));
	ui->reset_setting_wid->SetIcon(":/new/prefix1/icon/reset_setting_pic.png");

	ui->pushstation_wid->SetTopLabText(QString::fromUtf8("Item5"));
	ui->pushstation_wid->SetBottomLabText(QString::fromUtf8(""));
	ui->pushstation_wid->SetIcon(":/new/prefix1/icon/pushstation_pic.png");

	ui->serielport_test_wid->SetTopLabText(QString::fromUtf8("Item6"));
	ui->serielport_test_wid->SetBottomLabText(QString::fromUtf8(""));
	ui->serielport_test_wid->SetIcon(":/new/prefix1/icon/icon5.png");
}


void RXTools::paintEvent(QPaintEvent *)
{
	//�൱�����λ�10��aֵ�ݼ��ľ���
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(10, 10, this->width() - 20, this->height() - 20);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(Qt::white));

	QColor color(0, 0, 0, 50);
	for (int i = 0; i < 10; i++)
	{
		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		path.addRect(10 - i, 10 - i, this->width() - (10 - i) * 2, this->height() - (10 - i) * 2);
		color.setAlpha(150-qSqrt(i)*50);
		//if (i > 8)
		//{
		//	color.setAlpha(0);
		//}
		painter.setPen(color);
		painter.drawPath(path);
	}
}

void RXTools::leaveEvent(QEvent* event)
{
	QWidget::leaveEvent(event);
	is_press_title_wid = false;
	update();
}

void RXTools::mouseMoveEvent(QMouseEvent* event)
{
	if (is_press_title_wid)
	{
		if (event->buttons()&Qt::LeftButton)
		{
			//xλ�ƺ�yλ��
			int dis_x = event->x() - start_move_points.x();
			int dis_y = event->y() - start_move_points.y();
			this->move(this->x() + dis_x, this->y() + dis_y);
		}
	}
}

bool RXTools::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == ui->top_wid&& event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent *mouse_event;
		mouse_event = static_cast<QMouseEvent*>(event);
		start_move_points = mouse_event->pos();
		is_press_title_wid = true;
	}
	if (obj == ui->top_wid&& event->type() == QEvent::Leave)
	{
		is_press_title_wid = false;
	}

	if (obj == ui->ini_file_modify_wid&& event->type() == QEvent::MouseButtonPress)
	{

	}

	if (obj == ui->pushstation_wid&& event->type() == QEvent::MouseButtonPress)
	{

	}

	if (obj == ui->serielport_test_wid&& event->type() == QEvent::MouseButtonPress)
	{
	
	}

	if (obj == ui->batch_handle_wid&& event->type() == QEvent::MouseButtonPress)
	{
	
	}
	return QWidget::eventFilter(obj, event);
}

void RXTools::showEvent(QShowEvent*)
{
	//չʾ�� �ƶ�������������
	QWidget*parent_wid = this->parentWidget();
	if (parent_wid == NULL)
	{
		return;
	}
	this->move((parent_wid->width()-this->width())/2, (parent_wid->height()-this->height())/2);
}

void RXTools::on_close_win_btn_clicked()
{
	qApp->quit();
}

void RXTools::on_hide_win_btn_clicked()
{
	this->showMinimized();
}

void RXTools::on_zoom_win_btn_clicked()
{

}

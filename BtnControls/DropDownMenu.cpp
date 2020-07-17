#include "DropDownMenu.h"
#include "ui_DropDownMenu.h"
#include <QDebug>

#define RIGHTSPACE 12 //������һ���ұߵļ��


DropDownMenu::DropDownMenu(QPushButton*btn,QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::DropDownMenu();
	ui->setupUi(this);

	comb_btn = btn;
	connect(comb_btn, SIGNAL(clicked()), this, SLOT(combo_btn_click_slot()));

	vessel_name_list.clear();
	button_height = 0;
	space = 0;
	cur_vessel_name_index = -1;
	for (int i = 0; i < all_option_list.size(); i++)
	{
		if (all_option_list[i] != NULL)
		{
			delete all_option_list[i];
			all_option_list[i] = NULL;
		}
	}
	all_option_list.clear();
	vessel_name_list.clear();
	this->hide();
}

DropDownMenu::~DropDownMenu()
{
	delete ui;
}

void DropDownMenu::SetButtonFixHeight(int height)
{
	this->button_height = height;
}

void DropDownMenu::SetSpacing(int space)
{
	this->space = space;
}

void DropDownMenu::SetVesselOption(QList<QString>vessel_name_list)
{
	this->vessel_name_list = vessel_name_list;
}

void DropDownMenu::Update()
{
	if (vessel_name_list.size() <= 0)
	{
		return;
	}

	//Ĭ��ѡ��������һ��Ϊ��ǰѡ���Ѫ��
	cur_vessel_name_index = 0;
	comb_btn->setText(vessel_name_list[cur_vessel_name_index]);

	//������а�ť�б�
	for (int i = 0; i < all_option_list.size(); i++)
	{
		if (all_option_list[i] != NULL)
		{
			delete all_option_list[i];
			all_option_list[i] = NULL;
		}
	}
	all_option_list.clear();

	//ѡ��󶨰�ť
	for (int i = 0; i < vessel_name_list.size(); i++)
	{
		Option*option = new Option(ui->main_wid);

		option->btn->setText(vessel_name_list[i]);
		option->btn->setFixedHeight(button_height);
		option->btn->setFixedWidth(comb_btn->width()+RIGHTSPACE);
		connect(option->btn, SIGNAL(clicked(bool)), this, SLOT(btn_click_slot()));
		option->btn->setStyleSheet("color:rgb(255, 255, 255);border-image: url(:/CT20/picture/MainPage/mid_check.png);");
		option->btn->setFont(this->font);
		
		option->index = i;
		option->option_name = vessel_name_list[i];

		all_option_list.append(option);
	}
}

void DropDownMenu::SetTextShow(bool flag)
{
	if (all_option_list.size()<=0)
	{
		return;
	}
	if (flag)
	{
		comb_btn->setText(vessel_name_list[cur_vessel_name_index]);
	}
	else
	{
		comb_btn->setText("");
	}
}

void DropDownMenu::InitSelectIndex(QString cur_vessel_name)
{
	if (all_option_list.size()< 0)
	{
		return;
	}
	//�����ҳ���ǰ��
	cur_vessel_name_index = -1;
	for (int i = 0; i < all_option_list.size(); i++)
	{
		if (all_option_list[i]->option_name == cur_vessel_name)
		{
			cur_vessel_name_index =i;
		}
	}
	comb_btn->setText(all_option_list[cur_vessel_name_index]->option_name);
}

void DropDownMenu::ChangeVessel(QString cur_vessel_name)
{
	//�ж���all_option_list���ĸ���ť������
	int select_index = -1;
	for (int i = 0; i < all_option_list.size(); i++)
	{
		if (all_option_list[i]->option_name == cur_vessel_name)
		{
			select_index = i;
		}
	}

	//�������-1 ������û���ҵ���Ӧ�� return
	if (-1 == select_index)
	{
		return;
	}

	//����͵�ǰѡ�����ֲ�һ�� ��ı�ѡ�� �������ı��ź�
	if (select_index != cur_vessel_name_index)
	{
		//�ı䵱ǰ��ѡ��
		cur_vessel_name_index = select_index;
		comb_btn->setText(all_option_list[cur_vessel_name_index]->option_name);
		//�����ı��ź�
		emit OptionChanged(all_option_list[cur_vessel_name_index]->option_name);
	}

	//��ǰҳ����
	this->hide();
}

void DropDownMenu::SetBtnClickable(bool flag)
{
	if (flag)
	{
		comb_btn->setEnabled(true);
	}
	else
	{
		comb_btn->setEnabled(false);
	}
}

void DropDownMenu::SetFont(QFont font)
{
	this->font = font;
	comb_btn->setFont(this->font);
}

void DropDownMenu::InitMenu()
{
	for (int i = 0; i < all_option_list.size(); i++)
	{
		if (all_option_list[i] != NULL)
		{
			delete all_option_list[i];
			all_option_list[i] = NULL;
		}
	}
	all_option_list.clear();
	vessel_name_list.clear();
	cur_vessel_name_index = -1;
	comb_btn->setText("");
}

void DropDownMenu::showEvent(QShowEvent*e)
{
	this->StartShow();
}


//��ʾ
void DropDownMenu::StartShow()
{
	//���õ�ǰ��ťΪѡ�е��ַ���
	if ( vessel_name_list.size() <= 0)
	{
		return;
	}

	//�ı��С
	int btn_list_size = all_option_list.size();

	int width = comb_btn->width();
    qDebug() << width;
	int height = 2 * space + btn_list_size*button_height + (btn_list_size -1)*space;
	this->resize(width + RIGHTSPACE, height);//����������ұߵĿ� �Լ��޸�

	//�ƶ��ÿؼ�λ��
	QPoint point(comb_btn->parentWidget()->pos());
	qDebug() << point.x()<<point.y();
	this->move(point.x()+ RIGHTSPACE, point.y() + comb_btn->height());

	//����ʣ�ఴť�б�
	for (int btn_num = 0; btn_num < all_option_list.size(); btn_num++)
	{
		int pos_x = 0;
		int pos_y = btn_num*button_height + (btn_num + 1)*space;
		all_option_list[btn_num]->btn->move(pos_x, pos_y);
	}
}

void DropDownMenu::btn_click_slot()
{
	QPushButton* select_btn = (QPushButton*)sender();

	//��ȡѡ�е��ַ�
	QString select_str = select_btn->text();

	//�ж���all_option_list���ĸ���ť������
	int sender_index=0;
	for (int i = 0; i < all_option_list.size(); i++)
	{
		if (all_option_list[i]->btn ==select_btn)
		{
			sender_index = i;
		}
	}

	//����͵�ǰѡ�����ֲ�һ�� ��ı�ѡ�� �������ı��ź�
	if (sender_index != cur_vessel_name_index)
	{
		//�ı䵱ǰ��ѡ��
		cur_vessel_name_index = sender_index;
		comb_btn->setText(all_option_list[cur_vessel_name_index]->option_name);
		//�����ı��ź�
		emit OptionChanged(all_option_list[cur_vessel_name_index]->option_name);
	}
	//��ǰҳ����
	this->hide();
}

void DropDownMenu::combo_btn_click_slot()
{
	if (this->isVisible())
	{
		this->hide();
	}
	else
	{
		for (unsigned int option_num = 0; option_num < all_option_list.size(); option_num++)
		{
			Option *cur_option = all_option_list[option_num];
			cur_option->btn->setFixedWidth(comb_btn->width() + RIGHTSPACE);
		}
		this->show();
	}
}

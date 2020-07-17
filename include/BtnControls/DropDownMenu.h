#pragma once
//Ѫ��ѡ��ť�����˵� �ṩһ������Ͱ�һ����ť����
//ͨ��������Ƹ���ť


#include"btncontrols_global.h"
#include <QWidget>
#include <QPushButton>
namespace Ui { class DropDownMenu; };


class Option
{
public:
	Option(QWidget*btn_parent)
	{
		btn = new QPushButton(btn_parent);
	}
	~Option()
	{
		if (btn != NULL)
		{
			delete btn;
			btn = NULL;
		}
	}
	QPushButton *btn;
	QString option_name;
	int index;
};


class BTNCONTROLS_EXPORT DropDownMenu : public QWidget
{
	Q_OBJECT

public:
	DropDownMenu(QPushButton*,QWidget *parent = Q_NULLPTR);
	~DropDownMenu();

	//��һ��������������,֮�����ֻ�贫��ѡ����Update���� 
	void SetButtonFixHeight(int height);//���ð�ť�Ĺ̶��߶�
	void SetSpacing(int space);//���ð�ť֮��ļ��(�������¶���ʱ�������ֵ)
	
	//���س�ʼ״̬(ɾ���ڲ��б���Ϣ)
	void InitMenu();

	//���������������2������(ĿǰCT�̶�������Ѫ�ܲ���Ҫ��ô��)
	void SetVesselOption(QList<QString>vessel_name_list);
	void Update();//��ʼ������

	//�����ӿ����õ�ǰѪ�ܲ���ʾ
	void SetTextShow(bool flag);

	//�����ӿ� ��ʼ��ѡ���� �������ı��ź�
	void InitSelectIndex(QString cur_vessel_name);

    //�����ӿ� �л�ѡ���� һ����֮ǰ��һ�������ź�
	void ChangeVessel(QString cur_vessel_name);

	//�����ӿ� ��CT����״̬�н�ֹ���,��������Ե��
	void SetBtnClickable(bool flag);

	//��������(��ť��ѡ��)
	void SetFont(QFont);
private:
	Ui::DropDownMenu *ui;
	void showEvent(QShowEvent*);
	void StartShow();
	
	QPushButton *comb_btn;//��ϵ�pushbutton
	
	int button_height;//��ť�߶�
	int space;//��ť���

	int cur_vessel_name_index;//���õ�ǰѡ��������ڱ�ǩ
	QList<Option*>all_option_list;//���ݴ�����Ϣ,���ɵ����а�ťѡ��
	QList<QString>vessel_name_list;//�������Ϣ

	QFont font;
signals:
	void OptionChanged(QString cur_option_name);

private slots:
    void btn_click_slot();//ʣ�ఴť����ۺ���

	void combo_btn_click_slot();//��ϰ�ť���
};

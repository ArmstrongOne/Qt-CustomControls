#pragma once
//血管选择按钮下拉菜单 提供一个父类和绑定一个按钮即可
//通过这个控制父按钮


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

	//第一次设置所有属性,之后更新只需传入选项再Update即可 
	void SetButtonFixHeight(int height);//设置按钮的固定高度
	void SetSpacing(int space);//设置按钮之间的间距(左右上下都暂时用这个数值)
	
	//返回初始状态(删除内部列表信息)
	void InitMenu();

	//重新输入调用下面2个函数(目前CT固定那三个血管不需要这么做)
	void SetVesselOption(QList<QString>vessel_name_list);
	void Update();//初始化更新

	//单独接口设置当前血管不显示
	void SetTextShow(bool flag);

	//单独接口 初始化选择项 不发出改变信号
	void InitSelectIndex(QString cur_vessel_name);

    //单独接口 切换选中项 一旦和之前不一样发出信号
	void ChangeVessel(QString cur_vessel_name);

	//单独接口 在CT工具状态中禁止点击,不让其可以点击
	void SetBtnClickable(bool flag);

	//设置字体(按钮加选项)
	void SetFont(QFont);
private:
	Ui::DropDownMenu *ui;
	void showEvent(QShowEvent*);
	void StartShow();
	
	QPushButton *comb_btn;//组合的pushbutton
	
	int button_height;//按钮高度
	int space;//按钮间距

	int cur_vessel_name_index;//设置当前选择的容器内标签
	QList<Option*>all_option_list;//根据传入信息,生成的所有按钮选项
	QList<QString>vessel_name_list;//传入的信息

	QFont font;
signals:
	void OptionChanged(QString cur_option_name);

private slots:
    void btn_click_slot();//剩余按钮点击槽函数

	void combo_btn_click_slot();//组合按钮点击
};

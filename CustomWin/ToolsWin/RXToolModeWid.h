#pragma once
#include <QtWidgets/QWidget>
#include<QString>
namespace Ui 
{ 
	class RXToolModeWid; 
};

#pragma once
enum ButtonMode //按钮模式
{
	IniFileModifyMode,//配置文件修改模块
	DicomModifyMode,//图像修改模块
	BatchHandleMode,//批量处理模块
	ResetSettingMode,//恢复出厂设置模块
	PushStationMode//图像推送模块
};
class RXToolModeWid : public QWidget
{
	Q_OBJECT

public:
	RXToolModeWid(QWidget *parent = Q_NULLPTR);
	~RXToolModeWid();

	void SetTopLabText(QString);
	void SetBottomLabText(QString);
	void SetIcon(QString pic_path);
	void SetButtonMdoe(ButtonMode mode);
private:
	Ui::RXToolModeWid *ui;
	void showEvent(QShowEvent *e);
	void leaveEvent(QEvent* event);
	void enterEvent(QEvent *event);

	ButtonMode mode;
};

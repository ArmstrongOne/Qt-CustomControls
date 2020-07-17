#pragma once
#include <QtWidgets/QWidget>
#include<QString>
namespace Ui 
{ 
	class RXToolModeWid; 
};

#pragma once
enum ButtonMode //��ťģʽ
{
	IniFileModifyMode,//�����ļ��޸�ģ��
	DicomModifyMode,//ͼ���޸�ģ��
	BatchHandleMode,//��������ģ��
	ResetSettingMode,//�ָ���������ģ��
	PushStationMode//ͼ������ģ��
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

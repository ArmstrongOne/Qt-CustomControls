//�����кܶ�ط�д�ıȽ��� ������չ��Ч�� ���û���ʹ�� CustomPanel�����
//��CustomPanel�Ļ����Ͻ����޸�
#pragma once
#include <QWidget>
#include"Panel.h"

namespace Ui
{
	class CustomPanel;
}

class PANEL_EXPORT CustomPanel : public QWidget
{
	Q_OBJECT

public:
	CustomPanel(QWidget *parent = Q_NULLPTR);
	~CustomPanel();
	//���ñ߿����� ��Ⱥ���ɫ
	void SetBorderPropert(int border_width, QColor color);//�߿���ɫ
	void SetScaleFont(QFont scale_font);//�̶���������
	void SetPanelColor(QColor color); //�Ǳ�����ɫ
	void SetScaleNumColor(QColor scale_number_color);//�̶�������ɫ
	void SetScaleColor(QColor scale_color);//�̶���ɫ
	void SetMajorScaleProperty(int width, int length);//��̶ȳ���
	void SetMinorScaleProperty(int width, int length);//С�̶ȳ���
	
	void SetMajorCount(int count=10);//��̶�����
	void SetMinorCount(int count=10);//С�̶�����
	void SetMinValue(int min_value=0);//�̶���Сֵ
	void SetMaxValue(int max_value = 100);//�̶����ֵ
	void SetStartAngle(int start_angle = 60);//���ÿ�ʼ�Ƕ�(��:6���ӷ�λΪ0�� ˳��ת60��)
	void SetEndAngle(int end_angle = 60);//���ý����Ƕ�(��:6���ӷ�λΪ0�� ����ת60��)
	void SetCurValue(int cur_value);//���õ�ǰֵ

	//������ֵ����
	void SetTextPosition(int y);//����y������
	void SetTextFont(QFont font);
	void SetTextColor(QColor color);

	//���ñ�������
	void SetTitlePosition(int title_y);//����y������
	void SetTitleFont(QFont title_font);
	void SetTitleColor(QColor title_color);
	void SetTitleStr(QString title_str);

	//���ü��
	void SetSpaceBorderToScalenum(int space_border_scalenum);
	void SetSpaceScaleToScalenum(int spcae_scale_scalenum);

	//���ĵ�����
	void SetCenterRadius(int center_radius);

	//ָ������
	void SetPointerProperty(int pointer_width, int pointer_length);

private:
	Ui::CustomPanel *ui;
	void resizeEvent(QResizeEvent* size); //���ڴ�С�ı��¼������ڵõ���ȷ�Ŀؼ����Ϳ�

	int width;//�ÿؼ����,�Զ���ȡ
	int height;//�ÿؼ��߶�,�Զ���ȡ

	int out_cir_radius;//����ΧԲ�İ뾶
	int in_cir_radius;//��Բ�뾶 ȥ���߿��Բ

	int border_width;//�߿���
	QColor border_color;//�߿���ɫ

	QColor panel_color; //����ɫ
	QFont scale_font;    //�̶�����
	QColor scale_number_color;  //�̶�������ɫ
	QColor scale_color;    //�̶�����ɫ

	int space_border_scalenum; //�̶ȵ��Ǳ��̱߿����
	int spcae_scale_scalenum;//�̶ȵ��̶����ּ��

	int major_scale_length;//��̶ȳ�
	int major_scale_width;//��̶ȿ�
	int minor_scale_length;//С�̶ȳ�
	int minor_scale_width;//С�̶ȿ�

	int major_count;   //��̶�����
	int minor_count;   //С�̶�����

	int min_value;    //��Сֵ
	int max_value;    //���ֵ

	int start_angle;   //��ʼ�Ƕ�
	int end_angle;     //�����Ƕ�

	int cur_value;    //��ǰֵ


	//��ֵ��������
	int text_y;//���ֿ� ���Ͻ�y�� ֻ��Ҫ������� ��Ϊ�Ѿ��̶���ˮƽ����
	QFont text_font; //��������
	QColor text_color; //������ɫ

	//������������
	int title_y;     //���ֿ�y��
	QFont title_font;
	QColor title_color;
	QString title_str;

	//���ĵ�
	int center_radius;    //����Բ�뾶

	//ָ��
	int pointer_width;    //ָ����
	int pointer_length;   //ָ�볤��


	void paintEvent(QPaintEvent* event);//���ڻ�����
	void drawBackground(QPainter *painter);
	void drawScale(QPainter *painter);
	void drawScaleNum(QPainter *painter);
	void drawText(QPainter *painter);
	void drawTitle(QPainter *painter);
	void drawIndicator(QPainter *painter);
	void drawNumericValue(QPainter *painter);
};



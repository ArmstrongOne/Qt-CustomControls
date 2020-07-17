//该类有很多地方写的比较死 多用于展现效果 复用还是使用 CustomPanel这个类
#pragma once
#include <QWidget>
#include"Panel.h"

namespace Ui
{
	class NetSpeedPanel;
}

class PANEL_EXPORT NetSpeedPanel : public QWidget
{
	Q_OBJECT

public:
	NetSpeedPanel(QWidget *parent = Q_NULLPTR);
	~NetSpeedPanel();
	//设置边框属性 宽度和颜色
	void SetBorderPropert(int border_width, QColor color);//边框颜色
	void SetScaleFont(QFont scale_font);//刻度数字字体
	void SetPanelColor(QColor color); //仪表盘颜色
	void SetScaleNumColor(QColor scale_number_color);//刻度数字颜色
	void SetScaleColor(QColor scale_color);//刻度颜色
	void SetMajorScaleProperty(int width, int length);//大刻度长宽
	void SetMinorScaleProperty(int width, int length);//小刻度长宽

	void SetMajorCount(int count = 10);//大刻度数量
	void SetMinorCount(int count = 10);//小刻度数量
	void SetMinValue(int min_value = 0);//刻度最小值
	void SetMaxValue(int max_value = 100);//刻度最大值
	void SetStartAngle(int start_angle = 60);//设置开始角度(例:6点钟方位为0度 顺针转60度)
	void SetEndAngle(int end_angle = 60);//设置结束角度(例:6点钟方位为0度 逆针转60度)
	void SetCurValue(int cur_value);//设置当前值

									//设置数值文字
	void SetTextPosition(int y);//文字y轴坐标
	void SetTextFont(QFont font);
	void SetTextColor(QColor color);

	//设置标题文字
	void SetTitlePosition(int title_y);//文字y轴坐标
	void SetTitleFont(QFont title_font);
	void SetTitleColor(QColor title_color);
	void SetTitleStr(QString title_str);

	//设置间距
	void SetSpaceBorderToScale(int space_border_scale);
	void SetSpaceScaleToScalenum(int spcae_scale_scalenum);

	//中心点设置
	void SetCenterRadius(int center_radius);

	//指针设置
	void SetPointerProperty(int pointer_width, int pointer_length);

private:
	Ui::NetSpeedPanel *ui;
	void resizeEvent(QResizeEvent* size); //窗口大小改变事件，用于得到正确的控件长和宽

	int width;//该控件宽度,自动获取
	int height;//该控件高度,自动获取

	int out_cir_radius;//最外围圆的半径
	int in_cir_radius;//内圆半径 去除边框的圆

	int border_width;//边框宽度
	QColor border_color;//边框颜色

	QColor panel_color;
	QFont scale_font;
	QColor scale_number_color;
	QColor scale_color;

	int space_border_scale; //刻度到仪表盘边框距离
	int spcae_scale_scalenum;//刻度到刻度数字间距

	int major_scale_length;//大刻度长
	int major_scale_width;//大刻度宽
	int minor_scale_length;//小刻度长
	int minor_scale_width;//小刻度宽

	int major_count;
	int minor_count;

	int min_value;
	int max_value;

	int start_angle;
	int end_angle;

	int cur_value;//当前刻度


				  //数值文字属性
	int text_y;//文字框 左上角y点 只需要这个属性 因为已经固定在水平中央
	QFont text_font; //文字字体
	QColor text_color; //文字颜色

					   //标题文字属性
	int title_y;
	QFont title_font;
	QColor title_color;
	QString title_str;

	//中心点
	int center_radius;

	//指针
	int pointer_width;
	int pointer_length;


	void paintEvent(QPaintEvent* event);//用于画背景
	void drawBackground(QPainter *painter);
	void drawScale(QPainter *painter);
	void drawScaleNum(QPainter *painter);
	void drawText(QPainter *painter);
	void drawTitle(QPainter *painter);
	void drawIndicator(QPainter *painter);
	void drawNumericValue(QPainter *painter);
};




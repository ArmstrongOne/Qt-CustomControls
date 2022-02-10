#include "CustomControls.h"
#include <QtWidgets/QApplication>
#pragma execution_character_set("utf-8")

//ʹ��Qt���ø�DPI����ʽ
void QtDpiSetting()
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	qputenv("QT_ENABLE_HIGHDPI_SCALING", "1");
	// 5.14.0
#if QT_VERSION > 0x050E00
	QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#endif
}

int main(int argc, char *argv[])
{
	//��QApplication����ǰ����
	QtDpiSetting();
	QApplication a(argc, argv);
	CustomControls w;
	w.show();
	//w.showFullScreen();
	w.setWindowTitle(QString::fromUtf8("Qt�Ի�ؼ�-����Tom-2019.7"));
	return a.exec();
}

#include "CustomControls.h"
#include <QtWidgets/QApplication>
#pragma execution_character_set("utf-8")
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CustomControls w;
	w.show();
	//w.showFullScreen();
	w.setWindowTitle(QString::fromUtf8("Qt×Ô»æ¿Ø¼þ-ÇàÍÜTom-2019.7"));
	return a.exec();
}

#pragma once

#include <QWidget>
#include "ui_TriangleLabWidget.h"

class TriangleLabWidget : public QWidget
{
	Q_OBJECT

public:
	TriangleLabWidget(QWidget *parent = Q_NULLPTR);
	~TriangleLabWidget();

private:
	Ui::TriangleLabWidget ui;
	void paintEvent(QPaintEvent* event);//»­Èý½ÇÐÎ

};

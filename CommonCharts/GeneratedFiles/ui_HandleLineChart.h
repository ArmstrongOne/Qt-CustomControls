/********************************************************************************
** Form generated from reading UI file 'HandleLineChart.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDLELINECHART_H
#define UI_HANDLELINECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "QChartView.h"

QT_BEGIN_NAMESPACE

class Ui_HandleLineChart
{
public:
    QGridLayout *gridLayout;
    QChartView *qchart_view;

    void setupUi(QWidget *HandleLineChart)
    {
        if (HandleLineChart->objectName().isEmpty())
            HandleLineChart->setObjectName(QStringLiteral("HandleLineChart"));
        HandleLineChart->resize(400, 300);
        gridLayout = new QGridLayout(HandleLineChart);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        qchart_view = new QChartView(HandleLineChart);
        qchart_view->setObjectName(QStringLiteral("qchart_view"));

        gridLayout->addWidget(qchart_view, 0, 0, 1, 1);


        retranslateUi(HandleLineChart);

        QMetaObject::connectSlotsByName(HandleLineChart);
    } // setupUi

    void retranslateUi(QWidget *HandleLineChart)
    {
        HandleLineChart->setWindowTitle(QApplication::translate("HandleLineChart", "HandleLineChart", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HandleLineChart: public Ui_HandleLineChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLELINECHART_H

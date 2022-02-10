/********************************************************************************
** Form generated from reading UI file 'HandleScatterChart.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDLESCATTERCHART_H
#define UI_HANDLESCATTERCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "QChartView.h"

QT_BEGIN_NAMESPACE

class Ui_HandleScatterChart
{
public:
    QGridLayout *gridLayout;
    QChartView *qchart_view;

    void setupUi(QWidget *HandleScatterChart)
    {
        if (HandleScatterChart->objectName().isEmpty())
            HandleScatterChart->setObjectName(QString::fromUtf8("HandleScatterChart"));
        HandleScatterChart->resize(400, 300);
        gridLayout = new QGridLayout(HandleScatterChart);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        qchart_view = new QChartView(HandleScatterChart);
        qchart_view->setObjectName(QString::fromUtf8("qchart_view"));

        gridLayout->addWidget(qchart_view, 0, 0, 1, 1);


        retranslateUi(HandleScatterChart);

        QMetaObject::connectSlotsByName(HandleScatterChart);
    } // setupUi

    void retranslateUi(QWidget *HandleScatterChart)
    {
        HandleScatterChart->setWindowTitle(QCoreApplication::translate("HandleScatterChart", "HandleScatterChart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HandleScatterChart: public Ui_HandleScatterChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLESCATTERCHART_H

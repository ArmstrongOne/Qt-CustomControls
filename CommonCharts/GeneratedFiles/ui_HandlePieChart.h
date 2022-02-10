/********************************************************************************
** Form generated from reading UI file 'HandlePieChart.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDLEPIECHART_H
#define UI_HANDLEPIECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "QChartView.h"

QT_BEGIN_NAMESPACE

class Ui_HandlePieChart
{
public:
    QGridLayout *gridLayout;
    QChartView *qchart_view;

    void setupUi(QWidget *HandlePieChart)
    {
        if (HandlePieChart->objectName().isEmpty())
            HandlePieChart->setObjectName(QString::fromUtf8("HandlePieChart"));
        HandlePieChart->resize(400, 300);
        gridLayout = new QGridLayout(HandlePieChart);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        qchart_view = new QChartView(HandlePieChart);
        qchart_view->setObjectName(QString::fromUtf8("qchart_view"));

        gridLayout->addWidget(qchart_view, 0, 0, 1, 1);


        retranslateUi(HandlePieChart);

        QMetaObject::connectSlotsByName(HandlePieChart);
    } // setupUi

    void retranslateUi(QWidget *HandlePieChart)
    {
        HandlePieChart->setWindowTitle(QCoreApplication::translate("HandlePieChart", "HandlePieChart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HandlePieChart: public Ui_HandlePieChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLEPIECHART_H

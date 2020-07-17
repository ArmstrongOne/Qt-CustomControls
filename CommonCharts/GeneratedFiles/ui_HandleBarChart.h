/********************************************************************************
** Form generated from reading UI file 'HandleBarChart.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDLEBARCHART_H
#define UI_HANDLEBARCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "QChartView.h"

QT_BEGIN_NAMESPACE

class Ui_HandleBarChart
{
public:
    QGridLayout *gridLayout;
    QChartView *qchart_view;

    void setupUi(QWidget *HandleBarChart)
    {
        if (HandleBarChart->objectName().isEmpty())
            HandleBarChart->setObjectName(QStringLiteral("HandleBarChart"));
        HandleBarChart->resize(400, 300);
        gridLayout = new QGridLayout(HandleBarChart);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        qchart_view = new QChartView(HandleBarChart);
        qchart_view->setObjectName(QStringLiteral("qchart_view"));

        gridLayout->addWidget(qchart_view, 0, 0, 1, 1);


        retranslateUi(HandleBarChart);

        QMetaObject::connectSlotsByName(HandleBarChart);
    } // setupUi

    void retranslateUi(QWidget *HandleBarChart)
    {
        HandleBarChart->setWindowTitle(QApplication::translate("HandleBarChart", "HandleBarChart", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HandleBarChart: public Ui_HandleBarChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLEBARCHART_H

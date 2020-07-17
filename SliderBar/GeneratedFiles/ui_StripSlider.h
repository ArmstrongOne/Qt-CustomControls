/********************************************************************************
** Form generated from reading UI file 'StripSlider.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRIPSLIDER_H
#define UI_STRIPSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "SliderBar.h"

QT_BEGIN_NAMESPACE

class Ui_StripSlider
{
public:
    QRoundedLabel *hander_lab;

    void setupUi(QWidget *StripSlider)
    {
        if (StripSlider->objectName().isEmpty())
            StripSlider->setObjectName(QStringLiteral("StripSlider"));
        StripSlider->resize(161, 525);
        hander_lab = new QRoundedLabel(StripSlider);
        hander_lab->setObjectName(QStringLiteral("hander_lab"));
        hander_lab->setGeometry(QRect(40, 150, 91, 81));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hander_lab->sizePolicy().hasHeightForWidth());
        hander_lab->setSizePolicy(sizePolicy);

        retranslateUi(StripSlider);

        QMetaObject::connectSlotsByName(StripSlider);
    } // setupUi

    void retranslateUi(QWidget *StripSlider)
    {
        StripSlider->setWindowTitle(QApplication::translate("StripSlider", "StripSlider", Q_NULLPTR));
        hander_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StripSlider: public Ui_StripSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRIPSLIDER_H

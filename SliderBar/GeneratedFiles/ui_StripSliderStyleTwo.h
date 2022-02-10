/********************************************************************************
** Form generated from reading UI file 'StripSliderStyleTwo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRIPSLIDERSTYLETWO_H
#define UI_STRIPSLIDERSTYLETWO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "SliderBar.h"

QT_BEGIN_NAMESPACE

class Ui_StripSliderStyleTwo
{
public:
    QRoundedLabel *hander_lab;

    void setupUi(QWidget *StripSliderStyleTwo)
    {
        if (StripSliderStyleTwo->objectName().isEmpty())
            StripSliderStyleTwo->setObjectName(QString::fromUtf8("StripSliderStyleTwo"));
        StripSliderStyleTwo->resize(400, 300);
        hander_lab = new QRoundedLabel(StripSliderStyleTwo);
        hander_lab->setObjectName(QString::fromUtf8("hander_lab"));
        hander_lab->setGeometry(QRect(160, 90, 91, 81));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hander_lab->sizePolicy().hasHeightForWidth());
        hander_lab->setSizePolicy(sizePolicy);

        retranslateUi(StripSliderStyleTwo);

        QMetaObject::connectSlotsByName(StripSliderStyleTwo);
    } // setupUi

    void retranslateUi(QWidget *StripSliderStyleTwo)
    {
        StripSliderStyleTwo->setWindowTitle(QCoreApplication::translate("StripSliderStyleTwo", "StripSliderStyleTwo", nullptr));
        hander_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StripSliderStyleTwo: public Ui_StripSliderStyleTwo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRIPSLIDERSTYLETWO_H

/********************************************************************************
** Form generated from reading UI file 'CustomSliderStyleTwo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMSLIDERSTYLETWO_H
#define UI_CUSTOMSLIDERSTYLETWO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "CustomSliderStyleTwo.h"

QT_BEGIN_NAMESPACE

class Ui_CustomSliderStyleTwo
{
public:
    QRoundedLabelStyleTwo *hander_lab;

    void setupUi(QWidget *CustomSliderStyleTwo)
    {
        if (CustomSliderStyleTwo->objectName().isEmpty())
            CustomSliderStyleTwo->setObjectName(QString::fromUtf8("CustomSliderStyleTwo"));
        CustomSliderStyleTwo->resize(400, 300);
        hander_lab = new QRoundedLabelStyleTwo(CustomSliderStyleTwo);
        hander_lab->setObjectName(QString::fromUtf8("hander_lab"));
        hander_lab->setGeometry(QRect(110, 90, 151, 131));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hander_lab->sizePolicy().hasHeightForWidth());
        hander_lab->setSizePolicy(sizePolicy);
        hander_lab->setStyleSheet(QString::fromUtf8(""));
        hander_lab->setAlignment(Qt::AlignCenter);

        retranslateUi(CustomSliderStyleTwo);

        QMetaObject::connectSlotsByName(CustomSliderStyleTwo);
    } // setupUi

    void retranslateUi(QWidget *CustomSliderStyleTwo)
    {
        CustomSliderStyleTwo->setWindowTitle(QCoreApplication::translate("CustomSliderStyleTwo", "CustomSliderStyleTwo", nullptr));
        hander_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CustomSliderStyleTwo: public Ui_CustomSliderStyleTwo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMSLIDERSTYLETWO_H

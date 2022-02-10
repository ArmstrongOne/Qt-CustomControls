/********************************************************************************
** Form generated from reading UI file 'CustomSlider.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMSLIDER_H
#define UI_CUSTOMSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "SliderBar.h"

QT_BEGIN_NAMESPACE

class Ui_CustomSlider
{
public:
    QRoundedLabel *hander_lab;

    void setupUi(QWidget *CustomSlider)
    {
        if (CustomSlider->objectName().isEmpty())
            CustomSlider->setObjectName(QString::fromUtf8("CustomSlider"));
        CustomSlider->resize(213, 479);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CustomSlider->sizePolicy().hasHeightForWidth());
        CustomSlider->setSizePolicy(sizePolicy);
        hander_lab = new QRoundedLabel(CustomSlider);
        hander_lab->setObjectName(QString::fromUtf8("hander_lab"));
        hander_lab->setGeometry(QRect(50, 140, 81, 71));
        sizePolicy.setHeightForWidth(hander_lab->sizePolicy().hasHeightForWidth());
        hander_lab->setSizePolicy(sizePolicy);
        hander_lab->setStyleSheet(QString::fromUtf8(""));
        hander_lab->setAlignment(Qt::AlignCenter);

        retranslateUi(CustomSlider);

        QMetaObject::connectSlotsByName(CustomSlider);
    } // setupUi

    void retranslateUi(QWidget *CustomSlider)
    {
        CustomSlider->setWindowTitle(QCoreApplication::translate("CustomSlider", "CustomSlider", nullptr));
        hander_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CustomSlider: public Ui_CustomSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMSLIDER_H

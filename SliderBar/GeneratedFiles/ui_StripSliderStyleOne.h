/********************************************************************************
** Form generated from reading UI file 'StripSliderStyleOne.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRIPSLIDERSTYLEONE_H
#define UI_STRIPSLIDERSTYLEONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "StripSliderStyleOne.h"

QT_BEGIN_NAMESPACE

class Ui_StripSliderStyleOne
{
public:
    QRoundedLabel *hander_lab;

    void setupUi(QWidget *StripSliderStyleOne)
    {
        if (StripSliderStyleOne->objectName().isEmpty())
            StripSliderStyleOne->setObjectName(QStringLiteral("StripSliderStyleOne"));
        StripSliderStyleOne->resize(400, 300);
        hander_lab = new QRoundedLabel(StripSliderStyleOne);
        hander_lab->setObjectName(QStringLiteral("hander_lab"));
        hander_lab->setGeometry(QRect(150, 90, 91, 81));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hander_lab->sizePolicy().hasHeightForWidth());
        hander_lab->setSizePolicy(sizePolicy);

        retranslateUi(StripSliderStyleOne);

        QMetaObject::connectSlotsByName(StripSliderStyleOne);
    } // setupUi

    void retranslateUi(QWidget *StripSliderStyleOne)
    {
        StripSliderStyleOne->setWindowTitle(QApplication::translate("StripSliderStyleOne", "StripSliderStyleOne", Q_NULLPTR));
        hander_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StripSliderStyleOne: public Ui_StripSliderStyleOne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRIPSLIDERSTYLEONE_H

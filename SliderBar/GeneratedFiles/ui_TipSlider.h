/********************************************************************************
** Form generated from reading UI file 'TipSlider.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIPSLIDER_H
#define UI_TIPSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "SliderBar.h"

QT_BEGIN_NAMESPACE

class Ui_TipSlider
{
public:
    QRoundedLabel *hander_lab;
    QRoundedLabel *tip_lab;

    void setupUi(QWidget *TipSlider)
    {
        if (TipSlider->objectName().isEmpty())
            TipSlider->setObjectName(QStringLiteral("TipSlider"));
        TipSlider->resize(291, 486);
        hander_lab = new QRoundedLabel(TipSlider);
        hander_lab->setObjectName(QStringLiteral("hander_lab"));
        hander_lab->setGeometry(QRect(130, 80, 91, 81));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hander_lab->sizePolicy().hasHeightForWidth());
        hander_lab->setSizePolicy(sizePolicy);
        tip_lab = new QRoundedLabel(TipSlider);
        tip_lab->setObjectName(QStringLiteral("tip_lab"));
        tip_lab->setGeometry(QRect(100, 280, 54, 81));
        sizePolicy.setHeightForWidth(tip_lab->sizePolicy().hasHeightForWidth());
        tip_lab->setSizePolicy(sizePolicy);

        retranslateUi(TipSlider);

        QMetaObject::connectSlotsByName(TipSlider);
    } // setupUi

    void retranslateUi(QWidget *TipSlider)
    {
        TipSlider->setWindowTitle(QApplication::translate("TipSlider", "TipSlider", Q_NULLPTR));
        hander_lab->setText(QString());
        tip_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TipSlider: public Ui_TipSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIPSLIDER_H

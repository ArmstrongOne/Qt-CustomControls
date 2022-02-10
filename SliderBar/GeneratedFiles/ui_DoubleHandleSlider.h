/********************************************************************************
** Form generated from reading UI file 'DoubleHandleSlider.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLEHANDLESLIDER_H
#define UI_DOUBLEHANDLESLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "SliderBar.h"

QT_BEGIN_NAMESPACE

class Ui_DoubleHandleSlider
{
public:
    QRoundedLabel *min_handle_lab;
    QRoundedLabel *max_handle_lab;

    void setupUi(QWidget *DoubleHandleSlider)
    {
        if (DoubleHandleSlider->objectName().isEmpty())
            DoubleHandleSlider->setObjectName(QString::fromUtf8("DoubleHandleSlider"));
        DoubleHandleSlider->resize(241, 485);
        min_handle_lab = new QRoundedLabel(DoubleHandleSlider);
        min_handle_lab->setObjectName(QString::fromUtf8("min_handle_lab"));
        min_handle_lab->setGeometry(QRect(60, 60, 81, 71));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(min_handle_lab->sizePolicy().hasHeightForWidth());
        min_handle_lab->setSizePolicy(sizePolicy);
        min_handle_lab->setStyleSheet(QString::fromUtf8(""));
        min_handle_lab->setAlignment(Qt::AlignCenter);
        max_handle_lab = new QRoundedLabel(DoubleHandleSlider);
        max_handle_lab->setObjectName(QString::fromUtf8("max_handle_lab"));
        max_handle_lab->setGeometry(QRect(60, 230, 81, 71));
        sizePolicy.setHeightForWidth(max_handle_lab->sizePolicy().hasHeightForWidth());
        max_handle_lab->setSizePolicy(sizePolicy);
        max_handle_lab->setStyleSheet(QString::fromUtf8(""));
        max_handle_lab->setAlignment(Qt::AlignCenter);

        retranslateUi(DoubleHandleSlider);

        QMetaObject::connectSlotsByName(DoubleHandleSlider);
    } // setupUi

    void retranslateUi(QWidget *DoubleHandleSlider)
    {
        DoubleHandleSlider->setWindowTitle(QCoreApplication::translate("DoubleHandleSlider", "DoubleHandleSlider", nullptr));
        min_handle_lab->setText(QString());
        max_handle_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DoubleHandleSlider: public Ui_DoubleHandleSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLEHANDLESLIDER_H

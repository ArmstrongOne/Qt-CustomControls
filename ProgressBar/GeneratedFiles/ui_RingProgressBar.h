/********************************************************************************
** Form generated from reading UI file 'RingProgressBar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RINGPROGRESSBAR_H
#define UI_RINGPROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RingProgressBar
{
public:
    QLabel *text_lab;

    void setupUi(QWidget *RingProgressBar)
    {
        if (RingProgressBar->objectName().isEmpty())
            RingProgressBar->setObjectName(QString::fromUtf8("RingProgressBar"));
        RingProgressBar->resize(400, 300);
        text_lab = new QLabel(RingProgressBar);
        text_lab->setObjectName(QString::fromUtf8("text_lab"));
        text_lab->setGeometry(QRect(120, 80, 211, 141));
        text_lab->setAlignment(Qt::AlignCenter);

        retranslateUi(RingProgressBar);

        QMetaObject::connectSlotsByName(RingProgressBar);
    } // setupUi

    void retranslateUi(QWidget *RingProgressBar)
    {
        RingProgressBar->setWindowTitle(QCoreApplication::translate("RingProgressBar", "RingProgressBar", nullptr));
        text_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RingProgressBar: public Ui_RingProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RINGPROGRESSBAR_H

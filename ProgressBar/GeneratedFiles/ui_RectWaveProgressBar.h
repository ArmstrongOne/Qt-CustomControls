/********************************************************************************
** Form generated from reading UI file 'RectWaveProgressBar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTWAVEPROGRESSBAR_H
#define UI_RECTWAVEPROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RectWaveProgressBar
{
public:
    QLabel *text_lab;

    void setupUi(QWidget *RectWaveProgressBar)
    {
        if (RectWaveProgressBar->objectName().isEmpty())
            RectWaveProgressBar->setObjectName(QString::fromUtf8("RectWaveProgressBar"));
        RectWaveProgressBar->resize(400, 300);
        text_lab = new QLabel(RectWaveProgressBar);
        text_lab->setObjectName(QString::fromUtf8("text_lab"));
        text_lab->setGeometry(QRect(100, 70, 211, 141));
        text_lab->setAlignment(Qt::AlignCenter);

        retranslateUi(RectWaveProgressBar);

        QMetaObject::connectSlotsByName(RectWaveProgressBar);
    } // setupUi

    void retranslateUi(QWidget *RectWaveProgressBar)
    {
        RectWaveProgressBar->setWindowTitle(QCoreApplication::translate("RectWaveProgressBar", "RectWaveProgressBar", nullptr));
        text_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RectWaveProgressBar: public Ui_RectWaveProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTWAVEPROGRESSBAR_H

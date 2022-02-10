/********************************************************************************
** Form generated from reading UI file 'WaveProgressBar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEPROGRESSBAR_H
#define UI_WAVEPROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaveProgressBar
{
public:
    QLabel *text_lab;

    void setupUi(QWidget *WaveProgressBar)
    {
        if (WaveProgressBar->objectName().isEmpty())
            WaveProgressBar->setObjectName(QString::fromUtf8("WaveProgressBar"));
        WaveProgressBar->resize(400, 300);
        text_lab = new QLabel(WaveProgressBar);
        text_lab->setObjectName(QString::fromUtf8("text_lab"));
        text_lab->setGeometry(QRect(70, 80, 211, 141));
        text_lab->setAlignment(Qt::AlignCenter);

        retranslateUi(WaveProgressBar);

        QMetaObject::connectSlotsByName(WaveProgressBar);
    } // setupUi

    void retranslateUi(QWidget *WaveProgressBar)
    {
        WaveProgressBar->setWindowTitle(QCoreApplication::translate("WaveProgressBar", "WaveProgressBar", nullptr));
        text_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WaveProgressBar: public Ui_WaveProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEPROGRESSBAR_H

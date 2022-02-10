/********************************************************************************
** Form generated from reading UI file 'LinearProgressBar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEARPROGRESSBAR_H
#define UI_LINEARPROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LinearProgressBar
{
public:
    QLabel *text_lab;

    void setupUi(QWidget *LinearProgressBar)
    {
        if (LinearProgressBar->objectName().isEmpty())
            LinearProgressBar->setObjectName(QString::fromUtf8("LinearProgressBar"));
        LinearProgressBar->resize(400, 300);
        text_lab = new QLabel(LinearProgressBar);
        text_lab->setObjectName(QString::fromUtf8("text_lab"));
        text_lab->setGeometry(QRect(80, 70, 211, 141));
        text_lab->setAlignment(Qt::AlignCenter);

        retranslateUi(LinearProgressBar);

        QMetaObject::connectSlotsByName(LinearProgressBar);
    } // setupUi

    void retranslateUi(QWidget *LinearProgressBar)
    {
        LinearProgressBar->setWindowTitle(QCoreApplication::translate("LinearProgressBar", "LinearProgressBar", nullptr));
        text_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LinearProgressBar: public Ui_LinearProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEARPROGRESSBAR_H

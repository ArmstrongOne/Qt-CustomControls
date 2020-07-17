/********************************************************************************
** Form generated from reading UI file 'LinearProgressBar.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEARPROGRESSBAR_H
#define UI_LINEARPROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
            LinearProgressBar->setObjectName(QStringLiteral("LinearProgressBar"));
        LinearProgressBar->resize(400, 300);
        text_lab = new QLabel(LinearProgressBar);
        text_lab->setObjectName(QStringLiteral("text_lab"));
        text_lab->setGeometry(QRect(80, 70, 211, 141));
        text_lab->setAlignment(Qt::AlignCenter);

        retranslateUi(LinearProgressBar);

        QMetaObject::connectSlotsByName(LinearProgressBar);
    } // setupUi

    void retranslateUi(QWidget *LinearProgressBar)
    {
        LinearProgressBar->setWindowTitle(QApplication::translate("LinearProgressBar", "LinearProgressBar", Q_NULLPTR));
        text_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LinearProgressBar: public Ui_LinearProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEARPROGRESSBAR_H

/********************************************************************************
** Form generated from reading UI file 'SemiCirclePanel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEMICIRCLEPANEL_H
#define UI_SEMICIRCLEPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SemiCirclePanel
{
public:

    void setupUi(QWidget *SemiCirclePanel)
    {
        if (SemiCirclePanel->objectName().isEmpty())
            SemiCirclePanel->setObjectName(QString::fromUtf8("SemiCirclePanel"));
        SemiCirclePanel->resize(400, 300);
        SemiCirclePanel->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(SemiCirclePanel);

        QMetaObject::connectSlotsByName(SemiCirclePanel);
    } // setupUi

    void retranslateUi(QWidget *SemiCirclePanel)
    {
        SemiCirclePanel->setWindowTitle(QCoreApplication::translate("SemiCirclePanel", "SemiCirclePanel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SemiCirclePanel: public Ui_SemiCirclePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEMICIRCLEPANEL_H

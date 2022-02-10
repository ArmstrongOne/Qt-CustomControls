/********************************************************************************
** Form generated from reading UI file 'CustomPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMPANEL_H
#define UI_CUSTOMPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomPanel
{
public:

    void setupUi(QWidget *CustomPanel)
    {
        if (CustomPanel->objectName().isEmpty())
            CustomPanel->setObjectName(QString::fromUtf8("CustomPanel"));
        CustomPanel->resize(400, 300);

        retranslateUi(CustomPanel);

        QMetaObject::connectSlotsByName(CustomPanel);
    } // setupUi

    void retranslateUi(QWidget *CustomPanel)
    {
        CustomPanel->setWindowTitle(QCoreApplication::translate("CustomPanel", "CustomPanel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomPanel: public Ui_CustomPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMPANEL_H

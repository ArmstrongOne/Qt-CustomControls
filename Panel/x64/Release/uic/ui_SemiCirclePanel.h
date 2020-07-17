/********************************************************************************
** Form generated from reading UI file 'SemiCirclePanel.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEMICIRCLEPANEL_H
#define UI_SEMICIRCLEPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SemiCirclePanel
{
public:

    void setupUi(QWidget *SemiCirclePanel)
    {
        if (SemiCirclePanel->objectName().isEmpty())
            SemiCirclePanel->setObjectName(QStringLiteral("SemiCirclePanel"));
        SemiCirclePanel->resize(400, 300);
        SemiCirclePanel->setStyleSheet(QStringLiteral(""));

        retranslateUi(SemiCirclePanel);

        QMetaObject::connectSlotsByName(SemiCirclePanel);
    } // setupUi

    void retranslateUi(QWidget *SemiCirclePanel)
    {
        SemiCirclePanel->setWindowTitle(QApplication::translate("SemiCirclePanel", "SemiCirclePanel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SemiCirclePanel: public Ui_SemiCirclePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEMICIRCLEPANEL_H

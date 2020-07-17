/********************************************************************************
** Form generated from reading UI file 'DropDownMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DROPDOWNMENU_H
#define UI_DROPDOWNMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DropDownMenu
{
public:
    QGridLayout *gridLayout;
    QWidget *main_wid;

    void setupUi(QWidget *DropDownMenu)
    {
        if (DropDownMenu->objectName().isEmpty())
            DropDownMenu->setObjectName(QStringLiteral("DropDownMenu"));
        DropDownMenu->resize(400, 300);
        DropDownMenu->setStyleSheet(QStringLiteral("background-color: rgb(26, 26, 26);"));
        gridLayout = new QGridLayout(DropDownMenu);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        main_wid = new QWidget(DropDownMenu);
        main_wid->setObjectName(QStringLiteral("main_wid"));

        gridLayout->addWidget(main_wid, 0, 0, 1, 1);


        retranslateUi(DropDownMenu);

        QMetaObject::connectSlotsByName(DropDownMenu);
    } // setupUi

    void retranslateUi(QWidget *DropDownMenu)
    {
        DropDownMenu->setWindowTitle(QApplication::translate("DropDownMenu", "DropDownMenu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DropDownMenu: public Ui_DropDownMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DROPDOWNMENU_H

/********************************************************************************
** Form generated from reading UI file 'DashBoard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashBoard
{
public:
    QLabel *text_lab;

    void setupUi(QWidget *DashBoard)
    {
        if (DashBoard->objectName().isEmpty())
            DashBoard->setObjectName(QString::fromUtf8("DashBoard"));
        DashBoard->resize(474, 431);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DashBoard->sizePolicy().hasHeightForWidth());
        DashBoard->setSizePolicy(sizePolicy);
        text_lab = new QLabel(DashBoard);
        text_lab->setObjectName(QString::fromUtf8("text_lab"));
        text_lab->setGeometry(QRect(119, 108, 211, 141));
        text_lab->setAlignment(Qt::AlignCenter);

        retranslateUi(DashBoard);

        QMetaObject::connectSlotsByName(DashBoard);
    } // setupUi

    void retranslateUi(QWidget *DashBoard)
    {
        DashBoard->setWindowTitle(QCoreApplication::translate("DashBoard", "DashBoard", nullptr));
        text_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DashBoard: public Ui_DashBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H

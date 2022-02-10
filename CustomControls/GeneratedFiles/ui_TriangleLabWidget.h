/********************************************************************************
** Form generated from reading UI file 'TriangleLabWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIANGLELABWIDGET_H
#define UI_TRIANGLELABWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TriangleLabWidget
{
public:

    void setupUi(QWidget *TriangleLabWidget)
    {
        if (TriangleLabWidget->objectName().isEmpty())
            TriangleLabWidget->setObjectName(QString::fromUtf8("TriangleLabWidget"));
        TriangleLabWidget->resize(94, 380);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TriangleLabWidget->sizePolicy().hasHeightForWidth());
        TriangleLabWidget->setSizePolicy(sizePolicy);
        TriangleLabWidget->setMinimumSize(QSize(1, 1));
        TriangleLabWidget->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(TriangleLabWidget);

        QMetaObject::connectSlotsByName(TriangleLabWidget);
    } // setupUi

    void retranslateUi(QWidget *TriangleLabWidget)
    {
        TriangleLabWidget->setWindowTitle(QCoreApplication::translate("TriangleLabWidget", "TriangleLabWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TriangleLabWidget: public Ui_TriangleLabWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIANGLELABWIDGET_H

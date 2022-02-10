/********************************************************************************
** Form generated from reading UI file 'RXTurnPan.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RXTURNPAN_H
#define UI_RXTURNPAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RXTurnPan
{
public:

    void setupUi(QWidget *RXTurnPan)
    {
        if (RXTurnPan->objectName().isEmpty())
            RXTurnPan->setObjectName(QString::fromUtf8("RXTurnPan"));
        RXTurnPan->resize(400, 300);

        retranslateUi(RXTurnPan);

        QMetaObject::connectSlotsByName(RXTurnPan);
    } // setupUi

    void retranslateUi(QWidget *RXTurnPan)
    {
        RXTurnPan->setWindowTitle(QCoreApplication::translate("RXTurnPan", "RXTurnPan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RXTurnPan: public Ui_RXTurnPan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RXTURNPAN_H

/********************************************************************************
** Form generated from reading UI file 'RXTurnPan.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RXTURNPAN_H
#define UI_RXTURNPAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RXTurnPan
{
public:

    void setupUi(QWidget *RXTurnPan)
    {
        if (RXTurnPan->objectName().isEmpty())
            RXTurnPan->setObjectName(QStringLiteral("RXTurnPan"));
        RXTurnPan->resize(400, 300);

        retranslateUi(RXTurnPan);

        QMetaObject::connectSlotsByName(RXTurnPan);
    } // setupUi

    void retranslateUi(QWidget *RXTurnPan)
    {
        RXTurnPan->setWindowTitle(QApplication::translate("RXTurnPan", "RXTurnPan", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RXTurnPan: public Ui_RXTurnPan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RXTURNPAN_H

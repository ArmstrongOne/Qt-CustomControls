/********************************************************************************
** Form generated from reading UI file 'NetSpeedPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETSPEEDPANEL_H
#define UI_NETSPEEDPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetSpeedPanel
{
public:

    void setupUi(QWidget *NetSpeedPanel)
    {
        if (NetSpeedPanel->objectName().isEmpty())
            NetSpeedPanel->setObjectName(QStringLiteral("NetSpeedPanel"));
        NetSpeedPanel->resize(400, 300);

        retranslateUi(NetSpeedPanel);

        QMetaObject::connectSlotsByName(NetSpeedPanel);
    } // setupUi

    void retranslateUi(QWidget *NetSpeedPanel)
    {
        NetSpeedPanel->setWindowTitle(QApplication::translate("NetSpeedPanel", "NetSpeedPanel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NetSpeedPanel: public Ui_NetSpeedPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETSPEEDPANEL_H

/********************************************************************************
** Form generated from reading UI file 'LoginStateWid.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSTATEWID_H
#define UI_LOGINSTATEWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginStateWid
{
public:
    QGridLayout *gridLayout;
    QWidget *wid_main;
    QGridLayout *gridLayout_2;
    QRadioButton *radiobtn_state_online;
    QRadioButton *radiobtn_state_leave;
    QRadioButton *radiobtn_state_notdisturb;
    QRadioButton *radiobtn_state_busy;
    QRadioButton *radiobtn_state_invisable;

    void setupUi(QWidget *LoginStateWid)
    {
        if (LoginStateWid->objectName().isEmpty())
            LoginStateWid->setObjectName(QStringLiteral("LoginStateWid"));
        LoginStateWid->resize(160, 160);
        LoginStateWid->setMinimumSize(QSize(160, 160));
        LoginStateWid->setMaximumSize(QSize(160, 160));
        gridLayout = new QGridLayout(LoginStateWid);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        wid_main = new QWidget(LoginStateWid);
        wid_main->setObjectName(QStringLiteral("wid_main"));
        wid_main->setMinimumSize(QSize(150, 150));
        wid_main->setMaximumSize(QSize(150, 150));
        wid_main->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 200);"));
        gridLayout_2 = new QGridLayout(wid_main);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        radiobtn_state_online = new QRadioButton(wid_main);
        radiobtn_state_online->setObjectName(QStringLiteral("radiobtn_state_online"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radiobtn_state_online->sizePolicy().hasHeightForWidth());
        radiobtn_state_online->setSizePolicy(sizePolicy);
        radiobtn_state_online->setStyleSheet(QLatin1String("QRadioButton{color: rgb(0, 0, 0);padding-left:10px;} \n"
"\n"
"QRadioButton::indicator {width: 15px; height:15px;color: rgb(166, 166, 166);}\n"
"\n"
"QRadioButton:focus\n"
"{\n"
"color:rgb(166, 166, 166);\n"
"}\n"
"\n"
"QRadioButton::hover:unchecked \n"
"{\n"
"background-color: rgb(238, 238, 238);\n"
"}\n"
"\n"
"QRadioButton::hover:checked \n"
"{\n"
"background-color: rgb(238, 238, 238);\n"
"}\n"
"QRadioButton::indicator:unchecked \n"
"{\n"
"border-image: url(:/icon/Win_Login/state_online.png); \n"
"}\n"
"\n"
"QRadioButton::indicator:checked \n"
"{\n"
"border-image: url(:/icon/Win_Login/state_online.png);\n"
"}\n"
""));

        gridLayout_2->addWidget(radiobtn_state_online, 0, 0, 1, 1);

        radiobtn_state_leave = new QRadioButton(wid_main);
        radiobtn_state_leave->setObjectName(QStringLiteral("radiobtn_state_leave"));
        sizePolicy.setHeightForWidth(radiobtn_state_leave->sizePolicy().hasHeightForWidth());
        radiobtn_state_leave->setSizePolicy(sizePolicy);
        radiobtn_state_leave->setStyleSheet(QLatin1String("QRadioButton{color: rgb(0, 0, 0);padding-left:10px;} \n"
"\n"
"\n"
"QRadioButton::indicator {width: 15px; height:15px;color: rgb(166, 166, 166);}\n"
"\n"
"QRadioButton:focus\n"
"{\n"
"color:rgb(166, 166, 166);\n"
"}\n"
"\n"
"QRadioButton::hover:unchecked \n"
"{\n"
"background-color: rgb(238, 238, 238);\n"
"}\n"
"\n"
"QRadioButton::hover:checked \n"
"{\n"
"background-color: rgb(238, 238, 238);\n"
"}\n"
"QRadioButton::indicator:unchecked \n"
"{\n"
"border-image: url(:/icon/Win_Login/state_leave.png); \n"
"}\n"
"\n"
"QRadioButton::indicator:checked \n"
"{\n"
"border-image: url(:/icon/Win_Login/state_leave.png); \n"
"}"));

        gridLayout_2->addWidget(radiobtn_state_leave, 1, 0, 1, 1);

        radiobtn_state_notdisturb = new QRadioButton(wid_main);
        radiobtn_state_notdisturb->setObjectName(QStringLiteral("radiobtn_state_notdisturb"));
        sizePolicy.setHeightForWidth(radiobtn_state_notdisturb->sizePolicy().hasHeightForWidth());
        radiobtn_state_notdisturb->setSizePolicy(sizePolicy);
        radiobtn_state_notdisturb->setStyleSheet(QLatin1String("QRadioButton{color: rgb(0, 0, 0);padding-left:10px;} \n"
"\n"
"\n"
"QRadioButton::indicator {width: 15px; height:15px;color: rgb(166, 166, 166);}\n"
"\n"
"QRadioButton:focus\n"
"{\n"
"color:rgb(166, 166, 166);\n"
"}\n"
"\n"
"QRadioButton::hover:unchecked \n"
"{\n"
"background-color: rgb(238, 238, 238);\n"
"}\n"
"\n"
"QRadioButton::hover:checked \n"
"{\n"
"background-color: rgb(238, 238, 238);\n"
"}\n"
"QRadioButton::indicator:unchecked \n"
"{\n"
"border-image: url(:/icon/Win_Login/state_ban.png); \n"
"}\n"
"\n"
"QRadioButton::indicator:checked \n"
"{\n"
"border-image: url(:/icon/Win_Login/state_ban.png); \n"
"}"));

        gridLayout_2->addWidget(radiobtn_state_notdisturb, 3, 0, 1, 1);

        radiobtn_state_busy = new QRadioButton(wid_main);
        radiobtn_state_busy->setObjectName(QStringLiteral("radiobtn_state_busy"));
        sizePolicy.setHeightForWidth(radiobtn_state_busy->sizePolicy().hasHeightForWidth());
        radiobtn_state_busy->setSizePolicy(sizePolicy);
        radiobtn_state_busy->setStyleSheet(QLatin1String("QRadioButton{color: rgb(0, 0, 0);padding-left:10px;} \n"
"\n"
"\n"
"QRadioButton::indicator {width: 15px; height:15px;color: rgb(166, 166, 166);}\n"
"\n"
"QRadioButton:focus\n"
"{\n"
"color:rgb(166, 166, 166);\n"
"}\n"
"\n"
"QRadioButton::hover:unchecked \n"
"{\n"
"background-color: rgb(238, 238, 238);\n"
"}\n"
"\n"
"QRadioButton::hover:checked \n"
"{\n"
"background-color: rgb(238, 238, 238);\n"
"}\n"
"QRadioButton::indicator:unchecked \n"
"{\n"
"border-image: url(:/icon/Win_Login/state_busy.png); \n"
"}\n"
"\n"
"QRadioButton::indicator:checked \n"
"{\n"
"border-image: url(:/icon/Win_Login/state_buzy.png); \n"
"}"));

        gridLayout_2->addWidget(radiobtn_state_busy, 2, 0, 1, 1);

        radiobtn_state_invisable = new QRadioButton(wid_main);
        radiobtn_state_invisable->setObjectName(QStringLiteral("radiobtn_state_invisable"));
        sizePolicy.setHeightForWidth(radiobtn_state_invisable->sizePolicy().hasHeightForWidth());
        radiobtn_state_invisable->setSizePolicy(sizePolicy);
        radiobtn_state_invisable->setStyleSheet(QLatin1String("QRadioButton{color: rgb(0, 0, 0);padding-left:10px;} \n"
"\n"
"\n"
"QRadioButton::indicator {width: 15px; height:15px;color: rgb(166, 166, 166);}\n"
"\n"
"QRadioButton:focus\n"
"{\n"
"color:rgb(166, 166, 166);\n"
"}\n"
"\n"
"QRadioButton::hover:unchecked \n"
"{\n"
"background-color: rgb(238, 238, 238);\n"
"}\n"
"\n"
"QRadioButton::hover:checked \n"
"{\n"
"background-color: rgb(238, 238, 238);\n"
"}\n"
"QRadioButton::indicator:unchecked \n"
"{\n"
"border-image: url(:/icon/Win_Login/state_yinshen.png); \n"
"}\n"
"\n"
"QRadioButton::indicator:checked \n"
"{\n"
"border-image: url(:/icon/Win_Login/state_yinshen.png); \n"
"}"));

        gridLayout_2->addWidget(radiobtn_state_invisable, 4, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 10);
        gridLayout_2->setRowStretch(1, 10);
        gridLayout_2->setRowStretch(2, 10);
        gridLayout_2->setRowStretch(3, 10);
        gridLayout_2->setRowStretch(4, 10);
        gridLayout_2->setRowMinimumHeight(0, 10);
        gridLayout_2->setRowMinimumHeight(1, 10);
        gridLayout_2->setRowMinimumHeight(2, 10);
        gridLayout_2->setRowMinimumHeight(3, 10);
        gridLayout_2->setRowMinimumHeight(4, 10);

        gridLayout->addWidget(wid_main, 0, 0, 1, 1);


        retranslateUi(LoginStateWid);

        QMetaObject::connectSlotsByName(LoginStateWid);
    } // setupUi

    void retranslateUi(QWidget *LoginStateWid)
    {
        LoginStateWid->setWindowTitle(QApplication::translate("LoginStateWid", "LoginStateWid", Q_NULLPTR));
        radiobtn_state_online->setText(QApplication::translate("LoginStateWid", "  \346\210\221\345\234\250\347\272\277\344\270\212", Q_NULLPTR));
        radiobtn_state_leave->setText(QApplication::translate("LoginStateWid", "  \347\246\273\345\274\200", Q_NULLPTR));
        radiobtn_state_notdisturb->setText(QApplication::translate("LoginStateWid", "  \350\257\267\345\213\277\346\211\223\346\211\260", Q_NULLPTR));
        radiobtn_state_busy->setText(QApplication::translate("LoginStateWid", "  \345\277\231\347\242\214", Q_NULLPTR));
        radiobtn_state_invisable->setText(QApplication::translate("LoginStateWid", "  \351\232\220\350\272\253", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginStateWid: public Ui_LoginStateWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSTATEWID_H

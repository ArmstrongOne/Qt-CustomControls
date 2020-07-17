/********************************************************************************
** Form generated from reading UI file 'LoginAvatarWid.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINAVATARWID_H
#define UI_LOGINAVATARWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginAvatarWid
{
public:
    QPushButton *btn_login_state;

    void setupUi(QWidget *LoginAvatarWid)
    {
        if (LoginAvatarWid->objectName().isEmpty())
            LoginAvatarWid->setObjectName(QStringLiteral("LoginAvatarWid"));
        LoginAvatarWid->setWindowModality(Qt::NonModal);
        LoginAvatarWid->resize(94, 70);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginAvatarWid->sizePolicy().hasHeightForWidth());
        LoginAvatarWid->setSizePolicy(sizePolicy);
        LoginAvatarWid->setMinimumSize(QSize(70, 70));
        LoginAvatarWid->setMaximumSize(QSize(94, 70));
        btn_login_state = new QPushButton(LoginAvatarWid);
        btn_login_state->setObjectName(QStringLiteral("btn_login_state"));
        btn_login_state->setGeometry(QRect(240, 220, 16, 16));
        btn_login_state->setMinimumSize(QSize(16, 16));
        btn_login_state->setMaximumSize(QSize(16, 16));
        btn_login_state->setStyleSheet(QLatin1String("border:0px;\n"
"border-image: url(:/icon/Win_Login/state_online.png);"));

        retranslateUi(LoginAvatarWid);

        QMetaObject::connectSlotsByName(LoginAvatarWid);
    } // setupUi

    void retranslateUi(QWidget *LoginAvatarWid)
    {
        LoginAvatarWid->setWindowTitle(QApplication::translate("LoginAvatarWid", "LoginAvatarWid", Q_NULLPTR));
        btn_login_state->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginAvatarWid: public Ui_LoginAvatarWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINAVATARWID_H

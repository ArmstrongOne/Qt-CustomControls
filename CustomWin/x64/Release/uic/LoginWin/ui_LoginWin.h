/********************************************************************************
** Form generated from reading UI file 'LoginWin.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIN_H
#define UI_LOGINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWin
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stack_wid_main;
    QWidget *main_page;
    QVBoxLayout *verticalLayout_2;
    QWidget *wid_top;
    QVBoxLayout *verticalLayout_3;
    QWidget *wid_tool;
    QHBoxLayout *horizontalLayout;
    QLabel *lab_logo;
    QLabel *lab_logo_text;
    QSpacerItem *horizontalSpacer;
    QWidget *wid_top_btns;
    QGridLayout *gridLayout;
    QPushButton *btn_setting;
    QPushButton *btn_min;
    QPushButton *btn_close;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QWidget *wid_bottom;
    QHBoxLayout *horizontalLayout_2;
    QWidget *wid_left;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btn_register;
    QWidget *wid_mid;
    QVBoxLayout *verticalLayout_5;
    QWidget *wid_account;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lab_account_logo;
    QLineEdit *edit_account;
    QWidget *wid_password;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lab_password_logo;
    QLineEdit *edit_password;
    QWidget *wid_btns;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkbtn_auto_login;
    QCheckBox *checkbtn_remb_password;
    QPushButton *btn_search_password;
    QPushButton *pushButton;
    QWidget *wid_right;
    QWidget *page_2;

    void setupUi(QWidget *LoginWin)
    {
        if (LoginWin->objectName().isEmpty())
            LoginWin->setObjectName(QStringLiteral("LoginWin"));
        LoginWin->resize(440, 340);
        LoginWin->setMinimumSize(QSize(440, 340));
        LoginWin->setMaximumSize(QSize(440, 354));
        verticalLayout = new QVBoxLayout(LoginWin);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        stack_wid_main = new QStackedWidget(LoginWin);
        stack_wid_main->setObjectName(QStringLiteral("stack_wid_main"));
        main_page = new QWidget();
        main_page->setObjectName(QStringLiteral("main_page"));
        verticalLayout_2 = new QVBoxLayout(main_page);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        wid_top = new QWidget(main_page);
        wid_top->setObjectName(QStringLiteral("wid_top"));
        wid_top->setMinimumSize(QSize(0, 130));
        wid_top->setMaximumSize(QSize(16777215, 130));
        wid_top->setStyleSheet(QLatin1String("#wid_top\n"
"{\n"
"background-color: qlineargradient(spread:reflect, x1:0.845, y1:0, x2:0.408, y2:0.829727, stop:0 rgba(0, 20, 0, 255), stop:0.966102 rgba(102, 112, 255, 255));\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(wid_top);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        wid_tool = new QWidget(wid_top);
        wid_tool->setObjectName(QStringLiteral("wid_tool"));
        wid_tool->setMinimumSize(QSize(0, 50));
        wid_tool->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(wid_tool);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lab_logo = new QLabel(wid_tool);
        lab_logo->setObjectName(QStringLiteral("lab_logo"));
        lab_logo->setMinimumSize(QSize(50, 0));
        lab_logo->setMaximumSize(QSize(50, 16777215));
        lab_logo->setStyleSheet(QLatin1String("border-image: url(:/icon/Win_Login/logo.png);\n"
"margin-top:8px;\n"
"margin-bottom:8px;\n"
"margin-left:8px;\n"
"margin-right:8px;"));

        horizontalLayout->addWidget(lab_logo);

        lab_logo_text = new QLabel(wid_tool);
        lab_logo_text->setObjectName(QStringLiteral("lab_logo_text"));
        lab_logo_text->setMinimumSize(QSize(100, 0));
        lab_logo_text->setMaximumSize(QSize(100, 16777215));
        lab_logo_text->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"border-image: url(:/icon/Win_Login/logo_text.png);\n"
"margin-top:10px;\n"
"margin-bottom:10px;\n"
""));

        horizontalLayout->addWidget(lab_logo_text);

        horizontalSpacer = new QSpacerItem(197, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        wid_top_btns = new QWidget(wid_tool);
        wid_top_btns->setObjectName(QStringLiteral("wid_top_btns"));
        gridLayout = new QGridLayout(wid_top_btns);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 0, 0, 0);
        btn_setting = new QPushButton(wid_top_btns);
        btn_setting->setObjectName(QStringLiteral("btn_setting"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_setting->sizePolicy().hasHeightForWidth());
        btn_setting->setSizePolicy(sizePolicy);
        btn_setting->setMinimumSize(QSize(25, 25));
        btn_setting->setMaximumSize(QSize(25, 25));
        btn_setting->setStyleSheet(QLatin1String("\n"
"\n"
"QPushButton \n"
"{\n"
"border-image: url(:/icon/Win_Login/setting.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"border-image: url(:/icon/Win_Login/setting.png);\n"
"background-color: rgb(255, 255, 255,200);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"border-image: url(:/icon/Win_Login/setting.png);\n"
"background-color: rgb(255, 255, 255,100);\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled \n"
"{\n"
"\n"
"}"));

        gridLayout->addWidget(btn_setting, 0, 0, 1, 1);

        btn_min = new QPushButton(wid_top_btns);
        btn_min->setObjectName(QStringLiteral("btn_min"));
        sizePolicy.setHeightForWidth(btn_min->sizePolicy().hasHeightForWidth());
        btn_min->setSizePolicy(sizePolicy);
        btn_min->setMinimumSize(QSize(25, 25));
        btn_min->setMaximumSize(QSize(25, 25));
        btn_min->setStyleSheet(QLatin1String("\n"
"\n"
"QPushButton \n"
"{\n"
"border-image: url(:/icon/Win_Login/win_min.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"border-image: url(:/icon/Win_Login/win_min.png);\n"
"background-color: rgb(255, 255, 255,200);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"border-image: url(:/icon/Win_Login/win_min.png);\n"
"background-color: rgb(255, 255, 255,100);\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled \n"
"{\n"
"\n"
"}"));

        gridLayout->addWidget(btn_min, 0, 1, 1, 1);

        btn_close = new QPushButton(wid_top_btns);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        btn_close->setMinimumSize(QSize(25, 25));
        btn_close->setMaximumSize(QSize(25, 25));
        btn_close->setStyleSheet(QLatin1String("\n"
"QPushButton \n"
"{\n"
"border-image: url(:/icon/Win_Login/close.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"border-image: url(:/icon/Win_Login/close.png);\n"
"background-color: rgb(255, 84, 57,255);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"border-image: url(:/icon/Win_Login/close.png);\n"
"background-color: rgb(255, 84, 57,255);\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled \n"
"{\n"
"\n"
"}"));

        gridLayout->addWidget(btn_close, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setColumnStretch(0, 10);
        gridLayout->setColumnStretch(1, 10);
        gridLayout->setColumnStretch(2, 10);

        horizontalLayout->addWidget(wid_top_btns);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(2, 10);
        horizontalLayout->setStretch(3, 4);

        verticalLayout_3->addWidget(wid_tool);

        verticalSpacer = new QSpacerItem(20, 77, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_3->setStretch(0, 10);
        verticalLayout_3->setStretch(1, 10);

        verticalLayout_2->addWidget(wid_top);

        wid_bottom = new QWidget(main_page);
        wid_bottom->setObjectName(QStringLiteral("wid_bottom"));
        wid_bottom->setStyleSheet(QLatin1String("#wid_bottom\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(wid_bottom);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        wid_left = new QWidget(wid_bottom);
        wid_left->setObjectName(QStringLiteral("wid_left"));
        verticalLayout_4 = new QVBoxLayout(wid_left);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 10);
        verticalSpacer_3 = new QSpacerItem(20, 175, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        btn_register = new QPushButton(wid_left);
        btn_register->setObjectName(QStringLiteral("btn_register"));
        btn_register->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(166, 166, 166);\n"
"border:0px;\n"
""));

        verticalLayout_4->addWidget(btn_register);


        horizontalLayout_2->addWidget(wid_left);

        wid_mid = new QWidget(wid_bottom);
        wid_mid->setObjectName(QStringLiteral("wid_mid"));
        wid_mid->setMinimumSize(QSize(240, 0));
        wid_mid->setMaximumSize(QSize(240, 16777215));
        verticalLayout_5 = new QVBoxLayout(wid_mid);
        verticalLayout_5->setSpacing(8);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 40, 0, 20);
        wid_account = new QWidget(wid_mid);
        wid_account->setObjectName(QStringLiteral("wid_account"));
        sizePolicy.setHeightForWidth(wid_account->sizePolicy().hasHeightForWidth());
        wid_account->setSizePolicy(sizePolicy);
        wid_account->setMinimumSize(QSize(0, 30));
        wid_account->setMaximumSize(QSize(16777215, 30));
        wid_account->setStyleSheet(QLatin1String("#wid_account\n"
"{\n"
"border:1px solid;\n"
"border-top:0px;\n"
"border-left:0px;\n"
"border-right:0px;\n"
"border-color:rgb(229,229,229);\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(wid_account);
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 1, 2, 1);
        lab_account_logo = new QLabel(wid_account);
        lab_account_logo->setObjectName(QStringLiteral("lab_account_logo"));
        lab_account_logo->setMinimumSize(QSize(20, 20));
        lab_account_logo->setMaximumSize(QSize(20, 20));
        lab_account_logo->setStyleSheet(QStringLiteral("border-image: url(:/icon/Win_Login/uncheck_account_ logo.png);"));

        horizontalLayout_3->addWidget(lab_account_logo);

        edit_account = new QLineEdit(wid_account);
        edit_account->setObjectName(QStringLiteral("edit_account"));
        sizePolicy.setHeightForWidth(edit_account->sizePolicy().hasHeightForWidth());
        edit_account->setSizePolicy(sizePolicy);
        edit_account->setStyleSheet(QStringLiteral("border:0px;"));

        horizontalLayout_3->addWidget(edit_account);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 10);

        verticalLayout_5->addWidget(wid_account);

        wid_password = new QWidget(wid_mid);
        wid_password->setObjectName(QStringLiteral("wid_password"));
        sizePolicy.setHeightForWidth(wid_password->sizePolicy().hasHeightForWidth());
        wid_password->setSizePolicy(sizePolicy);
        wid_password->setMinimumSize(QSize(0, 30));
        wid_password->setMaximumSize(QSize(1111111, 30));
        wid_password->setStyleSheet(QLatin1String("#wid_password\n"
"{\n"
"border:1px solid;\n"
"border-top:0px;\n"
"border-left:0px;\n"
"border-right:0px;\n"
"border-color:rgb(229,229,229);\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(wid_password);
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(2, 1, 2, 1);
        lab_password_logo = new QLabel(wid_password);
        lab_password_logo->setObjectName(QStringLiteral("lab_password_logo"));
        lab_password_logo->setMinimumSize(QSize(20, 20));
        lab_password_logo->setMaximumSize(QSize(20, 20));
        lab_password_logo->setStyleSheet(QStringLiteral("border-image: url(:/icon/Win_Login/uncheck_code_logo.png);"));

        horizontalLayout_4->addWidget(lab_password_logo);

        edit_password = new QLineEdit(wid_password);
        edit_password->setObjectName(QStringLiteral("edit_password"));
        sizePolicy.setHeightForWidth(edit_password->sizePolicy().hasHeightForWidth());
        edit_password->setSizePolicy(sizePolicy);
        edit_password->setMinimumSize(QSize(0, 1));
        edit_password->setMaximumSize(QSize(16777215, 11111));
        edit_password->setStyleSheet(QStringLiteral("border:0px;"));

        horizontalLayout_4->addWidget(edit_password);

        horizontalLayout_4->setStretch(0, 10);
        horizontalLayout_4->setStretch(1, 100);

        verticalLayout_5->addWidget(wid_password);

        wid_btns = new QWidget(wid_mid);
        wid_btns->setObjectName(QStringLiteral("wid_btns"));
        sizePolicy.setHeightForWidth(wid_btns->sizePolicy().hasHeightForWidth());
        wid_btns->setSizePolicy(sizePolicy);
        wid_btns->setMinimumSize(QSize(0, 35));
        wid_btns->setMaximumSize(QSize(16777215, 35));
        horizontalLayout_5 = new QHBoxLayout(wid_btns);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        checkbtn_auto_login = new QCheckBox(wid_btns);
        checkbtn_auto_login->setObjectName(QStringLiteral("checkbtn_auto_login"));
        checkbtn_auto_login->setStyleSheet(QLatin1String("QCheckBox{color:rgb(166,166,166)} \n"
"\n"
"QCheckBox::indicator {width: 15px; height:15px;color: rgb(166, 166, 166);}\n"
"\n"
"QCheckBox:focus\n"
"{\n"
"color:rgb(166, 166, 166);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {border-image: url(:/icon/Win_Login/uncheck_checkbtn.png);}\n"
"\n"
"\n"
"QCheckBox::indicator:checked {border-image: url(:/icon/Win_Login/check_checkbtn.png);}\n"
""));

        horizontalLayout_5->addWidget(checkbtn_auto_login);

        checkbtn_remb_password = new QCheckBox(wid_btns);
        checkbtn_remb_password->setObjectName(QStringLiteral("checkbtn_remb_password"));
        checkbtn_remb_password->setStyleSheet(QLatin1String("QCheckBox{color:rgb(166,166,166)} \n"
"\n"
"QCheckBox::indicator {width: 15px; height:15px;color: rgb(166, 166, 166);}\n"
"\n"
"QCheckBox:focus\n"
"{\n"
"color:rgb(166, 166, 166);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {border-image: url(:/icon/Win_Login/uncheck_checkbtn.png);}\n"
"\n"
"\n"
"QCheckBox::indicator:checked {border-image: url(:/icon/Win_Login/check_checkbtn.png);}\n"
""));

        horizontalLayout_5->addWidget(checkbtn_remb_password);

        btn_search_password = new QPushButton(wid_btns);
        btn_search_password->setObjectName(QStringLiteral("btn_search_password"));
        btn_search_password->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(166, 166, 166);\n"
"border:0px;"));

        horizontalLayout_5->addWidget(btn_search_password);


        verticalLayout_5->addWidget(wid_btns);

        pushButton = new QPushButton(wid_mid);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(0, 35));
        pushButton->setMaximumSize(QSize(16777215, 35));
        pushButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(80, 90, 196);\n"
"radius:5px;\n"
"border-radius:5px;"));

        verticalLayout_5->addWidget(pushButton);


        horizontalLayout_2->addWidget(wid_mid);

        wid_right = new QWidget(wid_bottom);
        wid_right->setObjectName(QStringLiteral("wid_right"));

        horizontalLayout_2->addWidget(wid_right);

        horizontalLayout_2->setStretch(0, 10);
        horizontalLayout_2->setStretch(1, 10);
        horizontalLayout_2->setStretch(2, 10);

        verticalLayout_2->addWidget(wid_bottom);

        verticalLayout_2->setStretch(0, 10);
        verticalLayout_2->setStretch(1, 10);
        stack_wid_main->addWidget(main_page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stack_wid_main->addWidget(page_2);

        verticalLayout->addWidget(stack_wid_main);


        retranslateUi(LoginWin);

        stack_wid_main->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginWin);
    } // setupUi

    void retranslateUi(QWidget *LoginWin)
    {
        LoginWin->setWindowTitle(QApplication::translate("LoginWin", "LoginWin", Q_NULLPTR));
        lab_logo->setText(QString());
        lab_logo_text->setText(QString());
        btn_setting->setText(QString());
        btn_min->setText(QString());
        btn_close->setText(QString());
        btn_register->setText(QApplication::translate("LoginWin", "\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
        lab_account_logo->setText(QString());
        lab_password_logo->setText(QString());
        checkbtn_auto_login->setText(QApplication::translate("LoginWin", "\350\207\252\345\212\250\347\231\273\351\231\206", Q_NULLPTR));
        checkbtn_remb_password->setText(QApplication::translate("LoginWin", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        btn_search_password->setText(QApplication::translate("LoginWin", "\346\211\276\345\233\236\345\257\206\347\240\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("LoginWin", "\347\231\273\351\231\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWin: public Ui_LoginWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIN_H

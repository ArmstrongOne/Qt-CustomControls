/********************************************************************************
** Form generated from reading UI file 'RXTools.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RXTOOLS_H
#define UI_RXTOOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "RXToolModeWid.h"

QT_BEGIN_NAMESPACE

class Ui_RXToolsClass
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *top_wid;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *company_logo_wid;
    QLabel *company_name_lab;
    QSpacerItem *horizontalSpacer;
    QWidget *user_head_pic_wid;
    QLabel *user_name_lab;
    QWidget *widget_3;
    QPushButton *hide_win_btn;
    QPushButton *zoom_win_btn;
    QPushButton *close_win_btn;
    QWidget *main_widget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QWidget *tip_wid;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_top;
    QLabel *label_bottom;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *btn_group_wid;
    QGridLayout *gridLayout_2;
    RXToolModeWid *serielport_test_wid;
    RXToolModeWid *pushstation_wid;
    RXToolModeWid *batch_handle_wid;
    RXToolModeWid *dicom_modify_wid;
    RXToolModeWid *ini_file_modify_wid;
    RXToolModeWid *reset_setting_wid;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *RXToolsClass)
    {
        if (RXToolsClass->objectName().isEmpty())
            RXToolsClass->setObjectName(QStringLiteral("RXToolsClass"));
        RXToolsClass->resize(370, 250);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RXToolsClass->sizePolicy().hasHeightForWidth());
        RXToolsClass->setSizePolicy(sizePolicy);
        RXToolsClass->setMinimumSize(QSize(1, 1));
        RXToolsClass->setMaximumSize(QSize(11111111, 460111));
        RXToolsClass->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(RXToolsClass);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        top_wid = new QWidget(RXToolsClass);
        top_wid->setObjectName(QStringLiteral("top_wid"));
        top_wid->setMinimumSize(QSize(0, 60));
        top_wid->setMaximumSize(QSize(16777215, 60));
        top_wid->setStyleSheet(QStringLiteral("background-color: rgb(238, 240, 246);"));
        horizontalLayout_2 = new QHBoxLayout(top_wid);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 10, 0);
        widget = new QWidget(top_wid);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(120, 0));
        widget->setMaximumSize(QSize(120, 16777215));
        widget->setSizeIncrement(QSize(100, 0));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        company_logo_wid = new QWidget(widget);
        company_logo_wid->setObjectName(QStringLiteral("company_logo_wid"));
        company_logo_wid->setMinimumSize(QSize(40, 40));
        company_logo_wid->setMaximumSize(QSize(40, 40));
        company_logo_wid->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/icon/company_logo.png);"));

        horizontalLayout->addWidget(company_logo_wid);

        company_name_lab = new QLabel(widget);
        company_name_lab->setObjectName(QStringLiteral("company_name_lab"));
        company_name_lab->setMinimumSize(QSize(60, 60));
        company_name_lab->setMaximumSize(QSize(60, 60));
        company_name_lab->setStyleSheet(QString::fromUtf8("\n"
"font: 20px \"\351\273\221\344\275\223\";\n"
"color: rgb(50, 50, 50);"));
        company_name_lab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(company_name_lab);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        horizontalLayout_2->addWidget(widget);

        horizontalSpacer = new QSpacerItem(63, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        user_head_pic_wid = new QWidget(top_wid);
        user_head_pic_wid->setObjectName(QStringLiteral("user_head_pic_wid"));
        user_head_pic_wid->setMinimumSize(QSize(30, 30));
        user_head_pic_wid->setMaximumSize(QSize(30, 30));
        user_head_pic_wid->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/icon/head_pic.png);"));

        horizontalLayout_2->addWidget(user_head_pic_wid);

        user_name_lab = new QLabel(top_wid);
        user_name_lab->setObjectName(QStringLiteral("user_name_lab"));
        user_name_lab->setMinimumSize(QSize(90, 50));
        user_name_lab->setMaximumSize(QSize(90, 50));
        user_name_lab->setStyleSheet(QString::fromUtf8("\n"
"font: 12px \"\346\226\260\345\256\213\344\275\223\";"));

        horizontalLayout_2->addWidget(user_name_lab);

        widget_3 = new QWidget(top_wid);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(20, 35));
        widget_3->setMaximumSize(QSize(20, 35));
        widget_3->setStyleSheet(QStringLiteral("border-image: url(:/RXTools/icon/divider.png);"));

        horizontalLayout_2->addWidget(widget_3);

        hide_win_btn = new QPushButton(top_wid);
        hide_win_btn->setObjectName(QStringLiteral("hide_win_btn"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(hide_win_btn->sizePolicy().hasHeightForWidth());
        hide_win_btn->setSizePolicy(sizePolicy1);
        hide_win_btn->setMinimumSize(QSize(15, 15));
        hide_win_btn->setMaximumSize(QSize(15, 15));
        hide_win_btn->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/RXTools/icon/hide_btn.png);background-color:rgb(255, 255, 255,0);}\n"
"QPushButton:hover{border-image: url(:/RXTools/icon/hide_btn.png);background-color:rgb(255, 255, 255,0);}\n"
"QPushButton:pressed{border-image: url(:/RXTools/icon/hide_btn.png);background-color:rgb(255, 255, 255,0);}"));

        horizontalLayout_2->addWidget(hide_win_btn);

        zoom_win_btn = new QPushButton(top_wid);
        zoom_win_btn->setObjectName(QStringLiteral("zoom_win_btn"));
        sizePolicy1.setHeightForWidth(zoom_win_btn->sizePolicy().hasHeightForWidth());
        zoom_win_btn->setSizePolicy(sizePolicy1);
        zoom_win_btn->setMinimumSize(QSize(15, 15));
        zoom_win_btn->setMaximumSize(QSize(15, 15));
        zoom_win_btn->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/RXTools/icon/zoom_btn.png);background-color:rgb(255, 255, 255,0);}\n"
"QPushButton:hover{border-image: url(:/RXTools/icon/zoom_btn.png);background-color:rgb(255, 255, 255,0);}\n"
"QPushButton:pressed{border-image: url(:/RXTools/icon/zoom_btn.png);background-color:rgb(255, 255, 255,0);}"));

        horizontalLayout_2->addWidget(zoom_win_btn);

        close_win_btn = new QPushButton(top_wid);
        close_win_btn->setObjectName(QStringLiteral("close_win_btn"));
        sizePolicy1.setHeightForWidth(close_win_btn->sizePolicy().hasHeightForWidth());
        close_win_btn->setSizePolicy(sizePolicy1);
        close_win_btn->setMinimumSize(QSize(15, 15));
        close_win_btn->setMaximumSize(QSize(15, 15));
        close_win_btn->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/RXTools/icon/close.png);background-color:rgb(255, 255, 255,0);}\n"
"QPushButton:hover{border-image: url(:/RXTools/icon/close.png);background-color:rgb(255, 255, 255,0);}\n"
"QPushButton:pressed{border-image: url(:/RXTools/icon/close.png);background-color:rgb(255, 255, 255,0);}"));

        horizontalLayout_2->addWidget(close_win_btn);

        horizontalLayout_2->setStretch(0, 10);
        horizontalLayout_2->setStretch(1, 10);
        horizontalLayout_2->setStretch(2, 10);
        horizontalLayout_2->setStretch(3, 10);
        horizontalLayout_2->setStretch(5, 10);
        horizontalLayout_2->setStretch(6, 10);
        horizontalLayout_2->setStretch(7, 10);

        verticalLayout->addWidget(top_wid);

        main_widget = new QWidget(RXToolsClass);
        main_widget->setObjectName(QStringLiteral("main_widget"));
        main_widget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(main_widget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(56, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        tip_wid = new QWidget(main_widget);
        tip_wid->setObjectName(QStringLiteral("tip_wid"));
        verticalLayout_2 = new QVBoxLayout(tip_wid);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_top = new QLabel(tip_wid);
        label_top->setObjectName(QStringLiteral("label_top"));
        label_top->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_top->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_top);

        label_bottom = new QLabel(tip_wid);
        label_bottom->setObjectName(QStringLiteral("label_bottom"));
        label_bottom->setStyleSheet(QString::fromUtf8("color: rgb(150, 150, 150);\n"
"font: 10px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_bottom->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_bottom);

        verticalLayout_2->setStretch(0, 10);
        verticalLayout_2->setStretch(1, 10);

        gridLayout->addWidget(tip_wid, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(56, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 9, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(56, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        btn_group_wid = new QWidget(main_widget);
        btn_group_wid->setObjectName(QStringLiteral("btn_group_wid"));
        btn_group_wid->setMinimumSize(QSize(1, 1));
        btn_group_wid->setMaximumSize(QSize(10000, 10000));
        gridLayout_2 = new QGridLayout(btn_group_wid);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(15);
        gridLayout_2->setVerticalSpacing(20);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        serielport_test_wid = new RXToolModeWid(btn_group_wid);
        serielport_test_wid->setObjectName(QStringLiteral("serielport_test_wid"));

        gridLayout_2->addWidget(serielport_test_wid, 1, 2, 1, 1);

        pushstation_wid = new RXToolModeWid(btn_group_wid);
        pushstation_wid->setObjectName(QStringLiteral("pushstation_wid"));

        gridLayout_2->addWidget(pushstation_wid, 1, 1, 1, 1);

        batch_handle_wid = new RXToolModeWid(btn_group_wid);
        batch_handle_wid->setObjectName(QStringLiteral("batch_handle_wid"));

        gridLayout_2->addWidget(batch_handle_wid, 0, 2, 1, 1);

        dicom_modify_wid = new RXToolModeWid(btn_group_wid);
        dicom_modify_wid->setObjectName(QStringLiteral("dicom_modify_wid"));

        gridLayout_2->addWidget(dicom_modify_wid, 0, 1, 1, 1);

        ini_file_modify_wid = new RXToolModeWid(btn_group_wid);
        ini_file_modify_wid->setObjectName(QStringLiteral("ini_file_modify_wid"));

        gridLayout_2->addWidget(ini_file_modify_wid, 0, 0, 1, 1);

        reset_setting_wid = new RXToolModeWid(btn_group_wid);
        reset_setting_wid->setObjectName(QStringLiteral("reset_setting_wid"));

        gridLayout_2->addWidget(reset_setting_wid, 1, 0, 1, 1);


        gridLayout->addWidget(btn_group_wid, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(56, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 74, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 1, 1, 1);

        gridLayout->setRowStretch(0, 10);
        gridLayout->setRowStretch(1, 20);
        gridLayout->setRowStretch(2, 5);
        gridLayout->setRowStretch(3, 100);
        gridLayout->setRowStretch(4, 10);
        gridLayout->setColumnStretch(0, 5);
        gridLayout->setColumnStretch(1, 100);
        gridLayout->setColumnStretch(2, 5);

        verticalLayout->addWidget(main_widget);

        verticalLayout->setStretch(0, 20);
        verticalLayout->setStretch(1, 100);

        retranslateUi(RXToolsClass);

        QMetaObject::connectSlotsByName(RXToolsClass);
    } // setupUi

    void retranslateUi(QWidget *RXToolsClass)
    {
        RXToolsClass->setWindowTitle(QApplication::translate("RXToolsClass", "RXTools", Q_NULLPTR));
        company_name_lab->setText(QApplication::translate("RXToolsClass", "Name", Q_NULLPTR));
        user_name_lab->setText(QApplication::translate("RXToolsClass", "user", Q_NULLPTR));
        hide_win_btn->setText(QString());
        zoom_win_btn->setText(QString());
        close_win_btn->setText(QString());
        label_top->setText(QApplication::translate("RXToolsClass", "\345\267\245\345\205\267\345\214\205", Q_NULLPTR));
        label_bottom->setText(QApplication::translate("RXToolsClass", "\346\233\264\345\244\232\345\212\237\350\203\275,\345\270\246\347\273\231\346\202\250\346\233\264\350\264\264\345\277\203\347\232\204\344\275\223\351\252\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RXToolsClass: public Ui_RXToolsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RXTOOLS_H

/********************************************************************************
** Form generated from reading UI file 'RXDateSelectPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RXDATESELECTPAGE_H
#define UI_RXDATESELECTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RXDateSelectPage
{
public:
    QVBoxLayout *verticalLayout_6;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QWidget *data_show_mode;
    QHBoxLayout *horizontalLayout;
    QWidget *year_mode;
    QVBoxLayout *verticalLayout;
    QLabel *last_year;
    QLabel *cur_year;
    QLabel *next_year;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QWidget *widget_4;
    QWidget *widget_7;
    QWidget *widget_5;
    QWidget *widget_8;
    QWidget *widget_6;
    QWidget *widget_9;
    QWidget *month_mode;
    QVBoxLayout *verticalLayout_2;
    QLabel *last_month;
    QLabel *cur_month;
    QLabel *next_month;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QWidget *widget_10;
    QWidget *widget_11;
    QWidget *widget_12;
    QWidget *widget_13;
    QWidget *widget_14;
    QWidget *widget_16;
    QWidget *day_mode;
    QVBoxLayout *day_mode_layout;
    QLabel *last_day;
    QLabel *cur_day;
    QLabel *next_day;
    QWidget *btn_group;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *date_confirm_btn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancel_btn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *RXDateSelectPage)
    {
        if (RXDateSelectPage->objectName().isEmpty())
            RXDateSelectPage->setObjectName(QString::fromUtf8("RXDateSelectPage"));
        RXDateSelectPage->resize(181, 147);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RXDateSelectPage->sizePolicy().hasHeightForWidth());
        RXDateSelectPage->setSizePolicy(sizePolicy);
        RXDateSelectPage->setStyleSheet(QString::fromUtf8("outline:none;"));
        verticalLayout_6 = new QVBoxLayout(RXDateSelectPage);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(RXDateSelectPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8("border:0px;"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        data_show_mode = new QWidget(widget);
        data_show_mode->setObjectName(QString::fromUtf8("data_show_mode"));
        sizePolicy.setHeightForWidth(data_show_mode->sizePolicy().hasHeightForWidth());
        data_show_mode->setSizePolicy(sizePolicy);
        data_show_mode->setStyleSheet(QString::fromUtf8("background-color: rgb(30,30,30);"));
        horizontalLayout = new QHBoxLayout(data_show_mode);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        year_mode = new QWidget(data_show_mode);
        year_mode->setObjectName(QString::fromUtf8("year_mode"));
        sizePolicy.setHeightForWidth(year_mode->sizePolicy().hasHeightForWidth());
        year_mode->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(year_mode);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        last_year = new QLabel(year_mode);
        last_year->setObjectName(QString::fromUtf8("last_year"));
        last_year->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        last_year->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(last_year);

        cur_year = new QLabel(year_mode);
        cur_year->setObjectName(QString::fromUtf8("cur_year"));
        sizePolicy.setHeightForWidth(cur_year->sizePolicy().hasHeightForWidth());
        cur_year->setSizePolicy(sizePolicy);
        cur_year->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 255);\n"
"background-color: rgb(50, 50, 50);\n"
""));
        cur_year->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(cur_year);

        next_year = new QLabel(year_mode);
        next_year->setObjectName(QString::fromUtf8("next_year"));
        next_year->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        next_year->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(next_year);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);

        horizontalLayout->addWidget(year_mode);

        widget_2 = new QWidget(data_show_mode);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 150, 150);"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(2);
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        sizePolicy.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy);
        widget_4->setMinimumSize(QSize(1, 1));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);"));

        gridLayout_2->addWidget(widget_4, 0, 0, 1, 1);

        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        sizePolicy.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy);
        widget_7->setMinimumSize(QSize(1, 1));
        widget_7->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);"));

        gridLayout_2->addWidget(widget_7, 0, 1, 1, 1);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        widget_5->setMinimumSize(QSize(1, 1));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);"));

        gridLayout_2->addWidget(widget_5, 1, 0, 1, 1);

        widget_8 = new QWidget(widget_2);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        sizePolicy.setHeightForWidth(widget_8->sizePolicy().hasHeightForWidth());
        widget_8->setSizePolicy(sizePolicy);
        widget_8->setMinimumSize(QSize(1, 1));
        widget_8->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);"));

        gridLayout_2->addWidget(widget_8, 1, 1, 1, 1);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        sizePolicy.setHeightForWidth(widget_6->sizePolicy().hasHeightForWidth());
        widget_6->setSizePolicy(sizePolicy);
        widget_6->setMinimumSize(QSize(1, 1));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);"));

        gridLayout_2->addWidget(widget_6, 2, 0, 1, 1);

        widget_9 = new QWidget(widget_2);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        sizePolicy.setHeightForWidth(widget_9->sizePolicy().hasHeightForWidth());
        widget_9->setSizePolicy(sizePolicy);
        widget_9->setMinimumSize(QSize(1, 1));
        widget_9->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);"));

        gridLayout_2->addWidget(widget_9, 2, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setRowStretch(2, 1);
        gridLayout_2->setRowMinimumHeight(0, 1);
        gridLayout_2->setRowMinimumHeight(1, 1);
        gridLayout_2->setRowMinimumHeight(2, 1);

        horizontalLayout->addWidget(widget_2);

        month_mode = new QWidget(data_show_mode);
        month_mode->setObjectName(QString::fromUtf8("month_mode"));
        sizePolicy.setHeightForWidth(month_mode->sizePolicy().hasHeightForWidth());
        month_mode->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(month_mode);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        last_month = new QLabel(month_mode);
        last_month->setObjectName(QString::fromUtf8("last_month"));
        last_month->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        last_month->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(last_month);

        cur_month = new QLabel(month_mode);
        cur_month->setObjectName(QString::fromUtf8("cur_month"));
        sizePolicy.setHeightForWidth(cur_month->sizePolicy().hasHeightForWidth());
        cur_month->setSizePolicy(sizePolicy);
        cur_month->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);\n"
"color: rgb(0, 255, 255);\n"
""));
        cur_month->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(cur_month);

        next_month = new QLabel(month_mode);
        next_month->setObjectName(QString::fromUtf8("next_month"));
        next_month->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        next_month->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(next_month);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout->addWidget(month_mode);

        widget_3 = new QWidget(data_show_mode);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 150, 150);"));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(2);
        gridLayout_3->setVerticalSpacing(0);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_10 = new QWidget(widget_3);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setMinimumSize(QSize(1, 1));
        widget_10->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);"));

        gridLayout_3->addWidget(widget_10, 0, 0, 1, 1);

        widget_11 = new QWidget(widget_3);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setMinimumSize(QSize(1, 1));
        widget_11->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);"));

        gridLayout_3->addWidget(widget_11, 0, 1, 1, 1);

        widget_12 = new QWidget(widget_3);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        widget_12->setMinimumSize(QSize(1, 1));
        widget_12->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);"));

        gridLayout_3->addWidget(widget_12, 1, 0, 1, 1);

        widget_13 = new QWidget(widget_3);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        widget_13->setMinimumSize(QSize(1, 1));
        widget_13->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);"));

        gridLayout_3->addWidget(widget_13, 1, 1, 1, 1);

        widget_14 = new QWidget(widget_3);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        widget_14->setMinimumSize(QSize(1, 1));
        widget_14->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);"));

        gridLayout_3->addWidget(widget_14, 2, 0, 1, 1);

        widget_16 = new QWidget(widget_3);
        widget_16->setObjectName(QString::fromUtf8("widget_16"));
        widget_16->setMinimumSize(QSize(1, 1));
        widget_16->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);"));

        gridLayout_3->addWidget(widget_16, 2, 1, 1, 1);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 1);
        gridLayout_3->setRowStretch(2, 1);
        gridLayout_3->setRowMinimumHeight(0, 1);
        gridLayout_3->setRowMinimumHeight(1, 1);
        gridLayout_3->setRowMinimumHeight(2, 1);

        horizontalLayout->addWidget(widget_3);

        day_mode = new QWidget(data_show_mode);
        day_mode->setObjectName(QString::fromUtf8("day_mode"));
        sizePolicy.setHeightForWidth(day_mode->sizePolicy().hasHeightForWidth());
        day_mode->setSizePolicy(sizePolicy);
        day_mode_layout = new QVBoxLayout(day_mode);
        day_mode_layout->setSpacing(0);
        day_mode_layout->setContentsMargins(11, 11, 11, 11);
        day_mode_layout->setObjectName(QString::fromUtf8("day_mode_layout"));
        day_mode_layout->setContentsMargins(0, 0, 0, 0);
        last_day = new QLabel(day_mode);
        last_day->setObjectName(QString::fromUtf8("last_day"));
        last_day->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        last_day->setAlignment(Qt::AlignCenter);

        day_mode_layout->addWidget(last_day);

        cur_day = new QLabel(day_mode);
        cur_day->setObjectName(QString::fromUtf8("cur_day"));
        sizePolicy.setHeightForWidth(cur_day->sizePolicy().hasHeightForWidth());
        cur_day->setSizePolicy(sizePolicy);
        cur_day->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 255);\n"
"background-color: rgb(50, 50, 50);"));
        cur_day->setAlignment(Qt::AlignCenter);

        day_mode_layout->addWidget(cur_day);

        next_day = new QLabel(day_mode);
        next_day->setObjectName(QString::fromUtf8("next_day"));
        next_day->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        next_day->setAlignment(Qt::AlignCenter);

        day_mode_layout->addWidget(next_day);

        day_mode_layout->setStretch(0, 1);
        day_mode_layout->setStretch(1, 1);
        day_mode_layout->setStretch(2, 1);

        horizontalLayout->addWidget(day_mode);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 5);
        horizontalLayout->setStretch(3, 5);
        horizontalLayout->setStretch(4, 5);

        verticalLayout_3->addWidget(data_show_mode);

        verticalLayout_3->setStretch(0, 3);

        verticalLayout_6->addWidget(widget);

        btn_group = new QWidget(RXDateSelectPage);
        btn_group->setObjectName(QString::fromUtf8("btn_group"));
        sizePolicy.setHeightForWidth(btn_group->sizePolicy().hasHeightForWidth());
        btn_group->setSizePolicy(sizePolicy);
        btn_group->setStyleSheet(QString::fromUtf8("background-color: rgb(30,30,30);"));
        gridLayout = new QGridLayout(btn_group);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 9, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 9, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        date_confirm_btn = new QPushButton(btn_group);
        date_confirm_btn->setObjectName(QString::fromUtf8("date_confirm_btn"));
        sizePolicy.setHeightForWidth(date_confirm_btn->sizePolicy().hasHeightForWidth());
        date_confirm_btn->setSizePolicy(sizePolicy);
        date_confirm_btn->setMinimumSize(QSize(1, 1));
        date_confirm_btn->setMaximumSize(QSize(12312, 11111));
        date_confirm_btn->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(50, 50, 50);"));

        gridLayout->addWidget(date_confirm_btn, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(51, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        cancel_btn = new QPushButton(btn_group);
        cancel_btn->setObjectName(QString::fromUtf8("cancel_btn"));
        sizePolicy.setHeightForWidth(cancel_btn->sizePolicy().hasHeightForWidth());
        cancel_btn->setSizePolicy(sizePolicy);
        cancel_btn->setMinimumSize(QSize(1, 1));
        cancel_btn->setMaximumSize(QSize(16777215, 111111));
        cancel_btn->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(50, 50, 50);"));

        gridLayout->addWidget(cancel_btn, 1, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 3, 1, 1);

        gridLayout->setRowStretch(0, 2);
        gridLayout->setRowStretch(1, 4);
        gridLayout->setRowStretch(2, 2);
        gridLayout->setColumnStretch(0, 5);
        gridLayout->setColumnStretch(1, 7);
        gridLayout->setColumnStretch(2, 5);
        gridLayout->setColumnStretch(3, 7);
        gridLayout->setColumnStretch(4, 5);

        verticalLayout_6->addWidget(btn_group);

        verticalLayout_6->setStretch(0, 6);
        verticalLayout_6->setStretch(1, 2);

        retranslateUi(RXDateSelectPage);

        QMetaObject::connectSlotsByName(RXDateSelectPage);
    } // setupUi

    void retranslateUi(QWidget *RXDateSelectPage)
    {
        RXDateSelectPage->setWindowTitle(QCoreApplication::translate("RXDateSelectPage", "RXDateSelectPage", nullptr));
        last_year->setText(QCoreApplication::translate("RXDateSelectPage", "2018", nullptr));
        cur_year->setText(QCoreApplication::translate("RXDateSelectPage", "2019", nullptr));
        next_year->setText(QCoreApplication::translate("RXDateSelectPage", "2020", nullptr));
        last_month->setText(QCoreApplication::translate("RXDateSelectPage", "01", nullptr));
        cur_month->setText(QCoreApplication::translate("RXDateSelectPage", "02", nullptr));
        next_month->setText(QCoreApplication::translate("RXDateSelectPage", "03", nullptr));
        last_day->setText(QCoreApplication::translate("RXDateSelectPage", "01", nullptr));
        cur_day->setText(QCoreApplication::translate("RXDateSelectPage", "02", nullptr));
        next_day->setText(QCoreApplication::translate("RXDateSelectPage", "03", nullptr));
        date_confirm_btn->setText(QCoreApplication::translate("RXDateSelectPage", "\347\241\256\345\256\232", nullptr));
        cancel_btn->setText(QCoreApplication::translate("RXDateSelectPage", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RXDateSelectPage: public Ui_RXDateSelectPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RXDATESELECTPAGE_H

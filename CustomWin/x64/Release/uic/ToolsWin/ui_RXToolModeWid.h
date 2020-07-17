/********************************************************************************
** Form generated from reading UI file 'RXToolModeWid.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RXTOOLMODEWID_H
#define UI_RXTOOLMODEWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RXToolModeWid
{
public:
    QGridLayout *gridLayout_2;
    QWidget *main_wid;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *pic_lab;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *top_lab;
    QLabel *bottom_lab;

    void setupUi(QWidget *RXToolModeWid)
    {
        if (RXToolModeWid->objectName().isEmpty())
            RXToolModeWid->setObjectName(QStringLiteral("RXToolModeWid"));
        RXToolModeWid->resize(150, 64);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RXToolModeWid->sizePolicy().hasHeightForWidth());
        RXToolModeWid->setSizePolicy(sizePolicy);
        RXToolModeWid->setMinimumSize(QSize(1, 1));
        RXToolModeWid->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(RXToolModeWid);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        main_wid = new QWidget(RXToolModeWid);
        main_wid->setObjectName(QStringLiteral("main_wid"));
        main_wid->setStyleSheet(QLatin1String("#main_wid\n"
"{\n"
"border:1px solid;\n"
"border-color:rgb(216,216,216);\n"
"background-color: rgb(241, 241, 241);\n"
"}"));
        horizontalLayout = new QHBoxLayout(main_wid);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(11, 1, 1, 1);
        widget = new QWidget(main_wid);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(1, 1));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(241, 241, 241);"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 7, 0, 7);
        pic_lab = new QLabel(widget);
        pic_lab->setObjectName(QStringLiteral("pic_lab"));
        sizePolicy.setHeightForWidth(pic_lab->sizePolicy().hasHeightForWidth());
        pic_lab->setSizePolicy(sizePolicy);
        pic_lab->setMinimumSize(QSize(35, 35));
        pic_lab->setMaximumSize(QSize(35, 35));
        pic_lab->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(pic_lab, 0, 0, 1, 1);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(main_wid);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMinimumSize(QSize(1, 1));
        widget_2->setStyleSheet(QLatin1String("background-color: rgb(241, 241, 241);\n"
""));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 0, 10);
        top_lab = new QLabel(widget_2);
        top_lab->setObjectName(QStringLiteral("top_lab"));
        sizePolicy.setHeightForWidth(top_lab->sizePolicy().hasHeightForWidth());
        top_lab->setSizePolicy(sizePolicy);
        top_lab->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        top_lab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(top_lab);

        bottom_lab = new QLabel(widget_2);
        bottom_lab->setObjectName(QStringLiteral("bottom_lab"));
        sizePolicy.setHeightForWidth(bottom_lab->sizePolicy().hasHeightForWidth());
        bottom_lab->setSizePolicy(sizePolicy);
        bottom_lab->setMaximumSize(QSize(0, 0));
        bottom_lab->setStyleSheet(QString::fromUtf8("color: rgb(150, 150, 150);\n"
"font: 10px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        bottom_lab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(bottom_lab);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 1);

        horizontalLayout->addWidget(widget_2);

        horizontalLayout->setStretch(0, 20);
        horizontalLayout->setStretch(1, 30);

        gridLayout_2->addWidget(main_wid, 0, 0, 1, 1);


        retranslateUi(RXToolModeWid);

        QMetaObject::connectSlotsByName(RXToolModeWid);
    } // setupUi

    void retranslateUi(QWidget *RXToolModeWid)
    {
        RXToolModeWid->setWindowTitle(QApplication::translate("RXToolModeWid", "RXToolModeWid", Q_NULLPTR));
        pic_lab->setText(QString());
        top_lab->setText(QApplication::translate("RXToolModeWid", "\345\236\203\345\234\276\346\226\207\344\273\266\346\270\205\347\220\206", Q_NULLPTR));
        bottom_lab->setText(QApplication::translate("RXToolModeWid", "\350\212\202\347\234\201\347\275\221\347\233\230\347\251\272\351\227\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RXToolModeWid: public Ui_RXToolModeWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RXTOOLMODEWID_H

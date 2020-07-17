/********************************************************************************
** Form generated from reading UI file 'CustomSlider.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMSLIDER_H
#define UI_CUSTOMSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomSlider
{
public:
    QWidget *slider_wid;
    QGridLayout *gridLayout;
    QLabel *hander_lab;

    void setupUi(QWidget *CustomSlider)
    {
        if (CustomSlider->objectName().isEmpty())
            CustomSlider->setObjectName(QStringLiteral("CustomSlider"));
        CustomSlider->resize(213, 479);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CustomSlider->sizePolicy().hasHeightForWidth());
        CustomSlider->setSizePolicy(sizePolicy);
        slider_wid = new QWidget(CustomSlider);
        slider_wid->setObjectName(QStringLiteral("slider_wid"));
        slider_wid->setGeometry(QRect(60, 40, 71, 71));
        sizePolicy.setHeightForWidth(slider_wid->sizePolicy().hasHeightForWidth());
        slider_wid->setSizePolicy(sizePolicy);
        slider_wid->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(slider_wid);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        hander_lab = new QLabel(slider_wid);
        hander_lab->setObjectName(QStringLiteral("hander_lab"));
        sizePolicy.setHeightForWidth(hander_lab->sizePolicy().hasHeightForWidth());
        hander_lab->setSizePolicy(sizePolicy);
        hander_lab->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(hander_lab, 0, 0, 1, 1);


        retranslateUi(CustomSlider);

        QMetaObject::connectSlotsByName(CustomSlider);
    } // setupUi

    void retranslateUi(QWidget *CustomSlider)
    {
        CustomSlider->setWindowTitle(QApplication::translate("CustomSlider", "CustomSlider", Q_NULLPTR));
        hander_lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CustomSlider: public Ui_CustomSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMSLIDER_H

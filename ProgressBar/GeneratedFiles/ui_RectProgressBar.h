/********************************************************************************
** Form generated from reading UI file 'RectProgressBar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTPROGRESSBAR_H
#define UI_RECTPROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RectProgressBar
{
public:
    QGridLayout *rect_progressbar_layout;
    QWidget *progressbar_wid;

    void setupUi(QWidget *RectProgressBar)
    {
        if (RectProgressBar->objectName().isEmpty())
            RectProgressBar->setObjectName(QString::fromUtf8("RectProgressBar"));
        RectProgressBar->resize(202, 562);
        rect_progressbar_layout = new QGridLayout(RectProgressBar);
        rect_progressbar_layout->setSpacing(0);
        rect_progressbar_layout->setContentsMargins(11, 11, 11, 11);
        rect_progressbar_layout->setObjectName(QString::fromUtf8("rect_progressbar_layout"));
        rect_progressbar_layout->setContentsMargins(0, 0, 0, 0);
        progressbar_wid = new QWidget(RectProgressBar);
        progressbar_wid->setObjectName(QString::fromUtf8("progressbar_wid"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(progressbar_wid->sizePolicy().hasHeightForWidth());
        progressbar_wid->setSizePolicy(sizePolicy);
        progressbar_wid->setMinimumSize(QSize(1, 1));

        rect_progressbar_layout->addWidget(progressbar_wid, 0, 0, 1, 1);

        rect_progressbar_layout->setColumnStretch(0, 1);

        retranslateUi(RectProgressBar);

        QMetaObject::connectSlotsByName(RectProgressBar);
    } // setupUi

    void retranslateUi(QWidget *RectProgressBar)
    {
        RectProgressBar->setWindowTitle(QCoreApplication::translate("RectProgressBar", "RectProgressBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RectProgressBar: public Ui_RectProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTPROGRESSBAR_H

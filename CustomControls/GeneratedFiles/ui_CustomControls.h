/********************************************************************************
** Form generated from reading UI file 'CustomControls.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMCONTROLS_H
#define UI_CUSTOMCONTROLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CustomPanel.h"
#include "CustomSlider.h"
#include "CustomSliderStyleOne.h"
#include "CustomSliderStyleTwo.h"
#include "DashBoard.h"
#include "DoubleHandleSlider.h"
#include "HandleBarChart.h"
#include "HandleLineChart.h"
#include "HandlePieChart.h"
#include "HandleScatterChart.h"
#include "LinearProgressBar.h"
#include "NetSpeedPanel.h"
#include "RXTurnPan.h"
#include "RectProgressBar.h"
#include "RectWaveProgressBar.h"
#include "RingProgressBar.h"
#include "SemiCirclePanel.h"
#include "StripSlider.h"
#include "StripSliderStyleOne.h"
#include "StripSliderStyleTwo.h"
#include "TipSlider.h"
#include "WaveProgressBar.h"

QT_BEGIN_NAMESPACE

class Ui_CustomControlsClass
{
public:
    QGridLayout *gridLayout_2;
    QWidget *blank_wid_left;
    QVBoxLayout *verticalLayout_2;
    QWidget *left_mark_wid;
    QSpacerItem *verticalSpacer_2;
    QWidget *blank_wid_right;
    QVBoxLayout *verticalLayout_3;
    QWidget *right_mark_wid;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_wid;
    QGridLayout *gridLayout_3;
    QTabWidget *main_tab_wid;
    QWidget *progressbar_tab;
    QGridLayout *gridLayout_8;
    DashBoard *dash_board;
    RingProgressBar *ring_progressbar;
    LinearProgressBar *linear_progressbar;
    QWidget *widget_23;
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_6;
    QSlider *progress_slider;
    WaveProgressBar *wave_progressbar;
    RectProgressBar *rect_progressbar;
    RectWaveProgressBar *rect_wave_progressbar;
    QWidget *sliderbar_tab;
    QGridLayout *gridLayout_5;
    CustomSlider *custom_slider;
    DoubleHandleSlider *double_handle_slider;
    TipSlider *tip_slider;
    StripSlider *strip_slider;
    CustomSliderStyleOne *custom_slider_style_one;
    CustomSliderStyleTwo *custom_slider_style_two;
    StripSliderStyleOne *strip_slider_style_one;
    StripSliderStyleTwo *strip_slider_style_two;
    QWidget *panel_tab;
    QGridLayout *gridLayout_11;
    CustomPanel *custom_panel;
    NetSpeedPanel *netspeed_panel;
    QSlider *panel_slider;
    SemiCirclePanel *semicircle_panel;
    QWidget *qwt_tab;
    QGridLayout *gridLayout_9;
    QWidget *set_wid;
    QWidget *chart_wid;
    QGridLayout *gridLayout_10;
    HandleLineChart *handle_line_chart;
    HandlePieChart *handle_pie_chart;
    HandleScatterChart *handle_scatter_chart;
    HandleBarChart *handle_bar_chart;
    QWidget *animation_tab;
    QGridLayout *gridLayout_7;
    RXTurnPan *turn_pan;
    QWidget *widget_3;
    QWidget *widget_9;
    QWidget *widget_10;
    QWidget *widget_11;
    QWidget *widget_12;
    QWidget *otherbutton_tab;
    QGridLayout *gridLayout_12;
    QWidget *btns_wid;
    QGridLayout *gridLayout_13;
    QWidget *btn_controller_1_wid;
    QWidget *vessal_widget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *vessel_left_blank_wid;
    QPushButton *test_drop_menu_btn;
    QWidget *vessel_right_blank_wid;
    QWidget *btn_controller_2_wid;
    QGridLayout *gridLayout_14;
    QWidget *btn_controller_3_wid;
    QWidget *btn_controller_4_wid;
    QWidget *btn_controller_5_wid;
    QWidget *btn_controller_6_wid;
    QWidget *btn_controller_7_wid;
    QWidget *btn_controller_8_wid;
    QWidget *btn_controller_9_wid;
    QWidget *btn_controller_10_wid;
    QWidget *btn_controller_11_wid;
    QWidget *btn_controller_12_wid;
    QWidget *btn_controller_13_wid;
    QWidget *btn_controller_14_wid;
    QWidget *btn_controller_15_wid;
    QWidget *btn_controller_16_wid;
    QWidget *custom_win_tab;
    QGridLayout *gridLayout_15;
    QWidget *wid_customwin_0;
    QWidget *wid_customwin_1;
    QWidget *wid_customwin_2;
    QWidget *wid_customwin_3;
    QWidget *blank_tab;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QWidget *navigation_wid;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QRadioButton *sliderbar_btn;
    QRadioButton *panel_btn;
    QRadioButton *qwt_btn;
    QRadioButton *animation_btn;
    QRadioButton *otherbutton_btn;
    QRadioButton *progressbar_btn;
    QRadioButton *custom_win_btn;

    void setupUi(QWidget *CustomControlsClass)
    {
        if (CustomControlsClass->objectName().isEmpty())
            CustomControlsClass->setObjectName(QStringLiteral("CustomControlsClass"));
        CustomControlsClass->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CustomControlsClass->sizePolicy().hasHeightForWidth());
        CustomControlsClass->setSizePolicy(sizePolicy);
        CustomControlsClass->setMinimumSize(QSize(800, 600));
        CustomControlsClass->setMaximumSize(QSize(800, 600));
        CustomControlsClass->setSizeIncrement(QSize(800, 600));
        gridLayout_2 = new QGridLayout(CustomControlsClass);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        blank_wid_left = new QWidget(CustomControlsClass);
        blank_wid_left->setObjectName(QStringLiteral("blank_wid_left"));
        sizePolicy.setHeightForWidth(blank_wid_left->sizePolicy().hasHeightForWidth());
        blank_wid_left->setSizePolicy(sizePolicy);
        blank_wid_left->setStyleSheet(QLatin1String("#blank_wid_left\n"
"{\n"
"background-color: rgb(40, 43, 51);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(blank_wid_left);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        left_mark_wid = new QWidget(blank_wid_left);
        left_mark_wid->setObjectName(QStringLiteral("left_mark_wid"));
        sizePolicy.setHeightForWidth(left_mark_wid->sizePolicy().hasHeightForWidth());
        left_mark_wid->setSizePolicy(sizePolicy);
        left_mark_wid->setStyleSheet(QLatin1String("#left_mark_wid\n"
"{\n"
"background-color: rgb(40, 43, 51);\n"
"\n"
"border:0px;\n"
"}"));

        verticalLayout_2->addWidget(left_mark_wid);

        verticalSpacer_2 = new QSpacerItem(1, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalLayout_2->setStretch(0, 7);
        verticalLayout_2->setStretch(1, 9);

        gridLayout_2->addWidget(blank_wid_left, 0, 0, 1, 1);

        blank_wid_right = new QWidget(CustomControlsClass);
        blank_wid_right->setObjectName(QStringLiteral("blank_wid_right"));
        blank_wid_right->setStyleSheet(QLatin1String("#blank_wid_right\n"
"{\n"
"background-color: rgb(40, 43, 51);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(blank_wid_right);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        right_mark_wid = new QWidget(blank_wid_right);
        right_mark_wid->setObjectName(QStringLiteral("right_mark_wid"));
        sizePolicy.setHeightForWidth(right_mark_wid->sizePolicy().hasHeightForWidth());
        right_mark_wid->setSizePolicy(sizePolicy);
        right_mark_wid->setStyleSheet(QLatin1String("#right_mark_wid\n"
"{\n"
"\n"
"	background-color: rgb(40, 43, 51);\n"
"\n"
"border:0px;\n"
"}"));

        verticalLayout_3->addWidget(right_mark_wid);

        verticalSpacer_3 = new QSpacerItem(1, 372, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        verticalLayout_3->setStretch(0, 7);
        verticalLayout_3->setStretch(1, 9);

        gridLayout_2->addWidget(blank_wid_right, 0, 2, 1, 1);

        tab_wid = new QWidget(CustomControlsClass);
        tab_wid->setObjectName(QStringLiteral("tab_wid"));
        sizePolicy.setHeightForWidth(tab_wid->sizePolicy().hasHeightForWidth());
        tab_wid->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(tab_wid);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        main_tab_wid = new QTabWidget(tab_wid);
        main_tab_wid->setObjectName(QStringLiteral("main_tab_wid"));
        main_tab_wid->setStyleSheet(QLatin1String("\n"
"QTabWidget::pane \n"
"{ \n"
"border:0px solid;\n"
"}\n"
"\n"
""));
        progressbar_tab = new QWidget();
        progressbar_tab->setObjectName(QStringLiteral("progressbar_tab"));
        progressbar_tab->setStyleSheet(QLatin1String("\n"
"#progressbar_tab{\n"
"	\n"
"	border-image: url(:/CustomControls/picture/background.png);\n"
"}\n"
"\n"
"\n"
""));
        gridLayout_8 = new QGridLayout(progressbar_tab);
        gridLayout_8->setSpacing(5);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(5, 5, 5, 5);
        dash_board = new DashBoard(progressbar_tab);
        dash_board->setObjectName(QStringLiteral("dash_board"));
        sizePolicy.setHeightForWidth(dash_board->sizePolicy().hasHeightForWidth());
        dash_board->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(dash_board, 0, 0, 1, 1);

        ring_progressbar = new RingProgressBar(progressbar_tab);
        ring_progressbar->setObjectName(QStringLiteral("ring_progressbar"));
        sizePolicy.setHeightForWidth(ring_progressbar->sizePolicy().hasHeightForWidth());
        ring_progressbar->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(ring_progressbar, 0, 1, 1, 1);

        linear_progressbar = new LinearProgressBar(progressbar_tab);
        linear_progressbar->setObjectName(QStringLiteral("linear_progressbar"));
        sizePolicy.setHeightForWidth(linear_progressbar->sizePolicy().hasHeightForWidth());
        linear_progressbar->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(linear_progressbar, 0, 2, 1, 1);

        widget_23 = new QWidget(progressbar_tab);
        widget_23->setObjectName(QStringLiteral("widget_23"));
        sizePolicy.setHeightForWidth(widget_23->sizePolicy().hasHeightForWidth());
        widget_23->setSizePolicy(sizePolicy);
        widget_23->setStyleSheet(QStringLiteral(""));
        gridLayout_6 = new QGridLayout(widget_23);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_7 = new QSpacerItem(20, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_7, 2, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_6, 0, 0, 1, 1);

        progress_slider = new QSlider(widget_23);
        progress_slider->setObjectName(QStringLiteral("progress_slider"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progress_slider->sizePolicy().hasHeightForWidth());
        progress_slider->setSizePolicy(sizePolicy1);
        progress_slider->setStyleSheet(QStringLiteral(""));
        progress_slider->setMaximum(100);
        progress_slider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(progress_slider, 1, 0, 1, 1);

        gridLayout_6->setRowStretch(0, 10);
        gridLayout_6->setColumnStretch(0, 1);

        gridLayout_8->addWidget(widget_23, 1, 0, 1, 3);

        wave_progressbar = new WaveProgressBar(progressbar_tab);
        wave_progressbar->setObjectName(QStringLiteral("wave_progressbar"));
        sizePolicy.setHeightForWidth(wave_progressbar->sizePolicy().hasHeightForWidth());
        wave_progressbar->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(wave_progressbar, 2, 0, 1, 1);

        rect_progressbar = new RectProgressBar(progressbar_tab);
        rect_progressbar->setObjectName(QStringLiteral("rect_progressbar"));
        sizePolicy.setHeightForWidth(rect_progressbar->sizePolicy().hasHeightForWidth());
        rect_progressbar->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(rect_progressbar, 2, 1, 1, 1);

        rect_wave_progressbar = new RectWaveProgressBar(progressbar_tab);
        rect_wave_progressbar->setObjectName(QStringLiteral("rect_wave_progressbar"));
        sizePolicy.setHeightForWidth(rect_wave_progressbar->sizePolicy().hasHeightForWidth());
        rect_wave_progressbar->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(rect_wave_progressbar, 2, 2, 1, 1);

        gridLayout_8->setRowStretch(0, 10);
        gridLayout_8->setRowStretch(1, 5);
        gridLayout_8->setRowStretch(2, 10);
        gridLayout_8->setColumnStretch(0, 10);
        gridLayout_8->setColumnStretch(1, 10);
        gridLayout_8->setColumnStretch(2, 10);
        main_tab_wid->addTab(progressbar_tab, QString());
        sliderbar_tab = new QWidget();
        sliderbar_tab->setObjectName(QStringLiteral("sliderbar_tab"));
        sliderbar_tab->setStyleSheet(QLatin1String("#sliderbar_tab\n"
"{\n"
"\n"
"\n"
"	border-image: url(:/CustomControls/picture/background.png);\n"
"\n"
"\n"
"\n"
"\n"
"}"));
        gridLayout_5 = new QGridLayout(sliderbar_tab);
        gridLayout_5->setSpacing(5);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(5, 5, 5, 5);
        custom_slider = new CustomSlider(sliderbar_tab);
        custom_slider->setObjectName(QStringLiteral("custom_slider"));

        gridLayout_5->addWidget(custom_slider, 0, 0, 1, 1);

        double_handle_slider = new DoubleHandleSlider(sliderbar_tab);
        double_handle_slider->setObjectName(QStringLiteral("double_handle_slider"));

        gridLayout_5->addWidget(double_handle_slider, 0, 1, 1, 1);

        tip_slider = new TipSlider(sliderbar_tab);
        tip_slider->setObjectName(QStringLiteral("tip_slider"));

        gridLayout_5->addWidget(tip_slider, 0, 2, 1, 1);

        strip_slider = new StripSlider(sliderbar_tab);
        strip_slider->setObjectName(QStringLiteral("strip_slider"));

        gridLayout_5->addWidget(strip_slider, 0, 3, 1, 1);

        custom_slider_style_one = new CustomSliderStyleOne(sliderbar_tab);
        custom_slider_style_one->setObjectName(QStringLiteral("custom_slider_style_one"));

        gridLayout_5->addWidget(custom_slider_style_one, 1, 0, 1, 1);

        custom_slider_style_two = new CustomSliderStyleTwo(sliderbar_tab);
        custom_slider_style_two->setObjectName(QStringLiteral("custom_slider_style_two"));

        gridLayout_5->addWidget(custom_slider_style_two, 1, 1, 1, 1);

        strip_slider_style_one = new StripSliderStyleOne(sliderbar_tab);
        strip_slider_style_one->setObjectName(QStringLiteral("strip_slider_style_one"));

        gridLayout_5->addWidget(strip_slider_style_one, 1, 2, 1, 1);

        strip_slider_style_two = new StripSliderStyleTwo(sliderbar_tab);
        strip_slider_style_two->setObjectName(QStringLiteral("strip_slider_style_two"));

        gridLayout_5->addWidget(strip_slider_style_two, 1, 3, 1, 1);

        gridLayout_5->setRowStretch(0, 10);
        gridLayout_5->setRowStretch(1, 10);
        gridLayout_5->setColumnStretch(0, 10);
        gridLayout_5->setColumnStretch(1, 10);
        gridLayout_5->setColumnStretch(2, 10);
        gridLayout_5->setColumnStretch(3, 10);
        main_tab_wid->addTab(sliderbar_tab, QString());
        panel_tab = new QWidget();
        panel_tab->setObjectName(QStringLiteral("panel_tab"));
        panel_tab->setStyleSheet(QLatin1String("#panel_tab\n"
"{\n"
"border-image: url(:/CustomControls/picture/background.png);\n"
"\n"
"}\n"
""));
        gridLayout_11 = new QGridLayout(panel_tab);
        gridLayout_11->setSpacing(2);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(2, 2, 2, 2);
        custom_panel = new CustomPanel(panel_tab);
        custom_panel->setObjectName(QStringLiteral("custom_panel"));

        gridLayout_11->addWidget(custom_panel, 0, 0, 1, 1);

        netspeed_panel = new NetSpeedPanel(panel_tab);
        netspeed_panel->setObjectName(QStringLiteral("netspeed_panel"));

        gridLayout_11->addWidget(netspeed_panel, 0, 1, 1, 1);

        panel_slider = new QSlider(panel_tab);
        panel_slider->setObjectName(QStringLiteral("panel_slider"));
        sizePolicy.setHeightForWidth(panel_slider->sizePolicy().hasHeightForWidth());
        panel_slider->setSizePolicy(sizePolicy);
        panel_slider->setMaximum(100);
        panel_slider->setOrientation(Qt::Horizontal);

        gridLayout_11->addWidget(panel_slider, 1, 0, 1, 2);

        semicircle_panel = new SemiCirclePanel(panel_tab);
        semicircle_panel->setObjectName(QStringLiteral("semicircle_panel"));
        sizePolicy.setHeightForWidth(semicircle_panel->sizePolicy().hasHeightForWidth());
        semicircle_panel->setSizePolicy(sizePolicy);
        semicircle_panel->setStyleSheet(QStringLiteral(""));

        gridLayout_11->addWidget(semicircle_panel, 2, 0, 1, 2);

        gridLayout_11->setRowStretch(0, 20);
        gridLayout_11->setRowStretch(1, 1);
        gridLayout_11->setRowStretch(2, 20);
        main_tab_wid->addTab(panel_tab, QString());
        qwt_tab = new QWidget();
        qwt_tab->setObjectName(QStringLiteral("qwt_tab"));
        gridLayout_9 = new QGridLayout(qwt_tab);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        set_wid = new QWidget(qwt_tab);
        set_wid->setObjectName(QStringLiteral("set_wid"));
        set_wid->setStyleSheet(QStringLiteral("background-color: rgb(64, 67, 74);"));

        gridLayout_9->addWidget(set_wid, 0, 0, 1, 1);

        chart_wid = new QWidget(qwt_tab);
        chart_wid->setObjectName(QStringLiteral("chart_wid"));
        chart_wid->setStyleSheet(QStringLiteral("background-color: rgb(64, 67, 74);"));
        gridLayout_10 = new QGridLayout(chart_wid);
        gridLayout_10->setSpacing(15);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(15, 15, 15, 15);
        handle_line_chart = new HandleLineChart(chart_wid);
        handle_line_chart->setObjectName(QStringLiteral("handle_line_chart"));
        sizePolicy.setHeightForWidth(handle_line_chart->sizePolicy().hasHeightForWidth());
        handle_line_chart->setSizePolicy(sizePolicy);

        gridLayout_10->addWidget(handle_line_chart, 0, 0, 1, 1);

        handle_pie_chart = new HandlePieChart(chart_wid);
        handle_pie_chart->setObjectName(QStringLiteral("handle_pie_chart"));
        sizePolicy.setHeightForWidth(handle_pie_chart->sizePolicy().hasHeightForWidth());
        handle_pie_chart->setSizePolicy(sizePolicy);

        gridLayout_10->addWidget(handle_pie_chart, 0, 1, 1, 1);

        handle_scatter_chart = new HandleScatterChart(chart_wid);
        handle_scatter_chart->setObjectName(QStringLiteral("handle_scatter_chart"));
        sizePolicy.setHeightForWidth(handle_scatter_chart->sizePolicy().hasHeightForWidth());
        handle_scatter_chart->setSizePolicy(sizePolicy);

        gridLayout_10->addWidget(handle_scatter_chart, 1, 0, 1, 1);

        handle_bar_chart = new HandleBarChart(chart_wid);
        handle_bar_chart->setObjectName(QStringLiteral("handle_bar_chart"));
        sizePolicy.setHeightForWidth(handle_bar_chart->sizePolicy().hasHeightForWidth());
        handle_bar_chart->setSizePolicy(sizePolicy);

        gridLayout_10->addWidget(handle_bar_chart, 1, 1, 1, 1);

        gridLayout_10->setRowStretch(0, 1);
        gridLayout_10->setRowStretch(1, 1);
        gridLayout_10->setColumnStretch(0, 1);
        gridLayout_10->setColumnStretch(1, 1);

        gridLayout_9->addWidget(chart_wid, 1, 0, 1, 1);

        gridLayout_9->setRowStretch(0, 1);
        gridLayout_9->setRowStretch(1, 50);
        main_tab_wid->addTab(qwt_tab, QString());
        animation_tab = new QWidget();
        animation_tab->setObjectName(QStringLiteral("animation_tab"));
        animation_tab->setStyleSheet(QLatin1String("\n"
"#animation_tab{\n"
"	\n"
"	border-image: url(:/CustomControls/picture/background.png);\n"
"}\n"
"\n"
"\n"
""));
        gridLayout_7 = new QGridLayout(animation_tab);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        turn_pan = new RXTurnPan(animation_tab);
        turn_pan->setObjectName(QStringLiteral("turn_pan"));

        gridLayout_7->addWidget(turn_pan, 0, 0, 2, 2);

        widget_3 = new QWidget(animation_tab);
        widget_3->setObjectName(QStringLiteral("widget_3"));

        gridLayout_7->addWidget(widget_3, 0, 2, 1, 1);

        widget_9 = new QWidget(animation_tab);
        widget_9->setObjectName(QStringLiteral("widget_9"));

        gridLayout_7->addWidget(widget_9, 1, 2, 1, 1);

        widget_10 = new QWidget(animation_tab);
        widget_10->setObjectName(QStringLiteral("widget_10"));

        gridLayout_7->addWidget(widget_10, 2, 0, 1, 1);

        widget_11 = new QWidget(animation_tab);
        widget_11->setObjectName(QStringLiteral("widget_11"));

        gridLayout_7->addWidget(widget_11, 2, 1, 1, 1);

        widget_12 = new QWidget(animation_tab);
        widget_12->setObjectName(QStringLiteral("widget_12"));

        gridLayout_7->addWidget(widget_12, 2, 2, 1, 1);

        main_tab_wid->addTab(animation_tab, QString());
        otherbutton_tab = new QWidget();
        otherbutton_tab->setObjectName(QStringLiteral("otherbutton_tab"));
        otherbutton_tab->setStyleSheet(QStringLiteral(""));
        gridLayout_12 = new QGridLayout(otherbutton_tab);
        gridLayout_12->setSpacing(0);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        btns_wid = new QWidget(otherbutton_tab);
        btns_wid->setObjectName(QStringLiteral("btns_wid"));
        btns_wid->setStyleSheet(QLatin1String("\n"
"#btns_wid\n"
"{\n"
"\n"
"border-image: url(:/CustomControls/picture/background.png);\n"
"\n"
"\n"
"}\n"
"\n"
"\n"
""));
        gridLayout_13 = new QGridLayout(btns_wid);
        gridLayout_13->setSpacing(1);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        btn_controller_1_wid = new QWidget(btns_wid);
        btn_controller_1_wid->setObjectName(QStringLiteral("btn_controller_1_wid"));
        vessal_widget = new QWidget(btn_controller_1_wid);
        vessal_widget->setObjectName(QStringLiteral("vessal_widget"));
        vessal_widget->setGeometry(QRect(10, 40, 131, 41));
        sizePolicy.setHeightForWidth(vessal_widget->sizePolicy().hasHeightForWidth());
        vessal_widget->setSizePolicy(sizePolicy);
        vessal_widget->setMinimumSize(QSize(1, 1));
        vessal_widget->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(vessal_widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        vessel_left_blank_wid = new QWidget(vessal_widget);
        vessel_left_blank_wid->setObjectName(QStringLiteral("vessel_left_blank_wid"));
        vessel_left_blank_wid->setMinimumSize(QSize(1, 0));
        vessel_left_blank_wid->setMaximumSize(QSize(100000, 16777215));
        vessel_left_blank_wid->setStyleSheet(QStringLiteral("border-image: url(:/CustomControls/picture/btns_pic/left_check.png);"));

        horizontalLayout_3->addWidget(vessel_left_blank_wid);

        test_drop_menu_btn = new QPushButton(vessal_widget);
        test_drop_menu_btn->setObjectName(QStringLiteral("test_drop_menu_btn"));
        sizePolicy.setHeightForWidth(test_drop_menu_btn->sizePolicy().hasHeightForWidth());
        test_drop_menu_btn->setSizePolicy(sizePolicy);
        test_drop_menu_btn->setMinimumSize(QSize(1, 1));
        test_drop_menu_btn->setMaximumSize(QSize(10000, 16777215));
        test_drop_menu_btn->setFocusPolicy(Qt::NoFocus);
        test_drop_menu_btn->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color:rgb(255, 255, 255);\n"
"border-image: url(:/CustomControls/picture/btns_pic/mid_check.png);\n"
"}  \n"
"              \n"
"\n"
""));
        test_drop_menu_btn->setCheckable(true);
        test_drop_menu_btn->setChecked(true);

        horizontalLayout_3->addWidget(test_drop_menu_btn);

        vessel_right_blank_wid = new QWidget(vessal_widget);
        vessel_right_blank_wid->setObjectName(QStringLiteral("vessel_right_blank_wid"));
        vessel_right_blank_wid->setMinimumSize(QSize(1, 0));
        vessel_right_blank_wid->setMaximumSize(QSize(10000, 16777215));
        vessel_right_blank_wid->setStyleSheet(QStringLiteral("border-image: url(:/CustomControls/picture/btns_pic/right_check.png);"));

        horizontalLayout_3->addWidget(vessel_right_blank_wid);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 18);
        horizontalLayout_3->setStretch(2, 2);

        gridLayout_13->addWidget(btn_controller_1_wid, 0, 0, 1, 1);

        btn_controller_2_wid = new QWidget(btns_wid);
        btn_controller_2_wid->setObjectName(QStringLiteral("btn_controller_2_wid"));
        gridLayout_14 = new QGridLayout(btn_controller_2_wid);
        gridLayout_14->setSpacing(0);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);

        gridLayout_13->addWidget(btn_controller_2_wid, 0, 1, 1, 1);

        btn_controller_3_wid = new QWidget(btns_wid);
        btn_controller_3_wid->setObjectName(QStringLiteral("btn_controller_3_wid"));

        gridLayout_13->addWidget(btn_controller_3_wid, 0, 2, 1, 1);

        btn_controller_4_wid = new QWidget(btns_wid);
        btn_controller_4_wid->setObjectName(QStringLiteral("btn_controller_4_wid"));

        gridLayout_13->addWidget(btn_controller_4_wid, 0, 3, 1, 1);

        btn_controller_5_wid = new QWidget(btns_wid);
        btn_controller_5_wid->setObjectName(QStringLiteral("btn_controller_5_wid"));

        gridLayout_13->addWidget(btn_controller_5_wid, 1, 0, 1, 1);

        btn_controller_6_wid = new QWidget(btns_wid);
        btn_controller_6_wid->setObjectName(QStringLiteral("btn_controller_6_wid"));

        gridLayout_13->addWidget(btn_controller_6_wid, 1, 1, 1, 1);

        btn_controller_7_wid = new QWidget(btns_wid);
        btn_controller_7_wid->setObjectName(QStringLiteral("btn_controller_7_wid"));

        gridLayout_13->addWidget(btn_controller_7_wid, 1, 2, 1, 1);

        btn_controller_8_wid = new QWidget(btns_wid);
        btn_controller_8_wid->setObjectName(QStringLiteral("btn_controller_8_wid"));

        gridLayout_13->addWidget(btn_controller_8_wid, 1, 3, 1, 1);

        btn_controller_9_wid = new QWidget(btns_wid);
        btn_controller_9_wid->setObjectName(QStringLiteral("btn_controller_9_wid"));

        gridLayout_13->addWidget(btn_controller_9_wid, 2, 0, 1, 1);

        btn_controller_10_wid = new QWidget(btns_wid);
        btn_controller_10_wid->setObjectName(QStringLiteral("btn_controller_10_wid"));

        gridLayout_13->addWidget(btn_controller_10_wid, 2, 1, 1, 1);

        btn_controller_11_wid = new QWidget(btns_wid);
        btn_controller_11_wid->setObjectName(QStringLiteral("btn_controller_11_wid"));

        gridLayout_13->addWidget(btn_controller_11_wid, 2, 2, 1, 1);

        btn_controller_12_wid = new QWidget(btns_wid);
        btn_controller_12_wid->setObjectName(QStringLiteral("btn_controller_12_wid"));

        gridLayout_13->addWidget(btn_controller_12_wid, 2, 3, 1, 1);

        btn_controller_13_wid = new QWidget(btns_wid);
        btn_controller_13_wid->setObjectName(QStringLiteral("btn_controller_13_wid"));

        gridLayout_13->addWidget(btn_controller_13_wid, 3, 0, 1, 1);

        btn_controller_14_wid = new QWidget(btns_wid);
        btn_controller_14_wid->setObjectName(QStringLiteral("btn_controller_14_wid"));

        gridLayout_13->addWidget(btn_controller_14_wid, 3, 1, 1, 1);

        btn_controller_15_wid = new QWidget(btns_wid);
        btn_controller_15_wid->setObjectName(QStringLiteral("btn_controller_15_wid"));

        gridLayout_13->addWidget(btn_controller_15_wid, 3, 2, 1, 1);

        btn_controller_16_wid = new QWidget(btns_wid);
        btn_controller_16_wid->setObjectName(QStringLiteral("btn_controller_16_wid"));

        gridLayout_13->addWidget(btn_controller_16_wid, 3, 3, 1, 1);

        gridLayout_13->setRowStretch(0, 10);
        gridLayout_13->setRowStretch(1, 10);
        gridLayout_13->setRowStretch(2, 10);
        gridLayout_13->setRowStretch(3, 10);
        gridLayout_13->setColumnStretch(0, 10);
        gridLayout_13->setColumnStretch(1, 10);
        gridLayout_13->setColumnStretch(2, 10);
        gridLayout_13->setColumnStretch(3, 10);

        gridLayout_12->addWidget(btns_wid, 0, 0, 1, 1);

        main_tab_wid->addTab(otherbutton_tab, QString());
        custom_win_tab = new QWidget();
        custom_win_tab->setObjectName(QStringLiteral("custom_win_tab"));
        custom_win_tab->setStyleSheet(QLatin1String("#custom_win_tab\n"
"{\n"
"	\n"
"	border-image: url(:/CustomControls/picture/background.png);\n"
"}\n"
"\n"
"\n"
""));
        gridLayout_15 = new QGridLayout(custom_win_tab);
        gridLayout_15->setSpacing(0);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        wid_customwin_0 = new QWidget(custom_win_tab);
        wid_customwin_0->setObjectName(QStringLiteral("wid_customwin_0"));
        wid_customwin_0->setStyleSheet(QLatin1String("#wid_customwin_0\n"
"{\n"
"border:0px solid;\n"
"}"));

        gridLayout_15->addWidget(wid_customwin_0, 0, 0, 1, 1);

        wid_customwin_1 = new QWidget(custom_win_tab);
        wid_customwin_1->setObjectName(QStringLiteral("wid_customwin_1"));

        gridLayout_15->addWidget(wid_customwin_1, 0, 1, 1, 1);

        wid_customwin_2 = new QWidget(custom_win_tab);
        wid_customwin_2->setObjectName(QStringLiteral("wid_customwin_2"));
        wid_customwin_2->setStyleSheet(QLatin1String("#wid_customwin_2\n"
"{\n"
"border:0px solid;\n"
"}"));

        gridLayout_15->addWidget(wid_customwin_2, 1, 0, 1, 1);

        wid_customwin_3 = new QWidget(custom_win_tab);
        wid_customwin_3->setObjectName(QStringLiteral("wid_customwin_3"));

        gridLayout_15->addWidget(wid_customwin_3, 1, 1, 1, 1);

        gridLayout_15->setRowStretch(0, 10);
        gridLayout_15->setRowStretch(1, 7);
        gridLayout_15->setColumnStretch(0, 10);
        gridLayout_15->setColumnStretch(1, 3);
        main_tab_wid->addTab(custom_win_tab, QString());
        blank_tab = new QWidget();
        blank_tab->setObjectName(QStringLiteral("blank_tab"));
        blank_tab->setStyleSheet(QLatin1String("\n"
"#blank_tab\n"
"{\n"
"border:0px;\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(180, 180, 180, 255), stop:1 rgba(80, 80, 80, 255));\n"
"}\n"
"\n"
""));
        gridLayout_4 = new QGridLayout(blank_tab);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 141, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(161, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 0, 1, 1);

        label = new QLabel(blank_tab);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 60pt \"\345\256\213\344\275\223\";\n"
"color: rgb(231, 231, 231);\n"
"padding-bottom:50px;"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(161, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 141, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_5, 2, 1, 1, 1);

        gridLayout_4->setRowStretch(0, 10);
        gridLayout_4->setRowStretch(1, 20);
        gridLayout_4->setRowStretch(2, 10);
        gridLayout_4->setColumnStretch(0, 10);
        gridLayout_4->setColumnStretch(1, 20);
        gridLayout_4->setColumnStretch(2, 10);
        main_tab_wid->addTab(blank_tab, QString());

        gridLayout_3->addWidget(main_tab_wid, 0, 0, 1, 1);


        gridLayout_2->addWidget(tab_wid, 0, 3, 1, 1);

        navigation_wid = new QWidget(CustomControlsClass);
        navigation_wid->setObjectName(QStringLiteral("navigation_wid"));
        sizePolicy.setHeightForWidth(navigation_wid->sizePolicy().hasHeightForWidth());
        navigation_wid->setSizePolicy(sizePolicy);
        navigation_wid->setStyleSheet(QLatin1String("	\n"
"#navigation_wid\n"
"{\n"
"background-color: rgb(40, 43, 51);\n"
"}"));
        gridLayout = new QGridLayout(navigation_wid);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 1);

        sliderbar_btn = new QRadioButton(navigation_wid);
        sliderbar_btn->setObjectName(QStringLiteral("sliderbar_btn"));
        sizePolicy.setHeightForWidth(sliderbar_btn->sizePolicy().hasHeightForWidth());
        sliderbar_btn->setSizePolicy(sizePolicy);
        sliderbar_btn->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"font: 14px\"\345\256\213\344\275\223\"\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"   width: 0px;\n"
"   height:0px;\n"
" border:0px;\n"
"}\n"
"\n"
"QRadioButton::unchecked\n"
"{\n"
"	color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"QRadioButton::unchecked:hover\n"
" {\n"
"    color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"QRadioButton::checked\n"
"{	\n"
"   color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
""));

        gridLayout->addWidget(sliderbar_btn, 1, 0, 1, 1);

        panel_btn = new QRadioButton(navigation_wid);
        panel_btn->setObjectName(QStringLiteral("panel_btn"));
        sizePolicy.setHeightForWidth(panel_btn->sizePolicy().hasHeightForWidth());
        panel_btn->setSizePolicy(sizePolicy);
        panel_btn->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"font: 14px\"\345\256\213\344\275\223\"\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"   width: 0px;\n"
"   height:0px;\n"
" border:0px;\n"
"}\n"
"\n"
"QRadioButton::unchecked\n"
"{\n"
"	color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"QRadioButton::unchecked:hover\n"
" {\n"
"    color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"QRadioButton::checked\n"
"{	\n"
"   color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
""));

        gridLayout->addWidget(panel_btn, 2, 0, 1, 1);

        qwt_btn = new QRadioButton(navigation_wid);
        qwt_btn->setObjectName(QStringLiteral("qwt_btn"));
        sizePolicy.setHeightForWidth(qwt_btn->sizePolicy().hasHeightForWidth());
        qwt_btn->setSizePolicy(sizePolicy);
        qwt_btn->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"font: 14px\"\345\256\213\344\275\223\"\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"   width: 0px;\n"
"   height:0px;\n"
" border:0px;\n"
"}\n"
"\n"
"QRadioButton::unchecked\n"
"{\n"
"	color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"QRadioButton::unchecked:hover\n"
" {\n"
"    color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"QRadioButton::checked\n"
"{	\n"
"   color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}"));

        gridLayout->addWidget(qwt_btn, 3, 0, 1, 1);

        animation_btn = new QRadioButton(navigation_wid);
        animation_btn->setObjectName(QStringLiteral("animation_btn"));
        sizePolicy.setHeightForWidth(animation_btn->sizePolicy().hasHeightForWidth());
        animation_btn->setSizePolicy(sizePolicy);
        animation_btn->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"font: 14px\"\345\256\213\344\275\223\"\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"   width: 0px;\n"
"   height:0px;\n"
" border:0px;\n"
"}\n"
"\n"
"QRadioButton::unchecked\n"
"{\n"
"	color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"QRadioButton::unchecked:hover\n"
" {\n"
"    color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"QRadioButton::checked\n"
"{	\n"
"   color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
""));

        gridLayout->addWidget(animation_btn, 4, 0, 1, 1);

        otherbutton_btn = new QRadioButton(navigation_wid);
        otherbutton_btn->setObjectName(QStringLiteral("otherbutton_btn"));
        sizePolicy.setHeightForWidth(otherbutton_btn->sizePolicy().hasHeightForWidth());
        otherbutton_btn->setSizePolicy(sizePolicy);
        otherbutton_btn->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"font: 14px\"\345\256\213\344\275\223\"\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"   width: 0px;\n"
"   height:0px;\n"
" border:0px;\n"
"}\n"
"\n"
"QRadioButton::unchecked\n"
"{\n"
"	color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"QRadioButton::unchecked:hover\n"
" {\n"
"    color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"QRadioButton::checked\n"
"{	\n"
"   color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"\n"
""));

        gridLayout->addWidget(otherbutton_btn, 5, 0, 1, 1);

        progressbar_btn = new QRadioButton(navigation_wid);
        progressbar_btn->setObjectName(QStringLiteral("progressbar_btn"));
        sizePolicy.setHeightForWidth(progressbar_btn->sizePolicy().hasHeightForWidth());
        progressbar_btn->setSizePolicy(sizePolicy);
        progressbar_btn->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"font: 14px\"\345\256\213\344\275\223\"\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"   width: 0px;\n"
"   height:0px;\n"
" border:0px;\n"
"}\n"
"\n"
"QRadioButton::unchecked\n"
"{\n"
"	color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"QRadioButton::unchecked:hover\n"
" {\n"
"    color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"QRadioButton::checked\n"
"{	\n"
"   color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
""));

        gridLayout->addWidget(progressbar_btn, 0, 0, 1, 1);

        custom_win_btn = new QRadioButton(navigation_wid);
        custom_win_btn->setObjectName(QStringLiteral("custom_win_btn"));
        sizePolicy.setHeightForWidth(custom_win_btn->sizePolicy().hasHeightForWidth());
        custom_win_btn->setSizePolicy(sizePolicy);
        custom_win_btn->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"font: 14px\"\345\256\213\344\275\223\"\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"   width: 0px;\n"
"   height:0px;\n"
" border:0px;\n"
"}\n"
"\n"
"QRadioButton::unchecked\n"
"{\n"
"	color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"QRadioButton::unchecked:hover\n"
" {\n"
"    color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
"QRadioButton::checked\n"
"{	\n"
"   color: rgb(180,180,180);\n"
"    border:0px;\n"
"	background-color: rgb(40, 43, 51);\n"
"}\n"
""));

        gridLayout->addWidget(custom_win_btn, 6, 0, 1, 1);

        gridLayout->setRowStretch(0, 10);
        gridLayout->setRowStretch(1, 10);
        gridLayout->setRowStretch(2, 10);
        gridLayout->setRowStretch(3, 10);
        gridLayout->setRowStretch(4, 10);
        gridLayout->setRowStretch(5, 10);
        gridLayout->setRowStretch(6, 10);
        gridLayout->setRowStretch(7, 90);

        gridLayout_2->addWidget(navigation_wid, 0, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 30);
        gridLayout_2->setColumnStretch(2, 2);
        gridLayout_2->setColumnStretch(3, 160);

        retranslateUi(CustomControlsClass);

        main_tab_wid->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(CustomControlsClass);
    } // setupUi

    void retranslateUi(QWidget *CustomControlsClass)
    {
        CustomControlsClass->setWindowTitle(QApplication::translate("CustomControlsClass", "CustomControls", Q_NULLPTR));
        main_tab_wid->setTabText(main_tab_wid->indexOf(progressbar_tab), QApplication::translate("CustomControlsClass", "\350\277\233\345\272\246\346\235\241", Q_NULLPTR));
        main_tab_wid->setTabText(main_tab_wid->indexOf(sliderbar_tab), QApplication::translate("CustomControlsClass", "\346\273\221\345\212\250\346\235\241", Q_NULLPTR));
        main_tab_wid->setTabText(main_tab_wid->indexOf(panel_tab), QApplication::translate("CustomControlsClass", "\344\273\252\350\241\250\347\233\230", Q_NULLPTR));
        main_tab_wid->setTabText(main_tab_wid->indexOf(qwt_tab), QApplication::translate("CustomControlsClass", "\347\273\237\350\256\241\345\233\276", Q_NULLPTR));
        main_tab_wid->setTabText(main_tab_wid->indexOf(animation_tab), QApplication::translate("CustomControlsClass", "\345\212\250\347\224\273", Q_NULLPTR));
        test_drop_menu_btn->setText(QString());
        main_tab_wid->setTabText(main_tab_wid->indexOf(otherbutton_tab), QApplication::translate("CustomControlsClass", "\346\214\211\351\222\256", Q_NULLPTR));
        main_tab_wid->setTabText(main_tab_wid->indexOf(custom_win_tab), QApplication::translate("CustomControlsClass", "\350\275\257\344\273\266\351\241\265\351\235\242", Q_NULLPTR));
        label->setText(QApplication::translate("CustomControlsClass", "\346\254\242\350\277\216", Q_NULLPTR));
        main_tab_wid->setTabText(main_tab_wid->indexOf(blank_tab), QApplication::translate("CustomControlsClass", "\347\251\272\347\231\275\351\241\265", Q_NULLPTR));
        sliderbar_btn->setText(QApplication::translate("CustomControlsClass", "     \346\273\221\345\212\250\346\235\241", Q_NULLPTR));
        panel_btn->setText(QApplication::translate("CustomControlsClass", "     \344\273\252\350\241\250\347\233\230", Q_NULLPTR));
        qwt_btn->setText(QApplication::translate("CustomControlsClass", "     \347\273\237\350\256\241\345\233\276", Q_NULLPTR));
        animation_btn->setText(QApplication::translate("CustomControlsClass", "      \345\212\250\347\224\273", Q_NULLPTR));
        otherbutton_btn->setText(QApplication::translate("CustomControlsClass", "      \346\214\211\351\222\256", Q_NULLPTR));
        progressbar_btn->setText(QApplication::translate("CustomControlsClass", "     \350\277\233\345\272\246\346\235\241", Q_NULLPTR));
        custom_win_btn->setText(QApplication::translate("CustomControlsClass", "    \350\275\257\344\273\266\351\241\265\351\235\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CustomControlsClass: public Ui_CustomControlsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMCONTROLS_H

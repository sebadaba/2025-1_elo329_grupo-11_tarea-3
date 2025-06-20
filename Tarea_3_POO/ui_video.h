/********************************************************************************
** Form generated from reading UI file 'video.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_H
#define UI_VIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSlider *SliderVolumen;
    QPushButton *BotonReInicio;
    QHBoxLayout *VideoLayout;
    QPushButton *botonPlay;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(824, 591);
        gridLayoutWidget = new QWidget(Form);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 781, 541));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 2, 1, 1);

        SliderVolumen = new QSlider(gridLayoutWidget);
        SliderVolumen->setObjectName(QString::fromUtf8("SliderVolumen"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SliderVolumen->sizePolicy().hasHeightForWidth());
        SliderVolumen->setSizePolicy(sizePolicy);
        SliderVolumen->setMinimumSize(QSize(400, 0));
        SliderVolumen->setSizeIncrement(QSize(0, 0));
        SliderVolumen->setBaseSize(QSize(0, 0));
        SliderVolumen->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(SliderVolumen, 2, 4, 1, 1);

        BotonReInicio = new QPushButton(gridLayoutWidget);
        BotonReInicio->setObjectName(QString::fromUtf8("BotonReInicio"));

        gridLayout->addWidget(BotonReInicio, 2, 2, 1, 1);

        VideoLayout = new QHBoxLayout();
        VideoLayout->setObjectName(QString::fromUtf8("VideoLayout"));

        gridLayout->addLayout(VideoLayout, 0, 0, 1, 5);

        botonPlay = new QPushButton(gridLayoutWidget);
        botonPlay->setObjectName(QString::fromUtf8("botonPlay"));

        gridLayout->addWidget(botonPlay, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 3, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        BotonReInicio->setText(QCoreApplication::translate("Form", "<<", nullptr));
        botonPlay->setText(QCoreApplication::translate("Form", "||", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_H

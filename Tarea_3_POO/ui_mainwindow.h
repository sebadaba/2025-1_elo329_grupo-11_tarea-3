/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionVideo_Publisher;
    QAction *actionVideo_Subscriber;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *LayoutPublisher;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *campoURL;
    QSpacerItem *verticalSpacer;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *LayoutSusbcriber;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QPushButton *UrlBoton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuPublisher;
    QMenu *menuSubscriber;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 455);
        actionVideo_Publisher = new QAction(MainWindow);
        actionVideo_Publisher->setObjectName(QString::fromUtf8("actionVideo_Publisher"));
        actionVideo_Subscriber = new QAction(MainWindow);
        actionVideo_Subscriber->setObjectName(QString::fromUtf8("actionVideo_Subscriber"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 291, 411));
        LayoutPublisher = new QVBoxLayout(verticalLayoutWidget);
        LayoutPublisher->setObjectName(QString::fromUtf8("LayoutPublisher"));
        LayoutPublisher->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        campoURL = new QLineEdit(verticalLayoutWidget);
        campoURL->setObjectName(QString::fromUtf8("campoURL"));

        horizontalLayout_2->addWidget(campoURL);


        horizontalLayout->addLayout(horizontalLayout_2);


        LayoutPublisher->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        LayoutPublisher->addItem(verticalSpacer);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(290, 0, 501, 411));
        LayoutSusbcriber = new QVBoxLayout(verticalLayoutWidget_2);
        LayoutSusbcriber->setObjectName(QString::fromUtf8("LayoutSusbcriber"));
        LayoutSusbcriber->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        UrlBoton = new QPushButton(verticalLayoutWidget_2);
        UrlBoton->setObjectName(QString::fromUtf8("UrlBoton"));

        horizontalLayout_3->addWidget(UrlBoton);

        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        LayoutSusbcriber->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        LayoutSusbcriber->addItem(verticalSpacer_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuPublisher = new QMenu(menubar);
        menuPublisher->setObjectName(QString::fromUtf8("menuPublisher"));
        menuSubscriber = new QMenu(menubar);
        menuSubscriber->setObjectName(QString::fromUtf8("menuSubscriber"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPublisher->menuAction());
        menubar->addAction(menuSubscriber->menuAction());
        menuPublisher->addAction(actionVideo_Publisher);
        menuSubscriber->addAction(actionVideo_Subscriber);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Publisher-Subscriber Simulator", nullptr));
        actionVideo_Publisher->setText(QCoreApplication::translate("MainWindow", "Video", nullptr));
        actionVideo_Subscriber->setText(QCoreApplication::translate("MainWindow", "Video", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Ahmaru->Video", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Sebastian->video", nullptr));
        UrlBoton->setText(QCoreApplication::translate("MainWindow", "Not URL set", nullptr));
        menuPublisher->setTitle(QCoreApplication::translate("MainWindow", "Publisher", nullptr));
        menuSubscriber->setTitle(QCoreApplication::translate("MainWindow", "Subscriber", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

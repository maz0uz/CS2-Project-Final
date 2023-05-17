/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLineEdit *runTimeLabel;
    QLineEdit *landTimeLabel;
    QLabel *label_3;
    QPushButton *startButton;
    QLabel *avgLbl;
    QLabel *CrowdedLabel;
    QScrollArea *scroll;
    QWidget *scrollAreaWidgetContents_3;
    QGraphicsView *graphicsView;
    QLabel *CurrentTimeLabel;
    QLabel *Event;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1229, 777);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(420, 20, 151, 16));
        runTimeLabel = new QLineEdit(centralwidget);
        runTimeLabel->setObjectName("runTimeLabel");
        runTimeLabel->setGeometry(QRect(420, 40, 151, 21));
        landTimeLabel = new QLineEdit(centralwidget);
        landTimeLabel->setObjectName("landTimeLabel");
        landTimeLabel->setGeometry(QRect(590, 40, 151, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(590, 20, 151, 16));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(420, 60, 321, 31));
        avgLbl = new QLabel(centralwidget);
        avgLbl->setObjectName("avgLbl");
        avgLbl->setGeometry(QRect(770, 20, 391, 71));
        CrowdedLabel = new QLabel(centralwidget);
        CrowdedLabel->setObjectName("CrowdedLabel");
        CrowdedLabel->setGeometry(QRect(20, 50, 271, 51));
        scroll = new QScrollArea(centralwidget);
        scroll->setObjectName("scroll");
        scroll->setGeometry(QRect(0, 130, 1201, 571));
        scroll->setLayoutDirection(Qt::RightToLeft);
        scroll->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 1199, 569));
        graphicsView = new QGraphicsView(scrollAreaWidgetContents_3);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 20, 1181, 541));
        graphicsView->setMinimumSize(QSize(1181, 0));
        scroll->setWidget(scrollAreaWidgetContents_3);
        CurrentTimeLabel = new QLabel(centralwidget);
        CurrentTimeLabel->setObjectName("CurrentTimeLabel");
        CurrentTimeLabel->setGeometry(QRect(20, 90, 301, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font.setPointSize(30);
        CurrentTimeLabel->setFont(font);
        Event = new QLabel(centralwidget);
        Event->setObjectName("Event");
        Event->setGeometry(QRect(330, 120, 641, 16));
        MainWindow->setCentralWidget(centralwidget);
        scroll->raise();
        label_2->raise();
        runTimeLabel->raise();
        landTimeLabel->raise();
        label_3->raise();
        startButton->raise();
        avgLbl->raise();
        CrowdedLabel->raise();
        CurrentTimeLabel->raise();
        Event->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1229, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Simulation Run Time:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Planes Landing Time:", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        avgLbl->setText(QString());
        CrowdedLabel->setText(QString());
        CurrentTimeLabel->setText(QCoreApplication::translate("MainWindow", "Current Time:: 00:00", nullptr));
        Event->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

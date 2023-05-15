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
#include <QtWidgets/QGridLayout>
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
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *activityLog;
    QLabel *label_2;
    QLineEdit *runTimeLabel;
    QLineEdit *landTimeLabel;
    QLabel *label_3;
    QPushButton *startButton;
    QLabel *CurrentTimeLabel;
    QLabel *avgLbl;
    QLabel *runwayLab;
    QLabel *CrowdedLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(20, 10, 341, 311));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 339, 309));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName("gridLayout");
        activityLog = new QLabel(scrollAreaWidgetContents);
        activityLog->setObjectName("activityLog");
        activityLog->setWordWrap(true);

        gridLayout->addWidget(activityLog, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(400, 40, 151, 16));
        runTimeLabel = new QLineEdit(centralwidget);
        runTimeLabel->setObjectName("runTimeLabel");
        runTimeLabel->setGeometry(QRect(400, 60, 151, 21));
        landTimeLabel = new QLineEdit(centralwidget);
        landTimeLabel->setObjectName("landTimeLabel");
        landTimeLabel->setGeometry(QRect(570, 60, 151, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(570, 40, 151, 16));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(400, 80, 321, 31));
        CurrentTimeLabel = new QLabel(centralwidget);
        CurrentTimeLabel->setObjectName("CurrentTimeLabel");
        CurrentTimeLabel->setGeometry(QRect(590, 520, 171, 16));
        avgLbl = new QLabel(centralwidget);
        avgLbl->setObjectName("avgLbl");
        avgLbl->setGeometry(QRect(200, 370, 391, 71));
        runwayLab = new QLabel(centralwidget);
        runwayLab->setObjectName("runwayLab");
        runwayLab->setGeometry(QRect(230, 330, 131, 16));
        CrowdedLabel = new QLabel(centralwidget);
        CrowdedLabel->setObjectName("CrowdedLabel");
        CrowdedLabel->setGeometry(QRect(20, 380, 271, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        activityLog->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Simulation Run Time:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Planes Landing Time:", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        CurrentTimeLabel->setText(QCoreApplication::translate("MainWindow", "Current Time:: 00:00", nullptr));
        avgLbl->setText(QString());
        runwayLab->setText(QCoreApplication::translate("MainWindow", "Runway is Vacant", nullptr));
        CrowdedLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

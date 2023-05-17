#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "plane.h"
#include "DEQ.h"
#include "runway.h"
#include <vector>
#include<time.h>
#include <QThread>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double RNG();

private slots:
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    int t;
    int tWait;
    int landed;
    int tMax;
    double avgTime;
    int landTime;
    runway run;
    DEQ<plane>* queue;
    double avg;
    vector<QGraphicsTextItem*> vec;
    vector<QGraphicsRectItem*> vec1;

    QPixmap backgroundImage;
    QGraphicsScene *scene;
};
#endif // MAINWINDOW_H

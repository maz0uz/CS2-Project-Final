#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow), t(1),tWait(0),landed(0),avgTime(1.3),run(avgTime)
{
    ui->setupUi(this);
    queue = new DEQ<plane>;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete queue;
}

double MainWindow::RNG()
{
    int x = rand()%100+1;
    return x/100.0;
}


void MainWindow::on_startButton_clicked()
{
    t = 1;
    ui->avgLbl->setText("");
    ui->activityLog->setText("");
    ui->landTimeLabel->setReadOnly(true);
    ui->runTimeLabel->setReadOnly(true);
    ui->startButton->setEnabled(false);
    tMax = (ui->runTimeLabel->text()).toInt();
    landTime = (ui->landTimeLabel->text()).toInt();
    run.setUp(landTime);


    plane temp(landTime);

    while(t<tMax)
    {
        if(t/60<10&&t%60<10)
        {
            ui->CurrentTimeLabel->setText("Current Time: 0"+QString::number(t/60)+":0"+QString::number(t%60));
            ui->activityLog->setText(ui->activityLog->text()+"0"+QString::number(t/60)+":0"+QString::number(t%60)+'\n');
        }
        else if(t/60<10)
        {
             ui->CurrentTimeLabel->setText("Current Time: 0"+QString::number(t/60)+":"+QString::number(t%60));
             ui->activityLog->setText(ui->activityLog->text()+"0"+QString::number(t/60)+":"+QString::number(t%60)+'\n');
        }
        else if(t%60<10)
        {
            ui->CurrentTimeLabel->setText(QString::number(t/60)+":0"+QString::number(t%60));
            ui->activityLog->setText(ui->activityLog->text()+QString::number(t/60)+":0"+QString::number(t%60)+'\n');
        }
        double x = RNG();
        if(run.getProb()<x)
        {
            temp.newPlane();
            temp.setArrT(t);
            queue->Add_Rear(temp);
            ui->activityLog->setText(ui->activityLog->text()+"Plane "+QString::number(queue->View_Rear().getId())+" has arrived in the airspace\n");

            if(!queue->DEQisEmpty())
            {
                if(queue->View_Front().getArrT()+landTime<=t)
                {
                    if(!run.isOccupied(t))
                    {
                        run.land(t);
                         ui->activityLog->setText(ui->activityLog->text()+"Plane "+QString::number(queue->View_Front().getId())+" has landed and waited "+QString::number(t-queue->View_Front().getArrT()-landTime)+" minutes in the air\n");
                        tWait += t-queue->View_Front().getArrT()-landTime;
                        queue->Remove_Front();
                        landed++;
                    }else
                    {
                        ui->activityLog->setText(ui->activityLog->text()+"Plane "+QString::number(queue->View_Front().getId())+" is currently landing\n");
                         ui->activityLog->setText(ui->activityLog->text()+"Runway is currently occupied\n");
                    }
                }
                else
                {
                    ui->activityLog->setText(ui->activityLog->text()+"Plane is currently landing\n");
                }
            }
            else
            {
                ui->activityLog->setText(ui->activityLog->text()+"No planes currently\n");
            }
        }
        if(queue->DEQ_Length()>=10)
        {
            ui->CrowdedLabel->setText("Runway is crowded\nThere are currently "+QString::number(queue->DEQ_Length())+" planes waiting to land");
        }else
             ui->CrowdedLabel->setText("");
        t++;
        ui->activityLog->setText(ui->activityLog->text()+'\n');
        QThread::msleep(500);
        QCoreApplication::processEvents();
        if(run.isOccupied(t))
        {
            ui->runwayLab->setText("Runway is Occupied");
        }else
        {
            ui->runwayLab->setText("Runway is Vacant");
        }
    }
    ui->CrowdedLabel->setText("");

    if(landed != 0)
    {
        avg = tWait/landed;
        ui->avgLbl->setText("The average wait time for the "+QString::number(landed)+" planes which landed is: "+QString::number(avg)+"minutes\n"+QString::number(queue->DEQ_Length())+" planes have arrived but haven't landed");
    }
    else
        ui->avgLbl->setText("No planes have landed");
    ui->landTimeLabel->setReadOnly(false);
    ui->runTimeLabel->setReadOnly(false);
    ui->startButton->setEnabled(true);
}

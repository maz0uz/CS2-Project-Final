#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow), t(1),tWait(0),landed(0),avgTime(1.3),run(avgTime)
{
    ui->setupUi(this);
    queue = new DEQ<plane>;

    scene = new QGraphicsScene(this);
    backgroundImage.load("/Users/mohamedazouz/Downloads/RUNWAY.jpeg");

    double desiredWidth = ui->graphicsView->width();
    double desiredHeight = ui->graphicsView->height();
    double scaleX = desiredWidth / backgroundImage.width();
    double scaleY = desiredHeight / backgroundImage.height();

    ui->graphicsView->setTransform(QTransform::fromScale(scaleX, scaleY));

    scene->setSceneRect(0, 0, backgroundImage.width(), backgroundImage.height());
    scene->setBackgroundBrush(backgroundImage);


    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete queue;
    delete scene;
}

double MainWindow::RNG()
{
    int x = rand()%100+1;
    return x/100.0;
}


void MainWindow::on_startButton_clicked()
{
    int xc = 0, xc2=0;
    t = 1;
    ui->avgLbl->setText("");
   // ui->activityLog->setText("");
    ui->landTimeLabel->setReadOnly(true);
    ui->runTimeLabel->setReadOnly(true);
    ui->startButton->setEnabled(false);
    tMax = (ui->runTimeLabel->text()).toInt();
    landTime = (ui->landTimeLabel->text()).toInt();
    run.setUp(landTime);

    scene->clear();
    plane::reset();

    //QWidget *central = new QWidget;
   // QHBoxLayout *layoutNode = new QHBoxLayout(central);
   // ui->scroll->setWidget(central);
    plane temp(landTime);

    QPixmap pixmap;
    while(t<tMax)
    {
        if(!vec1.empty())
        {
            QColor customColor(255, 191, 0);
            vec1[0]->setBrush(customColor);
        }
        if(t/60<10&&t%60<10)
        {
            ui->CurrentTimeLabel->setText("Current Time: 0"+QString::number(t/60)+":0"+QString::number(t%60));
        //    ui->activityLog->setText(ui->activityLog->text()+"0"+QString::number(t/60)+":0"+QString::number(t%60)+'\n');
        }
        else if(t/60<10)
        {
             ui->CurrentTimeLabel->setText("Current Time: 0"+QString::number(t/60)+":"+QString::number(t%60));
        //     ui->activityLog->setText(ui->activityLog->text()+"0"+QString::number(t/60)+":"+QString::number(t%60)+'\n');
        }
        else if(t%60<10)
        {
            ui->CurrentTimeLabel->setText(QString::number(t/60)+":0"+QString::number(t%60));
     //       ui->activityLog->setText(ui->activityLog->text()+QString::number(t/60)+":0"+QString::number(t%60)+'\n');
        }
        double x = RNG();
        if(run.getProb()<x)
        {
            temp.newPlane();
            temp.setArrT(t);
            queue->Add_Rear(temp);
           // ui->activityLog->setText(ui->activityLog->text()+"Plane "+QString::number(queue->View_Rear().getId())+" has arrived in the airspace\n");
            ui->Event->setText("Plane "+QString::number(queue->View_Rear().getId())+" has arrived in the airspace");
          //  QLabel *tempL = new QLabel("Plane "+QString::number(temp.getId()));
            //tempL->setFixedWidth(80);
            //tempL->setFixedHeight(80);
    //        tempL->setStyleSheet("QLabel { background-color : green; color : black; }");
         //   vec.push_back(tempL);
            QGraphicsRectItem *tempItem = scene->addRect(50, backgroundImage.height()/4, 80, 120, QPen(Qt::black), QBrush(Qt::green));
                        tempItem->setPos(xc, 0);

            QGraphicsTextItem *textItem = new QGraphicsTextItem(tempItem);
            QString htmlContent = "<html><body>";
            htmlContent += "<img src='/Users/mohamedazouz/Downloads/PLANE.svg'>";
            htmlContent += QString("<p>Plane <b>%1</b></p>").arg(QString::number(queue->View_Rear().getId()));
            htmlContent += "</body></html>";
            textItem->setHtml(htmlContent);
            textItem->setDefaultTextColor(Qt::black);
            textItem->setPos(tempItem->rect().center() - textItem->boundingRect().center()+QPointF(20,0));
            vec.push_back(textItem);
            vec1.push_back(tempItem);
            xc += 100;
           // layoutNode->addWidget(tempL);
            if(!queue->DEQisEmpty())
            {
                if(queue->View_Front().getArrT()+landTime<=t)
                {
                    if(!run.isOccupied(t))
                    {
                        run.land(t);
                        ui->Event->setText("Plane "+QString::number(queue->View_Front().getId())+" has landed and waited "+QString::number(t-queue->View_Front().getArrT()-landTime)+" minutes in the air");
                       //  ui->activityLog->setText(ui->activityLog->text()+"Plane "+QString::number(queue->View_Front().getId())+" has landed and waited "+QString::number(t-queue->View_Front().getArrT()-landTime)+" minutes in the air\n");
                        tWait += t-queue->View_Front().getArrT()-landTime;
                        queue->Remove_Front();
                        scene->removeItem(vec.front());
                        scene->removeItem(vec1.front());
                        vec.erase(vec.begin());
                        vec1.erase(vec1.begin());
                        xc-=100;
                        QThread::msleep(300);
                        QCoreApplication::processEvents();
                        for(int i=0;i<(vec.size());i++)
                        {
                            vec1[i]->setPos(vec1[i]->pos()-QPointF(100,0));
                   //         vec1[i]->setPos(vec1[i]->pos()-QPointF(100,0));
                        }
                        tempItem = scene->addRect(xc2,235,90,90);
                        tempItem->setPen(QPen(Qt::transparent));
                        QGraphicsTextItem *babyplane = new QGraphicsTextItem(tempItem);
                        htmlContent = "<html><body>";
                        htmlContent += "<img src='/Users/mohamedazouz/Downloads/baby plane.svg'>";
                        htmlContent += "</body></html>";
                        babyplane->setHtml(htmlContent);
                        babyplane->setPos(tempItem->rect().center()-textItem->boundingRect().center());
                        textItem->setDefaultTextColor(Qt::black);
                       // babyplane->setPos(xc2,-150);
                        xc2+= 50;
                  //      tempL = *vec.begin();
                   //     tempL->setFixedSize(0,0);
                   //     layoutNode->removeWidget(tempL);
                     //   vec.erase(vec.begin());
                        landed++;
                    }//else
                   // {
                      //  ui->activityLog->setText(ui->activityLog->text()+"Plane "+QString::number(queue->View_Front().getId())+" is currently landing\n");
                       //  ui->activityLog->setText(ui->activityLog->text()+"Runway is currently occupied\n");
                    //}
                }
              //  else
              //  {
                //    ui->activityLog->setText(ui->activityLog->text()+"Plane is currently landing\n");
               // }
            }
            //else
            //{
              //  ui->activityLog->setText(ui->activityLog->text()+"No planes currently\n");
           // }
        }
        if(queue->DEQ_Length()>=10)
        {
            ui->CrowdedLabel->setText("Runway is crowded\nThere are currently "+QString::number(queue->DEQ_Length())+" planes waiting to land");
        }else
             ui->CrowdedLabel->setText("");
        t++;
      //  ui->activityLog->setText(ui->activityLog->text()+'\n');
        QThread::msleep(500);
        QCoreApplication::processEvents();
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

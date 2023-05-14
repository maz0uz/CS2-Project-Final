//
//  main.cpp
//  RestartProject
//
//  Created by Mohamed Azouz on 14/05/2023.
//

#include <iostream>
#include "plane.hpp"
#include "DEQ.h"
#include "runway.hpp"
#include <vector>
#include<time.h>
#include<fstream>
using namespace std;

double PoissonRandom()
{
    int x = rand()%100+1;
    return x/100.0;
}

int main()
{
    srand((unsigned)time(NULL));
    DEQ<plane> *queue = new DEQ<plane>;
    
    std::ofstream file("out.csv");
    
    int t = 1;
    int tMax = 100;
    int landTime = 10;
    double avgTime = 1.3;
    
    int tWait = 0;
    int landed = 0;
    
    runway run(avgTime, landTime);
    plane temp(landTime);
    
    while(t<tMax)
    {
        cout<<"Current time: ";
        if(t/60<10&&t%60<10)
        {
            cout<<"0"<<t/60<<":0"<<t%60<<endl;
            file << "0" << t / 60 << ":0" << t % 60 << ',';
        }
        else if(t/60<10)
        {
            cout<<"0"<<t/60<<":"<<t%60<<endl;
            file << "0" << t / 60 << ":" << t % 60 << ',';
        }
        else if(t%60<10)
        {
            cout<<t/60<<":0"<<t%60<<endl;
            file << t / 60 << ":0" << t % 60 << ',';
        }
        double x = PoissonRandom();
        if(run.getProb()<x)
        {
            temp.newPlane();
            temp.setArrT(t);
            queue->Add_Rear(temp);
            cout<<"Plane "<<queue->View_Rear().getId()<<" has arrived in the airspace"<<endl;
            file << "Plane " << queue->View_Rear().getId() << " has arrived in the airspace"<<endl;
        }
        
        if(!queue->DEQisEmpty())
        {
            if(queue->View_Front().getArrT()+landTime<=t)
            {
                if(!run.isOccupied(t))
                {
                    run.land(t);
                    file << "Plane " << queue->View_Front().getId() << " has landed and waited " << t - queue->View_Front().getArrT() - landTime << " minutes in the air"<<endl;
                    cout<<"Plane "<<queue->View_Front().getId()<<" has landed and waited "<<t-queue->View_Front().getArrT()-landTime<<" minutes in the air"<<endl;
                    tWait += t-queue->View_Front().getArrT();
                    queue->Remove_Front();
                    landed++;
                }else
                {
                    cout<<"Runway is currently occupied"<<endl;
                    file << "Runway is currently occupied"<<endl;
                }
            }
            else
            {
                cout<<"Plane is currently landing"<<endl;
                file << "No planes currently"<<endl;
            }
        }
        else
        {
            cout<<"No planes currently"<<endl;
            file << "No planes currently"<<endl;
        }
        file<<endl;
        t++;
//        nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
        cout<<endl;
    }
    
    double avg = tWait/landed;
    cout<<"The average wait time for the "<<landed<<" planes which landed is: "<<avg<<endl;
    cout<<queue->DEQ_Length()<<" planes have arrived but haven't landed"<<endl;
    file << "The average wait time for the " << landed << " planes which landed is: " << avg << '\n';
    file << queue->DEQ_Length() << " planes have arrived but haven't landed\n";
}

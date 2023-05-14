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
using namespace std;

double PoissonRandom() {
    return static_cast<double>(rand()) / RAND_MAX;
}

double ProbAppear()
{
    srand( (unsigned)time( NULL ) );
    return (float) rand()/RAND_MAX;
}

int main()
{
    DEQ<plane> *queue = new DEQ<plane>;
    
    int t = 1;
    int tMax = 100;
    int landTime = 10;
    int avgTime = 7;
    
    runway run(avgTime, landTime);
    plane temp(landTime);
    
    while(t<tMax)
    {
        cout<<t/60<<":"<<t%60<<endl;
        if(run.getProb()<PoissonRandom())
        {
            temp.newPlane();
            temp.setArrT(t);
            queue->Add_Rear(temp);
            cout<<"Plane "<<queue->View_Rear().getId()<<" has arrived in the airspace"<<endl;
        }
        
        if(!queue->DEQisEmpty())
        {
            if(queue->View_Front().getArrT()<=t)
            {
                if(!run.isOccupied(t))
                {
                    run.land(t);
                    cout<<"Plane "<<queue->View_Front().getId()<<" has landed and waited "<<t-queue->View_Front().getArrT()<<" minutes in the air"<<endl;
                    queue->Remove_Front();
                }
            }
            else
            {
                cout<<"No planes currently"<<endl;
            }
        }
        else
            cout<<"No planes currently"<<endl;
        t++;
    }
}

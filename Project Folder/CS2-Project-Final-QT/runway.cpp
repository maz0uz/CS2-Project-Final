//
//  runway.cpp
//  RestartProject
//
//  Created by Mohamed Azouz on 14/05/2023.
//

#include "runway.h"
#include<cmath>


bool runway::isOccupied(int t)
{
    if(freeT==-1||t>=freeT)
        return false;
    return true;
}

runway::runway(double d)
{
    avgDiff = d;
    probArr = (1.0/d);
    freeT=-1;
}

double runway::getProb()
{
    return probArr;
}

void runway::land(int t)
{
    freeT = t+time;
}

void runway::setUp(int t)
{
    time = t;
}

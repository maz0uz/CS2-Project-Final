//
//  plane.cpp
//  RestartProject
//
//  Created by Mohamed Azouz on 14/05/2023.
//

#include "plane.hpp"

int plane::numPlanes=0;
plane::plane(int l):landTime(l)
{
    
}
void plane::newPlane()
{
    numPlanes++;
    id = numPlanes;
}

void plane::setArrT(int t)
{
    arrival = t;
}

int plane::getArrT()
{
    return arrival;
}

int plane::getId()
{
    return id;
}

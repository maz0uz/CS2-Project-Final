//
//  plane.hpp
//  RestartProject
//
//  Created by Mohamed Azouz on 14/05/2023.
//

#ifndef plane_hpp
#define plane_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


class plane
{
private:
    static int numPlanes;
    const int landTime;
    int id;
    int wtime;
    int arrival;

    static vector<int> wait;
    static vector<int> arrive;
public:
    plane(int l);
    void newPlane();
    void setArrT(int t);
    int getArrT();
    int getId();
    static void reset();
};
#endif /* plane_hpp */

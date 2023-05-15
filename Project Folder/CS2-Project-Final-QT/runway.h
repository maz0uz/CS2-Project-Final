//
//  runway.hpp
//  RestartProject
//
//  Created by Mohamed Azouz on 14/05/2023.
//

#ifndef runway_hpp
#define runway_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class runway
{
private:
    int time;
    double avgDiff;
    double probArr;
    int freeT;
public:
    runway(double d);
    void setUp(int t);
    bool isOccupied(int t);
    double getProb();
    void land(int t);
};

#endif /* runway_hpp */

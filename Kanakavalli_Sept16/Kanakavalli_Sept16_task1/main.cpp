#include "LaneBoundary.h"
#include<iostream>
int main(){
    LaneBoundary lane1(0.015,1);
    LaneBoundary lane2(0.023,2);
    lane1.compareCurvature(lane2);
    lane2.compareCurvature(lane1);
    lane1.displayLaneDetails();
    lane2.displayLaneDetails();
    isCurvatureGreater(lane1,lane2);
    printLaneComparison(lane1,lane2);
    return 0;
}
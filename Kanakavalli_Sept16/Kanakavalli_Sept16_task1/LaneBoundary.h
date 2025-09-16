#ifndef LANEBOUNDARY_H
#define LANEBOUNDARY_H
#include<iostream>

class LaneBoundary{
   
    float curvature;
    int lane_id;
    public:
    //contructor to initialise variables
    LaneBoundary(float curvature,int lane_id);
    //getter fn
    float getCurvature() const;
    int getLaneId() const;
    //comparing curvature
    bool compareCurvature(const LaneBoundary &other) const;
    //display details
    void displayLaneDetails() const;
    //destructor
    ~LaneBoundary();
};
//global fn
bool isCurvatureGreater(const LaneBoundary& lane1, const LaneBoundary& lane2);
void printLaneComparison(const LaneBoundary& lane1, const LaneBoundary& lane2);
#endif
#pragma once
#define LANEBOUNDARY_H
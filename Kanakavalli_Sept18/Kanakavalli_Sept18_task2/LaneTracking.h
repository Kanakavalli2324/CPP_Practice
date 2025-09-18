#ifndef LANETRACKING_H
#define LANETRACKING_H
#include<iostream>
class EgoVehicleData{
    private:
    int num_lane;
    float* lane_position;
    float* sensor_confidence;
    public:
    EgoVehicleData(int n,float* lane,float* sensor);    
    ~EgoVehicleData();
    float getAverageLanePosition() const;
    void updateSensorConfidenc(float factor);
    float SumSensorConfidence();
    friend void printEgoVehicleData(const EgoVehicleData& data);
    friend void printHighestConfidenceVehicle(const EgoVehicleData* vehicle);
};
//addn task
void findHighestConfidenceVehicle(EgoVehicleData&array,int size,const EgoVehicleData*&highest);
//global helper fn
//making global as frnd function so that we can have access to the private variables without getters
#endif
#pragma once
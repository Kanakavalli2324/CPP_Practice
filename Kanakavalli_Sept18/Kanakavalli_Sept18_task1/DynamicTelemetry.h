#ifndef DYNAMICTELEMETRY_H
#define DYNAMICTELEMETRY_H
#include<iostream>
class VehicleStatus{
    private:
    int num_wheels,num_temp;
    float* wheel_speed;
    float* engine_temp;
    public:
    //constructor
    VehicleStatus(int n_wheels,float* w_speed,int n_temp,float* e_temp );
    //destructor
    ~VehicleStatus();
    //getter function for getting the private variables and arrays
    float* getWheelSpeed() const;
    float* getEngineTemp() const;
    //getting average wheel speed
    float averageWheelSpeed() const;
    //getting max temperature
    float maxTemp() const;
    //boolean to find the higher speed
    bool isWheelSpeedHigher(const VehicleStatus& other) const;
    //friend fn to get the private variables
    friend void printVehicleStatus(const VehicleStatus&vs1);
    friend bool compareWheelSpeedGlobal(const VehicleStatus&vs1,const VehicleStatus&vs2);
};

#endif
#pragma once

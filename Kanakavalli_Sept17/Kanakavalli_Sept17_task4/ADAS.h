#ifndef ADAS_H
#define ADAS_H
#include<iostream>

//enum
enum SensorType{
    LIDAR,
    RADAR,
    CAMERA
};
class SensorArray{
    public:
    int sensor_id;
    SensorType type;
    double* temperature_reading;
    int num_reading;
    static double global_max_temp;
    //default contructor
    SensorArray() ;
    //constructor
    SensorArray(int id, SensorType t, const double* readings, int n);

    //copy constructor
    SensorArray(const SensorArray& other);
    
    //helper fn
    double findLocalMax() const;
    //destructor
     ~SensorArray();

     double getMaxTemperature() const;
     void printSensorInfo() const;
     static double getGlobalMaxTemperature();
};
const char* sensorTypeToString(SensorType t);
void printSensor(const SensorArray& s);
void printAllSensors(const SensorArray* arr, int size);
#endif
#pragma once

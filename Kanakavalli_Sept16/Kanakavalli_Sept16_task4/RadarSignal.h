#ifndef RADARSIGNAL_H
#define RADARSIGNAL_H
#include <iostream>
class RadarSignal {
    public:
    int num_channels;
    float* signal_strength;
    //constructor
    RadarSignal(int channels, float* strengths);
    //copy constructor this is for deep copy and to avoid shallow copy
    RadarSignal(const RadarSignal &other);
    //destructor
    ~RadarSignal();
    //avg function
    float AverageSignal()const;
    //boosting by value and refrence
    void boostSignalByValue(RadarSignal obj);
    void boostSignalByReference(RadarSignal &obj);
};
//global fn
void printRadarSignal(const RadarSignal &obj);
RadarSignal* createRadarSignalOnHeap(int num, float* strengths);
#endif
#pragma once
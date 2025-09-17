#ifndef PEDESTRIANDETECTION_H
#define PEDESTRIANDETECTION_H
#include <cstdint>
#include <iostream>
class Pedestrian{
    private:
    uint32_t pedestrian_id;
    float distance_from_vehicle;
    public:
    //default constructor as allocating the array and assigning values doesnt occur properly
    Pedestrian();
    //constructor
    Pedestrian(uint32_t id,float dist);
    //memberfn
    void updateDistance(float dist);
    float getDistance()const;
    uint32_t getId()const;

};
//global fn
void printPedestrianInfo(const Pedestrian&ped);
void printClosestPedestrian(const Pedestrian* closest);
void findClosestPedestrian(Pedestrian* array, uint32_t size, const Pedestrian*& closest);


#endif
#pragma once




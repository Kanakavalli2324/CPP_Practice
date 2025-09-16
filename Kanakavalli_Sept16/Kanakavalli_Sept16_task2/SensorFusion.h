#ifndef SENSORFUSION_H
#define SENSORFUSION_H
#include <iostream>
class ObjectDistance {
public:
 float radar_distance;
 float camera_distance;
//constructor
ObjectDistance(float radar_dist,float camera_dist);
//pass by value this changes the copy value
void adjustDistancesByValue(ObjectDistance obj);
//pass by reference this changes the real value
void adjustDistancesByReference(ObjectDistance &obj);
~ObjectDistance();
};
//global fn
void printobjectDistance(const ObjectDistance &obj);
ObjectDistance* createObjectDistanceOnHeap(float radar_dist,float camera_dist);
#endif
#pragma once
#define SENSORFUSION_H



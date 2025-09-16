#include "SensorFusion.h"
//constructor
ObjectDistance::ObjectDistance(float radar_dist,float camera_dist):
radar_distance(radar_dist),camera_distance(camera_dist){}
//pass by value 
void ObjectDistance:: adjustDistancesByValue(ObjectDistance obj){
    obj.radar_distance+=5.0;
    obj.camera_distance+=5.0;
}
//destructor
ObjectDistance::~ObjectDistance(){}
//pass by reference
void ObjectDistance::adjustDistancesByReference(ObjectDistance &obj){
    obj.radar_distance+=5.0;
    obj.camera_distance+=5.0;
}
//globalfn
void printobjectDistance(const ObjectDistance &obj){
    std::cout<<"Radar Distance: "<<obj.radar_distance<<std::endl;
    std::cout<<"Camera Distance: "<<obj.camera_distance<<std::endl;
}
//heap allocation
ObjectDistance* createObjectDistanceOnHeap(float radar_dist,float camera_dist){
    return new ObjectDistance(radar_dist,camera_dist);
}


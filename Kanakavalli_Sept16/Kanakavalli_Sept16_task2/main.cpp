#include "SensorFusion.h"
#include<iostream>
int main(){
    ObjectDistance*obj1=createObjectDistanceOnHeap(35.5,34.8);
    std::cout<<"Initial Distances:"<<std::endl;
    printobjectDistance(*obj1);

    obj1->adjustDistancesByValue(*obj1);
    std::cout<<"After adjustDistancesByValue call:"<<std::endl;
    printobjectDistance(*obj1);
    std::cout<<"After adjustDistancesByReference call:"<<std::endl;
    obj1->adjustDistancesByReference(*obj1);
    printobjectDistance(*obj1);
    delete obj1;
    obj1=nullptr;
    return 0;
}
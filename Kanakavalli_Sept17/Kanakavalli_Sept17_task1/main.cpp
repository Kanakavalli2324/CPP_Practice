#include "PedestrianDetection.h"
#include<iostream>
#include<cstdint>
int main(){
    uint32_t size=3;
    Pedestrian* array=new Pedestrian[size];
    array[0]=Pedestrian(101,12.4);
    array[1]=Pedestrian(102,8.7);
    array[2]=Pedestrian(103,15.1);
    const Pedestrian* closest=nullptr;
    findClosestPedestrian(array,3,closest);
    for(uint32_t i=0;i<size;i++){
        printPedestrianInfo(array[i]);
    }
    printClosestPedestrian(closest);
    delete[] array;
    return 0;

}
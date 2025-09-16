#include "RadarSignal.h"
#include<iostream>
int main(){
    int num_channels=4;
    float*strengths=new float[num_channels]{55.5, 48.2, 60.1, 52.6};
    RadarSignal* radar1=createRadarSignalOnHeap(num_channels,strengths);
    std::cout<<"Actual values:"<<std::endl;
    printRadarSignal(*radar1);
    std::cout<<std::endl;
    std::cout<<"After Boosting by value"<<std::endl;
    radar1->boostSignalByValue(*radar1);
    printRadarSignal(*radar1);
    std::cout<<std::endl;
    std::cout<<"After Boosting by Refrence"<<std::endl;
    radar1->boostSignalByReference(*radar1);
    std::cout<<std::endl;
    printRadarSignal(*radar1);
    delete radar1;
    radar1=nullptr;
}
#include "RadarSignal.h"
//constructor
RadarSignal::RadarSignal(int channels,float*strengths){
    num_channels=channels;
    signal_strength=new float[channels];
    for(int i=0;i<channels;i++){
        signal_strength[i]=strengths[i];
    }
}
//copyconstructor
RadarSignal::RadarSignal(const RadarSignal &other){
    num_channels=other.num_channels;
    signal_strength=new float[num_channels];
    for(int i=0;i<num_channels;i++){
        signal_strength[i]=other.signal_strength[i];
    }
}
//destructor
RadarSignal::~RadarSignal(){
    delete[] signal_strength;
}
//avg fn
float RadarSignal:: AverageSignal()const{
    float sum=0.0;
    for(int i=0;i<num_channels;i++){
        sum+=signal_strength[i];
    }
    return sum/num_channels;
}
//boost by value
void RadarSignal::boostSignalByValue(RadarSignal obj){
    for(int i=0;i<obj.num_channels;i++){
        obj.signal_strength[i]+=5.0;
    }
}
//boost by refrence
void RadarSignal::boostSignalByReference(RadarSignal &obj){
    for(int i=0;i<num_channels;i++){
        obj.signal_strength[i]+=5.0;
    }
}
void printRadarSignal(const RadarSignal &obj){
    std::cout<<"Radar Details:"<<std::endl;
    std::cout<<"Number channels present: "<<obj.num_channels<<std::endl;
    std::cout<<"Signal strengths: ";
    for(int i=0;i<obj.num_channels;i++){
        std::cout<<obj.signal_strength[i]<<" ";
    }
}
//heap allocation
RadarSignal* createRadarSignalOnHeap(int num,float*strengths){
    return new RadarSignal(num,strengths);
}

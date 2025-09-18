#include "LaneTracking.h"

//constructor
EgoVehicleData::EgoVehicleData(int n,float* lane,float* sensor){
    num_lane=n;
    lane_position=new float[num_lane];
    sensor_confidence=new float[num_lane];
    for(int i=0;i<num_lane;i++){
        lane_position[i]=lane[i];
    }
    for(int i=0;i<num_lane;i++){
        sensor_confidence[i]=sensor[i];
    }
}
//destructor
EgoVehicleData::~EgoVehicleData(){
    delete[]lane_position;
    delete[]sensor_confidence;
}
//avg lane
float EgoVehicleData::getAverageLanePosition()const{
    float sum=0.0;
    for(int i=0;i<num_lane;i++){
        sum+=lane_position[i];
    }
    return sum/num_lane;
}
void EgoVehicleData::updateSensorConfidenc(float factor){
    for(int i=0;i<num_lane;i++){
        sensor_confidence[i]*=factor;
    }
}
float EgoVehicleData::SumSensorConfidence(){
    float sum=0.0;
    for(int i=0;i<num_lane;i++){
        sum+=sensor_confidence[i];
    }
}

void findHighestConfidenceVehicle(EgoVehicleData&array,int size,const EgoVehicleData*&highest){
    highest=&array;
    // float maxsensor=0.0;
    // for(int i=0;i<array[0].getnumlane();i++){
    //     maxsensor+=
    // }
    float maxsensor=array.SumSensorConfidence();
    for(int i=1;i<size;i++){
        EgoVehicleData& ar=*(&array+i);
        float sum=ar.SumSensorConfidence();
        if(sum>maxsensor){
            maxsensor=sum;
            highest=&ar;
        }
    }
}
void printEgoVehicleData(const EgoVehicleData& data){
    std::cout<<"Lane Psoitions:"<<std::endl;
    for(int i=0;i<data.num_lane;i++){
        std::cout<<data.lane_position[i]<<std::endl;
    }
    std::cout<<"Sensor Confidence:"<<std::endl;
    for(int i=0;i<data.num_lane;i++){
        std::cout<<data.sensor_confidence[i]<<std::endl;
    }
}
void printHighestConfidenceVehicle(const EgoVehicleData* vehicle){
    if(vehicle){
        printEgoVehicleData(*vehicle);
    }
    else{
        std::cout<<"It's a null pointer";
    }
}
#include "Adaptivecruise.h"
//defaultconstructor
TrackedVehicle::TrackedVehicle():vehicle_id(0),speed(0.0),distance(0.0){}
//constructor
TrackedVehicle::TrackedVehicle(uint32_t id, float s, float dist):vehicle_id(id),speed(s),distance(dist){
    vehicle_count++;
    if(min_recorded_dist>dist){
        min_recorded_dist=dist;
    }
}
//display details
void TrackedVehicle::display() const{
    std::cout<<"Vehicle Details"<<std::endl;
    std::cout<<"Vehicle Id: "<<vehicle_id<<std::endl;
    std::cout<<"Vehicle Speed: "<<speed<<std::endl;
    std::cout<<"Vehicle Distance: "<<distance<<std::endl;
}
const TrackedVehicle* TrackedVehicle::compareDistance(const TrackedVehicle&other) const{
    if(this->distance<=other.distance){
        return this;
    }
    else{
        return &other;
    }
}
//getter for static member

float TrackedVehicle::getMinRecordedDistance(){
    return min_recorded_dist;
}

int TrackedVehicle::getVehicleCount(){
    return vehicle_count;
}
float TrackedVehicle::min_recorded_dist=100000000000000000.000000;
int TrackedVehicle::vehicle_count=0;

//global fns

void printTrackedVehicle(const TrackedVehicle& vehicle){
    std::cout<<"Vehicle Details: "<<std::endl;
    vehicle.display();
}

void printLeadVehicle(const TrackedVehicle* lead){
    if(lead){
        printTrackedVehicle(*lead);
    }
    std::cout<<"Vehicle Not found";
}

void findLeadVehicle(TrackedVehicle* arr,uint32_t size, const TrackedVehicle*& lead){
    if(size<=0||arr==nullptr){
        std::cout<<"Cannot be accessed";
    }
    lead=&arr[0];
    for(uint32_t i=1;i<size;i++){
        if(arr[i].compareDistance(*lead)==&arr[i]){
            lead=&arr[i];
        }
    }
}

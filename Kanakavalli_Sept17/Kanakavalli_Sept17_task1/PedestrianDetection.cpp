#include "PedestrianDetection.h"
//default constructor
Pedestrian::Pedestrian():pedestrian_id(0),distance_from_vehicle(0.0){}
//constructor
Pedestrian::Pedestrian(uint32_t id,float dist): pedestrian_id(id),distance_from_vehicle(dist){}
//updating new distance
void Pedestrian::updateDistance(float newdist){
    distance_from_vehicle=newdist;
}
//getter fn
float Pedestrian::getDistance() const{
    return distance_from_vehicle;
}
uint32_t Pedestrian::getId() const{
    return pedestrian_id;
}
void printPedestrianInfo(const Pedestrian&ped){
    std::cout<<"Pedestrian details: "<<std::endl;
    std::cout<<"Pedestrian Id: "<<ped.getId()<<std::endl;
    std::cout<<"Pedestrian Distance from vehicle: "<<ped.getDistance()<<std::endl;
}
void printClosestPedestrian(const Pedestrian* closest){
    if(closest){
        printPedestrianInfo(*closest);
    }
    else{
        std::cout<<"It's a null pointer";
    }
}
void findClosestPedestrian(Pedestrian* array, uint32_t size, const Pedestrian*& closest){
    if(size<=0||array==nullptr){
        std::cout<<"Not possible";
        closest=nullptr;
        return;
    }
    closest=&array[0];
    for(int i=1;i<size;i++){
        if(array[i].getDistance()<closest->getDistance()){
            closest=&array[i];
        }
    }
}

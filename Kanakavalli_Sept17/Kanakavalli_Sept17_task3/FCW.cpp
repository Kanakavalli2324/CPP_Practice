#include "FCW.h"
//constructor
DetectedObject::DetectedObject(uint32_t id, float speed, float dist):
object_id(id),rel_speed(speed),distance(dist){}
void DetectedObject::display()const{
    std::cout<<"Object Details: "<<std::endl;
    std::cout<<"id: "<<object_id<<" "<<"Speed: "<<rel_speed<<" "<<"Distance: "<<distance<<std::endl;
}
bool DetectedObject::isHigherRisk(const DetectedObject& other) const{
    if(other.distance<this->distance && other.rel_speed>this->rel_speed){
        return true;
    }
    return false;
}
void DetectedObject::updateValuesByValue(DetectedObject obj){
    obj.rel_speed+=2.0;
    obj.distance-=5.0;
}
void DetectedObject::updateValuesByReference(DetectedObject& obj){
    obj.rel_speed+=2.0;
    obj.distance-=5.0;
}
//global fn
void printDetectedObject(const DetectedObject& obj){
    obj.display();
}

void printHighestRiskObject(const DetectedObject* obj){
    if(obj){
        if(obj->isHigherRisk(*obj)){
            std::cout<<"Object at High Risk"<<std::endl;
            obj->display();
        }
    }
    else{
        std::cout<<"Warnig ,the passed pointer is null"<<std::endl;
    }
}
void updateObjectValuesByValueGlobal(DetectedObject obj){
    obj.updateValuesByValue(obj);
}
void updateObjectValuesByReferenceGlobal(DetectedObject& obj){
    obj.updateValuesByReference(obj);
}
//finding highrisk
void findHighestRiskObject(DetectedObject*arr, uint32_t size, const DetectedObject*& riskObj){
    if(arr==nullptr || size<=0){
        std::cout<<"Not able to access";
    }
    else{
        riskObj=&arr[0];
        for(uint32_t i=1;i<size;i++){
            if(arr[i].isHigherRisk(*riskObj)){
                riskObj=&arr[i];
            }
        }
    }
}



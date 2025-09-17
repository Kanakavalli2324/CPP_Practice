#ifndef FCW_H
#define FCW_H
#include<iostream>
#include<cstdint>
class DetectedObject{
    public:
    uint32_t object_id;
    float rel_speed,distance;
    // contructor
    DetectedObject(uint32_t id,float speed,float dist);
    void display() const;
    bool isHigherRisk(const DetectedObject& other) const;
    //by value
    void updateValuesByValue(DetectedObject obj);
    //by refrence
    void updateValuesByReference(DetectedObject& obj);
};
//global fn
void printDetectedObject(const DetectedObject& obj);

void printHighestRiskObject(const DetectedObject* obj);
//by value
void updateObjectValuesByValueGlobal(DetectedObject obj);
//refrence
void updateObjectValuesByReferenceGlobal(DetectedObject& obj);

void findHighestRiskObject(DetectedObject*arr, uint32_t size, const DetectedObject*& riskObj);

#endif
#pragma once



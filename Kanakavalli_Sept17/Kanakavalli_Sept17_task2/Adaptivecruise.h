#ifndef ADAPTIVECRUISE_H
#define ADAPTIVECRUISE_H
#include<iostream>
#include<cstdint>
 
class TrackedVehicle{
    private:
    uint32_t vehicle_id;
    float speed,distance;
    static float min_recorded_dist;
    static int vehicle_count;
    public:
    TrackedVehicle();
    TrackedVehicle(uint32_t id,float s,float dist);
    void display() const;
    const TrackedVehicle* compareDistance(const TrackedVehicle&other) const;
    static float getMinRecordedDistance();
    static int getVehicleCount();
    
};
void printTrackedVehicle(const TrackedVehicle& vehicle);
void printLeadVehicle(const TrackedVehicle* lead);
void findLeadVehicle(TrackedVehicle* arr,uint32_t size, const TrackedVehicle*& lead);
#endif
#pragma once

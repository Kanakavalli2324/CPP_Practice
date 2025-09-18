#ifndef SATELLITE_H
#define SATELLITE_H
#include<iostream>

enum SatelliteSatus{
    OPERATIONAL,
     MAINTENANCE,
    DECOMMISSIONED
};
class SatelliteData{
    int satellite_id,num_antennas;
    float* signalstrength;
    float orbital_altitude;
    SatelliteSatus status;
    static int active_stellite;
    public:
    //constructor
    SatelliteData(int id,int num,float* signal,float orbital,SatelliteSatus s);
    //copyconstructor
    SatelliteData(const SatelliteData &other);
    //destructor
    ~SatelliteData();
    //avgfn
    float getAverageSignalStrength() const;
    //boosting
    void boostSignal(float factor);
    void boostSignal(float factor, float threshold);
    //getter of static
    static int getActiveSatelliteCount();
    //setter
    void setStatus(SatelliteSatus new_status);
    //getting status as string
    std::string getStatusString() const;
    friend void printSatelliteData(const SatelliteData& sd);
    friend bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2);
    friend void cloneSatellite(const SatelliteData& source, SatelliteData*& target);
    friend void updateStatusIfWeak(SatelliteData& sd, float confidence_threshold);
    
    
};

//global fn
void printActiveSatelliteCount();

//declaring it as frnd functions
#endif
#pragma once
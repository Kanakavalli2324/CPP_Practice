#ifndef CAMERACONFIG_H
#define CAMERACONFIG_H
#include <iostream>
class CameraConfig {
    public:
    int num_modes;
    int* resolutions_width; 
    int* resolutions_height;
    //constructor
    CameraConfig(int modes, int* widths, int* heights);
    //copy constructor this is for deep copy and to avoid shallow copy
    CameraConfig(const CameraConfig &other);
    //destructor
    ~CameraConfig();
    //member fns
    void printConfig() const;
    bool isHighResolutionMode(int mode1,int mode2) const;    
};
//global fn
void printCameraConfig(const CameraConfig &config);
bool globalCompareResolution(const CameraConfig &config1,int m1,int m2);

#endif
#pragma once
#define CAMERACONFIG_H

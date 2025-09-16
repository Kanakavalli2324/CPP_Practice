#include "CameraConfig.h"
#include<iostream>
int main(){
    int modes=3;
    int widths[3]={1920,1280,3840};
    int heights[3]={1080,2160,2160};
    CameraConfig cam1(modes,widths,heights);
    cam1.isHighResolutionMode(0,2);
    cam1.printConfig();
    globalCompareResolution(cam1,0,2);
    printCameraConfig(cam1);
    return 0;
}
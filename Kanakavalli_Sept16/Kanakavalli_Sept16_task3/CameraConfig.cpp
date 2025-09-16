#include "CameraConfig.h"


//constructor
CameraConfig::CameraConfig(int modes, int* width, int* height){
    num_modes=modes;
    resolutions_width=new int[modes];
    resolutions_height=new int[modes];
    for(int i=0;i<modes;i++){
        resolutions_width[i]=width[i];
        resolutions_height[i]=height[i];
    }
}
//copy constructor for deep copy
CameraConfig::CameraConfig(const CameraConfig &other){
    num_modes=other.num_modes;
    resolutions_width=new int[num_modes];
    resolutions_height=new int[num_modes];
    for(int i=0;i<num_modes;i++){
        resolutions_width[i]=other.resolutions_width[i];
        resolutions_height[i]=other.resolutions_height[i];
    }
}
//destructor
CameraConfig::~CameraConfig(){
    delete[] resolutions_width;
    delete[] resolutions_height;
}
void CameraConfig:: printConfig() const{
    std::cout<<"Details of Camera Configuration:"<<std::endl;
    std::cout<<"Number of Modes: "<<num_modes<<std::endl;
    for(int i=0;i<num_modes;i++){
        std::cout<<"Mode "<<i+1<<": "<<resolutions_width[i]<<"x"<<resolutions_height[i]<<std::endl;
    }
}
bool CameraConfig:: isHighResolutionMode(int mode1,int mode2) const{
    if(mode1>num_modes||mode2>num_modes){
        std::cout<<"Not a valid mode";
    }
    else{
        int mode1_res=resolutions_width[mode1-1]*resolutions_height[mode1-1];
        int mode2_res=resolutions_width[mode2-1]*resolutions_height[mode2-1];
        return mode1_res>mode2_res;
    }
}
//global fn
void printCameraConfig(const CameraConfig &config){
    config.printConfig();
}
bool globalCompareResolution(const CameraConfig &config1,int m1,int m2){
    return config1.isHighResolutionMode(m1,m2);
}



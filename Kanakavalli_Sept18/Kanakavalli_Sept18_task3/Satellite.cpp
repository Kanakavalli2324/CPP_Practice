#include "Satellite.h"
int SatelliteData::active_stellite=0;
//constructor
SatelliteData::SatelliteData(int id,int num,float* signal,float orbital,SatelliteSatus s):satellite_id(id),num_antennas(num){
    signalstrength=new float[num_antennas];
    for(int i=0;i<num_antennas;i++){
        signalstrength[i]=signal[i];
    }
    orbital_altitude=orbital;
    status=s;
    active_stellite++;
}
//copy
SatelliteData::SatelliteData(const SatelliteData& other){
    satellite_id=other.satellite_id;
    num_antennas=other.num_antennas;
    signalstrength=new float [num_antennas];
    for(int i=0;i<num_antennas;i++){
        signalstrength[i]=other.signalstrength[i];
    }
    orbital_altitude=other.orbital_altitude;
    status=other.status;
    active_stellite++;
}
//destructor
SatelliteData::~SatelliteData(){
    delete[] signalstrength;
    active_stellite--;
}
//fns
float SatelliteData::getAverageSignalStrength()const{
    float sum=0.0;
    for(int i=0;i<num_antennas;i++){
        sum+=signalstrength[i];
    }
    return sum/num_antennas;
}
//boosting dfn
void SatelliteData::boostSignal(float factor){
    for(int i=0;i<num_antennas;i++){
        signalstrength[i]*=factor;
    }
}
void SatelliteData::boostSignal(float factor , float thresh){
    for(int i=0;i<num_antennas;i++){
        if(signalstrength[i]<thresh){
            signalstrength[i]*=factor;
        }
    }
}
//getter
int SatelliteData::getActiveSatelliteCount(){
    return active_stellite;
}
//setter
void SatelliteData::setStatus(SatelliteSatus new_status){
    status=new_status;
}
std::string SatelliteData::getStatusString()const{
    if(status==OPERATIONAL){
        return "Operational";
    }
    else if(status==MAINTENANCE){
        return "Maintenance";
    }
    else if(status==DECOMMISSIONED){
        return "Decommissioned";
    }
    else
    return "Unknown";
}

//global frnd fn
void printSatelliteData(const SatelliteData& sd){
    std::cout<<"Satellite Details: "<<std::endl;
    std::cout<<"Id: "<<sd.satellite_id<<" "<<"Altitude: "<<sd.orbital_altitude<<" "<<"Signal strength: ";
    for(int i=0;i<sd.num_antennas;i++){
        std::cout<<sd.signalstrength[i]<<",";
    }
    std::cout<<" Status: "<<sd.getStatusString()<<std::endl;

}
bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2){
    return s1.orbital_altitude>s2.orbital_altitude;
}
//non frnd fn
void cloneSatellite(const SatelliteData& source, SatelliteData*& target){
    target=new SatelliteData(source);
}

void printActiveSatelliteCount(){
    std::cout<<"No of active satellites: "<<SatelliteData::getActiveSatelliteCount()<<std::endl;
}

void updateStatusIfWeak(SatelliteData& sd, float confidence_threshold){
    if(sd.getAverageSignalStrength()<confidence_threshold){
        sd.setStatus(MAINTENANCE);
    }
}
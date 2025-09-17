#include "ADAS.h"
//default constructor
SensorArray::SensorArray(): sensor_id(0), type(LIDAR), temperature_reading(nullptr), num_reading(0) {}
//connstrcutor
SensorArray::SensorArray(int id, SensorType t, const double* readings, int n){
    sensor_id=id;
    
    type=t;
    temperature_reading=new double[n];
    for(int i=0;i<n;i++){
        temperature_reading[i]=readings[i];
    }
    num_reading=n;
    double maxtemp=findLocalMax();
    if(maxtemp>global_max_temp){
        global_max_temp=maxtemp;
    }
    
}


double SensorArray::findLocalMax() const {
        double maxVal = temperature_reading[0];
        for (int i = 1; i < num_reading; i++) {
            if (temperature_reading[i] > maxVal) {
                maxVal = temperature_reading[i];
            }
        }
        return maxVal;
    }
double SensorArray::getMaxTemperature() const{
    return findLocalMax();
}

double SensorArray::getGlobalMaxTemperature(){
    return global_max_temp;
}
void SensorArray::printSensorInfo() const {
    std::cout << "Sensor ID: " << sensor_id << ", Type: " << sensorTypeToString(type) << ", Max Temperature: " << getMaxTemperature() << std::endl;
}
//destructor
SensorArray::~SensorArray(){
    delete[] temperature_reading;
}
double SensorArray::global_max_temp = 0;

const char* sensorTypeToString(SensorType t) {
    switch (t) {
        case LIDAR:  
        return "LIDAR";
        case RADAR:
          return "RADAR";
        case CAMERA:
         return "CAMERA";
        default: 
         return "UNKNOWN";
    }
}

void printSensor(const SensorArray& s) {
    s.printSensorInfo();
}
void printAllSensors(const SensorArray* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i].printSensorInfo();
    }
}



#include "ADAS.h"
#include <iostream>
SensorArray::SensorArray(const SensorArray& other) {
    sensor_id = other.sensor_id;
    type = other.type;
    num_reading = other.num_reading;
    
    // Perform a deep copy by allocating new memory as
    // allocating the array on heap is not done withoud a default and copy constructor
    if (num_reading > 0) {
        temperature_reading = new double[num_reading];
        for (int i = 0; i < num_reading; i++) {
            temperature_reading[i] = other.temperature_reading[i];
        }
    } else {
        temperature_reading = nullptr;
    }
}

int main() {
    
    double readings1[] = {35.5, 36.1, 34.9};
    double readings2[] = {39.0, 38.7, 39.3};
    double readings3[] = {30.2, 31.0, 30.5};

    int size = 3;
    SensorArray* sensors = new SensorArray[size]{
    SensorArray(801, LIDAR, readings1, 3),
    SensorArray(802, RADAR, readings2, 3),
    SensorArray(803, CAMERA, readings3, 3)
};
    // Print individual sensors
    std::cout << "Sensor Information" << std::endl;
    printAllSensors(sensors, size);

    // Print global max
    std::cout << "\nGlobal Maximum Temperature across all sensors: "
         << SensorArray::getGlobalMaxTemperature() <<std::endl;

    delete[] sensors;

    return 0;
}
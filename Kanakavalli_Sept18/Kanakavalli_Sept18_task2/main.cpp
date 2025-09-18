#include "LaneTracking.h"

int main() {
   
    float lanes1[] = {3.2, 3.0, 3.4};
    float conf1[]  = {0.95, 0.97, 0.93};

    float lanes2[] = {2.9, 2.8, 3.1};
    float conf2[]  = {0.92, 0.90, 0.88};

    float lanes3[] = {3.4, 3.5, 3.6};
    float conf3[]  = {0.99, 0.98, 0.97};

    EgoVehicleData* vehicles = new EgoVehicleData[3]{
        EgoVehicleData(3, lanes1, conf1),
        EgoVehicleData(3, lanes2, conf2),
        EgoVehicleData(3, lanes3, conf3)
    };

    // Adjust sensor confidences
    vehicles[0].updateSensorConfidenc(1.05f);  
    vehicles[1].updateSensorConfidenc(1.10f); 
    vehicles[2].updateSensorConfidenc(1.02f);  

    // Print all
    std::cout << "All Vehicle Data:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "Vehicle " << i + 1 << ":\n";
        printEgoVehicleData(vehicles[i]);
    }

    // Find highest confidence vehicle
    const EgoVehicleData* highest = nullptr;
    findHighestConfidenceVehicle(*vehicles, 3, highest);

    // Print result
    printHighestConfidenceVehicle(highest);

    // Free memory
    delete[] vehicles;

    return 0;
}

#include "DynamicTelemetry.h"

int main() {
    
    float ws1[] = {55.5, 56.6, 57.2, 55.9};
    float et1[] = {90.5, 88.9};

    float ws2[] = {50.0, 51.2, 49.8, 50.4};
    float et2[] = {92.0, 89.5};
    VehicleStatus v1(4, ws1, 2, et1);
    VehicleStatus v2(4, ws2, 2, et2);

    std::cout << "Vehicle 1 Status:\n";
    printVehicleStatus(v1);
    std::cout << "Average Wheel Speed: " << v1.averageWheelSpeed() << "\n";
    std::cout << "Max Engine Temp: " << v1.maxTemp()<< "\n";

    std::cout << "Vehicle 2 Status:\n";
    printVehicleStatus(v2);
    std::cout << "Average Wheel Speed: " << v2.averageWheelSpeed() << "\n";
    std::cout << "Max Engine Temp: " << v2.maxTemp()<< "\n";
   // Compare using member function
    if (v1.isWheelSpeedHigher(v2))
        std::cout << "Vehicle 1 has higher max wheel speed than Vehicle 2 (Member Function).\n";
    else
        std::cout << "Vehicle 2 has higher or equal max wheel speed (Member Function).\n";

    // Compare using global function
    if (compareWheelSpeedGlobal(v1, v2))
        std::cout << "Vehicle 1 has higher max wheel speed than Vehicle 2 (Global Function).\n";
    else
        std::cout << "Vehicle 2 has higher or equal max wheel speed (Global Function).\n";

    return 0;
}
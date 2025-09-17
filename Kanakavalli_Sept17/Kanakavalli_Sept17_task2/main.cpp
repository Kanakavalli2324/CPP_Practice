#include "Adaptivecruise.h"
#include<iostream>
#include<cstdint>
int main() {
    const uint32_t size = 4;

    TrackedVehicle* vehicles = new TrackedVehicle[size]{
        {501, 80.0f, 60.0f},
        {502, 78.0f, 45.0f},
        {503, 85.0f, 100.0f},
        {504, 76.0f, 40.0f}
    };

    // Find lead vehicle
    const TrackedVehicle* lead = nullptr;
    findLeadVehicle(vehicles, size, lead);

    // Print all vehicles
    std::cout << "All Vehicles:\n";
    for (uint32_t i = 0; i < size; i++) {
        printTrackedVehicle(vehicles[i]);
    }

    // Highlight lead vehicle
    printLeadVehicle(lead);

    // Print static info
    std::cout << "\nMinimum Recorded Distance: "<< TrackedVehicle::getMinRecordedDistance() << " m\n";
    std::cout << "Total Vehicles Tracked: "<< TrackedVehicle::getVehicleCount() << "\n";


    delete[] vehicles;

    return 0;
}
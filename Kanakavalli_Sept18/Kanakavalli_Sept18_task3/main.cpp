#include "Satellite.h"

int main() {
    // Sample Data
    float signals1[] = {78.5f, 80.2f, 79.0f};
    float signals2[] = {75.0f, 76.5f};

    SatelliteData sat1(101, 3, signals1, 550.0f, OPERATIONAL);
    SatelliteData sat2(102, 2, signals2, 600.0f, MAINTENANCE);

    // Boosting
    sat1.boostSignal(1.05f);             
    sat2.boostSignal(1.10f, 76.0f);      

    // Compare Altitudes
    std::cout << "Altitude Comparison: ";
    if (compareAltitude(sat1, sat2))
        std::cout << "Satellite 1 is higher.\n\n";
    else
        std::cout << "Satellite 2 is higher.\n\n";

    // Clone Satellite 1
    SatelliteData* sat3 = nullptr;
    cloneSatellite(sat1, sat3);

    // Print all
    std::cout << "=== Satellite Data ===\n";
    printSatelliteData(sat1);
    printSatelliteData(sat2);
    printSatelliteData(*sat3);

    // Update status if weak
    updateStatusIfWeak(sat1, 79.5f);
    updateStatusIfWeak(sat2, 76.0f);

    std::cout << "After Status Update\n";
    printSatelliteData(sat1);
    printSatelliteData(sat2);

    printActiveSatelliteCount();

    
    delete sat3;

    // Final active count
    printActiveSatelliteCount();

    return 0;
}

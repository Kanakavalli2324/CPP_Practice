#include "FCW.h"
#include<iostream>
#include<cstdint>
int main() {
    const uint32_t size = 3;
    DetectedObject* objects = new DetectedObject[size]{
        {701, 15.0f, 55.0f},
        {702, 20.0f, 35.0f},
        {703, 10.0f, 30.0f}
    };

    std::cout << "Initial Objects:\n";
    for (uint32_t i = 0; i < size; i++) {
        printDetectedObject(objects[i]);
    }

    // Update by value (copy) - does not affect original
    std::cout << "\nupdate by VALUE\n";
    updateObjectValuesByValueGlobal(objects[0]);
    std::cout << "After updateValuesByValue, original remains unchanged: ";
    objects[0].display();

    // Update by reference (original object changes)
    std::cout << "\nupdate by REFERENCE\n";
    updateObjectValuesByReferenceGlobal(objects[1]);
    std::cout << "After updateValuesByReference, original changed: ";
    objects[1].display();

    // Find highest risk object
    const DetectedObject* riskObj = nullptr;
    findHighestRiskObject(objects, size, riskObj);
    printHighestRiskObject(riskObj);

    delete[] objects;

    return 0;
}
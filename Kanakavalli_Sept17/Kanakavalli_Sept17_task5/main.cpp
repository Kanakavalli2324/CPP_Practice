#include "ParcelAnalyser.h"
#include<iostream>
#include<string>
int main() {
    ParcelAnalyser analyser;

    // Grams
    printClassification(analyser.classifyWeight(450));    // Light
    printClassification(analyser.classifyWeight(1500));   // Medium
    printClassification(analyser.classifyWeight(2500));   // Heavy

    // Kilograms
    printClassification(analyser.classifyWeight(0.3f));   // Light
    printClassification(analyser.classifyWeight(1.5f));   // Medium
    printClassification(analyser.classifyWeight(3.0f));   // Heavy

    // Pounds
    printClassification(analyser.classifyWeight(0.9));    // Light
    printClassification(analyser.classifyWeight(2.5));    // Medium
    printClassification(analyser.classifyWeight(5.0));    // Heavy

    return 0;
}
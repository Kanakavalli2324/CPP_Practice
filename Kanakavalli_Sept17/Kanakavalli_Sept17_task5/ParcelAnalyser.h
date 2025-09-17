#ifndef PARCELANALYSER_H
#define PARCELANALYSER_H
#include<iostream>
#include<string>

class ParcelAnalyser{
    public:
    //overload fns
    std::string classifyWeight(int grams);
    std::string classifyWeight(float kilograms);  
    std::string classifyWeight(double pounds);


};
void printClassification(const std::string& label);
#endif
#pragma once

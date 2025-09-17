#include "ParcelAnalyser.h"

std::string ParcelAnalyser::classifyWeight(int gm){
    if(gm<500){
        return "Light";
    }
    else if(gm<=2000){
        return "Medium";
    }
    else{
        return "Heavy";
    }
}
std::string ParcelAnalyser::classifyWeight(float kg){
    if (kg < 0.5f) return "Light";
    else if (kg <= 2.0f) return "Medium";
    else return "Heavy";
}
std::string ParcelAnalyser::classifyWeight(double pounds){
    if (pounds < 1.1) return "Light";
    else if (pounds <= 4.4) return "Medium";
    else return "Heavy";
}
void printClassification(const std::string& label) {
    std::cout << label << std::endl;
}
#include "LaneBoundary.h"

   
 //contructor to initialise variables
LaneBoundary::LaneBoundary(float curvature,int lane_id):curvature(curvature),lane_id(lane_id){}
//getter fn
float LaneBoundary::getCurvature() const{
    return curvature;
}
int LaneBoundary:: getLaneId() const{
    return lane_id;
}
//comparing curvature
bool LaneBoundary:: compareCurvature(const LaneBoundary &other) const{
    return this->curvature>=other.curvature;
}
//display details
void LaneBoundary::displayLaneDetails() const{
    std::cout<<"The lane details are:"<<std::endl;
    std::cout<<"Lane Id: "<<lane_id<<std::endl;
    std::cout<<"Curvature: "<<curvature<<std::endl;
}
//destructor
LaneBoundary::~LaneBoundary(){}
//global fn
//comparing 2 lane curvatures
bool isCurvatureGreater(const LaneBoundary& lane1, const
LaneBoundary& lane2){
    return lane1.getCurvature()>lane2.getCurvature();
}
//printing lane comaprison
void printLaneComparison(const LaneBoundary& lane1, const
LaneBoundary& lane2){
    if(lane1.compareCurvature(lane2)){
        lane1.displayLaneDetails();
    }
    else if(lane2.compareCurvature(lane1)){
        lane2.displayLaneDetails();
    }
    else{
        std::cout<<"Both lanes have equal curvature."<<std::endl;
    }
    
}
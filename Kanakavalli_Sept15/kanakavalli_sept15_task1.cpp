#include <iostream>
#include<stdexcept>

class FleetVehicle{
    public:
    int vehicleId;
    float fuelLevel;
    double distanceTraveled;
    char status;
    bool isAvailable;
    std::string driverName;
    //default constructor
    FleetVehicle(){
        vehicleId=0;
        fuelLevel=50.0;
        distanceTraveled=0.0;
        status='A';
        isAvailable=true;
        driverName="Not Assigned";
    }
    //parameterized constructor
    FleetVehicle(int id,float fuel,double distance,char stat,bool available,std::string name){
        vehicleId=id;
        fuelLevel=fuel;
        distanceTraveled=distance;
        status=stat;
        isAvailable=available;
        driverName=name;
    }
    //getter methods
    int getVehicleId(){
        return vehicleId;
    }
    float getFuelLevel(){
        return fuelLevel;
    }
    double getDistance(){
        return distanceTraveled;
    }
    char getStatus(){
        return status;
    }
    bool getAvailability(){
        return isAvailable;
    }
    std::string getDrivername(){
        return driverName;
    }
    //setter methods
    void setVehicleId(int id){
        vehicleId=id;
    }
    void setFuelLeve(float fuel){
        fuelLevel=fuel;
    }
    void setDistance(double dist){
        distanceTraveled=dist;
    }
    void setStatus(char S){
        status=S;
    }
    void setAvailability(bool avail){
        isAvailable=avail;
    }
    void setDriverName(std::string name){
        driverName=name;
    }
    void UpdateStatus(){
        if(fuelLevel<10.0||!isAvailable){
            status='I';
        }
        else{
            status='A';
        }
    }
    void DisplayInfo(){
        std::cout<<"Vehicle ID: "<<vehicleId<<std::endl;
        std::cout<<"Fuel Level: "<<fuelLevel<<std::endl;
        std::cout<<"Distance Traveled: "<<distanceTraveled<<std::endl;
        std::cout<<"Status: "<<status<<std::endl;
        std::cout<<"Availability: "<<(isAvailable?"Active":"Inactive")<<std::endl;
        std::cout<<"Driver Name: "<<driverName<<std::endl;
    }
    ~FleetVehicle(){
        std::cout<<"Destructor called for Vehicle ID: "<<vehicleId<<std::endl;
    }
};
//global functions

void assignDriver(FleetVehicle &vehicle,std::string name){
    //setting drivername
    vehicle.setDriverName(name);
    vehicle.setAvailability(true);
    vehicle.UpdateStatus();
    //getting status
    std::cout<<"Driver "<<vehicle.getDrivername()<<" assigned to Vehicle ID: "<<vehicle.getVehicleId()<<std::endl;

}
void refuelVehicle(FleetVehicle &vehicle,float fuel){
    //validation of fuel
    if(fuel<0){
        throw std::invalid_argument("Fuel amount cannot be negative");
    }
    //increasing fuel
    vehicle.setFuelLeve(vehicle.getFuelLevel()+fuel);
    vehicle.UpdateStatus();
    std::cout<<"Vehicle ID: "<<vehicle.getVehicleId()<<" refueled. New Fuel Level: "<<vehicle.getFuelLevel()<<std::endl;
}
int main(){
    //array of object pointers
    FleetVehicle vehicles[3]; 
    int choice;

    do {
        std::cout << "\nFleet Management\n";
        std::cout << "1. Add vehicle details\n";
        std::cout << "2. Assign a driver\n";
        std::cout << "3. Refuel a vehicle\n";
        std::cout << "4. Update status\n";
        std::cout << "5. Display vehicle info\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int index, id;
            float fuel;
            double dist;
            char stat;
            bool avail;
            std::string driver;

            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            if (index < 0 || index >= 3) {
                std::cout << "Invalid index!" << std::endl;
                break;
            }

            std::cout << "Enter Vehicle ID: ";
            std::cin >> id;
            std::cout << "Enter Fuel Level: ";
            std::cin >> fuel;
            std::cout << "Enter Distance Travelled: ";
            std::cin >> dist;
            std::cout << "Enter Status (A/I): ";
            std::cin >> stat;
            std::cout << "Is Available (1 for Yes, 0 for No): ";
            std::cin >> avail;
            std::cout << "Enter Driver Name: ";
            std::cin>>driver;

            vehicles[index] = FleetVehicle(id, fuel, dist, stat, avail, driver);
            std::cout << "Vehicle details added successfully!" << std::endl;
            break;
        }
        case 2: {
            int index;
            std::string name;
            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            if (index < 0 || index >= 3) {
                std::cout << "Invalid index!" << std::endl;
                break;
            }
            std::cout << "Enter Driver Name: ";
            std::cin >> name;
            assignDriver(vehicles[index], name);
            break;
        }
        case 3: {
            int index;
            float amount;
            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            if (index < 0 || index >= 3) {
                std::cout << "Invalid index!" << std::endl;
                break;
            }
            std::cout << "Enter Fuel Amount to Add: ";
            std::cin >> amount;
            try {
                refuelVehicle(vehicles[index], amount);
            } catch (const std::exception &e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 4: {
            int index;
            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            if (index < 0 || index >= 3) {
                std::cout << "Invalid index!" << std::endl;
                break;
            }
            vehicles[index].UpdateStatus();
            std::cout << "Status updated successfully!" <<std:: endl;
            break;
        }
        case 5: {
            int index;
            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            if (index < 0 || index >= 3) {
                std::cout << "Invalid index!" << std::endl;
                break;
            }
            vehicles[index].DisplayInfo();
            break;
        }
        case 6:
            std::cout << "Exiting program. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 6);

    return 0;
}


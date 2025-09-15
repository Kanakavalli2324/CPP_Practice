#include<iostream>
#include<stdexcept>
//enum declaration
enum ComponentType
{
COMPONENT_TYPE_ENGINE,
COMPONENT_TYPE_AVIONICS,
COMPONENT_TYPE_LANDING_GEAR,
COMPONENT_TYPE_FUEL_SYSTEM
};
enum ComponentStatus
{
COMPONENT_STATUS_OPERATIONAL,
COMPONENT_STATUS_MAINTENANCE_REQUIRED,
COMPONENT_STATUS_FAILED
};
//class
class AerospaceComponent{
    private:
    int componentIdentifier;
    double componenetEfficiency;
    std::string componentManufacturer;
    ComponentType componentType;
    ComponentStatus componentStatus;
    public:
    //default constructor
    AerospaceComponent(){
        componentIdentifier=0;
        componenetEfficiency=100.0;
        componentManufacturer="Unknown";
        componentType=COMPONENT_TYPE_ENGINE;
        componentStatus=COMPONENT_STATUS_OPERATIONAL;
    }
    //parameterized constructor
    AerospaceComponent(int id,double efficiency,std::string manufacturer,ComponentType type,ComponentStatus status){
        componentIdentifier=id;
        componenetEfficiency=efficiency;
        componentManufacturer=manufacturer;
        componentType=type;
        componentStatus=status;
    }
    ~AerospaceComponent(){
        std::cout<<"Component"<<componentIdentifier<<"destroyed"<<std::endl;
    }
    //getter
    bool getEfficiency() const{
        return componenetEfficiency;
    }
    ComponentType getType() const{
        return componentType;
    }
    ComponentStatus getStatus() const{
        return componentStatus;
    }
    int getId() const{
        return componentIdentifier;
    }
    std::string getManufacturer() const{
        return componentManufacturer;
    }
    void setManufacturer(const std::string &manufacturerName){
        componentManufacturer=manufacturerName;
    }

    //member fn
    void UpdateStatus(){
        if(componenetEfficiency<50.0){
            componentStatus=COMPONENT_STATUS_FAILED;
        }
        else if(componenetEfficiency>=50.0 && componenetEfficiency<80.0){
            componentStatus=COMPONENT_STATUS_MAINTENANCE_REQUIRED;
        }
        else{
            componentStatus=COMPONENT_STATUS_OPERATIONAL;
        }
    }
    void SimulateUsage(int usageHours){
        for(int i=0;i<usageHours;i++){
            componenetEfficiency-=0.5; //decrease efficiency by 0.5% per hour
            if(componenetEfficiency<0.0){
                componenetEfficiency=0.0;
                break;
            }
        }
    }
    void PerformanceMaintananceCheck(){
        ComponentStatus comp;
        switch (comp)
        {
            case COMPONENT_STATUS_OPERATIONAL:
                std::cout<<"Component is operational. No maintenance needed."<<std::endl;
                break;
            case COMPONENT_STATUS_MAINTENANCE_REQUIRED:
                std::cout<<"Component requires maintenance."<<std::endl;
                break;
            case COMPONENT_STATUS_FAILED:
                std::cout<<"Component has failed! Immediate attention required!"<<std::endl;
                break;
            default:
            std::cout<<"Unkownstatus"<<std::endl;
            break;
        }
    }
    void boostEfficiency(){
        while(componenetEfficiency<100.0){
            componenetEfficiency+=1.0;
        }
    }
    void displayDetails() const{
        std::cout<<"Component ID: "<<componentIdentifier<<std::endl;
        std::cout<<"Efficiency: "<<componenetEfficiency<<std::endl;
        std::cout<<"Manufacturer: "<<componentManufacturer<<std::endl;
        std::cout<<"Type: ";
        switch(componentType){
            case COMPONENT_TYPE_ENGINE:
                std::cout<<"Engine"<<std::endl;
                break;
            case COMPONENT_TYPE_AVIONICS:
                std::cout<<"Avionics"<<std::endl;
                break;
            case COMPONENT_TYPE_LANDING_GEAR:
                std::cout<<"Landing Gear"<<std::endl;
                break;
            case COMPONENT_TYPE_FUEL_SYSTEM:
                std::cout<<"Fuel System"<<std::endl;
                break;
        }
        std::cout<<"Status: ";
        switch(componentStatus){
            case COMPONENT_STATUS_OPERATIONAL:
                std::cout<<"Operational"<<std::endl;
                break;
            case COMPONENT_STATUS_MAINTENANCE_REQUIRED:
                std::cout<<"Maintenance Required"<<std::endl;
                break;
            case COMPONENT_STATUS_FAILED:
                std::cout<<"Failed"<<std::endl;
                break;
        }
    }

};
//global fn
void AssignManufacturer(AerospaceComponent &component,const std:: string &manufacturerName){
    component.setManufacturer(manufacturerName);
}
bool isEfficient(const AerospaceComponent &component){
    if(component.getEfficiency()>85.0){
        return true;
    }
    return false;
}
bool isSameType(const AerospaceComponent &componentA,const AerospaceComponent &componentB){
    return componentA.getType()==componentB.getType();
}
bool isSameStatus(const AerospaceComponent &componentA,const AerospaceComponent &componentB){
    return componentA.getStatus()==componentB.getStatus();
}
void PrintFormattedComponentList(const AerospaceComponent componentList[],const int size){
    std::cout<<"ID | Efficiency | MAnufacturer | Type | Status"<<std::endl;
    for(int i=0;i<size;i++){
        std::cout<<componentList[i].getId()<<" | "<<componentList[i].getEfficiency()<<" | "<<componentList[i].getManufacturer()<<" | ";
        switch(componentList[i].getType()){
            case COMPONENT_TYPE_ENGINE:
                std::cout<<"Engine | ";
                break;
            case COMPONENT_TYPE_AVIONICS:
                std::cout<<"Avionics | ";
                break;
            case COMPONENT_TYPE_LANDING_GEAR:
                std::cout<<"Landing Gear | ";
                break;
            case COMPONENT_TYPE_FUEL_SYSTEM:
                std::cout<<"Fuel System | ";
                break;
        }
        switch(componentList[i].getStatus()){
            case COMPONENT_STATUS_OPERATIONAL:
                std::cout<<"Operational"<<std::endl;
                break;
            case COMPONENT_STATUS_MAINTENANCE_REQUIRED:
                std::cout<<"Maintenance Required"<<std::endl;
                break;
            case COMPONENT_STATUS_FAILED:
                std::cout<<"Failed"<<std::endl;
                break;
        }
    }
}
int SearchComponentById(const AerospaceComponent componentList[],const int size,const int searchid){
    for(int i=0;i<size;i++){
        if(componentList[i].getId()==searchid){
            return i;
        }
    }
    return -1;
}
int main(){
    AerospaceComponent components[3];
    int current_component_index = 0;
    int choice;
    while(true){
        std::cout<<"\n---Aerospace Component Management Menu---"<<std::endl;
        std::cout<<"1. Add component details"<<std::endl;
        std::cout<<"2. Assign manufacturer"<<std::endl;
        std::cout<<"3. Simulate usage"<<std::endl;
        std::cout<<"4. Boost Efficiency"<<std::endl;
        std::cout<<"5. Check maintanace of component"<<std::endl;
        std::cout<<"6. Compare Components"<<std::endl;
        std::cout<<"7. Search Componenet by Id"<<std::endl;
        std::cout<<"8. Print formatted list of all components"<<std::endl;
        std::cout<<"9. Exit"<<std::endl;
        std::cout<<"Enter your choice: ";
        std::cin>>choice;
        if(choice<=0||choice>9 ){
            std::cout<<"Invalid Choice!"<<std::endl;
            continue;  
          }

        
        std::cout << "Enter component index (0-3 ): ";
            std::cin >> current_component_index;
            if ( current_component_index < 0 || current_component_index >= 2) {
                std::cout << "Invalid component index. Please try again." << std::endl;
                continue;
            }
        if(choice==1){
            int id, type_choice, status_choice;
                double efficiency;
                std::string manufacturer;

                std::cout << "Enter Component ID: ";
                std::cin >> id;
                std::cout << "Enter Efficiency (0.0-100.0): ";
                std::cin >> efficiency;
                if (efficiency < 0.0 || efficiency > 100.0) {
                    std::cout << "Invalid efficiency. Aborting." << std::endl;
                    break;
                }

                std::cout << "Enter Manufacturer: ";
                std::getline(std::cin, manufacturer);
                if (manufacturer.empty()) {
                    std::cout << "Manufacturer name cannot be empty. Aborting." << std::endl;
                    break;
                }
                std::cout << "Enter Type (0=Engine, 1=Avionics, 2=Landing Gear, 3=Fuel System): ";
                std::cin >> type_choice;
                if (type_choice < 0 || type_choice > 3) {
                    std::cout << "Invalid type. Aborting." << std::endl;
                    break;
                }
                std::cout << "Enter Status (0=Operational, 1=Maintenance Required, 2=Failed): ";
                std::cin >> status_choice;
                if (status_choice < 0 || status_choice > 2) {
                    std::cout << "Invalid status. Aborting." << std::endl;
                    break;
                }
                components[current_component_index] = AerospaceComponent(id, efficiency, manufacturer,
                                                         static_cast<ComponentType>(type_choice),
                                                         static_cast<ComponentStatus>(status_choice));
                std::cout << "Component added successfully." << std::endl;
                }
        else if(choice==2){
            std::string manufacturer;
            std::cout << "Enter Manufacturer Name: ";
            std::getline(std::cin, manufacturer);
            AssignManufacturer(components[current_component_index], manufacturer);
            std::cout << "Manufacturer assigned successfully." << std::endl;
        }
        else if(choice==3){
            int usagehrs;
            std::cout << "Enter usage hours to simulate: ";
            std::cin >> usagehrs;
            components[current_component_index].SimulateUsage(usagehrs);
            components[current_component_index].UpdateStatus();
        }
        else if(choice==4){
            components[current_component_index].boostEfficiency();
            components[current_component_index].UpdateStatus();
            std::cout << "Efficiency boosted to 100%." << std::endl;
        }
        else if(choice==5){
            components[current_component_index].PerformanceMaintananceCheck();
        }
        else if(choice==6){
            int ind1,ind2;
            std::cout << "Enter index of first component (0-2): ";
            std::cin >> ind1;
            std::cout << "Enter index of second component (0-2): ";
            std::cin >> ind2;
            if(isSameType(components[ind1],components[ind2])){
                std::cout<<"Both components are of same type."<<std::endl;
            }
            else{
                std::cout<<"Components are of different types."<<std::endl;
            }
        }
        else if(choice==7){
            int searchid;
            std::cout << "Enter Component ID to search: ";
            std::cin >> searchid;
            int foundIndex = SearchComponentById(components, 3, searchid);
            if (foundIndex != -1) {
                std::cout << "Component found at index: " << foundIndex << std::endl;
            } else {
                std::cout << "Component with ID " << searchid << " not found." << std::endl;
            }
        }
        else if (choice==8){
            PrintFormattedComponentList(components, 3); 
        }
        else{
            break;
        }
        
}
}

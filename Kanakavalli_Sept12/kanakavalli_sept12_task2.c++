#include<iostream>
#include<string>
using namespace std;
class Sensor{
    public:
    int id;
    float value;
    int priority;
    string status;
    Sensor(int i,float v,int p):id(i),value(v),priority(p),status("Normal"){}
    void updateValue(float val){
        value=val;
        if(value>100.0){
            status="Critical";
        }
        else if(value>50.0){
            status="Warning";
        }
        else{
            status="Normal";
        }
    }
    ~Sensor(){}
};
void rebindCriticalSensor(Sensor* &criticalSensor,Sensor* sensorList[],int size){
    int highestPriority=-1;
    for(int i=0;i<size;i++){
        if(sensorList[i]&&sensorList[i]->priority>highestPriority){
            highestPriority=sensorList[i]->priority;
            criticalSensor=sensorList[i];
        }
    }
}
void printSensorMap(Sensor* sensot[],int size){
    for(int i=0;i<size;i++){
        if(sensot[i]){
            cout<<"SensorID:"<<sensot[i]->id<<",Value:"<<sensot[i]->value<<",Status:"<<sensot[i]->status<<",Priority:"<<sensot[i]->priority<<endl;

        }
    }
}
class Controller{
    public:
    Sensor* sensorlist[10];
    Sensor& criticalSensor;
    Controller(Sensor*sensor[10],Sensor& cs):criticalSensor(cs){
        for(int i=0;i<10;i++){
            sensorlist[i]=sensor[i];
        }
    }
    void bindCriticalSensor(){
        int highestPriority=-1;
        for(int i=0;i<10;i++){
            if(sensorlist[i]&&sensorlist[i]->priority>highestPriority){
                highestPriority=sensorlist[i]->priority;
                criticalSensor=*(sensorlist[i]);
            }
        }
    }
    void updateCriticalSensor(){
        Sensor* temp=&criticalSensor;
        rebindCriticalSensor(temp,sensorlist,10);
        criticalSensor=*temp;
    }
    void printStatus(){
        cout<<"Critical Sensor ID: "<<criticalSensor.id<<endl;
        cout<<"Value: "<<criticalSensor.value<<endl;
        cout<<"Status: "<<criticalSensor.status<<endl;
    }
    ~Controller(){}

};
class sensorDiagnostics{
    public :
    string checkHealth(Sensor&s){
        if(s.status=="Critical"||s.priority<0){
            return "faulty";
        }
        return "healthy";
    }
};


int main(){
    Sensor* sensors[10];
    for(int i=0;i<10;i++){
        sensors[i]=new Sensor(i*10,i*12.5,i%5);
    }
    Sensor criticalSensor(-1,0.0,-1);
    Controller controller(sensors,criticalSensor);
    controller.bindCriticalSensor();
    controller.printStatus();
    sensors[5]->updateValue(120.0);
    controller.updateCriticalSensor();
    controller.printStatus();
    printSensorMap(sensors,10);
    sensorDiagnostics diag;
    for(int i=0;i<10;i++){
        if(sensors[i]){
            cout<<"Sensor ID: "<<sensors[i]->id<<" is "<<diag.checkHealth(*sensors[i])<<endl;
        }
    }
    for(int i=0;i<10;i++){
        delete sensors[i];
    }
    return 0;
}

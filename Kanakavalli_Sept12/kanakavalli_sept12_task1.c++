#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class Sensor{
    
    public:
    int id;
    float value,threshold;
    string status;
    Sensor(int Id,float val,float thresh){
        id=Id;
        value=val;
        threshold=thresh;
        status="Normal";
    }
    virtual void simulate()=0;
    bool isFaulty(){
        if(value>threshold){
            return true;
        }
        return false;
    }

};
class temperatureSensor:public Sensor{
    public:
    temperatureSensor(int I,float v,float thr):Sensor(I,v,thr){}
    void simulate() override{
        value+=2.5;
        if(isFaulty()){
            status="Faulty";
        }
        else{
            status="Normal";
        }
    }

};
class pressureSensor:public Sensor{
    public :
    pressureSensor(int i, float v, float t):Sensor(i,v,t){}
    void simulate() override{
        value+=1.5;
        if(isFaulty()){
            status="Faulty";
        }
        else{
            status="Normal";
        }
    }
};
class Actuator{
    public:
    int id;
    string state;
    int responseTime;
    Actuator(int i,string s,int r):id(i),state(s),responseTime(r){}
    void triggerAction(){
        if(state=="on"){
            state="off";
        }
        else{
            state="on";
        }
    }
    ~Actuator(){};
};
class Faultinjector{
    public:
    vector<Sensor*> sensors;
    vector<Actuator*> actuators;
    Faultinjector() {} // Default constructor
    Faultinjector(vector<Sensor*> s,vector<Actuator*> a):sensors(s),actuators(a){}
    void injectsensorFaults(Sensor* s){
        s->simulate();
    }
    void injectActuatorFaults(Actuator &a){
        a.responseTime+=25;
        a.triggerAction();
    }
    void injectAllFaults(){
        for(auto s: sensors){
            injectsensorFaults(s);
        }
        for(auto a: actuators){
            injectActuatorFaults(*a);
        }
    }
    void ReportStatus(){
        cout<<"Sensor Status:";
        for(auto s:sensors){
            cout<<"Sensor id:"<<s->id<<", Value:"<<s->value<<", Status:"<<s->status<<endl;
        }
        for(auto a:actuators){
            cout<<"Actuator id:"<<a->id<<", State:"<<a->state<<", Response Time:"<<a->responseTime<<endl;
        }

    }
    ~Faultinjector(){};

};
class ConfigManager{
    public:
    void updateThreshold(Sensor& s, float newThreshold){
        s.threshold=newThreshold;
    }
};
void logFault(Sensor*s){
    ofstream logfile("faultlog.txt",ios::app);
    if(logfile.is_open()){
        logfile<<"Sensor id:"<<s->id<<", Value:"<<s->value<<", Status:"<<s->status<<endl;
        logfile.close();
    }   
}
void analyzeSystem(Faultinjector* fi){
    int faultySensors = 0;
    for (Sensor* s : fi->sensors) {
        if (s->isFaulty()) {
            faultySensors++;
        }
    }

    int delayedActuators = 0;
    for (Actuator* a : fi->actuators) {
        if (a->responseTime > 150) {  // Arbitrary threshold for "delayed"
            delayedActuators++;
        }
    }
    cout<<"Analysis Report:";
    cout<<"Total Faulty Sensors: "<<faultySensors<<endl;
    cout<<"Total Delayed Actuators: "<<delayedActuators<<endl;
};


class FaultLogger{
    public:
    void log(Sensor& s){
        logFault(&s);
    }
};


class SimulationEngine{
    private:
    ConfigManager& configManager;
    FaultLogger* faultLogger;
    Faultinjector faultinjector;
    public:
    SimulationEngine(ConfigManager& cm, FaultLogger* fl) : configManager(cm), faultLogger(fl) {}

    void runSimulation() {
        // Dynamically allocate 3 sensors and 2 actuators
        temperatureSensor* temp1 = new temperatureSensor(101, 95.0f, 90.0f);
        temperatureSensor* temp2 = new temperatureSensor(102, 85.0f, 90.0f);
        pressureSensor* press1 = new pressureSensor(103, 45.0f, 50.0f);
        Actuator* act1 = new Actuator(201, "Idle", 120);
        Actuator* act2 = new Actuator(202, "Idle", 80);

        
        faultinjector.sensors.push_back(temp1);
        faultinjector.sensors.push_back(temp2);
        faultinjector.sensors.push_back(press1);
        faultinjector.actuators.push_back(act1);
        faultinjector.actuators.push_back(act2);

        
        configManager.updateThreshold(*temp2, 80.0f);

        faultinjector.injectAllFaults();

        for (Sensor* s : faultinjector.sensors) {
            faultLogger->log(*s);
            logFault(s);
        }
        for (Actuator* a : faultinjector.actuators) {
            a->triggerAction();
        }

        faultinjector.ReportStatus();
        analyzeSystem(&faultinjector);
        delete temp1;
        delete temp2;
        delete press1;
        delete act1;
        delete act2;
    }

    ~SimulationEngine() {}
};

int main() {
    ConfigManager configManager;
    FaultLogger* faultLogger = new FaultLogger();

    SimulationEngine engine(configManager, faultLogger);
    engine.runSimulation();

    delete faultLogger;

    return 0;
}




#include "SmartGarage.h"

ServiceRecord::ServiceRecord():date_(""),mileage_(0),description_(""){}
ServiceRecord::ServiceRecord(const std::string& date, int mileage, const std::string&description){
    date_=date;
    mileage=mileage;
    description_=description;
}
ServiceRecord::ServiceRecord(const ServiceRecord& other){
    date_=other.date_;
    mileage_=other.mileage_;
    description_=other.description_;
}
//basic diff b/w assignment copy and normal copy operator is as we knw this copy is for deep copying from an 
//already existing obj to a non exist obj but the assi is for assigning a exist obj to another exist obj
ServiceRecord& ServiceRecord::operator=(const ServiceRecord& other){
    if(this!= &other){
        date_=other.date_;
        mileage_=other.mileage_;
        description_=other.description_;
    }
    return *this;
}
//getter
const std::string& ServiceRecord:: getDate() const{
    return date_;
}
int ServiceRecord::getMileage() const{
    return mileage_;
}
const std::string& ServiceRecord::getDescription() const{
    return description_;
}
void ServiceRecord::print() const{
    std::cout<<"Date: "<<date_<<std::endl;
    std::cout<<"Mileage: "<<mileage_<<std::endl;
    std::cout<<"Description of Car: "<<description_<<std::endl;
}
//class 2
size_t Car::totalCar_=0;
Car::Car() : vin_(""), make_(""), model_(""), price_(0),serviceHistory_(nullptr), serviceCount_(0), serviceCap_(0),
             damageCode_(nullptr), damageCount_(0), damageCap_(0) {
    totalCar_++;
}
Car::Car(const std::string& vin, const std::string& make, const std::string& model, double price){
    vin_=vin;
    make_=make;
    model_=model;
    price_=price;
    serviceHistory_=nullptr;
    serviceCount_=0;
    serviceCap_=0;
    damageCode_=nullptr;
    damageCount_=0;
    damageCap_=0;
    if(price_>0){
        totalCar_++;
    }
}
Car::Car(const Car& other){
    vin_=other.vin_;
    make_=other.make_;
    model_=other.model_;
    price_=other.price_;
    serviceHistory_=nullptr;
    serviceCount_=other.serviceCount_;
    serviceCap_=other.serviceCap_;
    damageCode_=nullptr;
    damageCount_=other.damageCount_;
    damageCap_=other.damageCap_;
    if(serviceCap_>0){
        serviceHistory_=new ServiceRecord[serviceCap_];
        for(int i=0;i<serviceCount_;i++){
            serviceHistory_[i]=other.serviceHistory_[i];
        }
    }
    if(damageCap_>0){
        damageCode_=new int[damageCap_];
        for(int i=0;i<damageCount_;i++){
            damageCode_[i]=other.damageCode_[i];
        }
    }
    totalCar_++;
}
Car::~Car(){
    delete[] damageCode_;
    delete[]serviceHistory_;
    totalCar_--;
}
//operat assign copy
Car& Car::operator=(Car other){
    swap(*this,other);
    return *this;
}
//frnd fn
void swap(Car& lhs, Car& rhs) noexcept{
    using std::swap;  // allow ADL
    swap(lhs.vin_, rhs.vin_);
    swap(lhs.make_, rhs.make_);
    swap(lhs.model_, rhs.model_);
    swap(lhs.price_, rhs.price_);
    swap(lhs.serviceHistory_, rhs.serviceHistory_);
    swap(lhs.serviceCount_, rhs.serviceCount_);
    swap(lhs.serviceCap_, rhs.serviceCap_);
    swap(lhs.damageCode_, rhs.damageCode_);
    swap(lhs.damageCount_, rhs.damageCount_);
    swap(lhs.damageCap_, rhs.damageCap_);
}
//fn to access static member
size_t Car::getTotalCars(){
    return totalCar_;
}
//setters
void Car::setVIN(const std::string& vin){
    vin_=vin;
}
void Car::setMake(const std::string& make){
    make_=make;
}
void Car::setModel(const std::string& model){
    model_=model;
}
void Car::setPrice(double price){
    if(price<0) {
        throw std::invalid_argument("Invlaid");
    };
    price_=price;
}

//getters
const std::string& Car:: getVIN() const{
    return vin_;
}
const std::string& Car:: getMake() const{
    return make_;
}
const std::string& Car:: getModel() const{
    return model_;
}
double Car::getPrice()const{
    return price_;
}
size_t Car::getServiceCount() const{
    return serviceCount_;
}
size_t Car::getDamageCount() const{
    return damageCount_;
}
const ServiceRecord* Car:: getServiceHistory() const{
    return serviceHistory_;
}
const int* Car::getDamageCodes() const{
    return damageCode_;
}

void Car:: reserveService(size_t newCap){
    if(newCap<serviceCap_){
        return;
    }
    ServiceRecord* serviceHistory_new= new ServiceRecord[newCap];
    int j=0;
    for(int i=0;i<serviceCount_;i++){
        serviceHistory_new[i]=serviceHistory_[i];
        j=i;
    }
    delete[]serviceHistory_;
    serviceHistory_=serviceHistory_new;
    serviceCap_=newCap;

}
void Car::reserveDamage(size_t newCap) {
    if (newCap <= damageCap_){
        return;
    } 
    int* newArr = new int[newCap];
    for (size_t i = 0; i < damageCount_; ++i){
        newArr[i] = damageCode_[i];
    } 
    delete[] damageCode_;
    damageCode_ = newArr;
    damageCap_ = newCap;
}

//logic fn
void Car:: addService(const ServiceRecord& rec){
    if (serviceCount_ == serviceCap_){
        reserveService(serviceCap_ == 0 ? 2 : serviceCap_ * 2);
    }
    serviceHistory_[serviceCount_++] = rec;
}
void Car::addDamageCode(int code){
    if(damageCount_==damageCap_) {
        reserveDamage(damageCap_==0?2:damageCap_*2);
    }
    damageCode_[damageCount_++]=code;
}
void Car::printInfo() const{
    std::cout<<"ID: "<<vin_<<std::endl<<"Maker: "<<make_<<std::endl<<"Model: "<<model_<<std::endl<<
    "Price: "<<price_<<std::endl;
    if(serviceCount_>0){
        std::cout<<"No. of service records:"<<serviceCount_<<std::endl;
    }
    if(damageCount_>0){
        std::cout<<"No of damage code: "<<damageCount_<<std::endl;
    }
}
//global
double averagePrice(const Car* arr, size_t n){
    double sum=0.0;
    for(int i=0;i<n;i++){
        sum+=arr[i].getPrice();
    }
    return sum/n;
}
//ascending
bool compareByPriceAsc(const Car& a, const Car& b){
    return a.getPrice()<b.getPrice();
}
//descending
bool compareByPriceDesc(const Car& a, const Car& b){
    return a.getPrice()>b.getPrice();
}
//equal id
bool areCarsEqual(const Car& a, const Car& b){
    return a.getVIN()==b.getVIN();
}
//getting max from array of car obj
const Car* maxPriceCar(const Car* arr, size_t n){
    double max=arr[0].getPrice();
    const Car* maxCar=&arr[0];
    for(int i=0;i<n;i++){
        if(arr[i].getPrice()>max){
            max=arr[i].getPrice();
            maxCar=&arr[i];
        }
    }
    return maxCar;
}
//search fn
const Car*findCarByVIN(const Car* arr, size_t n, const std::string& vin){
    for(int i=0;i<n;i++){
        if(arr[i].getVIN()==vin){
            return &arr[i];
        }
    }
    return nullptr;

}
//count of damage
size_t countCarsWithDamage(const Car* arr, size_t n, int code){
    size_t count=0;
    for(int i=0;i<n;i++){
        const int* d_arr=arr[i].getDamageCodes();
        for(size_t j=0;j<arr[i].getDamageCount();j++){
            if(d_arr[j]==code)
            count++;
        }

    }
    return count;
}
void swapCars(Car& a, Car& b) {
     swap(a, b);
}
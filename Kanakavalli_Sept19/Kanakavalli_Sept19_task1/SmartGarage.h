#ifndef SMARTGARAGE_H
#define SMARTGARAGE_H
#include<iostream>
class ServiceRecord{
    private:
    std::string date_;
    int mileage_;
    std::string description_;
    public:
    //constructor
    //default
    ServiceRecord();
    //parameterised
    ServiceRecord(const std::string& date, int mileage, const std::string&description);
    //copy
    ServiceRecord(const ServiceRecord&);
    ServiceRecord& operator=(const ServiceRecord&);
    //getter fn
    const std::string& getDate() const;
    int getMileage() const;
    const std::string& getDescription() const;
    //utility fn
    void print() const;

};
//second class
class Car{
    private:
    std::string vin_,make_,model_;
    double price_;
    ServiceRecord* serviceHistory_;
    size_t serviceCount_,serviceCap_;
    int* damageCode_;
    size_t damageCount_,damageCap_;
    static size_t totalCar_;
    //helper fn in appending 
    void reserveService(size_t newCap);
    void reserveDamage(size_t newCap);
    public:
    //constructor
    //default
    Car();
    //parameterised
    Car(const std::string& vin, const std::string& make, const std::string& model, double price);
    //copy
    Car(const Car& other);
    //destructor
    ~Car();

    //operator
    Car& operator=(Car other);
    //friend fn
    friend void swap(Car& lhs, Car& rhs) noexcept;
    //fn to access static member
    static size_t getTotalCars();
    //setters
    void setVIN(const std::string& vin);
    void setMake(const std::string& make);
    void setModel(const std::string& model);
    void setPrice(double price);
    //getters
    const std::string& getVIN() const;
    const std::string& getMake() const;
    const std::string& getModel() const;
    double getPrice() const;
    size_t getServiceCount() const;
    size_t getDamageCount() const;
    const ServiceRecord* getServiceHistory() const;
    const int* getDamageCodes() const;
    //logic fn
    void addService(const ServiceRecord& rec);
    void addDamageCode(int code);
    void printInfo() const;



};
//global
double averagePrice(const Car* arr, size_t n);
bool compareByPriceAsc(const Car& a, const Car& b);
bool compareByPriceDesc(const Car& a, const Car& b);
bool areCarsEqual(const Car& a, const Car& b);
const Car* maxPriceCar(const Car* arr, size_t n);
const Car*findCarByVIN(const Car* arr, size_t n, const std::string& vin);
size_t countCarsWithDamage(const Car* arr, size_t n, int code);
void swapCars(Car& a, Car& b);

#endif
#pragma once
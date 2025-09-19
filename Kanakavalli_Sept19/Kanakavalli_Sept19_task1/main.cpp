#include "SmartGarage.h"

#include <iostream>

int main() {
    using std::cout;

    cout << "Total Cars initially: " << Car::getTotalCars() << "\n";

    Car cDefault;
    cDefault.printInfo();
    cout << "Total Cars: " << Car::getTotalCars() << "\n";

    Car cHonda("1HGCM", "Honda", "Accord", 19999.99);
    cHonda.addDamageCode(101);
    cHonda.addDamageCode(205);
    cHonda.addDamageCode(307);

    ServiceRecord srOil("2022-03-15", 15000, "Oil change");
    ServiceRecord srBrake("2023-01-10", 25000, "Brake pads replacement");
    cHonda.addService(srOil);
    cHonda.addService(srBrake);
    cHonda.printInfo();

    Car cCopy(cHonda);
    cCopy.printInfo();

    Car cAssign;
    cAssign = cHonda;
    cAssign.printInfo();

    const size_t N = 3;
    Car* garage = new Car[N];
    garage[0] = Car("JH4KA", "Acura", "TLX", 27999.49);
    garage[1] = Car("5YJ3E", "Tesla", "Model 3", 39999.00);
    garage[2] = Car("WBA4", "BMW", "3 Series", 34999.99);

    garage[0].addDamageCode(102);
    garage[0].addDamageCode(208);
    garage[1].addDamageCode(110);
    garage[2].addDamageCode(150);

    garage[0].addService(ServiceRecord("2023-06-20", 30000, "Tire rotation"));
    garage[1].addService(ServiceRecord("2024-02-05", 35000, "Annual inspection"));

    for (size_t i = 0; i < N; ++i) garage[i].printInfo();

    cout << "Average price in garage: " << averagePrice(garage, N) << "\n";
    const Car* maxC = maxPriceCar(garage, N);
    if (maxC) cout << "Most expensive car VIN: " << maxC->getVIN() << "\n";

    const Car* found = findCarByVIN(garage, N, "5YJ3E");
    if (found) cout << "Found Tesla with price: " << found->getPrice() << "\n";

    cout << "Cars with damage code 150: " << countCarsWithDamage(garage, N, 150) << "\n";

    delete[] garage;
    cout << "Total Cars before exit: " << Car::getTotalCars() << "\n";
}
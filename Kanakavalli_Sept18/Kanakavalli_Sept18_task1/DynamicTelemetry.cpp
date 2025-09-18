#include "DynamicTelemetry.h"

// constructor defn
VehicleStatus::VehicleStatus(int n_wheels, float *w_speed, int n_temp, float *e_temp)
{
    num_wheels = n_wheels;
    wheel_speed = new float[num_wheels];
    for (int i = 0; i < num_wheels; i++)
    {
        wheel_speed[i] = w_speed[i];
    }
    num_temp = n_temp;
    engine_temp = new float[num_temp];
    for (int i = 0; i < num_temp; i++)
    {
        engine_temp[i] = e_temp[i];
    }
}
// destructor
VehicleStatus::~VehicleStatus()
{
    delete[] wheel_speed;
    delete[] engine_temp;
}
// getter fns
float *VehicleStatus::getWheelSpeed() const
{
    return wheel_speed;
}
float *VehicleStatus::getEngineTemp() const
{
    return engine_temp;
}
// member fns
float VehicleStatus::averageWheelSpeed() const
{
    float sum = 0.0;
    for (int i = 0; i < num_wheels; i++)
    {
        sum += wheel_speed[i];
    }
    return sum / num_wheels;
}
float VehicleStatus::maxTemp() const
{
    float max = 0.0;
    for (int i = 0; i < num_temp; i++)
    {
        if (engine_temp[i] > max)
        {
            max = engine_temp[i];
        }
    }
    return max;
}

// higher speed defn
bool VehicleStatus::isWheelSpeedHigher(const VehicleStatus &other) const
{
    float max1 = 0.0, max2 = 0.0;
    for (int i = 0; i < num_wheels; i++)
    {
        if (wheel_speed[i] > max1)
        {
            max1 = wheel_speed[i];
        }
    }
    for (int i = 0; i < other.num_wheels; i++)
    {
        if (other.wheel_speed[i] > max2)
        {
            max2 = other.wheel_speed[i];
        }
    }
    return max1 > max2;
}
// global fns
void printVehicleStatus(const VehicleStatus &vs)
{

    std::cout << "Wheel Speed of the given Vehicle are: " << std::endl;
    for (int i = 0; i < vs.num_wheels; i++)
    {
        std::cout << vs.wheel_speed[i] << std::endl;
    }
    std::cout << "\n";
    std::cout << "Engine temperature of the given vehicle: " << std::endl;
    for (int i = 0; i < vs.num_temp; i++)
    {
        std::cout << vs.engine_temp[i] << std::endl;
    }
}
bool compareWheelSpeedGlobal(const VehicleStatus &vs1, const VehicleStatus &vs2)
{
    return vs1.isWheelSpeedHigher(vs2);
}

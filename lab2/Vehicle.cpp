#include "Vehicle.h"
#include <iostream>

int Vehicle::objectCount = 0;

Vehicle::Vehicle()
    : brand("Unknown"),
      year(2000),
      kilometers(0.0),
      engineStarted(false),
      status(VehicleStatus::Working)
{
    objectCount++;
}

Vehicle::Vehicle(const std::string& brand, int year)
    : brand(brand),
      year(year),
      kilometers(0.0),
      engineStarted(false),
      status(VehicleStatus::Working)
{
    if (this->brand.empty())
    {
        this->brand = "Unknown";
    }

    if (this->year < 1886 || this->year > 2026)
    {
        this->year = 2000;
    }

    objectCount++;
}

Vehicle::Vehicle(
    const std::string& brand,
    int year,
    double kilometers,
    VehicleStatus status
)
    : brand(brand),
      year(year),
      kilometers(kilometers),
      engineStarted(false),
      status(status)
{
    if (this->brand.empty())
    {
        this->brand = "Unknown";
    }

    if (this->year < 1886 || this->year > 2026)
    {
        this->year = 2000;
    }

    if (this->kilometers < 0)
    {
        this->kilometers = 0;
    }

    objectCount++;
}

Vehicle::~Vehicle()
{
    std::cout << "Object " << brand << " destroyed" << std::endl;
    objectCount--;
}

std::string Vehicle::getBrand() const
{
    return brand;
}

int Vehicle::getYear() const
{
    return year;
}

double Vehicle::getKilometers() const
{
    return kilometers;
}

bool Vehicle::isEngineStarted() const
{
    return engineStarted;
}

VehicleStatus Vehicle::getStatus() const
{
    return status;
}

void Vehicle::startEngine()
{
    if (status == VehicleStatus::Broken)
    {
        std::cout << "Car is broken. Engine cannot be started." << std::endl;
        return;
    }

    if (engineStarted)
    {
        std::cout << "Engine is already started." << std::endl;
        return;
    }

    engineStarted = true;
    std::cout << "Engine started." << std::endl;
}

void Vehicle::stopEngine()
{
    if (!engineStarted)
    {
        std::cout << "Engine is already stopped." << std::endl;
        return;
    }

    engineStarted = false;
    std::cout << "Engine stopped." << std::endl;
}

void Vehicle::drive(double distance)
{
    if (distance <= 0)
    {
        std::cout << "Distance must be greater than zero." << std::endl;
        return;
    }

    if (status == VehicleStatus::Broken)
    {
        std::cout << "Car is broken and cannot drive." << std::endl;
        return;
    }

    if (!engineStarted)
    {
        std::cout << "Start the engine first." << std::endl;
        return;
    }

    kilometers += distance;

    std::cout << "Car drove "
              << distance
              << " km."
              << std::endl;
}

void Vehicle::breakCar()
{
    if (status == VehicleStatus::Broken)
    {
        std::cout << "Car is already broken." << std::endl;
        return;
    }

    status = VehicleStatus::Broken;
    engineStarted = false;

    std::cout << "Car is broken." << std::endl;
}

void Vehicle::repairCar()
{
    if (status == VehicleStatus::Working)
    {
        std::cout << "Car is already working." << std::endl;
        return;
    }

    status = VehicleStatus::Working;

    std::cout << "Car repaired." << std::endl;
}

void Vehicle::printInfo() const
{
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Kilometers: " << kilometers << std::endl;

    if (engineStarted)
    {
        std::cout << "Engine: started" << std::endl;
    }
    else
    {
        std::cout << "Engine: stopped" << std::endl;
    }

    if (status == VehicleStatus::Working)
    {
        std::cout << "Status: working" << std::endl;
    }
    else
    {
        std::cout << "Status: broken" << std::endl;
    }

    std::cout << std::endl;
}

int Vehicle::getObjectCount()
{
    return objectCount;
}
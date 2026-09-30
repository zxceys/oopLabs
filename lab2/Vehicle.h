#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

enum class VehicleStatus
{
    Working,
    Broken
};

class Vehicle
{
private:
    std::string brand;
    int year;
    double kilometers;
    bool engineStarted;
    VehicleStatus status;

    static int objectCount;

public:
    Vehicle();

    Vehicle(const std::string& brand, int year);

    Vehicle(
        const std::string& brand,
        int year,
        double kilometers,
        VehicleStatus status
    );

    ~Vehicle();

    std::string getBrand() const;
    int getYear() const;
    double getKilometers() const;
    bool isEngineStarted() const;
    VehicleStatus getStatus() const;

    void startEngine();
    void stopEngine();
    void drive(double distance);
    void breakCar();
    void repairCar();

    void printInfo() const;

    static int getObjectCount();
};

#endif
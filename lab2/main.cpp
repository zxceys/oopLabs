#include <iostream>
#include "Vehicle.h"

int main()
{
    std::cout << "Creating vehicles" << std::endl;
    std::cout << std::endl;

    // Создание объекта без параметров
    Vehicle car1;

    // Создание объекта с двумя параметрами
    Vehicle car2("Toyota", 2020);

    // Создание объекта с полным набором параметров
    Vehicle car3(
        "BMW",
        2022,
        35000,
        VehicleStatus::Working
    );

    std::cout << "Objects count: "
              << Vehicle::getObjectCount()
              << std::endl;

    std::cout << std::endl;

    // Вывод начального состояния
    std::cout << "Initial state:" << std::endl;
    std::cout << std::endl;

    std::cout << "Car 1:" << std::endl;
    car1.printInfo();

    std::cout << "Car 2:" << std::endl;
    car2.printInfo();

    std::cout << "Car 3:" << std::endl;
    car3.printInfo();

    // Проверка корректных действий
    std::cout << "Correct operations with car2:" << std::endl;
    std::cout << std::endl;

    car2.startEngine();
    car2.drive(100);
    car2.stopEngine();

    std::cout << std::endl;

    car2.printInfo();

    // Проверка некорректных действий
    std::cout << "Incorrect operations:" << std::endl;
    std::cout << std::endl;

    // Попытка ехать с выключенным двигателем
    car2.drive(100);

    // Отрицательное расстояние
    car2.drive(-50);

    // Ломаем автомобиль
    car2.breakCar();

    // Попытка запустить двигатель сломанного автомобиля
    car2.startEngine();

    // Попытка ехать на сломанном автомобиле
    car2.drive(50);

    std::cout << std::endl;

    // Проверяем, что состояние автомобиля осталось корректным
    std::cout << "Car2 state after incorrect operations:"
              << std::endl;
    car2.printInfo();

    // Ремонт автомобиля
    std::cout << "Repairing car2:" << std::endl;
    std::cout << std::endl;

    car2.repairCar();
    car2.startEngine();
    car2.drive(50);
    car2.stopEngine();

    std::cout << std::endl;

    car2.printInfo();

    // Проверка независимости объектов
    std::cout << "Checking independence of objects:"
              << std::endl;
    std::cout << std::endl;

    std::cout << "Changing car1..." << std::endl;

    car1.startEngine();
    car1.drive(200);

    std::cout << std::endl;

    std::cout << "Car1 after changes:" << std::endl;
    car1.printInfo();

    std::cout << "Car2:" << std::endl;
    car2.printInfo();

    std::cout << "Car3:" << std::endl;
    car3.printInfo();

    // Проверка количества существующих объектов
    std::cout << "Objects count before program end: "
              << Vehicle::getObjectCount()
              << std::endl;

    return 0;
}
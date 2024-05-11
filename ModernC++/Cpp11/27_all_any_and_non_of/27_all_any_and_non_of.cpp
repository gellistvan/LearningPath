#include <iostream>
#include <vector>
#include <algorithm>

class Car {
public:
    std::string make;
    int year;
    double price;
    bool isAvailable;

    Car(std::string m, int y, double p, bool available)
        : make(m), year(y), price(p), isAvailable(available) {}
};

int main() {
    std::vector<Car> cars {
        Car("Toyota", 2020, 20000.00, true),
        Car("Ford", 2018, 18000.00, false),
        Car("Honda", 2022, 22000.00, true),
        Car("Chevrolet", 2021, 21000.00, true)
    };

    // Check if all cars are available
    bool allAvailable = std::all_of(cars.begin(), cars.end(), [](const Car& car) {
        return car.isAvailable;
    });
    std::cout << "All cars are available: " << (allAvailable ? "Yes" : "No") << std::endl;

    // Check if any car is priced over $25,000
    bool anyExpensive = std::any_of(cars.begin(), cars.end(), [](const Car& car) {
        return car.price > 25000;
    });
    std::cout << "Any car is priced over $25,000: " << (anyExpensive ? "Yes" : "No") << std::endl;

    // Check if none of the cars are older than 2017
    bool noneOld = std::none_of(cars.begin(), cars.end(), [](const Car& car) {
        return car.year < 2017;
    });
    std::cout << "No cars are older than 2017: " << (noneOld ? "Yes" : "No") << std::endl;

    return 0;
}

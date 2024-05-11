#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct WeatherStation {
    std::string name;
    double temperature;

    WeatherStation(std::string name, double temperature)
        : name(name), temperature(temperature) {}

    void display() const {
        std::cout << name << ": " << temperature << " degrees Celsius" << std::endl;
    }
};

int main() {
    std::vector<WeatherStation> stations {
        {"Station A", 15.5},
        {"Station B", 23.1},
        {"Station C", 17.6},
        {"Station D", 19.3},
        {"Station E", 21.8}
    };

    // Find the station with the lowest and highest temperature
    auto result = std::minmax_element(stations.begin(), stations.end(), 
                                      [](const WeatherStation& a, const WeatherStation& b) {
                                          return a.temperature < b.temperature;
                                      });

    std::cout << "Coldest station: ";
    result.first->display();
    std::cout << "Hottest station: ";
    result.second->display();

    // Compare two specific temperature readings directly
    double temp1 = 18.7;
    double temp2 = 22.4;
    auto minmaxTemp = std::minmax(temp1, temp2);
    std::cout << "Comparing temperatures: " << minmaxTemp.first << " (min), " << minmaxTemp.second << " (max)" << std::endl;

    return 0;
}

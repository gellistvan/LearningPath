#include <chrono>
#include <thread>
#include <iostream>

void function() {
    // Simulate work by sleeping
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

auto elapsed () {
    auto start = std::chrono::high_resolution_clock::now();
    function();
    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = stop - start;
    return elapsed.count();
}

int main() {
    std::cout << "Function took " << elapsed() << " seconds." << std::endl;

    auto now = std::chrono::system_clock::now();
    auto later = now + std::chrono::hours(1);  // time point one hour from now
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::time_t later_c = std::chrono::system_clock::to_time_t(later);
    std::cout << "Current time: " << std::ctime(&now_c);
    std::cout << "One hour later: " << std::ctime(&later_c);
}

#include <iostream>
#include <thread>

thread_local int counter = 0;  // Each thread gets its own counter

void incrementCounter() {
    counter++;
    std::cout << "Counter in Thread " << std::this_thread::get_id()
              << " = " << counter << std::endl;
}

int main() {
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);
    std::thread t3(incrementCounter);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

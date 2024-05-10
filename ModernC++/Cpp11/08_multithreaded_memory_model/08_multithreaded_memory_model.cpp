#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <future>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
std::atomic<int> counter{0};

void print_id(int id) {
    std::unique_lock<std::mutex> lck(mtx);
    while (!ready) cv.wait(lck);
    std::cout << "Thread " << id << '\n';
}

void go() {
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    cv.notify_all();
}

void atomic_counter() {
    for (int i = 0; i < 1000; ++i) {
        counter.fetch_add(1, std::memory_order_relaxed);
    }
}

int compute_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) sum += i;
    return sum;
}
/*
 * Explanation of the Code
* 1. Threads and Condition Variables: The example starts 10 threads, each printing their ID once a condition variable signals that they can proceed. This shows the use of std::thread, std::mutex, and std::condition_variable.
* 2. Atomic Operations: A group of threads each increments an atomic counter 1000 times using a relaxed memory order to avoid unnecessary synchronization overhead.
* 3. Memory Barriers: Implicitly, barriers are used in condition variable wait and notify operations. Although not explicit in the code, these operations enforce memory synchronization.
* 4. Future and Promise: A std::promise and std::future are used to calculate and retrieve the sum of integers from 1 to 10 asynchronously. This demonstrates asynchronous task execution and data passing between threads.
* 5. Execution: All threads are joined at the end of their execution to ensure the program waits for their completion before exiting.
 */
int main() {
    std::thread threads[10];
    std::cout << "Spawning 10 threads...\n";
    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(print_id, i);

    std::cout << "10 threads ready to race...\n";
    go();

    for (auto& th : threads) th.join();

    std::vector<std::thread> counters(10);
    for (std::thread& th : counters) {
        th = std::thread(atomic_counter);
    }

    for (std::thread& th : counters) {
        th.join();
    }

    std::cout << "Counter value: " << counter << '\n';

    // Future and promise
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();
    std::thread sum_thread([&prom] { prom.set_value(compute_sum(10)); });
    std::cout << "The sum of 1 to 10 is " << fut.get() << std::endl;
    sum_thread.join();

    return 0;
}

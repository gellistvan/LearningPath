#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <random>

std::mutex log_mutex;
std::vector<std::string> log_entries;

void worker_function(int id) {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(100, 500);

    try {
        // Simulate some work by sleeping
        std::chrono::milliseconds work_time(distr(eng));
        std::cout << "Worker " << id << " is working for " << work_time.count() << " milliseconds.\n";
        std::this_thread::sleep_for(work_time);

        // Log when done
        std::lock_guard<std::mutex> lock(log_mutex);
        log_entries.push_back("Worker " + std::to_string(id) + " has completed work.");
    } catch (...) {
        std::lock_guard<std::mutex> lock(log_mutex);
        log_entries.push_back("Worker " + std::to_string(id) + " has encountered an exception.");
    }
}

int main() {
    std::vector<std::thread> workers;

    // Launch a group of workers
    for (int i = 0; i < 5; ++i) {
        workers.emplace_back(worker_function, i);
    }

    // Join all threads with the main thread
    for (auto &worker : workers) {
        worker.join();
    }

    // Output the log entries
    for (const auto& entry : log_entries) {
        std::cout << entry << '\n';
    }

    return 0;
}

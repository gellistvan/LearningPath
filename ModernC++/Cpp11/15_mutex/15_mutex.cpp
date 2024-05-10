#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <condition_variable>

std::mutex mtx;
std::recursive_mutex rec_mtx;
std::timed_mutex timed_mtx;
std::recursive_timed_mutex rec_timed_mtx;
std::condition_variable cond_var;
bool ready = false;
bool processed = false;

void worker(int id) {
    // Using std::lock_guard with std::mutex
    {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Worker " << id << " is processing data." << std::endl;
    } // mtx is automatically released here

    // Using std::recursive_mutex
    {
        std::lock(rec_mtx);
        std::lock(rec_mtx); // Recursive lock
        std::cout << "Worker " << id << " has entered recursive section." << std::endl;
        rec_mtx.unlock();
        rec_mtx.unlock();
    }

    // Using std::timed_mutex with std::unique_lock
    std::unique_lock<std::timed_mutex> timed_lock(timed_mtx, std::chrono::seconds(1));
    if (timed_lock.owns_lock()) {
        std::cout << "Worker " << id << " got the timed_mutex." << std::endl;
    } else {
        std::cout << "Worker " << id << " could not get the timed_mutex." << std::endl;
    }

    // Using std::recursive_timed_mutex
    if (rec_timed_mtx.try_lock_for(std::chrono::milliseconds(500))) {
        std::cout << "Worker " << id << " acquired recursive_timed_mutex." << std::endl;
        rec_timed_mtx.unlock();
    } else {
        std::cout << "Worker " << id << " could not acquire recursive_timed_mutex." << std::endl;
    }

    // Notify the condition variable
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
        std::cout << "Worker " << id << " signals data ready for processing." << std::endl;
    }
    cond_var.notify_one();
}

void data_processor() {
    std::unique_lock<std::mutex> ulock(mtx);
    cond_var.wait(ulock, []{ return ready; });

    std::cout << "Processing shared data." << std::endl;
    processed = true;
}

int main() {
    std::thread t1(worker, 1);
    std::thread t2(worker, 2);
    std::thread t3(data_processor);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

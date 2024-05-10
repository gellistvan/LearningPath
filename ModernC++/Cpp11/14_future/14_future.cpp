#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <vector>

// Function that simulates a long-running task
int longComputation(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    return x * x;
}

// Function to demonstrate std::async and std::future
void asyncExample() {
    // Start an asynchronous task
    auto future = std::async(std::launch::async, longComputation, 10);

    // Do other work here if needed

    // Wait for the result
    int result = future.get();
    std::cout << "Result of longComputation: " << result << std::endl;
}

// Function that uses std::promise to send a result from one thread to another
void promiseExample() {
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::thread workerThread([&promise]() {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
        promise.set_value(42); // Send result to the future
    });

    // Get the result from the future
    std::cout << "Promise delivered: " << future.get() << std::endl;

    workerThread.join(); // Always join your threads!
}

// Function to demonstrate the use of std::shared_future
void sharedFutureExample() {
    std::promise<int> promise;
    std::shared_future<int> future = promise.get_future().share();

    // Create a few threads that will use the shared_future
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; ++i) {
        threads.push_back(std::thread([i, &future]() {
            // Each thread waits for the result independently
            std::cout << "Thread " << i << " received: " << future.get() << std::endl;
        }));
    }

    // Set the value in the promise
    promise.set_value(99);

    // Join all threads
    for (auto& th : threads) {
        th.join();
    }
}

int main() {
    std::cout << "Async Example:" << std::endl;
    asyncExample();

    std::cout << "\nPromise Example:" << std::endl;
    promiseExample();

    std::cout << "\nShared Future Example:" << std::endl;
    sharedFutureExample();

    return 0;
}

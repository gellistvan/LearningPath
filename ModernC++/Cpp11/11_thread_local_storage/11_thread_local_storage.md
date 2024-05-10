Thread-local storage (TLS) in C++11 is a feature that allows variables to be created such that there is a separate instance of the variable for each thread. This means that each thread has its own individual copy of a variable, and changes made to the variable in one thread do not affect its value in another thread. This feature is particularly useful for writing thread-safe applications without relying on synchronization mechanisms like mutexes to prevent data races.

In C++11, you can declare thread-local variables using the `thread_local` keyword. This keyword can be applied to variables at namespace scope, at block scope, as well as to static class members. Here's a basic example of how to use `thread_local`:

```cpp
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
```

In this example:
- `counter` is declared with `thread_local`, which means each thread starts with its own copy of `counter` initialized to 0.
- Three different threads (t1, t2, t3) are created and each executes the `incrementCounter` function. The output will show that each thread sees `counter` incrementing independently from an initial value of 0.

Using `thread_local` variables is a powerful way to maintain thread-specific data without the need for complex and potentially costly synchronization, thus aiding in writing efficient multithreaded programs.
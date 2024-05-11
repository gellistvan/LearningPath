The `std::uninitialized_copy_n` function in C++11 is part of the `<memory>` header and is used to copy a certain number of elements into a block of uninitialized memory. It constructs the objects in-place, directly in the raw storage pointed to by the destination iterator, using the copy constructor of the objects. This is particularly useful when dealing with performance-critical applications where it is beneficial to separate memory allocation from object construction.

### Description of `std::uninitialized_copy_n`

`std::uninitialized_copy_n` takes three arguments: a starting iterator for the source range, the number of elements to copy, and a starting iterator for the destination range. The function copies the specified number of elements from the source to the destination, without requiring that the destination range is already initialized.

### Prototype
```cpp
template< class InputIt, class Size, class ForwardIt >
ForwardIt uninitialized_copy_n( InputIt first, Size count, ForwardIt d_first );
```

### Parameters
- **first**: Input iterator to the initial position in the source sequence.
- **count**: The number of elements to copy.
- **d_first**: Forward iterator to the initial position in the uninitialized destination sequence.

### Example: Copying a Sequence of Structs to Uninitialized Memory

Consider a scenario where we need to manage a sequence of `Event` structs. This might be used in an application that processes or logs events, where efficient memory usage is crucial.

```cpp
#include <iostream>
#include <memory> // For std::uninitialized_copy_n and allocators
#include <vector>
#include <cstring> // For std::strlen

class Event {
public:
    char* message;
    int id;

    Event(const char* msg, int id) : id(id) {
        message = new char[std::strlen(msg) + 1];
        std::strcpy(message, msg);
    }

    ~Event() {
        delete[] message;
    }

    // Copy constructor
    Event(const Event& other) : id(other.id) {
        message = new char[std::strlen(other.message) + 1];
        std::strcpy(message, other.message);
    }

    // Overload << to output Event data
    friend std::ostream& operator<<(std::ostream& os, const Event& event) {
        os << "Event ID: " << event.id << ", Message: " << event.message;
        return os;
    }
};

int main() {
    std::vector<Event> events = {
        Event("Event 1 occurred", 1),
        Event("Event 2 occurred", 2),
        Event("Event 3 occurred", 3)
    };

    // Allocator for Event
    std::allocator<Event> alloc;

    // Allocate raw memory for three events
    Event* raw_memory = alloc.allocate(events.size());

    try {
        // Copy events to uninitialized memory
        std::uninitialized_copy_n(events.begin(), events.size(), raw_memory);
    } catch (...) {
        alloc.deallocate(raw_memory, events.size());  // Clean up in case of an exception
        throw;
    }

    // Print the copied events
    for (size_t i = 0; i < events.size(); ++i) {
        std::cout << raw_memory[i] << std::endl;
    }

    // Manually call destructor for each element in the raw array
    for (size_t i = 0; i < events.size(); ++i) {
        raw_memory[i].~Event();
    }

    // Deallocate memory
    alloc.deallocate(raw_memory, events.size());

    return 0;
}
```

### Explanation

1. **Class Definition**: A simple `Event` class is created that includes dynamic memory allocation for a message.
2. **Vector of Events**: A vector of `Event` objects is initialized.
3. **Memory Allocation**: Raw, uninitialized memory is allocated using `std::allocator<Event>`.
4. **Copying**: The `std::uninitialized_copy_n` function is used to copy the `Event` objects from the vector to the raw memory. This directly constructs the `Event` objects in the uninitialized memory.
5. **Manual Cleanup**: After use, the destructor for each `Event` in the raw memory must be manually called, followed by memory deallocation.

This example showcases how `std::uninitialized_copy_n` can be used to efficiently manage memory by separating allocation from construction, which is useful in contexts that require optimization of both performance and memory usage.
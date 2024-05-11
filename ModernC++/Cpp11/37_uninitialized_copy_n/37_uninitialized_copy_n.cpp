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

#include <iostream>
#include <vector>
#include <algorithm>

class Task {
public:
    int priority;
    std::string description;

    Task(int priority, std::string description) : priority(priority), description(description) {}

    bool operator<(const Task& other) const {
        return priority < other.priority; // Defines max-heap on priority
    }

    void display() const {
        std::cout << "Task: " << description << " with priority " << priority << std::endl;
    }
};

int main() {
    std::vector<Task> tasks {
        {3, "Complete end-of-day reports"},
        {5, "Handle urgent ticket"},
        {1, "Check emails"},
        {4, "Prepare for meeting"}
    };

    // Make a heap from the vector
    std::make_heap(tasks.begin(), tasks.end());

    // Verify if the vector is a heap
    bool isHeap = std::is_heap(tasks.begin(), tasks.end());
    std::cout << "The tasks form a heap: " << (isHeap ? "Yes" : "No") << std::endl;

    // Add a new task and adjust the heap
    tasks.push_back({2, "Update project status"});
    std::push_heap(tasks.begin(), tasks.end());

    // Display tasks
    std::cout << "Tasks after adding and re-heapifying:" << std::endl;
    for (const Task& t : tasks) {
        t.display();
    }

    // Find where the heap property is violated, if at all
    auto heapEnd = std::is_heap_until(tasks.begin(), tasks.end());
    if (heapEnd != tasks.end()) {
        std::cout << "Heap property is violated at: ";
        heapEnd->display();
    } else {
        std::cout << "The entire range maintains the heap property." << std::endl;
    }

    return 0;
}

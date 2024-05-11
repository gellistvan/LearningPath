In C++11, the Standard Library includes functions such as `std::is_heap` and `std::is_heap_until` which are part of the `<algorithm>` header. These functions are particularly useful for working with heaps, which are a type of data structure that allows for fast retrieval of the largest (or smallest, depending on the configuration) element.

### Description

1. **`std::is_heap`**:
   - **Purpose**: Checks whether a range of elements forms a max-heap, meaning that each parent node is greater than or equal to its child nodes.
   - **Usage**: Useful for asserting the integrity of heap data structures before performing heap operations such as `push_heap`, `pop_heap`, or `sort_heap`.

2. **`std::is_heap_until`**:
   - **Purpose**: Finds the point in the range up to which the elements form a max-heap. It returns an iterator to the first element that is not in a heap relationship with its children.
   - **Usage**: Useful for diagnosing where a sequence fails to meet heap conditions, which can help in debugging or adjusting algorithms that manipulate heaps.

### Complex Example: Priority Task Management System

Imagine a system where tasks are managed based on their priority. Tasks are stored in a vector and should be processed according to a priority rule where higher numbers indicate higher priority. The heap functions can be used to ensure and diagnose the structure of this task prioritization.

### Implementation

Here's how you could implement these algorithms in a practical scenario:

```cpp
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
```

### Key Points

- **Task Management**: Tasks are handled based on their priority, with a heap ensuring that the task with the highest priority can be processed first.
- **Heap Verification**: `std::is_heap` is used to check the heap condition after creating it and before performing heap operations.
- **Heap Integrity Check**: `std::is_heap_until` is used to verify up to where in the tasks list the heap condition is maintained, particularly useful after modifications like adding new tasks.

This example shows how `std::is_heap` and `std::is_heap_until` can be applied in real-world scenarios where priority-based task management is required, ensuring data integrity and efficient processing.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::move and std::move_backward

class Task {
public:
    std::string description;
    std::vector<std::string> tags;

    Task(const std::string& desc) : description(desc) {}
    Task(Task&& other) noexcept : description(std::move(other.description)), tags(std::move(other.tags)) {}
    Task& operator=(Task&& other) noexcept {
        if (this != &other) {
            description = std::move(other.description);
            tags = std::move(other.tags);
        }
        return *this;
    }

    // Adding tasks is not trivially copyable, disable copy operations
    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;

    void addTag(const std::string& tag) {
        tags.push_back(tag);
    }

    void display() const {
        std::cout << "Task: " << description << "\nTags: ";
        for (const auto& tag : tags) {
            std::cout << tag << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    std::vector<Task> tasks;
    tasks.emplace_back("Fix login bug");
    tasks.back().addTag("bugfix");
    tasks.back().addTag("urgent");
    tasks.emplace_back("Write user documentation");
    tasks.back().addTag("documentation");

    // We need to move the last task to the front
    std::cout << "Before move:\n";
    for (const auto& task : tasks) task.display();

    // Move the last task to the front using std::move_backward
    std::move_backward(tasks.begin(), tasks.end() - 1, tasks.end());
    tasks.front() = std::move(tasks.back()); // Move-assign the last element to the front
    tasks.pop_back(); // Remove the now-empty last element

    std::cout << "\nAfter move:\n";
    for (const auto& task : tasks) task.display();

    return 0;
}

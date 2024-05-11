#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Employee {
public:
    std::string name;
    int id;
    bool isActive;

    Employee(std::string name, int id, bool isActive)
        : name(name), id(id), isActive(isActive) {}
};

int main() {
    std::vector<Employee> employees {
        Employee("Alice", 1, true),
        Employee("Bob", 2, false),
        Employee("Charlie", 3, true),
        Employee("David", 4, false),
        Employee("Eve", 5, true)
    };

    // Find the first inactive employee
    auto it = std::find_if_not(employees.begin(), employees.end(), [](const Employee& e) {
        return e.isActive;
    });
    if (it != employees.end()) {
        std::cout << "First inactive employee: " << it->name << std::endl;
    } else {
        std::cout << "All employees are active." << std::endl;
    }

    // Copy active employees to a new vector
    std::vector<Employee> activeEmployees;
    std::copy_if(employees.begin(), employees.end(), std::back_inserter(activeEmployees), [](const Employee& e) {
        return e.isActive;
    });

    // Display active employees
    std::cout << "Active employees:" << std::endl;
    for (const auto& emp : activeEmployees) {
        std::cout << emp.name << std::endl;
    }

    // Copy first 3 employees to another vector
    std::vector<Employee> firstThree;
    std::copy_n(employees.begin(), 3, std::back_inserter(firstThree));

    // Display first three employees
    std::cout << "First three employees:" << std::endl;
    for (const auto& emp : firstThree) {
        std::cout << emp.name << std::endl;
    }

    return 0;
}

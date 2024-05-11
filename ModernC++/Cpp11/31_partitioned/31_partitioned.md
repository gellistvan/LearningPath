In C++11, the Standard Library provides several algorithms for partitioning containers based on a predicate. These functions, `std::is_partitioned`, `std::partition_copy`, and `std::partition_point`, are incredibly useful for organizing and processing collections according to specific conditions.

### Description

1. **`std::is_partitioned`**:
   - **Purpose**: Checks whether a range is partitioned according to a predicate, i.e., all elements that satisfy the predicate precede those that do not.
   - **Usage**: Useful for validating whether data is already sorted or grouped according to a condition, which can be important before applying certain algorithms that assume a partitioned range.

2. **`std::partition_copy`**:
   - **Purpose**: Copies elements of a range into two different containers based on a predicate.
   - **Usage**: Ideal for separating data into two categories without altering the original container, often used in data processing or filtering scenarios.

3. **`std::partition_point`**:
   - **Purpose**: Given a range that is already partitioned, it finds the point that divides the elements that satisfy a predicate from those that do not.
   - **Usage**: Useful for quickly finding the boundary in a partitioned range, similar to binary search but for partitioned data.

### Complex Example: Managing a Database of Students

Let's create a scenario where you manage a database of students. You need to separate students into those who are eligible for a scholarship based on their grades and those who are not, and you want to analyze and process these groups separately.

### Implementation

Here’s how you might implement these algorithms in a practical scenario:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Student {
public:
    std::string name;
    double gpa;

    Student(std::string n, double g) : name(n), gpa(g) {}

    // Display student information
    void display() const {
        std::cout << name << ", GPA: " << gpa << std::endl;
    }
};

int main() {
    std::vector<Student> students {
        {"Alice", 3.8},
        {"Bob", 2.5},
        {"Charlie", 3.5},
        {"David", 3.0},
        {"Eve", 2.3}
    };

    // Predicate for scholarship eligibility
    auto isEligibleForScholarship = [](const Student& s) {
        return s.gpa >= 3.5;
    };

    // Check if the list is already partitioned
    bool alreadyPartitioned = std::is_partitioned(students.begin(), students.end(), isEligibleForScholarship);
    std::cout << "Students are already partitioned according to eligibility: " << (alreadyPartitioned ? "Yes" : "No") << std::endl;

    // Partition and copy into two separate lists
    std::vector<Student> eligible, notEligible;
    std::partition_copy(students.begin(), students.end(), std::back_inserter(eligible), std::back_inserter(notEligible), isEligibleForScholarship);

    std::cout << "\nEligible for Scholarship:" << std::endl;
    for (const auto& student : eligible) {
        student.display();
    }

    std::cout << "\nNot Eligible for Scholarship:" << std::endl;
    for (const auto& student : notEligible) {
        student.display();
    }

    // Ensure the vector is partitioned for using partition_point
    std::partition(students.begin(), students.end(), isEligibleForScholarship);

    // Find the partition point
    auto partitionIt = std::partition_point(students.begin(), students.end(), isEligibleForScholarship);
    std::cout << "\nFirst not eligible student in the partitioned list:" << std::endl;
    if (partitionIt != students.end()) {
        partitionIt->display();
    }

    return 0;
}
```

### Key Points

- **`std::is_partitioned`**: Checks if the students are already sorted into those eligible and not eligible for scholarships.
- **`std::partition_copy`**: Separates students into two different lists based on their GPA, making it easy to manage different groups for different processing.
- **`std::partition_point`**: After ensuring the list is partitioned, it identifies the first student who does not meet the scholarship criteria.

This example shows how these partitioning functions can be used in a realistic application to manage and process grouped data efficiently, such as separating and handling student records based on GPA for scholarship eligibility.
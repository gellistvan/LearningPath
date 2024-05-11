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

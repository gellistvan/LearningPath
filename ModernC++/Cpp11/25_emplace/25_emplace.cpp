#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>

class ComplexObject {
public:
    std::string name;
    int value;

    // Constructor
    ComplexObject(std::string n, int v) : name(std::move(n)), value(v) {
        std::cout << "Constructed " << name << " with value " << value << std::endl;
    }

    // Copy constructor
    ComplexObject(const ComplexObject& other) : name(other.name), value(other.value) {
        std::cout << "Copied " << name << std::endl;
    }

    // Move constructor
    ComplexObject(ComplexObject&& other) noexcept : name(std::move(other.name)), value(other.value) {
        std::cout << "Moved " << name << std::endl;
    }

    bool operator<(const ComplexObject& other) const {
        return value < other.value;
    }
};

int main() {
    std::vector<ComplexObject> vec;
    std::set<ComplexObject> s;
    std::map<int, ComplexObject> m;
    std::unordered_map<int, ComplexObject> um;

    std::cout << "Using emplace_back for vector:\n";
    vec.emplace_back("ObjectA", 10);

    std::cout << "\nUsing insert for set:\n";
    s.emplace("ObjectB", 20);

    std::cout << "\nUsing emplace for map:\n";
    m.emplace(1, ComplexObject("ObjectC", 30));

    std::cout << "\nUsing emplace for unordered_map:\n";
    um.emplace(std::piecewise_construct,
               std::forward_as_tuple(2),
               std::forward_as_tuple("ObjectD", 40));

    return 0;
}

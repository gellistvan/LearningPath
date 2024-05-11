The `emplace` function is a powerful tool provided by C++ STL containers which constructs elements in-place, potentially saving overhead caused by temporary objects and extra copies. This method can be used instead of `insert` or `push` to optimize performance, particularly when dealing with complex data structures.

Below is an example that demonstrates the usage of `emplace` in various STL containers (`vector`, `set`, `map`, and `unordered_map`) and contrasts it with conventional methods like `push_back` and `insert`. The example focuses on creating a complex object (a pair in the case of associative containers and a simple object in the case of sequence containers) and shows how `emplace` can be advantageous by reducing unnecessary copying.

### Example Code

```cpp
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
    std::set<ComplexProject> s;
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
```

### Explanation
- **Vector**: `emplace_back` constructs the object directly in the memory allocated by the vector, avoiding an extra copy or move that `push_back` would involve if passing a temporary object.
- **Set**: `emplace` directly constructs the object in the set, which is especially useful because sets often involve many repositionings due to their sorting nature.
- **Map and Unordered Map**: `emplace` in maps uses `std::piecewise_construct` to construct the pair directly in the container, optimizing the creation of the `pair` key-value objects.

This example illustrates how using `emplace` and `emplace_back` can lead to fewer constructions and copies/moves of objects, leading to more efficient code, particularly when objects are complex or expensive to move.
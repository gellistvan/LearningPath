#include <iostream>
#include <string>
#include <new> // For placement new

union Storage {
    std::string str;  // Non-trivial type
    int number;

    // Constructor
    Storage() {
        new(&str) std::string;  // Construct a string in the union using placement new
    }

    // Destructor
    ~Storage() {
        str.~basic_string();  // Explicitly call the destructor for the string
    }
};

int main() {
    Storage s;
    s.str = "Hello, Union!";
    std::cout << "Stored string: " << s.str << std::endl;

    // Must manually destroy the string before reusing the storage for another type
    s.str.~basic_string();

    // Placement new to use the same memory for an int
    new(&s.number) int(42);
    std::cout << "Stored number: " << s.number << std::endl;

    return 0;
}

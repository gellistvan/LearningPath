#include <iostream>
#include <tuple>
#include <string>
#include <vector>

// Function to create and return a tuple
std::tuple<int, double, std::string> createTuple() {
    return std::make_tuple(42, 3.14159, "Hello, World!");
}

// Utility function to print the contents of a tuple
void printTuple(const std::tuple<int, double, std::string>& t) {
    // Accessing elements using std::get
    std::cout << "Integer: " << std::get<0>(t) << std::endl;
    std::cout << "Double: " << std::get<1>(t) << std::endl;
    std::cout << "String: " << std::get<2>(t) << std::endl;
}

int main() {
    // Creating a tuple using the createTuple function
    auto myTuple = createTuple();

    // Print the tuple
    printTuple(myTuple);

    // Unpacking tuple using std::tie
    int myInt;
    double myDouble;
    std::string myString;
    std::tie(myInt, myDouble, myString) = myTuple;

    std::cout << "Unpacked Values: " << myInt << ", " << myDouble << ", \"" << myString << "\"" << std::endl;

    // Using std::tuple_size to get the number of elements in the tuple
    std::cout << "The tuple has " << std::tuple_size<decltype(myTuple)>::value << " elements." << std::endl;

    return 0;
}

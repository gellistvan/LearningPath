#include <iostream>
#include <string>

// Recursive variadic template function to print arguments
template<typename T>
void printRecursive(T arg) {
    std::cout << arg << std::endl; // Base case for recursion
}

template<typename T, typename... Args>
void printRecursive(T firstArg, Args... args) {
    std::cout << firstArg << ' ';
    printRecursive(args...); // Recursive call
}

// C++17 fold expression to print arguments
template<typename... Args>
void printFold(Args... args) {
    (std::cout << ... << args) << '\n'; // Fold expression
}

// Variadic template class for a simple Tuple
template<typename... Values>
class Tuple; // Forward declaration

template<>
class Tuple<> { // Base case: empty tuple
public:
    Tuple() { std::cout << "Empty Tuple" << std::endl; }
};

template<typename Head, typename... Tail>
class Tuple<Head, Tail...> : public Tuple<Tail...> {
    Head head;
public:
    Tuple(Head h, Tail... t) : Tuple<Tail...>(t...), head(h) {
        std::cout << "Storing element: " << head << std::endl;
    }
};

int main() {
    std::cout << "Using Recursive Variadic Template to Print:" << std::endl;
    printRecursive(1, 2.5, "Hello", std::string("World"));

    std::cout << "\nUsing Fold Expressions to Print (C++17):" << std::endl;
    printFold(1, 2.5, "Hello", std::string("World"));

    std::cout << "\nUsing Variadic Template Class Tuple:" << std::endl;
    Tuple<int, double, std::string> myTuple(1, 3.14, "C++ Variadics");

    return 0;
}

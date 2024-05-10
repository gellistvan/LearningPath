#include <iostream>
#include <type_traits>

// Function to return a reference
int& foo(int& x) {
    return x;
}

// Template function using decltype for return type deduction
template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

int main() {
    // Example 1: Basic usage with auto and decltype
    auto x = 1;  // x is an int
    decltype(x) y = x;  // y is also an int, deduced by decltype
    std::cout << "x: " << x << ", y: " << y << std::endl;

    // Example 2: Handling references
    int g = 5;
    decltype(foo(g)) h = g;  // h is of type int& and refers to g
    h = 10;  // Modifying h will modify g
    std::cout << "g: " << g << ", h: " << h << std::endl;

    // Example 3: Using decltype in templates
    int a = 5;
    double b = 5.5;
    auto result = add(a, b);  // result is deduced to double
    std::cout << "Result of add(a, b): " << result << std::endl;

    // Check types at compile time (only for illustration, not executed)
    static_assert(std::is_same<decltype(x), int>::value, "x should be int");
    static_assert(std::is_same<decltype(h), int&>::value, "h should be int&");
    static_assert(std::is_same<decltype(result), double>::value, "result should be double");

    return 0;
}

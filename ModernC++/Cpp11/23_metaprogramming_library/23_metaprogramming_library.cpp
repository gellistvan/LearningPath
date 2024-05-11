#include <iostream>
#include <type_traits>

// A compile-time function to calculate factorial
constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

// Template metaprogramming to check and print type properties
template<typename T>
void checkTypeProperties() {
    if (std::is_integral<T>::value) {
        std::cout << "Type is integral.\n";
    } else if (std::is_floating_point<T>::value) {
        std::cout << "Type is floating point.\n";
    } else {
        std::cout << "Type is something else.\n";
    }

    // Check if the type is const-qualified
    if (std::is_const<T>::value) {
        std::cout << "Type is const.\n";
    } else {
        std::cout << "Type is not const.\n";
    }
}

// Example using templates and type traits
template<typename T>
T computeValue(T value) {
    // Compile-time check: ensures T is an arithmetic type
    static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type.");

    return value * value;
}

int main() {
    // Demonstrating constexpr
    constexpr int val = factorial(5);
    std::cout << "Factorial of 5 computed at compile-time: " << val << std::endl;

    // Type traits usage
    std::cout << "Checking type properties for int:\n";
    checkTypeProperties<int>();

    std::cout << "Checking type properties for const double:\n";
    checkTypeProperties<const double>();

    // Template and type trait for computation
    std::cout << "Square of 4: " << computeValue(4) << std::endl;
    std::cout << "Square of 3.5: " << computeValue(3.5) << std::endl;

    return 0;
}

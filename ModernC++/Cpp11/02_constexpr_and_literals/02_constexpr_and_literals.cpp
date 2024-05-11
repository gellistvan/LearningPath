#include <iostream>
#include <cmath>

// constexpr variable
constexpr int max_size = 50;

// constexpr function to calculate factorial
constexpr int factorial(int n) {
    return n <= 1 ? 1 : (n * factorial(n - 1));
}

// Literal type with a constexpr constructor
struct Point {
    double x, y;

    constexpr Point(double x, double y) : x(x), y(y) {}

    // constexpr member function to calculate distance from origin
    constexpr double distanceFromOrigin() const {
        return sqrt(x*x + y*y);
    }
};

int main() {
    // Using constexpr variable as array size
    int arr[max_size];

    // Using constexpr function at compile time
    constexpr int fac_10 = factorial(10);
    std::cout << "Factorial of 10 is " << fac_10 << std::endl;

    // Using constexpr to create Point objects at compile time
    constexpr Point origin(0.0, 0.0);
    constexpr Point p(3.0, 4.0);

    // Output the points and distances
    std::cout << "Point origin is at (" << origin.x << ", " << origin.y << ")" << std::endl;
    std::cout << "Point p is at (" << p.x << ", " << p.y << ")" << std::endl;
    std::cout << "Distance of p from origin is " << p.distanceFromOrigin() << std::endl;

    return 0;
}

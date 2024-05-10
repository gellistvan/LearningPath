#include <iostream>
#include <ratio>

int main() {
    // Example of creating ratios
    typedef std::ratio<2, 3> two_thirds;
    typedef std::ratio<3, 4> three_fourths;

    // Arithmetic operations
    typedef std::ratio_add<two_thirds, three_fourths>::type sum;
    typedef std::ratio_subtract<two_thirds, three_fourths>::type difference;
    typedef std::ratio_multiply<two_thirds, three_fourths>::type product;
    typedef std::ratio_divide<two_thirds, three_fourths>::type quotient;

    // Output results of arithmetic operations
    std::cout << "Sum: " << sum::num << "/" << sum::den << std::endl;
    std::cout << "Difference: " << difference::num << "/" << difference::den << std::endl;
    std::cout << "Product: " << product::num << "/" << product::den << std::endl;
    std::cout << "Quotient: " << quotient::num << "/" << quotient::den << std::endl;

    // Comparison operations
    bool less = std::ratio_less<two_thirds, three_fourths>::value;
    bool less_equal = std::ratio_less_equal<two_thirds, three_fourths>::value;
    bool greater = std::ratio_greater<two_thirds, three_fourths>::value;
    bool greater_equal = std::ratio_greater_equal<two_thirds, three_fourths>::value;
    bool equal = std::ratio_equal<two_thirds, three_fourths>::value;
    bool not_equal = std::ratio_not_equal<two_thirds, three_fourths>::value;

    // Output results of comparison operations
    std::cout << "Less: " << less << std::endl;
    std::cout << "Less Equal: " << less_equal << std::endl;
    std::cout << "Greater: " << greater << std::endl;
    std::cout << "Greater Equal: " << greater_equal << std::endl;
    std::cout << "Equal: " << equal << std::endl;
    std::cout << "Not Equal: " << not_equal << std::endl;

    // Utilizing utility types
    typedef std::kilo kilo_ratio;
    typedef std::milli milli_ratio;

    // Output utility type ratios
    std::cout << "Kilo: " << kilo_ratio::num << "/" << kilo_ratio::den << std::endl;
    std::cout << "Milli: " << milli_ratio::num << "/" << milli_ratio::den << std::endl;

    return 0;
}

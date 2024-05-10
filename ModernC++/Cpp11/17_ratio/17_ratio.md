The `<ratio>` header in C++ is a part of the C++ Standard Library introduced in C++11, providing a way to deal with rational numbers at compile-time. This header mainly defines a template class and several utility functions that make it easier to perform calculations and comparisons with rational numbers. Here’s a detailed overview of its contents:

### 1. `std::ratio` Class Template
The core component of the `<ratio>` header is the `std::ratio` class template. It represents a compile-time, constant rational number where the numerator and denominator are provided as template arguments. The class defines two member types and uses static constants:
- **Numerator (`num`)**: A `static const` member of type `std::intmax_t` that represents the numerator of the ratio.
- **Denominator (`den`)**: A `static const` member of type `std::intmax_t` that represents the denominator of the ratio.

The `std::ratio` class automatically reduces the fraction to its simplest form. For example, `std::ratio<4, 6>` is simplified to `std::ratio<2, 3>` at compile time.

### 2. Arithmetic Operations
The `<ratio>` header defines several metafunctions for performing compile-time arithmetic on ratios:
- **Addition (`std::ratio_add`)**: Adds two `std::ratio` instances.
- **Subtraction (`std::ratio_subtract`)**: Subtracts one `std::ratio` instance from another.
- **Multiplication (`std::ratio_multiply`)**: Multiplies two `std::ratio` instances.
- **Division (`std::ratio_divide`)**: Divides one `std::ratio` instance by another.

Each of these operations results in a new `std::ratio` type that represents the result of the arithmetic operation.

### 3. Comparison Operations
The header also includes metafunctions for comparing two `std::ratio` instances:
- **Less (`std::ratio_less`)**: Returns `true` if the first ratio is less than the second, else `false`.
- **Less equal (`std::ratio_less_equal`)**: Returns `true` if the first ratio is less than or equal to the second, else `false`.
- **Greater (`std::ratio_greater`)**: Returns `true` if the first ratio is greater than the second, else `false`.
- **Greater equal (`std::ratio_greater_equal`)**: Returns `true` if the first ratio is greater than or equal to the second, else `false`.
- **Equal (`std::ratio_equal`)**: Returns `true` if the two ratios are equal, else `false`.
- **Not equal (`std::ratio_not_equal`)**: Returns `true` if the two ratios are not equal, else `false`.

### 4. Utility Types
The header defines several common ratio types for convenience:
- **`std::atto`**: Represents the ratio \(10^{-18}\).
- **`std::femto`**: Represents the ratio \(10^{-15}\).
- **`std::pico`**: Represents the ratio \(10^{-12}\).
- **`std::nano`**: Represents the ratio \(10^{-9}\).
- **`std::micro`**: Represents the ratio \(10^{-6}\).
- **`std::milli`**: Represents the ratio \(10^{-3}\).
- **`std::centi`**: Represents the ratio \(10^{-2}\).
- **`std::deci`**: Represents the ratio \(10^{-1}\).
- **`std::deca`**: Represents the ratio \(10^1\).
- **`std::hecto`**: Represents the ratio \(10^2\).
- **`std::kilo`**: Represents the ratio \(10^3\).
- **`std::mega`**: Represents the ratio \(10^6\).
- **`std::giga`**: Represents the ratio \(10^9\).
- **`std::tera`**: Represents the ratio \(10^{12}\).
- **`std::peta`**: Represents the ratio \(10^{15}\).
- **`std::exa`**: Represents the ratio \(10^{18}\).

These types make it easier to express commonly used scales and proportions in a type-safe way, aiding in both compile-time calculations and readability.

The `<ratio>` header is a powerful tool for handling ratios and performing precise mathematical computations at compile time, ensuring accuracy and efficiency in templated code.
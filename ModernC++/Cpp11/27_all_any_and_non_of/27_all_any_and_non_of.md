The C++11 standard introduced several convenient algorithms for checking properties on collections: `std::all_of`, `std::any_of`, and `std::none_of`. These functions are found in the `<algorithm>` header and provide a simple way to perform common conditional checks on ranges in a concise manner.

### Description

1. **`std::all_of`**:
   - **Purpose**: Checks if a predicate is true for all elements in a given range.
   - **Usage**: Useful when you need to verify that every element in a range satisfies a particular condition.

2. **`std::any_of`**:
   - **Purpose**: Checks if a predicate is true for at least one element in the range.
   - **Usage**: Useful for determining if there is at least one element in a range that meets a specific criterion.

3. **`std::none_of`**:
   - **Purpose**: Checks if a predicate is false for all elements in the range.
   - **Usage**: Useful for verifying that no elements in a range satisfy a certain condition.

### Example Usage

Suppose you have a collection of integers and you want to perform various checks to see if they meet certain conditions. Here is how you might use `std::all_of`, `std::any_of`, and `std::none_of`:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> data {1, 2, 3, 4, 5, 6};

    // Check if all elements are greater than 0
    bool allPositive = std::all_of(data.begin(), data.end(), [](int x) { return x > 0; });
    std::cout << "All elements are positive: " << (allPositive ? "Yes" : "No") << std::endl;

    // Check if any element is a multiple of 4
    bool anyMultipleOfFour = std::any_of(data.begin(), data.end(), [](int x) { return x % 4 == 0; });
    std::cout << "Any element is a multiple of 4: " << (anyMultipleOfFour ? "Yes" : "No") << std::endl;

    // Check if none of the elements are negative
    bool noneNegative = std::none_of(data.begin(), data.end(), [](int x) { return x < 0; });
    std::cout << "No negative elements: " << (noneNegative ? "Yes" : "No") << std::endl;

    return 0;
}
```

### Key Points
- These functions require two iterators (defining the range) and a predicate function that returns a `bool`. The predicate is applied to each element of the container.
- Lambda functions are commonly used as predicates, but you can also use regular functions or functors.
- These algorithms are part of the `<algorithm>` library, which provides a rich set of operations for standard containers.

This example demonstrates the utility of these algorithms for making concise and readable checks on data within containers, enhancing both code clarity and maintainability.
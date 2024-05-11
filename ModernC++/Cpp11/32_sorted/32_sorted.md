In C++11, the Standard Library introduced functions such as `std::is_sorted` and `std::is_sorted_until` to help work with sorted ranges. These functions are used to check the ordering of elements in containers and can be incredibly useful in verifying data integrity or preparing data for algorithms that require sorted input.

### Description

1. **`std::is_sorted`**:
   - **Purpose**: Determines if the elements in a range are sorted according to a comparator.
   - **Usage**: Useful for assertions and pre-condition checks in functions that operate on sorted data. Ensuring data is sorted before applying binary search algorithms, for example, is a common use case.

2. **`std::is_sorted_until`**:
   - **Purpose**: Identifies the point in a range up to which the elements are sorted, returning an iterator to the first element that does not continue the sort order.
   - **Usage**: Useful for diagnostics to find where a data set fails to be sorted and might need intervention or further sorting.

### Complex Example: Managing a Product Inventory

Consider a scenario where you manage an inventory of products. Each product has a unique ID and a price. For various operations like searching or pricing analytics, it's beneficial to have your inventory sorted by product ID or price. Let’s demonstrate how you can use `std::is_sorted` and `std::is_sorted_until` to ensure your inventory is appropriately managed.

### Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Product {
public:
    int id;
    double price;

    Product(int id, double price) : id(id), price(price) {}

    // Display product information
    void display() const {
        std::cout << "Product ID: " << id << " Price: $" << price << std::endl;
    }
};

int main() {
    std::vector<Product> inventory {
        {101, 19.99},
        {102, 24.99},
        {103, 22.50},
        {105, 9.99},
        {104, 14.99}
    };

    // Sort inventory by product ID
    std::sort(inventory.begin(), inventory.end(), [](const Product& a, const Product& b) {
        return a.id < b.id;
    });

    // Check if the inventory is sorted by ID
    bool sortedById = std::is_sorted(inventory.begin(), inventory.end(), [](const Product& a, const Product& b) {
        return a.id < b.id;
    });
    std::cout << "Inventory sorted by ID: " << (sortedById ? "Yes" : "No") << std::endl;

    // Find until which point the inventory is sorted by price
    auto it = std::is_sorted_until(inventory.begin(), inventory.end(), [](const Product& a, const Product& b) {
        return a.price < b.price;
    });

    std::cout << "Inventory sorted by price until:" << std::endl;
    if (it != inventory.end()) {
        it->display();
    } else {
        std::cout << "All inventory is sorted by price." << std::endl;
    }

    return 0;
}
```

### Key Points

- **Sorting and Checking**: First, the inventory is sorted by product ID using `std::sort`. Then, `std::is_sorted` checks if the sorting was successful.
- **Diagnostic Check**: `std::is_sorted_until` is used to determine how the inventory is sorted by price. It provides insight into whether the sorting criteria are met throughout the collection or if further action is needed.

This example shows how you can manage and verify sorting within a product inventory, ensuring that operations dependent on sorted data (like binary search or data segmentation) can be performed reliably. Such functionality is crucial in business applications where data integrity and order are essential for performance and correctness.
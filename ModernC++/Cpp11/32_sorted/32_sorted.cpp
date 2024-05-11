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

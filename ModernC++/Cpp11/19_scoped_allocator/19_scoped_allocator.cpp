#include <iostream>
#include <vector>
#include <list>
#include <scoped_allocator>
#include <memory>

// Define a type alias for the innermost vector that uses a custom allocator
using InnerVector = std::vector<int, std::allocator<int>>;

// Define a type alias for the list that uses a scoped_allocator,
// which itself contains the InnerVector using the same allocator type
using AllocatorList = std::scoped_allocator_adaptor<std::allocator<InnerVector>>;
using MiddleList = std::list<InnerVector, AllocatorList>;

// Define the outermost vector, which will also use a scoped_allocator.
// This allocator will propagate to the MiddleList and InnerVector
using AllocatorVector = std::scoped_allocator_adaptor<std::allocator<MiddleList>>;
using OuterVector = std::vector<MiddleList, AllocatorVector>;

int main() {
    // Create an instance of the outermost vector with initial size of 2
    OuterVector outerVector(2, AllocatorVector(AllocatorList()));

    // Populate the outerVector with some data
    int counter = 0;
    for (auto& middleList : outerVector) {
        for (int i = 0; i < 3; ++i) {
            middleList.emplace_back(InnerVector());
            for (int j = 0; j < 4; ++j) {
                middleList.back().push_back(counter++);
            }
        }
    }

    // Print the data structure
    for (const auto& middleList : outerVector) {
        for (const auto& innerVector : middleList) {
            for (int num : innerVector) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "----" << std::endl;
    }

    return 0;
}

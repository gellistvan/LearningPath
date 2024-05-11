#include <cstdlib>
#include <memory>
#include <iostream>
#include <vector>
#include <list>
#include <scoped_allocator>

template <typename T>
class MemoryPoolAllocator {
public:
    using value_type = T;

    MemoryPoolAllocator() noexcept {}

    template <typename U>
    MemoryPoolAllocator(const MemoryPoolAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        std::cout << "Allocating " << n << " objects." << std::endl;
        return static_cast<T*>(std::malloc(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t n) {
        std::cout << "Deallocating " << n << " objects." << std::endl;
        std::free(p);
    }
};

template <typename T, typename U>
bool operator==(const MemoryPoolAllocator<T>&, const MemoryPoolAllocator<U>&) { return true; }

template <typename T, typename U>
bool operator!=(const MemoryPoolAllocator<T>&, const MemoryPoolAllocator<U>&) { return false; }

int main() {
    using InnerVector = std::vector<int, MemoryPoolAllocator<int>>;
    using MiddleList = std::list<InnerVector, std::scoped_allocator_adaptor<MemoryPoolAllocator<InnerVector>>>;
    using OuterVector = std::vector<MiddleList,  std::scoped_allocator_adaptor<MemoryPoolAllocator<MiddleList>>>;

    OuterVector outerVector (2, (std::scoped_allocator_adaptor<MemoryPoolAllocator<MiddleList>>())); // Initialize with two middle lists

    int counter = 0;
    for (auto& middleList : outerVector) {
        for (int i = 0; i < 3; ++i) {
            middleList.emplace_back(InnerVector());
            for (int j = 0; j < 4; ++j) {
                middleList.back().push_back(counter++);
            }
        }
    }

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

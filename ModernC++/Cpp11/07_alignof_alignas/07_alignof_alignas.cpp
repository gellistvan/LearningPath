#include <iostream>
#include <cstddef> // For std::size_t

struct MyData {
    char a;
    int b;
    double c;
};

int main() {
    // Using alignof to query alignment requirements
    std::size_t align_char = alignof(char);
    std::size_t align_int = alignof(int);
    std::size_t align_double = alignof(double);
    std::size_t align_mydata = alignof(MyData);

    std::cout << "Alignment of char: " << align_char << std::endl;
    std::cout << "Alignment of int: " << align_int << std::endl;
    std::cout << "Alignment of double: " << align_double << std::endl;
    std::cout << "Alignment of MyData struct: " << align_mydata << std::endl;

    // Using alignas to specify alignment
    alignas(16) char buffer[128];  // Align a character buffer to 16 bytes
    alignas(std::max_align_t) MyData data; // Align to the maximum alignment of any standard type

    std::cout << "Alignment of buffer: " << alignof(buffer) << std::endl;
    std::cout << "Alignment of MyData with max_align_t: " << alignof(data) << std::endl;

    // Practical use case: aligning for SIMD operations
    alignas(32) float simd_data[8]; // Often used with SIMD operations requiring 32-byte alignment

    std::cout << "Alignment of simd_data for SIMD operations: " << alignof(simd_data) << std::endl;

    return 0;
}

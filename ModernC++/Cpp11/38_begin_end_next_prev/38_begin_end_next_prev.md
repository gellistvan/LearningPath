The functions `std::begin`, `std::end`, `std::next`, and `std::prev` introduced in C++11 are utilities that provide more generic ways to work with iterators in standard and user-defined containers. These functions are part of the `<iterator>` header and facilitate generic programming by abstracting away specific container details.

### Description of Each Function:

1. **`std::begin` and `std::end`**:
   - These functions return iterators to the beginning and the end of a container, respectively. They can be used with C-style arrays, standard containers, and even initializer lists.

2. **`std::next`**:
   - Advances an iterator by a specified number of positions in its container and returns the advanced iterator. It is useful when you want to skip certain elements in the container without modifying the original iterator.

3. **`std::prev`**:
   - Moves an iterator backwards by a specified number of positions and returns the resulting iterator. It is particularly useful in reverse iteration scenarios where you need to back up an iterator a specific number of steps.

### Example: Implementing a Simple Text Editor's Find and Replace Function

This example demonstrates how to use these iterator utilities in a typical application scenario: a simple text editor that needs to find and replace text within a document represented as a `std::list<std::string>`.

```cpp
#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>

// Function to find and replace a word in a document
void findAndReplace(std::list<std::string>& document, const std::string& oldWord, const std::string& newWord) {
    for (auto it = std::begin(document); it != std::end(document); ++it) {
        size_t pos = it->find(oldWord); // Find the oldWord in the string
        while (pos != std::string::npos) {
            it->replace(pos, oldWord.length(), newWord); // Replace oldWord with newWord
            pos = it->find(oldWord, pos + newWord.length()); // Continue finding from the next position
        }
    }
}

// Print the document
void printDocument(const std::list<std::string>& document) {
    for (const auto& line : document) {
        std::cout << line << std::endl;
    }
}

int main() {
    std::list<std::string> document = {
        "Hello world!",
        "This is a simple text editor.",
        "Hello again, world!",
        "This is another line."
    };

    std::cout << "Original Document:\n";
    printDocument(document);

    std::string oldWord = "Hello";
    std::string newWord = "Hi";

    findAndReplace(document, oldWord, newWord);

    std::cout << "\nDocument after replacement:\n";
    printDocument(document);

    return 0;
}
```

### Explanation:

1. **Document Representation**: The document is represented as a `std::list<std::string>`, where each string is a line in the document.
2. **Find and Replace**: The `findAndReplace` function iterates through each line using `std::begin` and `std::end` to access the start and end of the document list. For each line, it finds and replaces occurrences of `oldWord` with `newWord`.
3. **Printing the Document**: The `printDocument` function prints each line of the document, iterating over the list using range-based for loops, which internally use `std::begin` and `std::end`.

This example showcases the usefulness of these iterator utilities in scenarios involving text processing, making it easier to work with different types of containers in a uniform way. These functions abstract away container-specific details, enabling more flexible and maintainable code.
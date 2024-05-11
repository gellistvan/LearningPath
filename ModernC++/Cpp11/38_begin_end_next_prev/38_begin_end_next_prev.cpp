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

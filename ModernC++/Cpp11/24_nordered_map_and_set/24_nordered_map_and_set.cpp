#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    // Sample data: vector of strings
    std::vector<std::string> words = {"apple", "banana", "apple", "orange", "mango", "banana", "mango"};

    // Unordered map to count frequencies of each word
    std::unordered_map<std::string, int> freqMap;
    for (const auto& word : words) {
        ++freqMap[word];
    }

    // Unordered set to keep track of words that appear exactly once
    std::unordered_set<std::string> uniqueWords;

    // Iterate over the frequency map
    for (const auto& pair : freqMap) {
        if (pair.second == 1) {
            uniqueWords.insert(pair.first);
        }
    }

    // Move the unique words from the unordered set to a vector and sort it
    std::vector<std::string> sortedUniqueWords(uniqueWords.begin(), uniqueWords.end());
    std::sort(sortedUniqueWords.begin(), sortedUniqueWords.end());

    // Output the sorted unique words
    std::cout << "Unique words that appear exactly once:\n";
    for (const auto& word : sortedUniqueWords) {
        std::cout << word << std::endl;
    }

    return 0;
}

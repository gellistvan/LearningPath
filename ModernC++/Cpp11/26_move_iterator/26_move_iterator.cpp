#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<std::string> source {"apple", "banana", "cherry"};
    std::vector<std::string> destination;

    // Reserve enough space to avoid reallocations
    destination.reserve(source.size());

    // std::make_move_iterator creates a move iterator from a normal iterator
    std::move_iterator<std::vector<std::string>::iterator> begin(source.begin());
    std::move_iterator<std::vector<std::string>::iterator> end(source.end());

    // Use std::copy to "move" elements from source to destination
    std::copy(begin, end, std::back_inserter(destination));

    // Check the results
    std::cout << "Source (moved-from state):" << std::endl;
    for (const auto& s : source) {
        std::cout << '"' << s << "\" ";  // strings are in a valid but unspecified state
    }
    std::cout << std::endl;

    std::cout << "Destination:" << std::endl;
    for (const auto& s : destination) {
        std::cout << '"' << s << "\" ";
    }
    std::cout << std::endl;

    return 0;
}
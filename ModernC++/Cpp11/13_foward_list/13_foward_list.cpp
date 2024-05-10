#include <forward_list>
#include <iostream>

int main() {
    std::forward_list<int> flist = {10, 20, 30, 40};

    // Adding an element to the front
    flist.push_front(5);

    // Removing an element
    flist.remove(30); // Removes all elements equal to 30

    // Iterating through the list
    for (auto it = flist.begin(); it != flist.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}

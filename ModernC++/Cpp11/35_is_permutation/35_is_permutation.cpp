#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> systemA_logs = {105, 102, 101, 103, 104};
    std::vector<int> systemB_logs = {101, 102, 103, 104, 105};

    // Assuming the logs are just transaction IDs and the vectors should be permutations of each other
    if (std::is_permutation(systemA_logs.begin(), systemA_logs.end(), systemB_logs.begin())) {
        std::cout << "The transaction logs in both systems are identical in content." << std::endl;
    } else {
        std::cout << "The transaction logs differ!" << std::endl;
    }

    return 0;
}

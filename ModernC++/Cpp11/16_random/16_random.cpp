#include <iostream>
#include <random>
#include <vector>

int main() {
    // Random device for seeding
    std::random_device rd;

    // Random number engines
    std::mt19937 mt_engine(rd());  // Mersenne Twister engine
    std::minstd_rand minstd_engine(rd());  // Minimal Standard minstd_rand

    // Distributions
    std::uniform_int_distribution<int> uniform_dist(1, 100);  // Uniform integer distribution
    std::normal_distribution<double> normal_dist(5.0, 2.0);   // Normal distribution
    std::exponential_distribution<double> exp_dist(1.0);      // Exponential distribution

    // Generate and print random numbers from different distributions
    std::cout << "Uniform distribution [1,100]:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << uniform_dist(mt_engine) << " ";
    }
    std::cout << "\n\n";

    std::cout << "Normal distribution (mean=5, std dev=2):\n";
    for (int i = 0; i < 5; i++) {
        std::cout << normal_dist(mt_engine) << " ";
    }
    std::cout << "\n\n";

    std::cout << "Exponential distribution (rate=1):\n";
    for (int i = 0; i < 5; i++) {
        std::cout << exp_dist(minstd_engine) << " ";
    }
    std::cout << "\n";

    return 0;
}

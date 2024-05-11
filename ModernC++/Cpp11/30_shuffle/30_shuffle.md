`std::random_shuffle` and `std::shuffle` are two C++ algorithms used to rearrange elements in a container randomly. Both are found in the `<algorithm>` header, but they serve slightly different purposes and have different requirements regarding random number generation.

### Description

1. **`std::random_shuffle`**:
   - **Purpose**: Rearranges the elements in a range randomly using a pseudo-random number generator.
   - **Usage**: This function was deprecated in C++14 and removed in C++17 because it does not allow for the use of a better external random number generator, making its randomness potentially less useful for more demanding applications.

2. **`std::shuffle`**:
   - **Purpose**: Rearranges the elements in a range randomly using a specified uniform random number generator (URNG).
   - **Usage**: More flexible and recommended over `std::random_shuffle` for applications requiring reliable, reproducible randomness when given the same seed. Ideal for simulations, games, and other applications where controlled randomness is required.

### Complex Example: Card Game Simulation

Let's simulate part of a card game where you need to shuffle a deck of cards and deal a hand to each player. This scenario uses `std::shuffle` to ensure reproducibility of the deck's order when a specific seed is used, which is useful for debugging or reproducing game states.

### Implementation

```cpp
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>

class Card {
public:
    enum class Suit { Hearts, Diamonds, Clubs, Spades };
    enum class Rank { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

    Suit suit;
    Rank rank;

    Card(Suit s, Rank r) : suit(s), rank(r) {}

    friend std::ostream& operator<<(std::ostream& os, const Card& card) {
        const char* suit_names[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        const char* rank_names[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
        return os << rank_names[static_cast<int>(card.rank)] << " of " << suit_names[static_cast<int>(card.suit)];
    }
};

int main() {
    std::vector<Card> deck;

    // Create a standard deck of 52 cards
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 0; rank < 13; ++rank) {
            deck.emplace_back(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank));
        }
    }

    // Shuffle the deck
    std::random_device rd;  // Use a hardware entropy source if available
    std::mt19937 g(rd());  // Seed the generator
    std::shuffle(deck.begin(), deck.end(), g);

    // Print the shuffled deck
    std::cout << "Shuffled Deck:" << std::endl;
    for (const auto& card : deck) {
        std::cout << card << std::endl;
    }

    // Deal 5 cards
    std::cout << "\nHand of 5 cards:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << deck[i] << std::endl;
    }

    return 0;
}
```

### Key Points

- **Deck Creation**: The deck consists of 52 cards, representing each suit and rank combination.
- **Random Shuffle**: `std::shuffle` is used with a Mersenne Twister (`std::mt19937`), seeded by a hardware-generated random seed for high-quality random shuffling.
- **Dealing Cards**: After shuffling, the first five cards are displayed as a dealt hand.

This example demonstrates how to use `std::shuffle` to simulate real-world randomness in games or simulations, replacing `std::random_shuffle` for better control and reproducibility of random number generation.
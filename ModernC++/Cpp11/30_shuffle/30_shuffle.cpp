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

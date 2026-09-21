#pragma once
#include <string>

enum class Suit { DIAMONDS, SPADES, HEARTS, CLUBS };

class Card {
    public:
        Card(int rank, Suit suit);

        int getRank() const;
        Suit getSuit() const;

        std::string toString() const;
        
    private:
        int rank_;
        Suit suit_;
};
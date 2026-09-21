#include "poker/card.hpp"

Card::Card(int rank, Suit suit) : rank_(rank), suit_(suit) {}

int Card::getRank() const{
    return rank_;
}

Suit Card::getSuit() const{
    return suit_;
}

std::string Card::toString() const{
    static const std::string rankNames[] = {
        "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q",
        "K", "A"    
    };

    static const std::string suitNames[] = {
        "D", "S", "H", "C"
    };

    //rankNames 2 fixado
    return rankNames[rank_ - 2] + suitNames[static_cast<int>(suit_)];
}
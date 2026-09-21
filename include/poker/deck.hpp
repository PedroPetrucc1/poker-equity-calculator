#pragma once
#include <vector>
#include <random>
#include "poker/card.hpp"

class Deck{
    public:
        Deck();

        void removeCard(const Card& card);
        Card sortCard(std::mt19937& rng); //sorteia uma carta nao usada

        int avaibleCards() const;

    private:
        std::vector<Card> card_;
        std::vector<bool> used_;
};